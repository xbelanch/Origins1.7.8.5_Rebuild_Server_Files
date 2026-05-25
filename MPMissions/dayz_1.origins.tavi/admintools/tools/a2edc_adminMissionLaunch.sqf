private ["_subsystem","_mission","_uid","_name"];

_subsystem = _this select 0;
_mission = _this select 1;
_uid = getPlayerUID player;
_name = if (isNil "dayz_playerName") then {name player} else {dayz_playerName};

if (!(_uid in AdminList)) exitWith {
	cutText ["A2EDC mission launcher is admin-only.", "PLAIN DOWN"];
};

A2EDC_adminMissionLaunch = [player,_uid,_name,_subsystem,_mission];
publicVariableServer "A2EDC_adminMissionLaunch";

cutText [format ["A2EDC mission launch requested: %1 %2",_subsystem,_mission], "PLAIN DOWN"];
