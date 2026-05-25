private ["_vehicle","_class"];

_vehicle = _this select 0;

if (isNull _vehicle) exitWith {
	diag_log "A2EDC:WAI:PATROL_VEHICLE mode=transient class=<null> persistent=false result=skipped_null";
	false
};

_class = typeOf _vehicle;
_vehicle setVariable ["A2EDC_WAI_patrolVehicle",true,true];
_vehicle setVariable ["A2EDC_WAI_transientVehicle",true,true];
_vehicle setVariable ["ObjectID","0",true];
_vehicle setVariable ["ObjectUID","0",true];

if (!(isNil "PVDZE_serverObjectMonitor")) then {
	PVDZE_serverObjectMonitor = PVDZE_serverObjectMonitor - [_vehicle];
};
if (!(isNil "dayz_serverObjectMonitor")) then {
	dayz_serverObjectMonitor = dayz_serverObjectMonitor - [_vehicle];
};
if (!(isNil "serverObjectMonitor")) then {
	serverObjectMonitor = serverObjectMonitor - [_vehicle];
};

diag_log format ["A2EDC:WAI:PATROL_VEHICLE mode=transient class=%1 persistent=false",_class];
diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=created damage=%2 fuel=%3",_class,damage _vehicle,fuel _vehicle];

_vehicle addEventHandler ["HandleDamage",{
	private ["_vehicle","_damage","_source"];
	_vehicle = _this select 0;
	_damage = _this select 2;
	_source = objNull;
	if (count _this > 3) then {
		_source = _this select 3;
	};
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=hit damage=%2 source=%3",typeOf _vehicle,_damage,_source];
	_damage
}];

_vehicle addEventHandler ["Killed",{
	private ["_vehicle"];
	_vehicle = _this select 0;
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=killed damage=%2",typeOf _vehicle,damage _vehicle];
}];

_vehicle addEventHandler ["GetIn",{
	private ["_vehicle","_unit","_uid","_isAdmin","_adminUIDs"];
	_vehicle = _this select 0;
	_unit = _this select 2;
	_uid = "";
	if (isPlayer _unit) then {
		_uid = getPlayerUID _unit;
	};
	_adminUIDs = [];
	if (!(isNil "A2EDC_adminMissionLauncherUIDs")) then {
		if ((typeName A2EDC_adminMissionLauncherUIDs) == "ARRAY") then {
			_adminUIDs = _adminUIDs + A2EDC_adminMissionLauncherUIDs;
		};
	};
	if (!(isNil "A2EDC_adminUIDs")) then {
		if ((typeName A2EDC_adminUIDs) == "ARRAY") then {
			_adminUIDs = _adminUIDs + A2EDC_adminUIDs;
		};
	};
	if (!(isNil "AdminList")) then {
		if ((typeName AdminList) == "ARRAY") then {
			_adminUIDs = _adminUIDs + AdminList;
		};
	};
	_isAdmin = _uid in _adminUIDs;
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=getin_before damage=%2 fuel=%3 player=%4 uid=%5 isAdmin=%6",typeOf _vehicle,damage _vehicle,fuel _vehicle,name _unit,_uid,_isAdmin];
	[_vehicle,_unit,_uid,_isAdmin] spawn {
		private ["_vehicle","_unit","_uid","_isAdmin"];
		_vehicle = _this select 0;
		_unit = _this select 1;
		_uid = _this select 2;
		_isAdmin = _this select 3;
		sleep 1;
		if (!isNull _vehicle) then {
			diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=getin_after damage=%2 fuel=%3 player=%4 uid=%5 isAdmin=%6",typeOf _vehicle,damage _vehicle,fuel _vehicle,name _unit,_uid,_isAdmin];
		};
	};
}];

_vehicle addEventHandler ["GetOut",{
	private ["_vehicle","_unit","_uid"];
	_vehicle = _this select 0;
	_unit = _this select 2;
	_uid = "";
	if (isPlayer _unit) then {
		_uid = getPlayerUID _unit;
	};
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=getout damage=%2 fuel=%3 player=%4 uid=%5",typeOf _vehicle,damage _vehicle,fuel _vehicle,name _unit,_uid];
}];

true
