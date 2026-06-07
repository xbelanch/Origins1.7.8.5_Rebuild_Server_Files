# Admin Humanity Debug Helper

## Purpose

Adds an admin-only `Admin Tools -> Debug -> Humanity` menu for setting test humanity values used by Hero/Bandit-gated Origins mechanics.

## Thresholds Used

Audited Origins runtime checks classify humanity as:

- Survivor/neutral: `> 2000` and `< 2900`
- Hero L1: `>= 2900` and `< 6500`
- Hero L2: `>= 6500` and `<= 15000`
- Hero L3+: `> 15000`
- Bandit L1: `> -6500` and `<= 2000`
- Bandit L2: `>= -15000` and `<= -6500`
- Bandit L3+: `< -15000`

The menu uses safe probe values: `3000`, `7000`, `16000`, `21000`, `0`, `-3000`, `-7000`, `-16000`, and `-21000`.

## Security Model

- Client script: `MPMissions/dayz_1.origins.tavi/admintools/tools/a2edc_adminHumanityDebug.sqf`
- Server handler: `@dayz_1.origins.tavi/addons/dayz_server/compile/a2edc_adminHumanityDebug.sqf`
- Public variable request: `A2EDC_adminHumanityDebug`

The client never writes the humanity value. It sends a request to the server. The server validates:

- payload is an array
- player object is valid
- request UID matches `getPlayerUID` of the player object
- request characterID matches the server-side player object characterID
- requested humanity is numeric
- requested humanity is within `-1000000..1000000`
- UID is in the server-side admin UID sources, including `AdminList` when available

## Persistence

The handler first applies the value with server-side `setVariable ["humanity", value, true]`, then calls the existing legitimate sync path:

```sqf
[_player,[],true] call server_playerSync;
```

This uses `server_getDiff2` and `CHILD:201`, the same player sync path already used by normal character saves.

- Table affected: `Character_DATA`
- Column affected: `Humanity`
- Scope: current character, keyed by `CharacterID`
- Survives relog: yes, when the player has a valid non-zero `characterID`
- Global profile affected: no; `Player_DATA` is not modified
- If `characterID` is `"0"`: session value is applied and replicated, but persistence is skipped and logged as `persisted=false`

## Diagnostics

The helper logs:

- `A2EDC:ADMIN:HUMANITY_REQUEST`
- `A2EDC:ADMIN:HUMANITY_REFUSED`
- `A2EDC:ADMIN:HUMANITY_APPLY`
- `A2EDC:ADMIN:HUMANITY_SYNC`
- `A2EDC:ADMIN:HUMANITY_DONE`

Each server log includes UID, characterID, old humanity, requested humanity, applied humanity, source path, persisted state, and a reason.

## BattlEye

Updated:

- `dayz_1.origins.tavi/BattlEye/publicvariable.txt`
- `dayz_1.origins.tavi/BattlEye/scripts.txt`

Exported bundle:

- `Export/battleye_20260603-191200_admin-humanity-debug/`

The requested external Windows path was not mounted/reachable from this session:

- `C:\deadservers\origins-arma2-mod-rev\cfgorigins\BattlEye`
