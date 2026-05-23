private["_delay","_autoExit","_autoDelay","_display","_keyHandler","_startTime","_shouldExit","_dead"];

_delay = 8;
if (!isNil "A2EDC_QUICK_DEATH_EXIT_DELAY") then {
	_delay = A2EDC_QUICK_DEATH_EXIT_DELAY;
};

_autoExit = false;
if (!isNil "A2EDC_QUICK_DEATH_AUTO_EXIT") then {
	_autoExit = A2EDC_QUICK_DEATH_AUTO_EXIT;
};

_autoDelay = 25;
if (!isNil "A2EDC_QUICK_DEATH_AUTO_EXIT_DELAY") then {
	_autoDelay = A2EDC_QUICK_DEATH_AUTO_EXIT_DELAY;
};

sleep _delay;

_dead = false;
if (!alive player) then {
	_dead = true;
};
if (!isNil "r_player_dead") then {
	if (r_player_dead) then {
		_dead = true;
	};
};
if (!_dead) exitWith {
	diag_log "[A2EDC:DEATH_UI] quick death exit skipped because player is not dead";
};

A2EDC_QUICK_DEATH_EXIT_REQUESTED = false;

A2EDC_fnc_quickDeathExitKeyDown = {
	private["_dikCode","_handled","_dead"];
	_dikCode = _this select 1;
	_handled = false;
	if (_dikCode == A2EDC_QUICK_DEATH_EXIT_KEY) then {
		_dead = false;
		if (!alive player) then {
			_dead = true;
		};
		if (!isNil "r_player_dead") then {
			if (r_player_dead) then {
				_dead = true;
			};
		};
		if (_dead) then {
			A2EDC_QUICK_DEATH_EXIT_REQUESTED = true;
			diag_log "[A2EDC:DEATH_UI] quick death exit key pressed";
			_handled = true;
		};
	};
	_handled
};

disableSerialization;
waitUntil {
	_display = findDisplay 46;
	!isNull _display
};

diag_log format [
	"[A2EDC:DEATH_UI:DISPLAY] display=%1 dead=%2 alive=%3 r_player_dead=%4",
	_display,
	!alive player,
	alive player,
	if (isNil "r_player_dead") then {"<nil>"} else {r_player_dead}
];

_keyHandler = _display displayAddEventHandler ["KeyDown","_this call A2EDC_fnc_quickDeathExitKeyDown"];
diag_log "[A2EDC:DEATH_UI] quick death exit prompt shown";

titleText [
	"You are dead.\n\nPress SPACE to return to the lobby / respawn pool.",
	"PLAIN DOWN"
];

_startTime = time;
_shouldExit = false;
while {!_shouldExit} do {
	if (A2EDC_QUICK_DEATH_EXIT_REQUESTED) then {
		_shouldExit = true;
	};
	if (_autoExit) then {
		if ((time - _startTime) >= _autoDelay) then {
			diag_log "[A2EDC:DEATH_UI] quick death auto-exit timeout reached";
			_shouldExit = true;
		};
	};
	sleep 0.25;
};

_display displayRemoveEventHandler ["KeyDown",_keyHandler];

diag_log "[A2EDC:DEATH_UI] executing return-to-lobby action";
diag_log format [
	"[A2EDC:DEATH_UI:EXIT_TO_POOL] uid=%1 charID=%2 time=%3",
	getPlayerUID player,
	if (isNil "dayz_characterID") then {"<nil>"} else {dayz_characterID},
	time
];
endMission "END1";
