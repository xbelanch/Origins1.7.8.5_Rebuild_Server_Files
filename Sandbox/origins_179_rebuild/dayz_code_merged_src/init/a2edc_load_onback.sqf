if (isNil "A2EDC_fnc_loadOnBackCompile") then {
	A2EDC_fnc_loadOnBackCompile = {
		private["_source","_path"];
		_source = "unknown";
		if (!isNil "_this") then {
			if ((typeName _this) == "ARRAY") then {
				if ((count _this) > 0) then {
					_source = _this select 0;
				};
			} else {
				if ((typeName _this) == "STRING") then {
					_source = _this;
				};
			};
		};
		_path = "\z\addons\dayz_code\compile\a2edc_gearOnBack.sqf";
		diag_log format["A2EDC:ONBACK_COMPILE_LOAD path=%1 result=begin source=%2",_path,_source];
		call compile preprocessFileLineNumbers _path;
		diag_log format["A2EDC:ONBACK_COMPILE_LOAD path=%1 result=end source=%2 isNil_bSmenaTrigger=%3 isNil_switchOnBackWeapon=%4 isNil_refreshOnBackGearSlot=%5 isNil_dumpGearControls=%6",_path,_source,isNil "A2EDC_fnc_bSmenaTrigger",isNil "A2EDC_fnc_switchOnBackWeapon",isNil "A2EDC_fnc_refreshOnBackGearSlot",isNil "A2EDC_fnc_dumpGearControls"];
		if (!isNil "A2EDC_fnc_logOnBackCompileStatus") then {
			call A2EDC_fnc_logOnBackCompileStatus;
		};
	};
};

