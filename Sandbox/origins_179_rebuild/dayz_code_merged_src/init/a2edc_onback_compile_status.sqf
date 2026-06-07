A2EDC_onBackCodeVersion = "20260606-162055_house-l1-preview-forward-movement-fix-v2";

if (isNil "A2EDC_fnc_logOnBackCompileStatus") then {
  A2EDC_fnc_logOnBackCompileStatus = {
    private["_logIdentity","_version","_ready"];
    _ready = (!(isNil "A2EDC_fnc_bSmenaTrigger") && !(isNil "A2EDC_fnc_switchOnBackWeapon") && !(isNil "A2EDC_fnc_refreshOnBackGearSlot") && !(isNil "A2EDC_fnc_dumpGearControls"));
    if (!_ready) then {
      if (isNil "A2EDC_ONBACK_COMPILE_STATUS_EARLY_LOGGED") then {
        A2EDC_ONBACK_COMPILE_STATUS_EARLY_LOGGED = true;
        _version = if (isNil "A2EDC_onBackCodeVersion") then {"<nil>"} else {A2EDC_onBackCodeVersion};
        diag_log format [
          "A2EDC:ONBACK_COMPILE_STATUS_EARLY isNil_bSmenaTrigger=%1 isNil_switchOnBackWeapon=%2 isNil_refreshOnBackGearSlot=%3 isNil_dumpGearControls=%4 A2EDC_onBackCodeVersion=%5",
          isNil "A2EDC_fnc_bSmenaTrigger",
          isNil "A2EDC_fnc_switchOnBackWeapon",
          isNil "A2EDC_fnc_refreshOnBackGearSlot",
          isNil "A2EDC_fnc_dumpGearControls",
          _version
        ];
      };
    };
    _logIdentity = false;
    if (isNil "A2EDC_ONBACK_COMPILE_STATUS_LOGGED") then {_logIdentity = true;};
    if (!isNil "A2EDC_BUILD_IDENTITY_DEBUG") then {if (A2EDC_BUILD_IDENTITY_DEBUG) then {_logIdentity = true;};};
    if (!_ready && _logIdentity) exitWith {};
    if (_logIdentity) then {
      A2EDC_ONBACK_COMPILE_STATUS_LOGGED = true;
      _version = if (isNil "A2EDC_onBackCodeVersion") then {"<nil>"} else {A2EDC_onBackCodeVersion};
      diag_log format [
        "A2EDC:ONBACK_COMPILE_STATUS_LATE isNil_bSmenaTrigger=%1 isNil_switchOnBackWeapon=%2 isNil_refreshOnBackGearSlot=%3 isNil_dumpGearControls=%4 A2EDC_onBackCodeVersion=%5",
        isNil "A2EDC_fnc_bSmenaTrigger",
        isNil "A2EDC_fnc_switchOnBackWeapon",
        isNil "A2EDC_fnc_refreshOnBackGearSlot",
        isNil "A2EDC_fnc_dumpGearControls",
        _version
      ];
    };
  };
};

call A2EDC_fnc_logOnBackCompileStatus;

if (!isDedicated && isNil "A2EDC_ONBACK_COMPILE_STATUS_WATCH_STARTED") then {
  A2EDC_ONBACK_COMPILE_STATUS_WATCH_STARTED = true;
  [] spawn {
    waitUntil {!(isNil "A2EDC_fnc_bSmenaTrigger") && !(isNil "A2EDC_fnc_switchOnBackWeapon") && !(isNil "A2EDC_fnc_refreshOnBackGearSlot") && !(isNil "A2EDC_fnc_dumpGearControls")};
    call A2EDC_fnc_logOnBackCompileStatus;
  };
};
