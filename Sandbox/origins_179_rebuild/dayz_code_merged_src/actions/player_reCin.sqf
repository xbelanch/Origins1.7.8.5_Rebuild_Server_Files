private["_item"];
disableSerialization;
_item = 	_this;
_config =	configFile >> "CfgMagazines" >> _item;

_consume = 	getArray (_config >> "ItemActions" >> "ReloadMag" >> "use");
_create = 	getArray (_config >> "ItemActions" >> "ReloadMag" >> "output");

_textConsume1 =	getText(configFile >> "CfgMagazines" >> (_consume select 0) >> "displayName");
_textConsume2 =	getText(configFile >> "CfgMagazines" >> (_consume select 2) >> "displayName");
_textCreate =	getText(configFile >> "CfgMagazines" >> (_create select 0) >> "displayName");

_amountHas1 = {_x == (_consume select 0)} count magazines player;
_amountHas2 = {_x == (_consume select 2)} count magazines player;
_amountMake = 1;

_hasInput = (((_amountHas1 + _amountHas2) / 2) == 2);
if (_hasInput) then {
	player playActionNow "PutDown";
	{
		player removeMagazine _x;
	} forEach _consume;
	sleep 1;
	player addMagazine "ItemCinderblocks";
	cutText [localize  "str_player_35", "PLAIN DOWN"];
} else {
	cutText [format[(localize  "str_player_36"),_textConsume1,_textConsume2], "PLAIN DOWN"];
};