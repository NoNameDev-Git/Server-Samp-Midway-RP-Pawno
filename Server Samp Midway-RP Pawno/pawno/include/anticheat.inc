#if defined _dac_included
	#endinput
#endif
#define _dac_included

#define SAMP_AC_STATE_DAMAGE                                                    false

#include <pawn_raknet>
#include <nex-ac>
//#include <rakcheat>
#include <SAMP_AC/CUSTOM_FUNC/SAMP_AC_CONTROL_SYSTEM>


enum E_SAMP_AC_INFO
{
	SAMP_FUNC[100],
	SAMP_LAGG[100],
	SAMP_WARN[100],
	SAMP_FIX_WORLD,

	SAMP_TIMER,
	SAMP_TICK,
	SAMP_PING,


	SAMP_USE_SPAWN,
	SAMP_GTC_SPAWN,
	SAMP_FIX_SPAWN,
	SAMP_FIX_POSITION,


	SAMP_FIX_BRAKE,
	SAMP_FIX_SPEED,
	SAMP_LAST_SPEED,

	SAMP_USE_WEAPON,
	SAMP_SET_WEAPON,
	SAMP_GTC_WEAPON,
	SAMP_USE_REPORT,

	SAMP_ID_VEHICLE,
	SAMP_SET_VEHICLE,
	SAMP_USE_VEHICLE,
	SAMP_GTC_VEHICLE,
	SAMP_ID_SEAT,


	SAMP_WEAPON[13],
	SAMP_AMMOUT[13],
	SAMP_TIC_WEAPON,
	SAMP_FIX_WEAPON,

Float:	SAMP_POS_X,
Float:	SAMP_POS_Y,
Float:  SAMP_POS_Z,

Float:  SAMP_POS_SX,
Float:  SAMP_POS_SY,
Float:  SAMP_POS_SZ,

Float:  SAMP_SPEED_X,
Float:  SAMP_SPEED_Y,
Float:  SAMP_SPEED_Z,

Float: 	SAMP_FIX_TELEPORT,

}
new SERVER_INFO[MAX_PLAYERS][E_SAMP_AC_INFO];



new SAMP_AC_WEAPON_SLOT[47] =
{
	0, 0,
	1, 1, 1, 1, 1, 1, 1, 1,
	10, 10, 10, 10, 10, 10,
	8, 8, 8,
	0, 0, 0,
	2, 2, 2,
	3, 3, 3,
	4, 4,
	5, 5,
	4,
	6, 6,
	7, 7, 7, 7,
	8,
	12,
	9, 9, 9,
	11, 11, 11
};

new WEAPON_FIX_WARNING[3][13];
new SAMP_AC_VEHICLE_SPEED[MAX_VEHICLES];
new Float: SAMP_AC_VEHICLE_POSITION[MAX_VEHICLES];
new SAC_WARNING_PROGRESSIVE[MAX_PLAYERS][100];

#include                                                                        SAMP_AC/HOOK_RAKNET/SAMP_AC_RAKNET_SYNC


public OnPlayerConnect(playerid)
{

	for(new i = 99; i >= 0; i --)
	{
	    SERVER_INFO[playerid][SAMP_FUNC][i] = 1;
	    SERVER_INFO[playerid][SAMP_LAGG][i] = 1;
	    SERVER_INFO[playerid][SAMP_WARN][i] = 1;
	}
	for(new i = 12; i >= 0; i --)
	{
	    SERVER_INFO[playerid][SAMP_WEAPON][i] = 0;
	    SERVER_INFO[playerid][SAMP_AMMOUT][i] = 0;
 		WEAPON_FIX_WARNING[0][i] = 0;
 	 	WEAPON_FIX_WARNING[1][i] = 0;
 		WEAPON_FIX_WARNING[2][i] = 0;
	}
	SERVER_INFO[playerid][SAMP_USE_WEAPON] = 1;

	SERVER_INFO[playerid][SAMP_FIX_WORLD] =
	SERVER_INFO[playerid][SAMP_SET_WEAPON] =
	SERVER_INFO[playerid][SAMP_USE_SPAWN] = 0;


	SERVER_INFO[playerid][SAMP_FIX_SPEED] = 0;
	SERVER_INFO[playerid][SAMP_FIX_TELEPORT] = 0.0;

	SetPlayerTeam(playerid, NO_TEAM);

	SERVER_INFO[playerid][SAMP_TIMER] = SetTimerEx("SAMP_AC_SECOND_TIMER", 1000, true, "i", playerid);
    #if defined bac_OnPlayerConnect
         return bac_OnPlayerConnect(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect bac_OnPlayerConnect
#if defined bac_OnPlayerConnect
	forward bac_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	KillTimer(SERVER_INFO[playerid][SAMP_TIMER]);
    #if defined bac_OnPlayerDisconnect
         return bac_OnPlayerDisconnect(playerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect bac_OnPlayerDisconnect
#if defined bac_OnPlayerDisconnect
	forward bac_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{


	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 3000;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = SERVER_INFO[playerid][SAMP_TICK];
	SERVER_INFO[playerid][SAMP_USE_SPAWN] = 1;

    ResetPlayerWeapons(playerid);
    #if defined bac_OnPlayerDeath
         return bac_OnPlayerDeath(playerid, killerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath bac_OnPlayerDeath
#if defined bac_OnPlayerDeath
	forward bac_OnPlayerDeath(playerid, killerid, reason);
#endif

forward SAMP_AC_PLAYER_DEATH(playerid, killerid, reason);
public SAMP_AC_PLAYER_DEATH(playerid, killerid, reason)
{
	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 3000;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = SERVER_INFO[playerid][SAMP_TICK] + 3000;
	SERVER_INFO[playerid][SAMP_FIX_SPAWN] = 1;


    SetPlayerHealth(playerid, 100.0);
	ResetPlayerWeapons(playerid);
	SpawnPlayer(playerid);
	return true;
}

forward SAMP_AC_SECOND_TIMER(playerid);
public SAMP_AC_SECOND_TIMER(playerid)
{
	SERVER_INFO[playerid][SAMP_PING] = GetPlayerPing(playerid);
	return true;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    new
		SAMP_AC_IGN,
		SAMP_AC_USE;

    GetVehicleParamsEx(vehicleid, SAMP_AC_IGN, SAMP_AC_IGN, SAMP_AC_IGN,
								  SAMP_AC_USE,
								  SAMP_AC_IGN, SAMP_AC_IGN, SAMP_AC_IGN);

	if(ispassenger || SAMP_AC_USE != VEHICLE_PARAMS_ON)
    {
        SERVER_INFO[playerid][SAMP_USE_VEHICLE] = vehicleid;
        SERVER_INFO[playerid][SAMP_GTC_VEHICLE] = SERVER_INFO[playerid][SAMP_TICK];
    }
    #if defined bac_OnPlayerEnterVehicle
         return bac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle bac_OnPlayerEnterVehicle
#if defined bac_OnPlayerEnterVehicle
	forward bac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerRequestSpawn(playerid)
{
	SERVER_INFO[playerid][SAMP_USE_SPAWN] = 1;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = 0;
    #if defined bac_OnPlayerRequestSpawn
         return bac_OnPlayerRequestSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerRequestSpawn
	#undef OnPlayerRequestSpawn
#else
	#define _ALS_OnPlayerRequestSpawn
#endif
#define OnPlayerRequestSpawn bac_OnPlayerRequestSpawn
#if defined bac_OnPlayerRequestSpawn
	forward bac_OnPlayerRequestSpawn(playerid);
#endif

forward SAMP_AC_SEND_WARNING_FOR_SCRIPT(USERID, const SAC_NAME[], SAC_CODE, SAC_WARNING);
public SAMP_AC_SEND_WARNING_FOR_SCRIPT(USERID, const SAC_NAME[], SAC_CODE, SAC_WARNING)
{

    if(++ SAC_WARNING_PROGRESSIVE[USERID][SAC_CODE] > SAC_WARNING)
    {
        if(SAC_CODE == 1 || SAC_CODE == 50) return true;

		if(SAC_CODE == 11 || SAC_CODE == 13 || SAC_CODE == 2 || SAC_CODE == 19 || SAC_CODE == 65 || SAC_CODE == 21 || SAC_CODE == 14 || SAC_CODE == 4 || SAC_CODE == 53 || SAC_CODE == 59)
		    return 1;
	    
		if(SAC_CODE == 7)
		{
		    if(pTemp[USERID][pCheatWarning] < 5)
		    {
			    pTemp[USERID][pCheatWarning]++;
			    pTemp[USERID][pCheatTime] = gettime() + 30;
		    	AddCheater(0, USERID);
		    	return 1;
		    }
		}
        
		if(SAC_CODE == 4 && pTemp[USERID][pAntiAir])
		    return true;
		    
		if(gAntiCheatOff[SAC_CODE-1] == true)
		    return 1;

		if(gOffAntiCheat)
		    return 1;

		if(PI[USERID][pAdmin] >= 3)
		    return 1;
	    
		new string[128];
		format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", SAC_CODE);
		SendClientMessage(USERID, 0xFF7F49FF, string);
		printf("[AC] Kick %d, code %d", USERID, SAC_CODE);
		SendAntiCheatLog(USERID, SAC_CODE);
		_ResetGun(USERID);
		if(!gDebAntiCheat) J_Kick(USERID);

  		CallRemoteFunction("SAMP_AC_SEND_WARNING_FOR_MODE","isdd", USERID, SAC_NAME, SAC_CODE, CENTER_CONTROLE[SAC_CODE][CONTROL_DOOM]);
	}
	SetTimerEx("SAMP_AC_UPDATE_WARNING", 800, false, "ii", USERID, SAC_CODE);
	return true;
}

forward SAMP_AC_UPDATE_WARNING(USERID, SAC_CODE);
public SAMP_AC_UPDATE_WARNING(USERID, SAC_CODE)
{
	if(SAC_WARNING_PROGRESSIVE[USERID][SAC_CODE] > 0)
	{
	    SAC_WARNING_PROGRESSIVE[USERID][SAC_CODE] -= 1;
	}
	return true;
}
//============================== [ HOOK PACKET ] ===============================
#include                                                                        SAMP_AC/HOOK_RAKNET/PARCEL/HOOK_ONFOOT
#include                                                                        SAMP_AC/HOOK_RAKNET/PARCEL/HOOK_BULLET
#include                                                                        SAMP_AC/HOOK_RAKNET/PARCEL/HOOK_VEHICLE
#include                                                                        SAMP_AC/HOOK_RAKNET/PARCEL/HOOK_PASSENGER
//=============================== [ HOOK RPC ] =================================
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_SPAWN
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_POSITION
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_SPECTATE
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_SET_HEALTH
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_SET_ARMOUR
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_POSITION_Z
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_REMOVE_VEHICLE
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_PUT_VEHICLE
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_ARMED_WEAPON
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_VEHICLE_POSITION
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_VEHICLE_SPEED
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_ANIMATION
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_ACTION
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_WORLD

#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_GIVE_WEAPON
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_SET_AMMO
#include                                                                        SAMP_AC/HOOK_RAKNET/RPC/HOOK_RESET_WEAPON
//============================== [ ANTICHEATS ] ================================
#include                                                                        SAMP_AC/MODULE/ANTICHEAT/FAST_SPAWN
//#include                                                                        SAMP_AC/MODULE/ANTICHEAT/DAMAGE_HELPER
#include                                                                        SAMP_AC/MODULE/ANTICHEAT/TELEPORT_CAR_TO_PLAYER
//============================= [ ANTICRASHER ] ================================
#include                                                                        SAMP_AC/MODULE/ANTICRASHER/PAINTJOB
#include                                                                        SAMP_AC/MODULE/ANTICRASHER/LOADING
//============================= [ COSTUM FUNC ] ================================
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CHECK_BOAT
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CHECK_MOTO
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CHECK_SPEED
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CHECK_PLANE
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CHECK_VEHICLE
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_DAMAGE_SYSTEM
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
  	{
  	    SERVER_INFO[playerid][SAMP_ID_VEHICLE] = 0;
		SERVER_INFO[playerid][SAMP_FUNC][1] =
		SERVER_INFO[playerid][SAMP_WARN][1] = 1;
	}
	if(newstate == PLAYER_STATE_ONFOOT)
	{
	    SERVER_INFO[playerid][SAMP_FUNC][1] =
		SERVER_INFO[playerid][SAMP_WARN][1] = 1;
	    SERVER_INFO[playerid][SAMP_ID_VEHICLE] =
		SERVER_INFO[playerid][SAMP_USE_VEHICLE] = 0;
	}
    #if defined bac_OnPlayerStateChange
         return bac_OnPlayerStateChange(playerid, newstate, oldstate);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange bac_OnPlayerStateChange
#if defined bac_OnPlayerStateChange
	forward bac_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

public OnPlayerUpdate(playerid)
{
	SERVER_INFO[playerid][SAMP_TICK] = GetTickCount();
    #if defined bac_OnPlayerUpdate
         return bac_OnPlayerUpdate(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate bac_OnPlayerUpdate
#if defined bac_OnPlayerUpdate
	forward bac_OnPlayerUpdate(playerid);
#endif

public OnPlayerSpawn(playerid)
{
	SERVER_INFO[playerid][SAMP_USE_WEAPON] = 1;
    if(SERVER_INFO[playerid][SAMP_FIX_POSITION] == 1)
    {
        SERVER_INFO[playerid][SAMP_FUNC][0] = 1;
		SERVER_INFO[playerid][SAMP_WARN][0] = 1;
		SERVER_INFO[playerid][SAMP_FIX_POSITION] = 0;
    }
    #if defined bac_OnPlayerSpawn
         return bac_OnPlayerSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn bac_OnPlayerSpawn
#if defined bac_OnPlayerSpawn
	forward bac_OnPlayerSpawn(playerid);
#endif


forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	if(code == 17 && PI[playerid][pAdmin])
 		return 1;

	if(code == 49 || code == 10 || code == 32 || code == 0 || code == 11 || code == 52 || code == 39 || code == 21 || code == 26 || code == 29)
	    return 1;
 		
	if(PI[playerid][pAdmin] >= 3)
	    return 1;

	new string[128];
	
	if(code == 5 || code == 4 || code == 11 || code == 32 || code == 2 || code == 38 || code == 12 || code == 13 || code == 14 || code == 1 || code == 2)
	{
	    if(pTemp[playerid][pCheatWarning] < 5)
	    {
		    pTemp[playerid][pCheatWarning]++;
		    pTemp[playerid][pCheatTime] = gettime() + 30;
	    	AddRedCheater(playerid);
	    	return 1;
	    }
	}
	
	if(gAntiCheatOff[(100+code)-1] == true)
	    return 1;
	    
	if(gOffAntiCheat)
	    return 1;
	
	if(code != 52)
		format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", 100+code);

	else
	    format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", 100+type+code);

	SendClientMessage(playerid, 0xFF7F49FF, string);
	SendAntiCheatLog(playerid, 100+code);
	
	_ResetGun(playerid);
	if(!gDebAntiCheat) J_Kick(playerid);
	return 1;
}
