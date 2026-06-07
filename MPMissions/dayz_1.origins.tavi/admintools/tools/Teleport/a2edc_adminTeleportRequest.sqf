private ["_mode","_targetPos","_targetUID","_targetName","_uid","_name","_oldPos","_charID","_allowed"];

_mode = _this select 0;
_targetPos = if ((count _this) > 1) then {_this select 1} else {[]};
_targetUID = if ((count _this) > 2) then {_this select 2} else {""};
_targetName = if ((count _this) > 3) then {_this select 3} else {""};

_uid = getPlayerUID player;
_name = if (isNil "dayz_playerName") then {name player} else {dayz_playerName};
_oldPos = getPosATL player;
_charID = player getVariable ["characterID","0"];
_allowed = ["self_pos","self_to_player","player_to_self"];

if (!(_uid in AdminList)) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=not_admin",_uid,_charID,_mode,_oldPos,_targetPos];
	cutText ["A2EDC teleport is admin-only.", "PLAIN DOWN"];
};

if (!(_mode in _allowed)) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=unknown_mode",_uid,_charID,_mode,_oldPos,_targetPos];
	cutText ["Unknown A2EDC teleport mode.", "PLAIN DOWN"];
};

if (vehicle player != player) exitWith {
	diag_log format ["A2EDC:ADMIN:TELEPORT_REFUSED side=client uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 reason=in_vehicle",_uid,_charID,_mode,_oldPos,_targetPos];
	cutText ["A2EDC teleport refused while in a vehicle.", "PLAIN DOWN"];
};

diag_log format ["A2EDC:ADMIN:TELEPORT_REQUEST side=client uid=%1 charID=%2 mode=%3 oldPos=%4 targetPos=%5 targetUID=%6 targetName=%7 locality=%8",_uid,_charID,_mode,_oldPos,_targetPos,_targetUID,_targetName,local player];

A2EDC_adminTeleportRequest = [player,_uid,_name,_charID,_mode,_targetPos,_targetUID,_targetName,_oldPos];
publicVariableServer "A2EDC_adminTeleportRequest";

cutText ["A2EDC teleport authorization requested.", "PLAIN DOWN"];
