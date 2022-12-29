ORPC:RPC_VEHICLE_VELOCITY(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SAMP_FIX_SPEED] = SERVER_INFO[playerid][SAMP_TICK] + 500;
    return true;
}