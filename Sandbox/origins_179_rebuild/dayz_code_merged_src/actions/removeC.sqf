/*
delete object from db
parameters: _obj
*/
private ["_obj","_objName","_objPos","_ktoDel","_nearByW","_objectID","_listB"];
_obj		= _this select 3;
_objName 	= _obj getVariable ["RepBody", "unknown"];
_objPos		= (_obj modelToWorld [0.0, 0.0, 0.0]);
_ktoDel		= getPlayerUID player;
_nearByW = nearestObjects [_objPos, ["WeaponHolder","WeaponHolderBase"],1];
_objectID = "CroseHere";
_listB =  nearestObjects [_objPos,["DZ_Backpack_EP1","DZ_ALICE_Pack_EP1","CZ_VestPouch_EP1","DZ_Assault_Pack_EP1","DZ_CivilBackpack_EP1","DZ_Patrol_Pack_EP1","O_MegaPack_1","O_TravelerPack_1"],1];

player playActionNow "Medic";
sleep 1;
[player,"repair",0,false] call dayz_zombieSpeak;
_id = [player,50,true,(getPosATL player)] spawn player_alertZombies;
sleep 5;
	
oriUdalkaObj = [_objectID,_objName,_objPos,_ktoDel,_nearByW,_listB];
publicVariableServer "oriUdalkaObj";
{ deleteVehicle _x; } forEach _nearByW;
{ deleteVehicle _x; } forEach _listB;
deleteVehicle _obj;