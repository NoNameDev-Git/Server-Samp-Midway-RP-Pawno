public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
{
	if(passenger_seat > 0)
	{
		new Float: SAMP_AC_FLOAT_SPEED = floatsqroot(floatadd(floatadd(floatpower(vel_x, 2), floatpower(vel_y, 2)), floatpower(vel_z, 2))) * 100.3;
		new SAMP_AC_INT_SPEED = floatround(SAMP_AC_FLOAT_SPEED, floatround_floor);
		if(SAMP_AC_INT_SPEED - SAMP_AC_VEHICLE_SPEED[vehicleid] > 40)
		{
			RemovePlayerFromVehicle(playerid);
			SetPlayerPos(playerid, SERVER_INFO[playerid][SAMP_POS_X], SERVER_INFO[playerid][SAMP_POS_Y], SERVER_INFO[playerid][SAMP_POS_Z] + 2.5);
			ApplyAnimation(playerid, "ped", "BIKE_fallR", 4.0, 0, 1, 0, 0, 0,0);
			return false;
		}
		SAMP_AC_VEHICLE_SPEED[vehicleid] = SAMP_AC_INT_SPEED;
	}
	else 
	{
		new
			Float: SAMP_AC_POS_VX, Float: SAMP_AC_POS_VZ,
			Float: SAMP_AC_POS_VY, Float: SAMP_AC_POS_VR;

		new Float: SAMP_AC_DISTANCE = GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z);

		GetVehiclePos(vehicleid, SAMP_AC_POS_VX, SAMP_AC_POS_VY, SAMP_AC_POS_VZ);
		GetVehicleZAngle(vehicleid, SAMP_AC_POS_VR);

		if(SAMP_AC_DISTANCE > 15.0 && SAMP_AC_POS_VZ > -70.0 && SAMP_AC_DISTANCE > SAMP_AC_VEHICLE_POSITION[vehicleid] + ((SAMP_AC_DISTANCE / 3) * 1.6))
		{
			SetVehiclePos(vehicleid, SAMP_AC_POS_VX, SAMP_AC_POS_VY, SAMP_AC_POS_VZ);
			SetVehicleZAngle(vehicleid, SAMP_AC_POS_VR);
			return false;
		}
		SAMP_AC_VEHICLE_POSITION[vehicleid] = SAMP_AC_DISTANCE;
	}
#if defined SAC_OnUnoccupiedVehicleUpdate
    return SAC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#else
	return true;
#endif
}
#if defined _ALS_OnUnoccupiedVehicleUpdate
    #undef    OnUnoccupiedVehicleUpdate
#else
    #define    _ALS_OnUnoccupiedVehicleUpdate
#endif
#define    OnUnoccupiedVehicleUpdate    SAC_OnUnoccupiedVehicleUpdate
#if defined SAC_OnUnoccupiedVehicleUpdate
forward SAC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#endif
