ORPC:RPC_SPECTATING(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	new STATE_SPECTATING;
	
	BS_ReadUint16(CELL_BYTE, STATE_SPECTATING);	
	if(STATE_SPECTATING == 0)
	{
		SERVER_INFO[playerid][SAMP_USE_SPAWN] ++;
		SERVER_INFO[playerid][SAMP_GTC_SPAWN] = 0;
	}
	return true;
}

