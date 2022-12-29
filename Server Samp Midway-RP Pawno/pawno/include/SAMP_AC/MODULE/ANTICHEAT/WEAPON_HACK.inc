	new SAMP_AC_REAL_WEAPON = GetPlayerWeapon(playerid);
	new SAMP_AC_REAL_AMMOUT = GetPlayerAmmo(playerid);

	if(SAMP_AC_REAL_WEAPON != -1 && SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_FIX_WEAPON] + SERVER_INFO[playerid][SAMP_PING])
	{
		new SAMP_AC_REAL_WEAPON_SLOT = SAMP_AC_WEAPON_SLOT[SAMP_AC_REAL_WEAPON];
		if(CENTER_CONTROLE[16][CONTROL_STATE] == 1)
		{
			for(new i = 0; i != 13; i ++)
			{
				new SAMP_AC_CHECK_WEAPON[13], SAMP_AC_CHECK_AMMOUT[13];
				GetPlayerWeaponData(playerid, i, SAMP_AC_CHECK_WEAPON[i], SAMP_AC_CHECK_AMMOUT[i]);
				
				if(SAMP_AC_CHECK_WEAPON[i] > 0 && SAMP_AC_CHECK_WEAPON[i] != WEAPON_PARACHUTE && SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_TIC_WEAPON] + SERVER_INFO[playerid][SAMP_PING])
				{
					if(SAMP_AC_CHECK_WEAPON[i] != SERVER_INFO[playerid][SAMP_WEAPON][i])
					{
						if(++ WEAPON_FIX_WARNING[0][SAMP_AC_REAL_WEAPON_SLOT] > 2)
						{
							SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Weapon Hack", 16, 0);
						}
					}
					else WEAPON_FIX_WARNING[0][SAMP_AC_REAL_WEAPON_SLOT] = 0;
				}
				if(SAMP_AC_CHECK_WEAPON[i] > 0 && SAMP_AC_CHECK_WEAPON[i] != WEAPON_PARACHUTE && SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_TIC_WEAPON] + SERVER_INFO[playerid][SAMP_PING])
				{
					if(SAMP_AC_REAL_WEAPON != SAMP_AC_CHECK_WEAPON[SAMP_AC_REAL_WEAPON_SLOT])
					{
						if(++ WEAPON_FIX_WARNING[0][SAMP_AC_REAL_WEAPON_SLOT] > 2)
						{
							SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Weapon Hack", 16, 0);
						}
					}
					else WEAPON_FIX_WARNING[0][SAMP_AC_REAL_WEAPON_SLOT] = 0;
				}
			}
		}
		#include                                                                        SAMP_AC/MODULE/ANTICHEAT/AMMO_HACK
		#include                                                                        SAMP_AC/MODULE/ANTICHEAT/INFINITI_AMMO
		SERVER_INFO[playerid][SAMP_FIX_WEAPON] = SERVER_INFO[playerid][SAMP_TICK] + 1200;
	}