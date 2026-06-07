private ["_itOKbu","_stopGo","_flagTo","_Ok","_deagOK","_passUch","_objects","_object","_chePsw","_codeArray","_codeString","_status","_passwordN","_pcount","_msg","_playerID","_objectID","_objectLevel","_type","_rawType","_naObnovkuOld"];

diag_log format ["START ppver ,_this =%1 ",_this];
_itOKbu = false;
_stopGo = false;
_flagTo = 0;
CODEINPUT = [];
CODE = "";
_Ok = false;
_deagOK = false;
_passUch = [0,false,"Abort Password Security System"];
_objects = _this select 3;
_object = _objects select 0;
_flagTo = _objects select 1;

diag_log format ["ppver ,_flagTo =%1, typeName=%2 ",_flagTo, typeName _flagTo];
if(_flagTo != 1 and _flagTo != 2) exitWith { titletext ["Undefined, Something wrong", "PLAIN DOWN"]; _stopGo = true; };

_chePsw = {
	_codeArray = _this select 0;
	_codeString = _this select 1;
	_status = [];
	_passwordN = 0;
	_pcount = count(_codeArray) == 6;
	_passwordN = parseNumber _codeString;
	//diag_log format ["_passwordN = %1(%4),_codeArray=%2,_codeString=%3(%5)",_passwordN,_codeArray,_codeString,typeName _passwordN,typeName _codeString];
	if (_passwordN != 0) then {
		_Ok = (999999-_passwordN) >= 0;
		if (_Ok) then {	
			if (typeName _passwordN == "SCALAR") then {
				_msg = "Error";
				if(_flagTo == 1) then { _msg = "Unlock house, open Doors"; };
				if(_flagTo == 2) then { _msg = "Lock house, close Doors"; };
				_status = [_passwordN,true,_msg];
			} else {
				_status = [0,false,"The passoword must consist of numbers"];
			};
		} else {
			_status = [0,false,"The passoword must have only 6 numbers"];
		};
	} else { 
		_status = [0,false,"The passoword = 0"];						
	};
	_status;
};

// start dialog
_playerID =	getPlayerUID player;
_objectID = _object getVariable ["CharacterID","0"];
_objectLevel = _object getVariable ["levelhouse",0];
_rawType = typeOf _object;
_type = _object getVariable ["A2EDC_DBHouseType",_rawType];
if (_type == "Uroven1VelkaBudka") then {_type = "large_shed_lvl_1";};
if (_objectLevel == 0) exitWith { titletext ["House Level Undefined, Something wrong", "PLAIN DOWN"]; _stopGo = true; };
if ((_type == "wooden_shed_lvl_1") OR (_type == "large_shed_lvl_1") OR (_type == "big_house_lvl_3")) then {
	_stopGo = _objectLevel < 2;
};
if ((_type == "log_house_lvl_2") OR (_type == "small_house_lvl_2") OR (_type == "wooden_house_lvl_3")) 	then {
	_stopGo = _objectLevel < 3;
};
if ((_type == "small_garage") OR (_type == "big_garage")) 	then {
	_stopGo = _objectLevel < 3;
};
if (_type == "object_x") 	then {
	_stopGo = _objectLevel != 1;
};


//_objectLevel = _object getVariable ["levelhouse","0"];
if (!_stopGo) then {
	if (_playerID != _objectID) then { titletext ["You not the owner of this building", "PLAIN DOWN"]; _stopGo = true; } else {
		//diag_log ("START Open Dialog");
		_deagOK = createDialog "KeypadHouse";
		waitUntil { !dialog };
		if (CODE != "") then {
			_passUch = [CODEINPUT,CODE] call _chePsw;
		};
		//diag_log ("END Open Dialog");
		if (_passUch select 1) then {
			verbb_pas = [_object,player,_objectLevel,_playerID,_passUch select 0,_flagTo];
			publicVariableServer "verbb_pas";
			titletext [_passUch select 2, "PLAIN DOWN"];
			diag_log format ["verbb_pas=%1",verbb_pas];
			sleep 5;
			_naObnovkuOld = _object getVariable["DaBeUpd",false];
			if(_flagTo == 1)  then {
				if(_naObnovkuOld) then {
					player removeAction s_player_otkdv;
					s_player_otkdv = -1;
					s_player_otkdv = player addAction ["Lock house, close doors", "\z\addons\dayz_code\actions\player_ppver.sqf",[cursorTarget,2], 0, false, true, "",""];
				};
			};
			if(_flagTo == 2)  then {
				if(!_naObnovkuOld) then {
					player removeAction s_player_otkdv;
					s_player_otkdv = -1;
					s_player_otkdv = player addAction ["Un-lock house, open doors", "\z\addons\dayz_code\actions\player_ppver.sqf",[cursorTarget,1], 0, false, true, "",""];
				};
			};
		} else { titletext [_passUch select 2, "PLAIN DOWN"]; };
	};
} else {
	titletext ["This building not locked yet", "PLAIN DOWN"];
};

