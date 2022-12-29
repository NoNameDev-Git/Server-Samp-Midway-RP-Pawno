public OnPlayerSpawn(playerid)
{
	if(CENTER_CONTROLE[1][CONTROL_STATE] == 1)
	{
		if(SERVER_INFO[playerid][SAMP_USE_SPAWN] < 1 || SERVER_INFO[playerid][SAMP_TICK] < SERVER_INFO[playerid][SAMP_GTC_SPAWN] + 2000)
		{
			if(SERVER_INFO[playerid][SAMP_FIX_SPAWN] != 1)
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Fast Spawn", 1, 0);
			}
		}
	}
	SERVER_INFO[playerid][SAMP_USE_SPAWN] -= 1;
	SERVER_INFO[playerid][SAMP_FIX_SPAWN] = 0;
	
#if defined SAC_OnPlayerSpawn
    return SAC_OnPlayerSpawn(playerid);
#else
	return true;
#endif
}
#if defined _ALS_OnPlayerSpawn
    #undef    OnPlayerSpawn
#else
    #define    _ALS_OnPlayerSpawn
#endif
#define    OnPlayerSpawn    SAC_OnPlayerSpawn
#if defined SAC_OnPlayerSpawn
forward SAC_OnPlayerSpawn(playerid);
#endif

