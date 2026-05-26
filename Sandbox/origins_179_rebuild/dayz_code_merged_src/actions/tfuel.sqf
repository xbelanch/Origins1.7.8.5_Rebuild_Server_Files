private ["_vehicle","_togo","_jsel","_jsele","_canSize","_configVeh","_capacity","_nameType","_curFuel","_newFuel","_magazines"];
_vehicle = 		cursorTarget;
_togo = true;
if ("ItemJerrycanBEmpty" in magazines player) then { _jsel = "ItemJerrycanBEmpty"; _jsele = "ItemJerrycanB"; _togo = false;};
if ("ItemJerrycanEmpty" in magazines player) then { _jsel = "ItemJerrycanEmpty"; _jsele = "ItemJerrycan"; _togo = false;};
if (_togo) exitWith { cutText ["You need Empty Jerrycan", "PLAIN DOWN"]; };

_canSize = 		getNumber(configFile >> "cfgMagazines" >> _jsele >> "fuelQuantity");
_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = 	getNumber(_configVeh >> "fuelCapacity");
_nameType = 	getText(_configVeh >> "displayName");
_curFuel = 		((fuel _vehicle) * _capacity);
_newFuel = 		(_curFuel - _canSize);

//diag_log format ["_canSize=%1, _configVeh=%2, _capacity=%3, _nameType=%4, _curFuel=%5,_newFuel=%6",_canSize,_configVeh,_capacity,_nameType,_curFuel,_newFuel];
if (_curFuel < _canSize) then {
	cutText [format["There is not enough fuel in %1",_nameType], "PLAIN DOWN"];
} else {
	player removeMagazine _jsel;
	player addMagazine _jsele;
	_newFuel = (_newFuel / _capacity);
	_magazines	= call player_countmagazines;
	dayz_lastSave = time;
	dayz_Magazines = [];

	player playActionNow "Medic";
	[player,"refuel",0,false] call dayz_zombieSpeak;
		
	_id = [player,20,true,(getPosATL player)] spawn player_alertZombies;

	sleep 6;
	//diag_log format ["_canSize=%1, _configVeh=%2,_capacity=%3, _nameType=%4, _curFuel=%5,_newFuel=%6,_vehicle=%7",_canSize,_configVeh,_capacity,_nameType,_curFuel,_newFuel,_vehicle];
	dayzSetFuel = [_vehicle,_newFuel];
	dayzSetFuel spawn local_sefFuel;
	publicVariable "dayzSetFuel";
	cutText [format[localize "str_player_37",_nameType,_canSize], "PLAIN DOWN"];
	sleep 1;

	call fnc_usec_medic_removeActions;
	r_action = false;
};