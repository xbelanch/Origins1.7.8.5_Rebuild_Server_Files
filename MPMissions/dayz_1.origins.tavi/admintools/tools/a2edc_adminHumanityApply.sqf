private ["_payload","_uid","_charID","_oldServer","_newServer","_sourcePath","_persisted","_clientUID","_clientCharID","_oldClientHumanity","_oldDayzLast","_oldDayzGui","_oldOrigins","_newOrigins","_varsUpdated","_display","_ctrlFound","_combatCtrlFound","_ctrl1207Text","_sourceHumanity","_sourceOrigins","_textControls","_iconControls","_ctrl","_ctrlId","_before","_after","_hudAppliedControls","_humanityCtrlId","_displayName","_sourceVariable","_expectedText"];

_payload = _this;
if ((typeName _payload) != "ARRAY") exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_CLIENT_RECEIVED uid=%1 characterID=%2 oldServerValue=<invalid> newServerValue=<invalid> oldClientValues=<invalid> newClientValues=<invalid> varsUpdated=[] persisted=false reason=payload_not_array payload=%3",getPlayerUID player,player getVariable ["characterID","0"],_payload];
};
if ((count _payload) < 6) exitWith {
	diag_log format ["A2EDC:ADMIN:HUMANITY_CLIENT_RECEIVED uid=%1 characterID=%2 oldServerValue=<invalid> newServerValue=<invalid> oldClientValues=<invalid> newClientValues=<invalid> varsUpdated=[] persisted=false reason=payload_too_short payload=%3",getPlayerUID player,player getVariable ["characterID","0"],_payload];
};

_uid = _payload select 0;
_charID = _payload select 1;
_oldServer = _payload select 2;
_newServer = _payload select 3;
_sourcePath = _payload select 4;
_persisted = _payload select 5;
_clientUID = getPlayerUID player;
_clientCharID = player getVariable ["characterID","0"];
_oldClientHumanity = player getVariable ["humanity",0];
_oldDayzLast = if (isNil "dayz_lastHumanity") then {"<nil>"} else {dayz_lastHumanity};
_oldDayzGui = if (isNil "dayz_guiHumanity") then {"<nil>"} else {dayz_guiHumanity};
_oldOrigins = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {+dayzOriginsPlL2};
_varsUpdated = [];

diag_log format ["A2EDC:ADMIN:HUMANITY_CLIENT_RECEIVED uid=%1 characterID=%2 oldServerValue=%3 newServerValue=%4 oldClientValues=[humanity=%5,dayz_lastHumanity=%6,dayz_guiHumanity=%7,dayzOriginsPlL2=%8] newClientValues=<pending> varsUpdated=[] persisted=%9 sourcePath=%10 clientUID=%11 clientCharacterID=%12",_uid,_charID,_oldServer,_newServer,_oldClientHumanity,_oldDayzLast,_oldDayzGui,_oldOrigins,_persisted,_sourcePath,_clientUID,_clientCharID];

player setVariable ["humanity",_newServer,false];
_varsUpdated set [count _varsUpdated,"player.humanity"];

if (!isNil "dayzOriginsPlL2") then {
	if ((typeName dayzOriginsPlL2) == "ARRAY") then {
		if ((count dayzOriginsPlL2) > 2) then {
			dayzOriginsPlL2 set [2,_newServer];
			_varsUpdated set [count _varsUpdated,"dayzOriginsPlL2[2]"];
		};
	};
};
_newOrigins = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {+dayzOriginsPlL2};

diag_log format ["A2EDC:ADMIN:HUMANITY_CLIENT_APPLY uid=%1 characterID=%2 oldServerValue=%3 newServerValue=%4 oldClientValues=[humanity=%5,dayzOriginsPlL2=%6] newClientValues=[humanity=%7,dayzOriginsPlL2=%8] varsUpdated=%9 persisted=%10 sourcePath=%11",_uid,_charID,_oldServer,_newServer,_oldClientHumanity,_oldOrigins,player getVariable ["humanity",0],_newOrigins,_varsUpdated,_persisted,_sourcePath];

if (!isNil "dayz_lastHumanity") then {
	dayz_lastHumanity = -999999;
	_varsUpdated set [count _varsUpdated,"dayz_lastHumanity"];
};
if (!isNil "dayz_guiHumanity") then {
	dayz_guiHumanity = -999999;
	_varsUpdated set [count _varsUpdated,"dayz_guiHumanity"];
};

diag_log format ["A2EDC:ADMIN:HUMANITY_CLIENT_VAR uid=%1 characterID=%2 oldServerValue=%3 newServerValue=%4 oldClientValues=[humanity=%5,dayz_lastHumanity=%6,dayz_guiHumanity=%7,dayzOriginsPlL2=%8] newClientValues=[humanity=%9,dayz_lastHumanity=%10,dayz_guiHumanity=%11,dayzOriginsPlL2=%12] varsUpdated=%13 persisted=%14",_uid,_charID,_oldServer,_newServer,_oldClientHumanity,_oldDayzLast,_oldDayzGui,_oldOrigins,player getVariable ["humanity",0],if (isNil "dayz_lastHumanity") then {"<nil>"} else {dayz_lastHumanity},if (isNil "dayz_guiHumanity") then {"<nil>"} else {dayz_guiHumanity},_newOrigins,_varsUpdated,_persisted];

_display = uiNamespace getVariable ["DAYZ_GUI_display",displayNull];
_ctrlFound = false;
_combatCtrlFound = false;
_ctrl1207Text = "<no_display>";
_sourceHumanity = player getVariable ["humanity",0];
_sourceOrigins = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {+dayzOriginsPlL2};
_hudAppliedControls = [];
_humanityCtrlId = 1314;
_displayName = "DAYZ_GUI_display";
_sourceVariable = "player.humanity";
_expectedText = format ["%1",_sourceHumanity];
_before = "<not_read>";
_after = "<not_read>";

diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_SOURCE_FOUND uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 playerHumanity=%6 dayzOriginsPlL2=%7 dayz_lastHumanity=%8 dayz_guiHumanity=%9 displayId=%10 controlId=%11 sourcePath=%12",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_sourceHumanity,_sourceOrigins,if (isNil "dayz_lastHumanity") then {"<nil>"} else {dayz_lastHumanity},if (isNil "dayz_guiHumanity") then {"<nil>"} else {dayz_guiHumanity},_displayName,_humanityCtrlId,_sourcePath];
diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_SOURCE_VAR uid=%1 characterID=%2 playerHumanity=%3 dayzOriginsPlL2=%4 dayz_lastHumanity=%5 dayz_guiHumanity=%6 sourcePath=%7",_uid,_charID,_sourceHumanity,_sourceOrigins,if (isNil "dayz_lastHumanity") then {"<nil>"} else {dayz_lastHumanity},if (isNil "dayz_guiHumanity") then {"<nil>"} else {dayz_guiHumanity},_sourcePath];

if (!isNull _display) then {
	_ctrl = _display displayCtrl 1207;
	_combatCtrlFound = !isNull _ctrl;
	if (_combatCtrlFound) then {_ctrl1207Text = ctrlText _ctrl;};
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_CONTROL uid=%1 characterID=%2 displayFound=true idc=1207 found=%3 role=combat_border_not_humanity text=%4 source=rscTitles.hpp",_uid,_charID,_combatCtrlFound,_ctrl1207Text];
		_textControls = [1309,1310,1311,1312];
		{
			_ctrlId = _x;
			_ctrl = _display displayCtrl _ctrlId;
			_ctrlFound = !isNull _ctrl;
			_before = if (_ctrlFound) then {ctrlText _ctrl} else {"<missing>"};
			diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_TEXT_SKIPPED uid=%1 characterID=%2 idc=%3 found=%4 text=%5 intended=%6 reason=unsafe_candidate_control_no_direct_write",_uid,_charID,_ctrlId,_ctrlFound,_before,_sourceHumanity];
		} forEach _textControls;
	_iconControls = [1206,1209,1210,1308,1313];
	{
		_ctrlId = _x;
		_ctrl = _display displayCtrl _ctrlId;
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_CONTROL uid=%1 characterID=%2 displayFound=true idc=%3 found=%4 role=humanity_candidate source=rscTitles.hpp",_uid,_charID,_ctrlId,!isNull _ctrl];
	} forEach _iconControls;
	_ctrl = _display displayCtrl _humanityCtrlId;
	_ctrlFound = !isNull _ctrl;
	_before = if (_ctrlFound) then {ctrlText _ctrl} else {"<missing>"};
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_CONTROL_FOUND uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 found=%8 role=humanity_numeric_text textBefore=%9 textAfter=<pending> remainedAfterRefresh=false",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_ctrlFound,_before];
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_TEXT_BEFORE uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=%8 textAfter=<pending> remainedAfterRefresh=false",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_before];
	if (_ctrlFound) then {
		_ctrl ctrlSetText _expectedText;
		_hudAppliedControls set [count _hudAppliedControls,_humanityCtrlId];
		_after = ctrlText _ctrl;
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_TEXT_AFTER uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=%8 textAfter=%9 remainedAfterRefresh=false",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_before,_after];
	} else {
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_REAL_CONTROL_NOT_FOUND uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=%8 textAfter=<missing> remainedAfterRefresh=false",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_before];
	};
} else {
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_CONTROL uid=%1 characterID=%2 displayFound=false idc=<none> found=false role=DAYZ_GUI_display source=uiNamespace",_uid,_charID];
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_REAL_CONTROL_NOT_FOUND uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=<no_display> textAfter=<no_display> remainedAfterRefresh=false",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId];
};

if (!isNil "player_updateGui") then {
	call player_updateGui;
	_display = uiNamespace getVariable ["DAYZ_GUI_display",displayNull];
	_after = "<missing>";
	if (!isNull _display) then {
		_ctrl = _display displayCtrl _humanityCtrlId;
		if (!isNull _ctrl) then {_after = ctrlText _ctrl;};
	};
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_REFRESH_CALL uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=%8 textAfter=%9 remainedAfterRefresh=%10 varsUpdated=%11 persisted=%12 directControls=%13 reason=player_updateGui_updates_idc_1314",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_before,_after,(_after == _expectedText),_varsUpdated,_persisted,_hudAppliedControls];
} else {
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_REFRESH_CALL uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=%8 textAfter=<not_called> remainedAfterRefresh=false varsUpdated=%9 persisted=%10 directControls=%11 reason=player_updateGui_missing",_uid,_charID,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId,_before,_varsUpdated,_persisted,_hudAppliedControls];
};

[_uid,_charID,_sourceHumanity,_sourcePath,_oldClientHumanity,_newServer,_sourceVariable,_displayName,_humanityCtrlId] spawn {
	private["_uid","_charID","_expected","_sourcePath","_oldValue","_newValue","_sourceVariable","_displayName","_humanityCtrlId","_actual","_origins","_display","_ctrl","_textAfter","_remained"];
	_uid = _this select 0;
	_charID = _this select 1;
	_expected = _this select 2;
	_sourcePath = _this select 3;
	_oldValue = _this select 4;
	_newValue = _this select 5;
	_sourceVariable = _this select 6;
	_displayName = _this select 7;
	_humanityCtrlId = _this select 8;
	sleep 2;
	if (!isNil "player_updateGui") then {call player_updateGui;};
	_actual = player getVariable ["humanity",0];
	_origins = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {+dayzOriginsPlL2};
	_display = uiNamespace getVariable ["DAYZ_GUI_display",displayNull];
	_textAfter = "<missing>";
	if (!isNull _display) then {
		_ctrl = _display displayCtrl _humanityCtrlId;
		if (!isNull _ctrl) then {_textAfter = ctrlText _ctrl;};
	};
	_remained = (_textAfter == format ["%1",_expected]);
	diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_OVERWRITE_DETECTED uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=<delayed_check> textAfter=%8 expectedText=%9 remainedAfterRefresh=%10 expectedHumanity=%11 actualHumanity=%12 dayzOriginsPlL2=%13 overwritten=%14 sourcePath=%15 delaySeconds=2",_uid,_charID,_oldValue,_newValue,_sourceVariable,_displayName,_humanityCtrlId,_textAfter,format ["%1",_expected],_remained,_expected,_actual,_origins,!_remained,_sourcePath];
	sleep 8;
	if (!isNil "player_updateGui") then {call player_updateGui;};
	_actual = player getVariable ["humanity",0];
	_origins = if (isNil "dayzOriginsPlL2") then {"<nil>"} else {+dayzOriginsPlL2};
	_display = uiNamespace getVariable ["DAYZ_GUI_display",displayNull];
	_textAfter = "<missing>";
	if (!isNull _display) then {
		_ctrl = _display displayCtrl _humanityCtrlId;
		if (!isNull _ctrl) then {_textAfter = ctrlText _ctrl;};
	};
	_remained = (_textAfter == format ["%1",_expected]);
	if (_remained) then {
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_FIX_CONFIRMED uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=<delayed_check> textAfter=%8 expectedText=%9 remainedAfterRefresh=true expectedHumanity=%10 actualHumanity=%11 dayzOriginsPlL2=%12 sourcePath=%13 delaySeconds=10",_uid,_charID,_oldValue,_newValue,_sourceVariable,_displayName,_humanityCtrlId,_textAfter,format ["%1",_expected],_expected,_actual,_origins,_sourcePath];
	} else {
		diag_log format ["A2EDC:ADMIN:HUMANITY_HUD_OVERWRITE_DETECTED uid=%1 characterID=%2 oldValue=%3 newValue=%4 sourceVariable=%5 displayId=%6 controlId=%7 textBefore=<delayed_check> textAfter=%8 expectedText=%9 remainedAfterRefresh=false expectedHumanity=%10 actualHumanity=%11 dayzOriginsPlL2=%12 overwritten=true sourcePath=%13 delaySeconds=10",_uid,_charID,_oldValue,_newValue,_sourceVariable,_displayName,_humanityCtrlId,_textAfter,format ["%1",_expected],_expected,_actual,_origins,_sourcePath];
	};
};

cutText [format ["A2EDC humanity applied: %1",_newServer], "PLAIN DOWN"];
diag_log format ["A2EDC:ADMIN:HUMANITY_DONE side=client uid=%1 characterID=%2 oldServerValue=%3 newServerValue=%4 oldClientValues=[humanity=%5] newClientValues=[humanity=%6] varsUpdated=%7 persisted=%8 reason=client_apply_done",_uid,_charID,_oldServer,_newServer,_oldClientHumanity,player getVariable ["humanity",0],_varsUpdated,_persisted];
