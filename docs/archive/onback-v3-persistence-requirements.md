> Historical document. Kept for reference. Current entrypoint: [../INDEX.md](../INDEX.md)

# onBack v3 Persistence Requirements

Do not implement this until explicitly authorized.

## Inventory Shape

- Continue accepting legacy inventory arrays shaped as `[weapons, magazines]`.
- Add support for v3 inventory arrays shaped as `[weapons, magazines, onBack]`.
- Treat `onBack` as valid only when `inventory select 2` exists and is a string.
- Use migration guards for any older or malformed inventory shape.

## Client Restore and Transitions

- `player_gearSet` reads `inventory select 2` when it exists and is a string, then restores `A2EDC_onBack`.
- `player_death` preserves or drops `A2EDC_onBack` according to the final death/drop design.
- `player_humanityMorph` preserves `A2EDC_onBack` across morph/switch-model transitions.
- Disconnect and morph sync paths preserve `A2EDC_onBack`.

## Server Sync and Login

- `server_playerSync` writes `[weapons, magazines, A2EDC_onBack]`.
- Login/playLogni accepts both `[weapons, magazines]` and `[weapons, magazines, onBack]`.
- Server-side guards must not drop or overwrite `onBack` when handling legacy records.
