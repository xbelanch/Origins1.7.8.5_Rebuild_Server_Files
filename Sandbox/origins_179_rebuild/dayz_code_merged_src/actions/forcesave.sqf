private["_object"];

dayUpdateVehlcle = [_this select 3,"all"];
publicVariableServer "dayUpdateVehlcle";
if (isServer) then {
	dayUpdateVehlcle call server_updatObiect;
	diag_log ("Server forcesave.sqf");
};