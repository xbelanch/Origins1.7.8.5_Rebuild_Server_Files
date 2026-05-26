private["_targetRest","_posRest","_playerPosRest","_distDifRest","_display","_control"];
disableserialization;
_sleepobj = _this select 3;
_newCuTyp = typeOf _sleepobj;
_newTypeBS = ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","TentStorageR"];
if(!(_newCuTyp in _newTypeB)) exitWith { cutText ["You can sleep only in Camping Tent or House", "PLAIN DOWN"]};

_targetRest = nearestObject [player,_newCuTyp];
_posRest = (_targetRest modelToWorld [0.0, 0.0, 0.0]);
_playerPosRest = (player modelToWorld [0.0, 0.0, 0.0]);
_distDifRest = ((_playerPosRest select 0)-(_posRest select 0));
	
player removeAction s_player_rest;
s_player_rest = -1;

if (_distDifRest<1) then {
	disableUserInput true;
	player switchMove "deadState";
	0 cutRsc ["ZeepScreen","BLACK OUT",20];
	[player,"zeeping",0,false] call dayz_zombieSpeak;
	sleep 42;
	
	[objNull, player, rSwitchMove,"AmovPpneMstpSrasWrflDnon"] call RE;
	0 cutText ["", "PLAIN"];
	r_player_blood = r_player_bloodTotal;
	r_player_lowblood = false;	
	10 fadeSound 1;
	"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
	"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 1],  [1, 1, 1, 1]];"colorCorrections" ppEffectCommit 5;
	
	r_player_inpain = false;
	"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
	
	//Ensure Control is visible
	_display = uiNamespace getVariable 'DAYZ_GUI_display';
	_control = 	_display displayCtrl 1300;
	_control ctrlShow true;
	
	player setVariable["USEC_BloodQty",r_player_bloodTotal,true];
	disableUserInput false;
	
};
	
	