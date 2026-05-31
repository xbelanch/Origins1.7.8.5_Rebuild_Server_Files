A2EDC_MISSION_BUILD_ID = "20260531-083418";
A2EDC_MISSION_BUILD_UTC = "2026-05-31T08:34:18Z";
A2EDC_MISSION_BUILD_SOURCE = "MPMissions/dayz_1.origins.tavi";
A2EDC_MISSION_BUILD_PREFIX = "";
A2EDC_MISSION_BUILD_NOTE = "gear-visual-weight-tooltip-v1";
A2EDC_MISSION_BUILD_EXPORT = "Export/dayz_1.origins.tavi_20260531-083418_gear-visual-weight-tooltip-v1.pbo";
A2EDC_MISSION_BUILD_GIT_SHORT = "c631edf";
A2EDC_MISSION_BUILD_GIT_DIRTY = "true";

private["_locality","_logIdentity"];
_locality = "unknown";
if (isDedicated) then {
  _locality = "dedicated";
} else {
  if (hasInterface) then {
    _locality = "client";
  } else {
    if (isServer) then {_locality = "server";};
  };
};
_logIdentity = false;
if (isNil "A2EDC_MISSION_BUILD_LOGGED") then {_logIdentity = true;};
if (!isNil "A2EDC_BUILD_IDENTITY_DEBUG") then {if (A2EDC_BUILD_IDENTITY_DEBUG) then {_logIdentity = true;};};
if (_logIdentity) then {
  A2EDC_MISSION_BUILD_LOGGED = true;
diag_log format [
    "A2EDC:MISSION_BUILD build_id=%1 build_utc=%2 note=%3 source=mission locality=%4 export=%5 git=%6 dirty=%7",
    A2EDC_MISSION_BUILD_ID,
    A2EDC_MISSION_BUILD_UTC,
    A2EDC_MISSION_BUILD_NOTE,
    _locality,
    A2EDC_MISSION_BUILD_EXPORT,
    A2EDC_MISSION_BUILD_GIT_SHORT,
    A2EDC_MISSION_BUILD_GIT_DIRTY
];
};
