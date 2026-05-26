private ["_location","_onLadder","_isWater","_item","_buildobj","_text","_hasbuilditem","_dir","_object"];
_location = player modeltoworld [0,1,0];
_location set [2,0];
_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_isWater = 		(surfaceIsWater _location) or dayz_isSwimming;

call gear_ui_init;

if(_isWater) exitWith {cutText [localize "str_player_26", "PLAIN DOWN"];};
if(_onLadder) exitWith {cutText [localize "str_player_21", "PLAIN DOWN"];};

_item =			_this;
_buildobj = 	getText (configFile >> "CfgMagazines" >> _item >> "ItemActions" >> "Build" >> "create");
_text = 		getText (configFile >> "CfgVehicles" >> _buildobj >> "displayName");

_hasbuilditem = _this in magazines player;

if (!_hasbuilditem) exitWith {cutText [format[(localize "str_player_31"),_text,"build"] , "PLAIN DOWN"]};

_dir = getDir player;
player removeMagazine _item;

player playActionNow "Medic";
sleep 1;
[player,"repair",0,false] call dayz_zombieSpeak;
_id = [player,50,true,(getPosATL player)] spawn player_alertZombies;
sleep 5;

if (!(_buildobj in ["Wire_cat1","Hedgehog_DZ","Sandbag1_DZ","BearTrap_DZ"])) exitWith { cutText ["You cannot place this object", "PLAIN DOWN"]; };
player allowDamage false;
_object = createVehicle [_buildobj, _location, [], 0, "CAN_COLLIDE"];
_object setDir _dir;
player reveal _object;

cutText [format[localize "str_build_01",_text], "PLAIN DOWN"];

sleep 2;
player allowDamage true;