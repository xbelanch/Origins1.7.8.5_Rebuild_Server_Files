private["_item"];
_item = _this;
call gear_ui_init;
_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

if(!isnil("dayzLogin")) exitWith {
	0 cutText ["", "BLACK",10];
	diag_log "DEBUG: pirated server";
	disableUserInput false;
	1 cutText ["WARNING !!! This is un-official server of Origins Mod and does not represent the mod concepts or gameplay experience intended by the developers.", "PLAIN",15];
	player enableSimulation false;
};

if(!isnil("dayzLogin2")) exitWith {
	diag_log "DEBUG: pirated server";
	disableUserInput false;
	1 cutText ["WARNING !!! This is un-official server of Origins Mod and does not represent the mod concepts or gameplay experience intended by the developers.", "PLAIN",15];
	player enableSimulation false;
};

_hasmeditem = _this in magazines player;

_config = configFile >> "CfgMagazines" >> _item;
_text = getText (_config >> "displayName");

if (!_hasmeditem) exitWith {cutText [format[(localize "str_player_31"),_text,"use"] , "PLAIN DOWN"]};

switch (_item) do {
	case "ItemBandage": {
		_id = [0,0,0,[player]] execVM "\z\addons\dayz_code\medical\bandage.sqf";
	};
	case "ItemMorphine": {
		_id = [0,0,0,[player]] execVM "\z\addons\dayz_code\medical\morphine.sqf";
	};
	case "ItemPainkiller": {
		_id = [0,0,0,[player]] execVM "\z\addons\dayz_code\medical\painkiller.sqf";
	};
	case "ItemAntibiotic": {
		_id = [0,0,0,[player]] execVM "\z\addons\dayz_code\medical\antibiotics.sqf";
	};
	case "ItemHeatPack": {
		player removeMagazine "ItemHeatPack";
		dayz_temperatur = (dayz_temperatur + 5) min dayz_temperaturmax;
		cutText [localize "str_player_27", "PLAIN DOWN"];
	};
};