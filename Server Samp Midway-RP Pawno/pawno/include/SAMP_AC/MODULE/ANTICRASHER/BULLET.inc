				if(hittype == BULLET_HIT_TYPE_PLAYER)
				{
					if((floatcmp(floatabs(fX), 20.0) == 1) || (floatcmp(floatabs(fY), 20.0) == 1) || (floatcmp(floatabs(fZ), 20.0) == 1))
					{
						SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Bullet Crasher", 95, 0);
						return false;
					}
				}