	if(CENTER_CONTROLE[15][CONTROL_STATE] == 1)
	{
		if(SERVER_INFO[playerid][SAMP_SPEED_Z] > -0.3)
		{
			if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_SPEED] && SAMP_AC_REAL_SPEED(playerid) > 500)
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Speed Hack Onfoot", 15, 1);
				return 0;
			}
		}
	}
