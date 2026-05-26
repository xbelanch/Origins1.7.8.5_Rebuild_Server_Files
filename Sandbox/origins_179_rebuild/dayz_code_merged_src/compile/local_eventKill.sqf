//[unit, selectionName, damage, source, projectile]
//will only run when local to the created object
//record any key hits to the required selection
private["_zed","_killer","_kills","_array","_type","_humanity_s","_counzKill"];

_array = 		_this select 0;
_zed = 			_array select 0;
_killer = 		_array select 1;
_type = 		_this select 1;

if (local _zed) then {
	_kills = _killer getVariable[_type,0];
	_killer setVariable[_type,(_kills + 1),true];
	_counzKill = _killer getVariable ["zCountKill",0];
	if (_counzKill == 15) then {
		_humanity_s = _counzKill * 20;
		_killer setVariable ["zCountKill",0,true];
		dayzHmanity = [_killer,_humanity_s,0];
		publicVariable "dayzHmanity";
	} else {
		//diag_log ("Zed killed+1");
		_killer setVariable ["zCountKill",_counzKill+1,true];
	};
};