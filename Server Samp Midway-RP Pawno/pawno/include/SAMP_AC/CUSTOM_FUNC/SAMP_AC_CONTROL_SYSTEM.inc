enum E_SAMP_AC_CENTRAL_CONTROLE
{
	CONTROL_DAMAGE,
	CONTROL_STATE,
	CONTROL_DOOM,
}
new CENTER_CONTROLE[100][E_SAMP_AC_CENTRAL_CONTROLE];


forward SAMP_AC_UPLOAD_SETTING(SAMP_AC_CODE, SAMP_AC_STATE, SAMP_AC_DOOM);
public SAMP_AC_UPLOAD_SETTING(SAMP_AC_CODE, SAMP_AC_STATE, SAMP_AC_DOOM)
{
	CENTER_CONTROLE[SAMP_AC_CODE + 1][CONTROL_STATE] = SAMP_AC_STATE;
	CENTER_CONTROLE[SAMP_AC_CODE + 1][CONTROL_DOOM] = SAMP_AC_DOOM;
	return true;
}

public OnGameModeInit()
{
	for(new i = 0; i != 100; i ++)
	{
		CENTER_CONTROLE[i][CONTROL_STATE] = 1;
		CENTER_CONTROLE[i][CONTROL_DOOM] = 0;
	}
	CENTER_CONTROLE[0][CONTROL_DAMAGE] = SAMP_AC_STATE_DAMAGE;
#if defined SAC_OnGameModeInit
    return SAC_OnGameModeInit();
#else
	return true;
#endif
}
#if defined _ALS_OnGameModeInit
    #undef    OnGameModeInit
#else
    #define    _ALS_OnGameModeInit
#endif
#define    OnGameModeInit    SAC_OnGameModeInit
#if defined SAC_OnGameModeInit
forward SAC_OnGameModeInit();
#endif

public OnFilterScriptInit()
{
	for(new i = 0; i != 100; i ++)
	{
		CENTER_CONTROLE[i][CONTROL_STATE] = 1;
		CENTER_CONTROLE[i][CONTROL_DOOM] = 0;
	}
	CENTER_CONTROLE[0][CONTROL_DAMAGE] = SAMP_AC_STATE_DAMAGE;
#if defined SAC_OnFilterScriptInit
    return SAC_OnFilterScriptInit();
#else
	return true;
#endif
}
#if defined _ALS_OnFilterScriptInit
    #undef    OnFilterScriptInit
#else
    #define    _ALS_OnFilterScriptInit
#endif
#define    OnFilterScriptInit    SAC_OnFilterScriptInit
#if defined SAC_OnFilterScriptInit
forward SAC_OnFilterScriptInit();
#endif

forward SAMP_AC_SEND_STATE_DAMAGE(SAMP_AC_STATE);
public SAMP_AC_SEND_STATE_DAMAGE(SAMP_AC_STATE)
{
	if(SAMP_AC_STATE < 0 || SAMP_AC_STATE > 1) return 0x1;
	CENTER_CONTROLE[0][CONTROL_DAMAGE] = SAMP_AC_STATE;
	return 0x1;
}