# A2EDC Admin Mission Launcher

## Scope

Debug/admin-only launcher for WAI mission validation. The first validation target is `WAI -> armed_vehicle` for the v6 AI class fallback path.

Client requests use `A2EDC_adminMissionLaunch` and include `[player, uid, name, subsystem, mission]`. The server handler validates:

- payload shape
- player object is non-null
- payload UID matches `getPlayerUID _player`
- UID is in `AdminList`
- subsystem and mission are whitelisted
- WAI is initialized
- no WAI mission is already active via `missionrunning`

DZMS menu entries are inventoried in the admin UI, but the server refuses DZMS manual launches in this pass with `reason=dzms_manual_launch_not_enabled`.

## Mission Inventory

| subsystem | mission_id | source_file | scheduler_path | callable_directly_yes_no | notes |
| --- | --- | --- | --- | --- | --- |
| WAI | armed_vehicle | `WAI/missions/missions/armed_vehicle.sqf` | `WAI/missions/Missions.sqf` -> `execVM .../%1.sqf` | yes | Primary v6 test. Uses `missionrunning`, `clean_running_mission`, WAI timeout, `spawn_group`, `spawn_static`, and `custom_publish`. |
| WAI | mayors_mansion | `WAI/missions/missions/mayors_mansion.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | MV22 | `WAI/missions/missions/MV22.sqf` | same WAI scheduler path | yes | Vehicle publish after player presence. |
| WAI | C130_crash | `WAI/missions/missions/C130_crash.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | bandit_base | `WAI/missions/missions/bandit_base.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | convoy | `WAI/missions/missions/convoy.sqf` | same WAI scheduler path | yes | Publishes multiple vehicles after player presence. |
| WAI | crash_spawner | `WAI/missions/missions/crash_spawner.sqf` | same WAI scheduler path | yes | Sets `missionrunning = true` internally too. |
| WAI | disabled_civchopper | `WAI/missions/missions/disabled_civchopper.sqf` | same WAI scheduler path | yes | Vehicle publish after player presence. |
| WAI | disabled_milchopper | `WAI/missions/missions/disabled_milchopper.sqf` | same WAI scheduler path | yes | Vehicle publish after player presence. |
| WAI | ems_cache | `WAI/missions/missions/ems_cache.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | medi_camp | `WAI/missions/missions/medi_camp.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | Ural | `WAI/missions/missions/Ural.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| WAI | weapon_cache | `WAI/missions/missions/weapon_cache.sqf` | same WAI scheduler path | yes | Uses WAI mission globals and timeout. |
| DZMS_MAJOR | SM1 | `DZMS/Missions/Major/SM1.sqf` | `DZMS/Scripts/DZMSMajTimer.sqf` -> `execVM .../Major/%1.sqf` | no | Refused in this pass. Timer waits on `DZMSMajDone`; direct start needs timer coordination. |
| DZMS_MAJOR | SM2 | `DZMS/Missions/Major/SM2.sqf` | same DZMS major scheduler path | no | Refused in this pass. Uses `DZMSUnitsMajor`, `DZMSMajDone`. |
| DZMS_MAJOR | SM3 | `DZMS/Missions/Major/SM3.sqf` | same DZMS major scheduler path | no | Refused in this pass. Uses `DZMSUnitsMajor`, `DZMSMajDone`. |
| DZMS_MAJOR | SM4 | `DZMS/Missions/Major/SM4.sqf` | same DZMS major scheduler path | no | Refused in this pass. Uses `DZMSUnitsMajor`, `DZMSMajDone`. |
| DZMS_MAJOR | SM5 | `DZMS/Missions/Major/SM5.sqf` | same DZMS major scheduler path | no | Refused in this pass. Uses `DZMSUnitsMajor`, `DZMSMajDone`. |
| DZMS_MAJOR | SM6 | `DZMS/Missions/Major/SM6.sqf` | same DZMS major scheduler path | no | Refused in this pass. Uses `DZMSUnitsMajor`, `DZMSMajDone`. |
| DZMS_MAJOR | EM1 | `DZMS/Missions/Major/EM1.sqf` | major file exists but is not in `DZMSMajorArray` | no | Refused in this pass. Not randomly scheduled by current config. |
| DZMS_MINOR | SM1 | `DZMS/Missions/Minor/SM1.sqf` | `DZMS/Scripts/DZMSMinTimer.sqf` -> `execVM .../Minor/%1.sqf` | no | Refused in this pass. Timer waits on `DZMSMinDone`; direct start needs timer coordination. |
| DZMS_MINOR | SM2 | `DZMS/Missions/Minor/SM2.sqf` | same DZMS minor scheduler path | no | Refused in this pass. Uses `DZMSUnitsMinor`, `DZMSMinDone`. |
| DZMS_MINOR | SM3 | `DZMS/Missions/Minor/SM3.sqf` | same DZMS minor scheduler path | no | Refused in this pass. Uses `DZMSUnitsMinor`, `DZMSMinDone`. |
| DZMS_MINOR | SM4 | `DZMS/Missions/Minor/SM4.sqf` | same DZMS minor scheduler path | no | Refused in this pass. Uses `DZMSUnitsMinor`, `DZMSMinDone`. |
| DZMS_MINOR | SM5 | `DZMS/Missions/Minor/SM5.sqf` | same DZMS minor scheduler path | no | Refused in this pass. Uses `DZMSUnitsMinor`, `DZMSMinDone`. |
| DZMS_MINOR | SM6 | `DZMS/Missions/Minor/SM6.sqf` | same DZMS minor scheduler path | no | Refused in this pass. Uses `DZMSUnitsMinor`, `DZMSMinDone`. |

## BattleEye Impact

- Public variable: `A2EDC_adminMissionLaunch`
- `publicvariable.txt`: whitelists only `A2EDC_adminMissionLaunch`
- `scripts.txt`: whitelists only `publicVariableServer "A2EDC_adminMissionLaunch";`
- `publicvariableval.txt`: no change expected; payload is fixed data, not an exec path
- `remoteexec.txt`: no change; no `remoteExec` is used

## v6 Validation Flow

1. Deploy the exported v6-plus-launcher `dayz_server.pbo` and mission PBO manually.
2. Start the server.
3. Confirm RPT contains `[A2EDC:BUILD] ... note=wai-ai-unit-cleanup-v6-admin-mission-launcher`.
4. In game, open `Admin Menu -> Missions -> WAI -> armed_vehicle`.
5. Confirm RPT contains `A2EDC:ADMIN:MISSION_LAUNCH ... subsystem=WAI mission=armed_vehicle result=started`.
6. Confirm there are no `Cannot create entity with abstract type Ins_Soldier_Sapper` or `Cannot create non-ai vehicle Ins_Soldier_Sapper` errors.
7. Confirm RPT contains `A2EDC:WAI:AI_CLASS:SKIP_INVALID ... class=Ins_Soldier_Sapper ... fallback=Bandit2_3DZ`.
8. Confirm the WAI group still spawns and boot/login/DZMS remain clean.
