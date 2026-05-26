diag_log format ["START medEpl.sqf"];
// animHealed.sqf
_array = _this; //_this select 0;
_unit = _array select 0;
_medic = _array select 1;

_isDead = _unit getVariable["USEC_isDead",false];

//diag_log format ["_this=%1, _isDead =%2",_this,_isDead];

if (local _unit) then {_unit setCaptive false};

if (!_isDead) then {
	//_unit switchMove "AmovPpneMstpSnonWnonDnon_healed";
	_unit setVariable ["NORRN_unconscious", false, true];
	_unit setVariable ["USEC_isCardiac",false,true];
	_unit switchMove "AmovPpneMstpSnonWnonDnon_healed";
	_NORRN_unconscious2 = _unit getVariable "NORRN_unconscious";
	_USEC_isCardiac2 = _unit getVariable "USEC_isCardiac";
	//diag_log("TUTswitchMove and _NORRN_unconscious2=" + str(_NORRN_unconscious2) + "USEC_isCardiac2= "+ str(USEC_isCardiac2));
	
	if (_unit == player) then {
		diag_log("TUTswitchMove2");
		r_player_unconscious = false;
		disableUserInput false;
		r_player_cardiac = false;
		r_player_handler1 = false;
	};
	if (local _unit) then {
	 _unit setVariable["medForceUpdate",true, true];
	};
};