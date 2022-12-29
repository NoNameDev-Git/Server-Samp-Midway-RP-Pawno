IRPC:RPC_SET_WORLD(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	
	SERVER_INFO[playerid][SAMP_FIX_WORLD] = SERVER_INFO[playerid][SAMP_TICK] + 500;
    return true;
}

