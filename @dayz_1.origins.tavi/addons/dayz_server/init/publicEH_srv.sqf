if (isServer) then {

"dayzDeath"      	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzDeath",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_playerDied};
"DOgNo_Se"  	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["DOgNo_Se",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_playerSync;};
"oriWverOtkr"	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["oriWverOtkr",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_pubOriObj};
"dayUpdateVehlcle" 	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayUpdateVehlcle",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_updatObiect};
"oriUdalkaObj"    	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["oriUdalkaObj",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_udalitObj};
"DOdowndblink"      	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["DOdowndblink",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call DO_cperg};
"dayzOrigingsL2"		addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzOrigingsL2",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call serverDO_plSp};
"A2EDC_adminMissionLaunch" addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["A2EDC_adminMissionLaunch",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call A2EDC_fnc_adminMissionLaunch;};
"A2EDC_adminBuildingKit" addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["A2EDC_adminBuildingKit",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call A2EDC_fnc_adminBuildingKit;};
"A2EDC_adminTeleportRequest" addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["A2EDC_adminTeleportRequest",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call A2EDC_fnc_adminTeleport;};
"A2EDC_adminHumanityDebug" addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["A2EDC_adminHumanityDebug",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call A2EDC_fnc_adminHumanityDebug;};

"dayzLoginRecord"  	addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzLoginRecord",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call dayz_recordLogin};


"dayzDiscoAdd"		addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzDiscoAdd",(_this select 1)] call A2EDC_fnc_tracePV;};};dayz_disco set [count dayz_disco,(_this select 1)];};
"dayzDiscoRem"		addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzDiscoRem",(_this select 1)] call A2EDC_fnc_tracePV;};};dayz_disco = dayz_disco - [(_this select 1)];};


"dayzGutBody"		addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["dayzGutBody",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) spawn local_gutObject};

"wantbbplz"			addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["wantbbplz",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call server_wantbbplz};
"verbb_pas"			addPublicVariableEventHandler {if (!(isNil "A2EDC_TRACE")) then {if (A2EDC_TRACE) then {["verbb_pas",(_this select 1)] call A2EDC_fnc_tracePV;};};(_this select 1) call serv_verbb_pas};
};
