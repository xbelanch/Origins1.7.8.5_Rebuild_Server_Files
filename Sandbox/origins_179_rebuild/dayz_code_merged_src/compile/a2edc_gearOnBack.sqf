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
if (isNil "A2EDC_onBackNonPersistentWarningLast") then {
	A2EDC_onBackNonPersistentWarningLast = "";
};

A2EDC_fnc_warnOnBackNonPersistent = {
	private["_back"];
	_back = _this;
	if ((typeName _back) != "STRING") exitWith {};
	if (_back == "") exitWith {
		A2EDC_onBackNonPersistentWarningLast = "";
	};
	if (A2EDC_onBackNonPersistentWarningLast != _back) then {
		A2EDC_onBackNonPersistentWarningLast = _back;
		diag_log format["A2EDC:ONBACK_NONPERSISTENT_WARNING A2EDC_onBack=%1 note=onBack is client-only before v3; disconnect/relog may lose this item",_back];
	};
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
	private["_display","_ranges","_idc","_ctrl","_isNull","_text","_shown","_position"];
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
	{
		_idc = _x;
		_ctrl = _display displayCtrl _idc;
		_isNull = isNull _ctrl;
		_text = "<null>";
		_shown = false;
		_position = [];
		if (!_isNull) then {
			_text = ctrlText _ctrl;
			_shown = ctrlShown _ctrl;
			_position = ctrlPosition _ctrl;
		};
		diag_log format["A2EDC:GEAR_CTRL_DUMP idc=%1 isNull=%2 ctrlText=%3 ctrlShown=%4 ctrlPosition=%5",_idc,_isNull,_text,_shown,_position];
	} forEach _ranges;
};

A2EDC_fnc_refreshOnBackGearSlot = {
	private["_display","_ctrl","_back","_picture","_applied","_reason","_displayFound","_ctrlFound","_valid","_scheduleDelays","_displayId","_ctrlIdc","_textBefore","_textAfter","_shown","_position","_pictureEmpty","_setTextCalled","_commitCalled","_showAttempted"];
	disableSerialization;
	_scheduleDelays = true;
	if (!isNil "_this") then {
		if ((typeName _this) == "ARRAY") then {
			if ((count _this) > 0) then {
				_scheduleDelays = _this select 0;
			};
		};
	};
	call A2EDC_fnc_normalizeOnBack;
	_display = findDisplay 106;
	_displayFound = !(isNull _display);
	_ctrlFound = false;
	_displayId = 106;
	_back = A2EDC_onBack;
	_picture = "";
	_applied = false;
	_reason = "ok";
	_ctrlIdc = 108;
	_textBefore = "<no_ctrl>";
	_textAfter = "<no_ctrl>";
	_shown = false;
	_position = [];
	_pictureEmpty = true;
	_setTextCalled = false;
	_commitCalled = false;
	_showAttempted = false;

	if (!_displayFound) exitWith {
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH displayFound=%1 ctrl108Found=%2 A2EDC_onBack=%3 picture=%4 applied=%5 reason=%6",_displayFound,_ctrlFound,_back,_picture,_applied,"no_display"];
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DIAG displayId=%1 displayIsNull=%2 ctrl108IsNull=%3 ctrlIDC=%4 ctrlTextBefore=%5 ctrlTextAfter=%6 ctrlShown=%7 ctrlPosition=%8 A2EDC_onBack=%9 picture=%10 pictureEmpty=%11 ctrlSetTextCalled=%12 ctrlCommitCalled=%13 ctrlShowTrueAttempted=%14 applied=%15 reason=%16",_displayId,true,true,_ctrlIdc,_textBefore,_textAfter,_shown,_position,_back,_picture,_pictureEmpty,_setTextCalled,_commitCalled,_showAttempted,_applied,"no_display"];
	};

	_ctrl = _display displayCtrl 108;
	_ctrlFound = !(isNull _ctrl);
	if (!_ctrlFound) exitWith {
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH displayFound=%1 ctrl108Found=%2 A2EDC_onBack=%3 picture=%4 applied=%5 reason=%6",_displayFound,_ctrlFound,_back,_picture,_applied,"no_ctrl_108"];
		diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DIAG displayId=%1 displayIsNull=%2 ctrl108IsNull=%3 ctrlIDC=%4 ctrlTextBefore=%5 ctrlTextAfter=%6 ctrlShown=%7 ctrlPosition=%8 A2EDC_onBack=%9 picture=%10 pictureEmpty=%11 ctrlSetTextCalled=%12 ctrlCommitCalled=%13 ctrlShowTrueAttempted=%14 applied=%15 reason=%16",_displayId,false,true,_ctrlIdc,_textBefore,_textAfter,_shown,_position,_back,_picture,_pictureEmpty,_setTextCalled,_commitCalled,_showAttempted,_applied,"no_ctrl_108"];
	};
	_textBefore = ctrlText _ctrl;
	_shown = ctrlShown _ctrl;
	_position = ctrlPosition _ctrl;

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
	};
	_pictureEmpty = (_picture == "");

	if (_reason == "ok") then {
		_ctrl ctrlSetText _picture;
		_setTextCalled = true;
		_ctrl ctrlShow true;
		_showAttempted = true;
		_ctrl ctrlCommit 0;
		_commitCalled = true;
		_applied = true;
	};
	if (_back == "") then {
		_ctrl ctrlSetText "";
		_setTextCalled = true;
		_ctrl ctrlShow true;
		_showAttempted = true;
		_ctrl ctrlCommit 0;
		_commitCalled = true;
		_applied = true;
		_reason = "cleared_empty_onBack";
	};
	_textAfter = ctrlText _ctrl;
	_shown = ctrlShown _ctrl;
	_position = ctrlPosition _ctrl;
	diag_log format["A2EDC:ONBACK_SLOT_REFRESH displayFound=%1 ctrl108Found=%2 A2EDC_onBack=%3 picture=%4 applied=%5 reason=%6",_displayFound,_ctrlFound,_back,_picture,_applied,_reason];
	diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DIAG displayId=%1 displayIsNull=%2 ctrl108IsNull=%3 ctrlIDC=%4 ctrlTextBefore=%5 ctrlTextAfter=%6 ctrlShown=%7 ctrlPosition=%8 A2EDC_onBack=%9 picture=%10 pictureEmpty=%11 ctrlSetTextCalled=%12 ctrlCommitCalled=%13 ctrlShowTrueAttempted=%14 applied=%15 reason=%16",_displayId,false,false,_ctrlIdc,_textBefore,_textAfter,_shown,_position,_back,_picture,_pictureEmpty,_setTextCalled,_commitCalled,_showAttempted,_applied,_reason];

	if (_scheduleDelays and _displayFound and _ctrlFound) then {
		if (isNil "A2EDC_gearCtrlDumpDone") then {
			A2EDC_gearCtrlDumpDone = false;
		};
		if (!A2EDC_gearCtrlDumpDone) then {
			A2EDC_gearCtrlDumpDone = true;
			call A2EDC_fnc_dumpGearControls;
		};
		[["0",0],["001",0.01],["010",0.10],["025",0.25]] spawn {
			private["_pass","_delay","_display","_ctrl","_before","_after","_applied"];
			{
				_pass = _x select 0;
				_delay = _x select 1;
				if (_delay > 0) then {
					sleep _delay;
				};
				disableSerialization;
				_display = findDisplay 106;
				if (isNull _display) then {
					diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DELAY pass=%1 applied=false ctrlTextBefore=<no_display> ctrlTextAfter=<no_display>",_pass];
				} else {
					_ctrl = _display displayCtrl 108;
					if (isNull _ctrl) then {
						diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DELAY pass=%1 applied=false ctrlTextBefore=<no_ctrl_108> ctrlTextAfter=<no_ctrl_108>",_pass];
					} else {
						_before = ctrlText _ctrl;
						[false] call A2EDC_fnc_refreshOnBackGearSlot;
						_after = ctrlText _ctrl;
						_applied = (_after != "");
						if (_before != _after) then {
							_applied = true;
						};
						diag_log format["A2EDC:ONBACK_SLOT_REFRESH_DELAY pass=%1 applied=%2 ctrlTextBefore=%3 ctrlTextAfter=%4",_pass,_applied,_before,_after];
					};
				};
			} forEach _this;
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
	call A2EDC_fnc_refreshOnBackGearSlot;
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
	call A2EDC_fnc_refreshOnBackGearSlot;
};

A2EDC_fnc_switchWeapon = A2EDC_fnc_switchOnBackWeapon;
call A2EDC_fnc_normalizeOnBack;
call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\a2edc_buildinfo.sqf";
call compile preprocessFileLineNumbers "\z\addons\dayz_code\init\a2edc_onback_compile_status.sqf";
if (A2EDC_debugOnBack) then {
	diag_log format["A2EDC:ONBACK_INIT primary=%1 current=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5 dayz_onBack=%6 anim=%7",primaryWeapon player,currentWeapon player,weapons player,magazines player,A2EDC_onBack,dayz_onBack,animationState player];
};
