public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	if(!(0 <= paintjobid <= 2))
	{
		SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Paintjob Crasher", 92, 0);
	}
#if defined SAMP_AC_OnVehiclePaintjob
    return SAMP_AC_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
#else
	return true;
#endif
}
#if defined _ALS_OnVehiclePaintjob
	#undef    OnVehiclePaintjob
#else
	#define    _ALS_OnVehiclePaintjob
#endif
#define    OnVehiclePaintjob    SAMP_AC_OnVehiclePaintjob
#if defined SAMP_AC_OnVehiclePaintjob
forward SAMP_AC_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
#endif 