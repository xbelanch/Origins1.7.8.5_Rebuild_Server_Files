private["_new","_itOKbu","_passwordN","_Ok","_invChe","_objectF","_house","_stage","_typeOF","_hiry","_hinv","_objWpnTypes","_objWpnQty","_countr","_vsegoMaterial","_bOk","_qtyR","_qtyW","_qtyS","_qtyC","_qtyB","_qtyP","_qtyL","_chePsw","_codeArray","_codeString","_status","_pcount","_playerID","_lopata","_hasToolbox","_hasBlueprint","_buildobj","_text","_isSurvi_p","_isHero1_p","_isHero2_p","_isBandit1_p","_isBandit2_p","_isBandit3_p","_humanityVP","_isHero3_p","_nhouse","_syOfh","_qtyT","_ctentb","_posit","_listBB","_findMix","_listMix","_recived","_object","_level","_type","_nextlevelb","_objectID","_deagOK","_passUch","_stopGo","_ObjectUID","_builOk"];
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

_invChe = {
	_objectF = _this select 0;
	_house = _this select 1;
	_stage = _this select 2;
	_typeOF = typeOf _objectF;
	_hiry = getMagazineCargo _objectF;
	//diag_log format ["_hinv=%1(%2),o=%3,to=%4",_hiry,(count _hiry),_objectF,_typeOF];
	_objWpnTypes = (_hiry select 0);
	_objWpnQty = (_hiry select 1);
	_countr = 0;
	_vsegoMaterial = 0;
	_bOk = false;
	_qtyR = 0; _qtyW = 0; _qtyS = 0; _qtyC = 0; _qtyB = 0; _qtyP = 0; _qtyL = 0; 
	if (count _hiry > 0) then {
		//"PartWoodPile" "PartRock"	"PartScrap" "ItemCementBag" "ItemBattery" "ItemPin" "ItemCinderblocks"
		{
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
	if (count bb_base == 0) exitWith { titletext ["Cannot build at this moment, please wait while synchronization with server is completed.", "PLAIN DOWN"]; _stopGo = true; };
	if (!_stopGo) then {
		ConstrSt = true;
		_playerID =	getPlayerUID player;
		_lopata = "ItemEtool" in items player;
		_hasToolbox = "ItemToolbox" in items player;
		_hasBlueprint = _this in magazines player;
		
		if (!(_this in ["ItemBpt_b1","ItemBpt_b2","ItemBpt_b3","ItemBpt_h1","ItemBpt_h2","ItemBpt_h3","ItemBpt_g_s","ItemBpt_g_b"])) exitWith { diag_log format ["Wrong item(%1) recived",_this]; _stopGo = true; };
		if (!_stopGo) then {
			if (!_hasBlueprint) exitWith { titletext ["You need a Blueprint to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_hasToolbox) 	exitWith { titletext ["You need a Tool Box to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_lopata) 		exitWith { titletext ["You need to have an Enternchment Tool to begin building a house.", "PLAIN DOWN"]; _stopGo = true; };
			if (!_stopGo) then {
				_buildobj = getText (configFile >> "CfgMagazines" >> _this >> "ItemActions" >> "Build" >> "create");
				_text = 	getText (configFile >> "CfgVehicles" >> _buildobj >> "displayName");
				
				_humanityVP 	= player getVariable ["humanity",2500];
				if (_humanityVP > 2000 and _humanityVP < 2900) then { _isSurvi_p = true;};
				if (_isSurvi_p) exitWith { titletext ["For build house you need to be Heroe or Bandit", "PLAIN DOWN"]; _stopGo = true; };
				
				if (_humanityVP >= 2900 and _humanityVP < 6500) then  { _isHero1_p = true; };
				if (_humanityVP >= 6500 and _humanityVP <= 15000) then { _isHero2_p = true; };
				if (_humanityVP > 15000) then { _isHero3_p = true; };
				
				if (_humanityVP > -6500 and _humanityVP <= 2000) then { _isBandit1_p = true; };
				if (_humanityVP >= -15000 and _humanityVP <= -6500) then { _isBandit2_p = true; };
				if (_humanityVP < -15000) then { _isBandit3_p = true; };

				//"wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"
				if (_buildobj == "wooden_shed_lvl_1") then { _nhouse = 1; _syOfh = 13;
					if (!_isBandit1_p && !_isBandit2_p && !_isBandit3_p) then { _stopGo = true; titletext ["Only Bandits can build this house", "PLAIN DOWN"]; };
					if (bb_base select 0 == 1) then { _stopGo = true; titletext ["You have already built a level 1 house.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "log_house_lvl_2") then { _nhouse = 2; _syOfh = 20;
					if (!_isBandit2_p && !_isBandit3_p) then { _stopGo = true; titletext ["Only Bandit level 2 can build this house", "PLAIN DOWN"]; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 1) then { _stopGo = true; titletext ["You have already built a level 2 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "wooden_house_lvl_3") then { _nhouse = 3; _syOfh = 14;
					if (!_isBandit3_p) then { _stopGo = true; titletext ["Only Bandit level 3 can build this house", "PLAIN DOWN"]; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 0) then { _stopGo = true; titletext ["You need to build a level 2 house first.", "PLAIN DOWN"]; };
					if (bb_base select 2 == 1) then { _stopGo = true; titletext ["You have already built a level 3 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "large_shed_lvl_1") then { _nhouse = 1; _syOfh = 13;
					if (!_isHero1_p && !_isHero2_p && !_isHero3_p) then { _stopGo = true; titletext ["Only Heroes can build this house", "PLAIN DOWN"]; };
					if (bb_base select 0 == 1) then { _stopGo = true; titletext ["You have already built a level 1 house.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "small_house_lvl_2") then { _nhouse = 2; _syOfh = 10;
					if (!_isHero2_p && !_isHero3_p) then { _stopGo = true; titletext ["Only Heroe level 2 can build this house", "PLAIN DOWN"]; };
					if (bb_base select 0 == 0) then { _stopGo = true; titletext ["You need to build a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 1 == 1) then { _stopGo = true; titletext ["You have already built a level 2 house.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
				};
				if (_buildobj == "big_house_lvl_3") then { _nhouse = 33; _syOfh = 14;
					if (!_isHero3_p) then { _stopGo = true; titletext ["Only Heroe level 3 can build this house", "PLAIN DOWN"]; };
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
					if (!_isBandit3_p && !_isHero3_p) then { _stopGo = true; titletext ["Only Bandit or Heroe level 3 can build this house", "PLAIN DOWN"]; };
					if (bb_base select 2 == 0)  then { _stopGo = true; titletext ["You need to build a level 3 house first.", "PLAIN DOWN"]; };
					if (bb_base select 4 == 1) then { _stopGo = true; titletext ["You have already built a big garage.", "PLAIN DOWN"]; };
					if (bb_base select 5 == 0) then { _stopGo = true; titletext ["You need to finish building a level 1 house first.", "PLAIN DOWN"]; };
					if (bb_base select 6 == 0) then { _stopGo = true; titletext ["You need to finish building a level 2 house first.", "PLAIN DOWN"]; };
					if (bb_base select 7 == 0) then { _stopGo = true; titletext ["You need to finish building a level 3 house first.", "PLAIN DOWN"]; };
				};
				
				if (!_stopGo) then {
					_qtyB = true;
					_qtyT = true;
					_ctentb = true;
					_posit = player modeltoworld [0,7,0];
					_isRoadorNot = isOnRoad _posit;
					if (_isRoadorNot) exitWith { titletext ["You can not build a house on a road or if you are within 150m of a city", "PLAIN DOWN"]; _qtyB = false; };
					_builOk = ["Land_sloup_vn_drat","Land_sloup_vn","Land_telek1","Land_Ind_Timbers","Land_Misc_deerstand","Land_Rail_Zavora","Land_Rail_Semafor","Land_majak","Land_majak_podesta","Land_majak2","small_bunker"];
					{
						if (!(typeOf _x in _builOk)) then {
							if ((["Land_",(typeOf _x),false] call fnc_inString)) exitWith { _qtyB = false; };
						};
					} forEach nearestObjects [_posit, ["House"], 150];
					_ctentb = count (nearestObjects [_posit, ["TentStorage","TentStorageR"], _syOfh]) == 0;
					if (!_ctentb) then { titletext ["Cannot build here. Structures are obstructng this area.", "PLAIN DOWN"]; _qtyB = false; };
					if (_qtyB) then {
						_listBB = count (nearestObjects [_posit, ["wooden_shed_lvl_1","log_house_lvl_2","wooden_house_lvl_3","large_shed_lvl_1","small_house_lvl_2","big_house_lvl_3","small_garage","big_garage"], 15]) == 0;
						if (!_listBB) exitWith { titletext ["To build a house, you need to be at least 16 meters away from other house.", "PLAIN DOWN"]; };
						{
							if ((["t_",str(_x),false] call fnc_inString)) exitWith { titletext ["You cannot build here. Trees are obsructing this area.", "PLAIN DOWN"]; _qtyT = false; };
							if ((["r2_",str(_x),false] call fnc_inString)) exitWith { titletext ["You cannot build here. Rocks are obsructing this area.", "PLAIN DOWN"]; _qtyT = false; };
						} forEach nearestObjects [_posit, [], _syOfh];
						
						if (_qtyT) then {
							_findMix = position player nearObjects ["CementMixer",10];
							_listMix = 	count _findMix == 1;
							if (!_listMix) exitWith { titletext ["You need to stay  within 10 meters of cement mixer.", "PLAIN DOWN"]; };
								_itOKbu = [_findMix select 0,_nhouse,1] call _invChe;
								if (_itOKbu) then {
									//diag_log format ["player=%1(%2),_this=%3(%4)",player,typeName player,_this,typeName _this];
									[player,"bbfundd",0,false] call dayz_zombieSpeak;
									player playActionNow "Medic";
									sleep 5;
									player playActionNow "Medic";
									sleep 4;
									player removeMagazine _this;
									wantbbplz = [player, _this, _playerID];
									publicVariableServer "wantbbplz";
									diag_log format ["wantbbplz=%1",wantbbplz];
								} else { titletext ["Not enough material", "PLAIN DOWN"]; };
						};
					} else { titletext ["To build a house, you need to be at least 150 meters away from city.", "PLAIN DOWN"]; };
		//stopGo
	};};};};
};

if (_new == "ARRAY") then {
	diag_log format ["START UPGRADE BUILDING"];
	_recived = _this select 3;
	_object = _recived select 0;
	_level = _recived select 1;
	_type = typeOf _object;
	_itOKbu = false;
	_stopGo = false;
	_nextlevelb = 0;
	
	if (count bb_base == 0) exitWith { titletext ["Cannot build at this moment, please wait while synchronization with server is completed.", "PLAIN DOWN"]; _stopGo = true; };
	if (!_stopGo) then {
		_playerID =	getPlayerUID player;
		_objectID = _object getVariable ["CharacterID",0];
		_ObjectUID = _object getVariable ["ObjectUID","net"];
		if (_ObjectUID == "net") then {
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
								_itOKbu  = [_object,2,_nextlevelb] call _invChe;
								//diag_log format ["2b_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
						} else {
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
								_itOKbu  = [_object,3,_nextlevelb] call _invChe;
								//diag_log format ["3b_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
						} else {
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
								_itOKbu  = [_object,33,_nextlevelb] call _invChe;
								//diag_log format ["3h_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
						} else {
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
								_itOKbu  = [_object,4,_nextlevelb] call _invChe;
								//diag_log format ["1g_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
						} else {
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
								_itOKbu  = [_object,5,_nextlevelb] call _invChe;
								//diag_log format ["2g_itOKbu=%1",_itOKbu];
							} else { _stopGo = true; };
						} else {
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
					} else { titletext ["Not enough material", "PLAIN DOWN"]; };
				} else { titletext ["Password is incorrect or you need to finish other building", "PLAIN DOWN"]; };
			};
		} else { titletext ["The foundation needs 24 hours(Game Time) to dry - you can collect other materials and add it to the house inventory during this time.", "PLAIN DOWN"]; };
	} else { titletext ["Wrong Data", "PLAIN DOWN"]; };
};