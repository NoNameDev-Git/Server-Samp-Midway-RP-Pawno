	if(CENTER_CONTROLE[14][CONTROL_STATE] == 1 && SAMP_AC_CHECK_MODEL_VEHICLE(RAKNET_DRIVER[RAKNET_VEHICLE]))
	{
		if(SERVER_INFO[playerid][SAMP_LAST_SPEED] != 0 && SAMP_AC_REAL_SPEED(playerid) != 0 && SERVER_INFO[playerid][SAMP_SPEED_Z] > -0.05)
		{
				if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_SPEED] && SAMP_AC_REAL_SPEED(playerid) - SERVER_INFO[playerid][SAMP_LAST_SPEED] > 3)
				{
					SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Speed Hack Smooth", 14, 3);
				}
				else SAC_WARNING_PROGRESSIVE[playerid][14] = 0;
		}
		else SAC_WARNING_PROGRESSIVE[playerid][14] = 0;
	}
