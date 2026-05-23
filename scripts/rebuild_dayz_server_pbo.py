#!/usr/bin/env python3
import os
import socket
import subprocess
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "@dayz_1.origins.tavi" / "addons" / "dayz_server"
OUTPUT = ROOT / "@dayz_1.origins.tavi" / "addons" / "dayz_server.pbo"
MAKEPBO = ROOT / "tools" / "makepbo"
PREFIX = r"z\addons\dayz_server"
NOTE = "bleedguard-runtime-marker-v3"


def run_text(args):
    try:
        return subprocess.check_output(args, cwd=ROOT, text=True, stderr=subprocess.DEVNULL).strip()
    except Exception:
        return "unknown"


def rel_for_report(path):
    return path.relative_to(ROOT).as_posix()


def write_buildinfo():
    now = datetime.now(timezone.utc)
    build_id = now.strftime("%Y%m%d-%H%M%S")
    build_utc = now.strftime("%Y-%m-%dT%H:%M:%SZ")
    hostname = socket.gethostname() or "unknown"
    git_commit = run_text(["git", "rev-parse", "HEAD"])
    git_short = run_text(["git", "rev-parse", "--short", "HEAD"])
    git_dirty = run_text(["git", "status", "--short"])
    git_dirty_value = "true" if git_dirty else "false"

    sqf = SOURCE / "init" / "a2edc_buildinfo.sqf"
    sqf.write_text(
        "\n".join(
            [
                f'A2EDC_DAYZ_SERVER_BUILD_ID = "{build_id}";',
                f'A2EDC_DAYZ_SERVER_BUILD_UTC = "{build_utc}";',
                f'A2EDC_DAYZ_SERVER_BUILD_SOURCE = "{rel_for_report(SOURCE)}";',
                f'A2EDC_DAYZ_SERVER_BUILD_PREFIX = "{PREFIX}";',
                f'A2EDC_DAYZ_SERVER_BUILD_NOTE = "{NOTE}";',
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
                f"source={rel_for_report(SOURCE)}",
                f"output_pbo={rel_for_report(OUTPUT)}",
                f"prefix={PREFIX}",
                f"hostname={hostname}",
                f"git_commit={git_commit}",
                f"git_short={git_short}",
                f"git_dirty={git_dirty_value}",
                f"note={NOTE}",
                "",
            ]
        ),
        encoding="utf-8",
    )

    return build_id, build_utc


def pack_pbo():
    if not MAKEPBO.is_file():
        raise FileNotFoundError(f"makepbo not found: {MAKEPBO}")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    tmp = OUTPUT.with_suffix(".pbo.tmp")
    if tmp.exists():
        tmp.unlink()

    subprocess.check_call(
        [str(MAKEPBO), "-p", PREFIX, str(SOURCE), str(tmp)],
        cwd=ROOT,
    )
    os.replace(tmp, OUTPUT)


def main():
    build_id, build_utc = write_buildinfo()
    pack_pbo()
    print(f"build_id={build_id}")
    print(f"build_utc={build_utc}")
    print(f"output={OUTPUT}")
    print(f"prefix={PREFIX}")


if __name__ == "__main__":
    main()
