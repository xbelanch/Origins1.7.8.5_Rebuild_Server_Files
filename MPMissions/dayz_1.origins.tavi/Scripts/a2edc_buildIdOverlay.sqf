if (isDedicated) exitWith {};

if (!isNil "A2EDC_buildIdOverlayScriptLoaded") exitWith {};
A2EDC_buildIdOverlayScriptLoaded = true;

if (isNil "A2EDC_serverBuildInfo") then {
	A2EDC_serverBuildInfo = ["UNKNOWN","UNKNOWN","","",""];
};

A2EDC_fnc_buildIdOverlayRefreshInfo = {
	A2EDC_missionBuildInfo = [
		if (isNil "A2EDC_MISSION_BUILD_ID") then {"UNKNOWN"} else {A2EDC_MISSION_BUILD_ID},
		if (isNil "A2EDC_MISSION_BUILD_NOTE") then {"UNKNOWN"} else {A2EDC_MISSION_BUILD_NOTE},
		if (isNil "A2EDC_MISSION_BUILD_UTC") then {""} else {A2EDC_MISSION_BUILD_UTC},
		if (isNil "A2EDC_MISSION_BUILD_SOURCE") then {""} else {A2EDC_MISSION_BUILD_SOURCE},
		if (isNil "A2EDC_MISSION_BUILD_EXPORT") then {""} else {A2EDC_MISSION_BUILD_EXPORT}
	];
	A2EDC_dayzCodeBuildInfo = [
		if (isNil "A2EDC_DAYZ_CODE_BUILD_ID") then {"UNKNOWN"} else {A2EDC_DAYZ_CODE_BUILD_ID},
		if (isNil "A2EDC_DAYZ_CODE_BUILD_NOTE") then {"UNKNOWN"} else {A2EDC_DAYZ_CODE_BUILD_NOTE},
		if (isNil "A2EDC_DAYZ_CODE_BUILD_UTC") then {""} else {A2EDC_DAYZ_CODE_BUILD_UTC},
		if (isNil "A2EDC_DAYZ_CODE_BUILD_SOURCE") then {""} else {A2EDC_DAYZ_CODE_BUILD_SOURCE},
		if (isNil "A2EDC_DAYZ_CODE_BUILD_EXPORT") then {""} else {A2EDC_DAYZ_CODE_BUILD_EXPORT}
	];
};

A2EDC_fnc_buildIdOverlayShortNote = {
	private["_note","_limit","_chars","_out","_i"];
	_note = _this select 0;
	_limit = _this select 1;
	if (isNil "_note") exitWith {"UNKNOWN"};
	if ((typeName _note) != "STRING") exitWith {str _note};
	if ((count toArray _note) <= _limit) exitWith {_note};
	_chars = toArray _note;
	_out = [];
	for "_i" from 0 to (_limit - 1) do {
		_out set [count _out,_chars select _i];
	};
	toString _out
};

A2EDC_fnc_buildIdOverlayLine = {
	private["_label","_info","_id","_note","_shortNote"];
	_label = _this select 0;
	_info = _this select 1;
	if ((typeName _info) != "ARRAY") exitWith {format ["%1 UNKNOWN",_label]};
	_id = if ((count _info) > 0) then {_info select 0} else {"UNKNOWN"};
	_note = if ((count _info) > 1) then {_info select 1} else {"UNKNOWN"};
	if (isNil "_id") then {_id = "UNKNOWN";};
	if (isNil "_note") then {_note = "UNKNOWN";};
	if ((typeName _id) != "STRING") then {_id = str _id;};
	if ((typeName _note) != "STRING") then {_note = str _note;};
	if (_id == "") then {_id = "UNKNOWN";};
	if (_note == "") then {_note = "UNKNOWN";};
	_shortNote = [_note,42] call A2EDC_fnc_buildIdOverlayShortNote;
	format ["%1 %2 %3",_label,_id,_shortNote]
};

A2EDC_fnc_buildIdOverlayHumanityLine = {
	private["_humanity","_originsHumanity","_charId"];
	_humanity = if (isNull player) then {"<no player>"} else {player getVariable ["humanity","<nil>"]};
	_originsHumanity = "<nil>";
	if (!isNil "dayzOriginsPlL2") then {
		if ((typeName dayzOriginsPlL2) == "ARRAY") then {
			if ((count dayzOriginsPlL2) > 2) then {_originsHumanity = dayzOriginsPlL2 select 2;};
		};
	};
	_charId = if (isNull player) then {"<no player>"} else {player getVariable ["characterID","0"]};
	format ["HUM %1 ORI %2 CID %3",_humanity,_originsHumanity,_charId]
};

A2EDC_fnc_buildIdOverlayShow = {
	6 cutRsc ["A2EDC_BuildIdOverlay","PLAIN",0];
};

A2EDC_fnc_buildIdOverlayUpdate = {
	disableSerialization;
	private["_display","_mission","_client","_server","_humanity","_text","_header","_misCtrl","_cliCtrl","_srvCtrl","_humCtrl","_missingControl"];
	call A2EDC_fnc_buildIdOverlayRefreshInfo;
	_display = uiNamespace getVariable ["A2EDC_BuildIdOverlayDisplay",displayNull];
	if (isNull _display) then {
		call A2EDC_fnc_buildIdOverlayShow;
		_display = uiNamespace getVariable ["A2EDC_BuildIdOverlayDisplay",displayNull];
	};
	if (isNull _display) exitWith {
		if (isNil "A2EDC_buildIdOverlayMissingLogged") then {
			A2EDC_buildIdOverlayMissingLogged = true;
			diag_log "A2EDC:BUILD_ID_OVERLAY_MISSING reason=rsc_title_display_missing";
		};
	};
	_header = _display displayCtrl 860621;
	_misCtrl = _display displayCtrl 860622;
	_cliCtrl = _display displayCtrl 860623;
	_srvCtrl = _display displayCtrl 860624;
	_humCtrl = _display displayCtrl 860625;
	_missingControl = false;
	if (isNull _header) then {_missingControl = true;};
	if (isNull _misCtrl) then {_missingControl = true;};
	if (isNull _cliCtrl) then {_missingControl = true;};
	if (isNull _srvCtrl) then {_missingControl = true;};
	if (isNull _humCtrl) then {_missingControl = true;};
	if (_missingControl) exitWith {
		if (isNil "A2EDC_buildIdOverlayMissingLogged") then {
			A2EDC_buildIdOverlayMissingLogged = true;
			diag_log "A2EDC:BUILD_ID_OVERLAY_MISSING reason=rsc_title_control_missing";
		};
	};
	_mission = ["MIS",A2EDC_missionBuildInfo] call A2EDC_fnc_buildIdOverlayLine;
	_client = ["CLI",A2EDC_dayzCodeBuildInfo] call A2EDC_fnc_buildIdOverlayLine;
	_server = ["SRV",A2EDC_serverBuildInfo] call A2EDC_fnc_buildIdOverlayLine;
	_humanity = call A2EDC_fnc_buildIdOverlayHumanityLine;
	_header ctrlSetText "A2EDC BUILD";
	_misCtrl ctrlSetText _mission;
	_cliCtrl ctrlSetText _client;
	_srvCtrl ctrlSetText _server;
	_humCtrl ctrlSetText _humanity;
	_text = format ["A2EDC BUILD|%1|%2|%3|%4",_mission,_client,_server,_humanity];
	if (isNil "A2EDC_buildIdOverlayLastText") then {A2EDC_buildIdOverlayLastText = "";};
	if (A2EDC_buildIdOverlayLastText != _text) then {
		A2EDC_buildIdOverlayLastText = _text;
			diag_log format ["A2EDC:BUILD_ID_OVERLAY_UPDATE mission=%1 client=%2 server=%3 humanity=%4",A2EDC_missionBuildInfo,A2EDC_dayzCodeBuildInfo,A2EDC_serverBuildInfo,_humanity];
	};
};

if (isNil "A2EDC_buildIdOverlayHumanityWatchStarted") then {
	A2EDC_buildIdOverlayHumanityWatchStarted = true;
	[] spawn {
		while {true} do {
			sleep 5;
			if (!isNil "A2EDC_fnc_buildIdOverlayUpdate") then {
				[] call A2EDC_fnc_buildIdOverlayUpdate;
			};
		};
	};
};

if (isNil "A2EDC_buildIdOverlayPvehInstalled") then {
	A2EDC_buildIdOverlayPvehInstalled = true;
	"A2EDC_serverBuildInfo" addPublicVariableEventHandler {
		A2EDC_serverBuildInfo = _this select 1;
		diag_log format ["A2EDC:BUILD_ID_CLIENT_RECEIVED server=%1",A2EDC_serverBuildInfo];
		[] spawn {
			sleep 0.1;
			if (!isNil "A2EDC_fnc_buildIdOverlayUpdate") then {
				[] call A2EDC_fnc_buildIdOverlayUpdate;
			};
		};
	};
};

[] spawn {
	private["_i","_display"];
	waitUntil {!isNull player};
	sleep 2;
	diag_log "A2EDC:BUILD_ID_OVERLAY_INIT";
	for "_i" from 1 to 10 do {
		call A2EDC_fnc_buildIdOverlayShow;
		sleep 0.25;
		[] call A2EDC_fnc_buildIdOverlayUpdate;
		_display = uiNamespace getVariable ["A2EDC_BuildIdOverlayDisplay",displayNull];
		if (!isNull _display) exitWith {};
		sleep 0.75;
	};
};
