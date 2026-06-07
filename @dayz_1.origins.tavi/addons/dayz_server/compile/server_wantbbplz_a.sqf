private["_player","_item","_playerIDc","_typN1","_typN2","_canBuildH","_anim","_objectF","_stageArF","_selection","_dam","_animSource","_GivName","_text","_tA","_tA2","_count","_tT","_basebbm","_playerIDs","_bbases","_playerID","_pNameR","_stageAr","_hasBPitem","_housetype","_levelhouse","_bb_baseserver","_posit","_dir","_object","_vector","_worldspace","_uid","_key","_gObjId","_objectIDCl","_zapiskavDB","_a2edcHouseCreateClass","_a2edcHouseDbType","_a2edcHouseAnimationSource","_a2edcGetCfgText","_a2edcGetCfgNumber","_a2edcServerContains","_createClass","_createCfg","_dbCfg","_createIsClass","_dbIsClass","_createScope","_dbScope","_createSimulation","_dbSimulation","_createVehicleClass","_dbVehicleClass","_createModel","_dbModel","_objectIsNull","_stageSelections","_requestedPos","_requestedDir","_placementValid","_placementReason","_placementHouses","_placementTents","_placementRealTents","_placementCityObjects","_placementCityBlockers","_placementNature","_placementType","_placementModel","_placementCombined","_placementIsLand","_placementIsUtility","_placementIsCoastal","_placementMixers","_placementMixer","_placementRequired","_placementCargo","_placementCargoTypes","_placementCargoQty","_placementMaterialValid","_placementMissing","_placementRequiredClass","_placementRequiredQty","_placementFoundQty","_placementCargoIndex"];
diag_log format ["server_wantbbplz this=%1",_this];
_player 	= _this select 0;
_item 		= _this select 1;
_playerIDc 	= _this select 2;
_playerPosA2EDC = [];
if (!(isNull _player)) then {_playerPosA2EDC = getPosATL _player;};
diag_log format ["A2EDC:HOUSE_BUILD_ACTION item=%1 action=server_wantbbplz uid=%2 player=%3 playerPos=%4 cursorTarget=%5 selectedBlueprint=%6 selectedBuilding=%7",_item,_playerIDc,_player,_playerPosA2EDC,objNull,_item,""];
_typN1 = typeName _player;
_typN2 = typeName _item;
_canBuildH = false;
_gObjId = "";
_sObjId = "";
_zapiskavDB = false;
OriginBB = [];
if (isNull _player) exitWith { diag_log ("SETUP INIT FAILED: Exiting, player object null: " + str(_player)); };

_a2edcHouseCreateClass = {
	private["_dbType","_createType"];
	_dbType = _this;
	_createType = _dbType;
	if (_dbType == "wooden_shed_lvl_1") then {_createType = "Uroven1DrevenaBudka";};
	if (_dbType == "log_house_lvl_2") then {_createType = "Uroven2KladaDomek";};
	if (_dbType == "wooden_house_lvl_3") then {_createType = "Uroven3DrevenyDomek";};
	if (_dbType == "large_shed_lvl_1") then {_createType = "Uroven1VelkaBudka";};
	if (_dbType == "small_house_lvl_2") then {_createType = "Uroven2MalyDomek";};
	if (_dbType == "big_house_lvl_3") then {_createType = "Uroven3VelkyDomek";};
	if (_dbType == "small_garage") then {_createType = "malaGaraz";};
	if (_dbType == "big_garage") then {_createType = "velkaGaraz";};
	_createType
};

_a2edcHouseDbType = {
	private["_objType","_dbType"];
	_objType = _this;
	_dbType = _objType;
	if (_objType == "Uroven1VelkaBudka") then {_dbType = "large_shed_lvl_1";};
	_dbType
};

_a2edcHouseAnimationSource = {
    private["_selection","_objectType","_source"];
    _selection = _this select 0;
    _objectType = _this select 1;
    _source = _selection;
    if (_selection == "stage_1") then {_source = "stupenJeden";};
    if (_selection == "stage_2") then {_source = "stupenDva";};
    if (_selection == "stage_2_hide") then {_source = "stupenDvaSkryt";};
    if (_selection == "stage_3") then {_source = "stupenTri";};
    if (_selection == "stage_4") then {_source = "stupen4tiri";};
    if (_selection == "upgrd_1_stage_1") then {_source = "povyseniJednaStupenJeden";};
    if (_selection == "upgrd_1_stage_2") then {_source = "povyseniDvaStupenDruhy";};
    if (_selection == "upgrd_1_stage_3") then {_source = "povyseniTriStupenTreti";};
    if (_selection == "upgrd_1_stage_4") then {_source = "povyseniJednaStupen4tvrty";};
    if (_selection == "upgrd_1_hide_1") then {_source = "povyseniJednaSkrytJedna";};
    if (_selection == "upgrd_1_show_1") then {_source = "povyseniJednaPojevitJedna";};
	_source
};

_a2edcGetCfgText = {
	private["_cfg","_field","_value"];
	_cfg = _this select 0;
	_field = _this select 1;
	_value = "";
	if (isClass _cfg) then {_value = getText (_cfg >> _field);};
	_value
};

_a2edcGetCfgNumber = {
	private["_cfg","_field","_value"];
	_cfg = _this select 0;
	_field = _this select 1;
	_value = -1;
	if (isClass _cfg) then {_value = getNumber (_cfg >> _field);};
	_value
};

_a2edcServerContains = {
	private["_needleChars","_haystackChars","_needleCount","_haystackCount","_found","_match","_i","_j"];
	_needleChars = toArray (toLower (_this select 0));
	_haystackChars = toArray (toLower (_this select 1));
	_needleCount = count _needleChars;
	_haystackCount = count _haystackChars;
	_found = (_needleCount == 0);
	if (_needleCount <= _haystackCount && !_found) then {
		for "_i" from 0 to (_haystackCount - _needleCount) do {
			_match = true;
			for "_j" from 0 to (_needleCount - 1) do {
				if ((_haystackChars select (_i + _j)) != (_needleChars select _j)) exitWith {_match = false;};
			};
			if (_match) exitWith {_found = true;};
		};
	};
	_found
};

_anim = {
_objectF = _this select 0;
_stageArF = _this select 1;
{
_selection = _x select 0;
_dam = _x select 1;
if(_selection != "passwordtut") then {
if (_dam == 9999999) then {
_objectF setVariable ["Name",_selection,false];
_objectF setVariable ["PName",_selection,true];
} else {
_animSource = [_selection,typeOf _objectF] call _a2edcHouseAnimationSource;
diag_log format ["A2EDC:HOUSE_STAGE_ANIMATION_SOURCE source=server_wantbbplz object=%1 typeOf=%2 logicalSelection=%3 animationSource=%4 value=%5",_objectF,typeOf _objectF,_selection,_animSource,_dam];
diag_log format ["A2EDC:HOUSE_STAGE_ANIMATION_APPLY source=server_wantbbplz object=%1 typeOf=%2 logicalSelection=%3 animationSource=%4 value=%5 mapped=%6 evidence=p3d_animation_name",_objectF,typeOf _objectF,_selection,_animSource,_dam,(_animSource != _selection)];
_objectF animate [_animSource,_dam];
};
} else {
_objectF setVariable ["passwordtut",_dam,false];
};
diag_log format ["_selection=%1,_dam=%2",_selection,_dam];
} forEach _stageArF;
};

_GivName = {
_text = _this select 0;
_tA = toArray _text;
_tA2 = [];
_count = 0;
{
if (_x == 34) then { _x = 39; };
_tA2 set [_count,_x];
_count = _count + 1;
} forEach _tA;
_tT = toString _tA2;
_tT;
};

_basebbm = {
_playerIDs = _this select 0;
_bbases = [];

if (_playerID in bb_base_level1b) then { _bbases set [0,1]; } else { _bbases set [0,0]; };
if (_playerID in bb_base_level2b) then { _bbases set [1,1]; } else { _bbases set [1,0]; };
if (_playerID in bb_base_level3b) then { _bbases set [2,1]; } else { _bbases set [2,0]; };





if (_playerID in bb_base_level1g) then { _bbases set [3,1]; } else { _bbases set [3,0]; };
if (_playerID in bb_base_level2g) then { _bbases set [4,1]; } else { _bbases set [4,0]; };

if (_playerID in bb_base_level1f) then { _bbases set [5,1]; } else { _bbases set [5,0]; };
if (_playerID in bb_base_level2f) then { _bbases set [6,1]; } else { _bbases set [6,0]; };
if (_playerID in bb_base_level3f) then { _bbases set [7,1]; } else { _bbases set [7,0]; };

_bbases;
};

diag_log format ["LOG_BB _player=%1(%2),_item=%3(%4),",_player,typeName _player,_item,typeName _item];
if (!(_typN1 == "OBJECT")) exitWith { diag_log format ["ERROR_BB Player is not OBJECT(%1, %2)",_player,_item]; };
_playerID =	getPlayerUID _player;
_pNameR = [name _player] call _GivName;
if (_playerID != _playerIDc) exitWith { diag_log format ["ERROR_BB Wrong _playerIDc(%4) recived from %1, %2, %3",_playerID,_player,_item,_playerIDc]; };

_stageAr =  [];
if (_typN2 == "STRING") then {
diag_log format ["A2EDC:HOUSE_FOUNDATION_REQUEST_RECEIVED payload=%1 player=%2 playerUID=%3 blueprint=%4 payloadCount=%5",_this,_player,_playerID,_item,count _this];
if ((count _this) != 5) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_SERVER_REJECT payload=%1 reason=foundation_request_requires_confirmed_position_and_direction",_this];
};
_requestedPos = _this select 3;
_requestedDir = _this select 4;
_placementValid = ((typeName _requestedPos) == "ARRAY") && {(count _requestedPos) == 3} && {((typeName _requestedDir) == "SCALAR")};
_placementReason = if (_placementValid) then {"shape_valid"} else {"invalid_payload_shape"};
if (_placementValid && {_player distance _requestedPos > 20}) then {_placementValid = false; _placementReason = "confirmed_position_too_far_from_player";};
if (_placementValid && {isOnRoad _requestedPos}) then {_placementValid = false; _placementReason = "confirmed_position_on_road";};
_placementHouses = if (_placementValid) then {nearestObjects [_requestedPos,["wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"],15]} else {[]};
if (_placementValid && {(count _placementHouses) > 0}) then {_placementValid = false; _placementReason = "confirmed_position_house_within_15m";};
_placementTents = if (_placementValid) then {nearestObjects [_requestedPos,["TentStorage","TentStorageR"],15]} else {[]};
_placementRealTents = [];
{
	if (!((_x getVariable ["A2EDC_adminTempObject",false]) && {(_x getVariable ["A2EDC_adminBuildingKit",""]) != ""})) then {
		_placementRealTents set [count _placementRealTents,_x];
	};
} forEach _placementTents;
if (_placementValid && {(count _placementRealTents) > 0}) then {_placementValid = false; _placementReason = "confirmed_position_storage_or_tent_within_15m";};
_placementCityObjects = if (_placementValid) then {nearestObjects [_requestedPos,["House"],150]} else {[]};
_placementCityBlockers = [];
if (_placementValid) then {
	{
		_placementType = typeOf _x;
		_placementModel = getText (configFile >> "CfgVehicles" >> _placementType >> "model");
		_placementCombined = toLower (_placementType + " " + _placementModel);
		_placementIsLand = ["land_",_placementType] call _a2edcServerContains;
		_placementIsUtility = (_placementType in ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor","Land_majak","Land_majak_podesta","Land_majak2","small_bunker"]);
		if (!_placementIsUtility) then {
			{if ([_x,_placementCombined] call _a2edcServerContains) exitWith {_placementIsUtility = true;};} forEach ["land_radio_box","radio_box","sloup","telek","timbers","deerstand","rail_zavora","rail_semafor","majak","small_bunker"];
		};
		_placementIsCoastal = false;
		{if ([_x,_placementCombined] call _a2edcServerContains) exitWith {_placementIsCoastal = true;};} forEach ["land_nav_boathouse_piert","nav_boathouse_pier","nav_boathouse_piert","boathouse_pier"];
		if (_placementIsLand && !_placementIsUtility && !_placementIsCoastal) then {_placementCityBlockers set [count _placementCityBlockers,_x];};
	} forEach _placementCityObjects;
};
if (_placementValid && {(count _placementCityBlockers) > 0}) then {_placementValid = false; _placementReason = "confirmed_position_city_house_within_150m";};
_placementNature = if (_placementValid) then {nearestObjects [_requestedPos,[],15]} else {[]};
if (_placementValid) then {
	{
		if ((["t_",str(_x)] call _a2edcServerContains) || {(["r2_",str(_x)] call _a2edcServerContains)}) exitWith {_placementValid = false; _placementReason = "confirmed_position_tree_or_rock";};
	} forEach _placementNature;
};
diag_log format ["A2EDC:HOUSE_PREVIEW_SERVER_VALIDATE payload=%1 valid=%2 reason=%3 requestedPos=%4 requestedDir=%5 playerPos=%6 playerDistance=%7 nearbyHouses=%8 nearbyTents=%9 realTents=%10 ignoredAdminTempTents=%11 cityObjects=%12 cityBlockers=%13 natureObjects=%14",_this,_placementValid,_placementReason,_requestedPos,_requestedDir,getPosATL _player,_player distance _requestedPos,count _placementHouses,count _placementTents,count _placementRealTents,(count _placementTents) - (count _placementRealTents),count _placementCityObjects,count _placementCityBlockers,count _placementNature];
_placementMixers = position _player nearObjects ["CementMixer",15];
_placementMaterialValid = (count _placementMixers) == 1;
_placementMissing = [];
_placementRequired = [];
if (_item in ["ItemBpt_b1","ItemBpt_h1","ItemBpt_b2","ItemBpt_h2"]) then {_placementRequired = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2]];};
if (_item in ["ItemBpt_b3","ItemBpt_h3"]) then {_placementRequired = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2],["ItemCinderblocks",5]];};
if (_item == "ItemBpt_g_s") then {_placementRequired = [["ItemRocks",25],["PartWoodPile",25],["PartScrap",5],["ItemCementBag",5]];};
if (_item == "ItemBpt_g_b") then {_placementRequired = [["ItemRocks",45],["PartWoodPile",45],["PartScrap",5],["ItemCementBag",10],["ItemCinderblocks",10]];};
if (_placementMaterialValid) then {
	_placementMixer = _placementMixers select 0;
	_placementCargo = getMagazineCargo _placementMixer;
	_placementCargoTypes = _placementCargo select 0;
	_placementCargoQty = _placementCargo select 1;
	{
		_placementRequiredClass = _x select 0;
		_placementRequiredQty = _x select 1;
		_placementFoundQty = 0;
		for "_placementCargoIndex" from 0 to ((count _placementCargoTypes) - 1) do {
			if ((_placementCargoTypes select _placementCargoIndex) == _placementRequiredClass) then {_placementFoundQty = _placementFoundQty + (_placementCargoQty select _placementCargoIndex);};
		};
		if (_placementFoundQty < _placementRequiredQty) then {_placementMissing set [count _placementMissing,[_placementRequiredClass,_placementRequiredQty,_placementFoundQty]];};
	} forEach _placementRequired;
	_placementMaterialValid = (count _placementMissing) == 0;
};
if (_placementValid && {!_placementMaterialValid}) then {_placementValid = false; _placementReason = "confirmed_cement_mixer_material_validation_failed";};
diag_log format ["A2EDC:HOUSE_FOUNDATION_REQUEST_PAYLOAD payload=%1 payloadCount=%2 payloadType=%3 player=%4 playerUID=%5 blueprint=%6 requestedPos=%7 requestedDir=%8",_this,count _this,typeName _this,_player,_playerID,_item,_requestedPos,_requestedDir];
diag_log format ["A2EDC:HOUSE_FOUNDATION_SERVER_VALIDATE payload=%1 valid=%2 reason=%3 player=%4 playerUID=%5 blueprint=%6 requestedPos=%7 requestedDir=%8 cementMixerCount=%9 materialValid=%10 required=%11 missing=%12",_this,_placementValid,_placementReason,_player,_playerID,_item,_requestedPos,_requestedDir,count _placementMixers,_placementMaterialValid,_placementRequired,_placementMissing];
if (!_placementValid) exitWith {
	diag_log format ["A2EDC:HOUSE_FOUNDATION_SERVER_VALIDATE_FAIL payload=%1 valid=false reason=%2 player=%3 playerUID=%4 blueprint=%5 requestedPos=%6 requestedDir=%7 cementMixerCount=%8 materialValid=%9 missing=%10",_this,_placementReason,_player,_playerID,_item,_requestedPos,_requestedDir,count _placementMixers,_placementMaterialValid,_placementMissing];
	diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=false stage=1 reason=server_confirmed_placement_rejected missingSummary=[] materialRemoved=false details=%1",_placementReason];
};
_stopGo = false;
if (!(_item in ["ItemBpt_b1","ItemBpt_b2","ItemBpt_b3","ItemBpt_h1","ItemBpt_h2","ItemBpt_h3","ItemBpt_g_s","ItemBpt_g_b"])) exitWith { diag_log format ["ERROR_BB Wrong _item(%1) recived from %2",_item,_playerID]; _stopGo = true; };
if (!_stopGo) then {




if (_item == "ItemBpt_b1") then {
if (_playerID in bb_base_level1b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 1b(%2)",_playerID,_item]; };

_housetype = "wooden_shed_lvl_1"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],[_pNameR,9999999]];

};
if (_item == "ItemBpt_b2") then {
if (!(_playerID in bb_base_level1b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b for 2b(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 2b(%2)",_playerID,_item]; };
if (_playerID in bb_base_level2b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 2b(%2)",_playerID,_item]; };
_housetype = "log_house_lvl_2"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
};
if (_item == "ItemBpt_b3") then {
if (!(_playerID in bb_base_level1b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b for 3b(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level2b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b for 3b(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 3h(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level2f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b finished for 3b(%2)",_playerID,_item]; };
if (_playerID in bb_base_level3b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 3b(%2)",_playerID,_item]; };
_housetype = "wooden_house_lvl_3"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",1],[_pNameR,9999999]];

};

	if (_item == "ItemBpt_h1") then {
	if (_playerID in bb_base_level1b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 1h(%2)",_playerID,_item]; };
	_housetype = "large_shed_lvl_1"; _levelhouse = 1;
	diag_log format ["A2EDC:HOUSE_BUILD_RECIPE blueprint=%1 targetBuilding=%2 stage=%3 required=%4",_item,_housetype,1,[["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2]]];
	_canBuildH = true;
	_stageAr = [["stage_1",0],["stage_2",1],[_pNameR,9999999]];
	};
if (_item == "ItemBpt_h2") then {
if (!(_playerID in bb_base_level1b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b for 2h(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 2h(%2)",_playerID,_item]; };
if (_playerID in bb_base_level2b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 2h(%2)",_playerID,_item]; };
_housetype = "small_house_lvl_2"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],["stage_2_hide",1],[_pNameR,9999999]];
};
if (_item == "ItemBpt_h3") then {
if (!(_playerID in bb_base_level1b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b for 3h(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b for 3h(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 3h(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level2f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b finished for 3h(%2)",_playerID,_item]; };
if (_playerID in bb_base_level3b) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have level 3h(%2)",_playerID,_item]; };
_housetype = "big_house_lvl_3"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",1],[_pNameR,9999999]];
};

if (_item == "ItemBpt_g_s") then {
if (!(_playerID in bb_base_level1b) && !(_playerID in bb_base_level2b)&& !(_playerID in bb_base_level3b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b,1h for 1g(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 1g(%2)",_playerID,_item]; };
if (_playerID in bb_base_level1g) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have small g(%2)",_playerID,_item]; };
_housetype = "small_garage"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
};
if (_item == "ItemBpt_g_b") then {
if (!(_playerID in bb_base_level3b)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 3b,3h for 2g(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for 2g(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level2f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b finished for 2g(%2)",_playerID,_item]; };
if (!(_playerID in bb_base_level3f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 3b finished for 2g(%2)",_playerID,_item]; };
if (_playerID in bb_base_level2g) exitWith { diag_log format ["ERROR_BB _playerID(%1) already have big g(%2)",_playerID,_item]; };
_housetype = "big_garage"; _levelhouse = 1;
_canBuildH = true;
_stageAr = [["stage_1",0],["stage_2",1],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
};

if (_canBuildH) then {
	diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=server_cement_mixer scanSource=cement mixer scanRadius=%1 playerPos=%2 buildPos=%3",15,getPosATL _player,_requestedPos];
	_findMix = position _player nearObjects ["CementMixer",15];
	_listMix = 	count _findMix == 1;
	diag_log format ["_findMix=%1",_findMix];
	{
		diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_x,typeOf _x,_player distance _x,_requestedPos distance _x,isNull _x,count ((getMagazineCargo _x) select 0),_listMix,"server_cement_mixer_candidate"];
	} forEach _findMix;
	if (_listMix) then {
	diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",true,1,"server_foundation_build_mixer_deleted",[],true];
	deleteVehicle (_findMix select 0);
if (_item in ["ItemBpt_b1","ItemBpt_h1"]) then {bb_base_level1b set [count bb_base_level1b,_playerID];};
if (_item in ["ItemBpt_b2","ItemBpt_h2"]) then {bb_base_level2b set [count bb_base_level2b,_playerID];};
if (_item in ["ItemBpt_b3","ItemBpt_h3"]) then {bb_base_level3b set [count bb_base_level3b,_playerID];};
if (_item == "ItemBpt_g_s") then {bb_base_level1g set [count bb_base_level1g,_playerID];};
if (_item == "ItemBpt_g_b") then {bb_base_level2g set [count bb_base_level2g,_playerID];};
diag_log format ["A2EDC:HOUSE_BUILD_PERMISSION_COMMIT item=%1 playerID=%2 reason=confirmed_placement_valid_and_mixer_consumed",_item,_playerID];

_bb_baseserver = [_playerID] call _basebbm;
_player setVariable["bb_base",_bb_baseserver,true];

_posit = +_requestedPos;
diag_log format ["_posit=%1",_posit];
_posit set [2,0];
_dir = round(_requestedDir);
diag_log format ["LOG_BB2 _playerID(%1),item(%2),%3,%4",_playerID,_item,_player,_bb_baseserver];

_createClass = _housetype call _a2edcHouseCreateClass;
_createCfg = configFile >> "CfgVehicles" >> _createClass;
_dbCfg = configFile >> "CfgVehicles" >> _housetype;
_createIsClass = isClass _createCfg;
_dbIsClass = isClass _dbCfg;
_createScope = [_createCfg,"scope"] call _a2edcGetCfgNumber;
_dbScope = [_dbCfg,"scope"] call _a2edcGetCfgNumber;
_createSimulation = [_createCfg,"simulation"] call _a2edcGetCfgText;
_dbSimulation = [_dbCfg,"simulation"] call _a2edcGetCfgText;
_createVehicleClass = [_createCfg,"vehicleClass"] call _a2edcGetCfgText;
_dbVehicleClass = [_dbCfg,"vehicleClass"] call _a2edcGetCfgText;
_createModel = [_createCfg,"model"] call _a2edcGetCfgText;
_dbModel = [_dbCfg,"model"] call _a2edcGetCfgText;
_stageSelections = [];
{_stageSelections set [count _stageSelections,_x select 0];} forEach _stageAr;

diag_log format ["A2EDC:HOUSE_FOUNDATION_CLASS requestedBlueprint=%1 dbHouseType=%2 runtimeClass=%3 createVehicleClass=%4 expectedRole=foundation_stage_object stageAr=%5",_item,_housetype,_createClass,_createClass,_stageAr];
diag_log format ["A2EDC:HOUSE_SERVER_CREATE_BEGIN requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 playerUID=%5 position=%6 direction=%7 stageAr=%8",_item,_housetype,_createClass,_createClass,_playerID,_posit,_dir,_stageAr];
diag_log format ["A2EDC:HOUSE_SERVER_CREATE_CLASS_CHECK requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 dbIsClass=%5 createIsClass=%6 dbScope=%7 createScope=%8 dbSimulation=%9 createSimulation=%10 dbVehicleClass=%11 createVehicleClassCfg=%12 dbModel=%13 createModel=%14 position=%15 direction=%16",_item,_housetype,_createClass,_createClass,_dbIsClass,_createIsClass,_dbScope,_createScope,_dbSimulation,_createSimulation,_dbVehicleClass,_createVehicleClass,_dbModel,_createModel,_posit,_dir];
if (!_createIsClass) exitWith {
	diag_log format ["A2EDC:HOUSE_SERVER_CREATE_FAIL requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 isClass=false position=%5 direction=%6 hiveWrite=false reason=create_class_missing",_item,_housetype,_createClass,_createClass,_posit,_dir];
};
diag_log format ["A2EDC:HOUSE_SERVER_CREATE_ATTEMPT requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 position=%5 direction=%6",_item,_housetype,_createClass,_createClass,_posit,_dir];

_object = createVehicle [_createClass, _posit, [], 0, "CAN_COLLIDE"];
_objectIsNull = isNull _object;
diag_log format ["A2EDC:HOUSE_FOUNDATION_CREATE requestedBlueprint=%1 dbHouseType=%2 runtimeClass=%3 object=%4 isNull=%5 typeOf=%6 position=%7 direction=%8",_item,_housetype,_createClass,_object,_objectIsNull,if (_objectIsNull) then {"<null>"} else {typeOf _object},_posit,_dir];
diag_log format ["A2EDC:HOUSE_SERVER_CREATE_RESULT requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 resultObject=%5 isNull=%6 typeOf=%7 position=%8 direction=%9",_item,_housetype,_createClass,_createClass,_object,_objectIsNull,if (_objectIsNull) then {"<null>"} else {typeOf _object},_posit,_dir];
if (_objectIsNull) exitWith {
	diag_log format ["A2EDC:HOUSE_SERVER_CREATE_FAIL requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 resultObject=%5 isNull=true position=%6 direction=%7 hiveWrite=false reason=create_returned_null",_item,_housetype,_createClass,_createClass,_object,_posit,_dir];
};
_object setdir _dir;
_object setpos _posit;
_vector = vectorUp _object;
diag_log format ["A2EDC:HOUSE_FOUNDATION_INIT_BEGIN object=%1 typeOf=%2 model=%3 dbHouseType=%4 runtimeClass=%5 owner=%6 stageAr=%7",_object,typeOf _object,getText (configFile >> "CfgVehicles" >> typeOf _object >> "model"),_housetype,_createClass,_playerID,_stageAr];
[_object, _stageAr] call _anim;
diag_log format ["A2EDC:HOUSE_SERVER_STAGE_SELECTIONS requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 object=%5 typeOf=%6 selections=%7 stageAr=%8",_item,_housetype,_createClass,_createClass,_object,typeOf _object,_stageSelections,_stageAr];


_player reveal _object;
_worldspace = [_dir,_posit,_vector];

_uid = _worldspace call dayz_objectUID2;


_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",dayZ_instance, _housetype, 0, _playerID, _worldspace, [], _stageAr, 0,_uid];
diag_log format ["A2EDC:HOUSE_SERVER_HIVE_WRITE requestedBlueprint=%1 dbHouseType=%2 createVehicleClass=%3 mappedVisualClass=%4 object=%5 isNull=%6 typeOf=%7 keyOpcode=308 worldspace=%8 uid=%9 stageAr=%10 hiveWrite=true",_item,_housetype,_createClass,_createClass,_object,isNull _object,typeOf _object,_worldspace,_uid,_stageAr];

_key call server_hiveWrite;

ori_servObjMonitor set [count ori_servObjMonitor,_object];
diag_log format ["A2EDC:HOUSE_FOUNDATION_MONITOR_ADD object=%1 typeOf=%2 dbHouseType=%3 monitor=ori_servObjMonitor monitorCount=%4",_object,typeOf _object,_housetype,count ori_servObjMonitor];

_object setVariable ["A2EDC_DBHouseType",_housetype,true];
diag_log format ["A2EDC:HOUSE_FOUNDATION_SET_VAR object=%1 typeOf=%2 dbHouseType=%3 variable=A2EDC_DBHouseType value=%4 public=true",_object,typeOf _object,_housetype,_housetype];
_object setVariable ["A2EDC_CreateClass",_createClass,true];
diag_log format ["A2EDC:HOUSE_FOUNDATION_SET_VAR object=%1 typeOf=%2 dbHouseType=%3 variable=A2EDC_CreateClass value=%4 public=true",_object,typeOf _object,_housetype,_createClass];
_object setVariable ["Name",_pNameR,false];
_object setVariable ["Slevelhouse",_levelhouse,false];
_object setVariable ["HObjectID", 0, false];
_object setVariable ["SOwner", _playerID, false];
_object setVariable ["lastUpdate",time];

_object setVariable ["PName",_pNameR,true];
_object setVariable ["levelhouse",_levelhouse,true];

_object setVariable ["ObjectUID", _uid, true];
    _object setVariable ["CharacterID", _playerID, true];
    diag_log format ["A2EDC:HOUSE_FOUNDATION_PUBLISH_INIT object=%1 typeOf=%2 dbHouseType=%3 objectID=%4 objectUID=%5 owner=%6 levelhouse=%7 hObjectID=%8 sOwner=%9 lastUpdate=%10",_object,typeOf _object,_housetype,_object getVariable ["ObjectID","<missing>"],_object getVariable ["ObjectUID","<missing>"],_object getVariable ["CharacterID","<missing>"],_object getVariable ["levelhouse","<missing>"],_object getVariable ["HObjectID","<missing>"],_object getVariable ["SOwner","<missing>"],_object getVariable ["lastUpdate","<missing>"]];
    diag_log format ["A2EDC:HOUSE_FOUNDATION_CARGO_CAPACITY object=%1 typeOf=%2 dbHouseType=%3 transportMaxMagazines=%4 transportMaxWeapons=%5 transportMaxBackpacks=%6",_object,typeOf _object,_housetype,getNumber (configFile >> "CfgVehicles" >> typeOf _object >> "transportMaxMagazines"),getNumber (configFile >> "CfgVehicles" >> typeOf _object >> "transportMaxWeapons"),getNumber (configFile >> "CfgVehicles" >> typeOf _object >> "transportMaxBackpacks")];
    diag_log format ["A2EDC:HOUSE_FOUNDATION_INIT_DONE object=%1 typeOf=%2 model=%3 dbHouseType=%4 runtimeClass=%5 objectID=%6 objectUID=%7 owner=%8 stageAr=%9 monitorCount=%10",_object,typeOf _object,getText (configFile >> "CfgVehicles" >> typeOf _object >> "model"),_housetype,_createClass,_object getVariable ["ObjectID","<missing>"],_object getVariable ["ObjectUID","<missing>"],_playerID,_stageAr,count ori_servObjMonitor];
	diag_log format ["_housetype=%1,_playerID=%2,_stageAr=%3,_worldspace=%4",_housetype,_playerID,_stageAr,_worldspace];
	} else { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"server_cement_mixer_not_found_or_not_unique",[],false]; diag_log format ["Mixer not found %1(%2)",_findMix,_listMix]; };
	} else { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"server_build_permission_failed",[],false]; diag_log format ["ERROR _housetype=%1,_playerID=%2,_stageAr=%3,_worldspace=%4",_housetype,_playerID,_stageAr,_worldspace]; };
	};
};

if (_typN2 == "SCALAR") then {
_conti = count (_this) == 5;
diag_log format ["START_UPG _this = %1",_this];
if (!_conti) then { diag_log format ["ERROR_UPG Recive bad data (%1)",_this];  } else {
_object = _this select 3;
_password = _this select 4;
diag_log format ["A2EDC:HOUSE_STAGE2_SERVER_REQUEST_RECEIVED payload=%1 object=%2 requestedLevel=%3 player=%4 playerID=%5 passwordType=%6",_this,_object,_item,_player,_playerID,typeName _password];
	diag_log format ["A2EDC:HOUSE_BUILD_ACTION item=%1 action=server_stage_upgrade uid=%2 player=%3 playerPos=%4 cursorTarget=%5 selectedBlueprint=%6 selectedBuilding=%7",_item,_playerID,_player,getPosATL _player,_object,"",typeOf _object];
_slevel = _object getVariable ["Slevelhouse",0];
_sOwners = _object getVariable ["SOwner","Net"];
_sObjId = _object getVariable ["HObjectID","0"];
_gObjId = _object getVariable ["ObjectID","0"];
_objType = _object getVariable ["A2EDC_DBHouseType",typeOf _object];
_objType = _objType call _a2edcHouseDbType;
_hiry = getMagazineCargo _object;
diag_log format ["A2EDC:HOUSE_STAGE2_SOURCE_EXPECTED action=server_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 owner=%5 objectID=%6 hObjectID=%7 uid=%8 expectedSource=%9",_object,typeOf _object,_objType,_slevel,_sOwners,_gObjId,_sObjId,_object getVariable ["ObjectUID","0"],"house_cargo"];
diag_log format ["A2EDC:HOUSE_STAGE2_CARGO_BEGIN action=server_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 owner=%5 objectID=%6 hObjectID=%7 uid=%8 expectedSource=house_cargo",_object,typeOf _object,_objType,_slevel,_sOwners,_gObjId,_sObjId,_object getVariable ["ObjectUID","0"]];
diag_log format ["A2EDC:HOUSE_STAGE2_CARGO_CHECK action=server_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 cargoMagazinesCount=%5 cargo=%6",_object,typeOf _object,_objType,_slevel,count (_hiry select 0),_hiry];
_zapiskavDB = false;
if (typeName _sObjId != "STRING") then {
_slevel = 0;
diag_log format ["ERROR_UPG _sObjId(%1)",_sObjId];
diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=identity reason=hObjectID_not_string object=%1 hObjectID=%2 objectID=%3",_object,_sObjId,_gObjId];
};
_nextlevel = _slevel + 1;
if (_item != _nextlevel) then { diag_log format ["ERROR_UPG House level error (%3)(%1)!=(%2)(%4)",_item,_slevel,typeName _item,typeName _slevel]; diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=stage reason=requested_level_mismatch requestedLevel=%1 currentLevel=%2 nextLevel=%3 object=%4",_item,_slevel,_nextlevel,_object]; _slevel = 0; };
if (_playerID != _sOwners) then { diag_log format ["ERROR_UPG House Owner  (%1)!=(%2)",_playerID,_sOwners]; diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=owner reason=owner_mismatch playerID=%1 owner=%2 object=%3",_playerID,_sOwners,_object]; _slevel = 0; };
if (_sObjId != _gObjId) then { diag_log format ["ERROR_UPG House ObjectID  (%1)!=(%2)",_sObjId,_gObjId]; diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=identity reason=objectid_mismatch hObjectID=%1 objectID=%2 object=%3",_sObjId,_gObjId,_object]; _slevel = 0; };
if (typeName _password != "SCALAR") then { diag_log format ["ERROR_UPG _pass(%1)!=SCALAR,%2,%3,%4",_password,_playerID,_sObjId,_gObjId]; diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=password reason=password_not_scalar passwordType=%1 object=%2",typeName _password,_object]; _slevel = 0; };
if (_slevel != 0) then {
_objType = _object getVariable ["A2EDC_DBHouseType",typeOf _object];
_objType = _objType call _a2edcHouseDbType;
diag_log format ["A2EDC:HOUSE_STAGE2_SOURCE_EXPECTED action=server_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 owner=%5 objectID=%6 uid=%7 expectedSource=house_cargo",_object,typeOf _object,_objType,_slevel,_sOwners,_gObjId,_object getVariable ["ObjectUID","0"]];
if (!(_objType in ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"])) then { diag_log format ["ERROR_BB Wrong _item(%1) recived from %2",_item,_playerID]; } else {

if ((_objType == "wooden_shed_lvl_1") OR (_objType == "large_shed_lvl_1")) then {
if (!(_playerID in bb_base_level1b)) then { diag_log format ["ERROR_UPG _playerID not in level 1b (%1)!=(%2)",_playerID,bb_base_level1b];
} else {
if (_nextlevel == 2) then {
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
} else { diag_log format ["ERROR_UPG _password , level(%3) 1b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 1b (%1),(%2)",_playerID,_password,_nextlevel]; };
};

};
};

if ((_objType == "log_house_lvl_2") OR (_objType == "small_house_lvl_2")) then {
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for UPG 2borh(%2)",_playerID,bb_base_level1b]; };
if (!(_playerID in bb_base_level2b)) then { diag_log format ["ERROR_UPG _playerID not in level 2b (%1)!=(%2)",_playerID,bb_base_level2b];
} else {
if (_nextlevel == 2) then {
if (_objType == "log_house_lvl_2") then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
diag_log format ["OK_UPG = %1(p=-),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId];
_zapiskavDB = true;
} else {
_stageAr = [["stage_1",0],["stage_2",0],["stage_2_hide",0],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
diag_log format ["OK_UPG = %1(p=-),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId];
_zapiskavDB = true;
};

};
if (_nextlevel == 3) then {
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
if (_objType == "log_house_lvl_2") then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",1],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
} else {
_stageAr = [["stage_1",0],["stage_2",0],["stage_2_hide",1],["stage_3",0],["stage_4",1],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
_object setVariable ["passwordtut",_password,false];
} else { diag_log format ["ERROR_UPG _password , level(%3) 2b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 2b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
if (_nextlevel == 4) then {
_password = _object getVariable ["passwordtut",0];
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
if (_objType == "log_house_lvl_2") then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
} else {
_stageAr = [["stage_1",0],["stage_2",0],["stage_2_hide",1],["stage_3",0],["stage_4",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 2b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 2b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
};
};

if ((_objType == "wooden_house_lvl_3") OR (_objType == "big_house_lvl_3")) then {
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for UPG 3borh(%2)",_playerID,bb_base_level1b]; };
if (!(_playerID in bb_base_level2f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 2b finished for UPG 3borh(%2)",_playerID,bb_base_level2b]; };
if (!(_playerID in bb_base_level3b)) then { diag_log format ["ERROR_UPG _playerID not in level 3b (%1)!=(%2)",_playerID,bb_base_level3b];
} else {
if (_nextlevel == 2) then {
if (_objType == "wooden_house_lvl_3") then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",1],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",1],[_pNameR,9999999]];
diag_log format ["OK_UPG = %1(p=-),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId];
_zapiskavDB = true;
} else {
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",1],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
_object setVariable ["passwordtut",_password,false];
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
};
if (_nextlevel == 3) then {
if (_objType == "wooden_house_lvl_3") then {
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
_object setVariable ["passwordtut",_password,false];
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else {
_password = _object getVariable ["passwordtut",0];
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",1],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
};
if (_nextlevel == 4) then {
_password = _object getVariable ["passwordtut",0];
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],["upgrd_1_stage_1",1],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
if ((_nextlevel >4)&&(_nextlevel<=8)) then {
_password = _object getVariable ["passwordtut",0];
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
if (_nextlevel == 5) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],["upgrd_1_stage_1",0],["upgrd_1_stage_2",1],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
if (_nextlevel == 6) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],["upgrd_1_stage_1",0],["upgrd_1_stage_2",0],["upgrd_1_stage_3",1],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
if (_nextlevel == 7) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],["upgrd_1_stage_1",0],["upgrd_1_stage_2",0],["upgrd_1_stage_3",0],["upgrd_1_stage_4",1],["upgrd_1_show_1",1],["upgrd_1_hide_1",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
if (_nextlevel == 8) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],["upgrd_1_stage_1",0],["upgrd_1_stage_2",0],["upgrd_1_stage_3",0],["upgrd_1_stage_4",0],["upgrd_1_show_1",0],["upgrd_1_hide_1",1],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
};
} else { diag_log format ["ERROR_UPG _password>=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) 3b (%1),(%2)",_playerID,_password,_nextlevel]; };
};
};
};

if ((_objType == "small_garage") OR (_objType == "big_garage")) then { _Ok = true;
if (!(_playerID in bb_base_level1f)) exitWith { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for UPG 1g(%2)",_playerID,bb_base_level1b]; };
if (_objType == "small_garage") then {
if (!(_playerID in bb_base_level4b)) then { diag_log format ["ERROR_UPG _playerID not in level 4b (%1)!=(%2)",_playerID,bb_base_level4b]; _Ok = false;  };
};
if (_objType == "big_garage") then {
if (!(_playerID in bb_base_level1f)) then { diag_log format ["ERROR_BB _playerID(%1) not have 1b finished for UPG 2g(%2)",_playerID,bb_base_level1b]; _Ok = false; };
if (!(_playerID in bb_base_level2f)) then { diag_log format ["ERROR_BB _playerID(%1) not have 2b finished for UPG 2g(%2)",_playerID,bb_base_level2b]; _Ok = false; };
if (!(_playerID in bb_base_level3f)) then { diag_log format ["ERROR_BB _playerID(%1) not have 3b finished for UPG 2g(%2)",_playerID,bb_base_level3b]; _Ok = false; };
if (!(_playerID in bb_base_level5b)) then { diag_log format ["ERROR_UPG _playerID not in level 5b (%1)!=(%2)",_playerID,bb_base_level5b]; _Ok = false; };
};
if (_Ok) then {
if (_nextlevel == 2) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",1],["stage_4",1],[_pNameR,9999999]];
diag_log format ["OK_UPG G = %1(p=-),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId];
_zapiskavDB = true;
};
if (_nextlevel == 3) then {
if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",1],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG G = %1(p=-),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId];
_zapiskavDB = true;
} else { diag_log format ["ERROR_UPG _password , level(%3) g (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) g (%1),(%2)",_playerID,_password,_nextlevel]; };
};
if (_nextlevel == 4) then {

if (_password != 0) then {
_Ok = (999999-_password)>=0;
if (_Ok) then {
_stageAr = [["stage_1",0],["stage_2",0],["stage_3",0],["stage_4",0],[_pNameR,9999999],["passwordtut",_password]];
diag_log format ["OK_UPG G = %1(p=%5),_nlvl=%2,_sObjId=%3,_gObjId=%4",_stageAr,_nextlevel,_sObjId,_gObjId,_password];
_zapiskavDB = true;
_object setVariable ["passwordtut",_password,false];
} else { diag_log format ["ERROR_UPG _password , level(%3) g (%1),(%2)",_playerID,_password,_nextlevel]; };
} else { diag_log format ["ERROR_UPG _password=0 , level(%3) g (%1),(%2)",_playerID,_password,_nextlevel]; };
};
};
};

if (_zapiskavDB) then {
	_bb_baseserver = [_playerID] call _basebbm;
    diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",true,_nextlevel,"server_upgrade_applied_clearMagazineCargoGlobal",[],true];
    diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=true gate=server_upgrade reason=upgrade_applied object=%1 dbHouseType=%2 oldLevel=%3 nextLevel=%4 objectID=%5 owner=%6",_object,_objType,_slevel,_nextlevel,_sObjId,_sOwners];
	clearMagazineCargoGlobal _object;
[_object, _stageAr] call _anim;
if ((_objType == "small_garage") OR (_objType == "big_garage")) then {
_object animate ["garage_gate_1",1];
_object animate ["garage_gate_2",1];
_object animate ["garage_door_la",1];
_object animate ["garage_door_ra",1];
};
_player setVariable["bb_base",_bb_baseserver,true];
_object setVariable ["Slevelhouse",_nextlevel,false];
_object setVariable ["levelhouse",_nextlevel,true];
_object setVariable ["SOwner", _sOwners, false];
_object setVariable ["HObjectID", _sObjId, false];
_object setVariable ["ObjectID", _sObjId, true];



diag_log format ["LOG2_UPG level(%3)p(%1)pid(%2),objID(%4)upAr(%5)",_playerID,_password,_nextlevel,_sObjId,_stageAr];

_key = format["CHILD:306:%1:%2:%3:",_sObjId,_stageAr,0];

_key call server_hiveWrite;

dayUpdateVehlcle = [_object,"gear"];
dayUpdateVehlcle call server_updatObiect;


        } else { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,_nextlevel,"server_upgrade_validation_failed",[],false]; diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=server_upgrade reason=stage_recipe_or_password_validation_failed object=%1 dbHouseType=%2 currentLevel=%3 nextLevel=%4 objectID=%5 owner=%6",_object,_objType,_slevel,_nextlevel,_sObjId,_sOwners]; diag_log format ["ERROR_UPG level(%3)p(%1)pid(%2),objID(%4)upAr(%5)",_playerID,_password,_nextlevel,_sObjId,_stageAr]; };
};
};

};
};
