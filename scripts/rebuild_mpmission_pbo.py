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
MISSION_NAME = "dayz_1.origins.tavi"
SOURCE = ROOT / "MPMissions" / MISSION_NAME
ACTIVE_PBO = ROOT / "MPMissions" / f"{MISSION_NAME}.pbo"
EXPORT_DIR = ROOT / "Export"
MAKEPBO = ROOT / "tools" / "bin" / "makepbo"
UNPBO = ROOT / "tools" / "bin" / "unpbo"
PREFIX = ""
DEFAULT_NOTE = "mpmission-current-reconstruction-v1"
BUILDINFO_REL = Path("Scripts") / "a2edc_mission_buildinfo.sqf"
STALE_MARKERS = [
    "bleedguard-runtime-marker-v3",
    "build_id=20260523-185536",
    "build_id=20260523-232941",
]
EXPECTED_STRINGS = [
    "A2EDC:MISSION_BUILD",
    "A2EDC_MISSION_BUILD_ID",
    "Scripts\\a2edc_mission_buildinfo.sqf",
]


def run(args, *, check=True, capture=True):
    kwargs = {"cwd": ROOT, "text": True}
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


def sha256(path):
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def write_build_info(build_id, build_utc, build_note, export_path):
    git = git_info()
    buildinfo = SOURCE / BUILDINFO_REL
    buildinfo.parent.mkdir(parents=True, exist_ok=True)
    buildinfo.write_text(
        "\n".join(
            [
                f'A2EDC_MISSION_BUILD_ID = "{build_id}";',
                f'A2EDC_MISSION_BUILD_UTC = "{build_utc}";',
                f'A2EDC_MISSION_BUILD_SOURCE = "{rel(SOURCE)}";',
                f'A2EDC_MISSION_BUILD_PREFIX = "{PREFIX}";',
                f'A2EDC_MISSION_BUILD_NOTE = "{build_note}";',
                f'A2EDC_MISSION_BUILD_EXPORT = "{rel(export_path)}";',
                f'A2EDC_MISSION_BUILD_GIT_SHORT = "{git["short"]}";',
                f'A2EDC_MISSION_BUILD_GIT_DIRTY = "{str(git["dirty"]).lower()}";',
                "",
                'diag_log format [',
                '  "[A2EDC:MISSION_BUILD] dayz_1.origins.tavi.pbo build_id=%1 build_utc=%2 prefix=%3 note=%4 export=%5 git=%6 dirty=%7",',
                "  A2EDC_MISSION_BUILD_ID,",
                "  A2EDC_MISSION_BUILD_UTC,",
                "  A2EDC_MISSION_BUILD_PREFIX,",
                "  A2EDC_MISSION_BUILD_NOTE,",
                "  A2EDC_MISSION_BUILD_EXPORT,",
                "  A2EDC_MISSION_BUILD_GIT_SHORT,",
                "  A2EDC_MISSION_BUILD_GIT_DIRTY",
                "];",
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
        text = path.read_text(encoding="utf-8", errors="ignore")
        for marker in STALE_MARKERS:
            if marker in text:
                hits.append(f"{rel(path)}: {marker}")
    if hits:
        raise RuntimeError("stale build markers found in active mission source:\n" + "\n".join(hits))


def pack(export_path):
    if not MAKEPBO.is_file():
        raise FileNotFoundError(f"makepbo not found: {MAKEPBO}")
    EXPORT_DIR.mkdir(parents=True, exist_ok=True)
    active_bytes = ACTIVE_PBO.read_bytes() if ACTIVE_PBO.is_file() else None
    cmd = [
        str(MAKEPBO),
        str(SOURCE),
        str(export_path),
    ]
    try:
        output = run(cmd)
    finally:
        if active_bytes is not None and (not ACTIVE_PBO.is_file() or ACTIVE_PBO.read_bytes() != active_bytes):
            ACTIVE_PBO.write_bytes(active_bytes)
    syntax_result = (
        "skipped: mission PBO packed as raw text/no-prefix to match active mission; "
        "rapify syntax check rejects existing description.ext block comments"
    )
    return cmd, output, syntax_result


def verify_export(export_path, build_id, build_note):
    verify_dir = ROOT / ".audit" / "verify" / export_path.stem
    if verify_dir.exists():
        shutil.rmtree(verify_dir)
    verify_dir.parent.mkdir(parents=True, exist_ok=True)
    listing = run([str(UNPBO), "-v", "-l", str(export_path)])
    no_prefix = "property: prefix=" not in listing
    run([str(UNPBO), str(export_path), str(verify_dir)])

    buildinfo = verify_dir / BUILDINFO_REL
    if not buildinfo.is_file():
        raise RuntimeError(f"post-pack verification failed: {BUILDINFO_REL.as_posix()} missing")
    combined = "\n".join(
        path.read_text(encoding="utf-8", errors="ignore")
        for path in verify_dir.rglob("*")
        if path.is_file() and path.suffix.lower() in {"", ".sqf", ".txt", ".fsm", ".ext", ".sqm", ".hpp"}
    )
    missing = []
    for needle in [build_id, build_note] + EXPECTED_STRINGS:
        if needle not in combined:
            missing.append(needle)
    for marker in STALE_MARKERS:
        if marker in combined:
            missing.append(f"stale marker still packed: {marker}")
    if missing:
        raise RuntimeError("post-pack verification failed:\n" + "\n".join(missing))
    return {
        "validation_command": " ".join(str(part) for part in [UNPBO, "-v", "-l", export_path]),
        "prefix": "",
        "prefix_ok": no_prefix,
        "verify_dir": rel(verify_dir),
        "listing_head": listing.splitlines()[:20],
    }


def changed_files_summary():
    return run(["git", "status", "--short"], check=False).splitlines()


def write_manifest(path, data):
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args():
    parser = argparse.ArgumentParser(description="Build and export MPMission PBO with generated A2EDC metadata.")
    parser.add_argument("--build-id", default=None)
    parser.add_argument("--build-note", default=DEFAULT_NOTE)
    parser.add_argument("--output-name", default=None)
    return parser.parse_args()


def main():
    args = parse_args()
    generated_id, build_utc = now_build_id()
    build_id = args.build_id or generated_id
    safe_note = args.build_note.replace("/", "-").replace("\\", "-").replace(" ", "-")
    pbo_name = args.output_name or f"{MISSION_NAME}_{build_id}_{safe_note}.pbo"
    export_path = EXPORT_DIR / pbo_name
    manifest_path = export_path.with_suffix(".manifest.json")
    write_build_info(build_id, build_utc, args.build_note, export_path)
    validate_no_stale_markers()
    build_cmd, _build_output, syntax_check = pack(export_path)
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
        "build_command": " ".join(str(part) for part in build_cmd),
        "validation_command": verification["validation_command"],
        "syntax_check_result": syntax_check,
        "native_binarize": False,
        "pipeline_manifest": None,
        "post_pack_verify_dir": verification["verify_dir"],
        "changed_files_summary": changed_files_summary(),
    }
    write_manifest(manifest_path, manifest)

    print(f"pbo={rel(export_path)}")
    print(f"manifest={rel(manifest_path)}")
    print(f"build_id={build_id}")
    print(f"build_utc={build_utc}")
    print("prefix=<none>")
    print(f"sha256={digest}")
    print(syntax_check)


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(f"error: {exc}", file=sys.stderr)
        sys.exit(1)
