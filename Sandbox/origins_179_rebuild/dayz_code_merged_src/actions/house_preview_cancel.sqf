private["_target","_caller","_actionId","_args","_blueprint","_dbHouseType","_runtimeClass","_preview","_marker","_mixer","_ownerUID","_position","_direction","_confirmAction","_cancelAction","_rotateLeftAction","_rotateRightAction"];

_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_args = _this select 3;

if ((typeName _args) != "ARRAY" || {(count _args) != 7}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_HANDLER_MISSING handler=cancel actionId=%1 caller=%2 target=%3 args=%4 source=addAction_arguments reason=invalid_context",_actionId,_caller,_target,_args];
};

_blueprint = _args select 0;
_dbHouseType = _args select 1;
_runtimeClass = _args select 2;
_preview = _args select 3;
_marker = _args select 4;
_mixer = _args select 5;
_ownerUID = _args select 6;
_position = if (isNil "A2EDC_housePreviewPosition") then {[]} else {+A2EDC_housePreviewPosition};
_direction = if (isNil "A2EDC_housePreviewDirection") then {-1} else {A2EDC_housePreviewDirection};
_confirmAction = if (isNil "A2EDC_housePreviewConfirmAction") then {-1} else {A2EDC_housePreviewConfirmAction};
_cancelAction = if (isNil "A2EDC_housePreviewCancelAction") then {_actionId} else {A2EDC_housePreviewCancelAction};
_rotateLeftAction = if (isNil "A2EDC_housePreviewRotateLeftAction") then {-1} else {A2EDC_housePreviewRotateLeftAction};
_rotateRightAction = if (isNil "A2EDC_housePreviewRotateRightAction") then {-1} else {A2EDC_housePreviewRotateRightAction};

diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_SELECTED handler=cancel actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 ownerUID=%12 source=addAction_arguments previewNull=%13 markerNull=%14 mixerNull=%15",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,isNull _preview,isNull _marker,isNull _mixer];
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_BEGIN actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 source=addAction_arguments previewNull=%12 markerNull=%13",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,isNull _preview,isNull _marker];

if (!isNil "A2EDC_housePreviewConfirmInProgress" && {A2EDC_housePreviewConfirmInProgress}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_DUPLICATE_IGNORED handler=cancel actionId=%1 caller=%2 target=%3 blueprint=%4 reason=confirm_in_progress",_actionId,_caller,_target,_blueprint];
};

A2EDC_housePreviewConfirmInProgress = true;
A2EDC_housePreviewActive = false;
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_AFTER_BEGIN actionId=%1 caller=%2 target=%3 blueprint=%4 result=continue_cleanup",_actionId,_caller,_target,_blueprint];
diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_DEBOUNCE_SET handler=cancel actionId=%1 caller=%2 target=%3 blueprint=%4 value=true",_actionId,_caller,_target,_blueprint];
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_REMOVE_ACTIONS actionId=%1 confirmAction=%2 cancelAction=%3 caller=%4",_actionId,_confirmAction,_cancelAction,_caller];
diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_REMOVE handler=cancel actionId=%1 confirmAction=%2 cancelAction=%3 caller=%4",_actionId,_confirmAction,_cancelAction,_caller];
if (_confirmAction >= 0) then {_caller removeAction _confirmAction;};
_caller removeAction _cancelAction;
if (_rotateLeftAction >= 0) then {_caller removeAction _rotateLeftAction;};
if (_rotateRightAction >= 0) then {_caller removeAction _rotateRightAction;};
diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_ACTION_REMOVE handler=cancel actionId=%1 leftAction=%2 rightAction=%3 preview=%4 greenGhost=%5 redGhost=%6 finalDirection=%7",_actionId,_rotateLeftAction,_rotateRightAction,_preview,_marker,_preview,_direction];
diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_REMOVE_DONE handler=cancel actionId=%1 confirmAction=%2 cancelAction=%3 rotateLeftAction=%4 rotateRightAction=%5 caller=%6",_actionId,_confirmAction,_cancelAction,_rotateLeftAction,_rotateRightAction,_caller];
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_DELETE_PREVIEW actionId=%1 preview=%2 previewNullBefore=%3",_actionId,_preview,isNull _preview];
deleteVehicle _preview;
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_DELETE_MARKER actionId=%1 marker=%2 markerNullBefore=%3",_actionId,_marker,isNull _marker];
deleteVehicle _marker;
A2EDC_housePreviewChoice = 0;
diag_log format ["A2EDC:HOUSE_PREVIEW_CLEANUP handler=cancel actionId=%1 preview=%2 marker=%3 previewNull=%4 markerNull=%5 confirmAction=%6 cancelAction=%7 rotateLeftAction=%8 rotateRightAction=%9 requestSent=false",_actionId,_preview,_marker,isNull _preview,isNull _marker,_confirmAction,_cancelAction,_rotateLeftAction,_rotateRightAction];
diag_log format ["A2EDC:HOUSE_PREVIEW_CANCEL_DONE actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 ownerUID=%12 source=handler previewNull=%13 markerNull=%14 requestSent=false rotateLeftAction=%15 rotateRightAction=%16",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,isNull _preview,isNull _marker,_rotateLeftAction,_rotateRightAction];
