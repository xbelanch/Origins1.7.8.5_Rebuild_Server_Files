A2EDC_BUILD_ID = "20260527-184340";
A2EDC_BUILD_UTC = "2026-05-27T18:43:46Z";
A2EDC_BUILD_SOURCE = "@dayz_1.origins.tavi/addons/dayz_server";
A2EDC_BUILD_PREFIX = "z\addons\dayz_server";
A2EDC_BUILD_NOTE = "runtime-build-identity-v1.3-onback-compile-path-fix";
A2EDC_BUILD_EXPORT = "Export/dayz_server_20260527-184340_runtime-build-identity-v1.3-onback-compile-path-fix.pbo";
A2EDC_BUILD_GIT_SHORT = "eee95b1";
A2EDC_BUILD_GIT_DIRTY = "true";

A2EDC_DAYZ_SERVER_BUILD_ID = A2EDC_BUILD_ID;
A2EDC_DAYZ_SERVER_BUILD_UTC = A2EDC_BUILD_UTC;
A2EDC_DAYZ_SERVER_BUILD_SOURCE = A2EDC_BUILD_SOURCE;
A2EDC_DAYZ_SERVER_BUILD_PREFIX = A2EDC_BUILD_PREFIX;
A2EDC_DAYZ_SERVER_BUILD_NOTE = A2EDC_BUILD_NOTE;

A2EDC_BUILD_EXPECTED_DIAGNOSTICS = [
  "A2EDC:WAI:PUBLISH",
  "A2EDC:DZMS:SETUP",
  "A2EDC:DZMS:SAVE",
  "A2EDC:DZMS:PROTECT:SKIP_INVALID",
  "A2EDC:DZMS:PROTECT:SKIP_NULL",
  "A2EDC:DZMS:CLASS:SKIP_MISSING",
  "A2EDC:WAI:CLASS:SKIP_MISSING",
  "A2EDC:WAI:AI_CLASS:SKIP_INVALID",
  "A2EDC:WAI:CARGO:SKIP_MISSING",
  "A2EDC:OBJECT_GUARD",
  "server_updateObject = server_updatObiect"
];

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
if (isNil "A2EDC_DAYZ_SERVER_BUILD_LOGGED") then {_logIdentity = true;};
if (!isNil "A2EDC_BUILD_IDENTITY_DEBUG") then {if (A2EDC_BUILD_IDENTITY_DEBUG) then {_logIdentity = true;};};
if (_logIdentity) then {
  A2EDC_DAYZ_SERVER_BUILD_LOGGED = true;
diag_log format [
    "A2EDC:DAYZ_SERVER_BUILD build_id=%1 build_utc=%2 note=%3 source=dayz_server locality=%4 export=%5 git=%6 dirty=%7",
    A2EDC_BUILD_ID,
    A2EDC_BUILD_UTC,
    A2EDC_BUILD_NOTE,
    _locality,
    A2EDC_BUILD_EXPORT,
    A2EDC_BUILD_GIT_SHORT,
    A2EDC_BUILD_GIT_DIRTY
];
};
