#!/usr/bin/env python3
import argparse
import hashlib
import json
import shutil
import socket
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "@dayz_1.origins.tavi" / "addons" / "dayz_server"
ACTIVE_PBO = ROOT / "@dayz_1.origins.tavi" / "addons" / "dayz_server.pbo"
EXPORT_DIR = ROOT / "Export"
MAKEPBO = ROOT / "tools" / "bin" / "makepbo"
UNPBO = ROOT / "tools" / "bin" / "unpbo"
PREFIX = r"z\addons\dayz_server"
DEFAULT_NOTE = "wai-dzms-classname-cleanup-v5"
STALE_MARKERS = [
    "bleedguard-runtime-marker-v3",
    "build_id=20260523-185536",
    "build_id=20260523-232941",
]
EXPECTED_STRINGS = [
    "A2EDC:WAI:PUBLISH",
    "A2EDC:DZMS:SETUP",
    "A2EDC:DZMS:SAVE",
    "A2EDC:DZMS:PROTECT:SKIP_INVALID",
    "A2EDC:DZMS:PROTECT:SKIP_NULL",
    "A2EDC:DZMS:CLASS:SKIP_MISSING",
    "A2EDC:WAI:CLASS:SKIP_MISSING",
    "A2EDC:WAI:CARGO:SKIP_MISSING",
    "A2EDC:OBJECT_GUARD",
    "server_updateObject = server_updatObiect",
]


def run(args, *, check=True, capture=True):
    kwargs = {
        "cwd": ROOT,
        "text": True,
    }
    if capture:
        kwargs["stdout"] = subprocess.PIPE
        kwargs["stderr"] = subprocess.STDOUT
    proc = subprocess.run(args, **kwargs)
    if check and proc.returncode != 0:
        output = proc.stdout if capture else ""
        raise RuntimeError(f"command failed ({proc.returncode}): {' '.join(map(str, args))}\n{output}")
    return proc.stdout.strip() if capture and proc.stdout else ""


def rel(path):
    return path.relative_to(ROOT).as_posix()


def shell_quote_parts(parts):
    return " ".join(str(part) for part in parts)


def now_build_id():
    now = datetime.now(timezone.utc)
    return now.strftime("%Y%m%d-%H%M%S"), now.strftime("%Y-%m-%dT%H:%M:%SZ")


def git_info():
    commit = run(["git", "rev-parse", "HEAD"], check=False) or "unknown"
    short = run(["git", "rev-parse", "--short", "HEAD"], check=False) or "unknown"
    status = run(["git", "status", "--short"], check=False)
    return {
        "commit": commit,
        "short": short,
        "dirty": bool(status),
        "status_short": status.splitlines(),
    }


def file_count():
    return sum(1 for path in SOURCE.rglob("*") if path.is_file())


def write_build_info(build_id, build_utc, build_note, export_path):
    git = git_info()
    export_rel = rel(export_path)
    source_rel = rel(SOURCE)
    sqf = SOURCE / "init" / "a2edc_buildinfo.sqf"
    sqf.write_text(
        "\n".join(
            [
                f'A2EDC_BUILD_ID = "{build_id}";',
                f'A2EDC_BUILD_UTC = "{build_utc}";',
                f'A2EDC_BUILD_SOURCE = "{source_rel}";',
                f'A2EDC_BUILD_PREFIX = "{PREFIX}";',
                f'A2EDC_BUILD_NOTE = "{build_note}";',
                f'A2EDC_BUILD_EXPORT = "{export_rel}";',
                f'A2EDC_BUILD_GIT_SHORT = "{git["short"]}";',
                f'A2EDC_BUILD_GIT_DIRTY = "{str(git["dirty"]).lower()}";',
                "",
                "A2EDC_DAYZ_SERVER_BUILD_ID = A2EDC_BUILD_ID;",
                "A2EDC_DAYZ_SERVER_BUILD_UTC = A2EDC_BUILD_UTC;",
                "A2EDC_DAYZ_SERVER_BUILD_SOURCE = A2EDC_BUILD_SOURCE;",
                "A2EDC_DAYZ_SERVER_BUILD_PREFIX = A2EDC_BUILD_PREFIX;",
                "A2EDC_DAYZ_SERVER_BUILD_NOTE = A2EDC_BUILD_NOTE;",
                "",
                "A2EDC_BUILD_EXPECTED_DIAGNOSTICS = [",
                '  "A2EDC:WAI:PUBLISH",',
                '  "A2EDC:DZMS:SETUP",',
                '  "A2EDC:DZMS:SAVE",',
                '  "A2EDC:DZMS:PROTECT:SKIP_INVALID",',
                '  "A2EDC:DZMS:PROTECT:SKIP_NULL",',
                '  "A2EDC:DZMS:CLASS:SKIP_MISSING",',
                '  "A2EDC:WAI:CLASS:SKIP_MISSING",',
                '  "A2EDC:WAI:CARGO:SKIP_MISSING",',
                '  "A2EDC:OBJECT_GUARD",',
                '  "server_updateObject = server_updatObiect"',
                "];",
                "",
                'diag_log format [',
                '  "[A2EDC:BUILD] dayz_server.pbo build_id=%1 build_utc=%2 prefix=%3 note=%4 export=%5 git=%6 dirty=%7",',
                "  A2EDC_BUILD_ID,",
                "  A2EDC_BUILD_UTC,",
                "  A2EDC_BUILD_PREFIX,",
                "  A2EDC_BUILD_NOTE,",
                "  A2EDC_BUILD_EXPORT,",
                "  A2EDC_BUILD_GIT_SHORT,",
                "  A2EDC_BUILD_GIT_DIRTY",
                "];",
                "",
            ]
        ),
        encoding="utf-8",
    )

    txt = SOURCE / "A2EDC_BUILDINFO.txt"
    txt.write_text(
        "\n".join(
            [
                f"build_id={build_id}",
                f"build_utc={build_utc}",
                f"source={source_rel}",
                f"export_pbo={export_rel}",
                f"prefix={PREFIX}",
                f"hostname={socket.gethostname() or 'unknown'}",
                f"git_commit={git['commit']}",
                f"git_short={git['short']}",
                f"git_dirty={str(git['dirty']).lower()}",
                f"note={build_note}",
                "",
            ]
        ),
        encoding="utf-8",
    )


def validate_no_stale_markers():
    hits = []
    for path in SOURCE.rglob("*"):
        if not path.is_file():
            continue
        if path.suffix.lower() in {".pbo", ".png", ".jpg", ".jpeg", ".paa"}:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            continue
        for marker in STALE_MARKERS:
            if marker in text:
                hits.append(f"{rel(path)}: {marker}")
    if hits:
        raise RuntimeError("stale build markers found in active source:\n" + "\n".join(hits))


def sha256(path):
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def pack(export_path):
    if not MAKEPBO.is_file():
        raise FileNotFoundError(f"makepbo not found: {MAKEPBO}")
    EXPORT_DIR.mkdir(parents=True, exist_ok=True)
    active_bytes = ACTIVE_PBO.read_bytes() if ACTIVE_PBO.is_file() else None
    cmd = [
        str(MAKEPBO),
        "--prefix",
        PREFIX,
        str(SOURCE),
        str(export_path),
    ]
    try:
        output = run(cmd)
    finally:
        if active_bytes is not None and (not ACTIVE_PBO.is_file() or ACTIVE_PBO.read_bytes() != active_bytes):
            ACTIVE_PBO.write_bytes(active_bytes)
    syntax_line = "skipped: raw text pack to preserve system/server_cleanup.fsm as textual FSM"
    return cmd, output, syntax_line


def verify_export(export_path, build_id, build_note):
    verify_dir = ROOT / ".audit" / "verify" / export_path.stem
    if verify_dir.exists():
        shutil.rmtree(verify_dir)
    verify_dir.parent.mkdir(parents=True, exist_ok=True)
    listing = run([str(UNPBO), "-v", "-l", str(export_path)])
    prefix_ok = f"property: prefix={PREFIX}" in listing
    run([str(UNPBO), str(export_path), str(verify_dir)])

    buildinfo = verify_dir / "init" / "a2edc_buildinfo.sqf"
    if not buildinfo.is_file():
        raise RuntimeError("post-pack verification failed: init/a2edc_buildinfo.sqf missing")
    build_text = buildinfo.read_text(encoding="utf-8", errors="ignore")
    missing = []
    for needle in [build_id, build_note, "A2EDC:BUILD"]:
        if needle not in build_text:
            missing.append(needle)
    if not prefix_ok:
        missing.append(f"prefix {PREFIX}")

    combined = "\n".join(
        path.read_text(encoding="utf-8", errors="ignore")
        for path in verify_dir.rglob("*")
        if path.is_file() and path.suffix.lower() in {"", ".sqf", ".txt", ".fsm"}
    )
    for needle in EXPECTED_STRINGS:
        if needle not in combined:
            missing.append(needle)
    for marker in STALE_MARKERS:
        if marker in combined:
            missing.append(f"stale marker still packed: {marker}")

    fsm_path = verify_dir / "system" / "server_cleanup.fsm"
    if not fsm_path.is_file():
        missing.append("system/server_cleanup.fsm missing")
    else:
        fsm_bytes = fsm_path.read_bytes()[:8]
        fsm_text = fsm_path.read_text(encoding="utf-8", errors="ignore")
        if fsm_bytes.startswith(b"\x00raP") or ".raP" in fsm_text[:64]:
            missing.append("system/server_cleanup.fsm appears rapified/binary")
        if "/*%FSM<" not in fsm_text[:512] and "class FSM" not in fsm_text[:512]:
            missing.append("system/server_cleanup.fsm does not appear textual")
    if missing:
        raise RuntimeError("post-pack verification failed:\n" + "\n".join(missing))
    return {
        "validation_command": shell_quote_parts([UNPBO, "-v", "-l", export_path]),
        "prefix_ok": prefix_ok,
        "verify_dir": rel(verify_dir),
        "listing_head": listing.splitlines()[:20],
        "server_cleanup_fsm_textual": True,
    }


def changed_files_summary():
    status = run(["git", "status", "--short"], check=False)
    return status.splitlines()


def write_manifest(path, data):
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args():
    parser = argparse.ArgumentParser(description="Build and export dayz_server.pbo with generated A2EDC metadata.")
    parser.add_argument("--build-id", default=None)
    parser.add_argument("--build-note", default=DEFAULT_NOTE)
    parser.add_argument("--output-name", default=None)
    return parser.parse_args()


def main():
    args = parse_args()
    generated_id, build_utc = now_build_id()
    build_id = args.build_id or generated_id
    safe_note = args.build_note.replace("/", "-").replace("\\", "-").replace(" ", "-")
    pbo_name = args.output_name or f"dayz_server_{build_id}_{safe_note}.pbo"
    export_path = EXPORT_DIR / pbo_name
    manifest_path = export_path.with_suffix(".manifest.json")

    write_build_info(build_id, build_utc, args.build_note, export_path)
    validate_no_stale_markers()
    build_cmd, build_output, syntax_check = pack(export_path)
    digest = sha256(export_path)
    verification = verify_export(export_path, build_id, args.build_note)
    manifest = {
        "pbo_name": pbo_name,
        "export_path": rel(export_path),
        "build_id": build_id,
        "build_utc": build_utc,
        "build_note": args.build_note,
        "prefix": PREFIX,
        "source_dir": rel(SOURCE),
        "file_count": file_count(),
        "sha256": digest,
        "build_command": shell_quote_parts(build_cmd),
        "validation_command": verification["validation_command"],
        "syntax_check_result": syntax_check,
        "native_binarize": False,
        "pipeline_manifest": None,
        "server_cleanup_fsm_textual": verification["server_cleanup_fsm_textual"],
        "post_pack_verify_dir": verification["verify_dir"],
        "changed_files_summary": changed_files_summary(),
    }
    write_manifest(manifest_path, manifest)

    print(f"pbo={rel(export_path)}")
    print(f"manifest={rel(manifest_path)}")
    print(f"build_id={build_id}")
    print(f"build_utc={build_utc}")
    print(f"prefix={PREFIX}")
    print(f"sha256={digest}")
    print(syntax_check)


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(f"error: {exc}", file=sys.stderr)
        sys.exit(1)
