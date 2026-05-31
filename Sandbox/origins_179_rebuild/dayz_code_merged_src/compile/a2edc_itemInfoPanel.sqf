disableSerialization;
if (isNil "A2EDC_debugItemInfo") then {
	A2EDC_debugItemInfo = false;
};

private["_event","_mode","_control","_display","_item","_row","_conf","_confType","_name","_picture","_description","_count","_ammo","_ammoName","_usedIn","_cfgWeapons","_weaponCfg","_weaponName","_mags","_i","_weight","_weightSource","_showRounds","_text","_title","_panel","_image","_lines","_duplicateTitle","_visibleLines"];

_event = _this select 0;
_mode = _this select 1;
_control = _event select 0;
_display = findDisplay 106;
if (isNull _display) exitWith {};
if (isNil "A2EDC_debugOnBack") then {
	A2EDC_debugOnBack = true;
};
if (A2EDC_debugOnBack) then {
	diag_log format["A2EDC:ONBACK_STATE phase=tooltip_bridge_initialized primary=%1 current=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5 anim=%6",primaryWeapon player,currentWeapon player,weapons player,magazines player,player getVariable ["A2EDC_onBack",""],animationState player];
};

_item = "";
if (_mode == "slot") then {
	_item = gearSlotData _control;
};
if (_mode == "list") then {
	_row = -1;
	if ((count _event) > 1) then {
		_row = _event select 1;
	};
	if ((typeName _row) == "ARRAY") then {
		if ((count _row) > 0) then {
			_row = _row select 0;
		} else {
			_row = -1;
		};
	};
	if ((typeName _row) != "SCALAR") exitWith {
		if (A2EDC_debugItemInfo) then {
			diag_log "A2EDC:ITEM_INFO_PANEL item=<empty> result=fail reason=no_list_row";
		};
	};
	if (_row >= 0) then {
		_item = _control lnbData [_row,0];
		if (_item == "") then {
			_item = _control lnbData [_row,1];
		};
		if (_item == "") then {
			_item = _control lnbText [_row,1];
		};
	};
};

if (_item == "") exitWith {
	if (A2EDC_debugItemInfo) then {
		diag_log "A2EDC:ITEM_INFO_PANEL item=<empty> result=fail reason=no_item";
	};
};

_conf = configFile >> "CfgMagazines" >> _item;
_confType = "CfgMagazines";
if (!isClass _conf) then {
	_conf = configFile >> "CfgWeapons" >> _item;
	_confType = "CfgWeapons";
};
if (!isClass _conf) exitWith {
	diag_log format["A2EDC:ITEM_INFO_PANEL item=%1 result=fail reason=no_config",_item];
};

_name = getText (_conf >> "displayName");
if (_name == "") then {
	_name = _item;
};
_picture = getText (_conf >> "picture");
_description = getText (_conf >> "descriptionShort");

if ((isNil "A2EDC_fnc_getItemWeightKg") or (isNil "A2EDC_fnc_formatItemWeightKg")) then {
	call compile preprocessFileLineNumbers "\z\addons\dayz_code\compile\A2EDC_itemWeights.sqf";
};
_weight = [_item,_confType] call A2EDC_fnc_getItemWeightKg;
_weightSource = if (_weight >= 0) then {"A2EDC_reconstructed"} else {"none"};
_showRounds = (_weight < 0);

_lines = [];
if (_description != "") then {
	_lines set [count _lines,_description];
};

if (_confType == "CfgMagazines") then {
	_count = getNumber (_conf >> "count");
	if (_showRounds and (_count > 0)) then {
		_lines set [count _lines,format["Rounds: %1",_count]];
	};
	_ammo = getText (_conf >> "ammo");
	if (_ammo != "") then {
		_ammoName = getText (configFile >> "CfgAmmo" >> _ammo >> "displayName");
		if (_ammoName == "") then {
			_ammoName = _ammo;
		};
		_lines set [count _lines,format["Caliber: %1",_ammoName]];
	};
	_usedIn = [];
	_cfgWeapons = configFile >> "CfgWeapons";
	for "_i" from 0 to ((count _cfgWeapons) - 1) do {
		_weaponCfg = _cfgWeapons select _i;
		if (isClass _weaponCfg) then {
			_mags = getArray (_weaponCfg >> "magazines");
			if (_item in _mags) then {
				_weaponName = getText (_weaponCfg >> "displayName");
				if ((_weaponName != "") and !(_weaponName in _usedIn)) then {
					_usedIn set [count _usedIn,_weaponName];
				};
			};
		};
	};
	if ((count _usedIn) > 0) then {
		_lines set [count _lines,format["Used in: %1",_usedIn select 0]];
	};
};

if (_confType == "CfgWeapons") then {
	_mags = getArray (_conf >> "magazines");
	if ((count _mags) > 0) then {
		_lines set [count _lines,format["Magazine: %1",getText (configFile >> "CfgMagazines" >> (_mags select 0) >> "displayName")]];
	};
};

if (_weight >= 0) then {
	_lines set [count _lines,format["<t color='#ffffff'>Weight: %1 kg</t>",[_weight] call A2EDC_fnc_formatItemWeightKg]];
};

_duplicateTitle = false;
if ((count _lines) > 0) then {
	if ((_lines select 0) == _name) then {
		_lines set [0,""];
		_duplicateTitle = true;
	};
};

_text = "";
_visibleLines = 0;
{
	if (_x != "") then {
		if (_text == "") then {
			_text = _x;
		} else {
			_text = _text + "<br/>" + _x;
		};
		_visibleLines = _visibleLines + 1;
	};
} forEach _lines;
if (_text == "") then {
	_text = " ";
};

_title = _display displayCtrl 1101;
_panel = _display displayCtrl 1106;
_image = _display displayCtrl 1104;
if (!(isNull _title)) then {
	_title ctrlSetText _name;
};
if (!(isNull _panel)) then {
	_panel ctrlSetStructuredText parseText _text;
};
if (!(isNull _image)) then {
	_image ctrlSetText _picture;
};

diag_log format["A2EDC:ITEM_INFO item=%1 cfg=%2 displayName=%3 weight=%4 source=%5",_item,_confType,_name,if (_weight >= 0) then {_weight} else {"none"},_weightSource];
diag_log format["A2EDC:ITEM_INFO_PANEL item=%1 title=%2 lines=%3 duplicateTitle=%4 result=ok reason=updated",_item,_name,_visibleLines,_duplicateTitle];
