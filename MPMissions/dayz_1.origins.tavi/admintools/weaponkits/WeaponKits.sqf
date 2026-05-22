private ["_gun","_ammo","_HEammo","_gear","_gunOne","_gunTwo","_traceWeaponClass"];
_handGuns = ["UZI_SD_EP1","glock17_EP1","revolver_EP1","revolver_gold_EP1","UZI_EP1","Sa61_EP1","M9","M9SD","Colt1911","Makarov","MakarovSD"];
_gun = _this select 0;
_ammo = _this select 1;
_HEammo = _this select 2;

_traceWeaponClass = {
	private ["_context","_weapon","_type","_reason"];
	_context = _this select 0;
	_weapon = _this select 1;
	_type = typeName _weapon;
	_reason = "";
	if (_type != "STRING") then {
		_reason = format ["non-string type=%1", _type];
	} else {
		if (_weapon == "") then {
			_reason = "empty string";
		} else {
			if (!(isClass(configFile >> "CfgWeapons" >> _weapon))) then {
				_reason = "missing CfgWeapons class";
			};
		};
	};
	if (_reason != "") then {
		diag_log format ["[A2EDC:WEAPON_CLASS] %1 invalid weapon=%2 reason=%3", _context, _weapon, _reason];
	};
};

// Get player's weapons
_gunOne = (weapons player) select 0;
_gunTwo = (weapons player) select 1;

// Remove the correct player weapon
if(_gun in _handGuns) then{
	if(_gunOne in _handGuns) then {["AdminTools WeaponKits removeWeapon _gunOne", _gunOne] call _traceWeaponClass; player removeWeapon _gunOne;} else {["AdminTools WeaponKits removeWeapon _gunTwo", _gunTwo] call _traceWeaponClass; player removeWeapon _gunTwo;};
} else {
	if(_gunOne in _handGuns) then {["AdminTools WeaponKits removeWeapon _gunTwo", _gunTwo] call _traceWeaponClass; player removeWeapon _gunTwo;} else {["AdminTools WeaponKits removeWeapon _gunOne", _gunOne] call _traceWeaponClass; player removeWeapon _gunOne;};
};

// Add Items
player addMagazine _ammo;
player addMagazine _ammo;
["AdminTools WeaponKits addWeapon _gun", _gun] call _traceWeaponClass;
if ((typeName _gun == "STRING") && (_gun != "")) then {
	player addWeapon _gun;
};
player selectWeapon _gun;
if(!(isNil _HEammo)) then {
	player addMagazine _HEammo;
};
