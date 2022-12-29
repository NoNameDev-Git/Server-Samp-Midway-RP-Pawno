	if(CENTER_CONTROLE[8][CONTROL_STATE] == 1)
	{
		if(1 == SAMP_AC_CHECK_MODEL_PLANE(RAKNET_PASSENGER[RAKNET_VEHICLE]))
		{
			if(SERVER_INFO[playerid][SAMP_ID_VEHICLE] == 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0)
			{
				if(RAKNET_PASSENGER[RAKNET_VEHICLE] != SERVER_INFO[playerid][SAMP_USE_VEHICLE] || SERVER_INFO[playerid][SAMP_TICK] < SERVER_INFO[playerid][SAMP_GTC_VEHICLE] + 600)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Fast Enter Car Passenger", 8, 0);
				}
			
			}
		}
	}