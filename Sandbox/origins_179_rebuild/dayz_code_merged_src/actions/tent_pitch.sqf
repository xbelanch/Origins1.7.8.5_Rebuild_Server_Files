private["_playerPos","_item","_hastentitem","_hasWooditem","_hasToolbox","_hasItemRestTent","_location","_building","_isOk","_netRes","_isok","_config","_text","_config2","_text2","_config3","_text3","_objectsPond","_isPond","_pondPos","_dir","_id","_tent","_msfg","_listBB"];
//check if can pitch here
call gear_ui_init;
_playerPos = 	getPosATL player;
_item = _this;
_hastentitem = _this in magazines player;
_hasWooditem = "PartWoodPile" in magazines player;
_hasToolbox = "ItemToolbox" in items player;
_hasItemRestTent = _this in magazines player;
_location = player modeltoworld [0,2.5,0];
_location set [2,0];
_building = nearestObject [(vehicle player), "HouseBase"];
_isOk = [(vehicle player),_building] call fnc_isInsideBuilding;
//_isOk = true; 
_netRes = true;
_listBB = count (nearestObjects [_location, ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], 15]) == 0;
if (!_listBB) exitWith { titletext ["To build a house, you need to be at least 12 meters away from other house.", "PLAIN DOWN"]; };

diag_log format ["_building=%1, _isOk=%2,dayz_characterID=%3",_building,_isOk,dayz_characterID];
//diag_log ("Pitch Tent: " + str(_isok) );

_config = configFile >> "CfgMagazines" >> _item;
_text = getText (_config >> "displayName");

_config2 = configFile >> "CfgMagazines" >> "PartWoodPile";
_text2 = getText (_config2 >> "displayName");

_config3 = configFile >> "CfgMagazines" >> "ItemToolbox";
_text3 = getText (_config3 >> "displayName");

if (_item == "ItemRestTent") then {
	if (!_hasItemRestTent or !_hasToolbox or !_hasWooditem) then { _netRes = false; };
};
	if (!_hastentitem) exitWith {cutText [format[(localize "str_player_31"),_text,"",""] , "PLAIN DOWN"]};

if (!_netRes) exitWith {cutText [format[(localize "str_player_31"),_text,_text2,_text3] , "PLAIN DOWN"]};

//blocked
if (["concrete",dayz_surfaceType] call fnc_inString) then { _isOk = true; diag_log ("surface concrete"); };
//Block Tents in pounds
_objectsPond = 		nearestObjects [_playerPos, [], 10];
	{
		_isPond = ["pond",str(_x),false] call fnc_inString;
		if (_isPond) then {
			_pondPos = (_x worldToModel _playerPos) select 2;
			if (_pondPos < 0) then {
				_isOk = true;
			};
		};
	} forEach _objectsPond;

//diag_log ("Pitch Tent: " + str(_isok) );

if (!_isOk) then {
	//remove tentbag
	if (_item == "ItemRestTent") then {
		player removeMagazine "ItemRestTent";
		player removeMagazine "PartWoodPile";
		_dir = round(direction player);	
	} else {
		player removeMagazine "ItemTent";
		_dir = round(direction player);	
	};
	
	//wait a bit
	player playActionNow "Medic";
	sleep 1;
	if (_item == "ItemRestTent") then {
		[player,"bresttent",0,false] call dayz_zombieSpeak;
	};
	if (_item == "ItemTent") then {
		[player,"batent",0,false] call dayz_zombieSpeak;
	};
	_id = [player,50,true,(getPosATL player)] spawn player_alertZombies;
	
	sleep 5;
	//place tent (local)
	if (_item == "ItemRestTent") then {
		_tent = createVehicle ["TentStorageR", _location, [], 0, "CAN_COLLIDE"];
		_tent setdir _dir;
		_tent setpos _location;
		player reveal _tent;
		_location = getPosATL _tent;
		_msfg = "str_success_tent_pitch1";
	};
	if (_item == "ItemTent") then {
		_tent = createVehicle ["TentStorage", _location, [], 0, "CAN_COLLIDE"];
		_tent setdir _dir;
		_tent setpos _location;
		player reveal _tent;
		_location = getPosATL _tent;
		_msfg = "str_success_tent_pitch2";
	};
	_tent setVariable ["characterID",dayz_characterID,true];

	if (_item == "ItemRestTent") then {
		oriWverOtkr = [dayz_characterID,_tent,[_dir,_location],"TentStorageR"];
	};
	if (_item == "ItemTent") then {
		oriWverOtkr = [dayz_characterID,_tent,[_dir,_location],"TentStorage"];
	};
	
	diag_log format ["oriWverOtkr=%1",oriWverOtkr];
	publicVariableServer "oriWverOtkr";
		
	cutText [(localize _msfg), "PLAIN DOWN"];
} else {
	cutText [localize "str_fail_tent_pitch", "PLAIN DOWN"];
};

