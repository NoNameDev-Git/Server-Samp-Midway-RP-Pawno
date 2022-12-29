#if defined _br_included
	#endinput
#endif
#define _br_included

//#include <mapandreas>
#include <GZ_CirclesALS>
#include <c_object>
#include <SpawnAircraft>
//#include <FCNPC>


new
	gCenterJoin,
	gCenterExit,
	bool:PlayerInPlane[MAX_PLAYERS],
	bool:PlayerInGame[MAX_PLAYERS];

	
enum MATCH_INFO {
	mTimer,
	mStatus,
	mPlayers,
	mObject,
	mCircle
};
new gBattleRoyale[MATCH_INFO];

public OnGameModeInit()
{
    gCenterJoin = CreateDynamicSphere(1772.8782, -1655.2922, 14.4277, 2.0, 0, 0);
    CreateDynamicPickup(1318, 23, 1772.8782, -1655.2922, 14.4277, 0, 0);
    CreateDynamic3DTextLabel("Центр развлечений", 0xFFFFFFAA, 1772.8782, -1655.2922, 14.4277, 20.0);
    CreateDynamicMapIcon(1772.8782, -1655.2922, 14.4277, 53, -1, 0, 0);
    
    gCenterExit = CreateDynamicSphere(834.6666, 7.4341, 1004.1870, 2.0, 19, 3);
    CreateDynamicPickup(1318, 23, 834.6666, 7.4341, 1004.1870, 19, 3);

    #if defined br_OnGameModeInit
         return br_OnGameModeInit();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit br_OnGameModeInit
#if defined br_OnGameModeInit
	forward br_OnGameModeInit();
#endif


public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(areaid == gCenterJoin)
	{
	    if(IsPlayerInAnyVehicle(playerid))
        	return 1;
	
	    J_SetPlayerPos(playerid, 832.5601,7.3767,1004.1797);
		J_SetPlayerFacingAngle(playerid, 95.3257);
	    SetPlayerInterior(playerid, 3);
	    SetPlayerVirtualWorld(playerid, 19);
	}
	else if(areaid == gCenterExit)
	{
	    J_SetPlayerPos(playerid, 1770.7336,-1657.2252,14.4211);
		J_SetPlayerFacingAngle(playerid, 130.3092);
	    SetPlayerInterior(playerid, 0);
	    SetPlayerVirtualWorld(playerid, 0);
	}

    #if defined br_OnPlayerEnterDynamicArea
         return br_OnPlayerEnterDynamicArea(playerid, areaid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterDynamicArea
	#undef OnPlayerEnterDynamicArea
#else
	#define _ALS_OnPlayerEnterDynamicArea
#endif
#define OnPlayerEnterDynamicArea br_OnPlayerEnterDynamicArea
#if defined br_OnPlayerEnterDynamicArea
	forward br_OnPlayerEnterDynamicArea(playerid, areaid);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (newkeys & KEY_SPRINT)
    {
        if(PlayerInGame[playerid])
        {
			if(PlayerInPlane[playerid] && gBattleRoyale[mTimer] < 53)
			{
			    new
					Float:x, Float:y, Float:z;

				GetPlayerCameraLookAt(playerid, x, y, z);
				f_TogglePlayerControllable(playerid, true);
				PlayerInPlane[playerid] = false;
				GivePlayerWeapon(playerid, 46, 1);
				J_SetPlayerPos(playerid, x, y, z - 5.0);
				SetPlayerHealth(playerid, 100);
				SetPlayerSkills(playerid);
				SetPlayerSkinEx(playerid, GetSkinOfPlayer(playerid));
				if(PI[playerid][pFraction])
					SetPlayerColor(playerid,gFractionColor[PI[playerid][pFraction] - 1]);
			}
		}
	}
	
    #if defined br_OnPlayerKeyStateChange
         return br_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange br_OnPlayerKeyStateChange
#if defined br_OnPlayerKeyStateChange
	forward br_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif


public OnPlayerSpawn(playerid)
{
    if(PlayerInGame[playerid])
    {
		if(PlayerInPlane[playerid])
		{
		    new
				Float:x, Float:y, Float:z;
				
			GetPlayerCameraLookAt(playerid, x, y, z);
			f_TogglePlayerControllable(playerid, true);
			PlayerInPlane[playerid] = false;
			GivePlayerWeapon(playerid, 46, 1);
			J_SetPlayerPos(playerid, x, y, z - 5.0);
			SetPlayerHealth(playerid, 100);
			SetPlayerSkills(playerid);
			SetPlayerSkinEx(playerid, GetSkinOfPlayer(playerid));
			if(PI[playerid][pFraction])
				SetPlayerColor(playerid,gFractionColor[PI[playerid][pFraction] - 1]);
			return 1;
		}
	}

    #if defined br_OnPlayerSpawn
         return br_OnPlayerSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn br_OnPlayerSpawn
#if defined br_OnPlayerSpawn
	forward br_OnPlayerSpawn(playerid);
#endif

forward GrandTimer();
public GrandTimer()
{
	if(gBattleRoyale[mStatus] == 1 && gBattleRoyale[mTimer] == 300)
	{
		SendClientMessageToAll(0xED485FFF, !"Уважаемые игроки, через 5 минут пройдет мероприятие {FFFFFF}Королевская битва");
		SendClientMessageToAll(0xED485FFF, !"Для участия отправляйтесь в {FFFFFF}Центр развлечений");
		SendClientMessageToAll(0xED485FFF, !"Максимальное число участников: {FFFFFF}30{ED485F} игроков");
	}
	else if(gBattleRoyale[mStatus] == 1 && gBattleRoyale[mTimer] == 120)
	{
		SendClientMessageToAll(0xED485FFF, !"Уважаемые игроки, через 2 минуты пройдет мероприятие {FFFFFF}Королевская битва");
		SendClientMessageToAll(0xED485FFF, !"Для участия отправляйтесь в {FFFFFF}Центр развлечений");
		SendClientMessageToAll(0xED485FFF, !"Максимальное число участников: {FFFFFF}30{ED485F} игроков");
	}
	else if(gBattleRoyale[mStatus] == 1 && gBattleRoyale[mTimer] == 0)
	{
	    /*if(gBattleRoyale[mPlayers] < 6)
	    {
	        gBattleRoyale[mStatus] = 0;
	        SendClientMessageToAll(0xED485FFF, !"Королевская битва прервана из-за недостаточного количества участников!");
	    }
	    else
	    {*/
		SendClientMessageToAll(0xED485FFF, !"Королевская битва началась!");
		gBattleRoyale[mTimer] = 60;
		gBattleRoyale[mStatus] = 2;
		
		
		/*gBattleRoyale[mPlane] = CreateVehicle(519, 3000.0, 3000.0, 1000, 0, -1, -1, -1);
		SetVehicleVirtualWorld(gBattleRoyale[mPlane], 880);

		gBattleRoyale[mPilot] = FCNPC_Create("pilot");
		FCNPC_Spawn(gBattleRoyale[mPilot], 61, 0, 0, 3);
		FCNPC_SetInterior(gBattleRoyale[mPilot], 0);
		FCNPC_SetVirtualWorld(gBattleRoyale[mPilot], 880);
		FCNPC_PutInVehicle(gBattleRoyale[mPilot], gBattleRoyale[mPlane], 0);
		
		SetVehiclePos(gBattleRoyale[mPlane], 721, 967, 1000);
		//FCNPC_EnterVehicle(gBattleRoyale[mPilot], gBattleRoyale[mPlane], 0);
		FCNPC_GoTo(gBattleRoyale[mPilot], 2648.1501, 2518.9744, 1000, FCNPC_MOVE_TYPE_AUTO, 8.0);*/
		//gBattleRoyale[mObject] = CreateDynamicObject(19300, 840.827209, 710.157409, 800.000000, 0.000000, 0.000000, 0.000000, 880);

        gBattleRoyale[mCircle] = GZ_CircumferenceCreate(840.827209, 710.157409, 1000.0);
        
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
		{
		    if(!IsPlayerNPC(i))
		    {
		        SetPlayerInterior(i, 0);
			    SetPlayerVirtualWorld(i, 880);
				StartAircraft();
				SetPlayerPos(i, 968.7886, 1092.7424, 800.000000);
				//AttachCameraToObject(i, gBattleRoyale[mObject]);
				//SetPlayerCameraPos(i, 958.372131, 1086.297729, 805.793273);
				//SetPlayerCameraLookAt(i, 961.905090, 1089.311645, 803.940124);
				InterpolateCameraPos(i, 958.372131, 1086.297729, 805.793273, 2639.0793, 2648.0237, 805.793273, 50000);
				InterpolateCameraLookAt(i, 961.905090, 1089.311645, 803.940124, 2642.0793, 2652.0237, 803.940124, 50000);
				
				
				//SetTimerEx("@__camerapos", 100, 1, "i", i);
				PlayerInPlane[i] = true;
				PlayerInGame[i] = true;
				ResetPlayerWeapons(i);
				GZ_CircleShowForPlayer(i, gBattleRoyale[mCircle], 0xFFFFFFAA);
			}
		}
		//}
	}
	else if(gBattleRoyale[mStatus] == 2 && gBattleRoyale[mTimer] == 53)
	{
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
		{
		    if(!IsPlayerNPC(i))
		    {
		        if(PlayerInGame[i])
		        {
					if(PlayerInPlane[i])
					{
						GameTextForPlayer(i, "~n~~n~~y~Jump!", 5000, 3);
						SendClientMessage(i, -1, !"{42B02C}[Подсказка] {FFFFFF}Нажмите на клавишу {FFE805}быстрого бега{FFFFFF}, чтобы выпрыгнуть из самолета");
					}
				}
			}
		}
	}
	else if(gBattleRoyale[mStatus] == 2 && gBattleRoyale[mTimer] == 0)
	{
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
		{
		    if(!IsPlayerNPC(i))
		    {
		        if(PlayerInGame[i])
		        {
					if(PlayerInPlane[i])
					{
						f_TogglePlayerControllable(i, true);
						PlayerInPlane[i] = false;
						GivePlayerWeapon(i, 46, 1);
						J_SetPlayerPos(i, 2928.199951, 2649.303710, 802.000000 - 5.0);
						SetPlayerHealth(i, 100);
						SetPlayerSkills(i);
						SetPlayerSkinEx(i, GetSkinOfPlayer(i));
						if(PI[i][pFraction])
							SetPlayerColor(i,gFractionColor[PI[i][pFraction] - 1]);
					}
				}
		    }
		}
	}
	if(gBattleRoyale[mTimer] > 0)
        gBattleRoyale[mTimer]--;

    #if defined br_GrandTimer
         return br_GrandTimer();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_GrandTimer
	#undef GrandTimer
#else
	#define _ALS_GrandTimer
#endif
#define GrandTimer br_GrandTimer
#if defined br_GrandTimer
	forward br_GrandTimer();
#endif

CMD:testbattle(playerid)
{
	SendClientMessageToAll(0xED485FFF, !"Уважаемые игроки, через {FFFFFF}10{ED485F} минут пройдет мероприятие {FFFFFF}Королевская битва");
	SendClientMessageToAll(0xED485FFF, !"Для участия отправляйтесь в {FFFFFF}Центр развлечений");
	SendClientMessageToAll(0xED485FFF, !"Максимальное число участников: {FFFFFF}30{ED485F} игроков");
	gBattleRoyale[mTimer] = 2;
	gBattleRoyale[mStatus] = 1;

	return 1;
}
stock GetPlayerCameraLookAt(playerid, &Float:X, &Float:Y, &Float:Z)
{
    new
        Float:CamX, Float:CamY, Float:CamZ,
        Float:FrX, Float:FrY, Float:FrZ;
        
    GetPlayerCameraPos(playerid, CamX, CamY, CamZ);
    GetPlayerCameraFrontVector(playerid, FrX, FrY, FrZ);
    
    X = FrX + CamX;
    Y = FrY + CamY;
    Z = FrZ + CamZ;
}
stock StartAircraft()
{
    gBattleRoyale[mObject] = CreateObject(1681, 968.7886, 1095.7424, 800.000000, 0.0, 0.0, 313.0);
    MoveObject(gBattleRoyale[mObject], 2649.0793, 2658.0237, 800.000000, 50.00, 0.0, 0.0, 313.0);

    return 1;
}
@__camerapos(playerid);
@__camerapos(playerid)
{
	new
	    Float:CamX, Float:CamY, Float:CamZ;
	    
    GetObjectPos(gBattleRoyale[mObject], CamX, CamY, CamZ);
	    
	//SetPlayerCameraPos(playerid, 958.372131, 1086.297729, 805.793273);
	SetPlayerCameraPos(playerid, CamX-10.0, CamY-10.0, 805.793273);
	SetPlayerCameraLookAt(playerid, CamX-7.0, CamY-6.0, 803.940124);
}
