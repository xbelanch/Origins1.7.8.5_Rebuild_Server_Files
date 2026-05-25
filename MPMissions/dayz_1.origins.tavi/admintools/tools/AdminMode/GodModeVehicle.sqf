/*
Not 100% god mode. There is a chance the car can still be blown
up, but the chance is small. This will be a good script until
a better solution is found. DOES NOT interfere with normal god mode
*/
private ["_vehicle","_beforeDamage","_isPatrolVehicle"];
vehicleGod = _this select 0;
if (isNil "A2EDC_adminVehicleGodLastTrace") then {
	A2EDC_adminVehicleGodLastTrace = 0;
};
while{alive (vehicle player) && vehicleGod} do
{
	_vehicle = vehicle player;
	_beforeDamage = damage _vehicle;
	_isPatrolVehicle = _vehicle getVariable ["A2EDC_WAI_patrolVehicle",false];
	if (_isPatrolVehicle) then {
		if ((diag_tickTime - A2EDC_adminVehicleGodLastTrace) > 1) then {
			A2EDC_adminVehicleGodLastTrace = diag_tickTime;
			diag_log format ["A2EDC:ADMIN:VEHICLE_GOD vehicle=%1 class=%2 patrolVehicle=%3 beforeDamage=%4 godMode=%5 carGodMode=%6 vehicleGod=%7 adminMode=%8",_vehicle,typeOf _vehicle,_isPatrolVehicle,_beforeDamage,if (isNil "godMode") then {"<nil>"} else {godMode},if (isNil "carGodMode") then {"<nil>"} else {carGodMode},vehicleGod,if (isNil "AdminMode") then {"<nil>"} else {AdminMode}];
		};
	};
	_vehicle setfuel 1;
	_vehicle setdammage 0;
	if (_isPatrolVehicle) then {
		if (_beforeDamage > 0.01) then {
			diag_log format ["A2EDC:ADMIN:VEHICLE_GOD_RESET vehicle=%1 class=%2 beforeDamage=%3 afterDamage=%4",_vehicle,typeOf _vehicle,_beforeDamage,damage _vehicle];
		};
	};
	sleep 0.001;
};
