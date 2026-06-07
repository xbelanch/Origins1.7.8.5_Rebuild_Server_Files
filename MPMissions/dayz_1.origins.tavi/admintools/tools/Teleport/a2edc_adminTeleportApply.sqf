private ["_payload","_mode","_requestUID","_requestName","_targetPos","_serverOldPos","_serverTargetUID","_serverTargetName","_uid","_charID","_oldPos","_actualPos","_targetDir","_distance","_magazines","_worldspaceBefore","_dayzMyPositionBefore","_dayzMylastPosBefore","_lastPosBefore"];

_payload = _this;

if ((typeName _payload) != "ARRAY") exitWith {
	diag_log "A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=<invalid> charID=<invalid> reason=apply_payload_not_array";
};

if ((count _payload) < 7) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=<invalid> charID=<invalid> reason=apply_payload_too_short payload=%1",_payload];
};

_mode = _payload select 0;
_requestUID = _payload select 1;
_requestName = _payload select 2;
_targetPos = _payload select 3;
_serverOldPos = _payload select 4;
_serverTargetUID = _payload select 5;
_serverTargetName = _payload select 6;

_uid = getPlayerUID player;
_charID = player getVariable ["characterID","0"];
_oldPos = getPosATL player;

if (vehicle player != player) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=%1 charID=%2 requestUID=%3 mode=%4 oldPos=%5 targetPos=%6 reason=in_vehicle",_uid,_charID,_requestUID,_mode,_oldPos,_targetPos];
};

if (((typeName _targetPos) != "ARRAY") || {(count _targetPos) < 2}) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=%1 charID=%2 requestUID=%3 mode=%4 oldPos=%5 targetPos=%6 reason=invalid_target_pos",_uid,_charID,_requestUID,_mode,_oldPos,_targetPos];
};

if ((count _targetPos) < 3) then {
	_targetPos set [2,0];
};

_targetDir = getDir player;
diag_log format ["A2EDC:ADMIN:TELEPORT_APPLY_CLIENT uid=%1 charID=%2 requestUID=%3 requestName=%4 mode=%5 oldPos=%6 serverOldPos=%7 targetPos=%8 locality=%9 owner=%10",_uid,_charID,_requestUID,_requestName,_mode,_oldPos,_serverOldPos,_targetPos,local player,owner player];
_worldspaceBefore = player getVariable ["worldspace",[]];
_dayzMyPositionBefore = if (isNil "dayz_myPosition") then {"<nil>"} else {dayz_myPosition};
_dayzMylastPosBefore = if (isNil "dayz_mylastPos") then {"<nil>"} else {dayz_mylastPos};
_lastPosBefore = player getVariable ["lastPos",[]];
diag_log format ["A2EDC:ADMIN:TELEPORT_WORLDSPACE_BEFORE uid=%1 charID=%2 worldspaceVar=%3 dayz_myPosition=%4 dayz_mylastPos=%5 lastPos=%6",_uid,_charID,_worldspaceBefore,_dayzMyPositionBefore,_dayzMylastPosBefore,_lastPosBefore];

player setVariable ["A2EDC_adminTeleportTarget",_targetPos,true];
player setVariable ["A2EDC_adminTeleportActive",true,false];
player setVariable ["A2EDC_adminTeleportLastAccepted",_targetPos,false];
player setVariable ["A2EDC_adminTeleportSync",true,true];
player setVariable ["posForceUpdate",true,true];
player setVariable ["lastPos",_targetPos,true];
dayz_myPosition = _targetPos;
dayz_mylastPos = _targetPos;

player setDir _targetDir;
player setPosATL _targetPos;
sleep 0.2;
player setPosATL _targetPos;

_actualPos = getPosATL player;
player setVariable ["worldspace",[round _targetDir,_actualPos],true];
diag_log format ["A2EDC:ADMIN:TELEPORT_WORLDSPACE_AFTER uid=%1 charID=%2 worldspace=%3 dayz_myPosition=%4 dayz_mylastPos=%5 lastPos=%6",_uid,_charID,player getVariable ["worldspace",[]],dayz_myPosition,if (isNil "dayz_mylastPos") then {"<nil>"} else {dayz_mylastPos},player getVariable ["lastPos",[]]];
_magazines = if (isNil "dayz_Magazines") then {magazines player} else {dayz_Magazines};
DOgNo_Se = [player,_magazines,true];
publicVariableServer "DOgNo_Se";

diag_log format ["A2EDC:ADMIN:TELEPORT_SYNC side=client uid=%1 charID=%2 requestUID=%3 mode=%4 oldPos=%5 targetPos=%6 actualPos=%7 locality=%8",_uid,_charID,_requestUID,_mode,_oldPos,_targetPos,_actualPos,local player];

[_uid,_charID,_requestUID,_mode,_targetPos,_actualPos,_magazines] spawn {
	private ["_uid","_charID","_requestUID","_mode","_targetPos","_firstActual","_magazines","_actual","_distance"];
	_uid = _this select 0;
	_charID = _this select 1;
	_requestUID = _this select 2;
	_mode = _this select 3;
	_targetPos = _this select 4;
	_firstActual = _this select 5;
	_magazines = _this select 6;
	sleep 10;
	_actual = getPosATL player;
	_distance = _actual distance _targetPos;
	if (_distance > 15) then {
		diag_log format ["A2EDC:ADMIN:TELEPORT_SNAPBACK_GUARD uid=%1 charID=%2 requestUID=%3 mode=%4 targetPos=%5 firstActual=%6 actualPos=%7 distance=%8 action=reapply",_uid,_charID,_requestUID,_mode,_targetPos,_firstActual,_actual,_distance];
			player setVariable ["posForceUpdate",true,true];
			player setVariable ["lastPos",_targetPos,true];
			dayz_myPosition = _targetPos;
			dayz_mylastPos = _targetPos;
			player setVariable ["A2EDC_adminTeleportActive",true,false];
			player setVariable ["A2EDC_adminTeleportLastAccepted",_targetPos,false];
			player setPosATL _targetPos;
			DOgNo_Se = [player,_magazines,true];
			publicVariableServer "DOgNo_Se";
		} else {
			player setVariable ["A2EDC_adminTeleportActive",false,false];
			diag_log format ["A2EDC:ADMIN:TELEPORT_DONE uid=%1 charID=%2 requestUID=%3 mode=%4 targetPos=%5 actualPos=%6 distance=%7",_uid,_charID,_requestUID,_mode,_targetPos,_actual,_distance];
		};
};

cutText ["A2EDC teleport complete.", "PLAIN DOWN"];
