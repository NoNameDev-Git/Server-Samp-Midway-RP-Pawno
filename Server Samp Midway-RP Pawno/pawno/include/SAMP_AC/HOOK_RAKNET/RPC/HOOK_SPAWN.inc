ORPC:RPC_SPAWN_PLAYER(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	
	SERVER_INFO[playerid][SAMP_USE_SPAWN] ++;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = 0;
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 4000;
	SERVER_INFO[playerid][SAMP_FIX_POSITION] = 1;
    return true;
}

