public OnPlayerStateChange(playerid, newstate, oldstate)
{

#if defined SAC_OnPlayerStateChange
    return SAC_OnPlayerStateChange(playerid, newstate, oldstate);
#else
	return true;
#endif
}
#if defined _ALS_OnPlayerStateChange
    #undef    OnPlayerStateChange
#else
    #define    _ALS_OnPlayerStateChange
#endif
#define    OnPlayerStateChange    SAC_OnPlayerStateChange
#if defined SAC_OnPlayerStateChange
forward SAC_OnPlayerStateChange(playerid, newstate, oldstate);
#endif
