ORPC:RPC_SET_VEH_POS(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 5000;
	return true;
}

