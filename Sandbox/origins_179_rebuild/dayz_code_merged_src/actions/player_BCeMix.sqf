private["_playerPos","_playerID","_player","_item","_stopGo","_hastentitem","_hasToolbox","_location","_dir","_list","_listB","_lopata","_cemix","_builOk"];
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
_listB = nearestObjects [player, ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], 20];
_builOk = ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor"];
{
	if (!(typeOf _x in _builOk)) then {
		if ((["Land_",(typeOf _x),false] call fnc_inString)) exitWith { titletext ["To build a house, you need to be at least 150 meters away from city.", "PLAIN DOWN"]; _stopGo = true; diag_log ("CityHere"); };
	};
} forEach nearestObjects [_playerPos, ["House"], 150];

if (_stopGo) 			exitWith { titletext ["To build cement mixer, you need to be at least 150 meters away from city.", "PLAIN DOWN"]; _stopGo = true; };
if (!_hastentitem) 		exitWith { titletext ["You do not have cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (!_hasToolbox) 		exitWith { titletext ["You need a tool box to build cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (count _list != 0) 	exitWith { titletext ["You cannot build cement mixer within 20 meters of another cement mixer.", "PLAIN DOWN"]; _stopGo = true; };
if (count _listB != 0) 	exitWith { titletext ["You cannot build cement mixer within 20 meters of house.", "PLAIN DOWN"]; _stopGo = true; };

if(!_stopGo) then {
	diag_log format ["_playerPos=%1,_item=%2,_playerID=%3,",_player,_item,_playerID];
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