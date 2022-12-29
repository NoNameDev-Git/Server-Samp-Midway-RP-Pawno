#if defined _st_included
	#endinput
#endif
#define _st_included

#include <FCNPC>
#include <MapAndreas>

public OnGameModeInit()
{
	for (new i = 0; i < 500; i++) {
		SetTimer("@__CreateNPC", 3000 * i + random(10000), 0);
	}

    #if defined st_OnGameModeInit
         return st_OnGameModeInit();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit st_OnGameModeInit
#if defined st_OnGameModeInit
	forward st_OnGameModeInit();
#endif

static const
    letters[26][] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

@__CreateNPC();
@__CreateNPC()
{
	new name[MAX_PLAYER_NAME + 1];
	format(name, sizeof(name), "St_test_%s%s%s", letters[random(sizeof(letters))], letters[random(sizeof(letters))], letters[random(sizeof(letters))]);

	new npcid = FCNPC_Create(name);
	
	FCNPC_Spawn(npcid, 0, 1529.7676, -1592.6244, 13.3906);
	FCNPC_GoTo(npcid, 1212.0024, -1718.7108, 13.5469, FCNPC_MOVE_TYPE_WALK);
	
}

public FCNPC_OnSpawn(npcid)
{
	return 1;
}

public FCNPC_OnReachDestination(npcid)
{
	return 1;
}

