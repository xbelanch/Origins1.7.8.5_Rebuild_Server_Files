private ["_mission","_aipack","_aicskill","_position","_unitnumber","_skill","_gun","_mags","_backpack","_skin","_gear","_aiweapon","_aigear","_aiskin","_skillarray","_unitGroup","_weapon","_magazine","_weaponandmag","_gearmagazines","_geartools","_unit","_aiCfg","_aiClassExists","_aiScope","_aiSimulation","_aiBase","_aiPool","_aiReason","_aiFallbackSkin"];
_position = _this select 0;
_unitnumber = _this select 1;
_skill = _this select 2;
_gun = _this select 3;
_mags = _this select 4;
_backpack = _this select 5;
_skin = _this select 6;
_gear = _this select 7;
if (count _this > 8) then {
	_mission = _this select 8;
} else {
	_mission = False;
};

_aiweapon = [];
_aigear = [];
_aiskin = "";
_aicskill = [];
_aipack = "";
_skillarray = ["aimingAccuracy","aimingShake","aimingSpeed","endurance","spotDistance","spotTime","courage","reloadSpeed","commanding","general"];
_unitGroup = createGroup east;
_aiFallbackSkin = "Bandit2_3DZ";

if (!isServer) exitWith {};

for "_x" from 1 to _unitnumber do {
	switch (_gun) do {
		case 0 : {_aiweapon = ai_wep0;};
		case 1 : {_aiweapon = ai_wep1;};
		case 2 : {_aiweapon = ai_wep2;};
		case 3 : {_aiweapon = ai_wep3;};
		case 4 : {_aiweapon = ai_wep4;};
		case "Random" : {_aiweapon = ai_wep_random call BIS_fnc_selectRandom;};
	};
	_weaponandmag = _aiweapon call BIS_fnc_selectRandom;
	_weapon = _weaponandmag select 0;
	_magazine = _weaponandmag select 1;
		switch (_gear) do {
		case 0 : {_aigear = ai_gear0;};
		case 1 : {_aigear = ai_gear1;};
		case 2 : {_aigear = ai_gear2;};
		case 3 : {_aigear = ai_gear3;};
		case 4 : {_aigear = ai_gear4;};
		case "Random" : {_aigear = ai_gear_random call BIS_fnc_selectRandom;};
	};
	_gearmagazines = _aigear select 0;
	_geartools = _aigear select 1;
	if (_skin == "") then {
		_aiskin = ai_skin call BIS_fnc_selectRandom;
		_aiPool = "ai_skin";
	} else {
		_aiskin = _skin;
		_aiPool = "explicit-skin";
	};
	_aiCfg = configFile >> "CfgVehicles" >> _aiskin;
	_aiClassExists = isClass _aiCfg;
	_aiScope = -1;
	_aiSimulation = "";
	_aiBase = "";
	if (_aiClassExists) then {
		_aiScope = getNumber (_aiCfg >> "scope");
		_aiSimulation = getText (_aiCfg >> "simulation");
		_aiBase = configName (inheritsFrom _aiCfg);
	};
	_aiReason = "";
	if (!_aiClassExists) then {_aiReason = "missing";};
	if ((_aiReason == "") AND (_aiScope < 2)) then {_aiReason = "scope-private";};
	if ((_aiReason == "") AND (_aiSimulation == "")) then {_aiReason = "missing-simulation";};
	if ((_aiReason == "") AND (_aiBase == "Banned")) then {_aiReason = "banned-base";};
	if (_aiReason != "") then {
		diag_log text format ["[A2EDC:WAI:AI_CLASS:SKIP_INVALID] mission=%1 pool=%2 class=%3 reason=%4 scope=%5 simulation=%6 base=%7 fallback=%8 pos=%9", _mission, _aiPool, _aiskin, _aiReason, _aiScope, _aiSimulation, _aiBase, _aiFallbackSkin, _position];
		_aiskin = _aiFallbackSkin;
	};
	_unit = _unitGroup createUnit [_aiskin, [(_position select 0),(_position select 1),(_position select 2)], [], 10, "PRIVATE"];
	[_unit] joinSilent _unitGroup;
	if (_backpack == "") then {
		_aipack = ai_packs call BIS_fnc_selectRandom;
	} else {
		_aipack = _backpack
	};
	_unit enableAI "TARGET";
	_unit enableAI "AUTOTARGET";
	_unit enableAI "MOVE";
	_unit enableAI "ANIM";
	_unit enableAI "FSM";
	_unit setCombatMode ai_combatmode;
	_unit setBehaviour ai_behaviour;
	removeAllWeapons _unit;
	removeAllItems _unit;
	if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
		["WAI SpawnGroup primary addWeapon", _weapon] call A2EDC_fnc_traceWeaponClass;
	};
	if ((typeName _weapon == "STRING") && (_weapon != "")) then {
		_unit addweapon _weapon;
	};
	for "_i" from 1 to _mags do {_unit addMagazine _magazine;};
	_unit addBackpack _aipack;
	{_unit addMagazine _x} forEach _gearmagazines;
	{
		if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
			["WAI SpawnGroup gear tool addWeapon", _x] call A2EDC_fnc_traceWeaponClass;
		};
		if ((typeName _x == "STRING") && (_x != "")) then {
			_unit addweapon _x;
		};
	} forEach _geartools;
	if (typeName _skill == "ARRAY") then {
		{_unit setSkill [(_x select 0),(_x select 1)]} forEach _skill;
	} else {
	if (ai_custom_skills) then {
		switch (_skill) do {
		case 0 : {_aicskill = ai_custom_array1;};
		case 1 : {_aicskill = ai_custom_array2;};
		case 2 : {_aicskill= ai_custom_array3;};
		case "Random" : {_aicskill = ai_skill_random call BIS_fnc_selectRandom;};
	};
		{_unit setSkill [(_x select 0),(_x select 1)]} forEach _aicskill;
	} else {
		{_unit setSkill [_x,_skill]} forEach _skillarray;
	};
	};
	ai_ground_units = (ai_ground_units + 1);
	_unit addEventHandler ["Killed",{[_this select 0, _this select 1, "ground"] call on_kill;}];
	if (_mission) then {
		_unit setVariable ["missionclean", "ground"];
	};
};
_unitGroup selectLeader ((units _unitGroup) select 0);
[_unitGroup, _position, _mission] call group_waypoints;

diag_log format ["WAI: Spawned a group of %1 Bandits at %2",_unitnumber,_position];
