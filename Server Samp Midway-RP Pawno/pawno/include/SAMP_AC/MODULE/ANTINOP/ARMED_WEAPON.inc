	if(SERVER_INFO[playerid][SAMP_USE_WEAPON] == 0)
	{
		if(SERVER_INFO[playerid][SAMP_SET_WEAPON] == GetPlayerWeapon(playerid))
		{
			SERVER_INFO[playerid][SAMP_USE_WEAPON] = 1;
		}
		else if(!(PLAYER_STATE_DRIVER <= GetPlayerState(playerid) <= PLAYER_STATE_PASSENGER))
		{
			if(SERVER_INFO[playerid][SAMP_TICK] > (SERVER_INFO[playerid][SAMP_GTC_WEAPON] + 1650) + SERVER_INFO[playerid][SAMP_PING])
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "SetPlayerArmedWeapon", 53, 2);
			}
		}
	}