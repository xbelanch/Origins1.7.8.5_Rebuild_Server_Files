if (!isServer) exitWith {};
private ["_mission","_veh"];
_veh = _this select 0;
if (count _this == 2) then {
	_mission = _this select 1;
} else {
	_mission = false;
};
waitUntil { count crew _veh > 0};
while {(alive _veh) and ({alive _x} count crew _veh > 0)} do {
	_veh setVehicleAmmo 1;
	_veh setFuel 1;
	if (_veh getVariable ["A2EDC_WAI_patrolVehicle",false]) then {
		diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=monitor damage=%2 fuel=%3 crewAlive=%4",typeOf _veh,damage _veh,fuel _veh,{alive _x} count crew _veh];
	};
	if ({alive _x} count crew _veh == 0) then {
		_veh setDamage 1;
		_veh setVariable ["killedat", time];
		if (_veh getVariable ["A2EDC_WAI_patrolVehicle",false]) then {
			diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=crew_dead damage=%2",typeOf _veh,damage _veh];
		};
	};
	if ((_mission) AND (clean_running_mission)) then {
		_veh setDamage 1;
		_veh setVariable ["killedat", time];
		if (_veh getVariable ["A2EDC_WAI_patrolVehicle",false]) then {
			diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=mission_cleanup damage=%2",typeOf _veh,damage _veh];
		};
	};
	sleep 30;
};
_veh setDamage 1;
_veh setVariable ["killedat", time];
if (_veh getVariable ["A2EDC_WAI_patrolVehicle",false]) then {
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=cleanup damage=%2",typeOf _veh,damage _veh];
};
