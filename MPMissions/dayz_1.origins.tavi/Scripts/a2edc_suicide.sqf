private["_uid","_charID","_blocked","_reason","_method","_source"];

_uid = getPlayerUID player;
_charID = "<nil>";
if (!isNil "dayz_characterID") then {
	_charID = dayz_characterID;
};

diag_log format [
	"[A2EDC:SUICIDE] requested uid=%1 name=%2 charID=%3 alive=%4 r_player_dead=%5 unconscious=%6 deathHandled=%7 inProgress=%8",
	_uid,
	name player,
	_charID,
	alive player,
	if (isNil "r_player_dead") then {"<nil>"} else {r_player_dead},
	if (isNil "r_player_unconscious") then {"<nil>"} else {r_player_unconscious},
	if (isNil "deathHandled") then {"<nil>"} else {deathHandled},
	if (isNil "A2EDC_suicideInProgress") then {"<nil>"} else {A2EDC_suicideInProgress}
];

if (isNil "A2EDC_ENABLE_PLAYER_SUICIDE") then {
	A2EDC_ENABLE_PLAYER_SUICIDE = true;
};
if (isNil "A2EDC_suicideInProgress") then {
	A2EDC_suicideInProgress = false;
};

_blocked = false;
_reason = "";

if (!A2EDC_ENABLE_PLAYER_SUICIDE) then {
	_blocked = true;
	_reason = "config-disabled";
};
if (!_blocked) then {
	if (A2EDC_suicideInProgress) then {
		_blocked = true;
		_reason = "in-progress";
	};
};
if (!_blocked) then {
	if (!alive player) then {
		_blocked = true;
		_reason = "already-dead";
	};
};
if (!_blocked) then {
	if (!isNil "r_player_dead") then {
		if (r_player_dead) then {
			_blocked = true;
			_reason = "death-flow-active";
		};
	};
};
if (!_blocked) then {
	if (!isNil "deathHandled") then {
		if (deathHandled) then {
			_blocked = true;
			_reason = "death-handled";
		};
	};
};
if (!_blocked) then {
	if (!isNil "r_player_unconscious") then {
		if (r_player_unconscious) then {
			_blocked = true;
			_reason = "unconscious";
		};
	};
};

if (_blocked) exitWith {
	diag_log format [
		"[A2EDC:SUICIDE] blocked reason=%1 uid=%2 charID=%3 alive=%4",
		_reason,
		_uid,
		_charID,
		alive player
	];
};

A2EDC_suicideInProgress = true;

_method = "a2edc_suicide";
_source = player;

titleText ["You chose to end your life.", "PLAIN DOWN"];
diag_log format ["[A2EDC:SUICIDE] invoking player_death uid=%1 charID=%2 method=%3",_uid,_charID,_method];

player allowDamage true;

[_source,_method] spawn player_death;

[] spawn {
	sleep 1;
	if (alive player) then {
		diag_log "[A2EDC:SUICIDE] fallback setDamage=1 because player is still alive after player_death invoke";
		player setDamage 1;
	};
};
