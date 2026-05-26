private["_obj","_typeT","_ownerID","_objectID","_objectUID","_alreadyPacking","_dir","_pos","_mstrt","_bag","_holder","_weapons","_magazines","_backpacks","_objWpnTypes","_ojWnQy","_countr"];
_obj = _this;
_typeT = typeOf _this;
_ownerID 	= _obj getVariable["CharacterID","0"];
_objectID 	= _obj getVariable["ObjectID","0"];
_objectUID	= _obj getVariable["ObjectUID","0"];
player playActionNow "Medic";
//diag_log format ["Pack Tent1 _typeT=%1, _ownerID=%2, _objectID=%3, _objectUID=%4,dayz_characterID=%5",_typeT,_ownerID,_objectID,_objectUID,dayz_characterID];
player removeAction s_player_packtent;
s_player_packtent = -1;

if(_ownerID == dayz_characterID) then {
	_alreadyPacking = _obj getVariable["packing",0];

	if (_alreadyPacking == 1) exitWith {cutText [format[(localize "str_player_beingpacked")] , "PLAIN DOWN"]};

	_obj setVariable["packing",1];

	_dir = direction _obj;
	_pos = getposATL _obj;
	if (_typeT == "TentStorageR") then {
		[player,"reresttent",0,false] call dayz_zombieSpeak;
	};
	if (_typeT == "TentStorage") then {
		[player,"unbatent",0,false] call dayz_zombieSpeak;
	};
	//diag_log format ["Pack Tent2 _typeT=%1, _ownerID=%2, _objectID=%3, _objectUID=%4, _obj=%5",_typeT,_ownerID,_objectID,_objectUID,_obj];
	sleep 3;

	//place tent (local)
	if (_typeT == "TentStorageR") then {
		_mstrt = "str_success_tent_pack1";
		_bag = createVehicle ["WeaponHolder_ItemRestTent",_pos,[], 0, "CAN_COLLIDE"];
		_bag setdir _dir;
		player reveal _bag;
	};	
	if (_typeT == "TentStorage") then {
		_mstrt = "str_success_tent_pack2";
		_bag = createVehicle ["WeaponHolder_ItemTent",_pos,[], 0, "CAN_COLLIDE"];
		_bag setdir _dir;
		player reveal _bag;
	};
		
	_holder = "WeaponHolder" createVehicle _pos; 
	
	_weapons = 	getWeaponCargo _obj;
	_magazines = 	getMagazineCargo _obj;
	_backpacks = 	getBackpackCargo _obj;
	
	oriUdalkaObj = [_objectID,_objectUID,_typeT];
	publicVariableServer "oriUdalkaObj";
	deleteVehicle _obj;
	
	//Add weapons
	_objWpnTypes = 	_weapons select 0;
	_ojWnQy = 	_weapons select 1;
	_countr = 0;
	{
		_holder addweaponcargoGlobal [_x,(_ojWnQy select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;
	
	//Add Magazines
	_objWpnTypes = _magazines select 0;
	_ojWnQy = _magazines select 1;
	_countr = 0;
	{
		_holder addmagazinecargoGlobal [_x,(_ojWnQy select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;

	//Add Backpacks
	_objWpnTypes = _backpacks select 0;
	_ojWnQy = _backpacks select 1;
	_countr = 0;
	{
		_holder addbackpackcargoGlobal [_x,(_ojWnQy select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;
	
	cutText [(localize _mstrt), "PLAIN DOWN"];
} else {
	cutText [localize "str_fail_tent_pack", "PLAIN DOWN"];
};