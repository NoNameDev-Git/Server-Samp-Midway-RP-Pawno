	if(CENTER_CONTROLE[4][CONTROL_STATE] == 1)
	{
		if(SERVER_INFO[playerid][SAMP_FUNC][0] != 0 && SERVER_INFO[playerid][SAMP_FUNC][1] != 0 && SERVER_INFO[playerid][SAMP_FUNC][2] != 0)
		{
			if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_BRAKE] + SERVER_INFO[playerid][SAMP_PING] && SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_WORLD] + 500)
			{
				new Float: SAMP_AC_DISTANCE = GetPlayerDistanceFromPoint(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z]);
				
				if(SAMP_AC_DISTANCE > 35.0 && SERVER_INFO[playerid][SAMP_FIX_TELEPORT] > -95)
				{
					if(GetPlayerSurfingVehicleID(playerid) == 0xFFFF && GetPlayerSurfingObjectID(playerid) == 0xFFFF && GetPVarInt(playerid, "anticheat_tp") < gettime())
					{
						SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Teleport Hack", 4, 0);
					}
				}
				SERVER_INFO[playerid][SAMP_FIX_TELEPORT] = SERVER_INFO[playerid][SAMP_POS_Z];
			}
		}
	}
