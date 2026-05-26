private["_unit","_selection","_strH","_dam","_total"];
_unit =			_this select 0;
_selection =	_this select 1;
_damage =		_this select 2;

if (_selection != "" and local _unit) then {
	if (_selection in ["front_plow","wheel_guards","window_guards","windshield_guard"]) then {
		_unit setVariable [_selection,_damage,true];
		diag_log format ["Upgrade = _selection =%1,_damage=%2",_selection,_damage];
		dayUpdateVehlcle = [_unit,"repair"];
	} else {
		_strH = "hit_" + (_selection);
		_unit setHit[_selection,_damage];
		//player sidechat str _damage;
		_unit setVariable [_strH,_damage,true];
		if (_damage == 0) then {
			dayUpdateVehlcle = [_unit,"repair"];
		} else {
			dayUpdateVehlcle = [_unit,"damage"];
		};
	};
	//diag_log format ["ObjectSetFixServer dayUpdateVehlcle=%1",dayUpdateVehlcle];
	if (isServer) then {
		if (allowConnection) then {
			dayUpdateVehlcle call server_updatObiect;
			diag_log ("Server setFixServer.sqf");
		};
	} else {
		publicVariableServer "dayUpdateVehlcle";
	};
};