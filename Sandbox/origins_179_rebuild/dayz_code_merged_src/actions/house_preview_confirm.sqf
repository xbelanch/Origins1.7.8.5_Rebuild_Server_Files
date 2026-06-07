private["_target","_caller","_actionId","_args","_blueprint","_dbHouseType","_runtimeClass","_preview","_marker","_mixer","_ownerUID","_position","_direction","_contextReady","_valid","_payload","_confirmAction","_cancelAction","_rotateLeftAction","_rotateRightAction","_invalidReason"];

_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_args = _this select 3;
_contextReady = ((typeName _args) == "ARRAY") && {(count _args) == 7};

if (!_contextReady) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_HANDLER_MISSING handler=confirm actionId=%1 caller=%2 target=%3 args=%4 source=addAction_arguments reason=invalid_context",_actionId,_caller,_target,_args];
};

_blueprint = _args select 0;
_dbHouseType = _args select 1;
_runtimeClass = _args select 2;
_preview = _args select 3;
_marker = _args select 4;
_mixer = _args select 5;
_ownerUID = _args select 6;
_position = if (isNil "A2EDC_housePreviewBuildPosition") then {if (isNil "A2EDC_housePreviewPosition") then {[]} else {+A2EDC_housePreviewPosition}} else {+A2EDC_housePreviewBuildPosition};
_direction = if (isNil "A2EDC_housePreviewDirection") then {-1} else {A2EDC_housePreviewDirection};
_valid = if (isNil "A2EDC_housePreviewValid") then {false} else {A2EDC_housePreviewValid};
_invalidReason = if (isNil "A2EDC_housePreviewInvalidReason") then {"current_preview_invalid"} else {A2EDC_housePreviewInvalidReason};
_confirmAction = if (isNil "A2EDC_housePreviewConfirmAction") then {_actionId} else {A2EDC_housePreviewConfirmAction};
_cancelAction = if (isNil "A2EDC_housePreviewCancelAction") then {-1} else {A2EDC_housePreviewCancelAction};
_rotateLeftAction = if (isNil "A2EDC_housePreviewRotateLeftAction") then {-1} else {A2EDC_housePreviewRotateLeftAction};
_rotateRightAction = if (isNil "A2EDC_housePreviewRotateRightAction") then {-1} else {A2EDC_housePreviewRotateRightAction};

diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_SELECTED handler=confirm actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 ownerUID=%12 source=addAction_arguments previewNull=%13 markerNull=%14 mixerNull=%15",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,isNull _preview,isNull _marker,isNull _mixer];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_BEGIN actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 source=addAction_arguments valid=%12",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_valid];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_CURRENT_STATE actionId=%1 caller=%2 preview=%3 marker=%4 buildPosition=%5 direction=%6 valid=%7 reason=%8 confirmAction=%9 cancelAction=%10 rotateLeftAction=%11 rotateRightAction=%12 rotationOffset=%13",_actionId,_caller,_preview,_marker,_position,_direction,_valid,_invalidReason,_confirmAction,_cancelAction,_rotateLeftAction,_rotateRightAction,if (isNil "A2EDC_housePreviewRotationOffset") then {0} else {A2EDC_housePreviewRotationOffset}];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_STALE_ARGS_IGNORED actionId=%1 args=%2 latestPosition=%3 latestDirection=%4 reason=addAction_args_contain_object_context_not_position_state",_actionId,_args,_position,_direction];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_LATEST_STATE_USED actionId=%1 finalPayloadPosition=%2 finalPayloadDirection=%3 valid=%4 reason=%5",_actionId,_position,_direction,_valid,_invalidReason];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_ARGS actionId=%1 caller=%2 target=%3 args=%4 globalContext=%5 source=addAction_arguments",_actionId,_caller,_target,_args,if (isNil "A2EDC_housePreviewContext") then {[]} else {A2EDC_housePreviewContext}];

if (!isNil "A2EDC_housePreviewConfirmInProgress" && {A2EDC_housePreviewConfirmInProgress}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_DUPLICATE_IGNORED handler=confirm actionId=%1 caller=%2 target=%3 blueprint=%4 reason=confirm_in_progress",_actionId,_caller,_target,_blueprint];
};
if (isNull _preview || {isNull _marker} || {isNull _mixer}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_HANDLER_ERROR handler=confirm actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 cementMixer=%6 reason=required_object_null",_actionId,_caller,_target,_preview,_marker,_mixer];
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REQUEST_NOT_SENT actionId=%1 valid=%2 reason=required_object_null blueprint=%3 dbHouseType=%4 runtimeClass=%5 buildPosition=%6 direction=%7 cementMixer=%8 ownerUID=%9 preview=%10 marker=%11 pvName=wantbbplz payloadCount=0 payloadType=ARRAY",_actionId,_valid,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker];
};
if (!_valid) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_VALIDITY actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 source=global valid=false reason=%12",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_invalidReason];
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REJECTED_INVALID actionId=%1 caller=%2 blueprint=%3 buildPosition=%4 direction=%5 reason=%6",_actionId,_caller,_blueprint,_position,_direction,_invalidReason];
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REQUEST_NOT_SENT actionId=%1 valid=false reason=%2 blueprint=%3 dbHouseType=%4 runtimeClass=%5 buildPosition=%6 direction=%7 cementMixer=%8 ownerUID=%9 preview=%10 marker=%11 pvName=wantbbplz payloadCount=0 payloadType=ARRAY",_actionId,_invalidReason,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker];
	titleText [format ["Foundation placement is invalid: %1",_invalidReason], "PLAIN DOWN"];
};
if ((typeName _position) != "ARRAY" || {(count _position) != 3} || {(typeName _direction) != "SCALAR"} || {(getPlayerUID _caller) != _ownerUID}) exitWith {
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_ERROR actionId=%1 valid=%2 reason=invalid_final_context blueprint=%3 dbHouseType=%4 runtimeClass=%5 buildPosition=%6 direction=%7 cementMixer=%8 ownerUID=%9 callerUID=%10 preview=%11 marker=%12 pvName=wantbbplz",_actionId,_valid,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,getPlayerUID _caller,_preview,_marker];
	diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REQUEST_NOT_SENT actionId=%1 valid=%2 reason=invalid_final_context blueprint=%3 dbHouseType=%4 runtimeClass=%5 buildPosition=%6 direction=%7 cementMixer=%8 ownerUID=%9 preview=%10 marker=%11 pvName=wantbbplz payloadCount=0 payloadType=ARRAY",_actionId,_valid,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker];
};

A2EDC_housePreviewConfirmInProgress = true;
A2EDC_housePreviewActive = false;
diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_DEBOUNCE_SET handler=confirm actionId=%1 caller=%2 target=%3 blueprint=%4 value=true",_actionId,_caller,_target,_blueprint];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_VALIDITY actionId=%1 caller=%2 target=%3 preview=%4 marker=%5 blueprint=%6 dbHouseType=%7 runtimeClass=%8 buildPosition=%9 direction=%10 cementMixer=%11 source=global valid=true reason=handler_accepted",_actionId,_caller,_target,_preview,_marker,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_AFTER_VALIDITY actionId=%1 valid=true reason=handler_accepted blueprint=%2 dbHouseType=%3 runtimeClass=%4 buildPosition=%5 direction=%6 cementMixer=%7 ownerUID=%8 preview=%9 marker=%10 pvName=wantbbplz",_actionId,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker];

diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_REMOVE handler=confirm actionId=%1 confirmAction=%2 cancelAction=%3 caller=%4",_actionId,_confirmAction,_cancelAction,_caller];
_caller removeAction _confirmAction;
if (_cancelAction >= 0) then {_caller removeAction _cancelAction;};
if (_rotateLeftAction >= 0) then {_caller removeAction _rotateLeftAction;};
if (_rotateRightAction >= 0) then {_caller removeAction _rotateRightAction;};
diag_log format ["A2EDC:HOUSE_PREVIEW_ROTATE_ACTION_REMOVE handler=confirm actionId=%1 leftAction=%2 rightAction=%3 preview=%4 greenGhost=%5 redGhost=%6 finalDirection=%7",_actionId,_rotateLeftAction,_rotateRightAction,_preview,_marker,_preview,_direction];
diag_log format ["A2EDC:HOUSE_PREVIEW_ACTION_REMOVE_DONE handler=confirm actionId=%1 confirmAction=%2 cancelAction=%3 rotateLeftAction=%4 rotateRightAction=%5 caller=%6",_actionId,_confirmAction,_cancelAction,_rotateLeftAction,_rotateRightAction,_caller];

_payload = [_caller,_blueprint,_ownerUID,_position,_direction];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_BUILD_PAYLOAD actionId=%1 valid=true reason=handler_accepted blueprint=%2 dbHouseType=%3 runtimeClass=%4 buildPosition=%5 direction=%6 cementMixer=%7 ownerUID=%8 preview=%9 marker=%10 pvName=wantbbplz payload=%11 payloadCount=%12 payloadType=%13",_actionId,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker,_payload,count _payload,typeName _payload];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REQUEST_SEND_BEGIN actionId=%1 valid=true reason=handler_accepted blueprint=%2 dbHouseType=%3 runtimeClass=%4 buildPosition=%5 direction=%6 cementMixer=%7 ownerUID=%8 preview=%9 marker=%10 pvName=wantbbplz payloadCount=%11 payloadType=%12",_actionId,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker,count _payload,typeName _payload];
wantbbplz = _payload;
publicVariableServer "wantbbplz";
A2EDC_housePreviewRequestSent = true;
_caller removeMagazine _blueprint;
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_REQUEST_SENT actionId=%1 valid=true reason=handler_accepted blueprint=%2 dbHouseType=%3 runtimeClass=%4 buildPosition=%5 direction=%6 cementMixer=%7 ownerUID=%8 preview=%9 marker=%10 pvName=wantbbplz payload=%11 payloadCount=%12 payloadType=%13",_actionId,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker,_payload,count _payload,typeName _payload];
diag_log format ["A2EDC:HOUSE_FOUNDATION_REQUEST_SENT_AFTER_CONFIRM payload=%1 position=%2 direction=%3 actionId=%4 source=house_preview_confirm_handler",_payload,_position,_direction,_actionId];

deleteVehicle _preview;
deleteVehicle _marker;
A2EDC_housePreviewChoice = 1;
diag_log format ["A2EDC:HOUSE_PREVIEW_CLEANUP handler=confirm actionId=%1 preview=%2 marker=%3 previewNull=%4 markerNull=%5 requestSent=true",_actionId,_preview,_marker,isNull _preview,isNull _marker];
diag_log format ["A2EDC:HOUSE_PREVIEW_CONFIRM_EXIT actionId=%1 valid=true reason=request_sent_and_local_cleanup_done blueprint=%2 dbHouseType=%3 runtimeClass=%4 buildPosition=%5 direction=%6 cementMixer=%7 ownerUID=%8 preview=%9 marker=%10 pvName=wantbbplz payloadCount=%11 payloadType=%12",_actionId,_blueprint,_dbHouseType,_runtimeClass,_position,_direction,_mixer,_ownerUID,_preview,_marker,count _payload,typeName _payload];
