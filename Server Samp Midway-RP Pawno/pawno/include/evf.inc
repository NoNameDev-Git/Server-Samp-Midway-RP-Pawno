/********************************
 *   	  	 99.Pawn         	*
 *    "Easy Vehicle Functions"  *
 *     MADE BY (UvH)THIAZ99  	*
 *                              *
 *  Don't delete copyrights or  *
 *  change them to yours!       *
 *                              *
 ********************************/

#include <a_samp>
#include <float>

#define MAX_PVEHICLES 2000

new FALSE = false;
new TRUE = true;
#pragma unused TRUE

#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
#define SendFormattedMessage(%0,%1,%2,%3) do{new _string[128]; format(_string,sizeof(_string),%2,%3); SendClientMessage(%0,%1,_string);} while(FALSE)
#define SendFormattedMessageToAll(%0,%1,%2) do{new _string[128]; format(_string,sizeof(_string),%1,%2); SendClientMessageToAll(%0,_string);} while(FALSE)

#define TZ_RED 		 0xE60000FF

new VehicleNames[212][] = {
	"Landstalker","Bravura","Buffalo","Linerunner","Pereniel","Sentinel","Dumper","Firetruck","Trashmaster","Stretch","Manana","Infernus",
	"Voodoo","Pony","Mule","Cheetah","Ambulance","Leviathan","Moonbeam","Esperanto","Taxi","Washington","Bobcat","Mr Whoopee","BF Injection",
	"Hunter","Premier","Enforcer","Securicar","Banshee","Predator","Bus","Rhino","Barracks","Hotknife","Trailer","Previon","Coach","Cabbie",
	"Stallion","Rumpo","RC Bandit","Romero","Packer","Monster","Admiral","Squalo","Seasparrow","Pizzaboy","Tram","Trailer","Turismo","Speeder",
	"Reefer","Tropic","Flatbed","Yankee","Caddy","Solair","Berkley's RC Van","Skimmer","PCJ-600","Faggio","Freeway","RC Baron","RC Raider",
	"Glendale","Oceanic","Sanchez","Sparrow","Patriot","Quad","Coastguard","Dinghy","Hermes","Sabre","Rustler","ZR3 50","Walton","Regina",
	"Comet","BMX","Burrito","Camper","Marquis","Baggage","Dozer","Maverick","News Chopper","Rancher","FBI Rancher","Virgo","Greenwood",
	"Jetmax","Hotring","Sandking","Blista Compact","Police Maverick","Boxville","Benson","Mesa","RC Goblin","Hotring Racer A","Hotring Racer B",
	"Bloodring Banger","Rancher","Super GT","Elegant","Journey","Bike","Mountain Bike","Beagle","Cropdust","Stunt","Tanker","RoadTrain",
	"Nebula","Majestic","Buccaneer","Shamal","Hydra","FCR-900","NRG-500","HPV1000","Cement Truck","Tow Truck","Fortune","Cadrona","FBI Truck",
	"Willard","Forklift","Tractor","Combine","Feltzer","Remington","Slamvan","Blade","Freight","Streak","Vortex","Vincent","Bullet","Clover",
	"Sadler","Firetruck","Hustler","Intruder","Primo","Cargobob","Tampa","Sunrise","Merit","Utility","Nevada","Yosemite","Windsor","Monster A",
	"Monster B","Uranus","Jester","Sultan","Stratum","Elegy","Raindance","RC Tiger","Flash","Tahoma","Savanna","Bandito","Freight","Trailer",
	"Kart","Mower","Duneride","Sweeper","Broadway","Tornado","AT-400","DFT-30","Huntley","Stafford","BF-400","Newsvan","Tug","Trailer A","Emperor",
	"Wayfarer","Euros","Hotdog","Club","Trailer B","Trailer C","Andromada","Dodo","RC Cam","Launch","Police Car (LSPD)","Police Car (SFPD)",
	"Police Car (LVPD)","Police Ranger","Picador","S.W.A.T. Van","Alpha","Phoenix","Glendale","Sadler","Luggage Trailer A","Luggage Trailer B",
	"Stair Trailer","Boxville","Farm Plow","Utility Trailer"
};

new	ValidVehicles[] = {
	400,401,402,404,405,410,411,412,413,415,418,419,421,422,424,426,429,434,436,439,440,442,445,451,458,459,461,462,463,466,467,468,474,475,477,478,
	479,480,481,482,483,489,491,492,496,498,500,505,506,507,508,509,510,516,517,518,521,522,526,527,529,533,534,535,536,540,541,542,543,545,546,547,
	549,550,551,552,554,555,558,559,560,561,562,565,566,567,568,575,576,579,580,581,585,586,587,589,600,602,603,604,605,609
};

new
	//Private
	VEHICLEOWNER[MAX_VEHICLES][24],
	bool:ISVEHICLEOWNED[MAX_VEHICLES],
	hCAR[MAX_VEHICLES],
	PVC = -1,
	//Random
 	rCAR[MAX_VEHICLES],
 	RVC = -1;

forward AddPrivateVehicle(Owner[], Model, Float:X, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay);
forward AddRandomVehicle(Float:X, Float:Y, Float:Z, Float:A, RespawnDelay);
forward AddVehicleLine(HowMany, Model, Float:X, Float:FirstY, Float:Z, Float:A, Color1, Color2, RespawnDelay);
forward AddVehicleRow(HowMany, Model, Float:FirstX, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay);
forward Indestructible(vehicleid, bool:indestructable);
forward ExplodeVehicle(vehicleid, size);
forward INC_VehicleStateChange(playerid, newstate);
forward INC_VehicleSpawn(vehicleid);
forward LockVehicleForAll(vehicleid, bool:lock);
forward LockVehicleForPlayer(playerid, vehicleid, bool:lock);
forward WarpPlayerToVehicle(playerid, vehicleid);
forward WarpVehicleToPlayer(vehicleid, playerid);
forward LoadEVFVehiclesFromFiles();
/********************************************/
public AddPrivateVehicle(Owner[], Model, Float:X, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
	PVC++;
	format(VEHICLEOWNER[PVC], 24, Owner);
	ISVEHICLEOWNED[PVC] = true;
	hCAR[PVC] = CreateVehicle(Model, X, Y, Z, A, Color1, Color2, RespawnDelay);
	return true;
}

public AddRandomVehicle(Float:X, Float:Y, Float:Z, Float:A) {
	RVC++;
	rCAR[RVC] = CreateVehicle(ValidVehicles[random(sizeof(ValidVehicles))], X, Y, Z, A, -1, -1, 120000);
	return true;
}

public AddVehicleLine(HowMany, Model, Float:X, Float:FirstY, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
	new Float:Dif = FirstY;
	for(new i; i<HowMany; i++) {
	    Dif = Dif+4;
        CreateVehicle(Model, X, Dif, Z, A, Color1, Color2, RespawnDelay);
 	}
 	return true;
}

public AddVehicleRow(HowMany, Model, Float:FirstX, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
	new Float:Dif = FirstX;
	for(new i; i<HowMany; i++) {
	    Dif = Dif+10;
        CreateVehicle(Model, Dif, Y, Z, A, Color1, Color2, RespawnDelay);
 	}
 	return true;
}

public Indestructible(vehicleid, bool:indestructable) {
	if(indestructable == true) {
	    SetVehicleHealth(vehicleid, 999999.9);
	}
	else if(indestructable == false) {
	    SetVehicleHealth(vehicleid, 1000.0);
	}
	return true;
}

public ExplodeVehicle(vehicleid, size) {
	new Float:T[4];
	GetVehiclePos(vehicleid, T[0], T[1], T[2]);
	if(size < 5 || size > -1) {
		switch(size) {
		    case 0: for(new i; i<2; i++) { CreateExplosion(T[0], T[1], T[2], 5, 10); }
		    case 1: for(new i; i<4; i++) { CreateExplosion(T[0], T[1], T[2], 5, 10); }
		    case 2: for(new i; i<6; i++) { CreateExplosion(T[0], T[1], T[2], 5, 10); }
		    case 3: for(new i; i<8; i++) { CreateExplosion(T[0], T[1], T[2], 5, 10); }
		    case 4: for(new i; i<10; i++) { CreateExplosion(T[0], T[1], T[2], 5, 10); }
		}
	}
	return true;
}

public INC_VehicleStateChange(playerid, newstate) {
	new vehicleid = GetPlayerVehicleID(playerid);
	if(newstate == PLAYER_STATE_DRIVER) {
		for(new i; i<MAX_VEHICLES; i++) {
			if(vehicleid == hCAR[i] && strcmp(pRName(playerid), VEHICLEOWNER[i])) {
		    	SendFormattedMessage(playerid, TZ_RED, "This is %s's vehicle, you aren't allowed to enter it as a driver!", VEHICLEOWNER[i]);
		    	RemovePlayerFromVehicle(playerid);
			}
		}
	}
	return true;
}

public INC_VehicleSpawn(vehicleid) {
	for(new i; i<MAX_VEHICLES; i++) {
		if(vehicleid == rCAR[i]) {
		    new Float:T[4];
		    GetVehiclePosEx(vehicleid, T[0], T[1], T[2], T[3]);
		    DestroyVehicle(vehicleid);
		    rCAR[i] = CreateVehicle(ValidVehicles[random(sizeof(ValidVehicles))], T[0], T[1], T[2], T[3], -1, -1, 120000);
		}
	}
	return true;
}

public LockVehicleForPlayer(playerid, vehicleid, bool:lock) {
	if(lock == true) {
		SetVehicleParamsForPlayer(vehicleid, playerid, 0, 1);
	}
	else if(lock == false) {
		SetVehicleParamsForPlayer(vehicleid, playerid, 0, 0);
	}
	return true;
}

public LockVehicleForAll(vehicleid, bool:lock) {
	for(new i; i<MAX_PLAYERS; i++) {
		if(lock == true) {
	    	SetVehicleParamsForPlayer(vehicleid, i, 0, 1);
		}
		else if(lock == false) {
	    	SetVehicleParamsForPlayer(vehicleid, i, 0, 0);
		}
	}
	return true;
}

public WarpPlayerToVehicle(playerid, vehicleid) {
	new Float:p[4];
	GetVehiclePos(vehicleid, p[0], p[1], p[2]);
	GetVehicleZAngle(vehicleid, p[3]);
	SetPlayerPos(playerid, p[0], p[1], p[2]);
	SetPlayerFacingAngle(playerid, p[3]);
	PutPlayerInVehicle(playerid, vehicleid, 0);
}

public WarpVehicleToPlayer(vehicleid, playerid) {
    new Float:p[4];
	GetPlayerPos(playerid, p[0], p[1], p[2]);
	GetPlayerFacingAngle(playerid, p[3]);
	SetVehiclePos(vehicleid, p[0], p[1], p[2]);
	SetVehicleZAngle(vehicleid, p[3]);
	PutPlayerInVehicle(playerid, vehicleid, 0);
}

public LoadEVFVehiclesFromFiles() {
	new str[2048], splits[48][24], File:F = fopen("/EVF/RandomVehicles.txt", io_read);
	if(fexist("/EVF/RandomVehicles.txt")) {
		while(fread(F, str)) {
		    split(str, splits, ',');
		    AddRandomVehicle(floatstr(splits[0]), floatstr(splits[1]), floatstr(splits[2]), floatstr(splits[3]), strval(splits[4]));
		}
	}
	F = fopen("/EVF/PrivateVehicles.txt", io_read);
	if(fexist("/EVF/PrivateVehicles.txt")) {
		while(fread(F, str, 2048)) {
		    split(str, splits, ',');
		    AddPrivateVehicle(splits[0], strval(splits[1]), floatstr(splits[2]), floatstr(splits[3]), floatstr(splits[4]), floatstr(splits[5]), strval(splits[6]),strval(splits[7]), strval(splits[8]));
		}
	}
	F = fopen("/EVF/VehicleLines.txt", io_read);
	if(fexist("/EVF/VehicleLines.txt")) {
		while(fread(F, str, 2048)) {
		    split(str, splits, ',');
		    AddVehicleLine(strval(splits[0]), strval(splits[1]), floatstr(splits[2]), floatstr(splits[3]), floatstr(splits[4]), floatstr(splits[5]), strval(splits[6]),strval(splits[7]), strval(splits[8]));
		}
	}
	F = fopen("/EVF/VehicleRows.txt", io_read);
	if(fexist("/EVF/VehicleRows.txt")) {
		while(fread(F, str, 2048)) {
		    split(str, splits, ',');
		    AddVehicleRow(strval(splits[0]), strval(splits[1]), floatstr(splits[2]), floatstr(splits[3]), floatstr(splits[4]), floatstr(splits[5]), strval(splits[6]),strval(splits[7]), strval(splits[8]));
		}
	}
	F = fopen("/EVF/NormalVehicles.txt", io_read);
	if(fexist("/EVF/NormalVehicles.txt")) {
		while(fread(F, str, 2048)) {
		    split(str, splits, ',');
		    CreateVehicle(strval(splits[0]), floatstr(splits[1]), floatstr(splits[2]), floatstr(splits[3]), floatstr(splits[4]), strval(splits[5]), strval(splits[6]), strval(splits[7]));
		}
	}
	fclose(F);
	return true;
}

stock SavePrivateVehicle(Owner[], Model, Float:X, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
	new str[512], File:F = fopen("/EVF/PrivateVehicles.txt", io_append);
	format(str, 512, "%s, %.2f, %.2f, %.2f, %.2f, %d \r\n", Owner, X, Y, Z, A, Color1, Color2, RespawnDelay);
	fwrite(F, str);
	fclose(F);
}

stock SaveRandomVehicle(Float:X, Float:Y, Float:Z, Float:A, RespawnDelay) {
	new str[512], File:F = fopen("/EVF/RandomVehicles.txt", io_append);
	format(str, 512, "%.2f, %.2f, %.2f, %.2f, %d \r\n", X, Y, Z, A, RespawnDelay);
	fwrite(F, str);
	fclose(F);
}

stock SaveVehicleLine(HowMany, Model, Float:X, Float:FirstY, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
    new str[512], File:F = fopen("/EVF/VehicleLines.txt");
	format(str, 512, "%d, %d, %.2f, %.2f, %.2f, %.2f, %d, %d, %d \r\n", HowMany, Model, X, FirstY, Z, A, Color1, Color2, RespawnDelay);
	fwrite(F, str);
	fclose(F);
}

stock SaveVehicleRow(HowMany, Model, Float:FirstX, Float:Y, Float:Z, Float:A, Color1, Color2, RespawnDelay) {
    new str[512], File:F = fopen("/EVF/VehicleRows.txt", io_append);
	format(str, 512, "%d, %d, %.2f, %.2f, %.2f, %.2f, %d, %d, %d \r\n", HowMany, Model, FirstX, Y, Z, A, Color1, Color2, RespawnDelay);
	fwrite(F, str);
	fclose(F);
}

stock SaveNormalVehicle(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay) {
    new str[512], File:F = fopen("/EVF/NormalVehicles.txt", io_append);
	format(str, 512, "%d, %.2f, %.2f, %.2f, %.2f, %d, %d, %d \r\n", modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay);
	fwrite(F, str);
	fclose(F);
}

stock GetVehicleName(vehicleid) {
	new str[128];
	format(str, 128, "%s", VehicleNames[GetVehicleModel(vehicleid)-400]);
	return str;
}

stock SetVehiclePosEx(vehicleid, Float:X, Float:Y, Float:Z, Float:A) {
    SetVehiclePos(vehicleid, X, Y, Z);
	SetVehicleZAngle(vehicleid, A);
	return true;
}

stock GetVehiclePosEx(vehicleid, &Float:X, &Float:Y, &Float:Z, &Float:A) {
	GetVehiclePos(vehicleid, X, Y, Z);
	GetVehicleZAngle(vehicleid, A);
	return true;
}

stock GetVehicleOwner(vehicleid) { // Returns -1 if the car is no private vehicle...
	for(new i; i<MAX_VEHICLES; i++) {
	    if(vehicleid == hCAR[i]) {
	        return VEHICLEOWNER[i];
		} else { return -1; }
	}
}

stock GetVehicleDriverID(vehicleid) {
	for(new i; i<MAX_PLAYERS; i++) if(IsPlayerInVehicle(i, vehicleid) && GetPlayerState(i) == PLAYER_STATE_DRIVER) return i;
	return INVALID_PLAYER_ID;
}
	    
stock pRName(playerid) {
	new name[24];
	GetPlayerName(playerid, name, 24);
	return name;
}

stock split(const strsrc[], strdest[][], delimiter) {
 	new i, li;
 	new aNum;
 	new len;
	while(i <= strlen(strsrc)){
     	if(strsrc[i]==delimiter || i==strlen(strsrc)){
         	len = strmid(strdest[aNum], strsrc, li, i, 128);
         	strdest[aNum][len] = 0;
    	 	li = i+1;
        	aNum++;
  		}
  		i++;
 	}
 	return 1;
}
	
