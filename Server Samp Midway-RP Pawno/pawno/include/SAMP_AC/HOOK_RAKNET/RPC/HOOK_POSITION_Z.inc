ORPC:RPC_SET_POS_FIND_Z(playerid, BitStream: CELL_BYTE)
{
	if(playerid == -1) return true;
	BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SX]);
    BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SY]);
    BS_ReadFloat(CELL_BYTE, SERVER_INFO[playerid][SAMP_POS_SZ]);
	
	SERVER_INFO[playerid][SAMP_FUNC][0] = SERVER_INFO[playerid][SAMP_WARN][0] = 0;
	SERVER_INFO[playerid][SAMP_LAGG][0] = SERVER_INFO[playerid][SAMP_TICK];
	return true;
}

