ORPC:RPC_PUT_VEHICLE(playerid, BitStream:CELL_BYTE)
{
	if(playerid == -1) return true;
	new RAKNET_VEHICLE_ID;
	BS_ReadUint16(CELL_BYTE, RAKNET_VEHICLE_ID);	
	BS_ReadUint16(CELL_BYTE, SERVER_INFO[playerid][SAMP_ID_SEAT]);
	
	SERVER_INFO[playerid][SAMP_ID_VEHICLE] = SERVER_INFO[playerid][SAMP_SET_VEHICLE] = SERVER_INFO[playerid][SAMP_USE_VEHICLE] = RAKNET_VEHICLE_ID;
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 2500;
	SERVER_INFO[playerid][SAMP_FUNC][2] = SERVER_INFO[playerid][SAMP_WARN][2] = 0; 
	SERVER_INFO[playerid][SAMP_FUNC][1] = 1;
	return 0x1;
}