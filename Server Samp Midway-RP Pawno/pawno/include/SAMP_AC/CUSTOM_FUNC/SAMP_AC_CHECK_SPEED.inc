stock SAMP_AC_REAL_SPEED(playerid)
{
    new ac_v = GetPlayerVehicleID(playerid);
    new SAMP_AC_SPEED;
    
	new Float: SAMP_AC_SPEED_X, Float: SAMP_AC_SPEED_Y, Float: SAMP_AC_SPEED_Z;
    if(ac_v > 0)
	{
	    if(GetTickCount() < SERVER_INFO[playerid][SAMP_FIX_SPEED])
	    {
	        SAMP_AC_SPEED = 0;
	    }
	    else
	    {
			GetVehicleVelocity(ac_v, SAMP_AC_SPEED_X, SAMP_AC_SPEED_Y, SAMP_AC_SPEED_Z);
	    	SAMP_AC_SPEED = floatround(VectorSize(SAMP_AC_SPEED_X, SAMP_AC_SPEED_Y, SAMP_AC_SPEED_Z) * 100.0);
		}
	}
	else
	{
		GetPlayerVelocity(playerid, SAMP_AC_SPEED_X, SAMP_AC_SPEED_Y, SAMP_AC_SPEED_Z);
	    SAMP_AC_SPEED = floatround(VectorSize(SAMP_AC_SPEED_X, SAMP_AC_SPEED_Y, SAMP_AC_SPEED_Z) * 100.0);
    }
	return SAMP_AC_SPEED;
}