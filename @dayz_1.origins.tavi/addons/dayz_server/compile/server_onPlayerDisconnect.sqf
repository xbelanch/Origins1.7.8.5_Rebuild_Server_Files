private ["_playerID","_playerName","_object","_characterID","_timeout","_playerIDtoarray"];
_playerID = _this select 0;
_playerName = _this select 1;
_object = call compile format["if (isNil ""player%1"") then {objNull} else {player%1}",_playerID];
_characterID =	_object getVariable ["characterID","0"];
_timeout = _object getVariable["combattimeout",0];

_playerIDtoarray = [];
_playerIDtoarray = toArray _playerID;

if ((!isNull _object) && {vehicle _object != _object}) then {
_object action ["eject", vehicle _object];
};

if (59 in _playerIDtoarray) exitWith { 	diag_log ("Exited"); };

if ((_timeout - time) > 0) then {

_playerName = name player;
_timeout = _object getVariable["combattimeout",0];

diag_log format["COMBAT LOGGED: %1 (%2)", _playerName,_timeout];
};

diag_log format["DISCONNECT: %1 (%2) Object: %3, _characterID: %4", _playerName,_playerID,_object,_characterID];
diag_log format["A2EDC:REJOIN:DISCONNECT_BEGIN uid=%1 name=%2 charID=%3 object=%4 isNull=%5 pos=%6 botPlayers=%7 dayz_disco=%8",_playerID,_playerName,_characterID,_object,isNull _object,if (isNull _object) then {[]} else {getPosATL _object},if (isNil "botPlayers") then {"<nil>"} else {botPlayers},if (isNil "dayz_disco") then {"<nil>"} else {dayz_disco}];

dayz_disco = dayz_disco - [_playerID];
if (!isNull _object) then {

{ [_x,"gear"] call server_updateObject } foreach 
(nearestObjects [getPosATL _object, ["Car", "Helicopter", "Motorcycle", "Ship", "TentStorage", "TentStorageR"], 10]);
if (alive _object) then {
[_object,[],true] call server_playerSync;

diag_log format["BOTLOG spawn disco_playerMorph: %1 (%2) %3", _object,_playerID,_characterID];
[_object,_playerID,_characterID,30] spawn disco_playerMorph;
_id = [_playerID,_characterID,2] spawn dayz_recordLogin;
};
};
diag_log format["A2EDC:REJOIN:DISCONNECT_END uid=%1 name=%2 charID=%3 object=%4 botPlayers=%5 dayz_disco=%6",_playerID,_playerName,_characterID,_object,if (isNil "botPlayers") then {"<nil>"} else {botPlayers},if (isNil "dayz_disco") then {"<nil>"} else {dayz_disco}];
