ORPC:RPC_SET_ARM_WEAPON(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	
	BS_ReadUint16(CELL_BYTE, SERVER_INFO[playerid][SAMP_SET_WEAPON]);	
	
	if(0 <= SERVER_INFO[playerid][SAMP_SET_WEAPON] <= 18 || 22 <= SERVER_INFO[playerid][SAMP_SET_WEAPON] <= 46 && !(PLAYER_STATE_DRIVER <= GetPlayerState(playerid) <= PLAYER_STATE_PASSENGER))
	{
		SERVER_INFO[playerid][SAMP_GTC_WEAPON] = SERVER_INFO[playerid][SAMP_TICK];
		SERVER_INFO[playerid][SAMP_USE_WEAPON] = 0;
	}
	return 0x1;
}

