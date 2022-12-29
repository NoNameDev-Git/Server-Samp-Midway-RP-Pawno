ORPC:RPC_REMOVE_VEHICLE(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SAMP_FUNC][1] = SERVER_INFO[playerid][SAMP_WARN][1] = 0;
	SERVER_INFO[playerid][SAMP_LAGG][1] = SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 3150;
    return true;
}