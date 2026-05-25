private ["_mission","_difficulty","_markerColor","_aiSkill","_aiSkillProfile","_lootProfile","_requestedMarkerColor"];

_mission = _this select 0;
_difficulty = "medium";

if (count _this > 1) then {
	_difficulty = _this select 1;
};

if (!(isNil "A2EDC_WAI_forceDifficulty")) then {
	if ((typeName A2EDC_WAI_forceDifficulty == "STRING") && {A2EDC_WAI_forceDifficulty != ""}) then {
		_difficulty = A2EDC_WAI_forceDifficulty;
	};
};

_markerColor = "ColorOrange";
_aiSkill = 1;
_aiSkillProfile = "normal";
_lootProfile = "standard";

switch (_difficulty) do {
	case "easy": {
		_markerColor = "ColorGreen";
		_aiSkill = [
			["aimingAccuracy",0.35],
			["aimingShake",0.45],
			["aimingSpeed",0.50],
			["endurance",0.70],
			["spotDistance",0.45],
			["spotTime",0.50],
			["courage",0.65],
			["reloadSpeed",0.60],
			["commanding",0.60],
			["general",0.60]
		];
		_aiSkillProfile = "low";
		_lootProfile = "basic";
	};
	case "medium": {
		_markerColor = "ColorOrange";
		_aiSkill = [
			["aimingAccuracy",0.70],
			["aimingShake",0.65],
			["aimingSpeed",0.75],
			["endurance",0.85],
			["spotDistance",0.75],
			["spotTime",0.75],
			["courage",0.85],
			["reloadSpeed",0.80],
			["commanding",0.80],
			["general",0.80]
		];
		_aiSkillProfile = "normal";
		_lootProfile = "standard";
	};
	case "hard": {
		_markerColor = "ColorRed";
		_aiSkill = [
			["aimingAccuracy",0.82],
			["aimingShake",0.75],
			["aimingSpeed",0.88],
			["endurance",1.00],
			["spotDistance",0.90],
			["spotTime",0.90],
			["courage",1.00],
			["reloadSpeed",0.95],
			["commanding",0.95],
			["general",0.95]
		];
		_aiSkillProfile = "high";
		_lootProfile = "good";
	};
	case "hell": {
		_markerColor = "ColorBlack";
		_aiSkill = [
			["aimingAccuracy",0.88],
			["aimingShake",0.82],
			["aimingSpeed",0.92],
			["endurance",1.00],
			["spotDistance",1.00],
			["spotTime",1.00],
			["courage",1.00],
			["reloadSpeed",1.00],
			["commanding",1.00],
			["general",1.00]
		];
		_aiSkillProfile = "elite";
		_lootProfile = "rare";
	};
	default {
		diag_log format ["A2EDC:WAI:DIFFICULTY mission=%1 difficulty=%2 result=fallback fallback=medium",_mission,_difficulty];
		_difficulty = "medium";
		_markerColor = "ColorOrange";
		_aiSkill = [
			["aimingAccuracy",0.70],
			["aimingShake",0.65],
			["aimingSpeed",0.75],
			["endurance",0.85],
			["spotDistance",0.75],
			["spotTime",0.75],
			["courage",0.85],
			["reloadSpeed",0.80],
			["commanding",0.80],
			["general",0.80]
		];
		_aiSkillProfile = "normal";
		_lootProfile = "standard";
	};
};

_requestedMarkerColor = _markerColor;
if (!(isClass (configFile >> "CfgMarkerColors" >> _markerColor))) then {
	_markerColor = "ColorYellow";
	if (!(isClass (configFile >> "CfgMarkerColors" >> _markerColor))) then {
		_markerColor = "ColorRed";
	};
	diag_log format ["A2EDC:WAI:DIFFICULTY mission=%1 difficulty=%2 markerColorFallback requested=%3 fallback=%4",_mission,_difficulty,_requestedMarkerColor,_markerColor];
};

diag_log format ["A2EDC:WAI:DIFFICULTY mission=%1 difficulty=%2 markerColor=%3 aiSkillProfile=%4 lootProfile=%5",_mission,_difficulty,_markerColor,_aiSkillProfile,_lootProfile];

[_difficulty,_markerColor,_aiSkill,_aiSkillProfile,_lootProfile]
