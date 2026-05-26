private ["_obj","_type","_config","_positions","_lootChance","_itemType","_itemChance","_iPos2","_rnd","_nearBy","_weights","_index","_iArray","_item"];
_obj = 			_this select 0;
_type = 		typeOf _obj;
_config = 		configFile >> "CfgBuildingLoot" >> _type;

_positions =	 [] + getArray (_config >> "lootPos");
//diag_log ("LOOTSPAWN: READ:" + str(_type));
_lootChance =	getNumber (_config >> "lootChance");
_itemType =		 [] + getArray (_config >> "itemType");
//diag_log ("LOOTSPAWN: READ:" + str(_itemType));
_itemChance =	 [] + getArray (_config >> "itemChance");	

//diag_log format ["LOOTSPAWN: Type %1 / Chance %2 - Building:%3, Type:%4",(count _itemType),(count _itemChance),_config,_type];

//diag_log ("I want to spawn loot...");

{
	private["_iPos2"];
	_iPos2 = _obj modelToWorld _x;
	//diag_log format ["_iPos2 = %1",_iPos2];
	_rnd = random 1;
	//Place something at each position
	if (player distance _iPos2 > 50) then {
		//diag_log format ["_iPos2 = %1, PlayerDistance=%2",_iPos2,(player distance _iPos2)];
		if (_rnd < _lootChance) then {
			//if (true) then {	
				_nearBy = nearestObjects [_iPos2, ["WeaponHolder","WeaponHolderBase"],1];
				if (count _nearBy == 0) then {
					private["_index","_iArray"];
					_weights = [_itemType,_itemChance] call fnc_buildWeightedArray;
					_index = _weights call BIS_fnc_selectRandom;
					//diag_log ("LOOTSPAWN: _itemType:" + str(_itemType));
					//diag_log ("LOOTSPAWN: _index:" + str(_index));
					if (_index >= 0) then {
						_iArray = +(_itemType select _index);
						//diag_log ("LOOTSPAWN: _iArray" + str(_iArray));
						_iArray set [2,_iPos2];
						_iArray set [3,0];
						_iArray call spawn_loot;
						_iArray = [];
						//diag_log ("LOOTSPAWN");
					};
					_item setVariable ["created",(DateToNumber date),true];
				};
			//};
		};
	};
} forEach _positions;