private ["_object","_type","_objectID","_uid","_lastUpdate","_needUpdate","_object_position","_object_inventory","_object_damage","_isNotOk","_allowed","_naObnovku","_traceClass","_inputObject","_objectIDValue","_uidValue","_objectIDType","_uidType","_guardReason","_missingObjectID"];

_inputObject = _this select 0;
_object = 	_inputObject;
_type = 	toLower(_this select 1);
if (_object isKindOf "Man") then {
	if ((vehicle _object) != _object) then {
		diag_log format ["[A2EDC:OBJECT_GUARD] normalized Man update to vehicle man=%1 vehicle=%2 operation=%3 vehicleClass=%4", _object, vehicle _object, _type, typeOf (vehicle _object)];
		_object = vehicle _object;
	};
};
_parachuteWest = typeOf _object == "ParachuteWest";
_isNotOk = false;
_allowed =["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage","object_x"];
_objectID =	_object getVariable ["ObjectID","0"];
_uid = 		_object getVariable ["ObjectUID","0"];
_missingObjectID = false;
if (isNil "_objectID") then {
	_objectID = "<nil>";
	_missingObjectID = true;
};
if (isNil "_uid") then {
	_uid = "0";
};
if ((typeName _objectID == "STRING") && {_objectID == ""}) then {
	_missingObjectID = true;
};
if ((typeName _uid == "STRING") && {_uid == ""}) then {
	_uid = "0";
};
if (!(isNil "A2EDC_TRACE")) then {
if (A2EDC_TRACE) then {
	_traceClass = typeOf _object;
	["OBJECT", format ["class=%1 operation=%2 objectID=%3 uid=%4", _traceClass, _type, _objectID, _uid]] call A2EDC_fnc_trace;
	if (!(isNil "A2EDC_fnc_traceObjectState")) then {
		["OBJECT", format ["UPDATE begin operation=%1", _type], _object] call A2EDC_fnc_traceObjectState;
	};
	};
};

diag_log format ["_object=%1, _type=%2, _objectID=%3, _uid=%4",_object,_type,_objectID,_uid];

if (_object isKindOf "Man") exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] refused object update for Man object=%1 type=%2 class=%3 objectID=%4 uid=%5 pos=%6", _object, _type, typeOf _object, _objectID, _uid, getPosATL _object];
	if (!(isNil "A2EDC_fnc_traceObjectState")) then {
		["OBJECT_GUARD", format ["refused Man object update operation=%1", _type], _object] call A2EDC_fnc_traceObjectState;
	};
};

if (_object getVariable ["A2EDC_WAI_patrolVehicle", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=wai_patrol_transient_vehicle class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
	diag_log format ["A2EDC:WAI:PATROL_DAMAGE class=%1 event=guard_skip_update damage=%2 objectID=%3 uid=%4",typeOf _object,damage _object,_objectID,_uid];
};

if (_object getVariable ["A2EDC_WAI_transientVehicle", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=wai_transient_vehicle class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
};

if (_object getVariable ["A2EDC_WAI_transientLoot", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=wai_transient_loot class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
};

if (_object getVariable ["A2EDC_DZMS_transientVehicle", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=dzms_transient_vehicle class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
};

if (_object getVariable ["A2EDC_WAI_publishPendingObjectID", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=wai_publish_pending_objectid class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
};

if (_object getVariable ["A2EDC_WAI_publishFailedObjectID", false]) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=wai_publish_missing_objectid class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
};

if (!_parachuteWest && {_objectID == "1"} && {_uid == "0"}) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=placeholder_objectid class=%1 objectID=%2 uid=%3 operation=%4 object=%5 inputObject=%6", typeOf _object, _objectID, _uid, _type, _object, _inputObject];
};

if ((!_parachuteWest) && {_missingObjectID}) exitWith {
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=missing_objectid class=%1 objectID=%2 uid=%3 operation=%4 object=%5", typeOf _object, _objectID, _uid, _type, _object];
	if (!(isNil "A2EDC_fnc_traceObjectState")) then {
		["OBJECT_GUARD", format ["reason=missing_objectid operation=%1 objectID=%2 uid=%3", _type, _objectID, _uid], _object] call A2EDC_fnc_traceObjectState;
	};
};

_objectIDType = typeName _objectID;
_uidType = typeName _uid;
_objectIDValue = 0;
_uidValue = 0;

if (_objectIDType == "STRING") then {
	_objectIDValue = parseNumber _objectID;
} else {
	if (_objectIDType == "SCALAR") then {
		_objectIDValue = _objectID;
		_objectID = str(_objectID);
	} else {
		diag_log format ["[A2EDC:OBJECT_GUARD] reason=invalid_objectid_type class=%1 objectID=%2 objectIDType=%3 uid=%4 uidType=%5 operation=%6", typeOf _object, _objectID, _objectIDType, _uid, _uidType, _type];
	};
};

if (_uidType == "STRING") then {
	_uidValue = parseNumber _uid;
} else {
	if (_uidType == "SCALAR") then {
		_uidValue = _uid;
		_uid = str(_uid);
	} else {
		diag_log format ["[A2EDC:OBJECT_GUARD] reason=invalid_objectuid_type class=%1 objectID=%2 objectIDType=%3 uid=%4 uidType=%5 operation=%6", typeOf _object, _objectID, _objectIDType, _uid, _uidType, _type];
	};
};

if ((!_parachuteWest) && {_objectIDValue <= 0} && {_uidValue <= 0}) exitWith {
	_guardReason = "invalid_object_identity";
	if (_object isKindOf "AllVehicles") then {
		_guardReason = "temporary_invalid_identity";
	};
	_object_position = getPosATL _object;
	diag_log format ["[A2EDC:OBJECT_GUARD] reason=%1 class=%2 objectID=%3 uid=%4 operation=%5 object=%6 pos=%7", _guardReason, typeOf _object, _objectID, _uid, _type, _object, _object_position];
	if (!(isNil "A2EDC_fnc_traceObjectState")) then {
		["OBJECT_GUARD", format ["reason=%1 operation=%2 objectID=%3 uid=%4", _guardReason, _type, _objectID, _uid], _object] call A2EDC_fnc_traceObjectState;
	};
};

if (!_parachuteWest) then {
if (_objectID == "0" && _uid == "0") then
{
_object_position = getPosATL _object;
diag_log(format["Temporary object %1 with invalid ID at pos [%2,%3,%4]",
typeOf _object,
_object_position select 0,
_object_position select 1, 
_object_position select 2]);
_isNotOk = false;
};
};

if (_isNotOk) exitWith { deleteVehicle _object; };

_lastUpdate = _object getVariable ["lastUpdate",time];
_needUpdate = _object in needUpdate_objects;
_naObnovku = true;
_typeofObj = typeOf _object;
if (_typeofObj in ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage","object_x"]) then {
_naObnovku = _object getVariable["CanBeUpdated",false];
if (typeName _naObnovku != "BOOL") then { _naObnovku = false; };
} else {
_naObnovku = true;
}; 


_object_position = {
private["_position","_worldspace","_fuel","_key"];
_position = getPosATL _object;
_worldspace = [
round(direction _object),
_position
];
_fuel = 0;
if (_object isKindOf "AllVehicles") then {

_fuel = fuel _object;

	_key = format["CHILD:305:%1:%2:%3:",_objectID,_worldspace,_fuel];
	if (!(isNil "A2EDC_TRACE")) then {
	if (A2EDC_TRACE) then {
		["OBJECT", format ["position write class=%1 objectID=%2 worldspace=%3 fuel=%4", typeOf _object, _objectID, _worldspace, _fuel]] call A2EDC_fnc_trace;
	};
	};
	
	_key call server_hiveWrite;
	};
	};

_object_inventory = {
if (_naObnovku) then {
private["_inventory","_previous","_key"];
_inventory = [
getWeaponCargo _object,
getMagazineCargo _object,
getBackpackCargo _object
];
_previous = str(_object getVariable["lastInventory",[]]);

if (str(_inventory) != _previous) then {
_object setVariable["lastInventory",_inventory];

if (_objectID == "0") then {
_key = format["CHILD:309:%1:%2:",_uid,_inventory];
} else {
_key = format["CHILD:303:%1:%2:",_objectID,_inventory];
};

_key call server_hiveWrite;
};
} else {
diag_log format ["_naObnovku = %1, _typeofObj=%2",_naObnovku,_typeofObj];
};
};

_object_damage = {
private["_hitpoints","_array","_hit","_selection","_key","_damage","_cfg","_tc","_mti","_mt","_nameClass1","_st"];

if (!(typeOf _object in _allowed)) then {
_hitpoints = _object call vehicle_getHitpoints;
_damage = damage _object;

_array = [];
{
_hit = [_object,_x] call object_getHit;
_selection = getText (configFile >> "CfgVehicles" >> (typeOf _object) >> "HitPoints" >> _x >> "name");
if (_hit > 0) then {_array set [count _array,[_selection,_hit]]};
_object setHit ["_selection", _hit]
} forEach _hitpoints;


_cfg = configFile >> "CfgVehicles" >> (typeof _object) >> "AnimationSources";
_tc = count _cfg;
for "_mti" from 0 to _tc-1 do {
_mt = (_cfg select _mti);
_nameClass1 = configName(_mt);
_st = getText(_mt >> "source");
if (_st in ["front_plow","wheel_guards","window_guards","windshield_guard"]) then {
_hit = _object getVariable [_st,1];
_object animate [_st,_hit];
_array set [count _array,[_st,_hit]];

};
};


	_key = format["CHILD:306:%1:%2:%3:",_objectID,_array,_damage];
	if (!(isNil "A2EDC_TRACE")) then {
	if (A2EDC_TRACE) then {
		["OBJECT", format ["damage write class=%1 objectID=%2 hits=%3 damage=%4", typeOf _object, _objectID, count _array, _damage]] call A2EDC_fnc_trace;
	};
	};
	
	_key call server_hiveWrite;
	_object setVariable ["needUpdate",false,true];
};
};



_object setVariable ["lastUpdate",time,true];
switch (_type) do {
case "all": {
call _object_position;
call _object_inventory;
call _object_damage;
};
case "position": {
call _object_position;
};
case "gear": {
call _object_inventory;
};
case "damage": {
if ( (time - _lastUpdate) > 5 && !_needUpdate ) then {
call _object_damage;
} else {
if ( !_needUpdate ) then {
needUpdate_objects set [count needUpdate_objects, _object];
};
};
};
case "repair": {
call _object_damage;
};
};
