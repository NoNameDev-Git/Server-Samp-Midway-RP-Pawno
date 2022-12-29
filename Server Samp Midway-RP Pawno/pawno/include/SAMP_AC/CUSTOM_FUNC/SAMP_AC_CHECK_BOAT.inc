stock SAMP_AC_CHECK_MODEL_BOAT(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 430, 446, 452..454, 472, 473, 484, 493, 595: return 1;
	}
	return 0;
}