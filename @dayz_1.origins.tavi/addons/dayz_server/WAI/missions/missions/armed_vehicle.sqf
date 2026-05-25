//Armed Vehicle

private ["_playerPresent","_cleanmission","_currenttime","_starttime","_missiontimeout","_vehname","_veh","_position","_vehclass","_vehdir","_objPosition","_box","_cleanunits","_armedVehicleSkin","_infantryTarget","_a2edc_missionDifficulty","_difficultyProfile","_markerColor","_aiSkill","_aiSkillProfile","_lootProfile","_terrainResult","_terrainOk","_terrainReason","_terrainAttempts"];

_vehclass = armed_vehicle call BIS_fnc_selectRandom;
_armedVehicleSkin = "Ins_Soldier_Sapper";
_infantryTarget = 10;
_a2edc_missionDifficulty = "medium";
_difficultyProfile = ["armed_vehicle",_a2edc_missionDifficulty] call a2edc_wai_getDifficultyProfile;
_a2edc_missionDifficulty = _difficultyProfile select 0;
_markerColor = _difficultyProfile select 1;
_aiSkill = _difficultyProfile select 2;
_aiSkillProfile = _difficultyProfile select 3;
_lootProfile = _difficultyProfile select 4;
diag_log format ["A2EDC:WAI:MISSION_BALANCE mission=armed_vehicle infantryTarget=%1",_infantryTarget];

_vehname	= getText (configFile >> "CfgVehicles" >> _vehclass >> "displayName");
_position = [getMarkerPos "center",0,5500,10,0,2000,0] call BIS_fnc_findSafePos;
_terrainAttempts = 0;
_terrainResult = [_position,"armed_vehicle"] call a2edc_wai_validateMissionPosition;
_terrainOk = _terrainResult select 0;
_terrainReason = _terrainResult select 1;
while {(!_terrainOk) && (_terrainAttempts < 12)} do {
	_terrainAttempts = _terrainAttempts + 1;
	_position = [getMarkerPos "center",0,5500,10,0,2000,0] call BIS_fnc_findSafePos;
	_terrainResult = [_position,"armed_vehicle"] call a2edc_wai_validateMissionPosition;
	_terrainOk = _terrainResult select 0;
	_terrainReason = _terrainResult select 1;
};
diag_log format ["A2EDC:WAI:TERRAIN mission=armed_vehicle selected=%1 attempts=%2 result=%3 reason=%4",_position,_terrainAttempts,_terrainOk,_terrainReason];
diag_log format["WAI: Mission Armed Vehicle Started At %1",_position];

//Chain Bullet Box
_box = createVehicle ["USBasicWeaponsBox",[(_position select 0),(_position select 1) + 5,0], [], 0, "CAN_COLLIDE"];
[_box,_lootProfile,"armed_vehicle"] call a2edc_wai_applyRewardProfile;

//Armed Land Vehicle
_veh = createVehicle [_vehclass,_position, [], 0, "CAN_COLLIDE"];
_vehdir = round(random 360);
_veh setDir _vehdir;
_veh setVariable ["ObjectID","0",true];
diag_log format["WAI: Mission Armed Vehicle spawned a %1",_vehname];

_objPosition = getPosATL _veh;
[_veh,[_vehdir,_objPosition],_vehclass,false,"0"] call a2edc_wai_publishVehicle;
[_veh,"armed_vehicle","locked","mission_active"] call a2edc_wai_setMissionVehicleLock;

//Troops
[[_position select 0, _position select 1, 0],                  //position
5,						  //Number Of units
_aiSkill,				  //Skill level/profile.
"Random",			      //Primary gun set number. "Random" for random weapon set.
4,						  //Number of magazines
"",						  //Backpack "" for random or classname here.
_armedVehicleSkin,			  //Skin "" for random or classname here.
"Random",				  //Gearset number. "Random" for random gear set.
true					  // Mission true or false
] call spawn_group;

[[_position select 0, _position select 1, 0],                  //position
5,						  //Number Of units
_aiSkill,				  //Skill level/profile.
"Random",			      //Primary gun set number. "Random" for random weapon set.
4,						  //Number of magazines
"",						  //Backpack "" for random or classname here.
_armedVehicleSkin,			  //Skin "" for random or classname here.
"Random",				  //Gearset number. "Random" for random gear set.
true					  // Mission true or false
] call spawn_group;


[_position,_vehname,_markerColor] execVM "\z\addons\dayz_server\WAI\missions\compile\markers.sqf";
[nil,nil,rTitleText,"Bandits have disabled an armed vehicle with lots of chain gun ammo in the gear! Check your map for the location!", "PLAIN",10] call RE;

_missiontimeout = true;
_cleanmission = false;
_playerPresent = false;
_starttime = floor(time);
while {_missiontimeout} do {
	sleep 5;
	_currenttime = floor(time);
	{if((isPlayer _x) AND (_x distance _position <= 150)) then {_playerPresent = true};}forEach playableUnits;
	if (_currenttime - _starttime >= wai_mission_timeout) then {_cleanmission = true;};
	if ((_playerPresent) OR (_cleanmission)) then {_missiontimeout = false;};
};
if (_playerPresent) then {
	waitUntil
	{
		sleep 5;
		_playerPresent = false;
		{if((isPlayer _x) AND (_x distance _position <= 30)) then {_playerPresent = true};}forEach playableUnits;
		(_playerPresent)
	};
	[_veh,"armed_vehicle","unlocked","mission_cleared"] call a2edc_wai_setMissionVehicleLock;
	diag_log format["WAI: Mission Armed vehicle Ended At %1",_position];
	[nil,nil,rTitleText,"Survivors have secured the armed vehicle!", "PLAIN",10] call RE;
} else {
	clean_running_mission = True;
	deleteVehicle _veh;
	deleteVehicle _box;
	{_cleanunits = _x getVariable "missionclean";
	if (!isNil "_cleanunits") then {
		switch (_cleanunits) do {
			case "ground" :  {ai_ground_units = (ai_ground_units -1);};
			case "air" :     {ai_air_units = (ai_air_units -1);};
			case "vehicle" : {ai_vehicle_units = (ai_vehicle_units -1);};
			case "static" :  {ai_emplacement_units = (ai_emplacement_units -1);};
		};
		deleteVehicle _x;
		sleep 0.05;
	};	
	} forEach allUnits;
	
	diag_log format["WAI: Mission Armed vehicle Timed Out At %1",_position];
	[nil,nil,rTitleText,"Survivors did not secure the armed vehicle in time!", "PLAIN",10] call RE;
};

missionrunning = false;
