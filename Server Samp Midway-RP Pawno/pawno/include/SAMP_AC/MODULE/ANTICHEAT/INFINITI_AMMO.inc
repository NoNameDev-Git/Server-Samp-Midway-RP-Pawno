		if(CENTER_CONTROLE[18][CONTROL_STATE] == 1)
		{
			if(SERVER_INFO[playerid][SAMP_TICK] > SERVER_INFO[playerid][SAMP_TIC_WEAPON] + SERVER_INFO[playerid][SAMP_PING] && SAMP_AC_REAL_WEAPON != WEAPON_PARACHUTE)
			{
				switch(SAMP_AC_REAL_WEAPON)
				{
					case 0..15, 40, 44..46: return 0x1;
					default:
					{
						if(SERVER_INFO[playerid][SAMP_AMMOUT][SAMP_AC_REAL_WEAPON_SLOT] < 0 && SAMP_AC_REAL_AMMOUT > 0 || SAMP_AC_REAL_AMMOUT < 0 || SAMP_AC_REAL_AMMOUT - SERVER_INFO[playerid][SAMP_AMMOUT][SAMP_AC_REAL_WEAPON_SLOT] > 3)
						{
							if(++ WEAPON_FIX_WARNING[2][SAMP_AC_REAL_WEAPON_SLOT] > 2)
							{
								SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Infinite Ammo", 18, 0);
							}
						}
						else WEAPON_FIX_WARNING[2][SAMP_AC_REAL_WEAPON_SLOT] = 0;
					}
				}
			}
		}
