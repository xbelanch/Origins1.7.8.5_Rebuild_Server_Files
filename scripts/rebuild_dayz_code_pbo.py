#!/usr/bin/env python3
import argparse
import hashlib
import json
import shutil
import subprocess
import tempfile
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "Sandbox" / "origins_179_rebuild" / "dayz_code_merged_src"
EXPORT_DIR = ROOT / "Export"
MAKEPBO = ROOT / "tools" / "bin" / "makepbo"
RAPIFY = ROOT / "tools" / "bin" / "rapify"
UNPBO = ROOT / "tools" / "bin" / "unpbo"
PREFIX = r"z\addons\dayz_code"
DEFAULT_NOTE = "inventory-actions-bridge-fsm-text-v2"


def run(args, *, cwd=ROOT, check=True):
    proc = subprocess.run(
        args,
        cwd=cwd,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    if check and proc.returncode != 0:
        raise RuntimeError(f"command failed ({proc.returncode}): {' '.join(map(str, args))}\n{proc.stdout}")
    return proc.stdout.strip()


def rel(path):
    return path.relative_to(ROOT).as_posix()


def now_build_id():
    now = datetime.now(timezone.utc)
    return now.strftime("%Y%m%d-%H%M%S"), now.strftime("%Y-%m-%dT%H:%M:%SZ")


def sha256(path):
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def git_info():
    status = run(["git", "status", "--short"], check=False)
    return {
        "commit": run(["git", "rev-parse", "HEAD"], check=False) or "unknown",
        "short": run(["git", "rev-parse", "--short", "HEAD"], check=False) or "unknown",
        "dirty": bool(status),
        "status_short": status.splitlines(),
    }


def file_count(path):
    return sum(1 for item in path.rglob("*") if item.is_file())


def stage_source(stage):
    shutil.copytree(SOURCE, stage, dirs_exist_ok=True)
    config_cpp = stage / "config.cpp"
    config_bin = stage / "config.bin"
    if not config_cpp.is_file():
        raise RuntimeError("config.cpp missing from dayz_code source")
    run([str(RAPIFY), str(config_cpp), str(config_bin)])
    config_cpp.unlink()


def verify_fsm_textual(verify_dir):
    failures = []
    fsm_paths = sorted(verify_dir.rglob("*.fsm"))
    if not fsm_paths:
        failures.append("no .fsm files found")
    for path in fsm_paths:
        data = path.read_bytes()
        text = data[:512].decode("utf-8", errors="ignore")
        if data.startswith(b"\x00raP") or ".raP" in text[:64]:
            failures.append(f"{rel(path)} appears rapified/binary")
        if "/*%FSM<" not in text and "class FSM" not in text:
            failures.append(f"{rel(path)} does not appear textual")
    return failures


def verify_export(export_path, build_id, build_note):
    verify_dir = ROOT / ".audit" / "verify" / export_path.stem
    if verify_dir.exists():
        shutil.rmtree(verify_dir)
    verify_dir.parent.mkdir(parents=True, exist_ok=True)
    listing = run([str(UNPBO), "-v", "-l", str(export_path)])
    run([str(UNPBO), str(export_path), str(verify_dir)])

    missing = []
    if f"property: prefix={PREFIX}" not in listing:
        missing.append(f"prefix {PREFIX}")
    if not (verify_dir / "config.bin").is_file():
        missing.append("config.bin missing")
    if (verify_dir / "config.cpp").exists():
        missing.append("config.cpp unexpectedly packed beside config.bin")
    missing.extend(verify_fsm_textual(verify_dir))

    combined = "\n".join(
        path.read_text(encoding="utf-8", errors="ignore")
        for path in verify_dir.rglob("*")
        if path.is_file() and path.suffix.lower() in {".sqf", ".hpp", ".fsm"}
    )
    for needle in [
        "A2EDC:INV_ACTION",
        "A2EDC:INV_ACTION_BRIDGE",
        "player_selectSlot",
        "fnc_use_item",
    ]:
        if needle not in combined:
            missing.append(needle)
    if missing:
        raise RuntimeError("post-pack verification failed:\n" + "\n".join(missing))
    return {
        "verify_dir": rel(verify_dir),
        "listing_head": listing.splitlines()[:20],
        "fsm_textual": [rel(path) for path in sorted(verify_dir.rglob("*.fsm"))],
    }


def write_manifest(path, data):
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args():
    parser = argparse.ArgumentParser(description="Build dayz_code.pbo while preserving FSM files as text.")
    parser.add_argument("--build-id", default=None)
    parser.add_argument("--build-note", default=DEFAULT_NOTE)
    parser.add_argument("--output-name", default=None)
    return parser.parse_args()


def main():
    args = parse_args()
    generated_id, build_utc = now_build_id()
    build_id = args.build_id or generated_id
    safe_note = args.build_note.replace("/", "-").replace("\\", "-").replace(" ", "-")
    pbo_name = args.output_name or f"dayz_code_{build_id}_{safe_note}.pbo"
    EXPORT_DIR.mkdir(parents=True, exist_ok=True)
    export_path = EXPORT_DIR / pbo_name

    with tempfile.TemporaryDirectory(prefix="a2edc_dayz_code_") as tmp:
        stage = Path(tmp) / "dayz_code"
        stage_source(stage)
        build_output = run([str(MAKEPBO), "--prefix", PREFIX, str(stage), str(export_path)])

    digest = sha256(export_path)
    sha_path = export_path.with_suffix(export_path.suffix + ".sha256")
    sha_path.write_text(f"{digest}  {export_path.name}\n", encoding="utf-8")
    verification = verify_export(export_path, build_id, args.build_note)
    manifest = {
        "pbo_name": pbo_name,
        "export_path": rel(export_path),
        "build_id": build_id,
        "build_utc": build_utc,
        "build_note": args.build_note,
        "prefix": PREFIX,
        "source_dir": rel(SOURCE),
        "file_count": file_count(SOURCE),
        "sha256": digest,
        "sha256_file": rel(sha_path),
        "config_packaging": "config.cpp rapified to config.bin",
        "fsm_packaging": "all .fsm files preserved as raw text",
        "build_output": build_output,
        "post_pack_verify_dir": verification["verify_dir"],
        "fsm_textual": verification["fsm_textual"],
        "git": git_info(),
    }
    manifest_path = export_path.with_suffix(".manifest.json")
    write_manifest(manifest_path, manifest)
    print(f"pbo={rel(export_path)}")
    print(f"manifest={rel(manifest_path)}")
    print(f"build_id={build_id}")
    print(f"build_utc={build_utc}")
    print(f"prefix={PREFIX}")
    print(f"sha256={digest}")
    print("fsm_packaging=raw-text")


if __name__ == "__main__":
    main()
