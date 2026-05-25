private ["_payload","_player","_uid","_name","_subsystem","_mission","_result","_reason","_playerUID","_adminUIDs","_authSource","_isAdmin","_allowed"];

_payload = _this;
_result = "refused";
_reason = "unknown";

if ((typeName _payload) != "ARRAY") exitWith {
	diag_log "[A2EDC:ADMIN:MISSION_LAUNCH] uid=<invalid> name=<invalid> subsystem=<invalid> mission=<invalid> result=refused reason=payload_not_array";
};

if ((count _payload) < 5) exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=<invalid> name=<invalid> subsystem=<invalid> mission=<invalid> result=refused reason=payload_too_short payloadCount=%1",count _payload];
};

_player = _payload select 0;
_uid = _payload select 1;
_name = _payload select 2;
_subsystem = _payload select 3;
_mission = _payload select 4;

if ((typeName _player) != "OBJECT") exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=player_not_object",_uid,_name,_subsystem,_mission];
};

if (isNull _player) exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=player_null",_uid,_name,_subsystem,_mission];
};

_playerUID = getPlayerUID _player;
if (_playerUID != _uid) exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=uid_mismatch playerUID=%5",_uid,_name,_subsystem,_mission,_playerUID];
};

if (isNil "A2EDC_adminMissionLauncherUIDs") then {
	A2EDC_adminMissionLauncherUIDs = [
		"76561198024951069"
	];
};

_adminUIDs = [];
_authSource = "none";

if (!isNil "A2EDC_adminMissionLauncherUIDs") then {
	if ((typeName A2EDC_adminMissionLauncherUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminMissionLauncherUIDs;
		_authSource = "A2EDC_adminMissionLauncherUIDs";
	};
};

if (!isNil "A2EDC_adminUIDs") then {
	if ((typeName A2EDC_adminUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminUIDs;
		if (_authSource == "none") then {
			_authSource = "A2EDC_adminUIDs";
		} else {
			_authSource = _authSource + "+A2EDC_adminUIDs";
		};
	};
};

if (!isNil "AdminList") then {
	if ((typeName AdminList) == "ARRAY") then {
		_adminUIDs = _adminUIDs + AdminList;
		if (_authSource == "none") then {
			_authSource = "AdminList";
		} else {
			_authSource = _authSource + "+AdminList";
		};
	};
};

_isAdmin = _playerUID in _adminUIDs;
diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH_AUTH] uid=%1 playerUID=%2 adminCount=%3 isAdmin=%4 source=%5",_uid,_playerUID,count _adminUIDs,_isAdmin,_authSource];

if (!_isAdmin) exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=not_admin",_playerUID,_name,_subsystem,_mission];
};

if (_subsystem == "WAI") exitWith {
	_allowed = [
		"armed_vehicle",
		"mayors_mansion",
		"MV22",
		"C130_crash",
		"bandit_base",
		"convoy",
		"crash_spawner",
		"disabled_civchopper",
		"disabled_milchopper",
		"ems_cache",
		"medi_camp",
		"Ural",
		"weapon_cache"
	];

	if (!(_mission in _allowed)) exitWith {
		diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=WAI mission=%3 result=refused reason=not_whitelisted",_uid,_name,_mission];
	};

	if (isNil "WAImissionconfig") exitWith {
		diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=WAI mission=%3 result=refused reason=wai_not_initialized",_uid,_name,_mission];
	};

	if (isNil "missionrunning") then {missionrunning = false;};
	if (missionrunning) exitWith {
		diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=WAI mission=%3 result=refused reason=mission_already_active",_uid,_name,_mission];
	};

	if (isNil "markerready") then {markerready = true;};
	if (!markerready) exitWith {
		diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=WAI mission=%3 result=refused reason=marker_not_ready",_uid,_name,_mission];
	};

	clean_running_mission = false;
	missionrunning = true;
	execVM format ["\z\addons\dayz_server\WAI\missions\missions\%1.sqf",_mission];
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=WAI mission=%3 result=started reason=manual_admin_launch",_uid,_name,_mission];
};

if ((_subsystem == "DZMS_MAJOR") || (_subsystem == "DZMS_MINOR")) exitWith {
	diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=dzms_manual_launch_not_enabled",_uid,_name,_subsystem,_mission];
};

diag_log format ["[A2EDC:ADMIN:MISSION_LAUNCH] uid=%1 name=%2 subsystem=%3 mission=%4 result=refused reason=unknown_subsystem",_uid,_name,_subsystem,_mission];
