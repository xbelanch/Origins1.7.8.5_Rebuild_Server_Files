#!/usr/bin/env bash
set -euo pipefail

UID_TO_CHECK="${1:-76561198024951069}"

if [[ ! "$UID_TO_CHECK" =~ ^[0-9]+$ ]]; then
  echo "Invalid PlayerUID: $UID_TO_CHECK" >&2
  exit 1
fi

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
DB="$SCRIPT_DIR/db-query.sh"

echo "== Tables =="
"$DB" "SHOW FULL TABLES;"

echo
echo "== Player_DATA schema candidates =="
"$DB" "SHOW TABLES LIKE '%layer%';"

echo
echo "== Character_DATA schema candidates =="
"$DB" "SHOW TABLES LIKE '%haracter%';"

echo
echo "== Player_DATA columns =="
"$DB" "SHOW COLUMNS FROM Player_DATA;"

echo
echo "== Character_DATA columns =="
"$DB" "SHOW COLUMNS FROM Character_DATA;"

echo
echo "== Player row for UID $UID_TO_CHECK =="
"$DB" "SELECT * FROM Player_DATA WHERE PlayerUID='${UID_TO_CHECK}';"

echo
echo "== Last 10 login rows for UID $UID_TO_CHECK =="
"$DB" "SELECT * FROM Player_LOGIN WHERE PlayerUID='${UID_TO_CHECK}' ORDER BY ID DESC LIMIT 10;"

echo
echo "== Last 10 character rows for UID $UID_TO_CHECK =="
"$DB" "SELECT * FROM Character_DATA WHERE PlayerUID='${UID_TO_CHECK}' ORDER BY CharacterID DESC LIMIT 10;"

echo
echo "== Alive character count for UID $UID_TO_CHECK =="
"$DB" "SELECT COUNT(*) AS alive_rows FROM Character_DATA WHERE PlayerUID='${UID_TO_CHECK}' AND Alive=1;"

echo
echo "== Last 10 dead character rows for UID $UID_TO_CHECK =="
"$DB" "SELECT * FROM Character_DATA_DEAD WHERE PlayerUID='${UID_TO_CHECK}' ORDER BY CharacterID DESC LIMIT 10;"
