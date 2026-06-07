private ["_done"];
if (!("ItemGPS" in items player)) then {player addweapon "ItemGPS";};
_done = false;

teleport = {
	_pos = [_this select 0, _this select 1,_this select 2];
	openMap [false, false];
	TitleText [format[""], "PLAIN DOWN"];
	["self_pos",_pos] execVM "admintools\tools\Teleport\a2edc_adminTeleportRequest.sqf";
	_done = true;
};

closedialog 0;
sleep 0.5;
TitleText [format["Click on the map to Teleport"], "PLAIN DOWN"]; titleFadeOut 3;

if(!(visibleMap)) then {
	openMap [true, false];
};

onMapSingleClick '[_pos select 0, _pos select 1, _pos select 2] call teleport';
waitUntil{_done || !(visibleMap)};
onMapSingleClick "";
