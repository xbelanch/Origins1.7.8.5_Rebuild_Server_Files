#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

A2EDC_DB_ENV="${A2EDC_DB_ENV:-$SCRIPT_DIR/a2edc-db-shadow.env}" \
  "$REPO_ROOT/tools/db/inspect-gender-state.sh" "$@"
