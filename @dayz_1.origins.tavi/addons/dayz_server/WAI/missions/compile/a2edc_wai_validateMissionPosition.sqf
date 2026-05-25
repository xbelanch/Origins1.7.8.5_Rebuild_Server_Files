private ["_position","_mission","_flat","_reason","_ok"];

_position = _this select 0;
_mission = _this select 1;

_reason = "ok";
_ok = true;

if (surfaceIsWater _position) then {
	_ok = false;
	_reason = "water";
};

if (_ok) then {
	_flat = _position isFlatEmpty [10,0,0.35,10,0,false,objNull];
	if (count _flat == 0) then {
		_ok = false;
		_reason = "not_flat";
	};
};

diag_log format ["A2EDC:WAI:TERRAIN mission=%1 position=%2 result=%3 reason=%4",_mission,_position,_ok,_reason];

[_ok,_reason]
