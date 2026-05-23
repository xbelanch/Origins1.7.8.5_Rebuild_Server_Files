A2EDC_fnc_getHandgunWeapon = {
	private["_result","_weapons","_cfg","_type"];

	_result = "";
	_weapons = weapons player;

	{
		_cfg = configFile >> "CfgWeapons" >> _x;
		if (isClass _cfg) then {
			_type = getNumber (_cfg >> "type");
			if (_type == 2) then {
				if (_result == "") then {
					_result = _x;
				};
			};
		};
	} forEach _weapons;

	_result
};

A2EDC_fnc_traceWeaponStateAfterSpawn = {
	private["_phase","_primary","_secondary","_handgun","_current","_weapons","_magazines","_assignedItems","_anim","_unitPos","_inOwnVehicle"];

	_phase = _this select 0;
	_primary = primaryWeapon player;
	_secondary = secondaryWeapon player;
	_handgun = call A2EDC_fnc_getHandgunWeapon;
	_current = currentWeapon player;
	_weapons = weapons player;
	_magazines = magazines player;
	_assignedItems = items player;
	_anim = animationState player;
	_unitPos = unitPos player;
	_inOwnVehicle = (vehicle player == player);

	if (isNil "A2EDC_TRACE_WEAPON_STATE_AFTER_SPAWN") then {
		A2EDC_TRACE_WEAPON_STATE_AFTER_SPAWN = true;
	};

	if (A2EDC_TRACE_WEAPON_STATE_AFTER_SPAWN) then {
		diag_log format [
			"[A2EDC:WEAPON_STATE:POST_SPAWN] phase=%1 uid=%2 charID=%3 weapons=%4 magazines=%5 currentWeapon=%6 primaryWeapon=%7 secondaryWeapon=%8 handgunWeapon=%9 assignedItems=%10 animationState=%11 stance=%12 unitPos=%13 vehicleIsPlayer=%14 alive=%15",
			_phase,
			getPlayerUID player,
			if (isNil "dayz_characterID") then {"<nil>"} else {dayz_characterID},
			_weapons,
			_magazines,
			_current,
			_primary,
			_secondary,
			_handgun,
			_assignedItems,
			_anim,
			"<unavailable-a2>",
			_unitPos,
			_inOwnVehicle,
			alive player
		];
	};
};

A2EDC_fnc_fixWeaponStanceAfterSpawnOnce = {
	private["_phase","_primary","_secondary","_handgun","_selectedSecondary","_current","_weapons","_reason","_blocked"];

	_phase = _this select 0;

	[_phase + "-before"] call A2EDC_fnc_traceWeaponStateAfterSpawn;

	_blocked = false;
	if (!alive player) then {
		_blocked = true;
		diag_log format ["[A2EDC:WEAPON_STATE:FIX] phase=%1 skipped reason=not-alive",_phase];
	};
	if (!_blocked) then {
		if (vehicle player != player) then {
			_blocked = true;
			diag_log format ["[A2EDC:WEAPON_STATE:FIX] phase=%1 skipped reason=in-vehicle",_phase];
		};
	};
	if (!isNil "r_player_unconscious") then {
		if (!_blocked) then {
			if (r_player_unconscious) then {
				_blocked = true;
				diag_log format ["[A2EDC:WEAPON_STATE:FIX] phase=%1 skipped reason=unconscious",_phase];
			};
		};
	};
	if (_blocked) exitWith {};

	_primary = primaryWeapon player;
	_secondary = secondaryWeapon player;
	_handgun = call A2EDC_fnc_getHandgunWeapon;
	_selectedSecondary = _handgun;
	if (_selectedSecondary == "") then {
		_selectedSecondary = _secondary;
	};
	_current = currentWeapon player;
	_weapons = weapons player;
	_reason = "none";

	if (_primary != "") then {
		if ((_current == "") or (!(_current in _weapons))) then {
			player selectWeapon _primary;
			_reason = "selected-primary";
		} else {
			_reason = "primary-current-ok";
		};
	} else {
		if (_selectedSecondary != "") then {
			player switchMove "";
			player selectWeapon _selectedSecondary;
			_reason = "selected-secondary-reset-anim";
		} else {
			player action ["SwitchWeapon", player, player, 100];
			player switchMove "";
			player playMoveNow "AmovPercMstpSnonWnonDnon";
			_reason = "forced-unarmed-idle";
		};
	};

	diag_log format [
		"[A2EDC:WEAPON_STATE:FIX] phase=%1 reason=%2 primary=%3 secondary=%4 handgun=%5 selectedSecondary=%6 currentBefore=%7 weapons=%8",
		_phase,
		_reason,
		_primary,
		_secondary,
		_handgun,
		_selectedSecondary,
		_current,
		_weapons
	];

	[_phase + "-after"] call A2EDC_fnc_traceWeaponStateAfterSpawn;
};

A2EDC_fnc_fixWeaponStanceAfterSpawn = {
	if (isNil "A2EDC_FIX_WEAPON_STANCE_AFTER_SPAWN") then {
		A2EDC_FIX_WEAPON_STANCE_AFTER_SPAWN = true;
	};
	if (!A2EDC_FIX_WEAPON_STANCE_AFTER_SPAWN) exitWith {
		diag_log "[A2EDC:WEAPON_STATE:FIX] skipped reason=config-disabled";
	};

	waitUntil {!isNull player};
	waitUntil {local player};
	waitUntil {alive player};
	waitUntil {!isNil "dayzGearSave"};

	sleep 0.2;
	["initial"] call A2EDC_fnc_fixWeaponStanceAfterSpawnOnce;

	sleep 2;
	["delayed"] call A2EDC_fnc_fixWeaponStanceAfterSpawnOnce;
};
