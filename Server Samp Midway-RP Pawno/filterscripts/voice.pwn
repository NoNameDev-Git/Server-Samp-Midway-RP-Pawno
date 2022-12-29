main() {}
#include <a_samp>
#include <core>
#include <float>
#include <sampvoice>
#pragma tabsize 0


/////////////////////////////////////////////////////
//����� ��������� ���
#define NONE_3D_TEXT 					(Text3D:-1)
///
#if defined _sampvoice_included
	#define SV_KEY_B 0x42
	#define SV_KEY_Z 0x5A
#endif
///////////////////////////////////////////////////

//////////////////////////////////////////
//����� ��������� ���
new SV_GSTREAM:gstream = SV_NULL;
new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };
//////////////////////////////////////////



public OnFilterScriptInit()
{
//////////////////////////////////////////////////////
//����� ��������� ���
	gstream = SvCreateGStream(0xffff0000, "Global");
/////////////////////////////////////////////////////
	//����� ��������� ���
	#if defined _sampvoice_included
		gstream = SvCreateGStream(0xFF0000FF, "Global");
	#endif

	return 1;
}

public OnFilterScriptExit()
{
	//����� ��������� ���
	#if defined _sampvoice_included
		if (gstream != SV_NULL) {
			SvDeleteStream(gstream);
			gstream = SV_NULL;
		}
	#endif
	//����� ��������� ���
	if (gstream) SvDeleteStream(gstream);
}

public OnPlayerConnect(playerid)
{
	///////////////////////////////////////////////////////////
	//����� ��������� ���
	if (SvGetVersion(playerid) == SV_NULL)
	{
		SendClientMessage(playerid, -1, "���������� ������.");
	}
	else if (SvHasMicro(playerid) == SV_FALSE)
	{
		SendClientMessage(playerid, -1, "�������� �� ���������.");
	}
	else if ((lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0xff0000ff, "Local")))
	{
		SendClientMessage(playerid, -1, "������� Z, ����� ���������� � ���������� �����, � B, ����� ���������� � ��������� �����..");

		if (gstream) SvAttachListenerToStream(gstream, playerid);
		SvAddKey(playerid, 0x5A);
	}
	//////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	//����� ��������� ���
	#if defined _sampvoice_included
	if (SvGetVersion(playerid) == SV_NULL) {
		SendClientMessage(playerid, -1, "�� ������� ���������� ������ sampvoice");
	} else if (SvHasMicro(playerid) == SV_FALSE) {
		SendClientMessage(playerid, -1, "�� ������� ���������� ��������");
	} else {
		if (gstream != SV_NULL) {
			SvAttachListenerToStream(gstream, playerid);
			SvAddKey(playerid, SV_KEY_B);
		}
		if ((lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0x00FFFFF, "Local")) != SV_NULL) {
			SvAddKey(playerid, SV_KEY_Z);
		}
	}
	#endif
	////////////////////////////////////////////////////
}

public OnPlayerDisconnect(playerid, reason)
{
	//////////////////////////////////////////
	//����� ��������� ���
	if (lstream[playerid])
	{
		SvDeleteStream(lstream[playerid]);
		lstream[playerid] = SV_NULL;
	}
	//////////////////////////////////////////
	//����� ��������� ���
	#if defined _sampvoice_included
		if (lstream[playerid] != SV_NULL) {
			SvDeleteStream(lstream[playerid]);
			lstream[playerid] = SV_NULL;
		}
	#endif
}

////////////////////////////////////////////////
//����� ��������� ���
#if defined _sampvoice_included
public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid)
{
	if ((keyid == SV_KEY_B) && (lstream[playerid] != SV_NULL)){
		SvAttachSpeakerToStream(lstream[playerid], playerid);
	} else if ((keyid == SV_KEY_Z) && (gstream != SV_NULL)) {
		SvAttachSpeakerToStream(gstream, playerid);
	}
	return SV_VOID:1;
}

public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid, SV_UINT:keyid)
{
	if ((keyid == SV_KEY_B) && (lstream[playerid] != SV_NULL)) {
		SvDetachSpeakerFromStream(lstream[playerid], playerid);
	} else if ((keyid == SV_KEY_Z) && (gstream != SV_NULL)) {
        SvDetachSpeakerFromStream(gstream, playerid);
	}
	return SV_VOID:1;
}
#endif
//////////////////////////////////////////////////