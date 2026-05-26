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
};

A2EDC_fnc_switchWeapon = A2EDC_fnc_switchOnBackWeapon;
call A2EDC_fnc_normalizeOnBack;
if (A2EDC_debugOnBack) then {
	diag_log format["A2EDC:ONBACK_INIT primary=%1 current=%2 weapons=%3 magazines=%4 A2EDC_onBack=%5 dayz_onBack=%6 anim=%7",primaryWeapon player,currentWeapon player,weapons player,magazines player,A2EDC_onBack,dayz_onBack,animationState player];
};
