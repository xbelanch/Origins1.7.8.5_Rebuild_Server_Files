private["_target","_caller","_actionId","_args","_side","_step","_oldDir","_oldOffset","_newOffset","_newDir","_preview","_marker","_position"];

_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_args = _this select 3;

if ((typeName _args) != "ARRAY" || {(count _args) < 2}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_ERROR actionId=%1 caller=%2 target=%3 args=%4 reason=invalid_args",_actionId,_caller,_target,_args];
};

_side = _args select 0;
_step = _args select 1;
if ((typeName _step) != "SCALAR") then {_step = 15;};
if (_side != "left" && {_side != "right"}) then {_side = "right";};

_oldDir = if (isNil "A2EDC_housePreviewDirection") then {round(direction _caller)} else {A2EDC_housePreviewDirection};
_oldOffset = if (isNil "A2EDC_housePreviewRotationOffset") then {0} else {A2EDC_housePreviewRotationOffset};
if (_side == "left") then {
	_newOffset = _oldOffset - _step;
} else {
	_newOffset = _oldOffset + _step;
};
while {_newOffset < 0} do {_newOffset = _newOffset + 360;};
while {_newOffset >= 360} do {_newOffset = _newOffset - 360;};
_newDir = (round(direction _caller) + _newOffset) mod 360;

A2EDC_housePreviewRotationOffset = _newOffset;
A2EDC_housePreviewDirection = _newDir;

_preview = if (isNil "A2EDC_housePreviewObject") then {objNull} else {A2EDC_housePreviewObject};
_marker = if (isNil "A2EDC_housePreviewMarker") then {objNull} else {A2EDC_housePreviewMarker};
_position = if (isNil "A2EDC_housePreviewPosition") then {[]} else {+A2EDC_housePreviewPosition};
if (!isNull _preview) then {_preview setDir _newDir;};
if (!isNull _marker) then {_marker setDir _newDir;};

if (_side == "left") then {
	diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_LEFT actionId=%1 oldDirection=%2 newDirection=%3 oldOffset=%4 newOffset=%5 stepDegrees=%6 preview=%7 greenGhost=%8 redGhost=%9 finalDirection=%10 position=%11",_actionId,_oldDir,_newDir,_oldOffset,_newOffset,_step,_preview,_marker,_preview,A2EDC_housePreviewDirection,_position];
} else {
	diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_RIGHT actionId=%1 oldDirection=%2 newDirection=%3 oldOffset=%4 newOffset=%5 stepDegrees=%6 preview=%7 greenGhost=%8 redGhost=%9 finalDirection=%10 position=%11",_actionId,_oldDir,_newDir,_oldOffset,_newOffset,_step,_preview,_marker,_preview,A2EDC_housePreviewDirection,_position];
};
diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_APPLY actionId=%1 side=%2 oldDirection=%3 newDirection=%4 stepDegrees=%5 preview=%6 greenGhost=%7 redGhost=%8 finalDirection=%9 position=%10",_actionId,_side,_oldDir,_newDir,_step,_preview,_marker,_preview,A2EDC_housePreviewDirection,_position];
