diag_log format [
"[A2EDC:DISCO:VERSION] disco_playerMorph executing build_id=%1 build_utc=%2 note=%3",
if (isNil "A2EDC_DAYZ_SERVER_BUILD_ID") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_ID},
if (isNil "A2EDC_DAYZ_SERVER_BUILD_UTC") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_UTC},
if (isNil "A2EDC_DAYZ_SERVER_BUILD_NOTE") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_NOTE}
];

private ["_object","_playerID","_characterID","_penalty","_playerName","_model","_position","_dir","_currentAnim","_updates","_humanity","_temp","_worldspace","_zombieKills","_headShots","_humanKills","_banditKills","_medical","_messing","_weapons","_magazines","_primweapon","_secweapon","_newBackpackType","_backpackWpn","_backpackMag","_currentWpn","_muzzles","_doLoop","_key","_primary","_newUnit","_newBackpack","_backpackWpnTypes","_backpackWpnQtys","_countr","_backpackmagTypes","_backpackmagQtys","_backpackmag","_fractures","_mydamage_eh1","_isDead","_playerGear","_playerBackp","_a2edcBleedFn","_a2edcRawOnBack","_a2edcNorm","_a2edcReason","_a2edcDup"];
_object 	= _this select 0;

_playerID 	= _this select 1; 
_characterID 	= _this select 2; 

_penalty	= _this select 3;
_playerName	= _object getVariable["bodyName","unknown"]; 
_model		= typeOf _object;
_position 	= getPosATL _object;
_dir 		= getDir _object;
_currentAnim 	= animationState _object;

_object removeAllEventHandlers "FiredNear";
_object removeAllEventHandlers "HandleDamage";
_object removeAllEventHandlers "Killed";
_object removeAllEventHandlers "Fired";



_updates 	= _object getVariable["updatePlayer",[false,false,false,false,false]];
_updates set [0,true];
_object setVariable["updatePlayer",_updates,true];

_humanity 	= _object getVariable["humanity",0];
_temp 		= round(_object getVariable ["temperature",100]);
_worldspace 	= [round(_dir),_position];
_zombieKills 	= _object getVariable ["zombieKills",0];
_headShots 	= _object getVariable ["headShots",0];
_humanKills 	= _object getVariable ["humanKills",0];
_banditKills 	= _object getVariable ["banditKills",0];
_medical 	= _object call player_sumMedical;
_messing	= _object getVariable ["messing",[0,0]];



_weapons 	= weapons _object;
_magazines	= magazines _object;
_primweapon	= primaryWeapon _object;
_secweapon	= secondaryWeapon _object;
_a2edcRawOnBack = _object getVariable ["A2EDC_onBack",""];
if (((typeName _a2edcRawOnBack) != "STRING") or (_a2edcRawOnBack == "")) then {
_a2edcRawOnBack = _object getVariable ["dayz_onBack",""];
};
_a2edcNorm = [_a2edcRawOnBack,_weapons,_primweapon,_playerID,_characterID,"disco_playerMorph"] call A2EDC_fnc_normalizeOnBackPersist;
_a2edcReason = _a2edcNorm select 1;
_a2edcDup = _a2edcNorm select 2;
_a2edcNorm = _a2edcNorm select 0;
diag_log format["A2EDC:ONBACK_DISCO_CAPTURE uid=%1 charID=%2 rawOnBack=%3 normalizedOnBack=%4 reason=%5 duplicate=%6 primary=%7 weapons=%8",_playerID,_characterID,_a2edcRawOnBack,_a2edcNorm,_a2edcReason,_a2edcDup,_primweapon,_weapons];


if(!(_primweapon in _weapons) && _primweapon != "") then {
_weapons = _weapons + [_primweapon];
};

if(!(_secweapon in _weapons) && _secweapon != "") then {
_weapons = _weapons + [_secweapon];
};

if(count _magazines == 0) then {
_magazines = magazines _object;
};


_newBackpackType = typeOf (unitBackpack _object);
if(_newBackpackType != "") then {
_backpackWpn = getWeaponCargo unitBackpack _object;
_backpackMag = getMagazineCargo unitBackpack _object;
};


_currentWpn = "";
if (isNil "_currentWpn") then {
_currentWpn = "";
};
diag_log format [
"[A2EDC:DISCO:CURRENT_WPN] build_id=%1 currentWpn=%2 type=%3 isNil=%4",
if (isNil "A2EDC_DAYZ_SERVER_BUILD_ID") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_ID},
_currentWpn,
typeName _currentWpn,
isNil "_currentWpn"
];
if ((typeName _currentWpn) == "STRING") then {
if (_currentWpn != "") then {
if (!(isClass(configFile >> "CfgWeapons" >> _currentWpn))) then {
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph currentWpn before CfgWeapons probe", _currentWpn] call A2EDC_fnc_traceWeaponClass;
};
};
_muzzles = getArray(configFile >> "cfgWeapons" >> _currentWpn >> "muzzles");
if (count _muzzles > 1) then {
_currentWpn = currentMuzzle _object;
};
} else {
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph currentWpn before CfgWeapons probe", _currentWpn] call A2EDC_fnc_traceWeaponClass;
};
};
} else {
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph currentWpn before CfgWeapons probe", _currentWpn] call A2EDC_fnc_traceWeaponClass;
};
};
















_group 		= createGroup civilian;
_newUnit 	= _group createUnit [_model,[0,0,0],[],0,"NONE"];
sleep 0.1;


{_newUnit removeMagazine _x;} forEach (magazines _newUnit);
removeAllWeapons _newUnit;


{ _newUnit addMagazine _x } forEach _magazines;
{
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph restore _weapons addWeapon", _x] call A2EDC_fnc_traceWeaponClass;
};
if ((typeName _x == "STRING") && (_x != "")) then {
_newUnit addWeapon _x;
};
} forEach _weapons;
if(_primweapon !=  (primaryWeapon _newUnit)) then {
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph restore _primweapon addWeapon", _primweapon] call A2EDC_fnc_traceWeaponClass;
};
if ((typeName _primweapon == "STRING") && (_primweapon != "")) then {
_newUnit addWeapon _primweapon;
};
};
if(_secweapon != (secondaryWeapon _newUnit) && _secweapon != "") then {
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph restore _secweapon addWeapon", _secweapon] call A2EDC_fnc_traceWeaponClass;
};
_newUnit addWeapon _secweapon;
};


if (!isNil "_newBackpackType") then {
if (_newBackpackType != "") then {
_newUnit addBackpack _newBackpackType;
_newBackpack = unitBackpack _newUnit;


_backpackWpnTypes = [];
_backpackWpnQtys = [];
if (count _backpackWpn > 0) then {
_backpackWpnTypes = _backpackWpn select 0;
_backpackWpnQtys = 	_backpackWpn select 1;
};
_countr = 0;
{
if (!(isNil "A2EDC_fnc_traceWeaponClass")) then {
["disco_playerMorph backpack addWeaponCargoGlobal", _x] call A2EDC_fnc_traceWeaponClass;
};
_newBackpack addWeaponCargoGlobal [_x,(_backpackWpnQtys select _countr)];
_countr = _countr + 1;
} forEach _backpackWpnTypes;

_backpackmagTypes = [];
_backpackmagQtys = [];
if (count _backpackmag > 0) then {
_backpackmagTypes = _backpackMag select 0;
_backpackmagQtys = 	_backpackMag select 1;
};
_countr = 0;
{
_newBackpack addmagazineCargoGlobal [_x,(_backpackmagQtys select _countr)];
_countr = _countr + 1;
} forEach _backpackmagTypes;
};
};

if (count _medical > 0) then {
_newUnit setVariable["USEC_isDead",(_medical select 0),true];
_newUnit setVariable["NORRN_unconscious", (_medical select 1), true];
_newUnit setVariable["USEC_infected",(_medical select 2),true];
_newUnit setVariable["USEC_injured",(_medical select 3),true];
_newUnit setVariable["USEC_inPain",(_medical select 4),true];
_newUnit setVariable["USEC_isCardiac",(_medical select 5),true];
_newUnit setVariable["USEC_lowBlood",(_medical select 6),true];
_newUnit setVariable["USEC_BloodQty",(_medical select 7),true];
_newUnit setVariable["unconsciousTime",(_medical select 10),true];

{
_newUnit setVariable[_x,true,true];
diag_log format [
"[A2EDC:DISCO:BLEED_GUARD:ENTER] build_id=%1 wound=%2 fnc_isNil=%3 newUnit=%4",
if (isNil "A2EDC_DAYZ_SERVER_BUILD_ID") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_ID},
_x,
isNil "fnc_usec_damageBleed",
_newUnit
];

_a2edcBleedFn = nil;

if (!isNil "fnc_usec_damageBleed") then {
_a2edcBleedFn = fnc_usec_damageBleed;
};

if (!isNil "_a2edcBleedFn") then {
diag_log format [
"[A2EDC:DISCO:BLEED_GUARD:SPAWN] build_id=%1 wound=%2 using=indirect",
if (isNil "A2EDC_DAYZ_SERVER_BUILD_ID") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_ID},
_x
];

[_newUnit,_x,0] spawn _a2edcBleedFn;
} else {
diag_log format [
"[A2EDC:DISCO:BLEED_GUARD:SKIP] build_id=%1 wound=%2 reason=fnc_usec_damageBleed undefined",
if (isNil "A2EDC_DAYZ_SERVER_BUILD_ID") then {"<nil>"} else {A2EDC_DAYZ_SERVER_BUILD_ID},
_x
];
};
usecBleed = [_newUnit,_x,0];
publicVariable "usecBleed";
} forEach (_medical select 8);

_fractures = (_medical select 9);
_newUnit setVariable ["hit_legs",(_fractures select 0),true];
_newUnit setVariable ["hit_hands",(_fractures select 1),true];
} else {

_newUnit setVariable ["hit_legs",0,true];
_newUnit setVariable ["hit_hands",0,true];
_newUnit setVariable ["USEC_injured",false,true];
_newUnit setVariable ["USEC_inPain",false,true];	
};

_newUnit setVariable["characterID",_characterID,true];
_newUnit setVariable["worldspace",_worldspace,true];
_newUnit setVariable["bodyName",_playerName,true];
_newUnit setVariable["playerID",_playerID,true];
_newUnit setVariable["temperature",_temp,true];
_newUnit setVariable["messing",_messing,true];
_newUnit setVariable["A2EDC_onBack",_a2edcNorm,true];
_newUnit setVariable["dayz_onBack",_a2edcNorm,true];


_newUnit allowDamage true;
deleteVehicle _object;
deleteGroup (group _object);
_newUnit setDir _dir;
_newUnit setPosATL _position;

_newUnit disableConversation true;
_newUnit setCaptive false;




botPlayers = botPlayers + [_playerID];
diag_log format["A2EDC:REJOIN:BOTPLAYERS_STATE uid=%1 charID=%2 action=add botPlayers=%3 pos=%4",_playerID,_characterID,botPlayers,_position];

_mydamage_eh1 = _newUnit addeventhandler ["HandleDamage",{ _this call disco_damageHandler; }];

diag_log format["DEBUG: Player %1 [%2] added to botPlayers: %3",_playerName,_playerID,botPlayers];

_isDead = _newUnit getVariable["USEC_isDead",false];
_doLoop = 0;
diag_log format["DEBUG: START _doLoop %1,_isDead=%2",_doLoop,_isDead];
while { _doLoop < 10 && !_isDead } do 
{
_isDead = _newUnit getVariable["USEC_isDead",false];
_doLoop = _doLoop + 1;
sleep 1;
};
diag_log format["DEBUG: END _doLoop %1, _isDead=%2",_doLoop,_isDead];
_newUnit removeAllEventHandlers "handleDamage";

if (!_isDead) then {
_medical = _newUnit call player_sumMedical;
_newBackpack = unitBackpack _newUnit;
_playerBackp = [typeOf _newBackpack,getWeaponCargo _newBackpack,getMagazineCargo _newBackpack];
_a2edcRawOnBack = _newUnit getVariable ["A2EDC_onBack",_a2edcNorm];
_a2edcNorm = [_a2edcRawOnBack,_weapons,_primweapon,_playerID,_characterID,"disco_playerMorph_save"] call A2EDC_fnc_normalizeOnBackPersist;
_a2edcReason = _a2edcNorm select 1;
_a2edcDup = _a2edcNorm select 2;
_a2edcNorm = _a2edcNorm select 0;
_playerGear = [_weapons,_magazines,_playerBackp,_a2edcNorm];
if (((typeName _a2edcRawOnBack) == "STRING") and (_a2edcRawOnBack != "") and (_a2edcNorm == "")) then {
diag_log format["A2EDC:ONBACK_SAVE_SKIP_INVALID side=server path=disco_playerMorph uid=%1 charID=%2 rawOnBack=%3 reason=%4 duplicate=%5 primary=%6 weapons=%7",_playerID,_characterID,_a2edcRawOnBack,_a2edcReason,_a2edcDup,_primweapon,_weapons];
};
diag_log format["A2EDC:ONBACK_SAVE side=server path=disco_playerMorph uid=%1 charID=%2 rawOnBack=%3 normalizedOnBack=%4 reason=%5 duplicate=%6 primary=%7 weapons=%8",_playerID,_characterID,_a2edcRawOnBack,_a2edcNorm,_a2edcReason,_a2edcDup,_primweapon,_weapons];

deleteVehicle _newUnit;
deleteGroup _group;

[_characterID,_worldspace,_playerGear,_playerBackp,_medical,[],"",_a2edcNorm] call server_characterSync;
};
botPlayers = botPlayers - [_playerID];
diag_log format["A2EDC:REJOIN:BOTPLAYERS_STATE uid=%1 charID=%2 action=remove botPlayers=%3",_playerID,_characterID,botPlayers];
diag_log format["DEBUG: Player %1 [%2] removed from botPlayers: %3",_playerName,_playerID,botPlayers];
