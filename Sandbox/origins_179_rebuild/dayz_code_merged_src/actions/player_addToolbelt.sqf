private["_item","_config","_onLadder","_create","_isOk","_config2","_hasPrimary","_action","_reason","_current","_primary","_lower","_hastoolweapon","_text","_magType","_meleeNum","_muzzles","_wtype","_type","_targetSlot","_back","_valid","_magsBefore","_weaponsBefore","_hasSwitch","_hasTrigger","_hasFallback","_onBackSystemAvailable"];
_item = _this;
_type = "cfgWeapons";
_config = configFile >> "cfgWeapons" >> _item;
_current = currentWeapon player;
_primary = primaryWeapon player;
_lower = secondaryWeapon player;
_hasPrimary = (_primary != "") and !(_primary in ["MeleeHatchet","MeleeCrowbar"]);
if (!isNil "A2EDC_fnc_normalizeOnBack") then {
	call A2EDC_fnc_normalizeOnBack;
};
_back = if (isNil "A2EDC_onBack") then {player getVariable ["A2EDC_onBack",""]} else {A2EDC_onBack};
if ((typeName _back) != "STRING") then {
	_back = "";
};
_action = "unknown";
_targetSlot = "activePrimary";
_weaponsBefore = weapons player;
_magsBefore = magazines player;

if (_item in ["ItemHatchet","ItemCrowbar"]) then {
	_action = "toMelee";
};
if (_item in ["MeleeHatchet","MeleeCrowbar"]) then {
	_action = "toToolbelt";
};

diag_log format["A2EDC:HATCHET_CONVERT_BEGIN item=%1 action=%2 primary=%3 A2EDC_onBack=%4 current=%5 weaponsBefore=%6 magazinesBefore=%7 anim=%8",_item,_action,_primary,_back,_current,_weaponsBefore,_magsBefore,animationState player];

_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {
	diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=on_ladder item=%1 primary=%2 A2EDC_onBack=%3 weapons=%4 magazines=%5",_item,primaryWeapon player,_back,weapons player,magazines player];
	cutText [(localize "str_player_21"), "PLAIN DOWN"];
};

_hastoolweapon = _item in weapons player;
_text = getText (_config >> "displayName");
if (!_hastoolweapon) exitWith {
	diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=missing_source item=%1 primary=%2 A2EDC_onBack=%3 weapons=%4 magazines=%5",_item,primaryWeapon player,_back,weapons player,magazines player];
	cutText [format[(localize "str_player_30"),_text], "PLAIN DOWN"];
};

call gear_ui_init;

_create = getArray (_config >> "ItemActions" >> "Toolbelt" >> "output") select 0;
_config2 = configFile >> "cfgWeapons" >> _create;
if (!isClass _config2) exitWith {
	diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=missing_output_class item=%1 create=%2 selectedTarget=%3 weapons=%4 magazines=%5",_item,_create,_targetSlot,weapons player,magazines player];
	cutText ["Toolbelt conversion failed: missing weapon class.", "PLAIN DOWN"];
};

if ((_create in ["MeleeHatchet","MeleeCrowbar"]) and _hasPrimary) exitWith {
	_targetSlot = "onBack";
	if (!isNil "A2EDC_fnc_normalizeOnBack") then {
		call A2EDC_fnc_normalizeOnBack;
	};
	_back = if (isNil "A2EDC_onBack") then {player getVariable ["A2EDC_onBack",""]} else {A2EDC_onBack};
	if ((typeName _back) != "STRING") then {
		_back = "";
	};
	_hasSwitch = !(isNil "A2EDC_fnc_switchOnBackWeapon");
	_hasTrigger = !(isNil "A2EDC_fnc_bSmenaTrigger");
	_hasFallback = !(isNil "s_player_a2edc_onBackSwitch");
	_onBackSystemAvailable = (!(isNil "A2EDC_onBack") and _hasSwitch and (_hasTrigger or _hasFallback) and (_back == "") and (isClass (configFile >> "CfgWeapons" >> _create)));
	if (!_onBackSystemAvailable) exitWith {
		diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=onback_system_unavailable item=%1 primary=%2 A2EDC_onBack=%3 hasSwitch=%4 hasTrigger=%5 hasFallback=%6 create=%7 createExists=%8",_item,_primary,_back,_hasSwitch,_hasTrigger,_hasFallback,_create,isClass (configFile >> "CfgWeapons" >> _create)];
		cutText ["Weapon on back is not ready yet.", "PLAIN DOWN"];
	};
	if (_back != "") exitWith {
		diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=onBack_occupied item=%1 create=%2 selectedTarget=%3 primary=%4 A2EDC_onBack=%5 weaponsBefore=%6 weaponsAfter=%7 magazinesBefore=%8 magazinesAfter=%9",_item,_create,_targetSlot,_primary,_back,_weaponsBefore,weapons player,_magsBefore,magazines player];
		cutText ["Weapon on back is already occupied.", "PLAIN DOWN"];
	};
	if (!isNil "A2EDC_fnc_onBackClassValid") then {
		_valid = _create call A2EDC_fnc_onBackClassValid;
	} else {
		_valid = [true,"no_validator"];
	};
	if (!(_valid select 0)) exitWith {
		diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=invalid_onBack_output detail=%1 item=%2 create=%3 selectedTarget=%4 primary=%5 weapons=%6 magazines=%7",_valid select 1,_item,_create,_targetSlot,_primary,weapons player,magazines player];
		cutText ["Toolbelt conversion failed: invalid on-back weapon.", "PLAIN DOWN"];
	};
	A2EDC_onBack = _create;
	dayz_onBack = A2EDC_onBack;
	player setVariable ["A2EDC_onBack",A2EDC_onBack,true];
	player removeWeapon _item;
	diag_log format["A2EDC:HATCHET_CONVERT_END reason=stored_onBack item=%1 create=%2 selectedTarget=%3 primary=%4 A2EDC_onBack=%5 weaponsBefore=%6 weaponsAfter=%7 magazinesBefore=%8 magazinesAfter=%9",_item,_create,_targetSlot,primaryWeapon player,A2EDC_onBack,_weaponsBefore,weapons player,_magsBefore,magazines player];
	if (!isNil "A2EDC_fnc_refreshOnBackGearSlot") then {
		call A2EDC_fnc_refreshOnBackGearSlot;
	};
};

if (_item in ["MeleeHatchet","MeleeCrowbar"]) then {
	_magType = ([] + getArray (configFile >> "cfgWeapons" >> _item >> "magazines")) select 0;
	_meleeNum = ({_x == _magType} count magazines player);
	for "_i" from 1 to _meleeNum do {
		player removeMagazine _magType;
	};
};

_isOk = [player,_config2] call BIS_fnc_invAdd;
if (_isOk) then {
	player removeWeapon _item;
	if (_create in ["MeleeHatchet","MeleeCrowbar"]) then {
		if (_create == "MeleeCrowbar") then {
			player addMagazine "crowbar_swing";
		} else {
			player addMagazine "hatchet_swing";
		};
		if (_type == "cfgWeapons") then {
			_muzzles = getArray(configFile >> "cfgWeapons" >> _create >> "muzzles");
			_wtype = ((weapons player) select 0);
			if (count _muzzles > 1) then {
				player selectWeapon (_muzzles select 0);
			} else {
				player selectWeapon _wtype;
			};
		};
	};
	_reason = "converted";
	if ((_create in ["MeleeHatchet","MeleeCrowbar"]) and (_create in weapons player)) then {
		player selectWeapon _create;
	};
	if ((currentWeapon player == "") and (_primary in weapons player)) then {
		player selectWeapon _primary;
		_reason = "converted_reselected_primary";
	};
	diag_log format["A2EDC:HATCHET_CONVERT_END reason=%1 item=%2 create=%3 selectedTarget=%4 primary=%5 A2EDC_onBack=%6 weaponsBefore=%7 weaponsAfter=%8 magazinesBefore=%9 magazinesAfter=%10",_reason,_item,_create,_targetSlot,primaryWeapon player,_back,_weaponsBefore,weapons player,_magsBefore,magazines player];
	if (!isNil "A2EDC_fnc_refreshOnBackGearSlot") then {
		call A2EDC_fnc_refreshOnBackGearSlot;
	};
} else {
	_reason = "inventory_add_failed";
	if ((_create in ["MeleeHatchet","MeleeCrowbar"]) and _hasPrimary) then {
		_reason = "primary_slot_occupied";
		cutText ["Weapon conversion failed: primary slot is occupied.", "PLAIN DOWN"];
	} else {
		cutText [localize "STR_DAYZ_CODE_2", "PLAIN DOWN"];
	};
	diag_log format["A2EDC:HATCHET_CONVERT_FAIL reason=%1 item=%2 create=%3 selectedTarget=%4 primary=%5 A2EDC_onBack=%6 weaponsBefore=%7 weaponsAfter=%8 magazinesBefore=%9 magazinesAfter=%10",_reason,_item,_create,_targetSlot,primaryWeapon player,_back,_weaponsBefore,weapons player,_magsBefore,magazines player];
	if (_item in ["MeleeHatchet","MeleeCrowbar"]) then {
		if (_item == "MeleeCrowbar") then {
			player addMagazine "crowbar_swing";
		} else {
			player addMagazine "hatchet_swing";
		};
	};
};
