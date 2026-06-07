private["_playerPos","_playerID","_player","_item","_stopGo","_hastentitem","_hasToolbox","_location","_dir","_list","_listB","_lopata","_cemix","_builOk","_cityObjects","_houseObjects","_a2edcUtilityNonBlockers","_a2edcCoastalNonBlockers","_a2edcIsUtilityNonBlocker","_a2edcIsCoastalNonBlocker","_a2edcGetModelPath","_type","_modelPath","_isBroadHouse","_isExplicitUtility","_isUtilityPattern","_isCoastalPattern","_isLandClass","_isTrueBlocker","_reason"];
call gear_ui_init;
_playerPos = getPosATL player;
_playerID =	getPlayerUID player;
_item = _this;
_stopGo = false;
_hastentitem = "ItemCeMix" in magazines player;
_hasToolbox = "ItemToolbox" in items player;
_location = player modeltoworld [0,2.5,0];
_location set [2,0];
_dir = round(direction player);
_list = position player nearObjects ["CementMixer",20];
_listB = nearestObjects [player, ["wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], 20];
diag_log format ["A2EDC:HOUSE_BUILD_ACTION item=%1 action=CeMix uid=%2 player=%3 playerPos=%4 cursorTarget=%5 selectedBlueprint= selectedBuilding=CementMixer",_item,_playerID,player,_playerPos,cursorTarget];
diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=cement_mixer_placement scanSource=cement_mixer scanRadius=20 playerPos=%1 buildPos=%2",_playerPos,_location];
{
	diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_x,typeOf _x,player distance _x,_location distance _x,isNull _x,count ((getMagazineCargo _x) select 0),false,"existing_mixer_blocks_new_mixer"];
} forEach _list;
diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=house_placement_blockers scanSource=nearby_house scanRadius=20 playerPos=%1 buildPos=%2",_playerPos,_location];
{
	diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_x,typeOf _x,player distance _x,_location distance _x,isNull _x,count ((getMagazineCargo _x) select 0),false,"nearby_house_blocks_mixer"];
} forEach _listB;
_builOk = ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor"];
_a2edcUtilityNonBlockers = ["land_radio_box","radio_box","sloup","telek","timbers","deerstand","rail_zavora","rail_semafor"];
_a2edcCoastalNonBlockers = ["land_nav_boathouse_piert","nav_boathouse_pier","nav_boathouse_piert","boathouse_pier"];
_a2edcIsUtilityNonBlocker = {
	private["_class","_lcClass","_matched"];
	_class = _this;
	_lcClass = toLower _class;
	_matched = (_class in _builOk);
	if (!_matched) then {
		{
			if ([_x,_lcClass,false] call fnc_inString) exitWith {_matched = true;};
		} forEach _a2edcUtilityNonBlockers;
	};
	_matched
};
_a2edcIsCoastalNonBlocker = {
	private["_class","_model","_lcClass","_lcModel","_combined","_matched"];
	_class = _this select 0;
	_model = _this select 1;
	_lcClass = toLower _class;
	_lcModel = toLower _model;
	_combined = _lcClass + " " + _lcModel;
	_matched = false;
	{
		if ([_x,_combined,false] call fnc_inString) exitWith {_matched = true;};
	} forEach _a2edcCoastalNonBlockers;
	if (!_matched) then {
		if ((["nav_boathouse",_combined,false] call fnc_inString) && {(["pier",_combined,false] call fnc_inString)}) then {_matched = true;};
	};
	_matched
};
_a2edcGetModelPath = {
	private["_obj","_path"];
	_obj = _this;
	_path = "<unknown>";
	if (!isNull _obj) then {
		_path = getText (configFile >> "CfgVehicles" >> (typeOf _obj) >> "model");
		if (_path == "") then {_path = "<unknown>";};
	};
	_path
};
_cityObjects = nearestObjects [_playerPos, ["House"], 150];
diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=cement_mixer_city_check scanSource=nearest_house scanRadius=150 playerPos=%1 buildPos=%2",_playerPos,_location];
diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_BEGIN scanSource=nearestObjects class=House scanRadius=150 playerPos=%1 buildPos=%2 objectCount=%3 explicitUtilityNonBlockers=%4 coastalNonBlockers=%5",_playerPos,_location,count _cityObjects,_builOk + _a2edcUtilityNonBlockers,_a2edcCoastalNonBlockers];
{
	_type = typeOf _x;
	_modelPath = _x call _a2edcGetModelPath;
	_isBroadHouse = true;
	_isExplicitUtility = (_type in _builOk);
	_isUtilityPattern = _type call _a2edcIsUtilityNonBlocker;
	_isCoastalPattern = [_type,_modelPath] call _a2edcIsCoastalNonBlocker;
	_isLandClass = ["Land_",_type,false] call fnc_inString;
	_isTrueBlocker = (_isLandClass && !_isExplicitUtility && !_isUtilityPattern && !_isCoastalPattern);
	_reason = if (_isTrueBlocker) then {"city_house_within_150m"} else {if (_isCoastalPattern) then {"coastal_non_blocker"} else {if (!_isLandClass) then {"non_land_house_class"} else {"utility_or_non_building_static"}}};
	diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_OBJECT object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 broadClassHouse=%7 landClass=%8 explicitUtility=%9 utilityPattern=%10 coastalPattern=%11 trueBlocker=%12 reason=%13",_x,_type,_modelPath,_type,player distance _x,_location distance _x,_isBroadHouse,_isLandClass,_isExplicitUtility,_isUtilityPattern,_isCoastalPattern,_isTrueBlocker,_reason];
	if (_isTrueBlocker) exitWith {
		titletext ["To build a house, you need to be at least 150 meters away from city.", "PLAIN DOWN"];
		_stopGo = true;
		diag_log ("CityHere");
		diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_ACCEPTED_BLOCKER object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 reason=%7 trueBlocker=true",_x,_type,_modelPath,_type,player distance _x,_location distance _x,_reason];
		diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_x,_type,player distance _x,_location distance _x,isNull _x,count ((getMagazineCargo _x) select 0),false,_reason];
	};
	if (!_isTrueBlocker) then {
		diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_IGNORED_OBJECT object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 reason=%7 trueBlocker=false",_x,_type,_modelPath,_type,player distance _x,_location distance _x,_reason];
	};
} forEach _cityObjects;
diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_RESULT allowed=%1 gate=city_check reason=%2 scanRadius=150 objectCount=%3 playerPos=%4 buildPos=%5",!_stopGo,if (_stopGo) then {"city_house_within_150m"} else {"no_true_city_house_blocker"},count _cityObjects,_playerPos,_location];
		
if (_stopGo) 			exitWith { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,0,"city_or_blocker_check_failed",[],false]; diag_log format ["A2EDC:HOUSE_BUILD_FAIL_REASON gate=%1 reason=%2 details=%3 message=%4","city_check","city house within 150m",[], "Build failed: too close to city/house"]; titletext ["To build cement mixer, you need to be at least 150 meters away from city.", "PLAIN DOWN"]; _stopGo = true; };
if (!_hastentitem) 		exitWith { diag_log format ["A2EDC:HOUSE_BUILD_MISSING_ITEM stage=%1 classname=%2 required=%3 found=%4 missing=%5",0,"ItemCeMix",1,0,1]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,0,"missing_ItemCeMix",["ItemCeMix",1,0,1],false]; titletext ["You do not have cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (!_hasToolbox) 		exitWith { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,0,"missing_ItemToolbox",["ItemToolbox"],false]; titletext ["You need a tool box to build cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (count _list != 0) 	exitWith { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,0,"existing_mixer_within_20m",[],false]; titletext ["You cannot build cement mixer within 20 meters of another cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (count _listB != 0) 	exitWith { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,0,"house_within_20m",[],false]; titletext ["You cannot build cement mixer within 20 meters of house.", "PLAIN DOWN"]; _stopGo = true; };

if(!_stopGo) then {
		diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",true,0,"cement_mixer_placed",[],true];
		diag_log format ["_playerPos=%1,_item=%2,_playerID=%3,",_playerPos,_item,_playerID];
	player removeMagazine "ItemCeMix";
	player playActionNow "Medic";
	[player,"repair",0,false] call dayz_zombieSpeak;
	sleep 5;
	_cemix = createVehicle ["CementMixer", _location, [], 0, "CAN_COLLIDE"];
	_cemix setdir _dir;
	_cemix setpos _location;
	player reveal _cemix;
} else {
	titletext ["Something wrong", "PLAIN DOWN"];
};
