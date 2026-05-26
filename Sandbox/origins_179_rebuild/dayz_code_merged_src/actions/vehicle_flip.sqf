private["_object"];
//Play Animation and alert Zombies
player playActionNow "Medic";
[player,"repair",0,false] call dayz_zombieSpeak;
sleep 6;
//Flip the vehicle
_object = _this select 3;
_object setVectorUp [0,0,1];
