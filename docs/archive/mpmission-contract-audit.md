> Historical document. Kept for reference. Current entrypoint: [../INDEX.md](../INDEX.md)

# First mpmission audit

**Entrypoint Map**
- [init.sqf](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:26)
  - Loads `Debug\variables.sqf`.
  - Loads vanilla `\z\addons\dayz_code\init\publicEH.sqf`.
  - Loads medical setup and `Debug\compiles.sqf`.
  - Overrides `player_spawn_2` with `debug\player_spawn_2.sqf`.
  - Server path starts vanilla `\z\addons\dayz_code\system\server_monitor.sqf`.
  - Client path starts `player_monitor`, login camera, KH refuel actions for non-admins, `core_time.fsm`, and admintools activation.
- [description.ext](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/description.ext:1)
  - Respawn/base mission config, channels, loading UI, `maxPlayers = 100`.
  - Includes `admintools\dialog.hpp`.
- [mission.sqm](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/mission.sqm:4)
  - Addons include `tavi`, `dayz_code`, `dayz_weapons`, `dayz_equip`, `dayz`.
  - Creates WEST playable slots using `Survivor1_DZ`; units start with simulation/damage disabled.
- [Debug/variables.sqf](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/variables.sqf:97)
  - Defines hive/server globals, self-action handles, medical vars, Origins globals such as `oriWverOtkr`.
- [Debug/compiles.sqf](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:15)
  - Main client override hub.
  - Replaces self-actions, damage actions, spawn check, drink, meds, pickup, damage handler, loot spawning.
  - Server clients compile `\z\addons\dayz_server\init\server_functions.sqf` when `isServer`.
- `BASTARDS/`
  - Custom replacements for damage, self-actions variant, spawn check, loot, meds, repair, retake, drink, pickup.
- `Debug/`
  - Active override layer: `compiles.sqf`, `variables.sqf`, `fn_selfActions.sqf`, `player_spawn_2.sqf`, self bloodbag.
- `Scripts/`
  - KH vehicle refuel loop/action.
- `admintools/`
  - Admin menu, teleport/spawn/heal/delete/vehicle tooling; several Epoch-style server PVs.
- `fix/`
  - Alternate `variables.sqf`; appears present but not loaded by current `init.sqf`.
- `Camera/`
  - Login camera waits on `dayzLoginRecord`.

**Mission-Side Server Communication**
- [init.sqf:28](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:28) loads `publicEH.sqf`.
  - Purpose: inherited DayZ public variable event handlers.
  - Receiver: external `dayz_code`, not mission-local.
- [init.sqf:55](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:55) starts `server_monitor.sqf`.
  - Purpose: server runtime bootstrap.
  - Receiver: server-local script.
- [Debug/player_spawn_2.sqf:303](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/player_spawn_2.sqf:303) `dayzDiscoRem`.
  - `publicVariableServer "dayzDiscoRem"` at line 304.
  - Purpose: remove UID from disconnect/combat timer tracking.
  - Likely receiver: server `publicEH_srv.sqf`, disco list handler.
- [Debug/player_spawn_2.sqf:317](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/player_spawn_2.sqf:317) `DOgNo_Se = [player,dayz_Magazines,false]`.
  - `publicVariableServer "DOgNo_Se"` at line 318.
  - Purpose: player sync/save request.
  - Likely receiver: server `publicEH_srv.sqf` -> `server_playerSync`.
- [BASTARDS/repair.sqf:34](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/BASTARDS/repair.sqf:34) `publicVariable "dayzSetFix"`.
  - Purpose: broadcast vehicle part fix state.
  - Receiver: DayZ object repair public EH / local object fix logic.
- [BASTARDS/repair.sqf:115](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/BASTARDS/repair.sqf:115) `dayUpdateVehlcle = [_vehicle,"repair"]`.
  - Server-local call `server_updatObiect` at line 118, otherwise `publicVariableServer "dayUpdateVehlcle"` at line 122.
  - Purpose: persist vehicle repair.
  - Likely receiver: server `publicEH_srv.sqf` -> `server_updatObiect`.
- [BASTARDS/retake.sqf:36](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/BASTARDS/retake.sqf:36) `publicVariable "dayzSetFix"`.
  - Purpose: broadcast removed/damaged part state.
  - Receiver: DayZ object fix handling.
- [BASTARDS/fn_damageHandler.sqf:170](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/BASTARDS/fn_damageHandler.sqf:170) `publicVariable "usecBIeed"`.
  - Purpose: medical bleed event propagation.
  - Receiver: DayZ medical public EH layer. Name looks like `BIeed` with capital `I`, worth preserving exactly.
- [core_time.fsm:148](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/core_time.fsm:148) `publicVariable "JipTimeNow"`.
  - Purpose: JIP time synchronization.
  - Receiver: clients/public EH time sync.
- [admintools/tools/addvehicle.sqf:43](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/addvehicle.sqf:43) `PVDZE_veh_Publish2`.
  - `publicVariableServer` at line 44.
  - Purpose: admin vehicle publish/spawn.
  - Likely receiver: Epoch-style server handler; not clearly detectable in this Origins server.
- [admintools/tools/malvehiclespawn.sqf:45](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/malvehiclespawn.sqf:45) `PVDZE_veh_Publish2`.
  - Same purpose/receiver risk as above.
- [admintools/tools/DatabaseRemove.sqf:27](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/DatabaseRemove.sqf:27) `PVDZE_obj_Delete`.
  - `publicVariableServer` at line 28; direct `server_deleteObj` call at line 30 if server.
  - Purpose: admin DB object delete.
  - Likely receiver: Epoch-style delete handler. Suspicious: server-side Origins function appears to be `server_udalitObj`, not `server_deleteObj`.
- [admintools/tools/deletebase.sqf:65](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/deletebase.sqf:65) `PVDZE_obj_Delete`.
  - Purpose: delete base object.
  - Receiver: likely Epoch-style; not clearly matched in Origins server.
- [admintools/tools/vehicle_lock.sqf:11](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/vehicle_lock.sqf:11) `PVDZE_veh_Lock`.
  - `publicVariable` at line 17.
  - Purpose: broadcast vehicle lock.
  - Receiver: likely Epoch local lock/unlock handler; not clearly mission-defined.
- [admintools/tools/vehicle_unlock.sqf:11](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/vehicle_unlock.sqf:11) `PVDZE_veh_Lock`.
  - Purpose: broadcast vehicle unlock.
  - Receiver: same as above.
- [admintools/tools/healp.sqf](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/admintools/tools/healp.sqf:1) broadcasts `usecBandage`, `usecTransfuse`, `usecMorphine`, `usecPainK`.
  - Purpose: admin medical heal actions.
  - Receiver: DayZ medical public EH functions compiled in `Debug/compiles.sqf`.

No mission-local `addPublicVariableEventHandler` definitions were found. No live mission-side references found for `oriUdalkaObj`, `DOdowndblink`, `dayzOrigingsL2`, `wantbbplz`, or `verbb_pas`. `oriWverOtkr` is initialized in [Debug/variables.sqf:236](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/variables.sqf:236) and [fix/variables.sqf:236](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/fix/variables.sqf:236), but I did not find a live mission-side send.

**Client Function Overrides**
- Self actions: [Debug/compiles.sqf:17](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:17) -> `Debug\fn_selfActions.sqf`.
- Damage actions: [Debug/compiles.sqf:15](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:15) -> `BASTARDS\fn_damageActions.sqf`.
- Damage handler: [Debug/compiles.sqf:409](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:409) -> `BASTARDS\fn_damageHandler.sqf`.
- Spawn check: [Debug/compiles.sqf:22](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:22) -> `BASTARDS\player_spawnCheck.sqf`.
- Spawn loop: [init.sqf:35](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:35) -> `Debug\player_spawn_2.sqf`.
- Loot: [Debug/compiles.sqf:432](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:432) -> `BASTARDS\spawn_loot.sqf`.
- Meds: [Debug/compiles.sqf:69](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Debug/compiles.sqf:69) -> `BASTARDS\player_useMeds.sqf`.
- Repair/remove part: self-actions use vanilla paths `\z\addons\dayz_code\actions\repair.sqf` and `retake.sqf`, but mission also contains `BASTARDS\repair.sqf` and `BASTARDS\retake.sqf`; actual runtime depends on whether external dayz_code paths are remapped/packed.
- Refuel: [init.sqf:75](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:75) starts `Scripts\kh_actions.sqf`; action calls [Scripts/kh_vehicle_refuel.sqf:27](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/Scripts/kh_vehicle_refuel.sqf:27).
- Admin tools: [init.sqf:83](/home/rotter/Coding/Origins1.7.8.5_Rebuild_Server_Files/MPMissions/dayz_1.origins.tavi/init.sqf:83) starts `admintools\Activate.sqf`.

**1.7.9 Compatibility Risks**
- Public variable payload compatibility: `DOgNo_Se = [player,dayz_Magazines,false]` is a custom save contract. Any 1.7.9-side `playerSync` shape change would be high risk.
- Origins-specific server variables: `dayUpdateVehlcle`, `oriWverOtkr`, and server-known but mission-quiet variables like `oriUdalkaObj`, `DOdowndblink`, `dayzOrigingsL2`, `wantbbplz`, `verbb_pas` are custom protocol surface.
- Epoch-style admin PVs: `PVDZE_veh_Publish2`, `PVDZE_obj_Delete`, `PVDZE_veh_Lock` may not be handled by the Origins 1.7.8.5 server unless compatibility handlers exist elsewhere.
- Custom self-action logic depends heavily on Origins class names, building classes, variables like `levelhouse`/`DaBeUpd`, and hard-coded action script paths.
- BattleEye-sensitive areas: admintools vehicle spawning/deletion/healing, public variable sends, local `setFuel`, teleport/spawn tools, and medical broadcasts.
- Class/item dependencies: custom women survivor classes, Origins base classes (`wooden_shed_lvl_1`, `object_x`, garages), backpacks, repair hitpoints, and `Land_A_FuelStation_Feed`.

**Minimal Mission-Side Tracing Plan**
Keep this opt-in and passive, same style as the server tracing:

- Add mission-side flags defaulting off, ideally loaded early after variables:
  - `A2EDC_MISSION_TRACE = false;`
  - `A2EDC_MISSION_TRACE_DEEP = false;`
- Add a tiny client helper that only `diag_log`s locally when enabled.
- Lowest-risk trace points:
  - `Debug/player_spawn_2.sqf`: log `dayzDiscoRem` UID and `DOgNo_Se` save event with player UID/name only; do not log `dayz_Magazines` unless deep tracing is true.
  - `BASTARDS/repair.sqf`: log `dayUpdateVehlcle` operation/class/object id if safely available.
  - `BASTARDS/fn_damageHandler.sqf`: log bleed event unit/name/wound only; avoid medical arrays.
  - Admin PV send scripts: log intended PV name and basic object/class/UID before `publicVariableServer`, but only when tracing is enabled.
  - `core_time.fsm`: avoid tracing unless diagnosing time sync specifically, because it can be noisy.
- Do not trace self-action loops broadly. If needed, trace only action creation for Origins building actions behind a separate deep flag, because `fn_selfActions` runs very frequently.

Best next manual inspection targets are `Debug/player_spawn_2.sqf`, `BASTARDS/repair.sqf`, `admintools/tools/DatabaseRemove.sqf`, and `admintools/tools/addvehicle.sqf`; those are the mission-side contract points most likely to affect server behavior.
