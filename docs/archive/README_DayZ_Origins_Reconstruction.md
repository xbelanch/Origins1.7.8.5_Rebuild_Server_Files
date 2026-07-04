> Historical document. Kept for reference. Current entrypoint: [../INDEX.md](../INDEX.md)

# DayZ Origins Server Reconstruction / Community Server Files

This repository contains community-provided server-side material and tooling used to run and reconstruct DayZ Origins server environments, especially around the 1.7.8.5 baseline and later experimental 1.7.9 reconstruction work.

This is not a clean official server release. Treat these files as a preservation/reconstruction workspace built from several sources:

- official DayZ Origins client packages;
- community server files;
- install/rebuild material from `installP`;
- custom patches required to make the available mission/server stack work;
- local audit and rebuild outputs.

The goal is to preserve and run historically significant DayZ Origins server versions while documenting every compatibility layer and deviation from the official client packages.

---

## Important Provenance Note

The `installP/addons/dayz_code.pbo` file is not currently considered a clean official client artifact.

Current audit results indicate:

- official DayZ Origins 1.7.8.5 client `dayz_code.pbo` is relatively slim;
- official DayZ Origins 1.7.9 client `dayz_code.pbo` is also slim;
- the large script-bearing `dayz_code.pbo` found under `installP/addons` contains many extra scripts under paths such as:

  - `actions/`
  - `compile/`
  - `medical/`
  - `init/`
  - `system/`
  - UI/resource files

This large `installP` version appears to be community/server-stack-derived or otherwise non-official. It contains markers such as “un-official server” and “DEBUG: pirated server” in some scripts, and its `hiveVersion` differs from the official 1.7.8.5 client package.

For this reason, the current merged `dayz_code` used in the 1.7.9 reconstruction must be understood as a **compatibility bridge**, not as a faithful official 1.7.9 reconstruction.

It is retained because the available mission/server stack still references legacy scripts under:

```text
z\addons\dayz_code
```

which are absent from the slim official client PBOs.

---

# Requirements

## Game files

Install both games from Steam:

- Arma 2
- Arma 2: Operation Arrowhead

DayZ Origins is an Arma 2 OA mod and requires the combined Arma 2 + Operation Arrowhead content.

The original community instructions recommended copying all Arma 2 files into the Operation Arrowhead folder. This works, but a cleaner setup may use junctions/symlinks or a Combined Operations layout, as long as Arma 2 content is visible to OA.

A typical working server layout needs access to:

```text
arma2oa/
├── addons/
├── Expansion/
├── ca/
├── @DayZOriginsP/
├── @dayz_1.origins.tavi/
├── MPMissions/
└── cfgorigins/
```

The exact folder names may vary depending on the reconstruction branch.

---

# Required Tools

Older instructions used **PBO Manager** for Windows.

The current reconstruction workspace now includes a local toolchain under:

```text
tools/bin
```

This toolchain should be preferred for reproducible work.

Available or expected capabilities include:

- unpacking PBOs;
- reading/preserving PBO prefixes;
- packing PBOs;
- rapifying `config.cpp` / `config.hpp` into `config.bin`;
- rebuilding PBOs with correct prefixes;
- validating output PBO structure;
- comparing PBO contents;
- generating checksums.

Before building or exporting any PBO, inspect the relevant tool help:

```bash
tools/bin/<tool-name> --help
```

Do not overwrite original PBOs from `Sandbox` or official source folders.

Generated PBOs must be written to:

```text
Export/
```

---

# Workspace Policy

The current workspace is organized conceptually as follows:

```text
Sandbox/
```

Reference and input material. This may include:

- original `@DayzOrigins179`;
- official DayZ Origins 1.7.8.5 client files;
- community 1.7.8.5 server/rebuild files;
- original PBOs used for comparison.

Do not mutate these files directly.

```text
origins_179_rebuild/
```

Working reconstruction area used for the 1.7.9 compatibility merge and related audits.

```text
tools/bin/
```

Local PBO/config tooling.

```text
Export/
```

Final generated PBO handoff directory.

Every generated PBO should be copied here with enough metadata to identify it later.

Recommended output metadata:

```text
Export/
├── dayz_code_<build_id>.pbo
├── dayz_code_<build_id>.pbo.sha256
├── dayz_code_<build_id>.manifest.json
├── dayz_server_<build_id>.pbo
├── dayz_server_<build_id>.pbo.sha256
└── dayz_server_<build_id>.manifest.json
```

Each manifest should record:

- build id;
- timestamp;
- source directories;
- PBO prefix;
- whether config was rapified;
- whether text `config.cpp` was preserved;
- SHA256;
- validation command/output;
- notes about whether the build is experimental or deployable.

---

# Packing `origins_pack`

The original community instructions required packing `installP/addons/origins_pack` before installation.

Original method:

1. Install PBO Manager.
2. Right-click:

```text
installP/addons/origins_pack
```

3. Pack it into:

```text
origins_pack.pbo
```

Current preferred method:

Use the local `tools/bin` PBO toolchain and preserve the correct prefix.

Before packing, verify whether `origins_pack` has an expected prefix file or needs an explicit prefix.

Example conceptual workflow:

```bash
tools/bin/makepbo \
  --prefix "<expected-prefix>" \
  installP/addons/origins_pack \
  Export/origins_pack_<build_id>.pbo
```

Use the actual syntax supported by the local tool. Do not assume PBO Manager behavior unless reproducing the original community setup exactly.

---

# Installing the 1.7.8.5 Community Server Baseline

## 1. Install the client mod

Install DayZ Origins version 1.7.8.5 into the Arma 2 OA folder.

The expected mod folder may be something like:

```text
@DayZOrigins
```

or:

```text
@DayZOriginsP
```

depending on the installer/rebuild process.

---

## 2. Copy the community server files

Extract the community server/rebuild files into the OA folder.

The original workflow provided an `install.cmd` script to generate:

```text
@DayZOriginsP
```

Run it only after verifying paths and ensuring the input folders are present.

---

## 3. Configure MySQL

Create the database:

```sql
CREATE DATABASE dayz_origins
  CHARACTER SET utf8
  COLLATE utf8_general_ci;
```

Execute the SQL files from the `SQLfile` folder in the required sequence.

The original instructions assumed a local Windows MySQL installation under `Program Files`.

The current project setup may instead use an external MySQL server, for example a Dockerized MySQL 5.7 instance. In that case, configure `hive.ini` to connect via TCP to the external database host.

Verify connectivity before launching the game server.

Typical checks:

```sql
SHOW DATABASES;
USE dayz_origins;
SHOW TABLES;
```

Also check table/view casing. Some server scripts expect names such as:

```text
Object_DATA
Object_CLASSES
Object_SPAWNS
Player_DATA
Character_DATA
```

while the underlying database may contain lowercase table names. If required, create compatible views or normalize schema casing carefully.

---

## 4. Configure server files

Edit the server configuration files, typically found under a folder such as:

```text
dayz_1.origins.tavi/
cfgorigins/
```

Important files may include:

```text
config.cfg
basic.cfg
hive.ini
server.cfg
BattlEye filters
originsserver.cmd
```

Adjust:

- server name;
- password/admin password;
- database credentials;
- HiveExt path;
- mod startup parameters;
- BattlEye path;
- mission name;
- profiles path;
- MySQL client path if using Windows scripts.

---

## 5. Configure admin tools

If the mission contains admin tools, reinsert your own PlayerID/UID where required.

Check files under:

```text
MPMissions/dayz_1.origins.tavi/
```

or similar mission directories.

Do not blindly preserve old admin IDs from community files.

---

## 6. Launch the server

The original community method used:

```text
originsserver.cmd
```

Current launch commands may be customized. A typical startup command includes:

```text
arma2oaserver.exe
-port=2422
-bepath=<BattlEye path>
-mod=Expansion\beta;Expansion\beta\expansion;ca;@dayzoriginsP;@dayz_1.origins.tavi
-config=<config.cfg>
-cfg=<basic.cfg>
-profiles=<profiles folder>
-name=<server profile>
```

Always preserve the exact mod load order that has been validated for the target reconstruction.

---

# Updating the 1.7.8.5 Community Baseline

The original community update procedure was:

Copy these folders/files into the OA folder and overwrite old ones:

```text
@dayz_1.origins.tavi
installP
MPMissions
originsserver.cmd
update.cmd
```

Then run:

```text
update.cmd
```

and execute any new SQL files from:

```text
SQLfile/
```

Current recommendation:

Before updating, back up:

- all PBOs;
- `MPMissions`;
- `cfgorigins`;
- `hive.ini`;
- BattlEye filters;
- database;
- custom admin tool configuration;
- any local patches.

Recommended database backup before applying updates:

```bash
mysqldump -u <user> -p dayz_origins > dayz_origins_backup_<date>.sql
```

Do not apply community updates directly over a working reconstruction without first comparing changed files.

---

# 1.7.9 Reconstruction Notes

The current 1.7.9 reconstruction is not a clean official 1.7.9 server release.

It combines:

- original 1.7.9 client/mod material;
- selected compatibility content from `installP`;
- a merged `dayz_code.pbo`;
- patched `dayz_server.pbo`;
- current mission/server files that still expect legacy `z\addons\dayz_code` scripts.

The current merged `dayz_code.pbo` should be considered:

```text
1.7.9 client/config/assets
+
installP legacy script API compatibility layer
```

It exists because the available mission/server stack references scripts that are absent from the official slim client PBOs.

Do not reduce or clean this merged PBO until smoke tests prove which restored files are safe to remove.

Current audit classification of restored files:

```text
keep: 148
investigate: 23
candidate_remove_later: 37
```

Most candidate removals are legacy GUI/stat/loading-screen assets. Core gameplay scripts, medical scripts, action scripts, compiles, public event handlers and player monitor files remain high risk.

---

# Known Current Issues in the 1.7.9 Reconstruction

At the current stage, the following areas require further work:

## Stale vehicle classes in database

The following classes are referenced by old data but are not valid spawnable `CfgVehicles` classes in the current 1.7.9 setup:

```text
ori_vil_originsmod_truck_civ1
ori_vil_originsmod_truck_civ2
```

They appear to be stale classnames from an older stack.

Likely migration target:

```text
ori_vil_originsmod_truck_civ
```

Do not migrate without backup.

Recommended preflight:

```sql
SELECT Classname, COUNT(*) AS rows_count
FROM Object_DATA
WHERE Classname IN (
  'ori_vil_originsmod_truck_civ1',
  'ori_vil_originsmod_truck_civ2',
  'ori_vil_originsmod_truck_civ',
  'ori_vil_truck_civ_base'
)
GROUP BY Classname;
```

---

## Admin crate BattleEye kick

Creating an admin crate currently triggers a BattleEye/protection kick.

The RPT shows:

```text
BE protection kicked in
msgType=68
msgType=40
```

The exact filter must be diagnosed from BattlEye logs, not only from RPT.

Relevant logs:

```text
createvehicle.log
scripts.log
publicvariable.log
remoteexec.log
setvariable.log
setvariableval.log
addweaponcargo.log
addmagazinecargo.log
addbackpackcargo.log
attachto.log
```

Avoid broad BE filter relaxation. Prefer moving crate creation to a server-side validated admin handler.

---

## Vehicle persistence anomaly

There is a known anomaly involving:

```text
ORI_gunship_helicopter
```

where the object update path sometimes appears to treat the player object as if it were the persistent vehicle object.

This may affect:

- vehicle save;
- vehicle force-save;
- in-vehicle player sync;
- disconnect handling;
- combat log handling;
- object persistence.

Relevant areas to audit:

```text
dayUpdateVehlcle
server_updateObject
player sync vehicle resolution
init/publicEH.sqf
vehicle persistence handlers
```

---

## Vehicle config warnings

The current 1.7.9 setup still emits warnings involving:

- missing `HitPoints` entries;
- `Damage/tex[]` arrays with invalid pairing;
- unknown animation sources.

Affected classes include vehicles such as:

```text
ori_vil_truck_civ_base
ori_vil_originsmod_truck_civ
ori_p85_originsmod_CUCV
ori_survivorBus
```

These are not yet treated as boot-blocking. Audit later after gameplay/admin/persistence issues are stabilized.

---

# Optional Adjustment: Teleport and Vehicle Eject Fix

The original community README suggested increasing anti-teleport thresholds in:

```text
Origins/MPMissions/dayz_1.origins.tavi/Debug/player_spawn_2.sqf
```

Original logic included checks similar to:

```sqf
_myPos = player getVariable ["lastPos", []];

if (count _myPos > 0) then {
    player setVariable ["lastPos", _mylastPos, true];
    player setVariable ["lastPos", []];
};

_lastPos = getPosATL player;

if (player == vehicle player) then {
    if (_mylastPos distance _lastPos > 200) then {
        if (alive player) then {
            player setPosATL _mylastPos;
        };
    };
} else {
    if (_mylastPos distance _lastPos > 800) then {
        if (alive player) then {
            player setPosATL _mylastPos;
        };
    };
};
```

The original workaround changed:

```text
200  -> 20000
800  -> 80000
```

This was intended to avoid false positives when using admin tools, vehicle boost, planes or fast movement on Taviana.

Current recommendation:

Do not blindly disable anti-teleport logic in production.

For testing/admin work, increasing the thresholds may be acceptable temporarily, but document the change and restore stricter values later.

A better long-term solution is to distinguish between:

- normal player movement;
- legitimate aircraft/vehicle movement;
- admin-authorized actions;
- actual teleport abuse.

---

# Smoke Tests

Before reducing the merged `dayz_code` or applying broad cleanup, run smoke tests for:

1. Existing character login.
2. Fresh character login.
3. Gender selection.
4. Spawn flow.
5. Medical actions:
   - bandage;
   - morphine;
   - painkillers;
   - antibiotics;
   - transfusion if available.
6. Vehicle:
   - enter/exit;
   - repair;
   - refuel;
   - save;
   - force-save;
   - restart persistence.
7. Vehicle damage and destruction.
8. Loot spawning.
9. Zombie spawning.
10. House/build actions:
    - build;
    - remove;
    - lock/unlock;
    - object pickup.
11. Admin tools:
    - teleport;
    - vehicle boost;
    - crate creation;
    - spawn vehicle;
    - delete object.
12. WAI/DZMS missions:
    - spawn;
    - AI behavior;
    - crate reward;
    - cleanup.
13. BattlEye:
    - createVehicle restrictions;
    - publicVariable restrictions;
    - script restrictions;
    - cargo restrictions.
14. UI:
    - status icons;
    - loading screens;
    - debug monitor;
    - dialogs/actions.

---

# Credits

Original community credit goes to MDark for the work involved in making the community server files available.

Additional reconstruction, auditing, PBO tooling, compatibility patches and documentation are part of the current preservation/rebuild effort.

All modifications should be documented with:

- changed files;
- reason for change;
- source comparison;
- build id;
- SHA256;
- test RPT;
- rollback notes.

---

# Preservation Note

This project is a digital preservation and reconstruction effort.

Because DayZ Origins server-side material was not fully or cleanly released for every version, some working builds require compatibility layers, community files, reconstructed scripts and careful comparison between available client/server/mission artifacts.

Whenever possible, preserve originals untouched and perform all work in reproducible rebuild/export directories.
