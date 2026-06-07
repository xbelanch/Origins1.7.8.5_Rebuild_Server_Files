private ["_payload","_player","_uid","_name","_kit","_playerUID","_adminUIDs","_authSource","_isAdmin","_allowedKits","_boxClass","_blueprint","_stage1","_stage2","_allItems","_missing","_fncCargoType","_fncAuditClass","_fncAddCargo","_dir","_pos","_stage1Pos","_stage2Pos","_box1","_box2","_cleanupDelay","_cleanupObjects","_deleted","_kept"];

_payload = _this;

if ((typeName _payload) != "ARRAY") exitWith {
	diag_log "A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=<invalid> name=<invalid> kit=<invalid> reason=payload_not_array";
};

if ((count _payload) < 4) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=<invalid> name=<invalid> kit=<invalid> reason=payload_too_short payloadCount=%1",count _payload];
};

_player = _payload select 0;
_uid = _payload select 1;
_name = _payload select 2;
_kit = _payload select 3;

diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REQUEST uid=%1 name=%2 kit=%3 payload=%4",_uid,_name,_kit,_payload];

if ((typeName _player) != "OBJECT") exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=player_not_object",_uid,_name,_kit];
};

if (isNull _player) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=player_null",_uid,_name,_kit];
};

_playerUID = getPlayerUID _player;
if (_playerUID != _uid) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=uid_mismatch playerUID=%4",_uid,_name,_kit,_playerUID];
};

if (isNil "A2EDC_adminBuildingKitUIDs") then {
	A2EDC_adminBuildingKitUIDs = [
		"76561198024951069"
	];
};

_adminUIDs = [];
_authSource = "none";

if (!isNil "A2EDC_adminBuildingKitUIDs") then {
	if ((typeName A2EDC_adminBuildingKitUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminBuildingKitUIDs;
		_authSource = "A2EDC_adminBuildingKitUIDs";
	};
};

if (!isNil "A2EDC_adminMissionLauncherUIDs") then {
	if ((typeName A2EDC_adminMissionLauncherUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminMissionLauncherUIDs;
		if (_authSource == "none") then {
			_authSource = "A2EDC_adminMissionLauncherUIDs";
		} else {
			_authSource = _authSource + "+A2EDC_adminMissionLauncherUIDs";
		};
	};
};

if (!isNil "A2EDC_adminUIDs") then {
	if ((typeName A2EDC_adminUIDs) == "ARRAY") then {
		_adminUIDs = _adminUIDs + A2EDC_adminUIDs;
		if (_authSource == "none") then {
			_authSource = "A2EDC_adminUIDs";
		} else {
			_authSource = _authSource + "+A2EDC_adminUIDs";
		};
	};
};

if (!isNil "AdminList") then {
	if ((typeName AdminList) == "ARRAY") then {
		_adminUIDs = _adminUIDs + AdminList;
		if (_authSource == "none") then {
			_authSource = "AdminList";
		} else {
			_authSource = _authSource + "+AdminList";
		};
	};
};

_isAdmin = _playerUID in _adminUIDs;
if (!_isAdmin) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=not_admin adminCount=%4 source=%5",_playerUID,_name,_kit,count _adminUIDs,_authSource];
};

_allowedKits = ["house_l1_hero","house_l1_bandit","cleanup_temp"];
if (!(_kit in _allowedKits)) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=not_whitelisted",_playerUID,_name,_kit];
};

if (_kit == "cleanup_temp") exitWith {
	_cleanupObjects = nearestObjects [_player, ["TentStorage","TentStorageR"], 80];
	_deleted = [];
	_kept = [];
	{
		if ((_x getVariable ["A2EDC_adminTempObject",false]) && ((_x getVariable ["A2EDC_adminBuildingKit",""]) != "")) then {
			_deleted set [count _deleted,[typeOf _x,getPosATL _x,_x getVariable ["A2EDC_adminBuildingKit",""],_x getVariable ["A2EDC_adminBuildingKitStage",-1]]];
			deleteVehicle _x;
		} else {
			_kept set [count _kept,[typeOf _x,getPosATL _x,_x getVariable ["A2EDC_adminBuildingKit",""],_x getVariable ["A2EDC_adminTempObject",false]]];
		};
	} forEach _cleanupObjects;
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_CLEANUP uid=%1 name=%2 radius=80 scanned=%3 deleted=%4 kept=%5",_playerUID,_name,count _cleanupObjects,_deleted,_kept];
};

_boxClass = "TentStorage";
_blueprint = if (_kit == "house_l1_hero") then {"ItemBpt_h1"} else {"ItemBpt_b1"};
_stage1 = [
	["ItemCeMix",1],
	[_blueprint,1],
	["ItemRocks",15],
	["PartWoodPile",25],
	["ItemCementBag",2],
	["PartScrap",2]
];
_stage2 = [
	["ItemRocks",25],
	["PartWoodPile",35],
	["ItemCementBag",4],
	["PartScrap",4],
	["ItemBattery",1],
	["ItemPin",1]
];
_allItems = _stage1 + _stage2;

_fncCargoType = {
	private ["_class","_cargoType"];
	_class = _this;
	_cargoType = "missing";
	if (isClass (configFile >> "CfgMagazines" >> _class)) then {
		_cargoType = "magazine";
	};
	if (_cargoType == "missing") then {
		if (isClass (configFile >> "CfgWeapons" >> _class)) then {
			_cargoType = "weapon";
		};
	};
	if (_cargoType == "missing") then {
		if (isClass (configFile >> "CfgVehicles" >> _class)) then {
			if ((getNumber (configFile >> "CfgVehicles" >> _class >> "isBackpack")) == 1) then {
				_cargoType = "backpack";
			} else {
				_cargoType = "vehicle";
			};
		};
	};
	_cargoType
};

_fncAuditClass = {
	private ["_class","_cargoType"];
	_class = _this;
	_cargoType = _class call _fncCargoType;
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_CLASS_AUDIT class=%1 cargoType=%2",_class,_cargoType];
	_cargoType
};

_missing = [];
if (!isClass (configFile >> "CfgVehicles" >> _boxClass)) then {
	_missing set [count _missing,[_boxClass,"box_vehicle_missing"]];
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_MISSING_CLASS class=%1 reason=box_vehicle_missing",_boxClass];
} else {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_CLASS_AUDIT class=%1 cargoType=vehicle",_boxClass];
};

{
	private ["_class","_cargoType"];
	_class = _x select 0;
	_cargoType = _class call _fncAuditClass;
	if (!(_cargoType in ["magazine","weapon","backpack"])) then {
		_missing set [count _missing,[_class,_cargoType]];
		diag_log format ["A2EDC:ADMIN:BUILDING_KIT_MISSING_CLASS class=%1 cargoType=%2",_class,_cargoType];
	};
} forEach _allItems;

if ((count _missing) > 0) exitWith {
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_REFUSED uid=%1 name=%2 kit=%3 reason=missing_class missing=%4",_playerUID,_name,_kit,_missing];
};

_fncAddCargo = {
	private ["_box","_stage","_entry","_class","_qty","_cargoType"];
	_box = _this select 0;
	_stage = _this select 1;
	_entry = _this select 2;
	_class = _entry select 0;
	_qty = _entry select 1;
	_cargoType = _class call _fncCargoType;
	if (_cargoType == "magazine") exitWith {
		_box addMagazineCargoGlobal [_class,_qty];
		diag_log format ["A2EDC:ADMIN:BUILDING_KIT_ADD_ITEM kit=%1 stage=%2 class=%3 qty=%4 cargoType=%5",_kit,_stage,_class,_qty,_cargoType];
	};
	if (_cargoType == "weapon") exitWith {
		_box addWeaponCargoGlobal [_class,_qty];
		diag_log format ["A2EDC:ADMIN:BUILDING_KIT_ADD_ITEM kit=%1 stage=%2 class=%3 qty=%4 cargoType=%5",_kit,_stage,_class,_qty,_cargoType];
	};
	if (_cargoType == "backpack") exitWith {
		_box addBackpackCargoGlobal [_class,_qty];
		diag_log format ["A2EDC:ADMIN:BUILDING_KIT_ADD_ITEM kit=%1 stage=%2 class=%3 qty=%4 cargoType=%5",_kit,_stage,_class,_qty,_cargoType];
	};
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_MISSING_CLASS class=%1 cargoType=%2 reason=unexpected_after_preflight",_class,_cargoType];
};

_dir = getDir _player;
_pos = getPosATL _player;
_stage1Pos = _player modelToWorld [-2,4,0];
_stage2Pos = _player modelToWorld [2,4,0];
_stage1Pos set [2,(_pos select 2)];
_stage2Pos set [2,(_pos select 2)];

_box1 = createVehicle [_boxClass,_stage1Pos,[],0,"CAN_COLLIDE"];
_box1 setDir _dir;
_box1 setPosATL _stage1Pos;
_box1 setVariable ["A2EDC_adminTempObject",true,true];
_box1 setVariable ["A2EDC_adminBuildingKit",_kit,true];
_box1 setVariable ["A2EDC_adminBuildingKitStage",1,true];
_box1 setVariable ["A2EDC_adminBuildingKitOwner",_playerUID,true];
clearWeaponCargoGlobal _box1;
clearMagazineCargoGlobal _box1;
clearBackpackCargoGlobal _box1;
diag_log format ["A2EDC:ADMIN:BUILDING_KIT_BOX_POS uid=%1 name=%2 kit=%3 stage=1 box=%4 object=%5 typeOf=%6 pos=%7 playerPos=%8 distancePlayer=%9 adminTemp=%10 adminKit=%11 adminStage=%12 ignored=false reason=admin_temp_building_kit_container_spawned_near_player",_playerUID,_name,_kit,_box1,_box1,typeOf _box1,getPosATL _box1,_pos,_player distance _box1,_box1 getVariable ["A2EDC_adminTempObject",false],_box1 getVariable ["A2EDC_adminBuildingKit",""],_box1 getVariable ["A2EDC_adminBuildingKitStage",-1]];

_box2 = createVehicle [_boxClass,_stage2Pos,[],0,"CAN_COLLIDE"];
_box2 setDir _dir;
_box2 setPosATL _stage2Pos;
_box2 setVariable ["A2EDC_adminTempObject",true,true];
_box2 setVariable ["A2EDC_adminBuildingKit",_kit,true];
_box2 setVariable ["A2EDC_adminBuildingKitStage",2,true];
_box2 setVariable ["A2EDC_adminBuildingKitOwner",_playerUID,true];
clearWeaponCargoGlobal _box2;
clearMagazineCargoGlobal _box2;
clearBackpackCargoGlobal _box2;
diag_log format ["A2EDC:ADMIN:BUILDING_KIT_BOX_POS uid=%1 name=%2 kit=%3 stage=2 box=%4 object=%5 typeOf=%6 pos=%7 playerPos=%8 distancePlayer=%9 adminTemp=%10 adminKit=%11 adminStage=%12 ignored=false reason=admin_temp_building_kit_container_spawned_near_player",_playerUID,_name,_kit,_box2,_box2,typeOf _box2,getPosATL _box2,_pos,_player distance _box2,_box2 getVariable ["A2EDC_adminTempObject",false],_box2 getVariable ["A2EDC_adminBuildingKit",""],_box2 getVariable ["A2EDC_adminBuildingKitStage",-1]];

diag_log format ["A2EDC:ADMIN:BUILDING_KIT_SPAWN uid=%1 name=%2 kit=%3 boxClass=%4 stage1Pos=%5 stage2Pos=%6 box1=%7 box2=%8",_playerUID,_name,_kit,_boxClass,_stage1Pos,_stage2Pos,_box1,_box2];

{
	[_box1,1,_x] call _fncAddCargo;
} forEach _stage1;

{
	[_box2,2,_x] call _fncAddCargo;
} forEach _stage2;

_cleanupDelay = 7200;
[_box1,_box2,_playerUID,_name,_kit,_cleanupDelay] spawn {
	private ["_box1","_box2","_uid","_name","_kit","_delay"];
	_box1 = _this select 0;
	_box2 = _this select 1;
	_uid = _this select 2;
	_name = _this select 3;
	_kit = _this select 4;
	_delay = _this select 5;
	sleep _delay;
	if (!isNull _box1) then {deleteVehicle _box1;};
	if (!isNull _box2) then {deleteVehicle _box2;};
	diag_log format ["A2EDC:ADMIN:BUILDING_KIT_DONE uid=%1 name=%2 kit=%3 reason=cleanup_deleted delay=%4",_uid,_name,_kit,_delay];
};

diag_log format ["A2EDC:ADMIN:BUILDING_KIT_DONE uid=%1 name=%2 kit=%3 result=spawned stage1Count=%4 stage2Count=%5 cleanupDelay=%6",_playerUID,_name,_kit,count _stage1,count _stage2,_cleanupDelay];
