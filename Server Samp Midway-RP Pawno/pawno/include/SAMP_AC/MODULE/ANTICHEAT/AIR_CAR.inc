	if(CENTER_CONTROLE[11][CONTROL_STATE] == 1)
	{
		if(SERVER_INFO[playerid][SAMP_FUNC][0] != 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0)
		{
			if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SERVER_INFO[playerid][SAMP_PING])
			{
				new Float: SAMP_AC_DISTANCE = GetPlayerDistanceFromPoint(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z]);
				if(SAMP_AC_DISTANCE > 3.0 && SAMP_AC_REAL_SPEED(playerid) < 2 && SERVER_INFO[playerid][SAMP_POS_Z] > - 95.0)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Air Car", 11, 2);
				}
			}
		}
	}