if (isNil "A2EDC_debugOnBack") then {
	A2EDC_debugOnBack = true;
};
if (isNil "A2EDC_onBackBanned") then {
	A2EDC_onBackBanned = [];
};
if (isNil "A2EDC_primaryToolbeltItems") then {
	A2EDC_primaryToolbeltItems = ["ItemHatchet","ItemCrowbar","ItemPickaxe","ItemToolbox","ItemEtool","ItemHose","ItemKnife","ItemMap","ItemCompass","ItemWatch","ItemRadio","ItemGPS","ItemMatchbox","ItemFlashlight","ItemFlashlightRed","Binocular","Binocular_Vector","NVGoggles"];
};
if (isNil "A2EDC_onBackNormalizedLogged") then {
	A2EDC_onBackNormalizedLogged = false;
};
if (isNil "A2EDC_debugOnBackVisual") then {
	A2EDC_debugOnBackVisual = false;
};
if (isNil "A2EDC_debugEpochRefGearRefresh") then {
	A2EDC_debugEpochRefGearRefresh = false;
};
if (isNil "A2EDC_onBackVisualTargetIDC") then {
	A2EDC_onBackVisualTargetIDC = 511;
};
if (isNil "A2EDC_onBackNonPersistentWarningLast") then {
	A2EDC_onBackNonPersistentWarningLast = "";
};
if (isNil "A2EDC_onBackPersistenceEnabled") then {
	A2EDC_onBackPersistenceEnabled = true;
};

A2EDC_fnc_warnOnBackNonPersistent = {
	private["_back"];
	if (isNil "A2EDC_onBackPersistenceEnabled") then {A2EDC_onBackPersistenceEnabled = true;};
	if ((typeName A2EDC_onBackPersistenceEnabled) != "BOOL") then {A2EDC_onBackPersistenceEnabled = true;};
	if (A2EDC_onBackPersistenceEnabled) exitWith {};
	_back = _this;
	if ((typeName _back) != "STRING") exitWith {};
	if (_back == "") exitWith {
		A2EDC_onBackNonPersistentWarningLast = "";
	};
	A2EDC_onBackNonPersistentWarningLast = _back;
};

A2EDC_fnc_normalizeOnBack = {
	private["_globalBefore","_playerBefore","_normalized","_changed","_reason"];
	_globalBefore = if (isNil "A2EDC_onBack") then {"<nil>"} else {A2EDC_onBack};
	_playerBefore = player getVariable ["A2EDC_onBack",""];
	_normalized = "";
	_changed = false;
	_reason = [];

	if (isNil "A2EDC_onBack") then {
		A2EDC_onBack = "";
		_changed = true;
		_reason set [count _reason,"global_nil"];
	};
	if ((typeName A2EDC_onBack) != "STRING") then {
		A2EDC_onBack = "";
		_changed = true;
		_reason set [count _reason,"global_not_string"];
	};
	if ((typeName _playerBefore) != "STRING") then {
		_playerBefore = "";
		_changed = true;
		_reason set [count _reason,"player_var_not_string"];
	};
	_normalized = A2EDC_onBack;
	if ((toLower _normalized) == "any") then {
		_normalized = "";
		_changed = true;
		_reason set [count _reason,"global_any_string"];
	};
	if ((_playerBefore != "") and (_normalized == "")) then {
		_normalized = _playerBefore;
	};
	if ((toLower _normalized) == "any") then {
		_normalized = "";
		_changed = true;
		_reason set [count _reason,"player_any_string"];
	};

	A2EDC_onBack = _normalized;
	dayz_onBack = A2EDC_onBack;
	player setVariable ["A2EDC_onBack",A2EDC_onBack,true];
	player setVariable ["dayz_onBack",dayz_onBack,true];
	if (isNil "dayz_onBack") then {
		dayz_onBack = A2EDC_onBack;
		_changed = true;
		_reason set [count _reason,"alias_nil"];
	};
	if ((typeName dayz_onBack) != "STRING") then {
		dayz_onBack = A2EDC_onBack;
		_changed = true;
		_reason set [count _reason,"alias_not_string"];
	};
	A2EDC_onBack call A2EDC_fnc_warnOnBackNonPersistent;
	if (_changed and !A2EDC_onBackNormalizedLogged) then {
		A2EDC_onBackNormalizedLogged = true;
		diag_log format["A2EDC:ONBACK_NORMALIZE reason=%1 globalBefore=%2 globalType=%3 playerBefore=%4 playerType=%5 normalized=%6",_reason,_globalBefore,typeName _globalBefore,player getVariable ["A2EDC_onBack",""],typeName _playerBefore,A2EDC_onBack];
	};
	A2EDC_onBack
};

call A2EDC_fnc_normalizeOnBack;

A2EDC_fnc_onBackState = {
	private["_phase","_back"];
	_phase = _this;
	call A2EDC_fnc_normalizeOnBack;
	_back = if (isNil "A2EDC_onBack") then {player getVariable ["A2EDC_onBack",""]} else {A2EDC_onBack};
	if (A2EDC_debugOnBack) then {
		diag_log format["A2EDC:ONBACK_STATE phase=%1 primary=%2 current=%3 weapons=%4 magazines=%5 A2EDC_onBack=%6 anim=%7",_phase,primaryWeapon player,currentWeapon player,weapons player,magazines player,_back,animationState player];
	};
};

A2EDC_fnc_onBackClassValid = {
	private["_weapon","_cfg","_scope","_type","_valid","_reason"];
	_weapon = _this;
	_cfg = configFile >> "CfgWeapons" >> _weapon;
	_valid = true;
	_reason = "ok";
	if (_weapon == "") exitWith {[true,"empty"]};
	if (!isClass _cfg) exitWith {[false,"missing_cfgWeapons_class"]};
	_scope = getNumber (_cfg >> "scope");
	if (_scope < 1) exitWith {[false,format["private_scope_%1",_scope]]};
	if (_weapon in A2EDC_onBackBanned) exitWith {[false,"banned_class"]};
	if (_weapon in A2EDC_primaryToolbeltItems) exitWith {[false,"toolbelt_item"]};
	_type = getNumber (_cfg >> "type");
	if (_type != 1) exitWith {[false,format["not_primary_type_%1",_type]]};
	[_valid,_reason]
};

A2EDC_fnc_selectOnBackWeapon = {
	private["_weapon","_muzzles"];
	_weapon = _this;
	if (_weapon == "") exitWith {};
	if (!(_weapon in weapons player)) exitWith {
		diag_log format["A2EDC:ONBACK_SWITCH_FAIL reason=select_not_in_weapons weapon=%1 weapons=%2",_weapon,weapons player];
	};
	_muzzles = getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles");
	if ((count _muzzles) > 1) then {
		player selectWeapon (_muzzles select 0);
	} else {
		player selectWeapon _weapon;
	};
};

A2EDC_fnc_dumpGearControls = {
	private["_display","_ranges","_idc","_ctrl","_isNull","_text","_shown","_position","_ctrlType","_enabled","_fade"];
	disableSerialization;
	_display = findDisplay 106;
	if (isNull _display) exitWith {
		diag_log "A2EDC:GEAR_CTRL_DUMP displayFound=false reason=no_display";
	};
	_ranges = [];
	for "_idc" from 100 to 130 do {
		_ranges set [count _ranges,_idc];
	};
	for "_idc" from 500 to 520 do {
		_ranges set [count _ranges,_idc];
	};
	for "_idc" from 5011 to 5022 do {
		_ranges set [count _ranges,_idc];
	};
	{
		_idc = _x;
		_ctrl = _display displayCtrl _idc;
		_isNull = isNull _ctrl;
		_text = "<null>";
		_shown = false;
		_position = [];
		_ctrlType = "<unsupported-a2>";
		_enabled = "<unsupported-a2>";
		_fade = "<unsupported-a2>";
		if (!_isNull) then {
			_text = ctrlText _ctrl;
			_shown = ctrlShown _ctrl;
			_position = ctrlPosition _ctrl;
		};
		diag_log format["A2EDC:GEAR_CTRL_DUMP idc=%1 isNull=%2 ctrlType=%3 ctrlText=%4 ctrlShown=%5 ctrlEnabled=%6 ctrlFade=%7 ctrlPosition=%8",_idc,_isNull,_ctrlType,_text,_shown,_enabled,_fade,_position];
	} forEach _ranges;
};

A2EDC_fnc_callEpochRefGearRefresh = {
	private["_display","_called","_function","_result","_displayFromArg","_fallbackFindDisplay"];
	disableSerialization;
	_display = findDisplay 999999;
	_called = false;
	_function = "none";
	_result = "skipped";
	_displayFromArg = false;
	_fallbackFindDisplay = false;

	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {
				_display = _this select 0;
				if (!isNull _display) then {
					_displayFromArg = true;
				};
			};
		};
	};
	if (isNull _display) then {
		_display = findDisplay 106;
		_fallbackFindDisplay = true;
	};

	if (A2EDC_debugEpochRefGearRefresh) then {
		if (isNull _display) then {
			_result = "no_display";
		} else {
			if (isNil "handleGear") then {
				_result = "handleGear_nil";
			} else {
				_called = true;
				_function = "handleGear_onLBSelChanged";
				_result = "called";
				[[_display],"onLBSelChanged"] call handleGear;
			};
		};
	};
	diag_log format["A2EDC:ONBACK_GEAR_REFRESH_EPOCH_REF called=%1 function=%2 result=%3 displayFromArg=%4 fallbackFindDisplay=%5 displayFound=%6",_called,_function,_result,_displayFromArg,_fallbackFindDisplay,!isNull _display];
	_called
};

A2EDC_fnc_refreshOnBackGearSlot = {
	private["_display","_ctrl","_back","_picture","_applied","_reason","_valid","_targetIDC","_textAfter","_displayFromArg","_fallbackFindDisplay","_source","_pass"];
	disableSerialization;
	call A2EDC_fnc_normalizeOnBack;
	_display = findDisplay 999999;
	_source = "direct";
	_pass = "none";
	_displayFromArg = false;
	_fallbackFindDisplay = false;
	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {
				_display = _this select 0;
				if (!isNull _display) then {
					_displayFromArg = true;
				};
			};
			if ((count _this) > 1) then {
				_source = _this select 1;
			};
			if ((count _this) > 2) then {
				_pass = _this select 2;
			};
		};
	};
	if (isNull _display) then {
		_display = findDisplay 106;
		_fallbackFindDisplay = true;
	};
	_targetIDC = 511;
	A2EDC_onBackVisualTargetIDC = _targetIDC;
	_back = A2EDC_onBack;
	_picture = "";
	_applied = false;
	_reason = "ok";
	_textAfter = "";

	if (isNull _display) exitWith {
		_reason = "no_display";
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH targetIDC=%1 source=%2 pass=%3 displayFromArg=%4 fallbackFindDisplay=%5 displayFound=%6 A2EDC_onBack=%7 picture=%8 applied=%9 reason=%10",_targetIDC,_source,_pass,_displayFromArg,_fallbackFindDisplay,false,_back,_picture,_applied,_reason];
	};

	_ctrl = _display displayCtrl _targetIDC;
	if (isNull _ctrl) exitWith {
		_reason = "no_target_control";
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH targetIDC=%1 source=%2 pass=%3 displayFromArg=%4 fallbackFindDisplay=%5 displayFound=%6 A2EDC_onBack=%7 picture=%8 applied=%9 reason=%10",_targetIDC,_source,_pass,_displayFromArg,_fallbackFindDisplay,true,_back,_picture,_applied,_reason];
	};

	if (_back != "") then {
		_valid = _back call A2EDC_fnc_onBackClassValid;
		if (!(_valid select 0)) then {
			_reason = format["invalid_onBack detail=%1",_valid select 1];
		} else {
			_picture = getText (configFile >> "CfgWeapons" >> _back >> "picture");
			if (_picture == "") then {
				_reason = "empty_picture";
			};
		};
		if (_reason == "ok") then {
			_ctrl ctrlSetText _picture;
			_ctrl ctrlShow true;
			_ctrl ctrlSetFade 0;
			_ctrl ctrlCommit 0;
			_textAfter = ctrlText _ctrl;
			_applied = true;
		};
	} else {
		_ctrl ctrlSetText "";
		_ctrl ctrlShow true;
		_ctrl ctrlSetFade 0;
		_ctrl ctrlCommit 0;
		_textAfter = ctrlText _ctrl;
		_applied = true;
		_reason = "cleared_empty_onBack";
	};
	diag_log format["A2EDC:ONBACK_SLOT_REFRESH targetIDC=%1 source=%2 pass=%3 displayFromArg=%4 fallbackFindDisplay=%5 displayFound=%6 A2EDC_onBack=%7 picture=%8 applied=%9 reason=%10",_targetIDC,_source,_pass,_displayFromArg,_fallbackFindDisplay,true,_back,_picture,_applied,_reason];
	if (A2EDC_debugOnBackVisual) then {
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DIAG targetIDC=%1 ctrlTextAfter=%2 ctrlShown=%3 ctrlPosition=%4",_targetIDC,_textAfter,ctrlShown _ctrl,ctrlPosition _ctrl];
	};
};

A2EDC_fnc_clearOnBackGearSlot = {
	private["_display","_ctrl","_source","_reason","_applied","_targetIDC"];
	disableSerialization;
	_display = findDisplay 999999;
	_source = "clear";
	_reason = "ok";
	_applied = false;
	_targetIDC = 511;
	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {
				_display = _this select 0;
			};
			if ((count _this) > 1) then {
				_source = _this select 1;
			};
		};
	};
	if (isNull _display) then {
		_display = findDisplay 106;
	};
	if (isNull _display) exitWith {
		_reason = "no_display";
		diag_log format["A2EDC:ONBACK_SLOT_CLEAR targetIDC=%1 source=%2 displayFound=%3 applied=%4 reason=%5",_targetIDC,_source,false,_applied,_reason];
	};
	_ctrl = _display displayCtrl _targetIDC;
	if (isNull _ctrl) exitWith {
		_reason = "no_target_control";
		diag_log format["A2EDC:ONBACK_SLOT_CLEAR targetIDC=%1 source=%2 displayFound=%3 applied=%4 reason=%5",_targetIDC,_source,true,_applied,_reason];
	};
	_ctrl ctrlSetText "";
	_ctrl ctrlShow true;
	_ctrl ctrlSetFade 0;
	_ctrl ctrlCommit 0;
	_applied = true;
	diag_log format["A2EDC:ONBACK_SLOT_CLEAR targetIDC=%1 source=%2 displayFound=%3 applied=%4 reason=%5",_targetIDC,_source,true,_applied,_reason];
};

A2EDC_fnc_refreshNativeGearAfterSwitch = {
	private["_display","_source","_method","_result"];
	disableSerialization;
	_display = findDisplay 106;
	_source = _this;
	if ((typeName _source) != "STRING") then {
		_source = "switch";
	};
	_method = "none";
	_result = "skipped";
	if (isNull _display) exitWith {
		diag_log format["A2EDC:ONBACK_NATIVE_GEAR_REFRESH source=%1 displayFound=%2 method=%3 result=%4",_source,false,_method,"no_display"];
		false
	};
	if (isNil "handleGear") exitWith {
		diag_log format["A2EDC:ONBACK_NATIVE_GEAR_REFRESH source=%1 displayFound=%2 method=%3 result=%4",_source,true,_method,"handleGear_nil"];
		false
	};
	_method = "initDialog";
	[[_display],"initDialog"] call handleGear;
	_result = "ok";
	diag_log format["A2EDC:ONBACK_NATIVE_GEAR_REFRESH source=%1 displayFound=%2 method=%3 result=%4",_source,true,_method,_result];
	true
};

A2EDC_fnc_postSwitchVisualClear = {
	private["_oldPrimary","_newPrimary","_onBack","_display","_result","_source","_delays"];
	disableSerialization;
	_oldPrimary = "";
	_newPrimary = primaryWeapon player;
	_onBack = player getVariable ["A2EDC_onBack",""];
	_source = "switch";
	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {_oldPrimary = _this select 0;};
			if ((count _this) > 1) then {_newPrimary = _this select 1;};
			if ((count _this) > 2) then {_onBack = _this select 2;};
			if ((count _this) > 3) then {_source = _this select 3;};
		};
	};
	_display = findDisplay 106;
	_result = if (isNull _display) then {"no_display"} else {"scheduled"};
	diag_log format["A2EDC:ONBACK_POST_SWITCH_VISUAL_CLEAR source=%1 targetIDC=511 oldPrimary=%2 newPrimary=%3 onBack=%4 result=%5",_source,_oldPrimary,_newPrimary,_onBack,_result];
	if (isNull _display) exitWith {};
	[_display,"switch_pre_refresh"] call A2EDC_fnc_clearOnBackGearSlot;
	diag_log format["A2EDC:ONBACK_POST_SWITCH_VISUAL_REFRESH phase=clear source=%1 targetIDC=511 primary=%2 current=%3 onBack=%4 result=ok",_source,primaryWeapon player,currentWeapon player,player getVariable ["A2EDC_onBack",""]];
	_source call A2EDC_fnc_refreshNativeGearAfterSwitch;
	diag_log format["A2EDC:ONBACK_POST_SWITCH_VISUAL_REFRESH phase=native source=%1 targetIDC=511 primary=%2 current=%3 onBack=%4 result=called",_source,primaryWeapon player,currentWeapon player,player getVariable ["A2EDC_onBack",""]];
	_delays = [0.01,0.10,0.25];
	[_display,_source,_oldPrimary,_newPrimary,_onBack,_delays] spawn {
		private["_display","_source","_oldPrimary","_newPrimary","_onBack","_delays","_delay","_pass"];
		_display = _this select 0;
		_source = _this select 1;
		_oldPrimary = _this select 2;
		_newPrimary = _this select 3;
		_onBack = _this select 4;
		_delays = _this select 5;
		{
			_delay = _x;
			if (_delay > 0) then {sleep _delay;};
			_pass = "000";
			if (_delay >= 0.009) then {_pass = "001";};
			if (_delay >= 0.09) then {_pass = "010";};
			if (isNull _display) then {
				_display = findDisplay 106;
			};
			[_display,_source,_pass] call A2EDC_fnc_refreshOnBackGearSlot;
			diag_log format["A2EDC:ONBACK_POST_SWITCH_VISUAL_REFRESH phase=repaint source=%1 pass=%2 targetIDC=511 primary=%3 current=%4 onBack=%5 result=%6",_source,_pass,primaryWeapon player,currentWeapon player,player getVariable ["A2EDC_onBack",""],if (isNull _display) then {"no_display"} else {"ok"}];
			diag_log format["A2EDC:ONBACK_POST_SWITCH_VISUAL_CLEAR source=%1 pass=%2 targetIDC=511 oldPrimary=%3 newPrimary=%4 onBack=%5 result=%6",_source,_pass,_oldPrimary,_newPrimary,_onBack,if (isNull _display) then {"no_display"} else {"refreshed"}];
		} forEach _delays;
	};
};

A2EDC_fnc_onBackGearOpenRefresh = {
	private["_display","_source","_displayFromArg","_fallbackFindDisplay","_delays","_targetIDC"];
	disableSerialization;
	_display = findDisplay 999999;
	_source = "manual";
	_displayFromArg = false;
	_fallbackFindDisplay = false;
	_targetIDC = 511;
	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {
				_display = _this select 0;
				if (!isNull _display) then {
					_displayFromArg = true;
				};
			};
			if ((count _this) > 1) then {
				_source = _this select 1;
			};
		};
	};
	if (isNull _display) then {
		_display = findDisplay 106;
		_fallbackFindDisplay = true;
	};
	if (isNull _display) exitWith {
		diag_log format["A2EDC:ONBACK_GEAR_OPEN_REFRESH pass=000 source=%1 displayFromArg=%2 fallbackFindDisplay=%3 displayFound=%4 targetIDC=%5 A2EDC_onBack=%6",_source,_displayFromArg,_fallbackFindDisplay,false,_targetIDC,player getVariable ["A2EDC_onBack",""]];
	};
	_delays = [0.01,0.10,0.25];
	[_display,_source,_displayFromArg,_fallbackFindDisplay,_delays,_targetIDC] spawn {
		private["_display","_source","_displayFromArg","_fallbackFindDisplay","_delays","_targetIDC","_delay","_pass"];
		_display = _this select 0;
		_source = _this select 1;
		_displayFromArg = _this select 2;
		_fallbackFindDisplay = _this select 3;
		_delays = _this select 4;
		_targetIDC = _this select 5;
		{
			_delay = _x;
			sleep _delay;
			_pass = "001";
			if (_delay >= 0.09) then {_pass = "010";};
			if (_delay >= 0.24) then {_pass = "025";};
			if (isNull _display) then {
				_display = findDisplay 106;
				_fallbackFindDisplay = true;
			};
			diag_log format["A2EDC:ONBACK_GEAR_OPEN_REFRESH pass=%1 source=%2 displayFromArg=%3 fallbackFindDisplay=%4 displayFound=%5 targetIDC=%6 A2EDC_onBack=%7",_pass,_source,_displayFromArg,_fallbackFindDisplay,!isNull _display,_targetIDC,player getVariable ["A2EDC_onBack",""]];
			[_display] call A2EDC_fnc_callEpochRefGearRefresh;
			[_display,_source,_pass] call A2EDC_fnc_refreshOnBackGearSlot;
		} forEach _delays;
	};
};

A2EDC_fnc_scheduleOnBackGearRefresh = {
	private["_source","_display"];
	disableSerialization;
	_source = _this;
	if ((typeName _source) != "STRING") then {
		_source = "manual";
	};
	_display = findDisplay 106;
	[_display,_source] call A2EDC_fnc_onBackGearOpenRefresh;
};

if (!isDedicated and isNil "A2EDC_onBackGearWatcherStarted") then {
	A2EDC_onBackGearWatcherStarted = true;
	[] spawn {
		private["_wasOpen","_display"];
		disableSerialization;
		_wasOpen = false;
		while {true} do {
			_display = findDisplay 106;
			if ((!isNull _display) and !_wasOpen) then {
				_wasOpen = true;
				diag_log format["A2EDC:ONBACK_GEAR_WATCH openDetected=true displayFound=%1 targetIDC=511 A2EDC_onBack=%2",true,player getVariable ["A2EDC_onBack",""]];
				[_display,"watch"] call A2EDC_fnc_onBackGearOpenRefresh;
			};
			if (isNull _display) then {
				_wasOpen = false;
			};
			sleep 0.25;
		};
	};
};

A2EDC_fnc_switchOnBackWeapon = {
	private["_held","_back","_weaponsBefore","_magsBefore","_validBack","_validHeld","_reason","_existsBack","_existsHeld","_fail","_failReason"];
	call A2EDC_fnc_normalizeOnBack;
	_held = primaryWeapon player;
	_back = player getVariable ["A2EDC_onBack",A2EDC_onBack];
	_weaponsBefore = weapons player;
	_magsBefore = magazines player;
	if ((typeName _held) != "STRING") then {
		_held = "";
	};
	if ((typeName _back) != "STRING") then {
		_back = "";
		A2EDC_onBack = "";
		dayz_onBack = "";
		player setVariable ["A2EDC_onBack","",true];
		player setVariable ["dayz_onBack","",true];
		diag_log format["A2EDC:ONBACK_VALIDATE_FAIL reason=onBack_not_string weapons=%1 magazines=%2",_weaponsBefore,_magsBefore];
	};
	_existsBack = if (_back == "") then {true} else {isClass (configFile >> "CfgWeapons" >> _back)};
	_existsHeld = if (_held == "") then {true} else {isClass (configFile >> "CfgWeapons" >> _held)};
	_fail = false;
	_failReason = "none";

	if (A2EDC_debugOnBack) then {
		diag_log format["A2EDC:ONBACK_SWITCH_BEGIN primary=%1 current=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5 anim=%6 backClassExists=%7 heldClassExists=%8",_held,currentWeapon player,_weaponsBefore,_magsBefore,_back,animationState player,_existsBack,_existsHeld];
	};
	"A2EDC:ONBACK_SWITCH_BEGIN" call A2EDC_fnc_onBackState;

	if ((_held == "") and (_back == "")) exitWith {
		diag_log format["A2EDC:ONBACK_VALIDATE_FAIL reason=empty_primary_and_onBack primary=%1 A2EDC_onBack=%2 weapons=%3 magazines=%4 anim=%5",_held,_back,_weaponsBefore,_magsBefore,animationState player];
	};
	if (vehicle player != player) exitWith {
		diag_log format["A2EDC:ONBACK_SWITCH_FAIL reason=in_vehicle primary=%1 A2EDC_onBack=%2",_held,_back];
	};
	if ((getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1) exitWith {
		diag_log format["A2EDC:ONBACK_SWITCH_FAIL reason=on_ladder primary=%1 A2EDC_onBack=%2 anim=%3",_held,_back,animationState player];
	};
	if ((_held != "") and (_held == _back)) exitWith {
		A2EDC_onBack = "";
		dayz_onBack = "";
		player setVariable ["A2EDC_onBack","",true];
		player setVariable ["dayz_onBack","",true];
		diag_log format["A2EDC:ONBACK_DUP_GUARD reason=held_equals_onBack normalized=clear_onBack class=%1 weapons=%2 magazines=%3",_held,_weaponsBefore,_magsBefore];
		call A2EDC_fnc_refreshOnBackGearSlot;
	};
	if ((_back != "") and (_back in _weaponsBefore)) exitWith {
		diag_log format["A2EDC:ONBACK_DUP_GUARD reason=onBack_already_in_weapons class=%1 primary=%2 weapons=%3 magazines=%4 action=skip_add",_back,_held,_weaponsBefore,_magsBefore];
	};
	if (_back != "") then {
		_validBack = _back call A2EDC_fnc_onBackClassValid;
		if (!(_validBack select 0)) then {
			_fail = true;
			_failReason = format["invalid_onBack detail=%1",_validBack select 1];
		};
	};
	if (_fail) exitWith {
		diag_log format["A2EDC:ONBACK_VALIDATE_FAIL reason=%1 class=%2 classExists=%3 primary=%4 weapons=%5",_failReason,_back,_existsBack,_held,_weaponsBefore];
	};
	if (_held != "") then {
		_validHeld = _held call A2EDC_fnc_onBackClassValid;
		if (!(_validHeld select 0)) then {
			_fail = true;
			_failReason = format["invalid_held detail=%1",_validHeld select 1];
		};
		if ((!_fail) and !(_held in _weaponsBefore)) then {
			_fail = true;
			_failReason = "held_not_in_weapons";
		};
	};
	if (_fail) exitWith {
		diag_log format["A2EDC:ONBACK_VALIDATE_FAIL reason=%1 class=%2 classExists=%3 A2EDC_onBack=%4 weapons=%5",_failReason,_held,_existsHeld,_back,_weaponsBefore];
	};

	if (_back != "") then {
		player addWeapon _back;
	};
	if ((_held != "") and (_held in _weaponsBefore)) then {
		player removeWeapon _held;
	};

	A2EDC_onBack = _held;
	dayz_onBack = A2EDC_onBack;
	player setVariable ["A2EDC_onBack",A2EDC_onBack,true];
	player setVariable ["dayz_onBack",dayz_onBack,true];
	if (_back != "") then {
		_back call A2EDC_fnc_selectOnBackWeapon;
	};

	_reason = "swapped";
	if (_back == "") then {
		_reason = "moved_primary_to_onBack";
	};
	if (A2EDC_debugOnBack) then {
		diag_log format["A2EDC:ONBACK_SWITCH_END reason=%1 oldPrimary=%2 oldOnBack=%3 newPrimary=%4 current=%5 weaponsBefore=%6 weaponsAfter=%7 magazinesBefore=%8 magazinesAfter=%9 A2EDC_onBack=%10 anim=%11",_reason,_held,_back,primaryWeapon player,currentWeapon player,_weaponsBefore,weapons player,_magsBefore,magazines player,A2EDC_onBack,animationState player];
	};
	"A2EDC:ONBACK_SWITCH_END" call A2EDC_fnc_onBackState;
	[_held,primaryWeapon player,A2EDC_onBack,"switch"] call A2EDC_fnc_postSwitchVisualClear;
	diag_log format["A2EDC:ONBACK_DUPLICATE_VISUAL_CHECK weapons=%1 magazines=%2 primary=%3 current=%4 onBack=%5",weapons player,magazines player,primaryWeapon player,currentWeapon player,A2EDC_onBack];
	"switch" call A2EDC_fnc_scheduleOnBackGearRefresh;
};

A2EDC_fnc_bSmenaTrigger = {
	private["_callable","_beforeBack","_beforePrimary","_beforeWeapons","_beforeMags","_afterBack","_result"];
	call A2EDC_fnc_normalizeOnBack;
	_callable = !(isNil "A2EDC_fnc_switchOnBackWeapon");
	_beforeBack = A2EDC_onBack;
	_beforePrimary = primaryWeapon player;
	_beforeWeapons = weapons player;
	_beforeMags = magazines player;
	diag_log format["A2EDC:ONBACK_BSMENA_TRIGGER phase=begin callable=%1 current=%2 primary=%3 weapons=%4 magazines=%5 A2EDC_onBack=%6",_callable,currentWeapon player,_beforePrimary,_beforeWeapons,_beforeMags,_beforeBack];
	if (!_callable) exitWith {
		diag_log format["A2EDC:ONBACK_BSMENA_TRIGGER phase=end result=not_callable current=%1 primary=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5",currentWeapon player,primaryWeapon player,weapons player,magazines player,_beforeBack];
	};
	call A2EDC_fnc_switchOnBackWeapon;
	call A2EDC_fnc_normalizeOnBack;
	_afterBack = A2EDC_onBack;
	_result = "called_no_change";
	if (_beforeBack != _afterBack) then {
		_result = "called_changed";
	};
	if (_beforePrimary != primaryWeapon player) then {
		_result = "called_changed";
	};
	if (_beforeWeapons != weapons player) then {
		_result = "called_changed";
	};
	if (_beforeMags != magazines player) then {
		_result = "called_changed";
	};
	diag_log format["A2EDC:ONBACK_BSMENA_TRIGGER phase=end result=%1 callable=%2 current=%3 primary=%4 weapons=%5 magazines=%6 A2EDC_onBackBefore=%7 A2EDC_onBackAfter=%8",_result,_callable,currentWeapon player,primaryWeapon player,weapons player,magazines player,_beforeBack,_afterBack];
	[_beforePrimary,primaryWeapon player,_afterBack,"bSmena"] call A2EDC_fnc_postSwitchVisualClear;
	diag_log format["A2EDC:ONBACK_DUPLICATE_VISUAL_CHECK weapons=%1 magazines=%2 primary=%3 current=%4 onBack=%5",weapons player,magazines player,primaryWeapon player,currentWeapon player,_afterBack];
	"bSmena" call A2EDC_fnc_scheduleOnBackGearRefresh;
};

A2EDC_fnc_switchWeapon = A2EDC_fnc_switchOnBackWeapon;
call A2EDC_fnc_normalizeOnBack;
call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\a2edc_buildinfo.sqf";
call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\a2edc_onback_compile_status.sqf";
if (A2EDC_debugOnBack) then {
	diag_log format["A2EDC:ONBACK_INIT primary=%1 current=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5 dayz_onBack=%6 anim=%7",primaryWeapon player,currentWeapon player,weapons player,magazines player,A2EDC_onBack,dayz_onBack,animationState player];
};
