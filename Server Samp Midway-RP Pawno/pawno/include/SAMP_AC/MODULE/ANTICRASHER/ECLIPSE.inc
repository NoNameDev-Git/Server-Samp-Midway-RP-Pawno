				if(hittype == BULLET_HIT_TYPE_PLAYER)
				{
					if(fX == -0.009999 && fY == -0.019999 && fZ == 0.039999)
					{
						SAMP_AC_SEND_WARNING_FOR_SCRIPT(playerid, "Eclipse Crasher", 96, 0);
						return false;
					}
				}