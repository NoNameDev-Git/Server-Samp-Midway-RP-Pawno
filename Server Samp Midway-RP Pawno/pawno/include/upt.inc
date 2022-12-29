CMD:test(playerid)
{
    if(GetSVarInt("updateload"))
      SendClientMessage(playerid, -1, "Ошибка")
}
