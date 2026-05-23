#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
ENV_FILE="${A2EDC_DB_ENV:-$SCRIPT_DIR/a2edc-db.env}"

if [[ ! -f "$ENV_FILE" ]]; then
  echo "Missing DB env file: $ENV_FILE" >&2
  echo "Copy tools/db/a2edc-db.env.example or tools/db/a2edc-db-shadow.env.example and fill local credentials." >&2
  exit 1
fi

# shellcheck source=/dev/null
source "$ENV_FILE"

DUMP_CLIENT="mysqldump"
if command -v mariadb-dump >/dev/null 2>&1; then
  DUMP_CLIENT="mariadb-dump"
elif ! command -v mysqldump >/dev/null 2>&1; then
  echo "Missing mysqldump client. On Arch Linux install it with: sudo pacman -S mariadb-clients" >&2
  exit 1
fi

: "${A2EDC_DB_HOST:?Missing A2EDC_DB_HOST in $ENV_FILE}"
: "${A2EDC_DB_PORT:?Missing A2EDC_DB_PORT in $ENV_FILE}"
: "${A2EDC_DB_NAME:?Missing A2EDC_DB_NAME in $ENV_FILE}"
: "${A2EDC_DB_USER:?Missing A2EDC_DB_USER in $ENV_FILE}"
: "${A2EDC_DB_PASS:?Missing A2EDC_DB_PASS in $ENV_FILE}"

TS="$(date -u +%Y%m%d-%H%M%SZ)"
OUT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)/backups/mysql"
OUT_FILE="$OUT_DIR/dayz_origins-$TS.sql"

mkdir -p "$OUT_DIR"

MYSQL_PWD="$A2EDC_DB_PASS" "$DUMP_CLIENT" \
  --protocol=TCP \
  -h "$A2EDC_DB_HOST" \
  -P "$A2EDC_DB_PORT" \
  -u "$A2EDC_DB_USER" \
  --single-transaction \
  --routines \
  --triggers \
  --events \
  "$A2EDC_DB_NAME" > "$OUT_FILE"

echo "$OUT_FILE"
