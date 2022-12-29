#if defined _pb_included
	#endinput
#endif
#define _pb_included

enum PAINT_INFO {
	pbTimer,
	pbStatus,
	pbPlayers,
	pbRedTeam,
	pbBlueTeam,
	pbWin
};
new gPaintBall[PAINT_INFO];

stock PaintUpdate(team)
{
	new str_score1[4], str_score2[4];
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
	{
		if(!pTemp[i][pPaintTeam]) continue;
		if(team == 1)
		{
			format(str_score1, sizeof str_score1, "%d", gPaintBall[pbRedTeam]);
			TextDrawSetString(tdPaintBall[5], str_score1);
		}
		else
		{
			format(str_score2, sizeof str_score2, "%d", gPaintBall[pbBlueTeam]);
			TextDrawSetString(tdPaintBall[7], str_score2);
		}
	}
}
public OnPlayerDisconnect(playerid, reason)
{
	if(pTemp[playerid][pRegPaint])
	{
	    gPaintBall[pbPlayers]--;
	    pTemp[playerid][pRegPaint] = false;
	}
	if(pTemp[playerid][pPaintTeam])
	{
	    if(pTemp[playerid][pPaintTeam] == 1)
			gPaintBall[pbRedTeam]--;

		else if(pTemp[playerid][pPaintTeam] == 2)
			gPaintBall[pbBlueTeam]--;

	    PaintUpdate(pTemp[playerid][pPaintTeam]);

	    ResetPlayerWeapons(playerid);
        pTemp[playerid][pPaintTeam] = 0;
        SetPlayerArmour(playerid, 0);
	}

    #if defined pb_OnPlayerDisconnect
         return pb_OnPlayerDisconnect(playerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect pb_OnPlayerDisconnect
#if defined pb_OnPlayerDisconnect
	forward pb_OnPlayerDisconnect(playerid, reason);
#endif


public OnPlayerSpawn(playerid)
{

    #if defined pb_OnPlayerSpawn
         return pb_OnPlayerSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn pb_OnPlayerSpawn
#if defined pb_OnPlayerSpawn
	forward pb_OnPlayerSpawn(playerid);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{
    #if defined pb_OnPlayerDeath
         return pb_OnPlayerDeath(playerid, killerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath pb_OnPlayerDeath
#if defined pb_OnPlayerDeath
	forward pb_OnPlayerDeath(playerid, killerid, reason);
#endif

CMD:spaintball(playerid)
{
	if(PI[playerid][pAdmin] < 7)
	    return 1;

	SendClientMessageToAll(0xED485FFF, !"Уважаемые игроки, через {FFFFFF}10{ED485F} минут пройдет мероприятие {FFFFFF}PaintBall");
	SendClientMessageToAll(0xED485FFF, !"Для участия отправляйтесь в {FFFFFF}Центр развлечений");
	SendClientMessageToAll(0xED485FFF, !"Максимальное число участников: {FFFFFF}30{ED485F} игроков");
	gPaintBall[pbTimer] = 600;
	gPaintBall[pbStatus] = 1;
	return 1;
}
CMD:startpaint(playerid)
{
    gPaintBall[pbTimer] = 5;
}
CMD:pbteam(playerid)
{
	if(pTemp[playerid][pPaintTeam] == 1)
		SendClientMessage(playerid, -1, "красный");
		
	else if(pTemp[playerid][pPaintTeam] == 2)
		SendClientMessage(playerid, -1, "голубой");

	printf("%d %d %d %d %d", gPaintBall[pbStatus], gPaintBall[pbWin], pTemp[playerid][pPaintTeam], gPaintBall[pbBlueTeam], gPaintBall[pbRedTeam]);
}
forward _GiveGunEx(playerid, weaponid, ammo);
public _GiveGunEx(playerid, weaponid, ammo)
{
	new slot = GetWeaponSlot(weaponid);
	if(slot == 0xFFFF) return false;
	gunmute[playerid] = gettime()+3;

    WeaponInfo[playerid][weaponid] = true;
    AmmoSlot[playerid][slot] += ammo;
    AmmoInfo[playerid][weaponid] = AmmoSlot[playerid][slot];

	AntiCheatGetWeaponData(playerid, slot,weaponid, ammo);
	return true;
}
@__paintball();
@__paintball()
{
	SendClientMessageToAll(0xED485FFF, !"Уважаемые игроки, через {FFFFFF}10{ED485F} минут пройдет мероприятие {FFFFFF}PaintBall");
	SendClientMessageToAll(0xED485FFF, !"Для участия отправляйтесь в {FFFFFF}Центр развлечений");
	SendClientMessageToAll(0xED485FFF, !"Максимальное число участников: {FFFFFF}30{ED485F} игроков");
	gPaintBall[pbTimer] = 600;
	gPaintBall[pbStatus] = 1;
}
