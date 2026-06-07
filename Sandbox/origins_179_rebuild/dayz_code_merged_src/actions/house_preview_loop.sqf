private["_args","_blueprint","_dbHouseType","_runtimeClass","_redGhost","_greenGhost","_mixer","_confirmAction","_cancelAction","_rotateLeftAction","_rotateRightAction","_hiddenPos","_safeDistance","_angleRef","_rotationOffset","_startTime","_contains","_isPreviewActive","_movementHandle","_validationCode","_validationInterval","_validationIteration","_exitReason","_choice","_redNull","_greenNull","_mixerNull","_playerAlive"];

_args = _this;
_blueprint = _args select 0;
_dbHouseType = _args select 1;
_runtimeClass = _args select 2;
_redGhost = _args select 3;
_greenGhost = _args select 4;
_mixer = _args select 5;
_confirmAction = _args select 6;
_cancelAction = _args select 7;
_rotateLeftAction = _args select 8;
_rotateRightAction = _args select 9;

_contains = {
	private["_needle","_haystack","_needleChars","_haystackChars","_needleCount","_haystackCount","_found","_i","_j","_match"];
	_needle = _this select 0;
	_haystack = _this select 1;
	_needleChars = toArray (toLower _needle);
	_haystackChars = toArray (toLower _haystack);
	_needleCount = count _needleChars;
	_haystackCount = count _haystackChars;
	_found = (_needleCount == 0);
	if (!_found && {_needleCount <= _haystackCount}) then {
		for "_i" from 0 to (_haystackCount - _needleCount) do {
			if (!_found) then {
				_match = true;
				for "_j" from 0 to (_needleCount - 1) do {
					if ((_haystackChars select (_i + _j)) != (_needleChars select _j)) then {_match = false;};
				};
				if (_match) then {_found = true;};
			};
		};
	};
	_found
};

_isPreviewActive = {
	private["_continue","_choice","_redNull","_greenNull"];
	_continue = false;
	if (!isNil "A2EDC_housePreviewContext") then {
		if ((typeName A2EDC_housePreviewContext) == "ARRAY") then {
			if ((count A2EDC_housePreviewContext) > 3) then {
				_continue = A2EDC_housePreviewContext select 3;
			};
		};
	};
	if (!isNil "A2EDC_housePreviewActive") then {
		if (!A2EDC_housePreviewActive) then {_continue = false;};
	};
	_choice = if (isNil "A2EDC_housePreviewChoice") then {-1} else {A2EDC_housePreviewChoice};
	_redNull = isNull (_this select 0);
	_greenNull = isNull (_this select 1);
	_continue && {_choice == -1} && {alive player} && {!(_redNull && {_greenNull})}
};

_hiddenPos = [0,0,-1000];
_safeDistance = 0.5 + (sizeOf _runtimeClass) * 0.5;
if (_safeDistance < 3) then {_safeDistance = 3;};
_rotationOffset = if (isNil "A2EDC_housePreviewRotationOffset") then {0} else {A2EDC_housePreviewRotationOffset};
_angleRef = (round ((getDir player) / 5) * 5 + _rotationOffset) mod 360;
_startTime = time;
_validationInterval = 0.45;
_validationIteration = 0;

A2EDC_housePreviewActive = true;
A2EDC_housePreviewBuildPosition = if (isNil "A2EDC_housePreviewPosition") then {getPosATL player} else {+A2EDC_housePreviewPosition};
A2EDC_housePreviewDirection = if (isNil "A2EDC_housePreviewDirection") then {_angleRef} else {A2EDC_housePreviewDirection};
A2EDC_housePreviewValid = if (isNil "A2EDC_housePreviewValid") then {true} else {A2EDC_housePreviewValid};
A2EDC_housePreviewInvalidReason = if (isNil "A2EDC_housePreviewInvalidReason") then {"valid"} else {A2EDC_housePreviewInvalidReason};
A2EDC_housePreviewReason = A2EDC_housePreviewInvalidReason;
A2EDC_housePreviewValidationRunning = false;
A2EDC_housePreviewLastColor = if (A2EDC_housePreviewValid) then {"green"} else {"red"};
A2EDC_housePreviewLastColorReason = A2EDC_housePreviewInvalidReason;
A2EDC_housePreviewContext = [_redGhost,_greenGhost,_angleRef,true,_mixer,_blueprint,_dbHouseType,_runtimeClass,_safeDistance,_rotationOffset];

diag_log format ["A2EDC:HOUSE_PREVIEW_LOOP_ENTER blueprint=%1 dbHouseType=%2 runtimeClass=%3 redGhost=%4 greenGhost=%5 mixer=%6 context=%7 safeDistance=%8 initialBuildPosition=%9 initialDirection=%10 playerPos=%11 playerDir=%12 architecture=movement_validation_decoupled validationInterval=%13",_blueprint,_dbHouseType,_runtimeClass,_redGhost,_greenGhost,_mixer,A2EDC_housePreviewContext,_safeDistance,A2EDC_housePreviewBuildPosition,A2EDC_housePreviewDirection,getPosATL player,getDir player,_validationInterval];
diag_log format ["A2EDC:HOUSE_PREVIEW_COLOR_SET blueprint=%1 color=%2 valid=%3 reason=%4 redGhost=%5 greenGhost=%6 activeGhost=%7 inactiveGhostPosition=%8 source=initial_cached",_blueprint,A2EDC_housePreviewLastColor,A2EDC_housePreviewValid,A2EDC_housePreviewInvalidReason,_redGhost,_greenGhost,if (A2EDC_housePreviewValid) then {_greenGhost} else {_redGhost},_hiddenPos];

_movementHandle = [_redGhost,_greenGhost,_hiddenPos,_safeDistance,_isPreviewActive] spawn {
	private["_redGhost","_greenGhost","_hiddenPos","_safeDistance","_isPreviewActive","_rotationOffset","_playerPos","_playerDir","_angleRef","_newDir","_tmp","_projectedPos","_previousBuildPos","_previousDir","_modelDelta","_dirChanged","_newBuildPos","_valid","_reason","_redNull","_greenNull"];
	_redGhost = _this select 0;
	_greenGhost = _this select 1;
	_hiddenPos = _this select 2;
	_safeDistance = _this select 3;
	_isPreviewActive = _this select 4;

	while {[_redGhost,_greenGhost] call _isPreviewActive} do {
		_redNull = isNull _redGhost;
		_greenNull = isNull _greenGhost;
		_rotationOffset = if (isNil "A2EDC_housePreviewRotationOffset") then {0} else {A2EDC_housePreviewRotationOffset};
		_playerPos = getPosATL player;
		_playerDir = getDir player;
		_angleRef = (round (_playerDir / 5) * 5 + _rotationOffset) mod 360;
		_newDir = _angleRef;
		_tmp = player modelToWorld [0,_safeDistance,0];
		_tmp set [2,0];
		_projectedPos = [
			(_playerPos select 0) + ((sin _playerDir) * _safeDistance),
			(_playerPos select 1) + ((cos _playerDir) * _safeDistance),
			0
		];
		_previousBuildPos = if (isNil "A2EDC_housePreviewBuildPosition") then {+_tmp} else {+A2EDC_housePreviewBuildPosition};
		if ((typeName _previousBuildPos) != "ARRAY") then {_previousBuildPos = +_tmp;};
		if ((count _previousBuildPos) < 2) then {_previousBuildPos = +_tmp;};
		_previousDir = if (isNil "A2EDC_housePreviewDirection") then {_newDir} else {A2EDC_housePreviewDirection};
		_modelDelta = _tmp distance _previousBuildPos;
		_dirChanged = abs(_playerDir - _previousDir);
		if (_dirChanged > 180) then {_dirChanged = 360 - _dirChanged;};
		_newBuildPos = +_tmp;
		if (_modelDelta <= 0.001 && {_dirChanged > 0.5}) then {_newBuildPos = +_projectedPos;};

		A2EDC_housePreviewBuildPosition = +_newBuildPos;
		A2EDC_housePreviewPosition = +_newBuildPos;
		A2EDC_housePreviewDirection = _newDir;
		if (!isNil "A2EDC_housePreviewContext") then {
			if ((typeName A2EDC_housePreviewContext) == "ARRAY") then {
				if ((count A2EDC_housePreviewContext) > 9) then {
					A2EDC_housePreviewContext set [2,_newDir];
					A2EDC_housePreviewContext set [3,true];
					A2EDC_housePreviewContext set [8,_safeDistance];
					A2EDC_housePreviewContext set [9,_rotationOffset];
				};
			};
		};

		_valid = if (isNil "A2EDC_housePreviewValid") then {true} else {A2EDC_housePreviewValid};
		_reason = if (isNil "A2EDC_housePreviewInvalidReason") then {"valid"} else {A2EDC_housePreviewInvalidReason};
		A2EDC_housePreviewReason = _reason;

		if (!_redNull) then {_redGhost setDir _newDir;};
		if (!_greenNull) then {_greenGhost setDir _newDir;};
		if (_valid) then {
			if (!_redNull) then {_redGhost setPosATL _hiddenPos;};
			if (!_greenNull) then {_greenGhost setPosATL _newBuildPos;};
		} else {
			if (!_greenNull) then {_greenGhost setPosATL _hiddenPos;};
			if (!_redNull) then {_redGhost setPosATL _newBuildPos;};
		};
		uiSleep 0.01;
	};
};
A2EDC_housePreviewMovementHandle = _movementHandle;

_validationCode = {
	private["_args","_iteration","_blueprint","_runtimeClass","_mixer","_redGhost","_greenGhost","_hiddenPos","_contains","_start","_pos","_dir","_valid","_reason","_mixerNull","_mixerPlayerDistance","_mixerBuildDistance","_nearbyHouses","_nearbyTents","_realTents","_ignoredAdminTempTents","_cityObjects","_cityBlockers","_natureObjects","_nearbyTrees","_nearbyRocks","_type","_model","_combined","_isLand","_isUtility","_isCoastal","_needle","_containsResult","_objectText","_elapsed","_previousValid","_previousReason","_color","_previousColor","_active","_choice"];
	_args = _this;
	_iteration = _args select 0;
	_blueprint = _args select 1;
	_runtimeClass = _args select 2;
	_mixer = _args select 3;
	_redGhost = _args select 4;
	_greenGhost = _args select 5;
	_hiddenPos = _args select 6;
	_contains = _args select 7;

	A2EDC_housePreviewValidationRunning = true;
	_start = time;
	_pos = if (isNil "A2EDC_housePreviewBuildPosition") then {if (isNil "A2EDC_housePreviewPosition") then {getPosATL player} else {+A2EDC_housePreviewPosition}} else {+A2EDC_housePreviewBuildPosition};
	_dir = if (isNil "A2EDC_housePreviewDirection") then {getDir player} else {A2EDC_housePreviewDirection};
	_valid = true;
	_reason = "valid";
	_mixerNull = isNull _mixer;
	_mixerPlayerDistance = if (_mixerNull) then {9999} else {player distance _mixer};
	_mixerBuildDistance = if (_mixerNull) then {9999} else {_pos distance _mixer};
	_nearbyHouses = [];
	_nearbyTents = [];
	_realTents = [];
	_ignoredAdminTempTents = 0;
	_cityObjects = [];
	_cityBlockers = [];
	_natureObjects = [];
	_nearbyTrees = 0;
	_nearbyRocks = 0;

	if (_mixerNull) then {_valid = false; _reason = "cement_mixer_missing";};
	if (_valid && {_mixerPlayerDistance > 15}) then {_valid = false; _reason = "cement_mixer_too_far";};
	if (_valid && {_mixerBuildDistance > 15}) then {_valid = false; _reason = "cement_mixer_too_far";};
	if (_valid && {player distance _pos > 20}) then {_valid = false; _reason = "confirmed_position_too_far_from_player";};
	if (_valid && {surfaceIsWater _pos}) then {_valid = false; _reason = "water";};
	if (_valid && {isOnRoad _pos}) then {_valid = false; _reason = "road";};

	if (_valid) then {
		_nearbyHouses = nearestObjects [_pos,["wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"],15];
		if ((count _nearbyHouses) > 0) then {_valid = false; _reason = "confirmed_position_house_within_15m";};
	};
	if (_valid) then {
		_nearbyTents = nearestObjects [_pos,["TentStorage","TentStorageR"],15];
		{
			if (!((_x getVariable ["A2EDC_adminTempObject",false]) && {(_x getVariable ["A2EDC_adminBuildingKit",""]) != ""})) then {
				_realTents set [count _realTents,_x];
			};
		} forEach _nearbyTents;
		_ignoredAdminTempTents = (count _nearbyTents) - (count _realTents);
		if ((count _realTents) > 0) then {_valid = false; _reason = "confirmed_position_storage_or_tent_within_15m";};
	};
	if (_valid) then {
		_cityObjects = nearestObjects [_pos,["House"],150];
		{
			_type = typeOf _x;
			_model = getText (configFile >> "CfgVehicles" >> _type >> "model");
			_combined = toLower (_type + " " + _model);
			_isLand = ["land_",_type] call _contains;
			_isUtility = (_type in ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor","Land_majak","Land_majak_podesta","Land_majak2","small_bunker"]);
			if (!_isUtility) then {
				{
					_needle = _x;
					_containsResult = [_needle,_combined] call _contains;
					if (_containsResult) then {_isUtility = true;};
				} forEach ["land_radio_box","radio_box","sloup","telek","timbers","deerstand","rail_zavora","rail_semafor","majak","small_bunker"];
			};
			_isCoastal = false;
			{
				_needle = _x;
				_containsResult = [_needle,_combined] call _contains;
				if (_containsResult) then {_isCoastal = true;};
			} forEach ["land_nav_boathouse_piert","nav_boathouse_pier","nav_boathouse_piert","boathouse_pier"];
			if (_isLand && {!_isUtility} && {!_isCoastal}) then {_cityBlockers set [count _cityBlockers,_x];};
		} forEach _cityObjects;
		if ((count _cityBlockers) > 0) then {_valid = false; _reason = "confirmed_position_city_house_within_150m";};
	};
	if (_valid) then {
		_natureObjects = nearestObjects [_pos,[],15];
		{
			_objectText = str(_x);
			if (["t_",_objectText] call _contains) then {
				_nearbyTrees = _nearbyTrees + 1;
				_valid = false;
				_reason = "confirmed_position_tree_or_rock";
			};
			if (["r2_",_objectText] call _contains) then {
				_nearbyRocks = _nearbyRocks + 1;
				_valid = false;
				_reason = "confirmed_position_tree_or_rock";
			};
		} forEach _natureObjects;
	};

	_elapsed = time - _start;
	_active = if (isNil "A2EDC_housePreviewActive") then {false} else {A2EDC_housePreviewActive};
	_choice = if (isNil "A2EDC_housePreviewChoice") then {-1} else {A2EDC_housePreviewChoice};
	if (_active && {_choice == -1}) then {
		_previousValid = if (isNil "A2EDC_housePreviewValid") then {true} else {A2EDC_housePreviewValid};
		_previousReason = if (isNil "A2EDC_housePreviewInvalidReason") then {"valid"} else {A2EDC_housePreviewInvalidReason};
		A2EDC_housePreviewValid = _valid;
		A2EDC_housePreviewInvalidReason = _reason;
		A2EDC_housePreviewReason = _reason;
		_color = if (_valid) then {"green"} else {"red"};
		_previousColor = if (_previousValid) then {"green"} else {"red"};
		diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDATE_RUN iteration=%1 elapsed=%2 valid=%3 reason=%4 position=%5 direction=%6 nearbyTrees=%7 nearbyRocks=%8 nearbyHouses=%9 nearbyTents=%10 realTents=%11 ignoredAdminTempTents=%12 cityObjects=%13 cityBlockers=%14 natureObjects=%15 mixerDistance=%16 mixerBuildDistance=%17",_iteration,_elapsed,_valid,_reason,_pos,_dir,_nearbyTrees,_nearbyRocks,count _nearbyHouses,count _nearbyTents,count _realTents,_ignoredAdminTempTents,count _cityObjects,count _cityBlockers,count _natureObjects,_mixerPlayerDistance,_mixerBuildDistance];
		if (_color != _previousColor || {_reason != _previousReason}) then {
			A2EDC_housePreviewLastColor = _color;
			A2EDC_housePreviewLastColorReason = _reason;
			diag_log format ["A2EDC:HOUSE_PREVIEW_COLOR_SET blueprint=%1 color=%2 valid=%3 reason=%4 redGhost=%5 greenGhost=%6 activeGhost=%7 inactiveGhostPosition=%8 source=validation",_blueprint,_color,_valid,_reason,_redGhost,_greenGhost,if (_valid) then {_greenGhost} else {_redGhost},_hiddenPos];
		};
	} else {
		diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDATE_DISCARD iteration=%1 elapsed=%2 reason=preview_no_longer_active choice=%3 active=%4",_iteration,_elapsed,_choice,_active];
	};
	A2EDC_housePreviewValidationRunning = false;
};

while {[_redGhost,_greenGhost] call _isPreviewActive} do {
	_validationIteration = _validationIteration + 1;
	if ((isNil "A2EDC_housePreviewValidationRunning") || {!A2EDC_housePreviewValidationRunning}) then {
		[_validationIteration,_blueprint,_runtimeClass,_mixer,_redGhost,_greenGhost,_hiddenPos,_contains] spawn _validationCode;
	} else {
		diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDATE_THROTTLE iteration=%1 skipped=true reason=validation_running",_validationIteration];
	};
	uiSleep _validationInterval;
};

_choice = if (isNil "A2EDC_housePreviewChoice") then {-1} else {A2EDC_housePreviewChoice};
_redNull = isNull _redGhost;
_greenNull = isNull _greenGhost;
_mixerNull = isNull _mixer;
_playerAlive = alive player;
_exitReason = "unknown";
if (!isNil "A2EDC_housePreviewActive") then {if (!A2EDC_housePreviewActive) then {_exitReason = "active_false";};};
if (_choice != -1) then {_exitReason = "choice_set";};
if (!_playerAlive) then {_exitReason = "player_not_alive";};
if (_redNull && {_greenNull}) then {_exitReason = "ghosts_null";};
if (!isNil "A2EDC_housePreviewContext") then {
	if ((typeName A2EDC_housePreviewContext) == "ARRAY") then {
		if ((count A2EDC_housePreviewContext) > 3) then {
			if (!(A2EDC_housePreviewContext select 3)) then {_exitReason = "context_continue_false";};
		};
	};
};

diag_log format ["A2EDC:HOUSE_PREVIEW_LOOP_EXIT reason=%1 choice=%2 active=%3 redNull=%4 greenNull=%5 mixerNull=%6 playerAlive=%7 elapsed=%8 finalPosition=%9 finalDirection=%10 valid=%11 invalidReason=%12 validationRunning=%13",_exitReason,_choice,if (isNil "A2EDC_housePreviewActive") then {"<nil>"} else {A2EDC_housePreviewActive},_redNull,_greenNull,_mixerNull,_playerAlive,time - _startTime,if (isNil "A2EDC_housePreviewBuildPosition") then {[]} else {A2EDC_housePreviewBuildPosition},if (isNil "A2EDC_housePreviewDirection") then {-1} else {A2EDC_housePreviewDirection},if (isNil "A2EDC_housePreviewValid") then {false} else {A2EDC_housePreviewValid},if (isNil "A2EDC_housePreviewInvalidReason") then {"<nil>"} else {A2EDC_housePreviewInvalidReason},if (isNil "A2EDC_housePreviewValidationRunning") then {false} else {A2EDC_housePreviewValidationRunning}];
