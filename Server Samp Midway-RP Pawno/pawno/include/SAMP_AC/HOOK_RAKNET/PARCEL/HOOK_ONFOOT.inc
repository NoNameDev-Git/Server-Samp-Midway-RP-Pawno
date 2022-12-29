IPacket:PACKET_PLAYER(playerid, BitStream:bs)
{
	new RAKNET_ONFOOT_PACKET;
	new RAKNET_ONFOOT[RAKNET_ONFOOT_SYNC];

	BS_ReadUint8(bs, RAKNET_ONFOOT_PACKET);
	BS_ReadOnFootSync(bs, RAKNET_ONFOOT);


	SERVER_INFO[playerid][SAMP_SPEED_X] = RAKNET_ONFOOT[RAKNET_SPEED_X];
	SERVER_INFO[playerid][SAMP_SPEED_Y] = RAKNET_ONFOOT[RAKNET_SPEED_Y];
	SERVER_INFO[playerid][SAMP_SPEED_Z] = RAKNET_ONFOOT[RAKNET_SPEED_Z];

	SERVER_INFO[playerid][SAMP_POS_X] = RAKNET_ONFOOT[RAKNET_POS_X];
	SERVER_INFO[playerid][SAMP_POS_Y] = RAKNET_ONFOOT[RAKNET_POS_Y];
	SERVER_INFO[playerid][SAMP_POS_Z] = RAKNET_ONFOOT[RAKNET_POS_Z];

	SERVER_INFO[playerid][SAMP_ID_VEHICLE] = 0;

	#include                                                                        SAMP_AC/MODULE/ANTINOP/POSITION
	#include                                                                        SAMP_AC/MODULE/ANTICHEAT/FLY_HACK
	#include                                                                        SAMP_AC/MODULE/ANTICHEAT/AIR_BREAK
	#include                                                                        SAMP_AC/MODULE/ANTICHEAT/TELEPORT_HACK
	#include																		SAMP_AC/MODULE/ANTICHEAT/MOP
	#include                                                                        SAMP_AC/MODULE/ANTINOP/PUT_VEHICLE
	#include                                                                        SAMP_AC/MODULE/ANTINOP/ARMED_WEAPON

	#include																		SAMP_AC/MODULE/ANTICHEAT/SPEED_HACK_ONFOOT
	#include																		SAMP_AC/MODULE/ANTICHEAT/WEAPON_HACK
	#include																		SAMP_AC/MODULE/ANTICHEAT/INVISIBLE_VEHICLE
	#include																		SAMP_AC/MODULE/ANTICHEAT/SURFING_INVISIBLE

	#include																		SAMP_AC/MODULE/ANTICRASHER/QUATERION


	if(CENTER_CONTROLE[0][CONTROL_DAMAGE] == 1)
	{
		BS_Reset(bs);
		BS_WriteUint8(bs, RAKNET_ONFOOT_PACKET);
		BS_WriteOnFootSync(bs, RAKNET_ONFOOT);
	}

    return 1;
}
