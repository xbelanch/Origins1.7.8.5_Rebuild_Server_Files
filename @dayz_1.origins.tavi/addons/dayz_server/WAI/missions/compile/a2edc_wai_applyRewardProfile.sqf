private ["_box","_profile","_mission"];

_box = _this select 0;
_profile = _this select 1;
_mission = _this select 2;

if (isNull _box) exitWith {
	diag_log format ["A2EDC:WAI:REWARD mission=%1 lootProfile=%2 result=skipped_null",_mission,_profile];
	false
};

_box setVariable ["ObjectID","0",true];
_box setVariable ["ObjectUID","0",true];
_box setVariable ["A2EDC_WAI_transientLoot",true,true];
_box setVariable ["permaLoot",true];

if (!(isNil "PVDZE_serverObjectMonitor")) then {
	PVDZE_serverObjectMonitor = PVDZE_serverObjectMonitor - [_box];
};

clearWeaponCargoGlobal _box;
clearMagazineCargoGlobal _box;
clearBackpackCargoGlobal _box;

switch (_profile) do {
	case "basic": {
		_box addMagazineCargoGlobal ["100Rnd_762x51_M240",2];
		_box addMagazineCargoGlobal ["200Rnd_762x51_M240",2];
		_box addMagazineCargoGlobal ["30Rnd_556x45_G36SD",6];
		_box addMagazineCargoGlobal ["ItemBandage",6];
		_box addMagazineCargoGlobal ["ItemMorphine",2];
		_box addWeaponCargoGlobal ["ItemToolbox",1];
		_box addBackpackCargoGlobal ["DZ_ALICE_Pack_EP1",1];
	};
	case "standard": {
		_box addMagazineCargoGlobal ["100Rnd_762x51_M240",5];
		_box addMagazineCargoGlobal ["200Rnd_762x51_M240",5];
		_box addMagazineCargoGlobal ["30Rnd_556x45_G36SD",15];
		_box addMagazineCargoGlobal ["75Rnd_545x39_RPK",5];
		_box addMagazineCargoGlobal ["ItemBandage",8];
		_box addMagazineCargoGlobal ["ItemMorphine",4];
		_box addWeaponCargoGlobal ["ItemToolbox",1];
		_box addBackpackCargoGlobal ["O_TravelerPack_1",1];
	};
	case "good": {
		_box addMagazineCargoGlobal ["100Rnd_762x51_M240",8];
		_box addMagazineCargoGlobal ["200Rnd_762x51_M240",8];
		_box addMagazineCargoGlobal ["30Rnd_556x45_G36SD",18];
		_box addMagazineCargoGlobal ["75Rnd_545x39_RPK",8];
		_box addMagazineCargoGlobal ["ItemBloodbag",6];
		_box addMagazineCargoGlobal ["ItemMorphine",6];
		_box addWeaponCargoGlobal ["ItemToolbox",2];
		_box addWeaponCargoGlobal ["ItemEtool",1];
		_box addBackpackCargoGlobal ["O_TravelerPack_1",2];
	};
	case "rare": {
		_box addMagazineCargoGlobal ["100Rnd_762x51_M240",10];
		_box addMagazineCargoGlobal ["200Rnd_762x51_M240",10];
		_box addMagazineCargoGlobal ["30Rnd_556x45_G36SD",20];
		_box addMagazineCargoGlobal ["75Rnd_545x39_RPK",10];
		_box addMagazineCargoGlobal ["ItemBloodbag",8];
		_box addMagazineCargoGlobal ["ItemAntibiotic",4];
		_box addWeaponCargoGlobal ["ItemToolbox",2];
		_box addWeaponCargoGlobal ["ItemEtool",2];
		_box addWeaponCargoGlobal ["Binocular_Vector",1];
		_box addBackpackCargoGlobal ["ori_30l_Backpack",1];
		_box addBackpackCargoGlobal ["O_TravelerPack_1",1];
	};
	default {
		_box addMagazineCargoGlobal ["100Rnd_762x51_M240",5];
		_box addMagazineCargoGlobal ["200Rnd_762x51_M240",5];
		_box addMagazineCargoGlobal ["30Rnd_556x45_G36SD",15];
		_box addBackpackCargoGlobal ["O_TravelerPack_1",1];
	};
};

diag_log format ["A2EDC:WAI:REWARD mission=%1 lootProfile=%2 class=%3",_mission,_profile,typeOf _box];
true
