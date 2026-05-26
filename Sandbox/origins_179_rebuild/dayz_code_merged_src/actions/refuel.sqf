private["_vehicle","_jsel","_jsele","_canSize","_configVeh","_capacity","_nameType","_curFuel","_newFuel","_fueled","_magazines","_id"];
_vehicle = 		cursorTarget;

if ("ItemJerrycan" in magazines player) then {
	_jsel = "ItemJerrycan"; _jsele = "ItemJerrycanEmpty";
};
if ("ItemJerrycanB" in magazines player) then { 
 	_jsel = "ItemJerrycanB"; _jsele = "ItemJerrycanBEmpty";
};

_canSize = 		getNumber(configFile >> "cfgMagazines" >> _jsel >> "fuelQuantity");
_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = 	getNumber(_configVeh >> "fuelCapacity");
_nameType = 	getText(_configVeh >> "displayName");
_curFuel = 		((fuel _vehicle) * _capacity);
_newFuel = 		(_curFuel + _canSize);
player removeMagazine _jsel;
player addMagazine _jsele;

	//diag_log format ["_canSize=%1, _configVeh=%2, _capacity=%3, _nameType=%4, _curFuel=%5,_newFuel=%6",_canSize,_configVeh,_capacity,_nameType,_curFuel,_newFuel];

if (_newFuel > _capacity) then {_newFuel = _capacity};
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
cutText [format[localize "str_player_05",_nameType,_canSize], "PLAIN DOWN"];
sleep 1;

call fnc_usec_medic_removeActions;
r_action = false;