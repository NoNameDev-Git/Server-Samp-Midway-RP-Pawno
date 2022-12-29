	if(CENTER_CONTROLE[19][CONTROL_STATE] == 1)
	{
		new SAMP_AC_OBJECT = GetPlayerSurfingObjectID(playerid);
		if(SAMP_AC_OBJECT > 0x0 && SAMP_AC_OBJECT != 0xFFFF && IsValidObject(SAMP_AC_OBJECT))
		{
			new Float: SAMP_AC_X, Float: SAMP_AC_Y, Float: SAMP_AC_Z;
			GetObjectPos(SAMP_AC_OBJECT, SAMP_AC_X, SAMP_AC_Y, SAMP_AC_Z);
			if(!IsPlayerInRangeOfPoint(playerid, 50.0, SAMP_AC_X, SAMP_AC_Y, SAMP_AC_Z))
			{
				SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Invisible Vehicle", 19, 0);
			}
		}
	}