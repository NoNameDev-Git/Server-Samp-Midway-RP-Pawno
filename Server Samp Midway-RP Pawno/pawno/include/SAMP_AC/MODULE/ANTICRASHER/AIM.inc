if(AIM_INFO[playerid][AIM_Z] != AIM_INFO[playerid][AIM_Z])
{
	#if defined OnGuardWarningCheater
		OnGuardWarningCheater(playerid, "Aim Crasher", 202);
	#else 
		return OnGuardWarningCheater(playerid, "Aim Crasher", 202);
	#endif
}