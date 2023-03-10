#if defined _rakcheat_included
	#endinput
#endif
#define _rakcheat_included

#include <a_samp>
#include <pawn_raknet>

#if !defined PAWNRAKNET_INC_
	#error You must have Pawn.RakNet include in order to use this one.
#endif


#if !defined RAK_MAX_QUAT_WARNINGS
	#define RAK_MAX_QUAT_WARNINGS 1
#endif

#if !defined RAK_MAX_SURF_WARNINGS
	#define RAK_MAX_SURF_WARNINGS 30
#endif

#if !defined RAK_MAX_SURF_DIST_WARNINGS
	#define RAK_MAX_SURF_DIST_WARNINGS 30
#endif

#if __Pawn >= 0x3A && defined __PawnBuild
	#if __Pawn > 0x3A || __PawnBuild >= 2
		#define static_enum static enum
	#endif
#endif
#if !defined static_enum
	#define static_enum enum
#endif

#if __Pawn >= 0x3A && defined __PawnBuild
	#if __Pawn > 0x3A || __PawnBuild >= 2
		#define static_const(%0) static enum { %0 }
	#endif
#endif
#if !defined static_const
	#define static_const(%0) static const %0
#endif

static_enum
{
	RAK_INVALID_POSITION = 1,
	RAK_INVALID_QUATERNION,
	RAK_INVALID_VELOCITY,
	RAK_INVALID_SURFING_OFFSETS,
	RAK_INVALID_SURFING,
	RAK_INVALID_ANIMATION_FLAGS,
	RAK_INVALID_HEALTH,
	RAK_INVALID_TRAIN_SPEED,
	RAK_INVALID_ROLL,
	RAK_INVALID_DIRECTION,
	RAK_INVALID_ANGULAR_VELOCITY,
	RAK_INVALID_ORIGIN,
	RAK_INVALID_HITPOS,
	RAK_INVALID_OFFSETS,
	RAK_INVALID_CAMFRONTVEC,
	RAK_INVALID_CAMPOS,
	RAK_INVALID_AIMZ,
	RAK_INVALID_SHOT
}

static_const(ID_PLAYER_SYNC = 207);
static_const(ID_VEHICLE_SYNC = 200);
static_const(ID_PASSENGER_SYNC = 211);
static_const(ID_UNOCCUPIED_SYNC = 209);
static_const(ID_TRAILER_SYNC = 210);
static_const(ID_SPECTATOR_SYNC = 212);
static_const(ID_BULLET_SYNC = 206);
static_const(ID_AIM_SYNC = 203);

#if defined OnRakcheatFilteredData
	forward OnRakcheatFilteredData(playerid, sync, type, subtype);
#endif

static_enum rakInfo
{
	rakQuatCount,
	rakSurfingCount,
	rakSurfingDistCount
}
static RAKInfo[MAX_PLAYERS][rakInfo];

#if !defined isnull
	#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

static CheckValidityData(Float:data)
{
	if(floatcmp(data, data) != 0 || floatcmp(data, 0x7F800000) == 0 || floatcmp(data, 0xFF800000) == 0) return 1;
	return 0;
}

static CheckOutputLimit(Float:data, Float:max, Float:min = 0.0, bool:check = false)
{
	if(floatcmp(floatabs(data), max) > 0 || check && floatcmp(data, min) < 0) return 1;
	return 0;
}

static KickWithCode(playerid, sync, type, subtype)
{
	if(IsPlayerConnected(playerid) == 0) return 0;
	#if defined RAK_DEBUG
		printf("[Rakcheat] Suspicious player ID %d. Reason code: %03d (%d)", playerid, type, subtype);
	#endif
	#if defined OnRakcheatFilteredData
		return OnRakcheatFilteredData(playerid, sync, type, subtype);
	#else
		#pragma unused sync
		Kick(playerid);
		return 0;
	#endif
}

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerConnect(playerid)
#else
	public OnPlayerConnect(playerid)
#endif
{
	RAKInfo[playerid][rakQuatCount] =
	RAKInfo[playerid][rakSurfingCount] =
	RAKInfo[playerid][rakSurfingDistCount] = 0;

	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined rak_OnPlayerConnect
		return rak_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect rak_OnPlayerConnect
	#if defined rak_OnPlayerConnect
		forward rak_OnPlayerConnect(playerid);
	#endif
#endif

IPacket:ID_PLAYER_SYNC(playerid, BitStream:bs)
{
	new onFootData[RAKNET_ONFOOT_SYNC];

	BS_IgnoreBits(bs, 8);
	BS_ReadOnFootSync(bs, onFootData);

	if(CheckValidityData(onFootData[RAKNET_POS_X]) || CheckValidityData(onFootData[RAKNET_POS_Y]) || CheckValidityData(onFootData[RAKNET_POS_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Position x, y, z: %f, %f, %f",
			onFootData[RAKNET_POS_X], onFootData[RAKNET_POS_Y], onFootData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(onFootData[RAKNET_POS_X], 20000.0) || CheckOutputLimit(onFootData[RAKNET_POS_Y], 20000.0) ||
	CheckOutputLimit(onFootData[RAKNET_POS_Z], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Position x, y, z: %f, %f, %f",
			onFootData[RAKNET_POS_X], onFootData[RAKNET_POS_Y], onFootData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_POSITION, 1);
	}

	if(CheckValidityData(onFootData[RAKNET_QUATERION_X]) || CheckValidityData(onFootData[RAKNET_QUATERION_Y]) || CheckValidityData(onFootData[RAKNET_QUATERION_Z]) ||
	CheckValidityData(onFootData[RAKNET_QUATERION_R]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			onFootData[RAKNET_QUATERION_X], onFootData[RAKNET_QUATERION_Y], onFootData[RAKNET_QUATERION_Z], onFootData[RAKNET_QUATERION_R]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_QUATERNION, 0);
	}

	if(CheckOutputLimit(onFootData[RAKNET_QUATERION_X], 1.0) || CheckOutputLimit(onFootData[RAKNET_QUATERION_Y], 1.0) ||
	CheckOutputLimit(onFootData[RAKNET_QUATERION_Z], 1.0) || CheckOutputLimit(onFootData[RAKNET_QUATERION_R], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			onFootData[RAKNET_QUATERION_X], onFootData[RAKNET_QUATERION_Y], onFootData[RAKNET_QUATERION_Z], onFootData[RAKNET_QUATERION_R]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_QUATERNION, 1);
	}

	new Float:rak_ang = atan2(floatmul(2.0, floatadd(floatmul(onFootData[RAKNET_QUATERION_Z], onFootData[RAKNET_QUATERION_R]),
	floatmul(onFootData[RAKNET_QUATERION_X], onFootData[RAKNET_QUATERION_Y]))), floatadd(floatsub(floatsub(floatpower(onFootData[RAKNET_QUATERION_X], 2.0),
	floatpower(onFootData[RAKNET_QUATERION_Y], 2.0)), floatpower(onFootData[RAKNET_QUATERION_Z], 2.0)),
	floatpower(onFootData[RAKNET_QUATERION_R], 2.0)));
	if(floatabs(rak_ang) > 85.0 && onFootData[RAKNET_ACTION] == SPECIAL_ACTION_NONE)
	{
		if(++RAKInfo[playerid][rakQuatCount] > RAK_MAX_QUAT_WARNINGS)
		{
			#if defined RAK_DEBUG
				printf("[Rakcheat debug] [ID_PLAYER_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f, angle: %f",
				onFootData[RAKNET_QUATERION_X], onFootData[RAKNET_QUATERION_Y], onFootData[RAKNET_QUATERION_Z], onFootData[RAKNET_QUATERION_R], rak_ang);
			#endif
			return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_QUATERNION, 2);
		}
	}
	else RAKInfo[playerid][rakQuatCount] = 0;

	if(CheckValidityData(onFootData[RAKNET_SPEED_X]) || CheckValidityData(onFootData[RAKNET_SPEED_Y]) || CheckValidityData(onFootData[RAKNET_SPEED_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Velocity x, y, z: %f, %f, %f",
			onFootData[RAKNET_SPEED_X], onFootData[RAKNET_SPEED_Y], onFootData[RAKNET_SPEED_Z]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_VELOCITY, 0);
	}

	if(CheckOutputLimit(onFootData[RAKNET_SPEED_X], 100.0) || CheckOutputLimit(onFootData[RAKNET_SPEED_Y], 100.0) || CheckOutputLimit(onFootData[RAKNET_SPEED_Z], 100.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Velocity x, y, z: %f, %f, %f",
			onFootData[RAKNET_SPEED_X], onFootData[RAKNET_SPEED_Y], onFootData[RAKNET_SPEED_Z]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_VELOCITY, 1);
	}

	if(CheckValidityData(onFootData[RAKNET_SURFING_X]) || CheckValidityData(onFootData[RAKNET_SURFING_Y]) || CheckValidityData(onFootData[RAKNET_SURFING_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Surfing offsets x, y, z: %f, %f, %f",
			onFootData[RAKNET_SURFING_X], onFootData[RAKNET_SURFING_Y], onFootData[RAKNET_SURFING_Z]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING_OFFSETS, 0);
	}

	if(CheckOutputLimit(onFootData[RAKNET_SURFING_X], 50.0) || CheckOutputLimit(onFootData[RAKNET_SURFING_Y], 50.0) ||
	CheckOutputLimit(onFootData[RAKNET_SURFING_Z], 50.0))
	{
		if(++RAKInfo[playerid][rakSurfingCount] > RAK_MAX_SURF_WARNINGS)
		{
			#if defined RAK_DEBUG
				printf("[Rakcheat debug] [ID_PLAYER_SYNC] Surfing offsets x, y, z: %f, %f, %f",
				onFootData[RAKNET_SURFING_X], onFootData[RAKNET_SURFING_Y], onFootData[RAKNET_SURFING_Z]);
			#endif
			return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING_OFFSETS, 1);
		}
	}
	else RAKInfo[playerid][rakSurfingCount] = 0;

	if(onFootData[RAKNET_SURFING_CAR_ID] != 0)
	{
		if(0 < onFootData[RAKNET_SURFING_CAR_ID] <= MAX_VEHICLES)
		{
			new rak_model = GetVehicleModel(onFootData[RAKNET_SURFING_CAR_ID]);
			if(rak_model == 0)
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_PLAYER_SYNC] Veh model: %d, vehicleid: %d",
					rak_model, onFootData[RAKNET_SURFING_CAR_ID]);
				#endif
				return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING, 0);
			}
			else
			{
				new Float:rak_vX, Float:rak_vY, Float:rak_vZ;
				GetVehiclePos(onFootData[RAKNET_SURFING_CAR_ID], rak_vX, rak_vY, rak_vZ);
				rak_ang = VectorSize(floatsub(onFootData[RAKNET_POS_X], rak_vX), floatsub(onFootData[RAKNET_POS_Y], rak_vY),
				floatsub(onFootData[RAKNET_POS_Z], rak_vZ));
				if(floatcmp(rak_ang, 50.0) > 0)
				{
					if(++RAKInfo[playerid][rakSurfingDistCount] > RAK_MAX_SURF_DIST_WARNINGS)
					{
						#if defined RAK_DEBUG
							printf("[Rakcheat debug] [ID_PLAYER_SYNC] Veh x, y, z: %f, %f, %f, player x, y, z: %f, %f, %f, distance: %f",
							rak_vX, rak_vY, rak_vZ, onFootData[RAKNET_POS_X], onFootData[RAKNET_POS_Y], onFootData[RAKNET_POS_Z], rak_ang);
						#endif
						return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING, 1);
					}
				}
				else RAKInfo[playerid][rakSurfingDistCount] = 0;
			}
		}
		else if(MAX_VEHICLES < onFootData[RAKNET_SURFING_CAR_ID] <= MAX_OBJECTS + MAX_VEHICLES)
		{
			new rak_object = GetObjectModel(onFootData[RAKNET_SURFING_CAR_ID]);
			if(rak_object == -1)
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_PLAYER_SYNC] Object model: %d, objectid: %d",
					rak_object, onFootData[RAKNET_SURFING_CAR_ID]);
				#endif
				return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING, 2);
			}
			else
			{
				new Float:rak_vX, Float:rak_vY, Float:rak_vZ;
				GetObjectPos(onFootData[RAKNET_SURFING_CAR_ID], rak_vX, rak_vY, rak_vZ);
				rak_ang = VectorSize(floatsub(onFootData[RAKNET_POS_X], rak_vX), floatsub(onFootData[RAKNET_POS_Y], rak_vY),
				floatsub(onFootData[RAKNET_POS_Z], rak_vZ));
				if(floatcmp(rak_ang, 50.0) > 0)
				{
					if(++RAKInfo[playerid][rakSurfingDistCount] > RAK_MAX_SURF_DIST_WARNINGS)
					{
						#if defined RAK_DEBUG
							printf("[Rakcheat debug] [ID_PLAYER_SYNC] Object x, y, z: %f, %f, %f, player x, y, z: %f, %f, %f, distance: %f",
							rak_vX, rak_vY, rak_vZ, onFootData[RAKNET_POS_X], onFootData[RAKNET_POS_Y], onFootData[RAKNET_POS_Z], rak_ang);
						#endif
						return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING, 3);
					}
				}
				else RAKInfo[playerid][rakSurfingDistCount] = 0;
			}
		}
		else
		{
			if(onFootData[RAKNET_SURFING_CAR_ID] != INVALID_VEHICLE_ID)
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_PLAYER_SYNC] Surfing: %d", onFootData[RAKNET_SURFING_CAR_ID]);
				#endif
				return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_SURFING, 4);
			}
		}
	}

	if(onFootData[PR_animationFlags] == 0)
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PLAYER_SYNC] Animation flags: %d", onFootData[PR_animationFlags]);
		#endif
		return KickWithCode(playerid, ID_PLAYER_SYNC, RAK_INVALID_ANIMATION_FLAGS, 0);
	}
	return 1;
}

IPacket:ID_VEHICLE_SYNC(playerid, BitStream:bs)
{
	new inCarData[RAKNET_DRIVER_SYNC];

	BS_IgnoreBits(bs, 8);
	BS_ReadInCarSync(bs, inCarData);

	if(CheckValidityData(inCarData[RAKNET_QUATERION_X]) || CheckValidityData(inCarData[RAKNET_QUATERION_Y]) || CheckValidityData(inCarData[RAKNET_QUATERION_Z]) ||
	CheckValidityData(inCarData[RAKNET_QUATERION_R]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			inCarData[RAKNET_QUATERION_X], inCarData[RAKNET_QUATERION_Y], inCarData[RAKNET_QUATERION_Z], inCarData[RAKNET_QUATERION_R]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_QUATERNION, 0);
	}

	if(CheckOutputLimit(inCarData[RAKNET_QUATERION_X], 1.0) || CheckOutputLimit(inCarData[RAKNET_QUATERION_Y], 1.0) ||
	CheckOutputLimit(inCarData[RAKNET_QUATERION_Z], 1.0) || CheckOutputLimit(inCarData[RAKNET_QUATERION_R], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			inCarData[RAKNET_QUATERION_X], inCarData[RAKNET_QUATERION_Y], inCarData[RAKNET_QUATERION_Z], inCarData[RAKNET_QUATERION_R]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_QUATERNION, 1);
	}

	if(CheckValidityData(inCarData[RAKNET_POS_X]) || CheckValidityData(inCarData[RAKNET_POS_Y]) || CheckValidityData(inCarData[RAKNET_POS_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Position x, y, z: %f, %f, %f",
			inCarData[RAKNET_POS_X], inCarData[RAKNET_POS_Y], inCarData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(inCarData[RAKNET_POS_X], 20000.0) || CheckOutputLimit(inCarData[RAKNET_POS_Y], 20000.0) ||
	CheckOutputLimit(inCarData[RAKNET_POS_Z], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Position x, y, z: %f, %f, %f",
			inCarData[RAKNET_POS_X], inCarData[RAKNET_POS_Y], inCarData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_POSITION, 1);
	}

	if(CheckValidityData(inCarData[RAKNET_SPEED_X]) || CheckValidityData(inCarData[RAKNET_SPEED_Y]) || CheckValidityData(inCarData[RAKNET_SPEED_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Velocity x, y, z: %f, %f, %f",
			inCarData[RAKNET_SPEED_X], inCarData[RAKNET_SPEED_Y], inCarData[RAKNET_SPEED_Z]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_VELOCITY, 0);
	}

	if(CheckOutputLimit(inCarData[RAKNET_SPEED_X], 100.0) || CheckOutputLimit(inCarData[RAKNET_SPEED_Y], 100.0) || CheckOutputLimit(inCarData[RAKNET_SPEED_Z], 100.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Velocity x, y, z: %f, %f, %f",
			inCarData[RAKNET_SPEED_X], inCarData[RAKNET_SPEED_Y], inCarData[RAKNET_SPEED_Z]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_VELOCITY, 1);
	}

	if(CheckValidityData(inCarData[PR_vehicleHealth]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Veh health: %f", inCarData[PR_vehicleHealth]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_HEALTH, 0);
	}

	if(CheckValidityData(inCarData[PR_trainSpeed]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Train speed: %f", inCarData[PR_trainSpeed]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_TRAIN_SPEED, 0);
	}

	if(CheckOutputLimit(inCarData[PR_trainSpeed], 3.5))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_VEHICLE_SYNC] Train speed: %f", inCarData[PR_trainSpeed]);
		#endif
		return KickWithCode(playerid, ID_VEHICLE_SYNC, RAK_INVALID_TRAIN_SPEED, 1);
	}
	return 1;
}

IPacket:ID_PASSENGER_SYNC(playerid, BitStream:bs)
{
	new passengerData[RAKNET_PASSENGER_SYNC];

	BS_IgnoreBits(bs, 8);
	BS_ReadPassengerSync(bs, passengerData);

	if(CheckValidityData(passengerData[RAKNET_POS_X]) || CheckValidityData(passengerData[RAKNET_POS_Y]) || CheckValidityData(passengerData[RAKNET_POS_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PASSENGER_SYNC] Position x, y, z: %f, %f, %f",
			passengerData[RAKNET_POS_X], passengerData[RAKNET_POS_Y], passengerData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_PASSENGER_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(passengerData[RAKNET_POS_X], 20000.0) || CheckOutputLimit(passengerData[RAKNET_POS_Y], 20000.0) ||
	CheckOutputLimit(passengerData[RAKNET_POS_Z], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_PASSENGER_SYNC] Position x, y, z: %f, %f, %f",
			passengerData[RAKNET_POS_X], passengerData[RAKNET_POS_Y], passengerData[RAKNET_POS_Z]);
		#endif
		return KickWithCode(playerid, ID_PASSENGER_SYNC, RAK_INVALID_POSITION, 1);
	}
	return 1;
}

IPacket:ID_UNOCCUPIED_SYNC(playerid, BitStream:bs)
{
	new unoccupiedData[PR_UnoccupiedSync];

	BS_IgnoreBits(bs, 8);
	BS_ReadUnoccupiedSync(bs, unoccupiedData);

	if(CheckValidityData(unoccupiedData[PR_roll][0]) || CheckValidityData(unoccupiedData[PR_roll][1]) || CheckValidityData(unoccupiedData[PR_roll][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Roll x, y, z: %f, %f, %f",
			unoccupiedData[PR_roll][0], unoccupiedData[PR_roll][1], unoccupiedData[PR_roll][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_ROLL, 0);
	}

	if(CheckOutputLimit(unoccupiedData[PR_roll][0], 1.0) || CheckOutputLimit(unoccupiedData[PR_roll][1], 1.0) || CheckOutputLimit(unoccupiedData[PR_roll][2], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Roll x, y, z: %f, %f, %f",
			unoccupiedData[PR_roll][0], unoccupiedData[PR_roll][1], unoccupiedData[PR_roll][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_ROLL, 1);
	}

	if(CheckValidityData(unoccupiedData[PR_direction][0]) || CheckValidityData(unoccupiedData[PR_direction][1]) || CheckValidityData(unoccupiedData[PR_direction][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Direction x, y, z: %f, %f, %f",
			unoccupiedData[PR_direction][0], unoccupiedData[PR_direction][1], unoccupiedData[PR_direction][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_DIRECTION, 0);
	}

	if(CheckOutputLimit(unoccupiedData[PR_direction][0], 1.0) || CheckOutputLimit(unoccupiedData[PR_direction][1], 1.0) ||
	CheckOutputLimit(unoccupiedData[PR_direction][2], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Direction x, y, z: %f, %f, %f",
			unoccupiedData[PR_direction][0], unoccupiedData[PR_direction][1], unoccupiedData[PR_direction][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_DIRECTION, 1);
	}

	if(CheckValidityData(unoccupiedData[PR_position][0]) || CheckValidityData(unoccupiedData[PR_position][1]) || CheckValidityData(unoccupiedData[PR_position][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Position x, y, z: %f, %f, %f",
			unoccupiedData[PR_position][0], unoccupiedData[PR_position][1], unoccupiedData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(unoccupiedData[PR_position][0], 20000.0) || CheckOutputLimit(unoccupiedData[PR_position][1], 20000.0) ||
	CheckOutputLimit(unoccupiedData[PR_position][2], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Position x, y, z: %f, %f, %f",
			unoccupiedData[PR_position][0], unoccupiedData[PR_position][1], unoccupiedData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_POSITION, 1);
	}

	if(CheckValidityData(unoccupiedData[PR_velocity][0]) || CheckValidityData(unoccupiedData[PR_velocity][1]) || CheckValidityData(unoccupiedData[PR_velocity][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Velocity x, y, z: %f, %f, %f",
			unoccupiedData[PR_velocity][0], unoccupiedData[PR_velocity][1], unoccupiedData[PR_velocity][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_VELOCITY, 0);
	}

	if(CheckOutputLimit(unoccupiedData[PR_velocity][0], 100.0) || CheckOutputLimit(unoccupiedData[PR_velocity][1], 100.0) ||
	CheckOutputLimit(unoccupiedData[PR_velocity][2], 100.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Velocity x, y, z: %f, %f, %f",
			unoccupiedData[PR_velocity][0], unoccupiedData[PR_velocity][1], unoccupiedData[PR_velocity][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_VELOCITY, 1);
	}

	if(CheckValidityData(unoccupiedData[PR_angularVelocity][0]) || CheckValidityData(unoccupiedData[PR_angularVelocity][1]) ||
	CheckValidityData(unoccupiedData[PR_angularVelocity][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Angular velocity x, y, z: %f, %f, %f",
			unoccupiedData[PR_angularVelocity][0], unoccupiedData[PR_angularVelocity][1], unoccupiedData[PR_angularVelocity][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_ANGULAR_VELOCITY, 0);
	}

	if(CheckOutputLimit(unoccupiedData[PR_angularVelocity][0], 1.0) || CheckOutputLimit(unoccupiedData[PR_angularVelocity][1], 1.0) ||
	CheckOutputLimit(unoccupiedData[PR_angularVelocity][2], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Angular velocity x, y, z: %f, %f, %f",
			unoccupiedData[PR_angularVelocity][0], unoccupiedData[PR_angularVelocity][1], unoccupiedData[PR_angularVelocity][2]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_ANGULAR_VELOCITY, 1);
	}

	if(CheckValidityData(unoccupiedData[PR_vehicleHealth]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_UNOCCUPIED_SYNC] Veh health: %f", unoccupiedData[PR_vehicleHealth]);
		#endif
		return KickWithCode(playerid, ID_UNOCCUPIED_SYNC, RAK_INVALID_HEALTH, 0);
	}
	return 1;
}

IPacket:ID_TRAILER_SYNC(playerid, BitStream:bs)
{
	new trailerData[PR_TrailerSync];

	BS_IgnoreBits(bs, 8);
	BS_ReadTrailerSync(bs, trailerData);

	if(CheckValidityData(trailerData[PR_position][0]) || CheckValidityData(trailerData[PR_position][1]) || CheckValidityData(trailerData[PR_position][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Position x, y, z: %f, %f, %f",
			trailerData[PR_position][0], trailerData[PR_position][1], trailerData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(trailerData[PR_position][0], 20000.0) || CheckOutputLimit(trailerData[PR_position][1], 20000.0) ||
	CheckOutputLimit(trailerData[PR_position][2], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Position x, y, z: %f, %f, %f",
			trailerData[PR_position][0], trailerData[PR_position][1], trailerData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_POSITION, 1);
	}

	if(CheckValidityData(trailerData[PR_quaternion][0]) || CheckValidityData(trailerData[PR_quaternion][1]) || CheckValidityData(trailerData[PR_quaternion][2]) ||
	CheckValidityData(trailerData[PR_quaternion][3]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			trailerData[PR_quaternion][0], trailerData[PR_quaternion][1], trailerData[PR_quaternion][2], trailerData[PR_quaternion][3]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_QUATERNION, 0);
	}

	if(CheckOutputLimit(trailerData[PR_quaternion][0], 1.0) || CheckOutputLimit(trailerData[PR_quaternion][1], 1.0) ||
	CheckOutputLimit(trailerData[PR_quaternion][2], 1.0) || CheckOutputLimit(trailerData[PR_quaternion][3], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Quaternion w, x, y, z: %f, %f, %f, %f",
			trailerData[PR_quaternion][0], trailerData[PR_quaternion][1], trailerData[PR_quaternion][2], trailerData[PR_quaternion][3]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_QUATERNION, 1);
	}

	if(CheckValidityData(trailerData[PR_velocity][0]) || CheckValidityData(trailerData[PR_velocity][1]) || CheckValidityData(trailerData[PR_velocity][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Velocity x, y, z: %f, %f, %f",
			trailerData[PR_velocity][0], trailerData[PR_velocity][1], trailerData[PR_velocity][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_VELOCITY, 0);
	}

	if(CheckOutputLimit(trailerData[PR_velocity][0], 100.0) || CheckOutputLimit(trailerData[PR_velocity][1], 100.0) ||
	CheckOutputLimit(trailerData[PR_velocity][2], 100.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Velocity x, y, z: %f, %f, %f",
			trailerData[PR_velocity][0], trailerData[PR_velocity][1], trailerData[PR_velocity][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_VELOCITY, 1);
	}

	if(CheckValidityData(trailerData[PR_angularVelocity][0]) || CheckValidityData(trailerData[PR_angularVelocity][1]) ||
	CheckValidityData(trailerData[PR_angularVelocity][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Angular velocity x, y, z: %f, %f, %f",
			trailerData[PR_angularVelocity][0], trailerData[PR_angularVelocity][1], trailerData[PR_angularVelocity][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_ANGULAR_VELOCITY, 0);
	}

	if(CheckOutputLimit(trailerData[PR_angularVelocity][0], 1.0) || CheckOutputLimit(trailerData[PR_angularVelocity][1], 1.0) ||
	CheckOutputLimit(trailerData[PR_angularVelocity][2], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_TRAILER_SYNC] Angular velocity x, y, z: %f, %f, %f",
			trailerData[PR_angularVelocity][0], trailerData[PR_angularVelocity][1], trailerData[PR_angularVelocity][2]);
		#endif
		return KickWithCode(playerid, ID_TRAILER_SYNC, RAK_INVALID_ANGULAR_VELOCITY, 1);
	}
	return 1;
}

IPacket:ID_SPECTATOR_SYNC(playerid, BitStream:bs)
{
	new spectatorData[PR_SpectatingSync];

	BS_IgnoreBits(bs, 8);
	BS_ReadSpectatingSync(bs, spectatorData);

	if(CheckValidityData(spectatorData[PR_position][0]) || CheckValidityData(spectatorData[PR_position][1]) || CheckValidityData(spectatorData[PR_position][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_SPECTATOR_SYNC] Position x, y, z: %f, %f, %f",
			spectatorData[PR_position][0], spectatorData[PR_position][1], spectatorData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_SPECTATOR_SYNC, RAK_INVALID_POSITION, 0);
	}

	if(CheckOutputLimit(spectatorData[PR_position][0], 20000.0) || CheckOutputLimit(spectatorData[PR_position][1], 20000.0) ||
	CheckOutputLimit(spectatorData[PR_position][2], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_SPECTATOR_SYNC] Position x, y, z: %f, %f, %f",
			spectatorData[PR_position][0], spectatorData[PR_position][1], spectatorData[PR_position][2]);
		#endif
		return KickWithCode(playerid, ID_SPECTATOR_SYNC, RAK_INVALID_POSITION, 1);
	}
	return 1;
}

IPacket:ID_BULLET_SYNC(playerid, BitStream:bs)
{
	new bulletData[RAKNET_BULLET_SYNC];

	BS_IgnoreBits(bs, 8);
	BS_ReadBulletSync(bs, bulletData);

	if(CheckValidityData(bulletData[RAKNET_START_X]) || CheckValidityData(bulletData[RAKNET_START_Y]) || CheckValidityData(bulletData[RAKNET_START_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_BULLET_SYNC] Origin x, y, z: %f, %f, %f",
			bulletData[RAKNET_START_X], bulletData[RAKNET_START_Y], bulletData[RAKNET_START_Z]);
		#endif
		return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_ORIGIN, 0);
	}

	if(CheckOutputLimit(bulletData[RAKNET_START_X], 20000.0) || CheckOutputLimit(bulletData[RAKNET_START_Y], 20000.0) || CheckOutputLimit(bulletData[RAKNET_START_Z], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_BULLET_SYNC] Origin x, y, z: %f, %f, %f",
			bulletData[RAKNET_START_X], bulletData[RAKNET_START_Y], bulletData[RAKNET_START_Z]);
		#endif
		return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_ORIGIN, 1);
	}

	if(CheckValidityData(bulletData[RAKNET_STOP_X]) || CheckValidityData(bulletData[RAKNET_STOP_Y]) || CheckValidityData(bulletData[RAKNET_STOP_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_BULLET_SYNC] Hitpos x, y, z: %f, %f, %f",
			bulletData[RAKNET_STOP_X], bulletData[RAKNET_STOP_Y], bulletData[RAKNET_STOP_Z]);
		#endif
		return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_HITPOS, 0);
	}

	if(CheckOutputLimit(bulletData[RAKNET_STOP_X], 20000.0) || CheckOutputLimit(bulletData[RAKNET_STOP_Y], 20000.0) || CheckOutputLimit(bulletData[RAKNET_STOP_Z], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_BULLET_SYNC] Hitpos x, y, z: %f, %f, %f",
			bulletData[RAKNET_STOP_X], bulletData[RAKNET_STOP_Y], bulletData[RAKNET_STOP_Z]);
		#endif
		return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_HITPOS, 1);
	}

	if(CheckValidityData(bulletData[RAKNET_OFFSET_X]) || CheckValidityData(bulletData[RAKNET_OFFSET_Y]) || CheckValidityData(bulletData[RAKNET_OFFSET_Z]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_BULLET_SYNC] Offsets x, y, z: %f, %f, %f",
			bulletData[RAKNET_OFFSET_X], bulletData[RAKNET_OFFSET_Y], bulletData[RAKNET_OFFSET_Z]);
		#endif
		return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_OFFSETS, 0);
	}

	#if defined RAK_ENABLED_SHOT
		if(bulletData[PR_hitType] != BULLET_HIT_TYPE_NONE)
		{
			new Float:rak_X, Float:rak_Y, Float:rak_Z;
			GetPlayerPos(playerid, rak_X, rak_Y, rak_Z);
			if(floatcmp(bulletData[RAKNET_START_X], rak_X) == 0 || floatcmp(bulletData[RAKNET_START_Y], rak_Y) == 0 || floatcmp(bulletData[RAKNET_START_Z], rak_Z) == 0)
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_BULLET_SYNC] Pos x, y, z: %f, %f, %f, sync x, y, z: %f, %f, %f",
					rak_X, rak_Y, rak_Z, bulletData[RAKNET_START_X], bulletData[RAKNET_START_Y], bulletData[RAKNET_START_Z]);
				#endif
				return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_SHOT, 0);
			}
		}
	#endif

	switch(bulletData[RAKNET_TYPE])
	{
		case BULLET_HIT_TYPE_PLAYER:
		{
			if(CheckOutputLimit(bulletData[RAKNET_OFFSET_X], 2.0) || CheckOutputLimit(bulletData[RAKNET_OFFSET_Y], 2.0) || CheckOutputLimit(bulletData[RAKNET_OFFSET_Z], 2.0))
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_BULLET_SYNC] Offsets x, y, z: %f, %f, %f",
					bulletData[RAKNET_OFFSET_X], bulletData[RAKNET_OFFSET_Y], bulletData[RAKNET_OFFSET_Z]);
				#endif
				return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_OFFSETS, 1);
			}

			#if defined RAK_ENABLED_SHOT
				if(bulletData[PR_hitId] != INVALID_PLAYER_ID)
				{
					new Float:rak_vX, Float:rak_vY, Float:rak_vZ;
					GetPlayerPos(bulletData[PR_hitId], rak_vX, rak_vY, rak_vZ);
					if(floatcmp(bulletData[RAKNET_STOP_X], rak_vX) == 0 || floatcmp(bulletData[RAKNET_STOP_Y], rak_vY) == 0 ||
					floatcmp(bulletData[RAKNET_STOP_Z], rak_vZ) == 0)
					{
						#if defined RAK_DEBUG
							printf("[Rakcheat debug] [ID_BULLET_SYNC] Pos x, y, z: %f, %f, %f, sync x, y, z: %f, %f, %f",
							rak_vX, rak_vY, rak_vZ, bulletData[RAKNET_STOP_X], bulletData[RAKNET_STOP_Y], bulletData[RAKNET_STOP_Z]);
						#endif
						return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_SHOT, 1);
					}
				}
			#endif
		}
		case BULLET_HIT_TYPE_VEHICLE:
		{
			if(CheckOutputLimit(bulletData[RAKNET_OFFSET_X], 300.0) || CheckOutputLimit(bulletData[RAKNET_OFFSET_Y], 300.0) ||
			CheckOutputLimit(bulletData[RAKNET_OFFSET_Z], 300.0))
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_BULLET_SYNC] Offsets x, y, z: %f, %f, %f",
					bulletData[RAKNET_OFFSET_X], bulletData[RAKNET_OFFSET_Y], bulletData[RAKNET_OFFSET_Z]);
				#endif
				return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_OFFSETS, 2);
			}

			#if defined RAK_ENABLED_SHOT
				if(bulletData[PR_hitId] != INVALID_VEHICLE_ID)
				{
					new Float:rak_vX, Float:rak_vY, Float:rak_vZ;
					GetVehiclePos(bulletData[PR_hitId], rak_vX, rak_vY, rak_vZ);
					if(floatcmp(bulletData[RAKNET_STOP_X], rak_vX) == 0 || floatcmp(bulletData[RAKNET_STOP_Y], rak_vY) == 0 ||
					floatcmp(bulletData[RAKNET_STOP_Z], rak_vZ) == 0)
					{
						#if defined RAK_DEBUG
							printf("[Rakcheat debug] [ID_BULLET_SYNC] Pos x, y, z: %f, %f, %f, sync x, y, z: %f, %f, %f",
							rak_vX, rak_vY, rak_vZ, bulletData[RAKNET_STOP_X], bulletData[RAKNET_STOP_Y], bulletData[RAKNET_STOP_Z]);
						#endif
						return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_SHOT, 2);
					}
				}
			#endif
		}
		default:
		{
			if(CheckOutputLimit(bulletData[RAKNET_OFFSET_X], 20000.0) || CheckOutputLimit(bulletData[RAKNET_OFFSET_Y], 20000.0) ||
			CheckOutputLimit(bulletData[RAKNET_OFFSET_Z], 20000.0))
			{
				#if defined RAK_DEBUG
					printf("[Rakcheat debug] [ID_BULLET_SYNC] Offsets x, y, z: %f, %f, %f",
					bulletData[RAKNET_OFFSET_X], bulletData[RAKNET_OFFSET_Y], bulletData[RAKNET_OFFSET_Z]);
				#endif
				return KickWithCode(playerid, ID_BULLET_SYNC, RAK_INVALID_OFFSETS, 3);
			}
		}
	}
	return 1;
}

IPacket:ID_AIM_SYNC(playerid, BitStream:bs)
{
	new aimData[PR_AimSync];

	BS_IgnoreBits(bs, 8);
	BS_ReadAimSync(bs, aimData);

	if(CheckValidityData(aimData[PR_camFrontVec][0]) || CheckValidityData(aimData[PR_camFrontVec][1]) || CheckValidityData(aimData[PR_camFrontVec][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Camfrontvec x, y, z: %f, %f, %f",
			aimData[PR_camFrontVec][0], aimData[PR_camFrontVec][1], aimData[PR_camFrontVec][2]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_CAMFRONTVEC, 0);
	}

	if(CheckOutputLimit(aimData[PR_camFrontVec][0], 1.0) || CheckOutputLimit(aimData[PR_camFrontVec][1], 1.0) || CheckOutputLimit(aimData[PR_camFrontVec][2], 1.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Camfrontvec x, y, z: %f, %f, %f",
			aimData[PR_camFrontVec][0], aimData[PR_camFrontVec][1], aimData[PR_camFrontVec][2]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_CAMFRONTVEC, 1);
	}

	if(CheckValidityData(aimData[PR_camPos][0]) || CheckValidityData(aimData[PR_camPos][1]) || CheckValidityData(aimData[PR_camPos][2]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Campos x, y, z: %f, %f, %f",
			aimData[PR_camPos][0], aimData[PR_camPos][1], aimData[PR_camPos][2]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_CAMPOS, 0);
	}

	if(CheckOutputLimit(aimData[PR_camPos][0], 20000.0) || CheckOutputLimit(aimData[PR_camPos][1], 20000.0) || CheckOutputLimit(aimData[PR_camPos][2], 20000.0))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Campos x, y, z: %f, %f, %f",
			aimData[PR_camPos][0], aimData[PR_camPos][1], aimData[PR_camPos][2]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_CAMPOS, 1);
	}

	if(CheckValidityData(aimData[PR_aimZ]))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Aimz: %f", aimData[PR_aimZ]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_AIMZ, 0);
	}

	if(CheckOutputLimit(aimData[PR_aimZ], 1.5))
	{
		#if defined RAK_DEBUG
			printf("[Rakcheat debug] [ID_AIM_SYNC] Aimz: %f", aimData[PR_aimZ]);
		#endif
		return KickWithCode(playerid, ID_AIM_SYNC, RAK_INVALID_AIMZ, 1);
	}
	return 1;
}
