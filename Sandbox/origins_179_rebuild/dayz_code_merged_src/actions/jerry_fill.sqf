private["_hasFood","_item","_text","_qty","_qtyB"];

player removeAction s_player_fillfuel;
s_player_fillfuel = -1;

_qty = {_x == "ItemJerrycanEmpty"} count magazines player;
_qtyB = {_x == "ItemJerrycanBEmpty"} count magazines player;
if (_qtyB > 2) then { _qtyB=2; };
if (("ItemJerrycanEmpty" in magazines player) or ("ItemJerrycanBEmpty" in magazines player)) then {
	if ("ItemJerrycanEmpty" in magazines player) then {
		for "_x" from 1 to _qty do {
			player removeMagazine "ItemJerrycanEmpty";
			player addMagazine "ItemJerrycan";
		};
	};
	if ("ItemJerrycanBEmpty" in magazines player) then {
		for "_x" from 1 to _qtyB do {
			player removeMagazine "ItemJerrycanBEmpty";
			player addMagazine "ItemJerrycanB";
		};
	};		
	[player,"refuel",0,false] call dayz_zombieSpeak;
	cutText [format[(localize  "str_player_09"),(_qty+_qtyB)], "PLAIN DOWN"];
} else {
	cutText [(localize "str_player_10") , "PLAIN DOWN"];
};