# House L1 operational context

## Stable baseline

- `dayz_code build_id=20260607-154328`
- `note=house-l1-preview-movement-decoupled-v1`
- PBO: `Export/dayz_code_20260607-154328_house-l1-preview-movement-decoupled-v1.pbo`
- SHA256: `9651298e7a9397b66f766a1abd6ac944c2e5f6619997f367f82ce0168efbd27e`
- PBO prefix: `z\addons\dayz_code`

## House L1 map

- Client flow: `Sandbox/origins_179_rebuild/dayz_code_merged_src/actions/player_BCeMix.sqf`, `actions/house_preview_confirm.sqf`, and `actions/bse_pp.sqf`.
- Client UI/config: `Sandbox/origins_179_rebuild/dayz_code_merged_src/rscTitles.hpp`.
- Server publish/lifecycle: `@dayz_1.origins.tavi/addons/dayz_server/compile/server_wantbbplz_a.sqf`, `compile/verbb_pas_a.sqf`, and `system/server_monitor.sqf`.
- Blueprints: `ItemBpt_b1` (bandit L1) and `ItemBpt_h1` (hero L1).
- Persistent classes: `wooden_shed_lvl_1` and `large_shed_lvl_1`; runtime/reload classes include `Uroven1DrevenaBudka` and `Uroven1VelkaBudka`.
- Material source: one nearby `CementMixer`.

## Materials and state

- Stage One: 15 `ItemRocks`, 25 `PartWoodPile`, 2 `PartScrap`, and 2 `ItemCementBag`.
- Stage Two (House L1): 25 `ItemRocks`, 35 `PartWoodPile`, 4 `PartScrap`, 4 `ItemCementBag`, 1 `ItemBattery`, and 1 `ItemPin`.
- Stage selections are `stage_1` and `stage_2`; completed state carries `passwordtut`.
- Wet/set is intentionally implicit: the freshly published foundation remains in its wet/transient identity state, and hive reload supplies the persistent object identity/runtime class before Stage Two is allowed.

## Next milestone

Pending: `house-l1-stage2-server-validation-v1`. Do not alter the validated preview/movement flow while adding it.
