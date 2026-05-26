// bleed.sqf
_unit = (_this select 3) select 0;
player removeMagazine "ItemEpinephrine";
_isDead = _unit getVariable["USEC_isDead",false];
call fnc_usec_medic_removeActions;

player playActionNow "Medic";


sleep 3;

if (!_isDead) then {
	_unit setVariable ["NORRN_unconscious", false, true];
	_unit setVariable ["USEC_isCardiac",false,true];
	sleep 5;
	usecEpl = [_unit,player,"ItemEpinephrine"];
	publicVariable "usecEpl";
	_unit switchMove "AmovPpneMstpSnonWnonDnon_healed";
};

r_action = false;