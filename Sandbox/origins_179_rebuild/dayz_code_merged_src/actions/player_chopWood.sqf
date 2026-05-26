private ["_item","_result","_rnd","_tC","_sA"];
_item = _this;
call gear_ui_init;
_name = 		getText(configFile >> "cfgWeapons" >> _item >> "displayName");
if(!(_item in weapons player)) exitWith {};
if (_item == "ItemPickaxe") then {
	if ((player distance [17382.5,8062.28,0] < 32) OR (player distance [8331.27,8909.49] < 32)) then {
		if(!(_item in weapons player)) exitWith { player removeMagazine "ItemRocks"; };
		_result = [player,"ItemRocks"] call BIS_fnc_invAdd;
		if (_result) then {
			[player,"pickaxe",0,false] call dayz_zombieSpeak;
			player playActionNow "Medic";
			sleep 5;
			cutText [localize "str_player_32", "PLAIN DOWN"];
			_rnd = random 1;
			if (_rnd > 0.98) then {
				[player,"slomkaon",0,false] call dayz_zombieSpeak;
				player removeWeapon "ItemPickaxe";
				cutText [format[localize "str_player_38",_name], "PLAIN DOWN",2];
			};
		} else {
			cutText [localize "str_player_24", "PLAIN DOWN"];
		};
	} else { cutText [localize "str_player_33", "PLAIN DOWN"]; };
	if(!(_item in weapons player)) exitWith { player removeMagazine "ItemRocks"; };
};

if (_item == "ItemHatchet") then {
	_tC = 0;
	_sA = [];
	{
	_sA = _sA + [str(_x)];
	} forEach nearestObjects [(position player), [], 30];
	{
		if ((["t_",str(_x),false] call fnc_inString)) then {
			_tC = _tC + 1;
		};
	} forEach _sA;
	
	diag_log format["A2EDC:INV_HATCHET item=%1 hasHatchet=%2 nearTree=%3 treeCount=%4 actionAvailable=%5",_item,(_item in weapons player),(_tC > 8),_tC,true];
	
	if (_tC > 8) then {
		if(!(_item in weapons player)) exitWith { player removeMagazine "PartWoodPile"; };
		_result = [player,"PartWoodPile"] call BIS_fnc_invAdd;
		if (_result) then {
			[player,"woodHcht",0,false] call dayz_zombieSpeak;
			player playActionNow "Medic";
			sleep 5;
			cutText [localize "str_player_25", "PLAIN DOWN"];
			_rnd = random 1;
			if (_rnd > 0.98) then {
				[player,"slomkaon",0,false] call dayz_zombieSpeak;
				player removeWeapon "ItemHatchet";
				cutText [format[localize "str_player_38",_name], "PLAIN DOWN",2];
			};
		} else {
			cutText [localize "str_player_24", "PLAIN DOWN"];
		};
	} else {
		disableSerialization;
		private["_gearDisplay","_titleCtrl","_panelCtrl","_displayMethod"];
		_displayMethod = "cutText";
		_gearDisplay = findDisplay 106;
		if (!(isNull _gearDisplay)) then {
			_titleCtrl = _gearDisplay displayCtrl 1101;
			_panelCtrl = _gearDisplay displayCtrl 1106;
			if (!(isNull _titleCtrl)) then {
				_titleCtrl ctrlSetText "Hatchet";
			};
			if (!(isNull _panelCtrl)) then {
				_panelCtrl ctrlSetStructuredText parseText "<t color='#ffcc66'>No suitable tree nearby.</t>";
				_displayMethod = "gear_panel";
			};
		};
		diag_log format["A2EDC:INV_HATCHET_NO_TREE item=%1 treeCount=%2 pos=%3 display=%4",_item,_tC,position player,_displayMethod];
		if (_displayMethod == "cutText") then {
			cutText ["No suitable tree nearby.", "PLAIN DOWN"];
		};
	};
	if(!(_item in weapons player)) exitWith { player removeMagazine "PartWoodPile"; };
};
