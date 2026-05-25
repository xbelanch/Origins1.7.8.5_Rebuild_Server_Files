private ["_object","_worldspace","_location","_dir","_class","_uid","_dam","_hitpoints","_selection","_array","_damage","_fuel","_key","_totaldam","_spawnDMG","_characterID"];
//[_veh,[_dir,_location],"V3S_Civ",true]
_object = 		_this select 0;
_worldspace = 	_this select 1;
_class = 		_this select 2;
_spawnDMG =		_this select 3;
_characterID =  _this select 4;

_fuel = 1;
_damage = 0;
_array = [];

if (isNil "generate_new_damage") then {
	generate_new_damage = {
		0
	};
	if (isNil "A2EDC_WAI_PUBLISH_DAMAGE_FALLBACK_LOGGED") then {
		A2EDC_WAI_PUBLISH_DAMAGE_FALLBACK_LOGGED = true;
		diag_log "A2EDC:WAI:PUBLISH:DAMAGE_FALLBACK generate_new_damage_missing=true";
	};
};

diag_log ("PUBLISH: Attempt " + str(_object));
if (!(isNil "A2EDC_fnc_traceObjectState")) then {
	["WAI:PUBLISH", "start", _object] call A2EDC_fnc_traceObjectState;
};
_dir = 		_worldspace select 0;
_location = _worldspace select 1;

//Generate UID test using time
// _uid = str( round (dateToNumber date)) + str(round time);
_uid = _worldspace call dayz_objectUID2;
//_uid = format["%1%2",(round time),_uid];
_object setVariable ["A2EDC_WAI_publishPendingObjectID", true, true];
_object setVariable ["ObjectUID", _uid, true];
PVDZE_serverObjectMonitor = PVDZE_serverObjectMonitor - [_object];
if (!(isNil "dayz_serverObjectMonitor")) then {
	dayz_serverObjectMonitor = dayz_serverObjectMonitor - [_object];
};

if (_spawnDMG) then { 
	_fuel = 0;
	if (getNumber(configFile >> "CfgVehicles" >> _class >> "isBicycle") != 1) then {

		// Create randomly damaged parts
	
		_totaldam = 0;
		_hitpoints = _object call vehicle_getHitpoints;
		{
			// generate damage on all parts
			_dam = call generate_new_damage;

			_selection = getText(configFile >> "cfgVehicles" >> _class >> "HitPoints" >> _x >> "name");
			
			if (_dam > 0) then {
				_array set [count _array,[_selection,_dam]];
				_totaldam = _totaldam + _dam;
			};
		} forEach _hitpoints;
		

		// just set low base dmg - may change later
		_damage = 0;
		_fuel = wai_mission_fuel;
	};
};

// TODO: check if uid already exists and if so increment by 1 and check again as soon as we find nothing continue.

//Send request
_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",dayZ_instance, _class, _damage , _characterID, _worldspace, [], _array, _fuel,_uid];
diag_log ("HIVE: WRITE: "+ str(_key)); 
if (!(isNil "A2EDC_TRACE")) then {
if (A2EDC_TRACE) then {
	["WAI:PUBLISH", format ["hive write class=%1 uid=%2 characterID=%3 worldspace=%4 damage=%5 hitCount=%6 fuel=%7", _class, _uid, _characterID, _worldspace, _damage, count _array, _fuel]] call A2EDC_fnc_trace;
};
};
_key call server_hiveWrite;

// Switched to spawn so we can wait a bit for the ID
[_object,_uid,_fuel,_damage,_array,_characterID,_class] spawn {
   private["_object","_uid","_fuel","_damage","_array","_characterID","_done","_retry","_maxRetries","_key","_result","_outcome","_oid","_selection","_dam","_class","_data","_status","_temp","_attempts","_compileFailed"];

   _object = _this select 0;
   _uid = _this select 1;
   _fuel = _this select 2;
   _damage = _this select 3;
   _array = _this select 4;
   _characterID = _this select 5;
   _class = _this select 6;

   _done = false;
	_retry = 0;
	_maxRetries = 5;
	_result = ["FAIL","NOT_ATTEMPTED"];
	while {_retry < _maxRetries} do {
		
		sleep 1;
		// GET DB ID
		_key = format["CHILD:388:%1:",_uid];
		diag_log ("HIVE: WRITE: "+ str(_key));
		_result = _key call server_hiveReadWrite;
		_outcome = if ((typeName _result) == "ARRAY" && {(count _result) > 0}) then {_result select 0} else {"FAIL"};
			if (_outcome == "PASS") then {
				_oid = _result select 1;
				if ((typeName _oid) != "STRING") then {_oid = str(_oid);};
				if (_oid != "0") then {
					_object setVariable ["ObjectID", _oid, true];
					_object setVariable ["ObjectUID", _uid, true];
					diag_log("CUSTOM: Selected " + str(_oid));
					if (!(isNil "A2EDC_fnc_traceObjectState")) then {
						["WAI:PUBLISH", format ["db id selected uid=%1 oid=%2", _uid, _oid], _object] call A2EDC_fnc_traceObjectState;
					};
					_done = true;
				};
				_retry = _maxRetries;

		} else {
			diag_log("CUSTOM: trying again to get id for: " + str(_uid));
			_done = false;
			_retry = _retry + 1;
		};
	};
	if (!_done) then {
		_key = format["CHILD:999:SELECT `ObjectID` FROM `object_data` WHERE `ObjectUID` = '?' ORDER BY `ObjectID` DESC LIMIT 1:[""%1""]:", _uid];
		diag_log format ["A2EDC:WAI:PUBLISH:OID_SQL_LOOKUP class=%1 uid=%2 key=%3",_class,_uid,_key];
		_data = "HiveEXT" callExtension _key;
		_result = ["FAIL","EMPTY_RESPONSE"];
		if ((typeName _data) == "STRING" && {(count (toArray _data)) > 0}) then {
			_compileFailed = isNil {_result = call compile format ["%1",_data];};
			if (_compileFailed) then {_result = ["FAIL","COMPILE_ERROR"];};
		};
		_status = if ((typeName _result) == "ARRAY" && {(count _result) > 0}) then {_result select 0} else {"FAIL"};
		if (_status == "CustomStreamStart") then {
			_temp = if ((count _result) > 1) then {_result select 1} else {0};
			if (_temp > 0) then {
				_data = "HiveEXT" callExtension _key;
				_result = ["FAIL","EMPTY_RESPONSE"];
				if ((typeName _data) == "STRING" && {(count (toArray _data)) > 0}) then {
					_compileFailed = isNil {_result = call compile format ["%1",_data];};
					if (_compileFailed) then {_result = ["FAIL","COMPILE_ERROR"];};
				};
				_status = if ((typeName _result) == "ARRAY" && {(count _result) > 0}) then {_result select 0} else {"FAIL"};
			};
		};
		if (_status == "PASS") then {
			_oid = if ((count _result) > 1) then {_result select 1} else {"0"};
			if ((typeName _oid) == "ARRAY") then {if ((count _oid) > 0) then {_oid = _oid select 0;} else {_oid = "0";};};
			if ((typeName _oid) == "ARRAY") then {if ((count _oid) > 0) then {_oid = _oid select 0;} else {_oid = "0";};};
			if ((typeName _oid) != "STRING") then {_oid = str(_oid);};
			if (_oid != "0") then {
				_object setVariable ["ObjectID", _oid, true];
				_object setVariable ["ObjectUID", _uid, true];
				diag_log format ["A2EDC:WAI:PUBLISH:OID_SQL_OK class=%1 uid=%2 oid=%3",_class,_uid,_oid];
				_done = true;
			};
		};
	};
	if(!_done) exitWith {
		_attempts = _maxRetries;
		diag_log format ["A2EDC:WAI:PUBLISH:OID_FAIL class=%1 uid=%2 attempts=%3 result=%4",_class,_uid,_attempts,_result];
		_object setVariable ["A2EDC_WAI_publishPendingObjectID", false, true];
		_object setVariable ["A2EDC_WAI_publishFailedObjectID", true, true];
		_object setVariable ["ObjectID", "0", true];
		_object setVariable ["ObjectUID", _uid, true];
		PVDZE_serverObjectMonitor = PVDZE_serverObjectMonitor - [_object];
		if (!(isNil "dayz_serverObjectMonitor")) then {
			dayz_serverObjectMonitor = dayz_serverObjectMonitor - [_object];
		};
	};

	_object setVariable ["A2EDC_WAI_publishPendingObjectID", false, true];
	_object setVariable ["A2EDC_WAI_publishFailedObjectID", false, true];
	_object setVariable ["lastUpdate",time];
	_object setVariable ["CharacterID", _characterID, true];
	_object setDamage _damage;

	// Set Hits after ObjectID is set
	{
		_selection = _x select 0;
		_dam = _x select 1;
		if (_selection in dayZ_explosiveParts and _dam > 0.8) then {_dam = 0.8};
		[_object,_selection,_dam] call object_setFixServer;
	} forEach _array;
	
	_object setFuel _fuel;
	
		_object setvelocity [0,0,1];

			_object call fnc_veh_ResetEH;
			PVDZE_serverObjectMonitor set [count PVDZE_serverObjectMonitor,_object];
			if (!(isNil "A2EDC_fnc_traceObjectState")) then {
				["WAI:PUBLISH", "added PVDZE_serverObjectMonitor", _object] call A2EDC_fnc_traceObjectState;
			};

			// testing - should make sure everyone has eventhandlers for vehicles was unused...
		PVDZE_veh_Init = _object;
		publicVariable "PVDZE_veh_Init";
		if (!(isNil "A2EDC_fnc_traceObjectState")) then {
			["WAI:PUBLISH", format ["end publicVariable PVDZE_veh_Init uid=%1", _uid], _object] call A2EDC_fnc_traceObjectState;
		};

		diag_log ("PUBLISH: Created " + (_class) + " with ID " + str(_uid));
	};
