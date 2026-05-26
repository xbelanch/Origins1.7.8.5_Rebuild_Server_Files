private ["_objects"];
_objects = nearestObjects [getPosATL player,["Car","Helicopter","Motorcycle","Ship","TentStorage","TentStorageR","wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"],15];
{
	dayUpdateVehlcle = [_x,"all"];
	publicVariableServer "dayUpdateVehlcle";
} foreach _objects;
//diag_log format ["_objects_p_GearS=%1",_objects];

private["_dialog","_magazineArray","_control","_item","_val","_max"];

disableSerialization;
_dialog = 			_this select 0;
_magazineArray = 	[];

//Primary Mags
for "_i" from 109 to 120 do 
{
	_control = 	_dialog displayCtrl _i;
	_item = 	gearSlotData _control;
	_val =		gearSlotAmmoCount _control;
	_max = 		getNumber (configFile >> "CfgMagazines" >> _item >> "count");
	if (_item != "") then {
		if (_val != _max) then {
			_magazineArray set [count _magazineArray,[_item,_val]];
		} else {
			_magazineArray set [count _magazineArray,_item];
		};
	};
};

//Secondary Mags
for "_i" from 122 to 129 do 
{
	_control = 	_dialog displayCtrl _i;
	_item = 	gearSlotData _control;
	_val =		gearSlotAmmoCount _control;
	_max = 		getNumber (configFile >> "CfgMagazines" >> _item >> "count");
	if (_item != "") then {
		if (_val != _max) then {
			_magazineArray set [count _magazineArray,[_item,_val]];
		} else {
			_magazineArray set [count _magazineArray,_item];
		};
	};
};
//dayz_unsaved = true;
//dayz_Magazines = _magazineArray;

DOgNo_Se = [player,_magazineArray,false];
publicVariableServer "DOgNo_Se";
//diag_log format ["SAVE_gearSync=%1",DOgNo_Se];
dayz_lastSave = time;
dayz_Magazines = [];
