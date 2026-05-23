private["_args","_deathAlreadyHandled","_quickExitEnabled"];

_args = _this;
_deathAlreadyHandled = false;
if (!isNil "deathHandled") then {
	_deathAlreadyHandled = deathHandled;
};

_quickExitEnabled = "<nil>";
if (!isNil "A2EDC_QUICK_DEATH_EXIT") then {
	_quickExitEnabled = A2EDC_QUICK_DEATH_EXIT;
};

diag_log format [
	"[A2EDC:DEATH_UI] entered death flow player=%1 uid=%2 time=%3 quickExit=%4",
	name player,
	getPlayerUID player,
	time,
	_quickExitEnabled
];

_args call A2EDC_player_death_original;

if (!_deathAlreadyHandled) then {
	if (!isNil "A2EDC_QUICK_DEATH_EXIT") then {
		if (A2EDC_QUICK_DEATH_EXIT) then {
			[] spawn compile preprocessFileLineNumbers "Scripts\a2edc_quick_death_exit.sqf";
		};
	};
};
