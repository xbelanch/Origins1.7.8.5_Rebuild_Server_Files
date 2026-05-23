if (isServer) then {
	waitUntil{dayz_preloadFinished};
};
_id = [] execFSM "Scripts\a2edc_player_monitor.fsm";
