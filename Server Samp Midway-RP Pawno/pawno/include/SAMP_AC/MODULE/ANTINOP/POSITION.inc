	if(SERVER_INFO[playerid][SAMP_FUNC][0] == 0)
	{
		if(IsPlayerInRangeOfPoint(playerid, 100.0, SERVER_INFO[playerid][SAMP_POS_SX], SERVER_INFO[playerid][SAMP_POS_SY], SERVER_INFO[playerid][SAMP_POS_SZ]))
		{
			SERVER_INFO[playerid][SAMP_FUNC][0] = 1;
			SERVER_INFO[playerid][SAMP_WARN][0] = 1;
		}
		else if(SERVER_INFO[playerid][SAMP_TICK] > (SERVER_INFO[playerid][SAMP_LAGG][0] + 5000) + SERVER_INFO[playerid][SAMP_PING])
		{
			SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "SetPlayerPos", 50, 4);
		}
	}
