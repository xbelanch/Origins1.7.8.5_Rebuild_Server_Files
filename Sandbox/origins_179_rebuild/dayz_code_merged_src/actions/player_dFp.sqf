private["_obj","_typeT","_ownerID","_objectID","_objectUID","_alreadyPacking","_dir","_pos","_mstrt","_bag","_holder","_weapons","_magazines","_backpacks","_objWpnTypes","_ojWnQy","_countr"];
diag_log format ["player_dFP _this = %1",_this];
_obj = _this select 3;
_typeT = typeOf _obj;
_point = 0;
OrignBB = [];
_ownerID 	= _obj getVariable["CharacterID","0"];
_objectID 	= _obj getVariable["ObjectID","0"];
_objectUID	= _obj getVariable["ObjectUID","0"];
_levelH		= _obj getVariable["levelhouse",0];

_lopata 	= "ItemEtool" in items player;
_hasToolbox = "ItemToolbox" in items player;
_playerID 	=	getPlayerUID player;
_allowedTo  = ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"];
if (!_lopata) exitWith {cutText ["Entrenching tool needed", "PLAIN DOWN"]};
if (!_hasToolbox) exitWith {cutText ["Toolbox needed", "PLAIN DOWN"]};
if (_levelH > 1) exitWith {cutText ["Only foundation can be removed ", "PLAIN DOWN"]};
if ((_typeT == "wooden_shed_lvl_1") OR (_typeT == "large_shed_lvl_1")) then {
	_point = bb_base select 0;
};
if ((_typeT == "log_house_lvl_2") OR (_typeT == "small_house_lvl_2")) then {
	_point = bb_base select 1;
};
if ((_typeT == "wooden_house_lvl_3") OR (_typeT == "big_house_lvl_3")) then {
	_point = bb_base select 2;
};
if (_typeT == "small_garage") then {
	_point = bb_base select 3;
};
if (_typeT == "big_garage") then {
	_point = bb_base select 4;
};

if (_point != 1) exitWith {cutText ["You not synchronized with server or this house is not your", "PLAIN DOWN"]};
player removeAction s_player_packFdp;
s_player_packFdp = -1;
player playActionNow "Medic";
diag_log format ["Pack Tent1 _typeT=%1, _ownerID=%2(%6), _objectID=%3, _objectUID=%4,_playerID=%5(%7)",_typeT,_ownerID,_objectID,_objectUID,_playerID,typeName _ownerID,typeName _playerID];
player removeAction s_player_packFdp;
s_player_packFdp = -1;

if(_ownerID == _playerID) then {
	diag_log ("dFp 1 _ownerID == _playerID");
	if (_typeT in _allowedTo) then {
		diag_log ("dFp 2 _typeT in _allowedTo");
		[player,"debbso",0,false] call dayz_zombieSpeak;
		
		diag_log format ["Pack Tent2 _typeT=%1, _ownerID=%2, _objectID=%3, _objectUID=%4, _obj=%5",_typeT,_ownerID,_objectID,_objectUID,_obj];
		sleep 3;

		oriUdalkaObj = [_objectID,_objectUID,_typeT,_obj,player];
		publicVariableServer "oriUdalkaObj";
		deleteVehicle _obj;
		
		cutText [(localize _mstrt), "PLAIN DOWN"];
	} else { cutText [localize "str_fail_tent_pack", "PLAIN DOWN"]; };
} else {
	cutText [localize "str_fail_tent_pack", "PLAIN DOWN"];
};