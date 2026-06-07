private["_new","_itOKbu","_passwordN","_Ok","_invChe","_objectF","_house","_stage","_typeOF","_hiry","_hinv","_objWpnTypes","_objWpnQty","_countr","_vsegoMaterial","_bOk","_qtyR","_qtyW","_qtyS","_qtyC","_qtyB","_qtyP","_qtyL","_chePsw","_codeArray","_codeString","_status","_pcount","_playerID","_lopata","_hasToolbox","_hasBlueprint","_buildobj","_text","_isSurvi_p","_isHero1_p","_isHero2_p","_isBandit1_p","_isBandit2_p","_isBandit3_p","_humanityVP","_isHero3_p","_nhouse","_syOfh","_qtyT","_ctentb","_posit","_listBB","_findMix","_listMix","_recived","_object","_level","_type","_rawType","_nextlevelb","_objectID","_deagOK","_passUch","_stopGo","_ObjectUID","_builOk","_cityObjects","_modelPath","_isBroadHouse","_isExplicitUtility","_isUtilityPattern","_isCoastalPattern","_isLandClass","_isTrueBlocker","_cityReason","_a2edcUtilityNonBlockers","_a2edcCoastalNonBlockers","_a2edcIsUtilityNonBlocker","_a2edcIsCoastalNonBlocker","_a2edcGetModelPath","_cityGateFailed","_placementGateFailed","_placementBlockers","_placementRealBlockers","_placementIgnoredAdminTemp","_placementObject","_isAdminTemp","_adminKit","_adminStage","_isStage2TargetMissing","_stage2IdentityReady","_stage2RejectReason","_a2edcPlayerBbBase","_a2edcLoginElapsed","_a2edcLoginTimeSource","_a2edcPreviewClass","_a2edcPreviewRedClass","_a2edcPreviewGreenClass","_a2edcPreviewPos","_a2edcPreviewOldPos","_a2edcPreviewHiddenPos","_a2edcPreviewDir","_a2edcPreviewOldDir","_a2edcPreviewPlayerDir","_a2edcPreviewDeltaDist","_a2edcPreviewDeltaDir","_a2edcPreviewLoopIteration","_a2edcPreviewElapsed","_a2edcPreview","_a2edcPreviewMarker","_a2edcPreviewLastValid","_a2edcPreviewReason","_a2edcPreviewCityValid","_a2edcPreviewCityReason","_a2edcPreviewLastCityPos","_a2edcPreviewLastLogPos","_a2edcPreviewLastLogDir","_a2edcPreviewLogUpdate","_a2edcPreviewDirectionChanged","_a2edcPreviewLastTick","_a2edcPreviewTickGap","_a2edcPreviewLastHeartbeat","_a2edcPreviewStartTime","_a2edcPreviewContext","_a2edcConfirmAction","_a2edcCancelAction","_a2edcRotateLeftAction","_a2edcRotateRightAction","_a2edcPreviewHouses","_a2edcPreviewRealHouses","_a2edcPreviewNature","_a2edcPreviewObject","_a2edcPreviewColor","_a2edcPreviewLastColor"];
call gear_ui_init;
_new = typeName _this;
//diag_log format ["bse_pp _this=%1,_new=%2", _this,_new];
_itOKbu = false;
_stopGo = false;
ConstrSt = false;
CODEINPUT = [];
OrignBB = [];
CODE = "";
_Ok = false;
_deagOK = false;
_passUch = [0,false,"temp"];
_isSurvi_p = false; _isHero1_p = false; _isHero2_p = false; _isHero3_p = false; _isBandit1_p = false; _isBandit2_p = false; _isBandit3_p = false;
_humanityVP = 0;

_a2edcRecipe = {
	private["_house","_stage","_required"];
	_house = _this select 0;
	_stage = _this select 1;
	_required = [];
	if (_house == 1) then {
		if (_stage == 1) then {_required = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2]];};
		if (_stage == 2) then {_required = [["ItemRocks",25],["PartWoodPile",35],["PartScrap",4],["ItemCementBag",4],["ItemBattery",1],["ItemPin",1]];};
	};
	if (_house == 2) then {
		if (_stage == 1) then {_required = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2]];};
		if (_stage == 2) then {_required = [["ItemRocks",25],["PartWoodPile",35],["PartScrap",4],["ItemCementBag",4]];};
		if (_stage == 3) then {_required = [["ItemRocks",30],["PartWoodPile",45],["PartScrap",4],["ItemCementBag",4],["ItemBattery",1],["ItemPin",1]];};
		if (_stage == 4) then {_required = [["ItemRocks",35],["PartWoodPile",55],["PartScrap",4],["ItemCementBag",4]];};
	};
	if ((_house == 3)||(_house == 33)) then {
		if (_stage == 1) then {_required = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2],["ItemCinderblocks",5]];};
		if (_house == 3) then {
			if (_stage == 2) then {_required = [["ItemRocks",25],["PartWoodPile",35],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",10]];};
			if (_stage == 3) then {_required = [["ItemRocks",30],["PartWoodPile",45],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",15],["ItemBattery",1],["ItemPin",1]];};
		};
		if (_house == 33) then {
			if (_stage == 2) then {_required = [["ItemRocks",25],["PartWoodPile",35],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",10],["ItemBattery",1],["ItemPin",1]];};
			if (_stage == 3) then {_required = [["ItemRocks",30],["PartWoodPile",45],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",15]];};
		};
		if (_stage == 4) then {_required = [["ItemRocks",35],["PartWoodPile",55],["PartScrap",6],["ItemCementBag",4],["ItemCinderblocks",25]];};
		if (_stage == 5) then {_required = [["ItemRocks",15],["PartWoodPile",25],["PartScrap",2],["ItemCementBag",2],["ItemCinderblocks",5]];};
		if (_stage == 6) then {_required = [["ItemRocks",25],["PartWoodPile",35],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",10]];};
		if (_stage == 7) then {_required = [["ItemRocks",30],["PartWoodPile",45],["PartScrap",4],["ItemCementBag",4],["ItemCinderblocks",15],["ItemBattery",1],["ItemPin",1]];};
		if (_stage == 8) then {_required = [["ItemRocks",35],["PartWoodPile",55],["PartScrap",6],["ItemCementBag",4],["ItemCinderblocks",20]];};
	};
	if (_house == 4) then {
		if (_stage == 1) then {_required = [["ItemRocks",25],["PartWoodPile",25],["PartScrap",5],["ItemCementBag",5]];};
		if (_stage == 2) then {_required = [["ItemRocks",35],["PartWoodPile",35],["PartScrap",5],["ItemCementBag",5]];};
		if (_stage == 3) then {_required = [["ItemRocks",45],["PartWoodPile",45],["PartScrap",5],["ItemCementBag",5],["ItemBattery",1],["ItemPin",1]];};
		if (_stage == 4) then {_required = [["ItemRocks",55],["PartWoodPile",55],["PartScrap",5],["ItemCementBag",5]];};
	};
	if (_house == 5) then {
		if (_stage == 1) then {_required = [["ItemRocks",45],["PartWoodPile",45],["PartScrap",5],["ItemCementBag",10],["ItemCinderblocks",10]];};
		if (_stage == 2) then {_required = [["ItemRocks",55],["PartWoodPile",55],["PartScrap",5],["ItemCementBag",10],["ItemCinderblocks",20]];};
		if (_stage == 3) then {_required = [["ItemRocks",65],["PartWoodPile",65],["PartScrap",10],["ItemCementBag",20],["ItemBattery",1],["ItemPin",1],["ItemCinderblocks",30]];};
		if (_stage == 4) then {_required = [["ItemRocks",75],["PartWoodPile",75],["PartScrap",10],["ItemCementBag",20],["ItemCinderblocks",40]];};
	};
	_required;
};

_a2edcFoundCount = {
	private["_class","_qtyR","_qtyW","_qtyS","_qtyC","_qtyB","_qtyP","_qtyL","_found"];
	_class = _this select 0;
	_qtyR = _this select 1; _qtyW = _this select 2; _qtyS = _this select 3; _qtyC = _this select 4; _qtyB = _this select 5; _qtyP = _this select 6; _qtyL = _this select 7;
	_found = 0;
	if (_class == "ItemRocks") then {_found = _qtyR;};
	if (_class == "PartWoodPile") then {_found = _qtyW;};
	if (_class == "PartScrap") then {_found = _qtyS;};
	if (_class == "ItemCementBag") then {_found = _qtyC;};
	if (_class == "ItemBattery") then {_found = _qtyB;};
	if (_class == "ItemPin") then {_found = _qtyP;};
	if (_class == "ItemCinderblocks") then {_found = _qtyL;};
	_found;
};

_a2edcAlignment = {
	private["_humanity","_alignment"];
	_humanity = _this;
	_alignment = "unknown";
	if (_humanity > 2000 and _humanity < 2900) then {_alignment = "survivor";};
	if (_humanity >= 2900 and _humanity < 6500) then {_alignment = "hero_l1";};
	if (_humanity >= 6500 and _humanity <= 15000) then {_alignment = "hero_l2";};
	if (_humanity > 15000) then {_alignment = "hero_l3_plus";};
	if (_humanity > -6500 and _humanity <= 2000) then {_alignment = "bandit_l1";};
	if (_humanity >= -15000 and _humanity <= -6500) then {_alignment = "bandit_l2";};
	if (_humanity < -15000) then {_alignment = "bandit_l3_plus";};
	_alignment;
};

	_a2edcDebugFail = {
	private["_gate","_reason","_message","_details","_missingText","_entry"];
	_gate = _this select 0;
	_reason = _this select 1;
	_details = if ((count _this) > 2) then {_this select 2} else {[]};
	_message = "Build failed; see RPT";
	if (_gate == "humanity") then {_message = format ["Build failed: %1",_reason];};
	if (_gate == "bandit") then {_message = format ["Build failed: %1",_reason];};
	if (_gate == "materials") then {
		_message = format ["Build failed: missing materials (%1)",_reason];
		if (((typeName _details) == "ARRAY") && {(count _details) > 0}) then {
			_missingText = "";
			{
				_entry = _x;
				if (((typeName _entry) == "ARRAY") && {(count _entry) > 3}) then {
					if (_missingText != "") then {_missingText = _missingText + ", ";};
					_missingText = _missingText + format ["%1x %2",_entry select 3,_entry select 0];
				};
			} forEach _details;
			if (_missingText != "") then {_message = format ["Build failed: missing materials: %1",_missingText];};
		};
	};
		if (_gate == "distance") then {_message = format ["Build failed: distance gate: %1",_reason];};
		if (_gate == "location") then {_message = format ["Build failed: location gate: %1",_reason];};
		if (_gate == "city_check") then {_message = format ["Build failed: city check: %1",_reason];};
		if (_gate == "city_check" && _reason == "city house within 150m") then {_message = "Build failed: too close to city/house.";};
		if (_gate == "placement_blocker") then {_message = format ["Build failed: placement blocker: %1",_reason];};
		if (_gate == "placement_blocker" && _reason == "nearby storage/tent") then {_message = "Build failed: placement blocked by nearby storage/tent.";};
		if (_gate == "mixer_state") then {_message = format ["Build failed: CementMixer %1",_reason];};
		if (_gate == "object_publish") then {_message = format ["Build failed: object publish %1",_reason];};
		if (_gate == "server_request") then {_message = format ["Build failed: server request %1",_reason];};
		if (_gate == "blueprint") then {_message = format ["Build failed: blueprint %1",_reason];};
	if (_gate == "unknown") then {_message = "Build failed: unknown gate; see RPT";};
	diag_log format ["A2EDC:HOUSE_BUILD_FAIL_REASON gate=%1 reason=%2 details=%3 message=%4",_gate,_reason,_details,_message];
		titletext [_message, "PLAIN DOWN"];
	};

	_a2edcUtilityNonBlockers = ["land_radio_box","radio_box","sloup","telek","timbers","deerstand","rail_zavora","rail_semafor","majak","small_bunker"];
	_a2edcCoastalNonBlockers = ["land_nav_boathouse_piert","nav_boathouse_pier","nav_boathouse_piert","boathouse_pier"];
	_a2edcIsUtilityNonBlocker = {
		private["_class","_lcClass","_matched"];
		_class = _this;
		_lcClass = toLower _class;
		_matched = (_class in _builOk);
		if (!_matched) then {
			{
				if ([_x,_lcClass,false] call fnc_inString) exitWith {_matched = true;};
			} forEach _a2edcUtilityNonBlockers;
		};
		_matched
	};
	_a2edcIsCoastalNonBlocker = {
		private["_class","_model","_lcClass","_lcModel","_combined","_matched"];
		_class = _this select 0;
		_model = _this select 1;
		_lcClass = toLower _class;
		_lcModel = toLower _model;
		_combined = _lcClass + " " + _lcModel;
		_matched = false;
		{
			if ([_x,_combined,false] call fnc_inString) exitWith {_matched = true;};
		} forEach _a2edcCoastalNonBlockers;
		if (!_matched) then {
			if ((["nav_boathouse",_combined,false] call fnc_inString) && {(["pier",_combined,false] call fnc_inString)}) then {_matched = true;};
		};
		_matched
	};
	_a2edcGetModelPath = {
		private["_obj","_path"];
		_obj = _this;
		_path = "<unknown>";
		if (!isNull _obj) then {
			_path = getText (configFile >> "CfgVehicles" >> (typeOf _obj) >> "model");
			if (_path == "") then {_path = "<unknown>";};
		};
		_path
	};

	_a2edcScanDiagnostics = {
	private["_accepted","_house","_stage","_radius","_playerPos","_buildPos","_objects","_bp","_bpCargo","_mags","_cls","_cnt","_cargo","_types","_qtys","_i","_acceptedSource","_reason","_scanObj"];
	_accepted = _this select 0;
	_house = _this select 1;
	_stage = _this select 2;
	_radius = _this select 3;
	_buildPos = _this select 4;
	_playerPos = getPosATL player;
	diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=player_inventory scanSource=player inventory scanRadius=%1 playerPos=%2 buildPos=%3",0,_playerPos,_buildPos];
	_mags = magazines player;
	{
		_cls = _x;
		_cnt = {_x == _cls} count _mags;
		if (_cnt > 0) then {diag_log format ["A2EDC:HOUSE_BUILD_FOUND_ITEM source=player_inventory classname=%1 count=%2",_cls,_cnt];};
	} forEach ["ItemRocks","PartWoodPile","PartScrap","ItemCementBag","ItemBattery","ItemPin","ItemCinderblocks","ItemCeMix"];
	diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",player,typeOf player,0,player distance _buildPos,isNull player,count _mags,false,"player_inventory_not_used_by_bse_pp_material_check"];
	diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=backpack scanSource=backpack cargo scanRadius=%1 playerPos=%2 buildPos=%3",0,_playerPos,_buildPos];
	_bp = unitBackpack player;
	if (isNull _bp) then {
		diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_bp,"",0,0,true,0,false,"no_backpack"];
	} else {
		_bpCargo = getMagazineCargo _bp;
		diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_bp,typeOf _bp,player distance _bp,_buildPos distance _bp,isNull _bp,count (_bpCargo select 0),false,"backpack_not_used_by_bse_pp_material_check"];
		_i = 0;
		{diag_log format ["A2EDC:HOUSE_BUILD_FOUND_ITEM source=backpack classname=%1 count=%2",_x,(_bpCargo select 1) select _i]; _i = _i + 1;} forEach (_bpCargo select 0);
	};
	diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=nearby_storage scanSource=nearby container/tent/vehicle/cement mixer scanRadius=%1 playerPos=%2 buildPos=%3",_radius,_playerPos,_buildPos];
	_objects = nearestObjects [_buildPos, ["TentStorage","TentStorageR","Car","Helicopter","Motorcycle","Ship","CementMixer","wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], _radius];
	{
		_scanObj = _x;
		_cargo = getMagazineCargo _scanObj;
		_acceptedSource = (_scanObj == _accepted);
		_reason = "nearby_storage_not_used_by_bse_pp_material_check";
		if (_acceptedSource) then {_reason = "accepted_runtime_material_source";};
		diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_scanObj,typeOf _scanObj,player distance _scanObj,_buildPos distance _scanObj,isNull _scanObj,count (_cargo select 0),_acceptedSource,_reason];
		_i = 0;
		{diag_log format ["A2EDC:HOUSE_BUILD_FOUND_ITEM source=%1 classname=%2 count=%3",typeOf _scanObj,_x,(_cargo select 1) select _i]; _i = _i + 1;} forEach (_cargo select 0);
	} forEach _objects;
};

_invChe = {
	_objectF = _this select 0;
	_house = _this select 1;
	_stage = _this select 2;
	_typeOF = typeOf _objectF;
	_required = [_house,_stage] call _a2edcRecipe;
	A2EDC_houseBuildLastMaterialFailure = ["unknown","not_checked",[],_house,_stage,_typeOF];
	diag_log format ["A2EDC:HOUSE_BUILD_RECIPE blueprint=%1 targetBuilding=%2 house=%3 stage=%4 required=%5",_typeOF,_typeOF,_house,_stage,_required];
	diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=%1 scanSource=%2 scanRadius=%3 playerPos=%4 buildPos=%5",_typeOF,_typeOF,0,getPosATL player,getPosATL _objectF];
	_hiry = getMagazineCargo _objectF;
	//diag_log format ["_hinv=%1(%2),o=%3,to=%4",_hiry,(count _hiry),_objectF,_typeOF];
	diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_objectF,_typeOF,player distance _objectF,0,isNull _objectF,count (_hiry select 0),true,"runtime_material_source"];
	_objWpnTypes = (_hiry select 0);
	_objWpnQty = (_hiry select 1);
	_countr = 0;
	_vsegoMaterial = 0;
	_bOk = false;
	_qtyR = 0; _qtyW = 0; _qtyS = 0; _qtyC = 0; _qtyB = 0; _qtyP = 0; _qtyL = 0;
	if (count _hiry > 0) then {
		//"PartWoodPile" "PartRock"	"PartScrap" "ItemCementBag" "ItemBattery" "ItemPin" "ItemCinderblocks"
			{
				diag_log format ["A2EDC:HOUSE_BUILD_FOUND_ITEM source=%1 classname=%2 count=%3",_typeOF,_x,(_objWpnQty select _countr)];
				if (_stage == 2) then {diag_log format ["A2EDC:HOUSE_STAGE2_FOUND_ITEM object=%1 targetType=%2 classname=%3 count=%4",_objectF,_typeOF,_x,(_objWpnQty select _countr)];};
				if(_x == "ItemRocks") then 			{ _qtyR = _qtyR + (_objWpnQty select _countr); };
				if(_x == "PartWoodPile") then 		{ _qtyW = _qtyW + (_objWpnQty select _countr); };
				if(_x == "PartScrap") then 			{ _qtyS = _qtyS + (_objWpnQty select _countr); };
			if(_x == "ItemCementBag") then 		{ _qtyC = _qtyC + (_objWpnQty select _countr); };
			if(_x == "ItemBattery") then 		{ _qtyB = _qtyB + (_objWpnQty select _countr); };
			if(_x == "ItemPin") then 			{ _qtyP = _qtyP + (_objWpnQty select _countr); };
			if(_x == "ItemCinderblocks") then 	{ _qtyL = _qtyL + (_objWpnQty select _countr); };
			_vsegoMaterial = _vsegoMaterial + (_objWpnQty select _countr);
			_countr = _countr + 1;
		} forEach _objWpnTypes;
		if (_house == 1) then {
			if (_stage == 1) then {
				if((_qtyR >= 15)&&(_qtyW >= 25)&&(_qtyS >= 2)&&(_qtyC >= 2)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
			if (_stage == 2) then {
				if((_qtyR >= 25)&&(_qtyW >= 35)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
			};
		};
		if (_house == 2) then {
			if (_stage == 1) then {
				if((_qtyR >= 15)&&(_qtyW >= 25)&&(_qtyS >= 2)&&(_qtyC >= 2)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
			if (_stage == 2) then {
				if((_qtyR >= 25)&&(_qtyW >= 35)&&(_qtyS >= 4)&&(_qtyC >= 4)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
			if (_stage == 3) then {
				if((_qtyR >= 30)&&(_qtyW >= 45)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
			};
			if (_stage == 4) then {
				if((_qtyR >= 35)&&(_qtyW >= 55)&&(_qtyS >= 4)&&(_qtyC >= 4)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
		};
		if ((_house == 3)||(_house == 33)) then {
			if (_stage == 1) then {
				if((_qtyR >= 15)&&(_qtyW >= 25)&&(_qtyS >= 2)&&(_qtyC >= 2)&&(_qtyL >=5)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_house == 3) then {
				if (_stage == 2) then {
					if((_qtyR >= 25)&&(_qtyW >= 35)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=10)) then { _bOk = true; };
					//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
				};
				if (_stage == 3) then {
					if((_qtyR >= 30)&&(_qtyW >= 45)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=15)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
					//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				};
			};
			if (_house == 33) then {
				if (_stage == 2) then {
					if((_qtyR >= 25)&&(_qtyW >= 35)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=10)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
					//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				};
				if (_stage == 3) then {
					if((_qtyR >= 30)&&(_qtyW >= 45)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=15)) then { _bOk = true; };
					//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
				};
			};
			if (_stage == 4) then {
				if((_qtyR >= 35)&&(_qtyW >= 55)&&(_qtyS >= 6)&&(_qtyC >= 4)&&(_qtyL >=25)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_stage == 5) then {
				if((_qtyR >= 15)&&(_qtyW >= 25)&&(_qtyS >= 2)&&(_qtyC >= 2)&&(_qtyL >=5)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_stage == 6) then {
				if((_qtyR >= 25)&&(_qtyW >= 35)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=10)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_stage == 7) then {
				if((_qtyR >= 30)&&(_qtyW >= 45)&&(_qtyS >= 4)&&(_qtyC >= 4)&&(_qtyL >=15)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
			};
			if (_stage == 8) then {
				if((_qtyR >= 35)&&(_qtyW >= 55)&&(_qtyS >= 6)&&(_qtyC >= 4)&&(_qtyL >=20)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
		};
		if (_house == 4) then {
			if (_stage == 1) then {
				if((_qtyR >= 25)&&(_qtyW >= 25)&&(_qtyS >= 5)&&(_qtyC >= 5)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
			if (_stage == 2) then {
				if((_qtyR >= 35)&&(_qtyW >= 35)&&(_qtyS >= 5)&&(_qtyC >= 5)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
			if (_stage == 3) then {
				if((_qtyR >= 45)&&(_qtyW >= 45)&&(_qtyS >= 5)&&(_qtyC >= 5)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)) then { _bOk = true; };
			};
			if (_stage == 4) then {
				if((_qtyR >= 55)&&(_qtyW >= 55)&&(_qtyS >= 5)&&(_qtyC >= 5)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)) then { _bOk = true; };
			};
		};
		if (_house == 5) then {
			if (_stage == 1) then {
				if((_qtyR >= 45)&&(_qtyW >= 45)&&(_qtyS >= 5)&&(_qtyC >= 10)&&(_qtyL >=10)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >=1)) then { _bOk = true; };
			};
			if (_stage == 2) then {
				if((_qtyR >= 55)&&(_qtyW >= 55)&&(_qtyS >= 5)&&(_qtyC >= 10)&&(_qtyL >=20)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_stage == 3) then {
				if((_qtyR >= 65)&&(_qtyW >= 65)&&(_qtyS >= 10)&&(_qtyC >= 20)&&(_qtyB >= 1)&&(_qtyP >= 1)&&(_qtyL >=30)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyB >= 1)&&(_qtyP >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			if (_stage == 4) then {
				if((_qtyR >= 75)&&(_qtyW >= 75)&&(_qtyS >= 10)&&(_qtyC >= 20)&&(_qtyL >=40)) then { _bOk = true; };
				//if((_qtyR >= 1)&&(_qtyW >= 1)&&(_qtyS >= 1)&&(_qtyC >= 1)&&(_qtyL >= 1)) then { _bOk = true; };
			};
			};

		} else { _bOk = false; };
		_missingSummary = [];
		if ((count _required) == 0) then {
			A2EDC_houseBuildLastMaterialFailure = ["materials","empty_recipe_or_unmapped_house_stage",[],_house,_stage,_typeOF];
			diag_log format ["A2EDC:HOUSE_BUILD_MATERIAL_CHECK_RESULT allowed=false gate=materials reason=empty_recipe_or_unmapped_house_stage house=%1 stage=%2 targetType=%3 qty=[rocks=%4,wood=%5,scrap=%6,cement=%7,battery=%8,pin=%9,cinder=%10] cargoTypes=%11 cargoQty=%12",_house,_stage,_typeOF,_qtyR,_qtyW,_qtyS,_qtyC,_qtyB,_qtyP,_qtyL,_objWpnTypes,_objWpnQty];
		};
		{
			_className = _x select 0;
			_requiredQty = _x select 1;
			_foundQty = [_className,_qtyR,_qtyW,_qtyS,_qtyC,_qtyB,_qtyP,_qtyL] call _a2edcFoundCount;
			diag_log format ["A2EDC:HOUSE_BUILD_MATERIAL_CHECK_ITEM house=%1 stage=%2 targetType=%3 classname=%4 required=%5 found=%6 pass=%7 sourceObject=%8",_house,_stage,_typeOF,_className,_requiredQty,_foundQty,(_foundQty >= _requiredQty),_objectF];
			if (_foundQty < _requiredQty) then {
				_missingQty = _requiredQty - _foundQty;
				_missingSummary set [count _missingSummary,[_className,_requiredQty,_foundQty,_missingQty]];
				diag_log format ["A2EDC:HOUSE_BUILD_MISSING_ITEM stage=%1 classname=%2 required=%3 found=%4 missing=%5",_stage,_className,_requiredQty,_foundQty,_missingQty];
				if (_stage == 2) then {diag_log format ["A2EDC:HOUSE_STAGE2_MISSING_ITEM object=%1 targetType=%2 classname=%3 required=%4 found=%5 missing=%6",_objectF,_typeOF,_className,_requiredQty,_foundQty,_missingQty];};
			};
		} forEach _required;
		if (!_bOk) then {
			if ((count _missingSummary) > 0) then {
				A2EDC_houseBuildLastMaterialFailure = ["materials","missing_items",_missingSummary,_house,_stage,_typeOF];
			} else {
				if ((count _required) > 0) then {
					A2EDC_houseBuildLastMaterialFailure = ["materials","legacy_boolean_failed_but_no_missing_items",[],_house,_stage,_typeOF];
				};
			};
		} else {
			A2EDC_houseBuildLastMaterialFailure = ["materials","pass",[],_house,_stage,_typeOF];
		};
		diag_log format ["A2EDC:HOUSE_BUILD_MATERIAL_CHECK_RESULT allowed=%1 gate=materials reason=%2 house=%3 stage=%4 targetType=%5 required=%6 missingSummary=%7 qty=[rocks=%8,wood=%9,scrap=%10,cement=%11,battery=%12,pin=%13,cinder=%14]",_bOk,if (_bOk) then {"material_check_pass"} else {A2EDC_houseBuildLastMaterialFailure select 1},_house,_stage,_typeOF,_required,_missingSummary,_qtyR,_qtyW,_qtyS,_qtyC,_qtyB,_qtyP,_qtyL];
		diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",_bOk,_stage,if (_bOk) then {"material_check_pass"} else {A2EDC_houseBuildLastMaterialFailure select 1},_missingSummary,false];
	_bOk;
	};
_chePsw = {
	//diag_log ("password start =" + str(_this));
	_codeArray = _this select 0;
	_codeString = _this select 1;
	_status = [];
	_passwordN = 0;
	_pcount = count(_codeArray) == 6;
	_passwordN = parseNumber _codeString;
	//diag_log format ["_passwordN = %1(%4),_codeArray=%2,_codeString=%3(%5)",_passwordN,_codeArray,_codeString,typeName _passwordN,typeName _codeString];
	if (_passwordN != 0) then {
		_Ok = (999999-_passwordN) >= 0;
		if (_Ok) then {
			if (typeName _passwordN == "SCALAR") then {
				_status = [_passwordN,true,"_passwordN OK"];
			} else {
				_status = [0,false,"The passoword must consist of numbers"];
			};
		} else {
			_status = [0,false,"The passoword must have only 6 numbers"];
		};
	} else {
		_status = [0,false,"The passoword = 0"];
	};
	_status;
};
if(_new == "STRING") then {
	//diag_log format ["START NEW BUILDING"];
	_playerID = getPlayerUID player;
	diag_log format ["A2EDC:HOUSE_PREVIEW_START_BEGIN item=%1 uid=%2 player=%3 playerPos=%4 cursorTarget=%5",_this,_playerID,player,getPosATL player,cursorTarget];
	_a2edcPlayerBbBase = player getVariable ["bb_base",[]];
	_a2edcLoginElapsed = if (isNil "dayz_loginTime") then {time} else {time - dayz_loginTime};
	_a2edcLoginTimeSource = if (isNil "dayz_loginTime") then {"mission_time"} else {"dayz_loginTime"};
	diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_BEGIN variable=bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5 timeSource=%6 playerVariable=%7",bb_base,_this,_playerID,player,_a2edcLoginElapsed,_a2edcLoginTimeSource,_a2edcPlayerBbBase];
	diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_VAR variable=bb_base_global value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5",bb_base,_this,_playerID,player,_a2edcLoginElapsed];
	diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_VAR variable=player.bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5",_a2edcPlayerBbBase,_this,_playerID,player,_a2edcLoginElapsed];
	if ((count bb_base) != 8 && {(count _a2edcPlayerBbBase) == 8}) then {
		bb_base = +_a2edcPlayerBbBase;
		diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_RECOVER variable=bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5 source=player_variable",bb_base,_this,_playerID,player,_a2edcLoginElapsed];
	};
	if ((count bb_base) != 8) exitWith {
		diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=bb_base_sync_not_ready item=%1 uid=%2 bb_base=%3 playerVariable=%4 timeSinceLogin=%5",_this,_playerID,bb_base,_a2edcPlayerBbBase,_a2edcLoginElapsed];
		diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_FAIL variable=bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5 playerVariable=%6",bb_base,_this,_playerID,player,_a2edcLoginElapsed,_a2edcPlayerBbBase];
		diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_MESSAGE variable=bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 message=%5",bb_base,_this,_playerID,player,"Cannot build at this moment, please wait while synchronization with server is completed."];
		titletext ["Cannot build at this moment, please wait while synchronization with server is completed.", "PLAIN DOWN"];
		_stopGo = true;
	};
	diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_PASS variable=bb_base value=%1 expected=count_8 action=bbstart item=%2 uid=%3 player=%4 timeSinceLogin=%5",bb_base,_this,_playerID,player,_a2edcLoginElapsed];
	if (!_stopGo && {!isNil "A2EDC_housePreviewObject"} && {!isNull A2EDC_housePreviewObject}) then {
		_stopGo = true;
		diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=preview_already_active item=%1 uid=%2 preview=%3 marker=%4",_this,_playerID,A2EDC_housePreviewObject,if (isNil "A2EDC_housePreviewMarker") then {objNull} else {A2EDC_housePreviewMarker}];
		diag_log format ["A2EDC:HOUSE_PREVIEW_HANDLER_ERROR action=bbstart caller=%1 target=%1 preview=%2 marker=%3 blueprint=%4 source=global reason=preview_already_active",player,A2EDC_housePreviewObject,if (isNil "A2EDC_housePreviewMarker") then {objNull} else {A2EDC_housePreviewMarker},_this];
		titleText ["A house foundation preview is already active. Confirm or cancel it first.", "PLAIN DOWN"];
	};
	if (!_stopGo) then {
		ConstrSt = true;
		_lopata = "ItemEtool" in items player;
		_hasToolbox = "ItemToolbox" in items player;
		_hasBlueprint = _this in magazines player;

		if (!(_this in ["ItemBpt_b1","ItemBpt_b2","ItemBpt_b3","ItemBpt_h1","ItemBpt_h2","ItemBpt_h3","ItemBpt_g_s","ItemBpt_g_b"])) exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=invalid_blueprint_item item=%1 uid=%2",_this,_playerID]; diag_log format ["Wrong item(%1) recived",_this]; _stopGo = true; };
		if (!_stopGo) then {
			if (!_hasBlueprint) exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=missing_blueprint item=%1 uid=%2 magazines=%3",_this,_playerID,magazines player]; titletext ["You need a Blueprint to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_hasToolbox) 	exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=missing_toolbox item=%1 uid=%2 items=%3",_this,_playerID,items player]; titletext ["You need a Tool Box to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_lopata) 		exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=missing_etool item=%1 uid=%2 items=%3",_this,_playerID,items player]; titletext ["You need to have an Enternchment Tool to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_stopGo) then {
					_buildobj = getText (configFile >> "CfgMagazines" >> _this >> "ItemActions" >> "Build" >> "create");
					_text = 	getText (configFile >> "CfgVehicles" >> _buildobj >> "displayName");
					diag_log format ["A2EDC:HOUSE_BUILD_ACTION item=%1 action=bbstart uid=%2 player=%3 playerPos=%4 cursorTarget=%5 selectedBlueprint=%6 selectedBuilding=%7",_this,_playerID,player,getPosATL player,cursorTarget,_this,_buildobj];

					_humanityVP 	= player getVariable ["humanity",2500];
				_a2edcMapSource = "bse_pp.sqf client blueprint map + Origins create-class aliases";
				_a2edcMappedHouseType = "<unmapped>";
				_a2edcMappedInternalHouse = -1;
				_a2edcMappedHouseLevel = -1;
				_a2edcMappedAlignment = _humanityVP call _a2edcAlignment;
				_a2edcBlueprintMapPass = false;
				diag_log format ["A2EDC:HOUSE_BUILD_BLUEPRINT_MAP_BEGIN selectedBlueprint=%1 selectedBuilding=%2 mappedHouseType=%3 mappedHouseLevel=%4 mappedInternalHouse=%5 alignment=%6 source=%7 pass=<pending>",_this,_buildobj,_a2edcMappedHouseType,_a2edcMappedHouseLevel,_a2edcMappedInternalHouse,_a2edcMappedAlignment,_a2edcMapSource];
				{
					_a2edcMapItem = _x;
					_a2edcMapBlueprint = _a2edcMapItem select 0;
					_a2edcMapBuilding = _a2edcMapItem select 1;
					_a2edcMapHouseType = _a2edcMapItem select 2;
					_a2edcMapInternalHouse = _a2edcMapItem select 3;
					_a2edcMapLevel = _a2edcMapItem select 4;
					_a2edcMapRequiredAlignment = _a2edcMapItem select 5;
					_a2edcMapMatch = ((_this == _a2edcMapBlueprint) && {_buildobj == _a2edcMapBuilding});
					diag_log format ["A2EDC:HOUSE_BUILD_BLUEPRINT_MAP_ITEM selectedBlueprint=%1 selectedBuilding=%2 candidateBlueprint=%3 candidateBuilding=%4 mappedHouseType=%5 mappedHouseLevel=%6 mappedInternalHouse=%7 alignment=%8 source=%9 pass=%10",_this,_buildobj,_a2edcMapBlueprint,_a2edcMapBuilding,_a2edcMapHouseType,_a2edcMapLevel,_a2edcMapInternalHouse,_a2edcMapRequiredAlignment,_a2edcMapSource,_a2edcMapMatch];
					if (_a2edcMapMatch) then {
						_a2edcMappedHouseType = _a2edcMapHouseType;
						_a2edcMappedInternalHouse = _a2edcMapInternalHouse;
						_a2edcMappedHouseLevel = _a2edcMapLevel;
						_a2edcMappedAlignment = _a2edcMapRequiredAlignment;
						_a2edcBlueprintMapPass = true;
					};
				} forEach [
					["ItemBpt_b1","wooden_shed_lvl_1","wooden_shed_lvl_1",1,1,"bandit_l1_plus"],
					["ItemBpt_b2","log_house_lvl_2","log_house_lvl_2",2,2,"bandit_l2_plus"],
					["ItemBpt_b3","wooden_house_lvl_3","wooden_house_lvl_3",3,3,"bandit_l3_plus"],
					["ItemBpt_h1","large_shed_lvl_1","large_shed_lvl_1",1,1,"hero_l1_plus"],
					["ItemBpt_h1","Uroven1VelkaBudka","large_shed_lvl_1",1,1,"hero_l1_plus"],
					["ItemBpt_h2","small_house_lvl_2","small_house_lvl_2",2,2,"hero_l2_plus"],
					["ItemBpt_h3","big_house_lvl_3","big_house_lvl_3",33,3,"hero_l3_plus"],
					["ItemBpt_g_s","small_garage","small_garage",4,1,"house_owner"],
					["ItemBpt_g_b","big_garage","big_garage",5,1,"hero_or_bandit_l3_plus"]
				];
				if (_a2edcBlueprintMapPass) then {
					diag_log format ["A2EDC:HOUSE_BUILD_BLUEPRINT_MAP_RESULT selectedBlueprint=%1 selectedBuilding=%2 mappedHouseType=%3 mappedHouseLevel=%4 mappedInternalHouse=%5 alignment=%6 source=%7 pass=true",_this,_buildobj,_a2edcMappedHouseType,_a2edcMappedHouseLevel,_a2edcMappedInternalHouse,_a2edcMappedAlignment,_a2edcMapSource];
				} else {
					diag_log format ["A2EDC:HOUSE_BUILD_BLUEPRINT_MAP_FAIL selectedBlueprint=%1 selectedBuilding=%2 mappedHouseType=%3 mappedHouseLevel=%4 mappedInternalHouse=%5 alignment=%6 source=%7 pass=false reason=unmapped_build_object",_this,_buildobj,_a2edcMappedHouseType,_a2edcMappedHouseLevel,_a2edcMappedInternalHouse,_a2edcMappedAlignment,_a2edcMapSource];
				};
				_a2edcDayzLastHumanity = if (isNil "dayz_lastHumanity") then {"<nil>"} else {dayz_lastHumanity};
				_a2edcDayzGuiHumanity = if (isNil "dayz_guiHumanity") then {"<nil>"} else {dayz_guiHumanity};
				_a2edcDayzOriginsHumanity = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {if (((typeName dayzOriginsPlL2) == "ARRAY") && {(count dayzOriginsPlL2) > 2}) then {dayzOriginsPlL2 select 2} else {"<missing>"}};
				diag_log format ["A2EDC:HOUSE_BUILD_GATE_CHECK selectedBlueprint=%1 selectedBuilding=%2 uid=%3 charID=%4 humanity=%5 dayz_lastHumanity=%6 dayz_guiHumanity=%7 dayzOriginsPlL2Humanity=%8 bb_base=%9 playerPos=%10 buildPreviewPos=%11",_this,_buildobj,_playerID,player getVariable ["characterID","0"],_humanityVP,_a2edcDayzLastHumanity,_a2edcDayzGuiHumanity,_a2edcDayzOriginsHumanity,bb_base,getPosATL player,player modeltoworld [0,7,0]];
				if (_humanityVP > 2000 and _humanityVP < 2900) then { _isSurvi_p = true;};
				if (_isSurvi_p) exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=humanity_survivor_band item=%1 selectedBuilding=%2 current=%3 uid=%4",_this,_buildobj,_humanityVP,_playerID]; diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=hero_or_bandit requiredHumanity=hero>=2900_or_bandit<=2000 current=%3 alignment=%4 pass=false gate=humanity",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment]; ["humanity",format ["Hero L1 requires 2900, current %1",_humanityVP],[]] call _a2edcDebugFail; _stopGo = true; };

				if (_humanityVP >= 2900 and _humanityVP < 6500) then  { _isHero1_p = true; };
				if (_humanityVP >= 6500 and _humanityVP <= 15000) then { _isHero2_p = true; };
				if (_humanityVP > 15000) then { _isHero3_p = true; };

				if (_humanityVP > -6500 and _humanityVP <= 2000) then { _isBandit1_p = true; };
				if (_humanityVP >= -15000 and _humanityVP <= -6500) then { _isBandit2_p = true; };
				if (_humanityVP < -15000) then { _isBandit3_p = true; };
				diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 current=%3 alignment=%4 heroFlags=[%5,%6,%7] banditFlags=[%8,%9,%10] survivor=%11 pass=%12",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,_isHero1_p,_isHero2_p,_isHero3_p,_isBandit1_p,_isBandit2_p,_isBandit3_p,_isSurvi_p,(!_isSurvi_p)];

				//"wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"
				if (_buildobj == "wooden_shed_lvl_1") then { _nhouse = 1; _syOfh = 13;
					diag_log format ["A2EDC:HOUSE_BUILD_BANDIT_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=bandit_l1_plus current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,(_isBandit1_p || _isBandit2_p || _isBandit3_p)];
					if (!_isBandit1_p && !_isBandit2_p && !_isBandit3_p) then { _stopGo = true; ["bandit",format ["this blueprint requires Bandit, current %1 (%2)",_humanityVP,_humanityVP call _a2edcAlignment],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 1) then { _stopGo = true; titletext ["You have already built a level 1 house.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "log_house_lvl_2") then { _nhouse = 2; _syOfh = 20;
					diag_log format ["A2EDC:HOUSE_BUILD_BANDIT_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=bandit_l2_plus current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,(_isBandit2_p || _isBandit3_p)];
					if (!_isBandit2_p && !_isBandit3_p) then { _stopGo = true; ["bandit",format ["Bandit L2 requires <= -6500, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 1) then { _stopGo = true; titletext ["You have already built a level 2 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "wooden_house_lvl_3") then { _nhouse = 3; _syOfh = 14;
					diag_log format ["A2EDC:HOUSE_BUILD_BANDIT_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=bandit_l3_plus current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,_isBandit3_p];
					if (!_isBandit3_p) then { _stopGo = true; ["bandit",format ["Bandit L3 requires < -15000, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 0) then { _stopGo = true; titletext ["You need to build a level 2 house first.", "PLAIN DOWN"]; };
					if (bb_base select 2 == 1) then { _stopGo = true; titletext ["You have already built a level 3 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj in ["large_shed_lvl_1","Uroven1VelkaBudka"]) then { _nhouse = 1; _syOfh = 13;
					diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=hero_l1_plus requiredHumanity=2900 current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,(_isHero1_p || _isHero2_p || _isHero3_p)];
					if (!_isHero1_p && !_isHero2_p && !_isHero3_p) then { _stopGo = true; ["humanity",format ["Hero L1 requires 2900, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 1) then { _stopGo = true; titletext ["You have already built a level 1 house.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "small_house_lvl_2") then { _nhouse = 2; _syOfh = 10;
					diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=hero_l2_plus requiredHumanity=6500 current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,(_isHero2_p || _isHero3_p)];
					if (!_isHero2_p && !_isHero3_p) then { _stopGo = true; ["humanity",format ["Hero L2 requires 6500, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 1) then { _stopGo = true; titletext ["You have already built a level 2 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "big_house_lvl_3") then { _nhouse = 33; _syOfh = 14;
					diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=hero_l3_plus requiredHumanity=15001 current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,_isHero3_p];
					if (!_isHero3_p) then { _stopGo = true; ["humanity",format ["Hero L3 requires >15000, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 0) then { _stopGo = true; titletext ["You need to build a level 2 house first.", "PLAIN DOWN"]; };
					if (bb_base select 2 == 1) then { _stopGo = true; titletext ["You have already built a level 3 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "small_garage") then { _nhouse = 4; _syOfh = 11;
					if ((bb_base select 0 == 0)&&(bb_base select 1 == 0)&&(bb_base select 2 == 0))  then { _stopGo = true; titletext ["You need to build a house first.", "PLAIN DOWN"]; };
					if (bb_base select 3 == 1) then { _stopGo = true; titletext ["You have already built a small garage.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "big_garage") then { _nhouse = 5; _syOfh = 14;
					diag_log format ["A2EDC:HOUSE_BUILD_HUMANITY_CHECK selectedBlueprint=%1 selectedBuilding=%2 required=hero_or_bandit_l3_plus current=%3 alignment=%4 pass=%5",_this,_buildobj,_humanityVP,_humanityVP call _a2edcAlignment,(_isBandit3_p || _isHero3_p)];
					if (!_isBandit3_p && !_isHero3_p) then { _stopGo = true; ["humanity",format ["Hero/Bandit L3 required, current %1",_humanityVP],[]] call _a2edcDebugFail; };
					if (bb_base select 2 == 0)  then { _stopGo = true; titletext ["You need to build a level 3 house first.", "PLAIN DOWN"]; };
					if (bb_base select 4 == 1) then { _stopGo = true; titletext ["You have already built a big garage.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN"]; };
					if (bb_base select 7 == 0) then { _stopGo = true; titletext ["You need to finish building a level 3 house first.", "PLAIN DOWN"]; };
				};
				if (isNil "_nhouse") then {
					_stopGo = true;
					diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=unmapped_build_object item=%1 selectedBuilding=%2 uid=%3",_this,_buildobj,_playerID];
					diag_log format ["A2EDC:HOUSE_BUILD_FAIL_REASON gate=blueprint reason=unmapped_build_object details=[selectedBlueprint=%1,selectedBuilding=%2] message=Cannot map blueprint to Origins house type",_this,_buildobj];
					["blueprint",format ["%1 cannot map building %2",_this,_buildobj],[]] call _a2edcDebugFail;
				};

				if (!_stopGo) then {
							_qtyB = true;
							_qtyT = true;
							_ctentb = true;
							_cityGateFailed = false;
							_placementGateFailed = false;
							_posit = player modeltoworld [0,7,0];
							_isRoadorNot = isOnRoad _posit;
							if (_isRoadorNot) exitWith { _qtyB = false; diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=road_check_failed item=%1 uid=%2 buildPos=%3",_this,_playerID,_posit]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"road_check_failed",[],false]; ["city_check","build position is on road",[_posit]] call _a2edcDebugFail; };
						_builOk = ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor","Land_majak","Land_majak_podesta","Land_majak2","small_bunker"];
						_cityObjects = nearestObjects [_posit, ["House"], 150];
						diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_BEGIN scanSource=nearestObjects class=House scanRadius=150 playerPos=%1 buildPos=%2 objectCount=%3 explicitUtilityNonBlockers=%4 coastalNonBlockers=%5",getPosATL player,_posit,count _cityObjects,_builOk + _a2edcUtilityNonBlockers,_a2edcCoastalNonBlockers];
						{
							_type = typeOf _x;
							_modelPath = _x call _a2edcGetModelPath;
							_isBroadHouse = true;
							_isExplicitUtility = (_type in _builOk);
							_isUtilityPattern = _type call _a2edcIsUtilityNonBlocker;
							_isCoastalPattern = [_type,_modelPath] call _a2edcIsCoastalNonBlocker;
							_isLandClass = ["Land_",_type,false] call fnc_inString;
							_isTrueBlocker = (_isLandClass && !_isExplicitUtility && !_isUtilityPattern && !_isCoastalPattern);
							_cityReason = if (_isTrueBlocker) then {"city_house_within_150m"} else {if (_isCoastalPattern) then {"coastal_non_blocker"} else {if (!_isLandClass) then {"non_land_house_class"} else {"utility_or_non_building_static"}}};
							diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_OBJECT object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 broadClassHouse=%7 landClass=%8 explicitUtility=%9 utilityPattern=%10 coastalPattern=%11 trueBlocker=%12 reason=%13",_x,_type,_modelPath,_type,player distance _x,_posit distance _x,_isBroadHouse,_isLandClass,_isExplicitUtility,_isUtilityPattern,_isCoastalPattern,_isTrueBlocker,_cityReason];
							if (_isTrueBlocker) exitWith {
								_qtyB = false;
								_cityGateFailed = true;
								diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=city_house_within_150m item=%1 uid=%2 buildPos=%3 blocker=%4 blockerType=%5",_this,_playerID,_posit,_x,_type];
								diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_ACCEPTED_BLOCKER object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 reason=%7 trueBlocker=true",_x,_type,_modelPath,_type,player distance _x,_posit distance _x,_cityReason];
							};
							if (!_isTrueBlocker) then {
								diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_IGNORED_OBJECT object=%1 typeOf=%2 modelPath=%3 configClass=%4 distancePlayer=%5 distanceBuild=%6 reason=%7 trueBlocker=false",_x,_type,_modelPath,_type,player distance _x,_posit distance _x,_cityReason];
							};
							} forEach _cityObjects;
							diag_log format ["A2EDC:HOUSE_BUILD_CITY_CHECK_RESULT allowed=%1 gate=city_check reason=%2 scanRadius=150 objectCount=%3 playerPos=%4 buildPos=%5",_qtyB,if (_qtyB) then {"no_true_city_house_blocker"} else {"city_house_within_150m"},count _cityObjects,getPosATL player,_posit];
							_placementBlockers = nearestObjects [_posit, ["TentStorage","TentStorageR"], _syOfh];
							_placementRealBlockers = [];
							_placementIgnoredAdminTemp = [];
							{
								_placementObject = _x;
								_adminKit = _placementObject getVariable ["A2EDC_adminBuildingKit",""];
								_adminStage = _placementObject getVariable ["A2EDC_adminBuildingKitStage",-1];
								_isAdminTemp = (_placementObject getVariable ["A2EDC_adminTempObject",false]) && (_adminKit != "");
								diag_log format ["A2EDC:HOUSE_BUILD_PLACEMENT_BLOCKER object=%1 typeOf=%2 pos=%3 distanceBuild=%4 distancePlayer=%5 radius=%6 adminTemp=%7 adminKit=%8 adminStage=%9 ignored=%10 reason=%11",_placementObject,typeOf _placementObject,getPosATL _placementObject,_posit distance _placementObject,player distance _placementObject,_syOfh,_placementObject getVariable ["A2EDC_adminTempObject",false],_adminKit,_adminStage,_isAdminTemp,if (_isAdminTemp) then {"admin_temp_building_kit_container"} else {"normal_storage_tent"}];
								if (_isAdminTemp) then {
									_placementIgnoredAdminTemp set [count _placementIgnoredAdminTemp,_placementObject];
									diag_log format ["A2EDC:HOUSE_BUILD_PLACEMENT_BLOCKER_IGNORED_ADMIN_TEMP object=%1 typeOf=%2 pos=%3 distanceBuild=%4 distancePlayer=%5 radius=%6 adminTemp=%7 adminKit=%8 adminStage=%9 ignored=true reason=admin_temp_building_kit_container",_placementObject,typeOf _placementObject,getPosATL _placementObject,_posit distance _placementObject,player distance _placementObject,_syOfh,_placementObject getVariable ["A2EDC_adminTempObject",false],_adminKit,_adminStage];
								} else {
									_placementRealBlockers set [count _placementRealBlockers,_placementObject];
									diag_log format ["A2EDC:HOUSE_BUILD_PLACEMENT_BLOCKER_ACCEPTED object=%1 typeOf=%2 pos=%3 distanceBuild=%4 distancePlayer=%5 radius=%6 adminTemp=%7 adminKit=%8 adminStage=%9 ignored=false reason=normal_storage_tent",_placementObject,typeOf _placementObject,getPosATL _placementObject,_posit distance _placementObject,player distance _placementObject,_syOfh,_placementObject getVariable ["A2EDC_adminTempObject",false],_adminKit,_adminStage];
								};
							} forEach _placementBlockers;
							_ctentb = count _placementRealBlockers == 0;
							if (!_ctentb) then {
								_placementGateFailed = true;
								diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=placement_blocker_tent_storage item=%1 uid=%2 buildPos=%3 blockers=%4 radius=%5",_this,_playerID,_posit,_placementRealBlockers,_syOfh];
								diag_log format ["A2EDC:HOUSE_BUILD_PLACEMENT_RESULT allowed=false gate=placement_blocker reason=normal_storage_tent count=%1 ignoredAdminTemp=%2 radius=%3 buildPos=%4",count _placementRealBlockers,count _placementIgnoredAdminTemp,_syOfh,_posit];
								diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"placement_blocker_tent_storage",[],false];
								["placement_blocker","nearby storage/tent",[_posit,_syOfh,_placementRealBlockers]] call _a2edcDebugFail;
								_qtyB = false;
							} else {
								diag_log format ["A2EDC:HOUSE_BUILD_PLACEMENT_RESULT allowed=true gate=placement_blocker reason=no_real_storage_tent_blocker count=0 ignoredAdminTemp=%1 radius=%2 buildPos=%3",count _placementIgnoredAdminTemp,_syOfh,_posit];
							};
						if (_qtyB) then {
							_listBB = count (nearestObjects [_posit, ["wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], 15]) == 0;
							if (!_listBB) exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=placement_blocker_house_within_16m item=%1 uid=%2 buildPos=%3",_this,_playerID,_posit]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"placement_blocker_house_within_16m",[],false]; ["placement_blocker","house within 16m",[_posit]] call _a2edcDebugFail; };
							{
								if ((["t_",str(_x),false] call fnc_inString)) exitWith { _qtyT = false; diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=placement_blocker_tree item=%1 uid=%2 buildPos=%3 blocker=%4",_this,_playerID,_posit,_x]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"placement_blocker_tree",[],false]; ["placement_blocker","trees obstructing area",[_x,_posit]] call _a2edcDebugFail; };
								if ((["r2_",str(_x),false] call fnc_inString)) exitWith { _qtyT = false; diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=placement_blocker_rock item=%1 uid=%2 buildPos=%3 blocker=%4",_this,_playerID,_posit,_x]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"placement_blocker_rock",[],false]; ["placement_blocker","rocks obstructing area",[_x,_posit]] call _a2edcDebugFail; };
							} forEach nearestObjects [_posit, [], _syOfh];

							if (_qtyT) then {
								_findMix = position player nearObjects ["CementMixer",10];
								_listMix = 	count _findMix == 1;
								diag_log format ["A2EDC:HOUSE_BUILD_SCAN_BEGIN source=cement_mixer_required scanSource=cement mixer scanRadius=%1 playerPos=%2 buildPos=%3",10,getPosATL player,_posit];
								{
									diag_log format ["A2EDC:HOUSE_BUILD_CONTAINER object=%1 type=%2 distancePlayer=%3 distanceBuild=%4 isNull=%5 cargoMagazinesCount=%6 accepted=%7 rejectionReason=%8",_x,typeOf _x,player distance _x,_posit distance _x,isNull _x,count ((getMagazineCargo _x) select 0),(count _findMix == 1),"candidate_cement_mixer"];
								} forEach _findMix;
								if (!_listMix) exitWith { diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=cement_mixer_not_found_or_not_unique item=%1 uid=%2 foundMixers=%3 playerPos=%4 buildPos=%5",_this,_playerID,count _findMix,getPosATL player,_posit]; diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"cement_mixer_not_found_or_not_unique",[],false]; ["mixer_state","not found or too far",[]] call _a2edcDebugFail; };
									[_findMix select 0,_nhouse,1,30,_posit] call _a2edcScanDiagnostics;
									_itOKbu = [_findMix select 0,_nhouse,1] call _invChe;
									if (_itOKbu) then {
										_a2edcPreviewClass = _buildobj;
										_a2edcPreviewRedClass = "gerojUroven1VelkaBudka_ghost";
										_a2edcPreviewGreenClass = "gerojUroven1VelkaBudka_ghostg_gs";
										_a2edcPreviewPos = +_posit;
										_a2edcPreviewHiddenPos = [0,0,-1000];
										_a2edcPreviewDir = round(direction player);
										_a2edcPreview = _a2edcPreviewRedClass createVehicleLocal _a2edcPreviewHiddenPos;
										_a2edcPreviewMarker = _a2edcPreviewGreenClass createVehicleLocal _a2edcPreviewPos;
										diag_log format ["A2EDC:HOUSE_PREVIEW_OBJECT_CREATED item=%1 redGhostClass=%2 greenGhostClass=%3 redGhost=%4 greenGhost=%5 redGhostNull=%6 greenGhostNull=%7 position=%8 hiddenPosition=%9 direction=%10",_this,_a2edcPreviewRedClass,_a2edcPreviewGreenClass,_a2edcPreview,_a2edcPreviewMarker,isNull _a2edcPreview,isNull _a2edcPreviewMarker,_a2edcPreviewPos,_a2edcPreviewHiddenPos,_a2edcPreviewDir];
										_a2edcPreview setVariable ["A2EDC_housePreviewLocal",true,false];
										_a2edcPreviewMarker setVariable ["A2EDC_housePreviewLocal",true,false];
										_a2edcPreview setDir _a2edcPreviewDir;
										_a2edcPreviewMarker setDir _a2edcPreviewDir;
										_a2edcPreview setPosATL _a2edcPreviewHiddenPos;
										_a2edcPreviewMarker setPosATL _a2edcPreviewPos;
										A2EDC_housePreviewChoice = -1;
										A2EDC_housePreviewValid = true;
										A2EDC_housePreviewInvalidReason = "valid";
										A2EDC_housePreviewConfirmInProgress = false;
										A2EDC_housePreviewRequestSent = false;
										A2EDC_housePreviewRotationOffset = 0;
										_a2edcPreviewLastValid = true;
										_a2edcPreviewReason = "initial_checks_passed";
										_a2edcPreviewCityValid = true;
										_a2edcPreviewCityReason = "initial_city_check_passed";
										_a2edcPreviewLastCityPos = +_a2edcPreviewPos;
										_a2edcPreviewLastLogPos = [0,0,0];
										_a2edcPreviewLastLogDir = _a2edcPreviewDir;
										_a2edcPreviewLastTick = time;
										_a2edcPreviewLastHeartbeat = time;
										_a2edcPreviewStartTime = time;
										_a2edcPreviewLoopIteration = 0;
										_a2edcPreviewLastColor = "";
										_a2edcPreviewContext = [_this,_a2edcMappedHouseType,_a2edcPreviewClass,_a2edcPreview,_a2edcPreviewMarker,_findMix select 0,_playerID];
										A2EDC_housePreviewContext = +_a2edcPreviewContext;
										A2EDC_housePreviewObject = _a2edcPreview;
										A2EDC_housePreviewMarker = _a2edcPreviewMarker;
										A2EDC_housePreviewPosition = +_a2edcPreviewPos;
										A2EDC_housePreviewDirection = _a2edcPreviewDir;
										_a2edcConfirmAction = player addAction ["<t color='#00ff80'>Confirm house foundation placement</t>","\z\addons\dayz_code\actions\house_preview_confirm.sqf",_a2edcPreviewContext,6,false,true,"","A2EDC_housePreviewValid"];
										_a2edcCancelAction = player addAction ["<t color='#ff4040'>Cancel house foundation placement</t>","\z\addons\dayz_code\actions\house_preview_cancel.sqf",_a2edcPreviewContext,6,false,true,"","true"];
										_a2edcRotateLeftAction = player addAction ["<t color='#80c8ff'>Rotate foundation left</t>","\z\addons\dayz_code\actions\house_preview_rotate.sqf",["left",15],5,false,true,"","!isNil 'A2EDC_housePreviewChoice' && {A2EDC_housePreviewChoice < 0}"];
										_a2edcRotateRightAction = player addAction ["<t color='#80c8ff'>Rotate foundation right</t>","\z\addons\dayz_code\actions\house_preview_rotate.sqf",["right",15],5,false,true,"","!isNil 'A2EDC_housePreviewChoice' && {A2EDC_housePreviewChoice < 0}"];
										A2EDC_housePreviewConfirmAction = _a2edcConfirmAction;
										A2EDC_housePreviewCancelAction = _a2edcCancelAction;
										A2EDC_housePreviewRotateLeftAction = _a2edcRotateLeftAction;
										A2EDC_housePreviewRotateRightAction = _a2edcRotateRightAction;
										diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_ADD confirmAction=%1 cancelAction=%2 rotateLeftAction=%3 rotateRightAction=%4 caller=%5 target=%5 preview=%6 marker=%7 blueprint=%8 dbHouseType=%9 runtimeClass=%10 buildPosition=%11 direction=%12 cementMixer=%13 source=global_context previewNull=%14 markerNull=%15 mixerNull=%16 handlers=%17",_a2edcConfirmAction,_a2edcCancelAction,_a2edcRotateLeftAction,_a2edcRotateRightAction,player,_a2edcPreview,_a2edcPreviewMarker,_this,_a2edcMappedHouseType,_a2edcPreviewClass,_a2edcPreviewPos,_a2edcPreviewDir,_findMix select 0,isNull _a2edcPreview,isNull _a2edcPreviewMarker,isNull (_findMix select 0),["\z\addons\dayz_code\actions\house_preview_confirm.sqf","\z\addons\dayz_code\actions\house_preview_cancel.sqf","\z\addons\dayz_code\actions\house_preview_rotate.sqf"]];
										diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_ACTION_ADD leftAction=%1 rightAction=%2 stepDegrees=15 preview=%3 greenGhost=%4 redGhost=%5 initialDirection=%6 finalDirection=%7",_a2edcRotateLeftAction,_a2edcRotateRightAction,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreview,_a2edcPreviewDir,A2EDC_housePreviewDirection];
										diag_log format ["A2EDC:HOUSE_PREVIEW_BEGIN blueprint=%1 previewClass=%2 object=%3 marker=%4 position=%5 direction=%6 stageAnimation=%7 confirmAction=%8 cancelAction=%9 rotateLeftAction=%10 rotateRightAction=%11",_this,_a2edcPreviewClass,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewPos,_a2edcPreviewDir,[],_a2edcConfirmAction,_a2edcCancelAction,_a2edcRotateLeftAction,_a2edcRotateRightAction];
										diag_log format ["A2EDC:HOUSE_PREVIEW_START blueprint=%1 previewClass=%2 position=%3 direction=%4",_this,_a2edcPreviewClass,_a2edcPreviewPos,_a2edcPreviewDir];
										diag_log format ["A2EDC:HOUSE_PREVIEW_OBJECT_CREATE blueprint=%1 previewObject=%2 markerObject=%3 previewNull=%4 markerNull=%5",_this,_a2edcPreview,_a2edcPreviewMarker,isNull _a2edcPreview,isNull _a2edcPreviewMarker];
										diag_log format ["A2EDC:HOUSE_PREVIEW_VISUAL_CLASS blueprint=%1 runtimeFoundationClass=%2 redGhostClass=%3 greenGhostClass=%4 redGhost=%5 greenGhost=%6",_this,_a2edcPreviewClass,_a2edcPreviewRedClass,_a2edcPreviewGreenClass,_a2edcPreview,_a2edcPreviewMarker];
										diag_log format ["A2EDC:HOUSE_PREVIEW_VISUAL_MODE mode=original_origins_dual_ghost activeColor=green inactiveGhostPosition=%1 localOnly=true",_a2edcPreviewHiddenPos];
										diag_log "A2EDC:HOUSE_PREVIEW_VISUAL_COLOR source=original_origins_ghost_textures valid=green invalid=red";
										diag_log "A2EDC:HOUSE_PREVIEW_VISUAL_TRANSPARENCY source=original_origins_ghost_models runtimeOverride=false";
										diag_log "A2EDC:HOUSE_PREVIEW_DEBUG_MARKER enabled=false reason=original_foundation_ghost_is_primary_visual";
										diag_log format ["A2EDC:HOUSE_PREVIEW_UPDATE_LOOP_START blueprint=%1 preview=%2 marker=%3 buildPosition=%4 direction=%5 playerPosition=%6 playerDirection=%7 iteration=%8 elapsed=%9 updateSource=player_modelToWorld_7m visualMode=original_origins_dual_ghost",_this,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewPos,_a2edcPreviewDir,getPosATL player,direction player,_a2edcPreviewLoopIteration,0];
										titleText ["Move to position the foundation. Use rotate left/right, Confirm, or Cancel.", "PLAIN DOWN"];
										A2EDC_housePreviewActive = true;
										A2EDC_housePreviewBuildPosition = +_a2edcPreviewPos;
										[_this,_a2edcMappedHouseType,_a2edcPreviewClass,_a2edcPreview,_a2edcPreviewMarker,_findMix select 0,_a2edcConfirmAction,_a2edcCancelAction,_a2edcRotateLeftAction,_a2edcRotateRightAction] execVM "\z\addons\dayz_code\actions\house_preview_loop.sqf";
										diag_log format ["A2EDC:HOUSE_PREVIEW_UPDATE_LOOP_SCHEDULED blueprint=%1 preview=%2 redGhost=%3 greenGhost=%4 confirmAction=%5 cancelAction=%6 rotateLeftAction=%7 rotateRightAction=%8 source=execVM_house_preview_loop_after_contract",_this,_a2edcPreview,_a2edcPreview,_a2edcPreviewMarker,_a2edcConfirmAction,_a2edcCancelAction,_a2edcRotateLeftAction,_a2edcRotateRightAction];
										while {A2EDC_housePreviewChoice < 0 && alive player && {!isNull _a2edcPreview} && {!isNull _a2edcPreviewMarker}} do {
											_a2edcPreviewLoopIteration = _a2edcPreviewLoopIteration + 1;
											_a2edcPreviewTickGap = time - _a2edcPreviewLastTick;
											if (_a2edcPreviewTickGap > 1) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_UPDATE_LOOP_STALE blueprint=%1 gapSeconds=%2 preview=%3 marker=%4 position=%5 direction=%6 playerPosition=%7 playerDirection=%8 choice=%9 iteration=%10 elapsed=%11",_this,_a2edcPreviewTickGap,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewPos,_a2edcPreviewDir,getPosATL player,direction player,A2EDC_housePreviewChoice,_a2edcPreviewLoopIteration,time - _a2edcPreviewStartTime];
											};
											_a2edcPreviewLastTick = time;
											_a2edcPreviewOldPos = +_a2edcPreviewPos;
											_a2edcPreviewOldDir = _a2edcPreviewDir;
											_a2edcPreviewPos = player modelToWorld [0,7,0];
											_a2edcPreviewPos set [2,0];
											_a2edcPreviewPlayerDir = round(direction player);
											_a2edcPreviewDir = (_a2edcPreviewPlayerDir + A2EDC_housePreviewRotationOffset) mod 360;
											A2EDC_housePreviewPosition = +_a2edcPreviewPos;
											A2EDC_housePreviewDirection = _a2edcPreviewDir;
											_a2edcPreview setDir _a2edcPreviewDir;
											_a2edcPreviewMarker setDir _a2edcPreviewDir;
											_a2edcPreviewDeltaDist = _a2edcPreviewPos distance _a2edcPreviewOldPos;
											_a2edcPreviewDeltaDir = abs(_a2edcPreviewDir - _a2edcPreviewOldDir);
											if (_a2edcPreviewDeltaDir > 180) then {_a2edcPreviewDeltaDir = 360 - _a2edcPreviewDeltaDir;};
											_a2edcPreviewDirectionChanged = abs(_a2edcPreviewDir - _a2edcPreviewLastLogDir) > 10;
											_a2edcPreviewLogUpdate = ((_a2edcPreviewPos distance _a2edcPreviewLastLogPos) > 1 || {_a2edcPreviewDirectionChanged});
											if (_a2edcPreviewLogUpdate) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_POSITION_UPDATE blueprint=%1 preview=%2 marker=%3 oldPosition=%4 newPosition=%5 oldDirection=%6 newDirection=%7 playerPosition=%8 playerDirection=%9 currentGhostPosition=%10 deltaDistance=%11 deltaDirection=%12 iteration=%13 elapsed=%14 source=player_modelToWorld_7m",_this,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewOldPos,_a2edcPreviewPos,_a2edcPreviewOldDir,_a2edcPreviewDir,getPosATL player,direction player,if (A2EDC_housePreviewValid) then {getPosATL _a2edcPreviewMarker} else {getPosATL _a2edcPreview},_a2edcPreviewDeltaDist,_a2edcPreviewDeltaDir,_a2edcPreviewLoopIteration,time - _a2edcPreviewStartTime];
												if (_a2edcPreviewDirectionChanged) then {
													diag_log format ["A2EDC:HOUSE_PREVIEW_DIRECTION_UPDATE blueprint=%1 preview=%2 marker=%3 oldPosition=%4 newPosition=%5 oldDirection=%6 newDirection=%7 playerPosition=%8 playerDirection=%9 rotationOffset=%10 currentGhostPosition=%11 deltaDistance=%12 deltaDirection=%13 iteration=%14 elapsed=%15 source=player_direction_plus_manual_offset",_this,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewOldPos,_a2edcPreviewPos,_a2edcPreviewLastLogDir,_a2edcPreviewDir,getPosATL player,direction player,A2EDC_housePreviewRotationOffset,if (A2EDC_housePreviewValid) then {getPosATL _a2edcPreviewMarker} else {getPosATL _a2edcPreview},_a2edcPreviewDeltaDist,_a2edcPreviewDeltaDir,_a2edcPreviewLoopIteration,time - _a2edcPreviewStartTime];
												};
												_a2edcPreviewLastLogPos = +_a2edcPreviewPos;
												_a2edcPreviewLastLogDir = _a2edcPreviewDir;
											};
											if ((time - _a2edcPreviewLastHeartbeat) > 5) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_UPDATE_LOOP_HEARTBEAT blueprint=%1 preview=%2 marker=%3 oldPosition=%4 newPosition=%5 oldDirection=%6 newDirection=%7 playerPosition=%8 playerDirection=%9 currentGhostPosition=%10 deltaDistance=%11 deltaDirection=%12 valid=%13 reason=%14 choice=%15 iteration=%16 elapsed=%17",_this,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewOldPos,_a2edcPreviewPos,_a2edcPreviewOldDir,_a2edcPreviewDir,getPosATL player,direction player,if (A2EDC_housePreviewValid) then {getPosATL _a2edcPreviewMarker} else {getPosATL _a2edcPreview},_a2edcPreviewDeltaDist,_a2edcPreviewDeltaDir,A2EDC_housePreviewValid,_a2edcPreviewReason,A2EDC_housePreviewChoice,_a2edcPreviewLoopIteration,time - _a2edcPreviewStartTime];
												_a2edcPreviewLastHeartbeat = time;
											};
											A2EDC_housePreviewValid = true;
											_a2edcPreviewReason = "valid";
											if (_a2edcPreviewLogUpdate) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDITY_CHECK blueprint=%1 buildPosition=%2 direction=%3 playerPosition=%4 playerDirection=%5 checks=%6 source=dynamic_loop slopeCheck=false slopeReason=not_available_in_current_arma2_preview_pass",_this,_a2edcPreviewPos,_a2edcPreviewDir,getPosATL player,direction player,["water","road","storage_or_tent","house","city","tree_or_rock"]];
											};
											if (surfaceIsWater _a2edcPreviewPos) then {A2EDC_housePreviewValid = false; _a2edcPreviewReason = "water";};
											if (isOnRoad _a2edcPreviewPos) then {A2EDC_housePreviewValid = false; _a2edcPreviewReason = "road";};
											if (A2EDC_housePreviewValid && {({!((_x getVariable ["A2EDC_adminTempObject",false]) && {(_x getVariable ["A2EDC_adminBuildingKit",""]) != ""})} count (nearestObjects [_a2edcPreviewPos,["TentStorage","TentStorageR"],_syOfh])) > 0}) then {A2EDC_housePreviewValid = false; _a2edcPreviewReason = "storage_or_tent";};
											_a2edcPreviewHouses = nearestObjects [_a2edcPreviewPos,["wooden_shed_lvl_1","Uroven1VelkaBudka","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"],15];
											_a2edcPreviewRealHouses = [];
											{
												_a2edcPreviewObject = _x;
												if (_a2edcPreviewObject == _a2edcPreview || {_a2edcPreviewObject getVariable ["A2EDC_housePreviewLocal",false]}) then {
													if (_a2edcPreviewLogUpdate) then {
													diag_log format ["A2EDC:HOUSE_PREVIEW_BLOCKER_SELF_IGNORED object=%1 typeOf=%2 preview=%3 marker=%4 position=%5 reason=current_local_preview",_a2edcPreviewObject,typeOf _a2edcPreviewObject,_a2edcPreview,_a2edcPreviewMarker,getPosATL _a2edcPreviewObject];
													};
												} else {
													_a2edcPreviewRealHouses set [count _a2edcPreviewRealHouses,_a2edcPreviewObject];
													if (_a2edcPreviewLogUpdate || {_a2edcPreviewLastValid}) then {
														diag_log format ["A2EDC:HOUSE_PREVIEW_BLOCKER_ACCEPTED object=%1 typeOf=%2 preview=%3 marker=%4 position=%5 reason=real_house_within_15m",_a2edcPreviewObject,typeOf _a2edcPreviewObject,_a2edcPreview,_a2edcPreviewMarker,getPosATL _a2edcPreviewObject];
													};
												};
											} forEach _a2edcPreviewHouses;
											if (_a2edcPreviewLogUpdate || {_a2edcPreviewLastValid != ((count _a2edcPreviewRealHouses) == 0)}) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_BLOCKER_RESULT buildPosition=%1 nearbyHouses=%2 realHouses=%3 ignoredSelf=%4 valid=%5",_a2edcPreviewPos,count _a2edcPreviewHouses,count _a2edcPreviewRealHouses,(count _a2edcPreviewHouses) - (count _a2edcPreviewRealHouses),(count _a2edcPreviewRealHouses) == 0];
											};
											if (A2EDC_housePreviewValid && {(count _a2edcPreviewRealHouses) > 0}) then {A2EDC_housePreviewValid = false; _a2edcPreviewReason = "house_within_15m";};
											if ((_a2edcPreviewPos distance _a2edcPreviewLastCityPos) > 2) then {
												_a2edcPreviewCityValid = true;
												_a2edcPreviewCityReason = "no_true_city_house_blocker";
												{
													_type = typeOf _x;
													_modelPath = _x call _a2edcGetModelPath;
													_isLandClass = ["Land_",_type,false] call fnc_inString;
													_isExplicitUtility = (_type in _builOk);
													_isUtilityPattern = _type call _a2edcIsUtilityNonBlocker;
													_isCoastalPattern = [_type,_modelPath] call _a2edcIsCoastalNonBlocker;
													if (_x != _a2edcPreview && {_isLandClass && !_isExplicitUtility && !_isUtilityPattern && !_isCoastalPattern}) exitWith {
														_a2edcPreviewCityValid = false;
														_a2edcPreviewCityReason = format ["city_house_within_150m:%1",_type];
													};
												} forEach nearestObjects [_a2edcPreviewPos,["House"],150];
												_a2edcPreviewLastCityPos = +_a2edcPreviewPos;
											};
											if (A2EDC_housePreviewValid && {!_a2edcPreviewCityValid}) then {A2EDC_housePreviewValid = false; _a2edcPreviewReason = _a2edcPreviewCityReason;};
											_a2edcPreviewNature = nearestObjects [_a2edcPreviewPos,[],_syOfh];
											{
												if (_x != _a2edcPreview && {_x != _a2edcPreviewMarker} && {!(_x getVariable ["A2EDC_housePreviewLocal",false])}) then {
													if ((["t_",str(_x),false] call fnc_inString) || {(["r2_",str(_x),false] call fnc_inString)}) exitWith {A2EDC_housePreviewValid = false; _a2edcPreviewReason = "tree_or_rock";};
												};
											} forEach _a2edcPreviewNature;
											_a2edcPreviewColor = if (A2EDC_housePreviewValid) then {"green"} else {"red"};
											A2EDC_housePreviewInvalidReason = _a2edcPreviewReason;
											if (A2EDC_housePreviewValid) then {
												_a2edcPreview setPosATL _a2edcPreviewHiddenPos;
												_a2edcPreviewMarker setPosATL _a2edcPreviewPos;
											} else {
												_a2edcPreviewMarker setPosATL _a2edcPreviewHiddenPos;
												_a2edcPreview setPosATL _a2edcPreviewPos;
											};
											if (_a2edcPreviewColor != _a2edcPreviewLastColor) then {
												_a2edcPreviewObject = if (A2EDC_housePreviewValid) then {_a2edcPreviewMarker} else {_a2edcPreview};
												diag_log format ["A2EDC:HOUSE_PREVIEW_COLOR_SET blueprint=%1 color=%2 valid=%3 reason=%4 redGhost=%5 greenGhost=%6 activeGhost=%7 inactiveGhostPosition=%8",_this,_a2edcPreviewColor,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreviewObject,_a2edcPreviewHiddenPos];
												_a2edcPreviewLastColor = _a2edcPreviewColor;
											};
											if (A2EDC_housePreviewValid != _a2edcPreviewLastValid) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDITY_TRANSITION blueprint=%1 previousValid=%2 valid=%3 reason=%4 position=%5 direction=%6 color=%7",_this,_a2edcPreviewLastValid,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir,_a2edcPreviewColor];
												if (!A2EDC_housePreviewValid) then {diag_log format ["A2EDC:HOUSE_PREVIEW_INVALID_REASON blueprint=%1 reason=%2 buildPosition=%3 direction=%4 playerPosition=%5 playerDirection=%6",_this,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir,getPosATL player,direction player];};
												titleText [format ["Foundation placement %1: %2",if (A2EDC_housePreviewValid) then {"valid"} else {"invalid"},_a2edcPreviewReason], "PLAIN DOWN"];
											};
											if (A2EDC_housePreviewValid != _a2edcPreviewLastValid || {_a2edcPreviewLogUpdate}) then {
												diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDITY blueprint=%1 valid=%2 reason=%3 position=%4 direction=%5",_this,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir];
												diag_log format ["A2EDC:HOUSE_PREVIEW_VALIDITY_RESULT blueprint=%1 valid=%2 reason=%3 buildPosition=%4 direction=%5 preview=%6 marker=%7 water=%8 road=%9 nearbyHouses=%10 realHouses=%11 tents=%12 cityValid=%13 natureObjects=%14 blockerObject=%15 blockerType=%16 blockerDistance=%17 playerPosition=%18 playerDirection=%19",_this,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir,_a2edcPreview,_a2edcPreviewMarker,surfaceIsWater _a2edcPreviewPos,isOnRoad _a2edcPreviewPos,count _a2edcPreviewHouses,count _a2edcPreviewRealHouses,({!((_x getVariable ["A2EDC_adminTempObject",false]) && {(_x getVariable ["A2EDC_adminBuildingKit",""]) != ""})} count (nearestObjects [_a2edcPreviewPos,["TentStorage","TentStorageR"],_syOfh])),_a2edcPreviewCityValid,count _a2edcPreviewNature,if ((count _a2edcPreviewRealHouses) > 0) then {_a2edcPreviewRealHouses select 0} else {objNull},if ((count _a2edcPreviewRealHouses) > 0) then {typeOf (_a2edcPreviewRealHouses select 0)} else {""},if ((count _a2edcPreviewRealHouses) > 0) then {_a2edcPreviewPos distance (_a2edcPreviewRealHouses select 0)} else {-1},getPosATL player,direction player];
												_a2edcPreviewLastValid = A2EDC_housePreviewValid;
											};
											sleep 0.1;
										};
										diag_log format ["A2EDC:HOUSE_PREVIEW_UPDATE_LOOP_STOP blueprint=%1 choice=%2 alive=%3 valid=%4 reason=%5 position=%6 direction=%7 playerPosition=%8 playerDirection=%9 iteration=%10 elapsed=%11",_this,A2EDC_housePreviewChoice,alive player,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir,getPosATL player,direction player,_a2edcPreviewLoopIteration,time - _a2edcPreviewStartTime];
										player removeAction _a2edcConfirmAction;
										player removeAction _a2edcCancelAction;
										player removeAction _a2edcRotateLeftAction;
										player removeAction _a2edcRotateRightAction;
										diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_ACTION_REMOVE leftAction=%1 rightAction=%2 preview=%3 greenGhost=%4 redGhost=%5 finalDirection=%6",_a2edcRotateLeftAction,_a2edcRotateRightAction,_a2edcPreview,_a2edcPreviewMarker,_a2edcPreview,A2EDC_housePreviewDirection];
										deleteVehicle _a2edcPreview;
										deleteVehicle _a2edcPreviewMarker;
										diag_log format ["A2EDC:HOUSE_PREVIEW_CLEANUP blueprint=%1 choice=%2 preview=%3 marker=%4 previewNull=%5 markerNull=%6 confirmAction=%7 cancelAction=%8 rotateLeftAction=%9 rotateRightAction=%10",_this,A2EDC_housePreviewChoice,_a2edcPreview,_a2edcPreviewMarker,isNull _a2edcPreview,isNull _a2edcPreviewMarker,_a2edcConfirmAction,_a2edcCancelAction,_a2edcRotateLeftAction,_a2edcRotateRightAction];
										if (!alive player) then {A2EDC_housePreviewChoice = 0;};
										if (A2EDC_housePreviewChoice == 1 && {A2EDC_housePreviewRequestSent}) then {
											diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRMED blueprint=%1 position=%2 direction=%3 valid=%4 reason=%5 requestSent=true source=confirm_handler",_this,_a2edcPreviewPos,_a2edcPreviewDir,A2EDC_housePreviewValid,_a2edcPreviewReason];
											diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",true,1,"client_foundation_request_sent_by_confirm_handler",[],false];
										} else {
											diag_log format ["A2EDC:HOUSE_PREVIEW_CANCELLED blueprint=%1 choice=%2 valid=%3 reason=%4 position=%5 direction=%6 blueprintRemoved=false mixerDeleted=false",_this,A2EDC_housePreviewChoice,A2EDC_housePreviewValid,_a2edcPreviewReason,_a2edcPreviewPos,_a2edcPreviewDir];
											titleText ["House foundation placement cancelled.", "PLAIN DOWN"];
										};
										A2EDC_housePreviewChoice = nil;
										A2EDC_housePreviewValid = nil;
										A2EDC_housePreviewContext = nil;
										A2EDC_housePreviewObject = nil;
										A2EDC_housePreviewMarker = nil;
										A2EDC_housePreviewPosition = nil;
										A2EDC_housePreviewDirection = nil;
										A2EDC_housePreviewConfirmAction = nil;
										A2EDC_housePreviewCancelAction = nil;
										A2EDC_housePreviewRotateLeftAction = nil;
										A2EDC_housePreviewRotateRightAction = nil;
										A2EDC_housePreviewRotationOffset = nil;
										A2EDC_housePreviewInvalidReason = nil;
										A2EDC_housePreviewConfirmInProgress = nil;
										A2EDC_housePreviewRequestSent = nil;
									} else {
										_a2edcMatFail = if (isNil "A2EDC_houseBuildLastMaterialFailure") then {["materials","unknown",[],_nhouse,1,typeOf (_findMix select 0)]} else {A2EDC_houseBuildLastMaterialFailure};
										diag_log format ["A2EDC:HOUSE_PREVIEW_START_BLOCKED reason=client_material_check_failed item=%1 uid=%2 selectedBuilding=%3 nhouse=%4 materialFailure=%5",_this,_playerID,_buildobj,_nhouse,_a2edcMatFail];
										diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5 selectedBlueprint=%6 selectedBuilding=%7 nhouse=%8 materialFailure=%9",false,1,"client_material_check_failed",if ((count _a2edcMatFail) > 2) then {_a2edcMatFail select 2} else {[]},false,_this,_buildobj,_nhouse,_a2edcMatFail];
										["materials",if ((count _a2edcMatFail) > 1) then {_a2edcMatFail select 1} else {"unknown"},if ((count _a2edcMatFail) > 2) then {_a2edcMatFail select 2} else {[]}] call _a2edcDebugFail;
										};
								};
						} else { if (_placementGateFailed) then { if (_cityGateFailed) then { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"city_and_placement_check_failed",[],false]; diag_log "A2EDC:HOUSE_BUILD_PLACEMENT_RESULT final=blocked_by_city_and_placement placement_message_already_emitted=true"; } else { diag_log "A2EDC:HOUSE_BUILD_PLACEMENT_RESULT final=blocked_by_placement message_already_emitted=true"; }; } else { if (_cityGateFailed) then { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"city_check_failed",[],false]; ["city_check","city house within 150m",[_posit]] call _a2edcDebugFail; } else { if (_qtyB) then { diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",false,1,"placement_blocker_unknown",[],false]; ["unknown","placement branch ended without request",[_posit]] call _a2edcDebugFail; }; }; }; };
		//stopGo
	};};};};
};

if (_new == "ARRAY") then {
	diag_log format ["START UPGRADE BUILDING"];
	_recived = _this select 3;
		_object = _recived select 0;
		_level = _recived select 1;
		_rawType = typeOf _object;
		_type = _object getVariable ["A2EDC_DBHouseType",_rawType];
		if (_type == "Uroven1VelkaBudka") then {_type = "large_shed_lvl_1";};
		_isStage2TargetMissing = (isNull _object) or !(_type in ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage","object_x"]);
		if (_isStage2TargetMissing) then {
			diag_log format ["A2EDC:HOUSE_STAGE2_TARGET_MISSING object=%1 rawType=%2 dbHouseType=%3 level=%4 player=%5 playerPos=%6 cursorTarget=%7 reason=%8",_object,_rawType,_type,_level,player,getPosATL player,cursorTarget,"null_or_non_house_target"];
		} else {
			diag_log format ["A2EDC:HOUSE_STAGE2_TARGET_FOUND object=%1 rawType=%2 dbHouseType=%3 level=%4 objectID=%5 objectUID=%6 owner=%7 position=%8",_object,_rawType,_type,_level,_object getVariable ["ObjectID","0"],_object getVariable ["ObjectUID","net"],_object getVariable ["CharacterID","0"],getPosATL _object];
		};
		_hiry = if (_isStage2TargetMissing) then {[[],[]]} else {getMagazineCargo _object};
			diag_log format ["A2EDC:HOUSE_STAGE2_SOURCE_EXPECTED action=client_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 expectedSource=%5 objectID=%6 objectUID=%7",_object,_rawType,_type,_level,"house_cargo",_object getVariable ["ObjectID","0"],_object getVariable ["ObjectUID","net"]];
			diag_log format ["A2EDC:HOUSE_STAGE2_CARGO_BEGIN action=client_stage_upgrade object=%1 rawType=%2 dbHouseType=%3 level=%4 expectedSource=house_cargo",_object,_rawType,_type,_level];
			diag_log format ["A2EDC:HOUSE_STAGE2_CARGO_CHECK object=%1 rawType=%2 dbHouseType=%3 level=%4 cargoMagazinesCount=%5 cargo=%6",_object,_rawType,_type,_level,count (_hiry select 0),_hiry];
		diag_log format ["A2EDC:HOUSE_BUILD_ACTION item=%1 action=stage_upgrade uid=%2 player=%3 playerPos=%4 cursorTarget=%5 selectedBlueprint=%6 selectedBuilding=%7",_level,getPlayerUID player,player,getPosATL player,cursorTarget,"",_type];
	_itOKbu = false;
	_stopGo = false;
	_nextlevelb = 0;

	_playerID = getPlayerUID player;
	_a2edcPlayerBbBase = player getVariable ["bb_base",[]];
	if ((count bb_base) != 8 && {(count _a2edcPlayerBbBase) == 8}) then {bb_base = +_a2edcPlayerBbBase;};
	if ((count bb_base) != 8) exitWith {
		diag_log format ["A2EDC:HOUSE_BUILD_SYNC_GUARD_FAIL variable=bb_base value=%1 expected=count_8 action=stage_upgrade item=%2 uid=%3 player=%4 playerVariable=%5",bb_base,_level,_playerID,player,_a2edcPlayerBbBase];
		titletext ["Cannot build at this moment, please wait while synchronization with server is completed.", "PLAIN DOWN"];
		_stopGo = true;
	};
	if (!_stopGo) then {
			_objectID = _object getVariable ["CharacterID",0];
			_ObjectUID = _object getVariable ["ObjectUID","net"];
			_stage2IdentityReady = ((_ObjectUID == "net") && {((_object getVariable ["ObjectID","0"]) != "0")});
			_stage2RejectReason = "ready";
			if (_ObjectUID != "net") then {_stage2RejectReason = "foundation_drying_objectuid_present_wait_for_hive_reload";};
			if ((_object getVariable ["ObjectID","0"]) == "0") then {_stage2RejectReason = "missing_database_objectid_wait_for_hive_reload";};
			diag_log format ["A2EDC:HOUSE_STAGE2_ACTION_%1 object=%2 rawType=%3 dbHouseType=%4 level=%5 owner=%6 playerID=%7 objectID=%8 objectUID=%9 identityReady=%10 reason=%11",if (_stage2IdentityReady) then {"AVAILABLE"} else {"REJECTED"},_object,_rawType,_type,_level,_objectID,_playerID,_object getVariable ["ObjectID","0"],_ObjectUID,_stage2IdentityReady,_stage2RejectReason];
			if (_stage2IdentityReady) then {
			_lopata = "ItemEtool" in items player;
			_hasToolbox = "ItemToolbox" in items player;
			if (!_hasToolbox) 	exitWith { titletext ["You need a ItemToolbox to begin building this house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_lopata) 		exitWith { titletext ["You need a ItemEtool to begin building this house.", "PLAIN DOWN"]; _stopGo = true; };
			if (_playerID != _objectID) exitWith { titletext ["You not the owner of this building", "PLAIN DOWN"]; _stopGo = true; };
			_nextlevelb = _level + 1;
			diag_log format ["LOG_UPD _object=%1,_level=%2,bb_base=%3,_playerID=%4,_nextlevelb=%5",_object,_level,bb_base,_playerID,_nextlevelb];
			//"wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"
			if (!_stopGo) then {
				player removeAction s_player_1bupd;
				s_player_1bupd = -1;
				if ((_type == "wooden_shed_lvl_1") OR (_type == "large_shed_lvl_1")) then {
					if ((_level < 2)&&(bb_base select 0 == 1)) then {
						//password start
						//diag_log ("START Open Dialog");
						_deagOK = createDialog "KeypadHouse";
						waitUntil { !dialog };
						if (CODE != "") then {
						_passUch = [CODEINPUT,CODE] call _chePsw;
						};
						//diag_log ("END Open Dialog");
							if (_passUch select 1) then {
								[_object,1,2,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,1,2] call _invChe;
								diag_log format ["1b1h_itOKbu=%1",_itOKbu];
						} else { _stopGo = true; };
					};
				};
				if ((_type == "log_house_lvl_2") OR (_type == "small_house_lvl_2")) then {
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN",4]; };
					if ((_level < 4)&&(bb_base select 1 == 1)) then {
						if (_nextlevelb > 2) then {
							//diag_log ("START Open Dialog");
							_deagOK = createDialog "KeypadHouse";
							waitUntil { !dialog };
							if (CODE != "") then {
							_passUch = [CODEINPUT,CODE] call _chePsw;
							};
							//diag_log ("END Open Dialog");
								if (_passUch select 1) then {
									[_object,2,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
									_itOKbu  = [_object,2,_nextlevelb] call _invChe;
									//diag_log format ["2b_itOKbu=%1",_itOKbu];
								} else { _stopGo = true; };
							} else {
								[_object,2,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,2,_nextlevelb] call _invChe;
							//diag_log format ["2b2h_itOKbu=%1",_itOKbu];
						};
					};
				};
				if (_type == "wooden_house_lvl_3") then {
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN",4]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN",4]; };
					if ((_level < 8)&&(bb_base select 2 == 1)) then {
						if (_nextlevelb > 2) then {
							//diag_log ("START Open Dialog");
							_deagOK = createDialog "KeypadHouse";
							waitUntil { !dialog };
							if (CODE != "") then {
								_passUch = [CODEINPUT,CODE] call _chePsw;
							};
							//diag_log ("END Open Dialog");
								if (_passUch select 1) then {
									[_object,3,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
									_itOKbu  = [_object,3,_nextlevelb] call _invChe;
								//diag_log format ["3b_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
							} else {
								[_object,3,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,3,_nextlevelb] call _invChe;
							//diag_log format ["3b_itOKbu=%1",_itOKbu];
						};
					};
				};

				if (_type == "big_house_lvl_3") then {
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN",4]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN",4]; };
					if ((_level < 8)&&(bb_base select 2 == 1)) then {
						if (_nextlevelb > 1) then {
							//diag_log ("START Open Dialog");
							_deagOK = createDialog "KeypadHouse";
							waitUntil { !dialog };
							if (CODE != "") then {
								_passUch = [CODEINPUT,CODE] call _chePsw;
							};
							//diag_log ("END Open Dialog");
								if (_passUch select 1) then {
									[_object,33,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
									_itOKbu  = [_object,33,_nextlevelb] call _invChe;
								//diag_log format ["3h_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
							} else {
								[_object,33,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,33,_nextlevelb] call _invChe;
							//diag_log format ["3h_itOKbu=%1",_itOKbu];
						};
					};
				};

				if (_type == "small_garage") then {
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN",4]; };
					if ((_level < 4)&&(bb_base select 3 == 1)) then {
						if (_nextlevelb > 2) then {
							//diag_log ("START Open Dialog");
							_deagOK = createDialog "KeypadHouse";
							waitUntil { !dialog };
							if (CODE != "") then {
								_passUch = [CODEINPUT,CODE] call _chePsw;
							};
							//diag_log ("END Open Dialog");
								if (_passUch select 1) then {
									[_object,4,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
									_itOKbu  = [_object,4,_nextlevelb] call _invChe;
								//diag_log format ["1g_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
							} else {
								[_object,4,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,4,_nextlevelb] call _invChe;
							//diag_log format ["1g_itOKbu=%1",_itOKbu];
						};
					};
				};
				if (_type == "big_garage") then {
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN",4]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN",4]; };
					if (bb_base select 7 == 0) then { _stopGo = true; titletext ["You need to finish building a level 3 house first.", "PLAIN DOWN",4]; };
					if ((_level < 4)&&(bb_base select 4 == 1)) then {
						if (_nextlevelb > 2) then {
							//diag_log ("START Open Dialog");
							_deagOK = createDialog "KeypadHouse";
							waitUntil { !dialog };
							if (CODE != "") then {
								_passUch = [CODEINPUT,CODE] call _chePsw;
							};
							//diag_log ("END Open Dialog");
								if (_passUch select 1) then {
									[_object,5,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
									_itOKbu  = [_object,5,_nextlevelb] call _invChe;
								//diag_log format ["2g_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
							} else {
								[_object,5,_nextlevelb,30,getPosATL _object] call _a2edcScanDiagnostics;
								_itOKbu  = [_object,5,_nextlevelb] call _invChe;
							//diag_log format ["2g_itOKbu=%1",_itOKbu];
						};
					};
				};

				//diag_log format ["_itOKbu=%1",_itOKbu];
				if (!_stopGo) then {
					if (_itOKbu) then {
						//diag_log ("_itOKbu");
						[player,"bbupdb",0,false] call dayz_zombieSpeak;
						player playActionNow "Medic";
						sleep 5;
						player playActionNow "Medic";
						sleep 4;

								wantbbplz = [player,_nextlevelb,_playerID,_object,_passUch select 0];
								diag_log format ["wantbbplz=%1",wantbbplz];
								publicVariableServer "wantbbplz";
								diag_log format ["A2EDC:HOUSE_STAGE2_UPGRADE_REQUEST_SENT object=%1 rawType=%2 dbHouseType=%3 currentLevel=%4 nextLevel=%5 owner=%6 playerID=%7 objectID=%8 objectUID=%9 cargo=%10",_object,_rawType,_type,_level,_nextlevelb,_objectID,_playerID,_object getVariable ["ObjectID","0"],_ObjectUID,getMagazineCargo _object];
								diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=true gate=client_request reason=upgrade_request_sent object=%1 dbHouseType=%2 currentLevel=%3 nextLevel=%4",_object,_type,_level,_nextlevelb];
								diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5",true,_nextlevelb,"client_upgrade_request_sent",[],false];
							} else {
							_a2edcMatFail = if (isNil "A2EDC_houseBuildLastMaterialFailure") then {["materials","unknown",[],_nextlevelb,1,typeOf _object]} else {A2EDC_houseBuildLastMaterialFailure};
								diag_log format ["A2EDC:HOUSE_BUILD_RESULT allowed=%1 stage=%2 reason=%3 missingSummary=%4 materialRemoved=%5 materialFailure=%6",false,_nextlevelb,"client_upgrade_material_check_failed",if ((count _a2edcMatFail) > 2) then {_a2edcMatFail select 2} else {[]},false,_a2edcMatFail];
								diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=materials reason=%1 object=%2 dbHouseType=%3 currentLevel=%4 nextLevel=%5 missingSummary=%6",if ((count _a2edcMatFail) > 1) then {_a2edcMatFail select 1} else {"unknown"},_object,_type,_level,_nextlevelb,if ((count _a2edcMatFail) > 2) then {_a2edcMatFail select 2} else {[]}];
								["materials",if ((count _a2edcMatFail) > 1) then {_a2edcMatFail select 1} else {"unknown"},if ((count _a2edcMatFail) > 2) then {_a2edcMatFail select 2} else {[]}] call _a2edcDebugFail;
							};
					} else { titletext ["Password is incorrect or you need to finish other building", "PLAIN DOWN"]; };
				};
			} else {
				diag_log format ["A2EDC:HOUSE_STAGE2_RESULT allowed=false gate=identity reason=%1 object=%2 rawType=%3 dbHouseType=%4 level=%5 objectID=%6 objectUID=%7 owner=%8",_stage2RejectReason,_object,_rawType,_type,_level,_object getVariable ["ObjectID","0"],_ObjectUID,_objectID];
				titletext ["The foundation needs 24 hours(Game Time) to dry - you can collect other materials and add it to the house inventory during this time.", "PLAIN DOWN"];
			};
	} else { titletext ["Wrong Data", "PLAIN DOWN"]; };
};
