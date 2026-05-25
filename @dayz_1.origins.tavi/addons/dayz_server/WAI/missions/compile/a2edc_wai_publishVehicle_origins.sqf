private ["_object","_worldspace","_class","_uid","_mode"];

_object = _this select 0;
_worldspace = _this select 1;
_class = _this select 2;

if (isNil "A2EDC_WAI_vehiclePersistenceMode") then {
	A2EDC_WAI_vehiclePersistenceMode = "transient";
};

_mode = A2EDC_WAI_vehiclePersistenceMode;

if (isNull _object) exitWith {
	diag_log format ["A2EDC:WAI:PUBLISH mode=%1 class=%2 uid=<null> persistent=false reason=null_object",_mode,_class];
	false
};

_uid = _worldspace call dayz_objectUID2;

if (_mode == "transient") exitWith {
	_object setVariable ["A2EDC_WAI_transientVehicle",true,true];
	_object setVariable ["A2EDC_WAI_publishPendingObjectID",false,true];
	_object setVariable ["A2EDC_WAI_publishFailedObjectID",false,true];
	_object setVariable ["ObjectID","0",true];
	_object setVariable ["ObjectUID",_uid,true];

	if (!(isNil "PVDZE_serverObjectMonitor")) then {
		PVDZE_serverObjectMonitor = PVDZE_serverObjectMonitor - [_object];
	};
	if (!(isNil "dayz_serverObjectMonitor")) then {
		dayz_serverObjectMonitor = dayz_serverObjectMonitor - [_object];
	};
	if (!(isNil "serverObjectMonitor")) then {
		serverObjectMonitor = serverObjectMonitor - [_object];
	};

	diag_log format ["A2EDC:WAI:PUBLISH mode=transient class=%1 uid=%2 persistent=false",_class,_uid];
	if (!(isNil "A2EDC_fnc_traceObjectState")) then {
		["WAI:PUBLISH", format ["transient publish uid=%1 persistent=false",_uid], _object] call A2EDC_fnc_traceObjectState;
	};

	true
};

diag_log format ["A2EDC:WAI:PUBLISH mode=%1 class=%2 uid=%3 persistent=false reason=unsupported_mode",_mode,_class,_uid];
false
