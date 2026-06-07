private ["_requested","_label","_uid","_name","_charID","_oldHumanity","_sourcePath"];

_requested = _this select 0;
_label = if ((count _this) > 1) then {_this select 1} else {"custom"};
_uid = getPlayerUID player;
_name = if (isNil "dayz_playerName") then {name player} else {dayz_playerName};
_charID = player getVariable ["characterID","0"];
_oldHumanity = player getVariable ["humanity",0];
_sourcePath = format ["AdminTools.Debug.Humanity.%1",_label];

if (isNil "AdminList") then {
	AdminList = [];
};

if (!(_uid in AdminList)) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED side=client uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=not_admin_client",_uid,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath];
	cutText ["A2EDC humanity debug is admin-only.", "PLAIN DOWN"];
};

if ((typeName _requested) != "SCALAR") exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_REFUSED side=client uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=%5 sourcePath=%6 persisted=false reason=non_numeric_client",_uid,_charID,_oldHumanity,_requested,_oldHumanity,_sourcePath];
	cutText ["A2EDC humanity debug refused: invalid value.", "PLAIN DOWN"];
};

diag_log format ["A2EDC:ADMIN:HUMANITY_REQUEST side=client uid=%1 characterID=%2 oldHumanity=%3 requestedHumanity=%4 appliedHumanity=<pending> sourcePath=%5 persisted=false reason=requested",_uid,_charID,_oldHumanity,_requested,_sourcePath];

A2EDC_adminHumanityDebug = [player,_uid,_name,_charID,_requested,_sourcePath,_oldHumanity];
publicVariableServer "A2EDC_adminHumanityDebug";

cutText [format ["A2EDC humanity debug requested: %1",_requested], "PLAIN DOWN"];
