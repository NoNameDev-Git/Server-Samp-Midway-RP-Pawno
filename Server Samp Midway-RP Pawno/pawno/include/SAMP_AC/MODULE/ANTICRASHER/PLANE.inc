			if(SERVER_INFO[playerid][SAMP_TICK] < SERVER_INFO[playerid][SAMP_LAGG][91])
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Plane Crasher", 91, 0);
				return 0;
			}
			SERVER_INFO[playerid][SAMP_LAGG][91] = SERVER_INFO[playerid][SAMP_TICK] + 400;