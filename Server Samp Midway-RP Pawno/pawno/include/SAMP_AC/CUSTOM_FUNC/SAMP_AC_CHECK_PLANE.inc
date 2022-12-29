stock SAMP_AC_CHECK_MODEL_PLANE(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 417, 425, 447, 460, 465, 469, 476, 487, 497, 501, 511..513,
		519, 520, 548, 553, 563, 577, 592, 598, 464, 488: return 1;
	}
	return 0;
}