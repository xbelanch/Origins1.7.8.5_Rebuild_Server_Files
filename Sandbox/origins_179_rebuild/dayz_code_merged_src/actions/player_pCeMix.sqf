private["_cemmix","_hasToolbox","_text","_alreadyPacking","_dir","_pos","_bag","_holder","_weapons","_magazines","_backpacks","_cemmixWpnTypes","_cemmixWpnQty","_countr"];
_cemmix = _this select 3;
player playActionNow "Medic";
player removeAction s_player_cnbb;
s_player_cnbb = -1;
_hasToolbox = "ItemToolbox" in items player;
_text = "ItemToolbox";
if (!_hasToolbox) exitWith {cutText [format[localize "str_player_34",_text], "PLAIN DOWN"]};

_alreadyPacking = _cemmix getVariable["packing",0];
if (_alreadyPacking == 1) exitWith {cutText [localize "str_player_beingpackMix", "PLAIN DOWN"]};

_cemmix setVariable["packing",1];
_dir = direction _cemmix;
_pos = getposATL _cemmix;
[player,"repair",0,false] call dayz_zombieSpeak;
sleep 4;
_bag = createVehicle ["WeaponHolder_ItemCeMix",_pos,[], 0, "CAN_COLLIDE"];
_bag setdir _dir;
player reveal _bag;
_holder = "WeaponHolder" createVehicle _pos; 
_magazines = 	getMagazineCargo _cemmix;
deleteVehicle _cemmix;

//Add Magazines
_cemmixWpnTypes = _magazines select 0;
_cemmixWpnQty = _magazines select 1;
_countr = 0;
{
	_holder addmagazinecargoGlobal [_x,(_cemmixWpnQty select _countr)];
	_countr = _countr + 1;
} forEach _cemmixWpnTypes;
cutText [localize "str_success_Cemix_pack", "PLAIN DOWN"];