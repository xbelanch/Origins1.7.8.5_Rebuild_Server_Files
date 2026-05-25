private ["_vehicle","_mission","_state","_reason","_uid","_class","_locked"];

_vehicle = _this select 0;
_mission = _this select 1;
_state = _this select 2;
_reason = _this select 3;

if (isNull _vehicle) exitWith {
	diag_log format ["A2EDC:WAI:VEHICLE_LOCK mission=%1 class=<null> uid=<null> state=%2 reason=%3 result=skipped_null",_mission,_state,_reason];
	false
};

_class = typeOf _vehicle;
_uid = _vehicle getVariable ["ObjectUID","0"];
_locked = (_state == "locked");

if (_locked) then {
	_vehicle setVehicleLock "LOCKED";
	_vehicle lock true;
} else {
	_vehicle setVehicleLock "UNLOCKED";
	_vehicle lock false;
};

diag_log format ["A2EDC:WAI:VEHICLE_LOCK mission=%1 class=%2 uid=%3 state=%4 reason=%5",_mission,_class,_uid,_state,_reason];
true
