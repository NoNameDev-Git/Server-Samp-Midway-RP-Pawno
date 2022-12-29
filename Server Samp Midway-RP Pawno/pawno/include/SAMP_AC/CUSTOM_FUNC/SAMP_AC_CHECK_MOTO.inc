stock SAMP_AC_CHECK_MODEL_MOTO(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 448, 461..463, 468, 521..523, 581, 586: return 1;
	}
	return 0;
}