A2EDC_DAYZ_CODE_BUILD_ID = "20260527-184340";
A2EDC_DAYZ_CODE_BUILD_UTC = "2026-05-27T18:43:46Z";
A2EDC_DAYZ_CODE_BUILD_SOURCE = "dayz_code";
A2EDC_DAYZ_CODE_BUILD_SOURCE_TREE = "Sandbox/origins_179_rebuild/dayz_code_merged_src";
A2EDC_DAYZ_CODE_BUILD_PREFIX = "z\addons\dayz_code";
A2EDC_DAYZ_CODE_BUILD_NOTE = "runtime-build-identity-v1.3-onback-compile-path-fix";
A2EDC_DAYZ_CODE_BUILD_EXPORT = "Export/dayz_code_20260527-184340_runtime-build-identity-v1.3-onback-compile-path-fix.pbo";
A2EDC_DAYZ_CODE_BUILD_GIT_SHORT = "eee95b1";
A2EDC_DAYZ_CODE_BUILD_GIT_COMMIT = "eee95b132e5b9163fb506a60d316e56bae659560";
A2EDC_DAYZ_CODE_BUILD_GIT_DIRTY = "true";
A2EDC_DAYZ_CODE_BUILD_EXPECTED_SHA256 = "<see-export-sha256>";

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
if (isNil "A2EDC_dayzCodeBuildLogged") then {_logIdentity = true;};
if (!isNil "A2EDC_BUILD_IDENTITY_DEBUG") then {if (A2EDC_BUILD_IDENTITY_DEBUG) then {_logIdentity = true;};};
if (_logIdentity) then {
  A2EDC_dayzCodeBuildLogged = true;
  A2EDC_DAYZ_CODE_BUILD_LOGGED = true;
  diag_log format [
    "A2EDC:DAYZ_CODE_BUILD build_id=%1 build_utc=%2 note=%3 source=%4 locality=%5 export=%6 git=%7 dirty=%8",
    A2EDC_DAYZ_CODE_BUILD_ID,
    A2EDC_DAYZ_CODE_BUILD_UTC,
    A2EDC_DAYZ_CODE_BUILD_NOTE,
    A2EDC_DAYZ_CODE_BUILD_SOURCE,
    _locality,
    A2EDC_DAYZ_CODE_BUILD_EXPORT,
    A2EDC_DAYZ_CODE_BUILD_GIT_SHORT,
    A2EDC_DAYZ_CODE_BUILD_GIT_DIRTY
  ];
};
