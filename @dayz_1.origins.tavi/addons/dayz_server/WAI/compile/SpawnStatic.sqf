private ["_mission","_aipack","_class","_position2","_direction","_static","_position","_unitnumber","_skill","_gun","_mags","_backpack","_skin","_gear","_aiweapon","_aigear","_aiskin","_skillarray","_unitGroup","_weapon","_magazine","_weaponandmag","_gearmagazines","_geartools","_unit","_aiCfg","_aiClassExists","_aiScope","_aiSimulation","_aiBase","_aiPool","_aiReason","_aiFallbackSkin"];
_position = _this select 0;
_class = _this select 1;
_skill = _this select 2;
_skin = _this select 3;
if (ai_static_useweapon) then {
	_gun = _this select 4;
	_mags = _this select 5;
	_backpack = _this select 6;
	_gear = _this select 7;
};
if ((count _this == 9) OR (count _this == 5)) then {
	if (count _this == 9) then {_mission = _this select 8};
	if (count _this == 5) then {_mission = _this select 4};
} else {
	_mission = false;
};
_position2 = [];
_aiweapon = [];
_aigear = [];
_aiskin = "";
_aipack = "";
_skillarray = ["aimingAccuracy","aimingShake","aimingSpeed","endurance","spotDistance","spotTime","courage","reloadSpeed","commanding","general"];
_unitGroup = createGroup east;
_unitnumber = count _position;
_aiFallbackSkin = "Bandit2_3DZ";

if (!isServer) exitWith {};


{_position2 = _x;

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
	diag_log text format ["[A2EDC:WAI:AI_CLASS:SKIP_INVALID] mission=%1 pool=%2 class=%3 reason=%4 scope=%5 simulation=%6 base=%7 fallback=%8 pos=%9 static=%10", _mission, _aiPool, _aiskin, _aiReason, _aiScope, _aiSimulation, _aiBase, _aiFallbackSkin, _position2, _class];
	_aiskin = _aiFallbackSkin;
};
_unit = _unitGroup createUnit [_aiskin, [0,0,0], [], 10, "PRIVATE"];
_static = createVehicle [_class, [(_position2 select 0),(_position2 select 1),(_position2 select 2)], [], 0, "CAN_COLLIDE"];
_static setDir round(random 360);
_static setPos [(_position2 select 0),(_position2 select 1),(_position2 select 2)];
[_unit] joinSilent _unitGroup;
_unit enableAI "TARGET";
_unit enableAI "AUTOTARGET";
_unit enableAI "MOVE";
_unit enableAI "ANIM";
_unit enableAI "FSM";
_unit setCombatMode ai_combatmode;
_unit setBehaviour ai_behaviour;
removeAllWeapons _unit;
removeAllItems _unit;
if (ai_static_useweapon) then {
	switch (_gun) do {
		case 0 : {_aiweapon = ai_wep0;};
		case 1 : {_aiweapon = ai_wep1;};
		case 2 : {_aiweapon = ai_wep2;};
		case 3 : {_aiweapon = ai_wep3;};
		case 4 : {_aiweapon = ai_wep4;};
		case "Random" : {_aiweapon = ai_wep_random call BIS_fnc_selectRandom};
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
		case "Random" : {_aigear = ai_gear_random call BIS_fnc_selectRandom};
	};
	if (_backpack == "") then {
	_aipack = ai_packs call BIS_fnc_selectRandom;
	} else {
	_aipack = _backpack
	};
	_gearmagazines = _aigear select 0;
	_geartools = _aigear select 1;
	if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
		["WAI SpawnStatic primary addWeapon", _weapon] call A2EDC_fnc_traceWeaponClass;
	};
	if ((typeName _weapon == "STRING") && (_weapon != "")) then {
		_unit addweapon _weapon;
	};
	for "_i" from 1 to _mags do {_unit addMagazine _magazine};
	_unit addBackpack _aipack;
	{_unit addMagazine _x} forEach _gearmagazines;
	{
		if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
			["WAI SpawnStatic gear tool addWeapon", _x] call A2EDC_fnc_traceWeaponClass;
		};
		if ((typeName _x == "STRING") && (_x != "")) then {
			_unit addweapon _x;
		};
	} forEach _geartools;
};
if (ai_static_skills) then {
	{_unit setSkill [(_x select 0),(_x select 1)]} forEach ai_static_array;
} else {
	{_unit setSkill [_x,_skill]} forEach _skillarray;
};
ai_emplacement_units = (ai_emplacement_units + 1);
_unit addEventHandler ["Killed",{[_this select 0, _this select 1, "static"] call on_kill}];
_static addEventHandler ["GetOut",{(_this select 0) setDamage 1}];
PVDZE_serverObjectMonitor set [count PVDZE_serverObjectMonitor,_static];
_unit moveingunner _static;
if (_mission) then {
	_unit setVariable ["missionclean", "static"];
	[_static, True] spawn veh_monitor;
} else {
	[_static] spawn veh_monitor;
};
} forEach _position;
_unitGroup selectLeader ((units _unitGroup) select 0);
diag_log format ["WAI: Sapwned in %1 %2",_unitnumber,_class];
