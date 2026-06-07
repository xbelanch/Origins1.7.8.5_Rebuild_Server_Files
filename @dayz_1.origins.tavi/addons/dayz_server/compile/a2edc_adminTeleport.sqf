private ["_payload","_requester","_uid","_name","_charID","_mode","_targetPos","_targetUID","_targetName","_clientOldPos","_playerUID","_adminUIDs","_authSource","_isAdmin","_allowedModes","_targetObj","_teleportObj","_resolvedTargetPos","_teleportOwner","_teleportCharID","_payloadOut","_refused"];

_payload = _this;

if ((typeName _payload) != "ARRAY") exitWith {
	diag_log "A2EDC:ADMIN:TELEPORT_REFUSED uid=<invalid> charID=<invalid> mode=<invalid> reason=payload_not_array";
};

if ((count _payload) < 9) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=<invalid> charID=<invalid> mode=<invalid> reason=payload_too_short payload=%1",_payload];
};

_requester = _payload select 0;
_uid = _payload select 1;
_name = _payload select 2;
_charID = _payload select 3;
_mode = _payload select 4;
_targetPos = _payload select 5;
_targetUID = _payload select 6;
_targetName = _payload select 7;
_clientOldPos = _payload select 8;

if ((typeName _requester) != "OBJECT") exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=requester_not_object",_uid,_charID,_mode,_clientOldPos,_targetPos];
};

if (isNull _requester) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=requester_null",_uid,_charID,_mode,_clientOldPos,_targetPos];
};

diag_log format ["A2EDC:ADMIN:TELEPORT_REQUEST side=server uid=%1 charID=%2 name=%3 mode=%4 oldPos=%5 targetPos=%6 targetUID=%7 targetName=%8 requester=%9 locality=%10 owner=%11",_uid,_charID,_name,_mode,_clientOldPos,_targetPos,_targetUID,_targetName,_requester,local _requester,owner _requester];

_playerUID = getPlayerUID _requester;
if (_playerUID != _uid) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=uid_mismatch playerUID=%6",_uid,_charID,_mode,_clientOldPos,_targetPos,_playerUID];
};

if (vehicle _requester != _requester) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=requester_in_vehicle",_uid,_charID,_mode,_clientOldPos,_targetPos];
};

_adminUIDs = [];
_authSource = "none";

if (isNil "A2EDC_adminTeleportUIDs") then {
	A2EDC_adminTeleportUIDs = [
		"76561198024951069"
	];
};

if (!isNil "A2EDC_adminTeleportUIDs") then {
	if ((typeName A2EDC_adminTeleportUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminTeleportUIDs;
		_authSource = "A2EDC_adminTeleportUIDs";
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
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=not_admin adminCount=%6 source=%7",_playerUID,_charID,_mode,_clientOldPos,_targetPos,count _adminUIDs,_authSource];
};

_allowedModes = ["self_pos","self_to_player","player_to_self"];
if (!(_mode in _allowedModes)) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=unknown_mode",_playerUID,_charID,_mode,_clientOldPos,_targetPos];
};

_teleportObj = _requester;
_resolvedTargetPos = _targetPos;
_refused = false;

if (_mode == "self_pos") then {
	if (((typeName _targetPos) != "ARRAY") || {(count _targetPos) < 2}) then {
		diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=invalid_target_pos",_playerUID,_charID,_mode,_clientOldPos,_targetPos];
		_refused = true;
	};
	if ((count _resolvedTargetPos) < 3) then {_resolvedTargetPos set [2,0];};
};

if (_mode in ["self_to_player","player_to_self"]) then {
	_targetObj = objNull;
	{
		if ((getPlayerUID _x) == _targetUID) exitWith {
			_targetObj = _x;
		};
	} forEach playableUnits;
	if (isNull _targetObj) then {
		{
			if ((getPlayerUID _x) == _targetUID) exitWith {
				_targetObj = _x;
			};
		} forEach (entities "CAManBase");
	};
	if (isNull _targetObj) then {
		diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetUID=%5 targetName=%6 reason=unknown_target",_playerUID,_charID,_mode,_clientOldPos,_targetUID,_targetName];
		_refused = true;
	};
	if ((!_refused) && {_mode == "self_to_player"}) then {
		if (vehicle _targetObj != _targetObj) then {
			diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetUID=%5 targetName=%6 reason=target_in_vehicle",_playerUID,_charID,_mode,_clientOldPos,_targetUID,_targetName];
			_refused = true;
		};
		if (!_refused) then {
			_teleportObj = _requester;
			_resolvedTargetPos = getPosATL _targetObj;
		};
	};
	if ((!_refused) && {_mode == "player_to_self"}) then {
		if (vehicle _targetObj != _targetObj) then {
			diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetUID=%5 targetName=%6 reason=target_in_vehicle",_playerUID,_charID,_mode,_clientOldPos,_targetUID,_targetName];
			_refused = true;
		};
		if (!_refused) then {
			_teleportObj = _targetObj;
			_resolvedTargetPos = getPosATL _requester;
		};
	};
};

if (_refused) exitWith {};

if (isNull _teleportObj) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=teleport_object_null",_playerUID,_charID,_mode,_clientOldPos,_resolvedTargetPos];
};

if ((count _resolvedTargetPos) < 3) then {_resolvedTargetPos set [2,0];};

_teleportOwner = owner _teleportObj;
_teleportCharID = _teleportObj getVariable ["characterID","0"];
_payloadOut = [_mode,_playerUID,_name,_resolvedTargetPos,getPosATL _teleportObj,_targetUID,_targetName];

diag_log format ["A2EDC:ADMIN:TELEPORT_AUTHORIZED uid=%1 charID=%2 mode=%3 teleportUID=%4 teleportCharID=%5 oldPos=%6 targetPos=%7 targetUID=%8 owner=%9 locality=%10 source=%11",_playerUID,_charID,_mode,getPlayerUID _teleportObj,_teleportCharID,getPosATL _teleportObj,_resolvedTargetPos,_targetUID,_teleportOwner,local _teleportObj,_authSource];

A2EDC_adminTeleportApply = _payloadOut;
_teleportOwner publicVariableClient "A2EDC_adminTeleportApply";
