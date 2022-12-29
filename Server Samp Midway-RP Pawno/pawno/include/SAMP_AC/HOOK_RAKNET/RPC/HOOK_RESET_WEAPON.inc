ORPC:RPC_RESET_WEAPON(playerid, BitStream:bs)
{
	if(playerid == -1) return true;
	for(new i = 12; i >= 0; i --)
	{
		SERVER_INFO[playerid][SAMP_WEAPON][i] = SERVER_INFO[playerid][SAMP_AMMOUT][i] = 0;
	}
	SERVER_INFO[playerid][SAMP_USE_WEAPON] = 1;
	SERVER_INFO[playerid][SAMP_TIC_WEAPON] = SERVER_INFO[playerid][SAMP_TICK] + 1000;
	return true;
}