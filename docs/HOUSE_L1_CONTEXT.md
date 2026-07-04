# House L1 operational context

## Lifecycle

`Stage One` consumeix materials i publica una foundation humida/transitòria. Després d'un reload del hive, la identitat persistent/runtime representa la foundation set i permet `Stage Two`. Stage Two completa la casa, aplica el PIN/code lock i deixa la casa final persistent.

El model wet/set és implícit per reload: no s'ha d'afegir una transició client-only. La validació autoritativa de Stage Two és el milestone pendent.

## Mapa funcional

- Client: `Sandbox/origins_179_rebuild/dayz_code_merged_src/actions/player_BCeMix.sqf`, `actions/house_preview_confirm.sqf`, `actions/bse_pp.sqf`.
- UI: `Sandbox/origins_179_rebuild/dayz_code_merged_src/rscTitles.hpp`.
- Servidor: `@dayz_1.origins.tavi/addons/dayz_server/compile/server_wantbbplz_a.sqf`, `compile/verbb_pas_a.sqf`, `system/server_monitor.sqf`.
- Blueprints: `ItemBpt_b1` (bandit) i `ItemBpt_h1` (hero).
- Classes persistents: `wooden_shed_lvl_1`, `large_shed_lvl_1`.
- Classes runtime/reload: `Uroven1DrevenaBudka`, `Uroven1VelkaBudka`.
- Font de materials: un `CementMixer` proper.

## Materials i estat

- Stage One: 15 `ItemRocks`, 25 `PartWoodPile`, 2 `PartScrap`, 2 `ItemCementBag`.
- Stage Two: 25 `ItemRocks`, 35 `PartWoodPile`, 4 `PartScrap`, 4 `ItemCementBag`, 1 `ItemBattery`, 1 `ItemPin`.
- Selections: `stage_1`, `stage_2`; l'estat completat porta `passwordtut`.

## Estat actual

La baseline `20260607-154328` (`house-l1-preview-movement-decoupled-v1`) és estable. Vegeu [CURRENT_BASELINE.md](CURRENT_BASELINE.md). Següent milestone: `house-l1-stage2-server-validation-v1`.
