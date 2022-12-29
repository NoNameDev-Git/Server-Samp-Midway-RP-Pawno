public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z) 
{
	if(GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z) > 50) return 0;
	
#if defined LOAD_OnUnoccupiedVehicleUpdate
    return LOAD_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#else
	return true;
#endif
}
#if defined _ALS_OnUnoccupiedVehicleUpdate
    #undef    OnUnoccupiedVehicleUpdate
#else
    #define    _ALS_OnUnoccupiedVehicleUpdate
#endif
#define    OnUnoccupiedVehicleUpdate    LOAD_OnUnoccupiedVehicleUpdate
#if defined LOAD_OnUnoccupiedVehicleUpdate
forward LOAD_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#endif