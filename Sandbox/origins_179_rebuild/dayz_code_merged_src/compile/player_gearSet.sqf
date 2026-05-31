private["_inventory","_wpns","_mags","_idc","_isOK","_val","_item","_x","_a2edcRawOnBack","_a2edcOnBack","_a2edcReason","_a2edcDuplicate","_a2edcCharID","_a2edcUID","_a2edcPrimary"];
_inventory = _this;
if (count _inventory > 0) then {
	_wpns = _inventory select 0;
	_mags = _inventory select 1;
	_a2edcRawOnBack = "";
	_a2edcOnBack = "";
	_a2edcReason = "old_inventory";
	_a2edcDuplicate = false;
	if ((count _inventory) > 3) then {
		_a2edcRawOnBack = _inventory select 3;
		_a2edcReason = "ok";
		if ((typeName _a2edcRawOnBack) != "STRING") then {
			_a2edcRawOnBack = "";
			_a2edcReason = "not_string";
		};
		if (_a2edcRawOnBack == "") then {
			_a2edcReason = "empty";
		} else {
			if (!(isClass(configFile >> "CfgWeapons" >> _a2edcRawOnBack))) then {
				_a2edcReason = "missing_cfgWeapons_class";
			} else {
				if (_a2edcRawOnBack in _wpns) then {
					_a2edcReason = "duplicate_active_weapon";
					_a2edcDuplicate = true;
				} else {
					_a2edcOnBack = _a2edcRawOnBack;
				};
			};
		};
	};

	//Add inventory
	{
		private["_item","_val"];
		//is it an array?
		_idc = 109;
		if (typeName _x == "ARRAY") then {
			_item = _x select 0;
			_val = 	_x select 1;
		} else {
			_item = _x;
			_val = -1;
		};
		//Is item legal?
		_isOK = 	isClass(configFile >> "CfgMagazines" >> _item);
		if (_isOK) then {
			if (_val != -1) then {
				player addMagazine [_item,_val];
			} else {
				player addMagazine _item;
			};
		};
		_idc = _idc + 1;
	} forEach _mags;
	
	//Add weapons
	{
		_isOK = 	isClass(configFile >> "CfgWeapons" >> _x);
		//Is item legal?
		if (_isOK) then {
			player addWeapon _x;
		};
	} forEach _wpns;

	_a2edcPrimary = primaryWeapon player;
	if ((_a2edcOnBack != "") and (_a2edcOnBack == _a2edcPrimary)) then {
		_a2edcReason = "duplicate_primary_after_load";
		_a2edcDuplicate = true;
		_a2edcOnBack = "";
	};
	A2EDC_onBack = _a2edcOnBack;
	dayz_onBack = _a2edcOnBack;
	player setVariable ["A2EDC_onBack",_a2edcOnBack,true];
	player setVariable ["dayz_onBack",_a2edcOnBack,true];
	_a2edcCharID = if (isNil "dayz_characterID") then {"<nil>"} else {dayz_characterID};
	_a2edcUID = if (isNil "dayz_playerUID") then {getPlayerUID player} else {dayz_playerUID};
	diag_log format["A2EDC:ONBACK_LOAD side=client path=player_gearSet uid=%1 charID=%2 inventoryCount=%3 rawOnBack=%4 normalizedOnBack=%5 reason=%6 duplicate=%7 primary=%8 weapons=%9",_a2edcUID,_a2edcCharID,count _inventory,_a2edcRawOnBack,_a2edcOnBack,_a2edcReason,_a2edcDuplicate,_a2edcPrimary,weapons player];
	if (!isNil "A2EDC_fnc_onBackGearOpenRefresh") then {
		[objNull,"login_load"] spawn A2EDC_fnc_onBackGearOpenRefresh;
	};
};
