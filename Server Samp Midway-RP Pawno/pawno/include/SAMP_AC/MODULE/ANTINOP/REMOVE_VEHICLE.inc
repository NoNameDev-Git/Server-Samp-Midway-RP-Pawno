	if(SERVER_INFO[playerid][SAMP_FUNC][1] == 0)
	{
		if(SERVER_INFO[playerid][SAMP_ID_VEHICLE] <= 0 && SERVER_INFO[playerid][SAMP_ID_VEHICLE] == 0xFFFF)
		{
			SERVER_INFO[playerid][SAMP_ID_VEHICLE] = 0;
			SERVER_INFO[playerid][SAMP_FUNC][1] = 1;
		}
		else if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_LAGG][1] + 1000)
		{
			SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "RemovePlayerFromVehicle", 51, 3);
		}
	}