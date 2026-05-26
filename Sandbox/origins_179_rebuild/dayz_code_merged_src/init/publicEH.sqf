//Medical Event Handlers

"dayzSetFuel"		addPublicVariableEventHandler {(_this select 1) spawn local_sefFuel};
"dayzSetFix"		addPublicVariableEventHandler {(_this select 1) call object_setFixServer};
"dayzFire"			addPublicVariableEventHandler {nul=(_this select 1) spawn BIS_Effects_Burn};

//Client only
if (!isDedicated) then {
	"usecMorphine"		addPublicVariableEventHandler {(_this select 1) call player_medMorphine};
	"usecBandage"		addPublicVariableEventHandler {(_this select 1) call player_medBandage};
	"usecEpl"			addPublicVariableEventHandler {(_this select 1) call player_medEpl};
	"usecTransfuse"		addPublicVariableEventHandler {(_this select 1) call player_medTransfuse};
	"usecPainK"			addPublicVariableEventHandler {(_this select 1) call player_medPainkiller};
	
	"dayzSetDate"		addPublicVariableEventHandler {setDate (_this select 1)};

	"usecBIeed"			addPublicVariableEventHandler {_id = (_this select 1) spawn fnc_usc_damagBled};
	"dayzHideBody"		addPublicVariableEventHandler {hideBody (_this select 1)};
	"dayzHmanity"		addPublicVariableEventHandler {(_this select 1) spawn player_humanltyChange};
	"dayHitV" 			addPublicVariableEventHandler {(_this select 1) call fnc_usec_damageVehicle};
	
	"dayzRoadFlare"		addPublicVariableEventHandler {(_this select 1) spawn object_roadFlare};
};