private["_isHero1_s","_isHero2_s","_isHero3_s","_isBandit1_s","_isBandit2_s","_isBandit3_s","_isHero1_p","_isHero2_p","_isHero3_p","_isBandit1_p","_isBandit2_p","_isBandit3_p","_plevel","_slevel","_isSurvi_p","_isSurvi_s","_body","_playerID","_source","_method","_id","_humanity","_wait","_array","_canHitFree","_humanityVP","_humanityVS","_MuKills_s","_HeroKills_s","_BandKills_s","_humanity_s","_myGroup","_typedeP","_nameKillerP"];
if (deathHandled) exitWith {};

_isHero1_s=false;_isHero2_s=false;_isHero3_s=false;
_isBandit1_s=false;_isBandit2_s=false;_isBandit3_s=false;
_isHero1_p=false;_isHero2_p=false;_isHero3_p=false;
_isBandit1_p=false;_isBandit2_p=false;_isBandit3_p=false;
_plevel=0;_slevel=0;_typedeP = 0;
_isSurvi_p = false; _isSurvi_s=false;
deathHandled = true;
//Death

_body =		player;
_playerID =	getPlayerUID player;
_source = 	_this select 0;
_method = 	_this select 1;
_nameKillerP = "unknown";

_id = [player,50,true,getPosATL player] spawn player_alertZombies;

sleep 0.5;

player setDamage 1;
0.1 fadeSound 0;

player setVariable ["NORRN_unconscious", false, true];
player setVariable ["unconsciousTime", 0, true];
player setVariable ["USEC_isCardiac",false,true];
player setVariable ["medForceUpdate",true,true];
//remove combat timer on death
player setVariable ["startcombattimer", 0, true];
r_player_unconscious = false;
r_player_cardiac = false;

//_id = player spawn spawn_flies;

_humanity =		0;
_wait = 		0;
_humanity_s = 	0;
_humanityVP = 	0;
_humanityVS =	0;
_MuKills_s =	0;
_HeroKills_s =	0;
_BandKills_s =	0;
_wait =			0;
_array = _this;
typedeP = 0;
//diag_log format ["(count _array)=%5,_array=%1,player=%3,_source=%2,_sourceT=%4",_array,_source,(typeOf player),(typeOf _source),(count _array)];

_humanityVP 	= (player getVariable ["humanity",2500]);

if (_humanityVP > 2000 and _humanityVP < 2900) then { _isSurvi_p = true; _typedeP = 2;};
			
if (_humanityVP >= 2900 and _humanityVP < 6500) then  { _isHero1_p = true; _plevel = 1; _typedeP = 3;};
if (_humanityVP >= 6500 and _humanityVP <= 15000) then { _isHero2_p = true; _plevel = 2; _typedeP = 3;};
if (_humanityVP > 15000) then { _isHero3_p = true; _plevel = 3; _typedeP = 3;};

if (_humanityVP > -6500 and _humanityVP <= 2000) then { _isBandit1_p = true; _plevel = 1; _typedeP = 1;};
if (_humanityVP >= -15000 and _humanityVP <= -6500) then { _isBandit2_p = true; _plevel = 2; _typedeP = 1;};
if (_humanityVP < -15000) then { _isBandit3_p = true; _plevel = 3; _typedeP = 1;};

if (count _array > 0) then {

	if (!isNull _source) then {
		if (_source != player) then {
			
			_canHitFree = 	player getVariable ["freeTarget",false];
			
			_humanityVS		= (_source getVariable ["humanity",2500]);
			//diag_log format ["_humanityVP=%1,_humanityVS=%2",_humanityVP,_humanityVS];

			if (_humanityVS > 2000 and _humanityVS < 2900) then { _isSurvi_s = true; };
			
			if (_humanityVS >= 2900 and _humanityVS < 6500) then  { _isHero1_s = true; _slevel = 1;};
			if (_humanityVS >= 6500 and _humanityVS <= 15000) then { _isHero2_s = true; _slevel = 2;};
			if (_humanityVS > 15000) then { _isHero3_s = true; _slevel = 3;};
			
			if (_humanityVS > -6500 and _humanityVS <= 2000) then { _isBandit1_s = true; _slevel = 1; };
			if (_humanityVS >= -15000 and _humanityVS <= -6500) then { _isBandit2_s = true; _slevel = 2;};
			if (_humanityVS < -15000) then { _isBandit3_s = true; _slevel = 3;};
			
			_MuKills_s 	= (_source getVariable ["humanKills",0]);
			_HeroKills_s 	= (_source getVariable["headShots",0]);	
			_BandKills_s 	= (_source getVariable ["banditKills",0]);

			
			
			//_isSurvi_s
			if ((!_canHitFree) && _isSurvi_s && _isSurvi_p) then 
				{ _humanity_s = -500; _source setVariable ["humanKills",(_MuKills_s + 1),true];};
			if ((!_canHitFree) && _isSurvi_s && (_isBandit1_p or _isBandit2_p or _isBandit3_p)) then 	
				{ _humanity_s = (400*_plevel); _source setVariable ["banditKills",(_BandKills_s + 1),true];};
			if ((!_canHitFree) && _isSurvi_s && (_isHero1_p or _isHero2_p or _isHero3_p)) then 	
				{ _humanity_s = -(500*_plevel); _source setVariable["headShots",(_HeroKills_s + 1),true];};
		
			//_isBandit1_s
			if (((!_canHitFree)) && (_isBandit1_s or _isBandit2_s or _isBandit3_s) && _isSurvi_p) then 		
				{ _humanity_s = -(200-(100*_slevel)); _source setVariable ["humanKills",(_MuKills_s + 1),true];};
			if ((!_canHitFree) && (_isBandit1_s or _isBandit2_s or _isBandit3_s) && (_isBandit1_p or _isBandit2_p or _isBandit3_p)) then 
				{ _humanity_s = -(200*(3-_slevel)*_plevel); _source setVariable ["banditKills",(_BandKills_s + 1),true];};
			if ((!_canHitFree) && (_isBandit1_s or _isBandit2_s or _isBandit3_s) && (_isHero1_p or _isHero2_p or _isHero3_p)) then 		
				{ _humanity_s = -(500*_plevel); _source setVariable["headShots",(_HeroKills_s + 1),true];};
			
			//_isHero1_s
			if ((!_canHitFree) && (_isHero1_s or _isHero2_s or _isHero3_s) && _isSurvi_p) then 		
				{ _humanity_s = -(100+(100*_slevel)*_slevel); _source setVariable ["humanKills",(_MuKills_s + 1),true];};
			if ((!_canHitFree) && (_isHero1_s or _isHero2_s or _isHero3_s) && (_isBandit1_p or _isBandit2_p or _isBandit3_p)) then 	
				{ _humanity_s = (300*_plevel); _source setVariable ["banditKills",(_BandKills_s + 1),true];};
			if ((!_canHitFree) && (_isHero1_s or _isHero2_s or _isHero3_s) && (_isHero1_p or _isHero2_p or _isHero3_p)) then 
				{ _humanity_s = -(500*_plevel); _source setVariable["headShots",(_HeroKills_s + 1),true];};
		
				//dayzHmanity = [_source,_humanity_s,_wait];
				//publicVariable "dayzHmanity";
				//diag_log format ["_MuKills_s=%1,_HeroKills_s=%2,_BandKills_s=%3,dayzHmanity=%4",_MuKills_s,_HeroKills_s,_BandKills_s,dayzHmanity];
		};
		_nameKillerP = (name _source);
	};
	
	_body setVariable ["deathType",_method,true];
	_body setVariable ["nameKillerP",_nameKillerP,true];
	_body setVariable ["typedeP",_typedeP,true];
};
//Send Death Notice
dayzDeath = [dayz_characterID,0,_body,_playerID,dayz_playerName,_source,_method,_humanity_s];
publicVariableServer "dayzDeath";
if (isServer) then {
	_id = dayzDeath spawn server_playerDied; 
	diag_log ("Client var dayzDeath");
};

terminate dayz_musicH;
terminate dayz_lootCheck;
terminate dayz_slowCheck;
terminate dayz_animalCheck;
terminate dayz_monitor1;
terminate dayz_medicalH;
terminate dayz_gui;

//Reset (just in case)
//deleteVehicle dayz_playerTrigger;
disableUserInput false;
r_player_dead = true;

"dynamicBlur" ppEffectEnable true;"dynamicBlur" ppEffectAdjust [4]; "dynamicBlur" ppEffectCommit 0.2;

"colorCorrections" ppEffectEnable true;
"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.01],  [1, 1, 1, 0.0]];
"colorCorrections" ppEffectCommit 1;

//Player is Dead!
3 fadeSound 0;
0 cutText ["", "BLACK",10];
dayz_DeathActioned = true;
sleep 1;

TitleText[localize "str_player_12","PLAIN DOWN",5];

dayz_originalPlayer enableSimulation true;

addSwitchableUnit dayz_originalPlayer;
setPlayable dayz_originalPlayer;
selectPlayer dayz_originalPlayer;

_myGroup = group _body;
[_body] joinSilent dayz_firstGroup;
deleteGroup _myGroup;

3 cutRsc ["default", "PLAIN",3];
4 cutRsc ["default", "PLAIN",3];

if (count _array > 0) then {
	_body setVariable ["deathType",_method,true];
};

_body setVariable["combattimeout", 0, true];

sleep 2;

1 cutRsc ["DeathScreen","BLACK OUT",3];


playMusic "dayz_track_death_1";

"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 1],  [1, 1, 1, 1]];"colorCorrections" ppEffectCommit 5;