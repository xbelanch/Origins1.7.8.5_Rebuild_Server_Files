private ["_payload","_player","_uid","_name","_clientCharID","_requested","_sourcePath","_clientOldHumanity","_playerUID","_charID","_oldHumanity","_adminUIDs","_authSource","_isAdmin","_persisted","_applied","_ownerID","_applyPayload"];

_payload = _this;
_persisted = false;

if ((typeName _payload) != "ARRAY") exitWith {
	diag_log "A2EDC:ADMIN:HUMANITY_REFUSED uid=<invalid> characterID=<invalid> oldHumanity=<invalid> requestedHumanity=<invalid> appliedHumanity=<invalid> sourcePath=server persisted=false reason=payload_not_array";
};

if ((count _payload) < 7) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=<invalid> characterID=<invalid> oldHumanity=<invalid> requestedHumanity=<invalid> appliedHumanity=<invalid> sourcePath=server persisted=false reason=payload_too_short payloadCount=%1",count _payload];
};

_player = _payload select 0;
_uid = _payload select 1;
_name = _payload select 2;
_clientCharID = _payload select 3;
_requested = _payload select 4;
_sourcePath = _payload select 5;
_clientOldHumanity = _payload select 6;

diag_log format ["A2EDC:ADMIN:HUMANITY_REQUEST uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=<pending> sourcePath=%5 persisted=false reason=received name=%6 payload=%7",_uid,_clientCharID,_clientOldHumanity,_requested,_sourcePath,_name,_payload];

if ((typeName _player) != "OBJECT") exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=player_not_object",_uid,_clientCharID,_clientOldHumanity,_requested,_clientOldHumanity,_sourcePath];
};

if (isNull _player) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=player_null",_uid,_clientCharID,_clientOldHumanity,_requested,_clientOldHumanity,_sourcePath];
};

_playerUID = getPlayerUID _player;
_charID = _player getVariable ["characterID","0"];
_oldHumanity = _player getVariable ["humanity",0];

if (_playerUID != _uid) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=uid_mismatch playerUID=%7",_uid,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath,_playerUID];
};

if (_charID != _clientCharID) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=character_mismatch clientCharacterID=%7",_playerUID,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath,_clientCharID];
};

if ((typeName _requested) != "SCALAR") exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=non_numeric",_playerUID,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath];
};

if ((_requested < -1000000) || (_requested > 1000000)) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=value_out_of_bounds",_playerUID,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath];
};

if ((typeName _sourcePath) != "STRING") then {
	_sourcePath = "AdminTools.Debug.Humanity.unknown";
};

if (isNil "A2EDC_adminHumanityUIDs") then {
	A2EDC_adminHumanityUIDs = [
		"76561198024951069"
	];
};

_adminUIDs = [];
_authSource = "none";

if (!isNil "A2EDC_adminHumanityUIDs") then {
	if ((typeName A2EDC_adminHumanityUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminHumanityUIDs;
		_authSource = "A2EDC_adminHumanityUIDs";
	};
};

if (!isNil "A2EDC_adminBuildingKitUIDs") then {
	if ((typeName A2EDC_adminBuildingKitUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminBuildingKitUIDs;
		if (_authSource == "none") then {_authSource = "A2EDC_adminBuildingKitUIDs";} else {_authSource = _authSource + "+A2EDC_adminBuildingKitUIDs";};
	};
};

if (!isNil "A2EDC_adminMissionLauncherUIDs") then {
	if ((typeName A2EDC_adminMissionLauncherUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminMissionLauncherUIDs;
		if (_authSource == "none") then {_authSource = "A2EDC_adminMissionLauncherUIDs";} else {_authSource = _authSource + "+A2EDC_adminMissionLauncherUIDs";};
	};
};

if (!isNil "A2EDC_adminUIDs") then {
	if ((typeName A2EDC_adminUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminUIDs;
		if (_authSource == "none") then {_authSource = "A2EDC_adminUIDs";} else {_authSource = _authSource + "+A2EDC_adminUIDs";};
	};
};

if (!isNil "AdminList") then {
	if ((typeName AdminList) == "ARRAY") then {
		_adminUIDs = _adminUIDs + AdminList;
		if (_authSource == "none") then {_authSource = "AdminList";} else {_authSource = _authSource + "+AdminList";};
	};
};

_isAdmin = _playerUID in _adminUIDs;
if (!_isAdmin) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=not_admin adminCount=%7 source=%8",_playerUID,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath,count _adminUIDs,_authSource];
};

_applied = round _requested;
diag_log format ["A2EDC:ADMIN:HUMANITY_APPLY uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=server_setVariable authSource=%7",_playerUID,_charID,_oldHumanity,_requested,_applied,_sourcePath,_authSource];

_player setVariable ["humanity",_applied,true];

if (_charID != "0") then {
	diag_log format ["A2EDC:ADMIN:HUMANITY_SYNC uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=true reason=server_playerSync_child201_character_data",_playerUID,_charID,_oldHumanity,_requested,_applied,_sourcePath];
	[_player,[],true] call server_playerSync;
	_persisted = true;
} else {
	diag_log format ["A2EDC:ADMIN:HUMANITY_SYNC uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=no_characterID_session_only",_playerUID,_charID,_oldHumanity,_requested,_applied,_sourcePath];
};

_ownerID = owner _player;
_applyPayload = [_playerUID,_charID,_oldHumanity,_applied,_sourcePath,_persisted];
A2EDC_adminHumanityApply = _applyPayload;
_ownerID publicVariableClient "A2EDC_adminHumanityApply";
diag_log format ["A2EDC:ADMIN:HUMANITY_SYNC uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=%7 reason=publicVariableClient owner=%8 payload=%9",_playerUID,_charID,_oldHumanity,_requested,_applied,_sourcePath,_persisted,_ownerID,_applyPayload];

diag_log format ["A2EDC:ADMIN:HUMANITY_DONE uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=%7 reason=ok",_playerUID,_charID,_oldHumanity,_requested,_applied,_sourcePath,_persisted];
