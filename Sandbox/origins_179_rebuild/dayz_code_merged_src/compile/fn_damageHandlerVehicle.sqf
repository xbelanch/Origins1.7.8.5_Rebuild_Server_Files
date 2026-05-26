scriptName "Functions\misc\fn_damageHandler.sqf";
/***********************************************************
	PROCESS DAMAGE TO A UNIT
	- Function
	- [unit, selectionName, damage, source, projectile] call fnc_usec_damageHandler;
	[_vehicle,_wound,_total,_unit,"zombie"]
************************************************************/
private["_unit","_hit","_damage","_unconscious","_wound","_isHit","_isInjured","_type","_hitPain","_inPain","_isDead","_isCardiac","_killerID","_evType","_recordable","_inVehicle","_isHeadHit","_isMinor","_total"];
_unit = _this select 0;
_hit = _this select 1;
_damage = _this select 2;
_source = _this select 3;
_ammo = _this select 4;
_total = _damage;

diag_log format ["DAMAGE VEH: type=%1, _hit=%2, _damage=%3, _ammo=%4",(typeof _unit),_hit,_damage,_ammo];

if (local _unit) then {
		_total = [_unit,_hit,_damage] call object_setHitServer;
		diag_log format ["Unit local,_unit=%1, _hit=%2, _damage=%3",_unit,_hit,_damage];
	};
diag_log format ["Unit NOT local,_total=%1",_total];
_total