private ["_kit","_uid","_name","_allowed"];

_kit = _this select 0;
_uid = getPlayerUID player;
_name = if (isNil "dayz_playerName") then {name player} else {dayz_playerName};
_allowed = ["house_l1_hero","house_l1_bandit","cleanup_temp"];

if (!(_uid in AdminList)) exitWith {
	cutText ["A2EDC building kit tool is admin-only.", "PLAIN DOWN"];
};

if (!(_kit in _allowed)) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED side=client uid=%1 name=%2 kit=%3 reason=not_whitelisted",_uid,_name,_kit];
	cutText ["Unknown A2EDC building kit.", "PLAIN DOWN"];
};

diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REQUEST side=client uid=%1 name=%2 kit=%3",_uid,_name,_kit];

A2EDC_adminBuildingKit = [player,_uid,_name,_kit];
publicVariableServer "A2EDC_adminBuildingKit";

cutText [format ["A2EDC building kit requested: %1",_kit], "PLAIN DOWN"];
