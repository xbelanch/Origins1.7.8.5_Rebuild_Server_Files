private["_item","_isFemale","_itemNew","_item","_onLadder","_model","_hasclothesitem","_config","_text","_fem_skin"];
_item = _this;
call gear_ui_init;
_onLadder = (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

_hasclothesitem = _this in magazines player;
_config = configFile >> "CfgMagazines";
_text = getText (_config >> _item >> "displayName");

if (!_hasclothesitem) exitWith {cutText [format[(localize "str_player_31"),_text,"wear"] , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText ["You may not change clothes while in a vehicle", "PLAIN DOWN"]};

_fem_skin = ["ori_vil_woman_survivor_1","ori_vil_woman_survivor_2","ori_vil_woman_survivor_3","ori_vil_woman_survivor_4","ori_vil_woman_survivor_5","ori_vil_woman_survivor_6","ori_vil_woman_bandit_1","ori_vil_woman_bandit_2","ori_vil_woman_bandit_3","ori_vil_woman_bandit_4","ori_vil_woman_bandit_5","ori_vil_woman_bandit_6","ori_vil_woman_hero_1","ori_vil_woman_hero_2","ori_vil_woman_hero_3","ori_vil_woman_hero_4","ori_vil_woman_hero_5","ori_vil_woman_hero_6","SurvivorW2_DZ","BanditW1_DZ"];

_isFemale = (typeOf player in _fem_skin);
if (_isFemale) exitWith {cutText ["Currently Female Characters cannot change to this skin. This will change in a future update.", "PLAIN DOWN"]};

private["_itemNew","_myModel","_humanity","_isBandit","_isHero"];
_myModel = (typeOf player);
_humanity = player getVariable ["humanity",2500];
_isBanditW = (_myModel=="BanditW1_DZ");

_isBandit = false;
if((_humanity > -6500) and (_humanity <= 2000)) then {
	_isBandit = true;
};
_isBandit2 = false;
if((_humanity >= -15000) and (_humanity <= -6500)) then {
	_isBandit2 = true;
};
_isBandit3 = false;
if(_humanity < -15000) then {
	_isBandit3 = true;
};
_isHero = false;
if((_humanity >= 2900) and (_humanity < 6500)) then {
	_isHero = true;
};
_isHero2 = false;
if((_humanity >= 6500) and (_humanity <= 15000)) then {
	_isHero2 = true;
};
_isHero3 = false;
if(_humanity > 15000) then {
	_isHero3 = true;
};

if (_myModel=="Bandit_S_DZ") then {
	_myModel = "Sniper1_DZ";
};
if ((_item == "Skin_Survivor2_DZ") and (_myModel!="Bandit_S_DZ") and (_myModel != "Sniper1_DZ")) then {
	player removeMagazine _item;
};

/*
if (_myModel == "Sniper1_DZ") then {
	if ( !(isClass(_config >> _itemNew)) ) then {
		_itemNew = if (!_isFemale) then {"Skin_Survivor2_DZ"} else {"Skin_SurvivorW2_DZ"}; 
	};
};
*/

switch (_item) do {
	case "Skin_Sniper1_DZ": {
		if((_isBandit) or (_isBandit2) or (_isBandit3)) then {
			_model = "Bandit_S_DZ";
		} else {
			_model = "Sniper1_DZ";
		};
		_itemNew = "Skin_Survivor2_DZ";

	};
	/*
	case "Skin_Camo1_DZ": {
		_model = "Camo1_DZ";
	};
	case "Skin_Soldier1_DZ": {
		_model = "Soldier1_DZ";
	};
	*/
	case "Skin_Survivor2_DZ": {
	 if (_myModel == "Sniper1_DZ") then {
		_itemNew = "Skin_Sniper1_DZ";
		_model = "Survivor2_DZ";
		if (_isFemale) then {
			_model = "SurvivorW2_DZ";
			if (_isBanditW) then {
				_model = "BanditW1_DZ";
			};
		};
		if (_isBandit) then {
			_model = ["Bandit1_1DZ","Bandit1_2DZ","Bandit1_3DZ","Bandit1_3_1DZ","Bandit1_3_2DZ","Bandit1_DZ"] select floor random 6;
		};
		if (_isBandit2) then {
			_model = ["Bandit2_1DZ","Bandit2_2DZ","Bandit2_3DZ","Bandit2_4DZ","Bandit2_5DZ"] select floor random 5;
		};
		if (_isBandit3) then {
			_model = "Bandit3_1";
		};
		if (_isHero) then {
			_model = ["Survivor3_DZ","Hero1_1DZ","Hero1_2DZ","Hero1_3DZ","Hero1_4DZ","Hero1_5DZ","Hero1_6DZ","Hero1_7DZ"] select floor random 8;
		};
		if (_isHero2) then {
			_model = ["Hero2_1DZ","Hero2_2DZ","Hero2_3DZ","Hero2_4DZ","Hero2_5DZ","Hero2_10DZ"] select floor random 6;
		};
		if (_isHero3) then {
			_model = ["Hero3_1DZ","Hero3_2DZ","Hero3_3DZ","Hero3_4DZ","Hero3_5DZ","Hero3_6DZ"] select floor random 6;
		};
	}; };
};

if (_model != _myModel) then {
		player removeMagazine _item;
		player addMagazine _itemNew;
	[dayz_playerUID,dayz_characterID,_model] spawn player_humanityMorph;
	};
