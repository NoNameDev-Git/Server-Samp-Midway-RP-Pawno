#if defined _ac_included
	#endinput
#endif
#define _ac_included

#define SAMP_AC_STATE_DAMAGE                                                    true

#include																		a_samp
#include                                                                        pawn_raknet
#include                                                                        rakcheat
#include                                                                        nex-ac
#include                                                                        SAMP_AC/CUSTOM_FUNC/SAMP_AC_CONTROL_SYSTEM

enum E_DAMAGE_SYSTEM
{
	DAMAGE_REASON,      //Причина
	DAMAGE_KILLER,      //Убийца
	DAMAGE_IMPACT,		//Коллизия
	DAMAGE_REPORT,      //Выстрел
	DAMAGE_FIX_HP,      //Для обработки
	DAMAGE_DEATH,       //Фиксация смерти
	DAMAGE_TIMER,       //Для таймера
	
Float: DAMAGE_HEALTH,
Float: DAMAGE_ARMOUR,
}
new DAMAGE_INFO[MAX_PLAYERS][E_DAMAGE_SYSTEM];

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
	
	DAMAGE_INFO[playerid][DAMAGE_REASON] = DAMAGE_INFO[playerid][DAMAGE_KILLER] = 0xFFFF;
	DAMAGE_INFO[playerid][DAMAGE_IMPACT] = DAMAGE_INFO[playerid][DAMAGE_REPORT] = 0xFFFF;
 	DAMAGE_INFO[playerid][DAMAGE_FIX_HP] = 5;
	DAMAGE_INFO[playerid][DAMAGE_HEALTH] = 100.0;
	DAMAGE_INFO[playerid][DAMAGE_ARMOUR] = 0.0;

	DAMAGE_INFO[playerid][DAMAGE_DEATH] =
	DAMAGE_INFO[playerid][DAMAGE_TIMER] = 0;
	
	SERVER_INFO[playerid][SAMP_FIX_SPEED] = 0;
	SERVER_INFO[playerid][SAMP_FIX_TELEPORT] = 0.0;
	
	SetPlayerTeam(playerid, NO_TEAM);
	
	SERVER_INFO[playerid][SAMP_TIMER] = SetTimerEx("SAMP_AC_SECOND_TIMER", 1000, true, "i", playerid);
    #if defined ac_OnPlayerConnect
         return ac_OnPlayerConnect(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect ac_OnPlayerConnect
#if defined ac_OnPlayerConnect
	forward ac_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	KillTimer(SERVER_INFO[playerid][SAMP_TIMER]);
    #if defined ac_OnPlayerDisconnect
         return ac_OnPlayerDisconnect(playerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect ac_OnPlayerDisconnect
#if defined ac_OnPlayerDisconnect
	forward ac_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{
    DAMAGE_INFO[playerid][DAMAGE_KILLER] = DAMAGE_INFO[playerid][DAMAGE_REASON] = 0xFFFF;
	DAMAGE_INFO[playerid][DAMAGE_IMPACT] = DAMAGE_INFO[playerid][DAMAGE_REPORT] = 0xFFFF;
	DAMAGE_INFO[playerid][DAMAGE_HEALTH] = DAMAGE_INFO[playerid][DAMAGE_ARMOUR] = 0;
	DAMAGE_INFO[playerid][DAMAGE_DEATH]  = DAMAGE_INFO[playerid][DAMAGE_TIMER] = 0;

	SERVER_INFO[playerid][SAMP_FIX_BRAKE] = SERVER_INFO[playerid][SAMP_TICK] + 3000;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = SERVER_INFO[playerid][SAMP_TICK];
	SERVER_INFO[playerid][SAMP_USE_SPAWN] = 1;
	
    ResetPlayerWeapons(playerid);
    #if defined ac_OnPlayerDeath
         return ac_OnPlayerDeath(playerid, killerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath ac_OnPlayerDeath
#if defined ac_OnPlayerDeath
	forward ac_OnPlayerDeath(playerid, killerid, reason);
#endif

forward SAMP_AC_PLAYER_DEATH(playerid, killerid, reason);
public SAMP_AC_PLAYER_DEATH(playerid, killerid, reason)
{
	DAMAGE_INFO[playerid][DAMAGE_KILLER] = DAMAGE_INFO[playerid][DAMAGE_REASON] = 0xFFFF;
	DAMAGE_INFO[playerid][DAMAGE_IMPACT] = DAMAGE_INFO[playerid][DAMAGE_REPORT] = 0xFFFF;
	DAMAGE_INFO[playerid][DAMAGE_HEALTH] = DAMAGE_INFO[playerid][DAMAGE_ARMOUR] = 0;
	DAMAGE_INFO[playerid][DAMAGE_DEATH]  = DAMAGE_INFO[playerid][DAMAGE_TIMER] = 0;
	
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
    #if defined ac_OnPlayerEnterVehicle
         return ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle ac_OnPlayerEnterVehicle
#if defined ac_OnPlayerEnterVehicle
	forward ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
#endif

public OnPlayerRequestSpawn(playerid)
{
	SERVER_INFO[playerid][SAMP_USE_SPAWN] = 1;
	SERVER_INFO[playerid][SAMP_GTC_SPAWN] = 0;
    #if defined ac_OnPlayerRequestSpawn
         return ac_OnPlayerRequestSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerRequestSpawn
	#undef OnPlayerRequestSpawn
#else
	#define _ALS_OnPlayerRequestSpawn
#endif
#define OnPlayerRequestSpawn ac_OnPlayerRequestSpawn
#if defined ac_OnPlayerRequestSpawn
	forward ac_OnPlayerRequestSpawn(playerid);
#endif

forward SAMP_AC_SEND_WARNING_FOR_SCRIPT(USERID, const SAC_NAME[], SAC_CODE, SAC_WARNING);
public SAMP_AC_SEND_WARNING_FOR_SCRIPT(USERID, const SAC_NAME[], SAC_CODE, SAC_WARNING)
{

    if(++ SAC_WARNING_PROGRESSIVE[USERID][SAC_CODE] > SAC_WARNING)
    {
        if(SAC_CODE == 1 || SAC_CODE == 50) return true;
        
        
		new string[128];
		format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", SAC_CODE);
		SendClientMessage(USERID, -1, string);
		J_Kick(USERID);
		
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
#include                                                                        SAMP_AC/MODULE/ANTICHEAT/DAMAGE_HELPER
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
    #if defined ac_OnPlayerStateChange
         return ac_OnPlayerStateChange(playerid, newstate, oldstate);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange ac_OnPlayerStateChange
#if defined ac_OnPlayerStateChange
	forward ac_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

public OnPlayerUpdate(playerid)
{
	SERVER_INFO[playerid][SAMP_TICK] = GetTickCount();
    if(DAMAGE_INFO[playerid][DAMAGE_FIX_HP] > 0) DAMAGE_INFO[playerid][DAMAGE_FIX_HP]--;
    #if defined ac_OnPlayerUpdate
         return ac_OnPlayerUpdate(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate ac_OnPlayerUpdate
#if defined ac_OnPlayerUpdate
	forward ac_OnPlayerUpdate(playerid);
#endif

public OnPlayerSpawn(playerid)
{
	SERVER_INFO[playerid][SAMP_USE_WEAPON] = 1;
    DAMAGE_INFO[playerid][DAMAGE_HEALTH] = 100.0;
    if(SERVER_INFO[playerid][SAMP_FIX_POSITION] == 1)
    {
        SERVER_INFO[playerid][SAMP_FUNC][0] = 1;
		SERVER_INFO[playerid][SAMP_WARN][0] = 1;
		SERVER_INFO[playerid][SAMP_FIX_POSITION] = 0;
    }
    SetPlayerPos(playerid, 0.0, 0.0, 12.0);//Закоментить
    #if defined ac_OnPlayerSpawn
         return ac_OnPlayerSpawn(playerid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn ac_OnPlayerSpawn
#if defined ac_OnPlayerSpawn
	forward ac_OnPlayerSpawn(playerid);
#endif

public OnRakcheatFilteredData(playerid, sync, type, subtype)
{
	new string[128];
	format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", 50+type);
	SendClientMessage(playerid, -1, string);
	J_Kick(playerid);
	return 1;
}

forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	new string[128];
	format(string, sizeof(string), "Вы были кикнуты по подозрению в читерстве [№%d]", 100+code);
	SendClientMessage(playerid, -1, string);
	J_Kick(playerid);
	return 1;
}
