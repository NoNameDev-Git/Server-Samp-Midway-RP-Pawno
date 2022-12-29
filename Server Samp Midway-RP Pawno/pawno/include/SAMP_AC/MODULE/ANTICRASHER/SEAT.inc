	if(GetPlayerVehicleSeat(playerid) == 0)
	{
		SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Seat Crasher", 94, 0);
		return 0;
	}