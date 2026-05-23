private["_botActive","_int","_newModel","_doLoop","_wait","_hiveVer","_isHiveOk","_playerID","_playerObj","_randomSpot","_publishTo","_primary","_secondary","_key","_result","_charID","_playerObj","_playerName","_finished","_spawnPos","_spawnDir","_items","_counter","_magazines","_weapons","_group","_backpack","_worldspace","_direction","_newUnit","_score","_position","_isNew","_inventory","_backpack","_medical","_survival","_stats","_state","_a2edcRawModel","_a2edcNeedsGenderSelect","_a2edcInvalidGenderModels","_a2edcModelInvalid"];


diag_log ("STARTING LOGIN: " + str(_this));

_playerID = _this select 0;
_playerObj = _this select 1;
_playerName = name _playerObj;
_worldspace = [];

if (count _this > 2) then {
dayz_players = dayz_players - [_this select 2];
};




_inventory =	[];
_backpack = 	[];
_items = 		[];
_magazines = 	[];
_weapons = 		[];
_medicalStats =	[];
_survival =		[0,0,0];
_tent =			[];
_state = 		[];
_direction =	0;
_model =		"";
_newUnit =		objNull;
_botActive = false;

if (_playerID == "") then {
_playerID = getPlayerUID _playerObj;
};

if ((_playerID == "") or (isNil "_playerID")) exitWith {
diag_log ("LOGIN FAILED: Player [" + _playerName + "] has no login ID");
};


diag_log ("LOGIN ATTEMPT: " + str(_playerID) + " " + _playerName);


_doLoop = 0;
while {_doLoop < 5} do {
_key = format["CHILD:101:%1:%2:%3:",_playerID,dayZ_instance,_playerName];
_primary = [_key,false,dayZ_hivePipeAuth] call server_hiveReadWrite;
if (count _primary > 0) then {
if ((_primary select 0) != "ERROR") then {
_doLoop = 9;
};
};
_doLoop = _doLoop + 1;
};

if (isNull _playerObj or !isPlayer _playerObj) exitWith {
diag_log ("LOGIN RESULT: Exiting, player object null: " + str(_playerObj));
};

if ((_primary select 0) == "ERROR") exitWith {	
diag_log format ["LOGIN RESULT: Exiting, failed to load _primary: %1 for player: %2 ",_primary,_playerID];
};


_newPlayer = 	_primary select 1;
_isNew = 		count _primary < 6; 
_charID = 		_primary select 2;
_randomSpot = false;

if (isNil "A2EDC_GENDER_SELECT_REQUIRE_VALID_MODEL") then {A2EDC_GENDER_SELECT_REQUIRE_VALID_MODEL = true;};
if (isNil "A2EDC_GENDER_SELECT_TRACE_DB_STATE") then {A2EDC_GENDER_SELECT_TRACE_DB_STATE = true;};

_a2edcRawModel = "";
if (_isNew) then {
if (count _primary > 3) then {
_a2edcRawModel = _primary select 3;
};
} else {
if (count _primary > 7) then {
_a2edcRawModel = _primary select 7;
};
};

_a2edcNeedsGenderSelect = _isNew;
_a2edcInvalidGenderModels = ["","Survivor1_DZ","""Survivor1_DZ"""];
_a2edcModelInvalid = false;

if ((typeName _a2edcRawModel) != "STRING") then {
_a2edcModelInvalid = true;
} else {
if (_a2edcRawModel in _a2edcInvalidGenderModels) then {
_a2edcModelInvalid = true;
};
};

if (A2EDC_GENDER_SELECT_REQUIRE_VALID_MODEL && {_a2edcModelInvalid}) then {
_a2edcNeedsGenderSelect = true;
};

diag_log format ["LOGIN RESULT_spl: %1",_primary];
diag_log format [
"[A2EDC:GENDER_SELECT:SERVER_LOGIN] uid=%1 name=%2 charID=%3 isNew=%4 newPlayer=%5 rawCount=%6 raw=%7",
_playerID,
_playerName,
_charID,
_isNew,
_newPlayer,
count _primary,
_primary
];

diag_log format [
"[A2EDC:GENDER_SELECT:SERVER_DECISION] uid=%1 name=%2 charID=%3 isNew=%4 needsGender=%5 rawModel=%6 modelInvalid=%7 primaryCount=%8 requireValidModel=%9",
_playerID,
_playerName,
_charID,
_isNew,
_a2edcNeedsGenderSelect,
_a2edcRawModel,
_a2edcModelInvalid,
count _primary,
A2EDC_GENDER_SELECT_REQUIRE_VALID_MODEL
];


_hiveVer = 0;

if (!_isNew) then {

_inventory = 	_primary select 4;
_backpack = 	_primary select 5;
_survival =		_primary select 6;
_model =		_primary select 7;
_hiveVer =		_primary select 8;





if (!(_model in ["SurvivorW2_DZ","Bandit1_DZ","Survivor2_DZ","Survivor2_1DZ","Survivor2_2DZ","Survivor2_3DZ","Survivor3_DZ","Survivor4_DZ","Survivor4_1DZ","Survivor4_2DZ","Survivor4_3DZ","Survivor8_DZ","Survivor8_1DZ","Survivor8_2DZ","Survivor8_3DZ","Bandit_S_DZ","Bandit1_1DZ","Bandit1_2DZ","Bandit1_3DZ","Bandit1_3_1DZ","Bandit1_3_2DZ","Bandit2_1DZ","Bandit2_2DZ","Bandit2_3DZ","Bandit2_4DZ","Bandit2_5DZ","Bandit3_1","Hero1_1DZ","Hero1_2DZ","Hero1_3DZ","Hero1_4DZ","Hero1_5DZ","Hero1_6DZ","Hero1_7DZ","Hero2_1DZ","Hero2_2DZ","Hero2_3DZ","Hero2_4DZ","Hero2_5DZ","Hero3_1DZ","Hero3_2DZ","Hero3_3DZ","Hero3_4DZ","Hero3_5DZ","Hero3_6DZ","Hero2_10DZ","Sniper1_DZ","ori_vil_woman_survivor_1","ori_vil_woman_survivor_2","ori_vil_woman_survivor_3","ori_vil_woman_survivor_4","ori_vil_woman_survivor_5","ori_vil_woman_survivor_6","ori_vil_woman_bandit_1","ori_vil_woman_bandit_2","ori_vil_woman_bandit_3","ori_vil_woman_bandit_4","ori_vil_woman_bandit_5","ori_vil_woman_bandit_6","ori_vil_woman_hero_1","ori_vil_woman_hero_2","ori_vil_woman_hero_3","ori_vil_woman_hero_4","ori_vil_woman_hero_5","ori_vil_woman_hero_6"])) then {

_model = ["Survivor2_DZ","Survivor2_1DZ","Survivor2_2DZ","Survivor2_3DZ","Survivor4_DZ","Survivor4_1DZ","Survivor4_2DZ","Survivor4_3DZ","Survivor8_DZ","Survivor8_1DZ","Survivor8_2DZ","Survivor8_3DZ"] select floor random 12;
};

} else {
_model =		_primary select 3;

_hiveVer =		_primary select 4;
if (isNil "_model") then {
_model = ["Survivor2_DZ","Survivor2_1DZ","Survivor2_2DZ","Survivor2_3DZ","Survivor4_DZ","Survivor4_1DZ","Survivor4_2DZ","Survivor4_3DZ","Survivor8_DZ","Survivor8_1DZ","Survivor8_2DZ","Survivor8_3DZ"] select floor random 12;
} else {
if (_model == "") then {
_model = ["Survivor2_DZ","Survivor2_1DZ","Survivor2_2DZ","Survivor2_3DZ","Survivor4_DZ","Survivor4_1DZ","Survivor4_2DZ","Survivor4_3DZ","Survivor8_DZ","Survivor8_1DZ","Survivor8_2DZ","Survivor8_3DZ"] select floor random 12;
};
};


_config = (configFile >> "CfgSurvival" >> "Inventory" >> "Default");
_mags = getArray (_config >> "magazines");
_wpns = getArray (_config >> "weapons");
_bcpk = getText (_config >> "backpack");
_randomSpot = true;


_key = format["CHILD:203:%1:%2:%3:",_charID,[_wpns,_mags],[_bcpk,[],[]]];
_key call server_hiveWrite;
diag_log format ["server_playerLpg = %1",_key];
};
diag_log format ["LOGIN LOADED_spl: %1, Type: %2, Model %3",_playerObj,(typeOf _playerObj),_model];

_isHiveOk = false;	
if (_hiveVer >= dayz_hiveVersionNo) then {
_isHiveOk = true;
};

dayzPlayerLogin = [_charID,_inventory,_backpack,_survival,_isNew,dayz_versionNo,_model,_isHiveOk,_newPlayer,_a2edcNeedsGenderSelect];
diag_log format [
"[A2EDC:GENDER_SELECT:SERVER_LOGIN] uid=%1 name=%2 charID=%3 isNew=%4 model=%5 hiveOk=%6 newPlayer=%7 needsGender=%8",
_playerID,
_playerName,
_charID,
_isNew,
_model,
_isHiveOk,
_newPlayer,
_a2edcNeedsGenderSelect
];
(owner _playerObj) publicVariableClient "dayzPlayerLogin";
