#if defined _ah_included
	#endinput
#endif
#define _ah_included

#define callacmd::%0(%1) \
    ah_pc_cmd_%0(%1)


static const gSubfractionName[MAX_SUBFRACTIONS][3][MAX_SUBFRACTION_NAME_LENGTH] =
{
	{"Больница LS","Больница SF","Больница LV"},
	{"Армия LV","Армия SF",""},
	{"LSPD","SFPD","LVPD"},
	{"Мэрия ЛС", "Мэрия СФ", "Мэрия ЛВ"},
	{"Радиоцентр ЛС", "Радиоцентр СФ", "Радиоцентр ЛВ"}
};

public OnGameModeInit()
{
	CreateDynamicObject(18759, -1462.30591, -1435.13525, 1000.25378, 0.00000, 0.00000, 0.00000, 20, 5);
	gDemorgan = CreateDynamicSphere(-1462.3071, -1435.1337, 1001.2538, 40.0, 20, 5);
	CreateDynamic3DTextLabel("Деморган\n{FFFFFF}Для того чтобы посмотреть время до освобождения используйте {FF0000}/ptime", 0x00AC77FF, -1462.3071, -1435.1337, 1001.2538, 10.0, .worldid = 20, .interiorid = 5 );


    #if defined ah_OnGameModeInit
         return ah_OnGameModeInit();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit ah_OnGameModeInit
#if defined ah_OnGameModeInit
	forward ah_OnGameModeInit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
    temp_godmode_target[playerid] = INVALID_PLAYER_ID;
    temp_godmode_health[playerid] = 0.0;
    temp_godmode_armour[playerid] = 0.0;
    if(temp_godmode_timer[playerid])
        KillTimer(temp_godmode_timer[playerid]);

    #if defined ah_OnPlayerDisconnect
         return ah_OnPlayerDisconnect(playerid, reason);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect ah_OnPlayerDisconnect
#if defined ah_OnPlayerDisconnect
	forward ah_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
	if(areaid == gDemorgan)
	{
		if(PI[playerid][pPrison] == 4 && PI[playerid][pJailTime] > 0)
		{
		    SetPlayerPos(playerid, -1462.3071, -1435.1337, 1001.2538);
			J_SetPlayerFacingAngle(playerid, 84.6462);
		}
	}
    #if defined ah_OnPlayerLeaveDynamicArea
         return ah_OnPlayerLeaveDynamicArea(playerid, areaid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerLeaveDynamicArea
	#undef OnPlayerLeaveDynamicArea
#else
	#define _ALS_OnPlayerLeaveDynamicArea
#endif
#define OnPlayerLeaveDynamicArea ah_OnPlayerLeaveDynamicArea
#if defined ah_OnPlayerLeaveDynamicArea
	forward ah_OnPlayerLeaveDynamicArea(playerid, areaid);
#endif

CMD:saveacc(playerid)
{
	if(PI[playerid][pAdmin] < 7) return true;
	SaveAccAll();
	return true;
}

CMD:weap(playerid, params[])
{
    if(PI[playerid][pAdmin] < 1)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /weap [ID игрока]");

	if(!IsPlayerConnected(target) || playerid == target || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	new
		frmt_gun_list[140],
		frmt_guns[890],
		gun_name[32];

	format(frmt_gun_list, sizeof frmt_gun_list, "Игрок:\t\t\t%s\n\n", PN(target));
	strcat(frmt_guns, frmt_gun_list);
	for(new i = 0; i < 13; i++)
	{
		GetWeaponName(PI[target][pGuns][i], gun_name, 32);
		if(PI[target][pGuns][i] != 0)
		{
			format(frmt_gun_list, sizeof frmt_gun_list, "{FFFFFF}\nОружие:\t\t%s (%d)\nПатроны:\t\t%d", gun_name, PI[target][pGuns][i], PI[target][pAmmos][i]);
			strcat(frmt_guns, frmt_gun_list);
		}
	}
	AdminLog(PI[playerid][pID], PI[target][pID], "/weap");
	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Оружие игрока", frmt_guns, !"Закрыть", !"");
	return true;
}
#if defined _ALS_pc_cmd_weap
	#undef pc_cmd_weap
#else
	#define _ALS_pc_cmd_weap
#endif
#define pc_cmd_weap ah_pc_cmd_weap
#if defined ah_pc_cmd_weap
	forward ah_pc_cmd_weap(playerid);
#endif

CMD:a(playerid, params[])
{
	if(PI[playerid][pAdmin] < 1)
		return 1;

	extract params -> new string:text[128]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /a [текст]");

	if(strlen(text) > 120)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный текст");

	new
	    frmt_admin_chat[151];

	format(frmt_admin_chat, sizeof frmt_admin_chat, "[A] %s[%d]: %s", PN(playerid), playerid, text);
    SendAdminsMessage(0x007FFFFF, frmt_admin_chat);
	return true;
}
#if defined _ALS_pc_cmd_a
	#undef pc_cmd_a
#else
	#define _ALS_pc_cmd_a
#endif
#define pc_cmd_a ah_pc_cmd_a
#if defined ah_pc_cmd_a
	forward ah_pc_cmd_a(playerid);
#endif

CMD:ans(playerid, params[])
{
    if(PI[playerid][pAdmin] < 1)
		return 1;

	extract params -> new player:target, string:text[128]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /ans [ID игрока] [ответ]");

	if(strlen(text) > 100)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный текст");

	if(!IsPlayerConnected(target) || playerid == target || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	new
		frmt_admin_answer[191];

    format(frmt_admin_answer, sizeof frmt_admin_answer, "Администратор %s[%d] для %s[%d]: %s", PN(playerid), playerid, PN(target), target, text);
   	SendClientMessage(target, COLOR_ORANGE, frmt_admin_answer);
    SendAdminsMessage(COLOR_ORANGE, frmt_admin_answer);
    return true;
}
#if defined _ALS_pc_cmd_ans
	#undef pc_cmd_ans
#else
	#define _ALS_pc_cmd_ans
#endif
#define pc_cmd_ans ah_pc_cmd_ans
#if defined ah_pc_cmd_ans
	forward ah_pc_cmd_ans(playerid);
#endif

CMD:admins(playerid)
{
    if(PI[playerid][pAdmin] < 1)
		return 1;

	new
		frmt_admin_list[2048],
		admins,
		frmt_admin_played[80];

	foreach(new i : Connect_Admin)
	{
		if(!IsPlayerConnected(i) || !PI[i][pAdmin] || PI[i][pAdmin] > 5)
			continue;

		admins++;
	}

	format(frmt_admin_list, sizeof frmt_admin_list, "Администрация онлайн: (%d)", admins);
	SendClientMessage(playerid, COLOR_GREEN, frmt_admin_list);
	foreach(new i : Connect_Admin)
	{
		if(!IsPlayerConnected(i) || !IsPlayerLogged[i] || IsPlayerNPC(i) || !PI[i][pAdmin] || PI[i][pAdmin] > 5)
			continue;

		if(pl_afk_time[i] >= 3)
		{
			if(PI[i][pSpectating])
				format(frmt_admin_list, sizeof frmt_admin_list, "%s[%d] (%d) {FF9900}[SP: %d] [AFK: %s]", PN(i), i, PI[i][pAdmin], PI[i][pSpectatee], Convert(pl_afk_time[i]));

			else
				format(frmt_admin_list, sizeof frmt_admin_list, "%s[%d] (%d) {FF9900}[AFK: %s]", PN(i), i, PI[i][pAdmin], Convert(pl_afk_time[i]));
		}
		else
		{
			if(PI[i][pSpectating])
				format(frmt_admin_list, sizeof frmt_admin_list, "%s[%d] (%d) {FF9900}[SP: %d]", PN(i), i, PI[i][pAdmin], PI[i][pSpectatee]);

			else
				format(frmt_admin_list, sizeof frmt_admin_list, "%s[%d] (%d)", PN(i), i, PI[i][pAdmin]);
		}
		SendClientMessage(playerid, COLOR_WHITE, frmt_admin_list);
	}
	format(frmt_admin_played, sizeof frmt_admin_played, "Время администрирования за сегодня: %d %s", PI[playerid][pAdminTime], Declension_GetMinutes(PI[playerid][pAdminTime]));
	SendClientMessage(playerid, COLOR_YELLOW, frmt_admin_played);

	return true;
}
#if defined _ALS_pc_cmd_admins
	#undef pc_cmd_admins
#else
	#define _ALS_pc_cmd_admins
#endif
#define pc_cmd_admins ah_pc_cmd_admins
#if defined ah_pc_cmd_admins
	forward ah_pc_cmd_admins(playerid);
#endif

CMD:settext(playerid, params[])
{
  	if(PI[playerid][pAdmin] < 1)
	  	return 1;

    if(temp_settext[playerid])
	{
		for(new td; td < 8; td++)
			TextDrawHideForPlayer(playerid, tdCapture[td]);

		for(new td; td < 8; td++)
			TextDrawHideForPlayer(playerid, tdBizWar[td]);

        temp_settext[playerid] = 0;
		SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы выключили отображение каптов / боев за бизнесов");
		return true;
	}

	extract params -> new type; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}/settext [1-2] (1 - капты / 2 - бизнесы)");

	if(type < 1 || type > 2)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный параметр");

    if(type == 1)
    {
        if(IsCapture == 1)
        {
	 		for(new td; td < 8; td++)
				TextDrawShowForPlayer(playerid, tdCapture[td]);
		}

		temp_settext[playerid] = type;
		SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы включили отображение таблички каптов");
	}
	else if(type == 2)
	{
        if(IsBizWar == 2)
        {
	 		for(new td; td < 8; td++)
				TextDrawShowForPlayer(playerid, tdBizWar[td]);
		}

		temp_settext[playerid] = type;
		SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы включили отображение таблички боев за бизнес");
	}
	return true;
}
#if defined _ALS_pc_cmd_settext
	#undef pc_cmd_settext
#else
	#define _ALS_pc_cmd_settext
#endif
#define pc_cmd_settext ah_pc_cmd_settext
#if defined ah_pc_cmd_settext
	forward ah_pc_cmd_settext(playerid);
#endif

CMD:spawn(playerid, params[])
{
    if(PI[playerid][pAdmin] < 1)
		return 1;

	if(PI[playerid][pAdmin] >= 4)
	{
	    new
	        target;

		if(sscanf(params, "D(-1)", target))
			return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}/spawn [ID игрока]");

		if(target == -1)
		{
		    if(PI[playerid][pSpectating])
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы находитесь в наблюдении");

		    return SpawnPlayer(playerid);
		}

		if(!IsPlayerConnected(target) || !IsPlayerLogged[target])
			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

		if(!PI[target][pID] || !IsPlayerLogged[target])
			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

		if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	    if(PI[target][pSpectating])
			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок находится в наблюдении");

	    SpawnPlayer(target);
	    AdminLog(PI[playerid][pID], PI[target][pID], "/spawn");
        SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы зареспавнили игрока");
	    new string[144];
	    format(string, sizeof(string), "[A] %s заспавнил игрока %s", PN(playerid), PN(target));
	    SendAdminsMessage(COLOR_GREY, string);
	}
	else
	{
	    if(PI[playerid][pSpectating])
			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы находитесь в наблюдении");

	    SpawnPlayer(playerid);
	}
	return true;
}
#if defined _ALS_pc_cmd_spawn
	#undef pc_cmd_spawn
#else
	#define _ALS_pc_cmd_spawn
#endif
#define pc_cmd_spawn ah_pc_cmd_spawn
#if defined ah_pc_cmd_spawn
	forward ah_pc_cmd_spawn(playerid);
#endif

CMD:kick(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new player:target, string:text[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /kick [ID игрока] [Причина]");

	if(strlen(text) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(PI[target][pAdmin] >= 7)
	{
		new
			frmt_kick_admin[150];

		format(frmt_kick_admin, sizeof frmt_kick_admin, "[A] %s попытался кикнуть Администратора %s", PN(playerid), PN(target));
 		SendAdminsMessage(COLOR_GREY, frmt_kick_admin);
 		return 1;
	}

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
		frmt_kick_text[189];

	format(frmt_kick_text, sizeof frmt_kick_text, "Администратор %s кикнул игрока %s. Причина: %s", PN(playerid), PN(target), text);
	ASCMTA(COLOR_LIGHTRED, frmt_kick_text);

	AdminLog(PI[playerid][pID], PI[target][pID], "/kick");

	J_Kick(target);
	return true;
}
#if defined _ALS_pc_cmd_kick
	#undef pc_cmd_kick
#else
	#define _ALS_pc_cmd_kick
#endif
#define pc_cmd_kick ah_pc_cmd_kick
#if defined ah_pc_cmd_kick
	forward ah_pc_cmd_kick(playerid);
#endif

CMD:mute(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new player:target, time, string:text[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /mute [ID игрока] [Время (в минутах)] [Причина]");

	if(strlen(text) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(time < 10 || time > 180)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Введите время от 10 до 180 минут");

	if(PI[target][pMuteTime] > 0)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Данный игрок уже имеет бан чата");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    PI[target][pMuteTime] = time*60;
    UpdatePlayerData(target, "MuteTime", PI[target][pMuteTime]);

	new
		frmt_mute_text[232];

	format(frmt_mute_text, sizeof frmt_mute_text, "Администратор %s выдал бан чата игроку %s на %d %s. Причина: %s", PN(playerid), PN(target), time, Declension_GetMinutesEx(time), text);
	ASCMTA(COLOR_LIGHTRED, frmt_mute_text);
	format(frmt_mute_text, sizeof frmt_mute_text, "Администратор %s выдал Вам бан чата на %d %s. Причина: %s", PN(playerid), time, Declension_GetMinutesEx(time), text);
	SendClientMessage(target, COLOR_LIGHTRED, frmt_mute_text);

	AdminLog(PI[playerid][pID], PI[target][pID], "/mute");
	return true;
}
#if defined _ALS_pc_cmd_mute
	#undef pc_cmd_mute
#else
	#define _ALS_pc_cmd_mute
#endif
#define pc_cmd_mute ah_pc_cmd_mute
#if defined ah_pc_cmd_mute
	forward ah_pc_cmd_mute(playerid);
#endif

CMD:unmute(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /unmute [ID игрока]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pMuteTime] == 0)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Данный игрок не имеет бана чата");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    PI[target][pMuteTime] = 0;
    UpdatePlayerData(target, "MuteTime", PI[target][pMuteTime]);

	new
		frmt_unmute_text[110];

	format(frmt_unmute_text, sizeof frmt_unmute_text, "Администратор %s снял бан чата игроку %s", PN(playerid), PN(target));
	ASCMTA(COLOR_LIGHTRED, frmt_unmute_text);
	format(frmt_unmute_text, sizeof frmt_unmute_text, "Администратор %s снял Вам бан чата", PN(playerid));
	SendClientMessage(target, COLOR_LIGHTRED, frmt_unmute_text);

	AdminLog(PI[playerid][pID], PI[target][pID], "/unmute");
	return true;
}
#if defined _ALS_pc_cmd_unmute
	#undef pc_cmd_unmute
#else
	#define _ALS_pc_cmd_unmute
#endif
#define pc_cmd_unmute ah_pc_cmd_unmute
#if defined ah_pc_cmd_unmute
	forward ah_pc_cmd_unmute(playerid);
#endif

CMD:money(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /money [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
	    frmt_money_info[1000];

	if(PI[target][pBizKey] < 1000 && PI[target][pBizKey] != 0)
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d\nБизнес:\t%d$", PI[target][pMoney], PI[target][pBank], PI[target][pLevel], PI[target][pVirMoney], BizInfo[PI[target][pBizKey]-1][bMoney]);

	else if(PI[target][pBizKey] > 1000 && PI[target][pBizKey] != 0)
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d\nБизнес:\t%d$", PI[target][pMoney], PI[target][pBank], PI[target][pLevel], PI[target][pVirMoney], gFillings[PI[target][pBizKey]-1001][fillingBank]);

	else
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d", PI[target][pMoney], PI[target][pBank], PI[target][pLevel], PI[target][pVirMoney]);

	if(PI[target][pBankCount])
	{
	    strcat(frmt_money_info, "\n\nСчет\t\tДеньги");

	    new
	        query_get_bank[90],
			frmt_bank_list[300],
			id,
			name_bank[250],
			money;

		format(query_get_bank, sizeof query_get_bank, "SELECT `id`, `name`, `money` FROM `bank` WHERE `ownerid` = '%d'", PI[target][pID]);
		new Cache:result = mysql_query(mysql, query_get_bank);


		for(new i; i < cache_get_row_count(mysql); i++)
		{
			id = cache_get_row_int(i, 0);
			cache_get_row(i, 1, name_bank, mysql, sizeof name_bank);
            money = cache_get_row_int(i, 2);
			format(frmt_bank_list, sizeof frmt_bank_list, "\n%d. %s{FFFFFF}\t\t%d$", id, name_bank, money);
			strcat(frmt_money_info, frmt_bank_list);
		}
		cache_delete(result, mysql);
	}
	AdminLog(PI[playerid][pID], PI[target][pID], "/money (/offmoney)");
	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, PN(target), frmt_money_info, !"Закрыть", !"");
	return true;
}


CMD:offmoney(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /offmoney [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
	    new getid[6];
	    format(getid, sizeof getid, "%d", GetPlayerID(nick));
		callcmd::money(playerid, getid);
		return 1;
	}

	new
		nickname[MAX_PLAYER_NAME+1],
		frmt_offmoney_check[180];

	mysql_escape_string(nick, nickname);

	format(frmt_offmoney_check, sizeof frmt_offmoney_check, "SELECT `ID`, `Money`, `Bank`, `BizKey`, `BankCount`, `Level`, `VirMoney`, `Admin` FROM `accounts` WHERE `NickName` = '%s'",nickname);
	new Cache:result = mysql_query(mysql, frmt_offmoney_check);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}
	new
	    id,
	    money,
	    bank,
	    bizkey,
		bankcount,
		level,
		virmoney,
		admin;

 	id = cache_get_row_int(0, 0);
	money = cache_get_row_int(0, 1);
	bank = cache_get_row_int(0, 2);
	bizkey = cache_get_row_int(0, 3);
	bankcount = cache_get_row_int(0, 4);
	level = cache_get_row_int(0, 5);
	virmoney = cache_get_row_int(0, 6);
	admin = cache_get_row_int(0, 7);

	cache_delete(result, mysql);

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
	    frmt_money_info[1000];

	if(bizkey < 1000 && bizkey != 0)
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d\nБизнес:\t%d$", money, bank, level, virmoney, BizInfo[bizkey-1][bMoney]);

	else if(bizkey > 1000 && bizkey != 0)
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d\nБизнес:\t%d$", money, bank, level, virmoney, gFillings[bizkey-1001][fillingBank]);

	else
		format(frmt_money_info, sizeof frmt_money_info, "{FFFFFF}Наличные:\t%d$\nБанк:\t\t%d$\nУровень:\t%d\nДонат:\t\t%d", money, bank, level, virmoney);

	if(bankcount)
	{
	    strcat(frmt_money_info, "\n\nСчет\t\tДеньги");

	    new
	        query_get_bank[90],
			frmt_bank_list[300],
			bankid,
			name_bank[250],
			bankmoney;

		format(query_get_bank, sizeof query_get_bank, "SELECT `id`, `name`, `money` FROM `bank` WHERE `ownerid` = '%d'", id);
		new Cache:b_result = mysql_query(mysql, query_get_bank);


		for(new i; i < cache_get_row_count(mysql); i++)
		{
			bankid = cache_get_row_int(i, 0);
			cache_get_row(i, 1, name_bank, mysql, sizeof name_bank);
            bankmoney = cache_get_row_int(i, 2);
			format(frmt_bank_list, sizeof frmt_bank_list, "\n%d. %s{FFFFFF}\t\t%d$", bankid, name_bank, bankmoney);
			strcat(frmt_money_info, frmt_bank_list);
		}
		cache_delete(b_result, mysql);
	}
	AdminLog(PI[playerid][pID], id, "/money (/offmoney)");
	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, nickname, frmt_money_info, !"Закрыть", !"");
	return true;
}
#if defined _ALS_pc_cmd_offmoney
	#undef pc_cmd_offmoney
#else
	#define _ALS_pc_cmd_offmoney
#endif
#define pc_cmd_offmoney ah_pc_cmd_offmoney
#if defined ah_pc_cmd_offmoney
	forward ah_pc_cmd_offmoney(playerid);
#endif

CMD:gm(playerid, params[])
{
    if(PI[playerid][pAdmin] < 2)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /gm [ID игрока]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    new
		Float:boomx,
		Float:boomy,
		Float:boomz;

    GetPlayerPos(target, boomx, boomy, boomz);
    GetPlayerHealth(target, temp_godmode_health[playerid]);

	temp_godmode_target[playerid] = target;

	CreateExplosion(boomx, boomy, boomz+7, 5, 0.5);
	GetPlayerArmour(target, temp_godmode_armour[playerid]);
	SetPlayerArmour(target, 0);
 	temp_godmode_timer[playerid] = SetTimerEx("@__godmode_test", 1000, false, "d", playerid);
 	AdminLog(PI[playerid][pID], PI[target][pID], "/gm");
	return true;
}
#if defined _ALS_pc_cmd_gm
	#undef pc_cmd_gm
#else
	#define _ALS_pc_cmd_gm
#endif
#define pc_cmd_gm ah_pc_cmd_gm
#if defined ah_pc_cmd_gm
	forward ah_pc_cmd_gm(playerid);
#endif

CMD:stats(playerid, params[])
{
	new target;

	if(sscanf(params, "u", target))
		target = playerid;

	if(target != playerid && PI[playerid][pAdmin] < 2)
		return 1;

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    ShowStats(playerid, target);
    if(PI[playerid][pAdmin]) AdminLog(PI[playerid][pID], PI[target][pID], "/stats");
	return true;
}


CMD:respawn(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	if(IsPlayerInAnyVehicle(playerid))
	{
	    SetVehicleToRespawnEx(GetPlayerVehicleID(playerid));
	    return 1;
	}

	extract params -> new vehicleid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /respawn [ID транспорта]");

	new
		model = GetVehicleModel(vehicleid);

	if(0 == model)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID транспорта");

	SetVehicleToRespawnEx(vehicleid);
	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы успешно зареспавнили введенный транспорт");
	return true;
}
#if defined _ALS_pc_cmd_respawn
	#undef pc_cmd_respawn
#else
	#define _ALS_pc_cmd_respawn
#endif
#define pc_cmd_respawn ah_pc_cmd_respawn
#if defined ah_pc_cmd_respawn
	forward ah_pc_cmd_respawn(playerid);
#endif

CMD:fv(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	if(IsPlayerInAnyVehicle(playerid))
	{
		J_SetVehicleHealth(GetPlayerVehicleID(playerid), 1000.0);
		J_RepairVehicle(GetPlayerVehicleID(playerid));
		return 1;
	}

	extract params -> new vehicleid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /fv [ID транспорта]");

	new
		model = GetVehicleModel(vehicleid);

	if(0 == model)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID транспорта");

	J_SetVehicleHealth(vehicleid, 1000.0);
	J_RepairVehicle(vehicleid);
	return true;
}
#if defined _ALS_pc_cmd_fv
	#undef pc_cmd_fv
#else
	#define _ALS_pc_cmd_fv
#endif
#define pc_cmd_fv ah_pc_cmd_fv
#if defined ah_pc_cmd_fv
	forward ah_pc_cmd_fv(playerid);
#endif

CMD:setfuel(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	if(IsPlayerInAnyVehicle(playerid))
	{
		VehicleInfo[GetPlayerVehicleID(playerid)][vFuel] = Transport[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400][trTank];
		return 1;
	}

	extract params -> new vehicleid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /setfuel [ID транспорта]");

	new
		model = GetVehicleModel(vehicleid);

	if(0 == model)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID транспорта");

	VehicleInfo[vehicleid][vFuel] = Transport[model - 400][trTank];

	for(new i; i < sizeof CarInfo; i ++)
	{
		if(CarInfo[i][cVehID] != vehicleid)
			continue;

		CarInfo[i][cFuel] = Transport[model - 400][trTank];
		break;
	}
	SendClientMessage(playerid,-1,"Вы заправили ТС");
	return true;
}
#if defined _ALS_pc_cmd_setfuel
	#undef pc_cmd_setfuel
#else
	#define _ALS_pc_cmd_setfuel
#endif
#define pc_cmd_setfuel ah_pc_cmd_setfuel
#if defined ah_pc_cmd_setfuel
	forward ah_pc_cmd_setfuel(playerid);
#endif

CMD:skick(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /skick [ID игрока]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(PI[target][pAdmin] >= 7)
	{
		new
			frmt_kick_admin[150];

		format(frmt_kick_admin, sizeof frmt_kick_admin, "[A] %s попытался тихо кикнуть Администратора %s", PN(playerid), PN(target));
 		SendAdminsMessage(COLOR_GREY, frmt_kick_admin);
 		return 1;
	}

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
		frmt_skick_text[100];

	format(frmt_skick_text, sizeof frmt_skick_text, "[A] %s тихо кикнул игрока %s", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_skick_text);
    AdminLog(PI[playerid][pID], PI[target][pID], "/skick");
	J_Kick(target);
	return true;
}
#if defined _ALS_pc_cmd_skick
	#undef pc_cmd_skick
#else
	#define _ALS_pc_cmd_skick
#endif
#define pc_cmd_skick ah_pc_cmd_skick
#if defined ah_pc_cmd_skick
	forward ah_pc_cmd_skick(playerid);
#endif

CMD:jail(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target, time, string:text[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /jail [ID игрока] [Время] [Причина]");

	if(strlen(text) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(time < 1 || time > 360)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Введите время от 1 до 360 минут");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	if(PI[target][pJailTime] > 0)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок уже в тюрьме");


    if(temp_cuffer_sender[target] != INVALID_PLAYER_ID)
    {
        new
			cufferid = temp_cuffer_sender[target]-1;

        SetPlayerSpecialAction(target, SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(target, 0);
        temp_cuffer_sender[target] = INVALID_PLAYER_ID;
        temp_cuffer_receiver[cufferid] = INVALID_PLAYER_ID;
    }
	if(GotoInfo[playerid][gtID] != INVALID_PLAYER_ID)
	{
	    CheckPlayerGoCuff(target);
		CheckPlayerGoCuff(playerid);
	}

    PI[target][pJailTime] = time*60;
    UpdatePlayerData(target, "JailTime", PI[target][pJailTime]);
    PI[target][pWanted] = 0;
    UpdatePlayerData(target, "Wanted", PI[target][pWanted]);
    SetPlayerWantedLevel(target, 0);
    PI[target][pJailAdmin] = 1;
    UpdatePlayerData(target, "JailAdmin", PI[target][pJailAdmin]);

    if(temp_table[playerid] != -1)
    {
       new table = temp_table[playerid];

       gTable[table][tCrup] = INVALID_PLAYER_ID;
       temp_table[playerid] = -1;

    }
    SetPlayerVirtualWorld(target, 20);
	SetPlayerInterior(target, 5);

    ResetPlayerWeapons(target);
    SetPlayerSkinEx(target, 42);
    PlayerPlaySound(target, 17004, 0.0, 0.0, 0.0);
    SetPlayerPos(target, -1462.3071, -1435.1337, 1001.2538);
	J_SetPlayerFacingAngle(target, 84.6462);
    PI[target][pPrison] = 4;
    UpdatePlayerData(target, "Prison", PI[target][pPrison]);

	new
	    frmt_jail_message[210];

	format(frmt_jail_message, sizeof frmt_jail_message, "Администратор %s посадил Вас в тюрьму на %d %s. Причина: %s", PN(playerid), time, Declension_GetMinutesEx(time), text);
	SendClientMessage(target, COLOR_LIGHTRED, frmt_jail_message);

    SendClientMessage(target, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Чтобы посмотреть сколько Вам осталось сидеть в тюрьме, введите команду {FFFF00}/ptime");

	format(frmt_jail_message, sizeof frmt_jail_message, "[A] %s посадил %s в тюрьму на %d %s. Причина: %s", PN(playerid), PN(target), time, Declension_GetMinutesEx(time), text);
	SendAdminsMessage(COLOR_GREY, frmt_jail_message);
	AdminLog(PI[playerid][pID], PI[target][pID], "/jail");
	return true;
}
#if defined _ALS_pc_cmd_jail
	#undef pc_cmd_jail
#else
	#define _ALS_pc_cmd_jail
#endif
#define pc_cmd_jail ah_pc_cmd_jail
#if defined ah_pc_cmd_jail
	forward ah_pc_cmd_jail(playerid);
#endif

CMD:unjail(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /unjail [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	if(PI[target][pJailTime] <= 0)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не в тюрьме");


	if(!PI[target][pJailAdmin])
	{
		new
			prison = PI[target][pPrison]-1;

		SetPlayerSkinEx(target, GetSkinOfPlayer(target));
		SetPlayerInterior(target, 0);
		SetPlayerVirtualWorld(target, 0);
		SetPlayerPos(target, gJailExit[prison][0], gJailExit[prison][1], gJailExit[prison][2]);
		J_SetPlayerFacingAngle(target, gJailExit[prison][3]);
	}
	else
	    SpawnPlayer(target);

    PI[target][pPrison] = 0;
    UpdatePlayerData(target, "Prison", PI[target][pPrison]);
    PI[target][pJailTime] = 0;
    UpdatePlayerData(target, "JailTime", PI[target][pJailTime]);
    PI[target][pWanted] = 0;
    UpdatePlayerData(target, "Wanted", PI[target][pWanted]);
    SetPlayerWantedLevel(target, 0);
    PI[target][pJailAdmin] = 0;
    UpdatePlayerData(target, "JailAdmin", PI[target][pJailAdmin]);

    ResetPlayerWeapons(target);


	new
	    frmt_jail_message[210];

	format(frmt_jail_message, sizeof frmt_jail_message, "Администратор %s выпустил Вас из тюрьмы", PN(playerid));
	SendClientMessage(target, COLOR_LIGHTRED, frmt_jail_message);

	format(frmt_jail_message, sizeof frmt_jail_message, "[A] %s выпустил %s из тюрьмы", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_jail_message);
	AdminLog(PI[playerid][pID], PI[target][pID], "/unjail");
	return true;
}
#if defined _ALS_pc_cmd_unjail
	#undef pc_cmd_unjail
#else
	#define _ALS_pc_cmd_unjail
#endif
#define pc_cmd_unjail ah_pc_cmd_unjail
#if defined ah_pc_cmd_unjail
	forward ah_pc_cmd_unjail(playerid);
#endif

CMD:get(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /get [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
	    reg_country[90],
	    reg_city[90],
	 	last_country[90],
	 	last_city[90],
 		frmt_get[390];

	GetIPCountry(PlayerIp[target], last_country, sizeof(last_country));
	GetIPCity(PlayerIp[target], last_city, sizeof(last_city));
	GetIPCountry(PlayerRegIP[target], reg_country, sizeof(reg_country));
	GetIPCity(PlayerRegIP[target], reg_city, sizeof(reg_city));

	format(frmt_get, sizeof frmt_get, "{FFFFFF}\
	Номер аккаунта:\t\t%d\n\
	Наличные:\t\t\t%d$\n\
	Осн. банк счёт:\t\t\t%d$\n\
	Уровень:\t\t\t%d\n\
	IP адрес(регис.):\t\t%s (%s %s)\n\
	IP адрес(послед.):\t\t%s (%s %s)\n\
	Дата регистрации:\t\t%s\n\
	Донат:\t\t\t\t%d",
	PI[target][pID], PI[target][pMoney], PI[target][pBank], PI[target][pLevel],
	PlayerRegIP[target], reg_country, reg_city, PlayerIp[target], last_country, last_city,
	PI[target][pDateReg], PI[target][pVirMoney]);

	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, PN(target), frmt_get, !"Закрыть", !"");
	AdminLog(PI[playerid][pID], PI[target][pID], "/get (/offget)");
	return true;
}

CMD:num(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4) return 1;
    new idacca;
    if(sscanf(params, "i", idacca)) return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /num [id аккаунта]");
    totalstring[0] = 0;
    format(totalstring, 350, "SELECT `Money`,`Bank`,`Level`,`RegIP`,`LastIP`,`DateReg`,`VirMoney`,`Admin`,`LastLogin`,`BanActivate` FROM `accounts` WHERE `ID` = '%d'", idacca);
    mysql_tquery(mysql, totalstring, "@OnPlayerIdAcca", "ii", playerid, idacca);
    totalstring[0] = 0;
    return 1;
}
CMD:offget(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /offget [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
	    new getid[6];
	    format(getid, sizeof getid, "%d", GetPlayerID(nick));
		callcmd::get(playerid, getid);
		return 1;
	}

	new
		nickname[MAX_PLAYER_NAME+1],
		frmt_offget_check[180];

	mysql_escape_string(nick, nickname);

	format(frmt_offget_check, sizeof frmt_offget_check, "SELECT `ID`, `Money`, `Bank`, `Level`, `RegIP`, `OldIP`, `DateReg`, `VirMoney`, `Admin` FROM `accounts` WHERE `NickName` = '%s'",nickname);
	new Cache:result = mysql_query(mysql, frmt_offget_check);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
	    id,
	    money,
	    bank,
	    level,
		regip[16],
		oldip[16],
		datereg[25],
		virmoney,
		admin;

 	id = cache_get_row_int(0, 0);
	money = cache_get_row_int(0, 1);
	bank = cache_get_row_int(0, 2);
	level = cache_get_row_int(0, 3);
	cache_get_row(0, 4, regip, mysql);
	cache_get_row(0, 5, oldip, mysql);
	cache_get_row(0, 6, datereg, mysql);
	virmoney = cache_get_row_int(0, 7);
	admin = cache_get_row_int(0, 8);

	cache_delete(result, mysql);

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");


	new
	    reg_country[90],
	    reg_city[90],
	 	last_country[90],
	 	last_city[90],
 		frmt_get[390];

	GetIPCountry(oldip, last_country, sizeof(last_country));
	GetIPCity(oldip, last_city, sizeof(last_city));
	GetIPCountry(regip, reg_country, sizeof(reg_country));
	GetIPCity(regip, reg_city, sizeof(reg_city));

	format(frmt_get, sizeof frmt_get, "{FFFFFF}\
	Номер аккаунта:\t\t%d\n\
	Наличные:\t\t\t%d$\n\
	Осн. банк счёт:\t\t\t%d$\n\
	Уровень:\t\t\t%d\n\
	IP адрес(регис.):\t\t%s (%s %s)\n\
	IP адрес(послед.):\t\t%s (%s %s)\n\
	Дата регистрации:\t\t%s\n\
	Донат:\t\t\t\t%d",
	id, money, bank, level, regip, reg_country, reg_city, oldip, last_country, last_city, datereg, virmoney);

	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, nickname, frmt_get, !"Закрыть", !"");
	AdminLog(PI[playerid][pID], id, "/get (/offget)");
	return true;
}
#if defined _ALS_pc_cmd_offget
	#undef pc_cmd_offget
#else
	#define _ALS_pc_cmd_offget
#endif
#define pc_cmd_offget ah_pc_cmd_offget
#if defined ah_pc_cmd_offget
	forward ah_pc_cmd_offget(playerid);
#endif

CMD:offstats(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /offstats [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
	    new getid[6];
	    format(getid, sizeof getid, "%d", GetPlayerID(nick));
		callcmd::stats(playerid, getid);
		return 1;
	}

	new
		nickname[MAX_PLAYER_NAME+1],
		frmt_offget_check[425];

	mysql_escape_string(nick, nickname);

	format(frmt_offget_check, sizeof frmt_offget_check, "SELECT `ID`, `Level`, `Exp`, `Warns`, `TelNum`, `In_Skill`, `ZKP`, `Wanted`, `Drugs`, `Mats`, `Packets`, `Age`, `Sex`, `Merrit`, `Nation`, \
														`Fraction`, `Rank`, `Subfraction`, `Job`, `FWarns`, `V_Fraction`, `V_Rank`, `V_Subfraction`, `V_Days`, `v_FWarns`, `HouseKey`, `BizKey`, `Tester`, `Admin` \
														FROM `accounts` WHERE `NickName` = '%s'", nickname);

	new Cache:result = mysql_query(mysql, frmt_offget_check);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}
	new
	    id,
	    level,
	    exp,
	    warns,
	    telnum,
	    in_skill,
	    zkp,
	    wanted,
	    drugs,
	    mats,
	    packets,
	    age,
	    sex,
	    merrit,
	    nationn,
	    fraction_id,
	    rank_id,
	    subfraction_id,
		fwarns,
		job_id,
		vfraction_id,
		vrank_id,
		vsubfraction_id,
		vdays,
		vwarns,
		housekey,
		bizkey,
		tester,
		admin;

 	id = cache_get_row_int(0, 0);
	level = cache_get_row_int(0, 1);
    exp = cache_get_row_int(0, 2);
	warns = cache_get_row_int(0, 3);
	telnum = cache_get_row_int(0, 4);
	in_skill = cache_get_row_int(0, 5);
	zkp = cache_get_row_int(0, 6);
    wanted = cache_get_row_int(0, 7);
    drugs = cache_get_row_int(0, 8);
    mats = cache_get_row_int(0, 9);
    packets = cache_get_row_int(0, 10);
    age = cache_get_row_int(0, 11);
    sex = cache_get_row_int(0, 12);
	merrit = cache_get_row_int(0, 13);
    nationn = cache_get_row_int(0, 14);
    fraction_id = cache_get_row_int(0, 15);
    rank_id = cache_get_row_int(0, 16);
    subfraction_id = cache_get_row_int(0, 17);
    job_id = cache_get_row_int(0, 18);
    fwarns = cache_get_row_int(0, 19);
    vfraction_id = cache_get_row_int(0, 20);
    vrank_id = cache_get_row_int(0, 21);
    vsubfraction_id = cache_get_row_int(0, 22);
    vdays = cache_get_row_int(0, 23);
    vwarns = cache_get_row_int(0, 24);
    housekey = cache_get_row_int(0, 25);
    bizkey = cache_get_row_int(0, 26);
    tester = cache_get_row_int(0, 27);
 	admin = cache_get_row_int(0, 28);

	cache_delete(result, mysql);

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
		stats_string[1200],
		mes_stats[2300],
		nation[20],
		fraction[32],
		job[70],
		houseinfo[45],
		bizinfo[40],
		classname[14],
		married[MAX_PLAYER_NAME+1],
		year,
		month,
		day,
		hour,
		minute,
		second;

	getdate(year, month, day);
	gettime(hour,minute,second);

 	if(!merrit) format(married,sizeof(married),"Отсутствует");
	else GetPlayerNameByID(merrit, married);

    switch(nationn)
	{
		case 1: strcat(nation,"Американец");
		case 2: strcat(nation,"Русский");
		case 3: strcat(nation,"Француз");
		case 4: strcat(nation,"Мексиканец");
		case 5: strcat(nation,"Латиноамериканец");
		case 6: strcat(nation,"Испанец");
		case 7: strcat(nation,"Португалец");
		case 8: strcat(nation,"Японец");
		case 9: strcat(nation,"Итальянец");
		case 10: strcat(nation,"Англичанин");
	}

	if(job_id && !fraction_id) format(job, 32, "%s", GetJobName(job_id));
	if(!job_id && !fraction_id && !vfraction_id) format(job, 32, "Отсутствует");

 	if(fraction_id)
	{
		new fractionid = fraction_id-1;
		new rank = rank_id;
		strcat(fraction, gFractionName[fractionid]);
		if(subfraction_id > 0)
		{
			new frid = GetSubfractionID(fractionid+1);
			new subid = subfraction_id-1;
			strcat(job, gSubfractionName[frid][subid]);
			strcat(job, " / ");
		}
		if(fractionid+1 == 10 && !subfraction_id && rank <= 9)
			strcat(job, gPrezRankName[rank-1]);

		else strcat(job,gFractionRankName[fractionid][rank-1]);
	}
 	else if(vfraction_id)
	{
		new fractionid = vfraction_id-1;
		new rank = vrank_id;
		strcat(fraction, gFractionName[fractionid]);
		if(vsubfraction_id > 0)
		{
			new frid = GetSubfractionID(fractionid+1);
			new subid = vsubfraction_id-1;
			strcat(job, gSubfractionName[frid][subid]);
			strcat(job, " / ");
		}
		if(fractionid+1 == 10 && !vsubfraction_id && rank <= 9)
			strcat(job, gPrezRankName[rank-1]);

		else strcat(job,gFractionRankName[fractionid][rank-1]);
	}
	else format(fraction, 32, "Отсутствует");

	if(housekey != 0)
	{
		switch(HouseInfo[housekey-1][hLevel])
		{
			case 0:classname = "[Эконом]";
			case 1:classname = "[Cредний]";
			case 2:classname = "[Элитный]";
			case 3:classname = "[Особняк]";
			default: classname = "[Неизвестно]";
		}
		format(houseinfo,sizeof(houseinfo), "%d %s", housekey, classname);
	}
	else format(houseinfo,sizeof(houseinfo), "\tОтсутствует");

	if(bizkey != 0)
	{
	    new
	        bizid = bizkey;

		if(bizid > 1000)
		    format(bizinfo, sizeof bizinfo, "АЗС №%d", bizid-1000);

		else
			format(bizinfo, sizeof(bizinfo), "%s (%d)", BizInfo[bizid-1][bName], bizid);
	}
	else
		format(bizinfo, sizeof(bizinfo), "Отсутствует");

	if(tester)
	{
	    format(mes_stats,sizeof(mes_stats),"{FFF312}Тестер проекта\n\n");
		strcat(stats_string,mes_stats);
	}
    format(mes_stats,sizeof(mes_stats),"{FFFFFF}Номер аккаунта:\t\t{0099ff}%d\n", id);
	strcat(stats_string,mes_stats);
 	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Имя:\t\t\t\t{0099ff}%s\n", nickname);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Уровень:\t\t\t{0099ff}%d\n", level);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Очки опыта:\t\t\t{0099ff}%d из %d\n", exp, (level+1)*4);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Предупреждений:\t\t{0099ff}%d\n\n", warns);
	strcat(stats_string,mes_stats);

	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Номер телефона:\t\t{0099ff}%d\n", telnum);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}На счету телефона:\t\t{0099ff}%d\n\n", in_skill);
	strcat(stats_string,mes_stats);

	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Законопослушность:\t\t{0099ff}%d\n", zkp);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Уровень розыска:\t\t{0099ff}%d\n", wanted);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Наркотиков:\t\t\t{0099ff}%d гр.\n", drugs);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Патроны:\t\t\t{0099ff}%d\n", mats);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Ед. Оружия:\t\t\t{0099ff}%d\n\n", packets);
	strcat(stats_string,mes_stats);

	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Пол:\t\t\t\t{0099ff}%s\n", (sex == 1) ? ("Мужской") : ("Женский"));
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Возраст:\t\t\t{0099ff}%d\n", age);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Муж/Жена:\t\t\t{0099ff}%s\n", married);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Национальность:\t\t\t{0099ff}%s\n\n", nation);
	strcat(stats_string,mes_stats);

	if(!vdays)
	{
		format(mes_stats,sizeof(mes_stats),"{FFFFFF}Организация:\t\t\t{0099ff}%s\n", fraction);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{FFFFFF}Работа/Должность:\t\t{0099ff}%s\n", job);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{FFFFFF}Ранг:\t\t\t\t{0099ff}%d\n", rank_id);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{FFFFFF}Выговоров:\t\t\t\t{0099ff}%d\n\n", fwarns);
		strcat(stats_string,mes_stats);
	}
	else
	{
		format(mes_stats,sizeof(mes_stats),"{F4CD8A}(В отпуске на %d %s)\n", vdays, Declension_GetDays(vdays));
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{F4CD8A}Организация:\t\t\t%s\n", fraction);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{F4CD8A}Работа/Должность:\t\t%s\n", job);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{F4CD8A}Ранг:\t\t\t\t%d\n", vrank_id);
		strcat(stats_string,mes_stats);
		format(mes_stats,sizeof(mes_stats),"{F4CD8A}Выговоров:\t\t\t\t%d\n\n", vwarns);
		strcat(stats_string,mes_stats);
	}

	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Дом:\t\t\t{0099ff}%s\n", houseinfo);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Бизнес:\t\t\t{0099ff}%s\n\n", bizinfo);
	strcat(stats_string,mes_stats);
	//format(mes_stats,sizeof(mes_stats),"{FFFFFF}Отель:\t\t\t\t{0099ff}%s\n\n", hotelinfo);
	//strcat(stats_string,mes_stats);

	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Время:\t\t\t\t{0099ff}%02d:%02d:%02d\n", hour,minute,second);
	strcat(stats_string,mes_stats);
	format(mes_stats,sizeof(mes_stats),"{FFFFFF}Дата:\t\t\t\t{0099ff}%02d.%02d.%02d", day,month,year);
	strcat(stats_string,mes_stats);

	ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Статистика", stats_string, !"Закрыть", !"");
	AdminLog(PI[playerid][pID], id, "/offstats");
	return true;
}
#if defined _ALS_pc_cmd_offstats
	#undef pc_cmd_offstats
#else
	#define _ALS_pc_cmd_offstats
#endif
#define pc_cmd_offstats ah_pc_cmd_offstats
#if defined ah_pc_cmd_offstats
	forward ah_pc_cmd_offstats(playerid);
#endif

CMD:tp(playerid)
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	ShowPlayerDialogEx(playerid, 400, DIALOG_STYLE_LIST, !"Телепорты", !"{FF7319}1.{FFFFFF} Общественные места\n{FF7319}2.{FFFFFF} Транспортные узлы\n{FF7319}3.{FFFFFF} Правительство\n{FF7319}4.{FFFFFF} Полиция/FBI\n{FF7319}5.{FFFFFF} Больницы\n{FF7319}6.{FFFFFF} Радиоцентры\n{FF7319}7.{FFFFFF} Армии\n{FF7319}8.{FFFFFF} Банды\n{FF7319}9.{FFFFFF} Мафии\n{FF7319}10.{FFFFFF} Банки", !"Далее", !"Отмена");
	return true;
}

CMD:slap(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /slap [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    if(PI[target][pSpectating])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Администратор находится в наблюдении");


    new
		Float:x, Float:y, Float:z,
		frmt_slap_message[100];

    GetPlayerPos(target, x, y, z);
    SetPlayerPos(target, x, y, z+5);
    format(frmt_slap_message, sizeof frmt_slap_message, "[A] %s подбросил игрока %s", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_slap_message);

	return true;
}
#if defined _ALS_pc_cmd_slap
	#undef pc_cmd_slap
#else
	#define _ALS_pc_cmd_slap
#endif
#define pc_cmd_slap ah_pc_cmd_slap
#if defined ah_pc_cmd_slap
	forward ah_pc_cmd_slap(playerid);
#endif

CMD:down(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /down [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

    if(PI[target][pSpectating])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Администратор находится в наблюдении");


    new
		Float:x, Float:y, Float:z,
		frmt_slap_message[100];

    GetPlayerPos(target, x, y, z);
    SetPlayerPos(target, x, y, z-5);
    format(frmt_slap_message, sizeof frmt_slap_message, "[A] %s опустил игрока %s", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_slap_message);
	return true;
}
#if defined _ALS_pc_cmd_down
	#undef pc_cmd_down
#else
	#define _ALS_pc_cmd_down
#endif
#define pc_cmd_down ah_pc_cmd_down
#if defined ah_pc_cmd_down
	forward ah_pc_cmd_down(playerid);
#endif

CMD:hp(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new player:target, health; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /hp [ID игрока] [Уровень здоровья]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

    if(PI[target][pSpectating])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Администратор находится в наблюдении");

	if(health < 1 || health > 100)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное количество здоровья (от 1 до 100)");

	J_SetPlayerHealth(target, health);

	new
	    frmt_heal_message[68];

	format(frmt_heal_message, sizeof frmt_heal_message, "Вы изменили здоровье игроку %s", PN(target));
	SendClientMessage(playerid, COLOR_WHITE, frmt_heal_message);

	format(frmt_heal_message, sizeof frmt_heal_message, "Администратор %s изменил вам здоровье", PN(playerid));
	SendClientMessage(target, COLOR_WHITE, frmt_heal_message);

	return true;
}
#if defined _ALS_pc_cmd_hp
	#undef pc_cmd_hp
#else
	#define _ALS_pc_cmd_hp
#endif
#define pc_cmd_hp ah_pc_cmd_hp
#if defined ah_pc_cmd_hp
	forward ah_pc_cmd_hp(playerid);
#endif

CMD:gtv(playerid, params[])
{
    if(PI[playerid][pAdmin] < 3)
		return 1;

	extract params -> new vehicleid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /gtv [ID транспорта]");

	new
		model = GetVehicleModel(vehicleid);

	if(0 == model)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID транспорта");

	new
		Float:x, Float:y, Float:z;

	GetVehiclePos(vehicleid, x, y, z);
	SetPlayerPos(playerid, x, y, z);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, GetVehicleVirtualWorld(vehicleid));

	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы успешно телепортировались к введенному транспорту");

	return true;
}
#if defined _ALS_pc_cmd_gtv
	#undef pc_cmd_gtv
#else
	#define _ALS_pc_cmd_gtv
#endif
#define pc_cmd_gtv ah_pc_cmd_gtv
#if defined ah_pc_cmd_gtv
	forward ah_pc_cmd_gtv(playerid);
#endif

CMD:goto(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /goto [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

    if(PI[target][pSpectating])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Администратор находится в наблюдении");

	new
		Float:x, Float:y, Float:z,
		frmt_goto_message[85];

    GetPlayerPos(target, x, y, z);
    SetPlayerPos(playerid, x+2, y+2, z);
    BizEntered[playerid] = BizEntered[target];
    HouseEntered[playerid] = HouseEntered[target];
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(target));
    SetPlayerInterior(playerid, GetPlayerInterior(target));

	format(frmt_goto_message, sizeof frmt_goto_message, "{FF9900}[Успешно] {FFFFFF}Вы телепортировались к игроку %s", PN(target));
	SendClientMessage(playerid, COLOR_WHITE, frmt_goto_message);
	return true;
}
#if defined _ALS_pc_cmd_goto
	#undef pc_cmd_goto
#else
	#define _ALS_pc_cmd_goto
#endif
#define pc_cmd_goto ah_pc_cmd_goto
#if defined ah_pc_cmd_goto
	forward ah_pc_cmd_goto(playerid);
#endif

CMD:biz(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4)
		return 1;

 	extract params -> new bizid; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /biz [номер бизнеса (АЗС от 1001 до 1019)]");

	if(bizid < 1001)
	{
		if(bizid < 1 || bizid > OWNABLEBIZES)
		    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный номер бизнеса");

	    SetPlayerVirtualWorld(playerid, 0);
	    SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, BizInfo[bizid-1][bEnter_X]+5.0*-floatsin(BizInfo[bizid-1][bEnter_R], degrees), BizInfo[bizid-1][bEnter_Y]+5.0*floatcos(BizInfo[bizid-1][bEnter_R], degrees), BizInfo[bizid-1][bEnter_Z]);
		SetPlayerFacingAngle(playerid, BizInfo[bizid-1][bEnter_R]);
	}
	else if(bizid >= 1001 && bizid <= 1001+MAX_FILLING)
	{
		if(bizid < 1001 || bizid > 1001+MAX_FILLING)
		    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный номер АЗС");

	    SetPlayerVirtualWorld(playerid, 0);
	    SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, gFillingBuy[bizid-1001][0], gFillingBuy[bizid-1001][1], gFillingBuy[bizid-1001][2]);
	}
	else
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный номер бизнеса/АЗС");

	return true;
}
#if defined _ALS_pc_cmd_biz
	#undef pc_cmd_biz
#else
	#define _ALS_pc_cmd_biz
#endif
#define pc_cmd_biz ah_pc_cmd_biz
#if defined ah_pc_cmd_biz
	forward ah_pc_cmd_biz(playerid);
#endif

CMD:ban(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target, days, string:reason[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /ban [ID игрока] [Кол-во дней] [Причина]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(!PI[target][pID] || !IsPlayerLogged[target])
	{
		J_Kick(target);
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован, поэтому был кикнут");
	}


	if(days < 1 || days > 30)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное кол-во дней");

	if(PI[target][pAdmin] >= 7)
	{
		new
			frmt_ban_admin[110];

		format(frmt_ban_admin, sizeof frmt_ban_admin, "[A] %s попытался забанить Администратора %s", PN(playerid), PN(target));
 		SendAdminsMessage(COLOR_GREY, frmt_ban_admin);
 		return 1;
	}

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new query_auninvite[190 + 9];
	format(query_auninvite, sizeof query_auninvite, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0' WHERE `ID` = '%d'", PI[target][pID]);
	mysql_query(mysql, query_auninvite);

	PI[target][pFraction] = 0;
	PI[target][pRank] = 0;
	PI[target][pFWarns] = 0;
	PI[target][pFractionSkin] = 0;
	PI[target][pSubfraction] = 0;
	SetString(PI[target][pDateInvite], "00-00-0000");
	SetString(PI[target][pLastRank], "00-00-0000");
	PI[target][pDivision] = 0;
	UpdatePlayerData(target, "Division", PI[target][pDivision]);
	SetPlayerColor(target, 0xFFFFFF11);
	SetPlayerSkin(target, PI[target][pSkin]);
	SetPlayerArmour(target, 0);
	resetgun(target);

	new
		frmt_ban_text[143],
	    frmt_ban_dialog[448];

	format(frmt_ban_text, sizeof frmt_ban_text, "Администратор %s забанил игрока %s на %d %s. Причина: %s", PN(playerid), PN(target), days, Declension_GetDays(days), reason);
	ASCMTA(COLOR_LIGHTRED, frmt_ban_text);

	new
		d,
		m,
		y,
		hours,
		minutes;

	getdate(y, m, d);
	gettime(hours, minutes);
	format(frmt_ban_dialog, sizeof frmt_ban_dialog,
	"{FFFFFF}Внимание,\n\
	Ваш аккаунт заблокирован за нарушение правил сервера,\n\
	обязательно сделайте скриншот данного окна или Ваша жалоба не будет принята.\n\
	Дата выдачи наказания: {86B9FF}%d-%d-%d %d:%d{FFFFFF}\n\
	Срок наказания: {FFFF00}%d %s{FFFFFF}\n\
	Причина: {FFFF00}%s{FFFFFF}\n\
	Администратор, выдавший наказание: {FFFF00}%s", d, m, y, hours, minutes, days, Declension_GetDays(days), reason, PN(playerid));
	ShowPlayerDialogEx(target, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, PN(target), frmt_ban_dialog, !"Закрыть", !"");

	AdminLog(PI[playerid][pID], PI[target][pID], "/ban");

	ServerBan(playerid, target, days, reason);

    J_Kick(target);

	return true;
}
#if defined _ALS_pc_cmd_ban
	#undef pc_cmd_ban
#else
	#define _ALS_pc_cmd_ban
#endif
#define pc_cmd_ban ah_pc_cmd_ban
#if defined ah_pc_cmd_ban
	forward ah_pc_cmd_ban(playerid);
#endif


CMD:warn(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target, string:reason[35]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /warn [ID игрока] [Причина]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(!PI[target][pID] || !IsPlayerLogged[target])
	{
		J_Kick(target);
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован, поэтому был кикнут");
	}

	if(PI[target][pAdmin] >= 7)
	{
		new
			frmt_ban_admin[150];

		format(frmt_ban_admin, sizeof frmt_ban_admin, "[A] %s попытался выдать предупреждение Администратору %s", PN(playerid), PN(target));
 		SendAdminsMessage(COLOR_GREY, frmt_ban_admin);
 		return 1;
	}
	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new query_auninvite[320 + 9];
	format(query_auninvite, sizeof query_auninvite, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0', `v_Days` = '0', `v_Fraction` = '0', `v_Rank` = '0', `v_Subfraction` = '0', `v_FractionSkin` = '0', `v_FWarns` = '0', `Division` = '0' WHERE `ID` = '%d'", PI[target][pID]);
	mysql_query(mysql, query_auninvite);

	PI[target][pFraction] =
	PI[target][pRank] =
	PI[target][pFWarns] =
	PI[target][pFractionSkin] =
	PI[target][pSubfraction] =
	PI[target][pv_Fraction] =
	PI[target][pv_Rank] =
	PI[target][pv_FWarns] =
	PI[target][pv_FractionSkin] =
	PI[target][pv_Subfraction] =
	PI[target][pv_Days] =
	PI[target][pDivision] = 0;
	SetString(PI[target][pDateInvite], "00-00-0000");
	SetString(PI[target][pLastRank], "00-00-0000");

	SetPlayerColor(target, 0xFFFFFF11);
	SetPlayerSkin(target, PI[target][pSkin]);
	SetPlayerArmour(target, 0);
	resetgun(target);

	new
		warnscount = PI[target][pWarns]+1;

	if(warnscount < 3)
	{
		new
			frmt_warn_text[143];

		format(frmt_warn_text, sizeof frmt_warn_text, "Администратор %s выдал предупреждение игроку %s [%d/3]. Причина: %s", PN(playerid), PN(target), warnscount, reason);
		ASCMTA(COLOR_LIGHTRED, frmt_warn_text);
	}
	PI[target][pWarnTime] += 7;
	UpdatePlayerData(target, "WarnTime", PI[target][pWarnTime]);

	PI[target][pWarns] = warnscount;
	UpdatePlayerData(target, "Warns", PI[target][pWarns]);

	PI[target][pWarnStatus] = 0;
	UpdatePlayerData(target, "WarnStatus", PI[target][pWarnStatus]);

	AdminLog(PI[playerid][pID], PI[target][pID], "/warn");

	if(warnscount == 3)
	{

		PI[target][pWarnTime] = 0;
		UpdatePlayerData(target, "WarnTime", PI[target][pWarnTime]);

		PI[target][pWarns] = 0;
		UpdatePlayerData(target, "Warns", PI[target][pWarns]);

		new
			frmt_ban_text[193],
		    frmt_ban_dialog[448];

		format(frmt_ban_text, sizeof frmt_ban_text, "Администратор %s забанил игрока %s на 10 дней (3 предупреждения). Причина: %s", PN(playerid), PN(target), reason);
		ASCMTA(COLOR_LIGHTRED, frmt_ban_text);

		new
			d,
			m,
			y,
			hours,
			minutes;

		getdate(y, m, d);
		gettime(hours, minutes);
		format(frmt_ban_dialog, sizeof frmt_ban_dialog,
		"{FFFFFF}Внимание,\n\
		Ваш аккаунт заблокирован за нарушение правил сервера,\n\
		обязательно сделайте скриншот данного окна или Ваша жалоба не будет принята.\n\
		Дата выдачи наказания: {86B9FF}%d-%d-%d %d:%d{FFFFFF}\n\
		Срок наказания: {FFFF00}10 дней{FFFFFF}\n\
		Причина: {FFFF00}%s{FFFFFF}\n\
		Администратор, выдавший наказание: {FFFF00}%s", d, m, y, hours, minutes, reason, PN(playerid));
		ShowPlayerDialogEx(target, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, PN(target), frmt_ban_dialog, !"Закрыть", !"");

		ServerBan(playerid, target, 10, reason);
	}

	J_Kick(target);
	return true;
}
#if defined _ALS_pc_cmd_warn
	#undef pc_cmd_warn
#else
	#define _ALS_pc_cmd_warn
#endif
#define pc_cmd_warn ah_pc_cmd_warn
#if defined ah_pc_cmd_warn
	forward ah_pc_cmd_warn(playerid);
#endif

CMD:unwarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /unwarn [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(!PI[target][pWarns])
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У игрока нет предупреждений");

	PI[target][pWarns]--;
	UpdatePlayerData(target, "Warns", PI[target][pWarns]);

	if(PI[target][pWarnTime] > 7)
	{
	    PI[target][pWarnTime] = 7;
	    UpdatePlayerData(target, "WarnTime", PI[target][pWarnTime]);
	}
	else if(PI[target][pWarnTime] < 7)
	{
	    PI[target][pWarnTime] = 0;
	    UpdatePlayerData(target, "WarnTime", PI[target][pWarnTime]);
	}

	new
	    frmt_unwarn_message[110];

	format(frmt_unwarn_message, sizeof frmt_unwarn_message, "[A] %s снял предупреждение игроку %s", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_unwarn_message);
	format(frmt_unwarn_message, sizeof frmt_unwarn_message, "Администратор %s снял Вам предупреждение", PN(playerid));
	SendClientMessage(target, COLOR_LIGHTRED, frmt_unwarn_message);
	AdminLog(PI[playerid][pID], PI[target][pID], "/unwarn");
	return true;
}
#if defined _ALS_pc_cmd_unwarn
	#undef pc_cmd_unwarn
#else
	#define _ALS_pc_cmd_unwarn
#endif
#define pc_cmd_unwarn ah_pc_cmd_unwarn
#if defined ah_pc_cmd_unwarn
	forward ah_pc_cmd_unwarn(playerid);
#endif

CMD:delad(playerid)
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

    if(0 == gAdvertCount)
        return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Нет объявлений");

	for(new i; i < gAdvertCount; i++)
	{
		strdel(gAdvert[i][adSender],0,24);
		gAdvert[i][adPhone] = 0;
		strdel(gAdvert[i][adText],0,100);
		strdel(gAdvert[i][adChecker],0,24);
		gAdvert[i][adCheckerID] = 0;
		strdel(gAdvert[i][adRang],0,30);
		gAdvert[i][adBusy] = false;
		gAdvert[i][adChecked] = false;
		gAdvert[i][adChecking] = false;
		gAdvert[i][adTime] = 0;
	}
	gAdvertCount = 0;

    AdminLog(PI[playerid][pID], 0, "/delad");
	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы успешно очистили все объявления");
	return true;
}
#if defined _ALS_pc_cmd_delad
	#undef pc_cmd_delad
#else
	#define _ALS_pc_cmd_delad
#endif
#define pc_cmd_delad ah_pc_cmd_delad
#if defined ah_pc_cmd_delad
	forward ah_pc_cmd_delad(playerid);
#endif

CMD:respv(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new radius; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /respv [Радиус (от 1 до 100)]");

    if(radius < 1 || radius > 100)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный радиус (от 1 до 100)");

	new
		Float:car_x,
		Float:car_y,
		Float:car_z;

	for(new i, j = GetVehiclePoolSize(); i <= j; i++)
	{
	    if(i == INVALID_VEHICLE_ID)
	        continue;

		if(GetVehicleModel(i) > 399 && !IsPlayerInVehicle(playerid, i))
		{
		    GetVehiclePos(i, car_x, car_y, car_z);

		    if(IsPlayerInRangeOfPoint(playerid, radius, car_x, car_y, car_z) && !IsVehicleOccupied(i))
				SetVehicleToRespawnEx(i);
	    }
	}
	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Транспорт в введенном радиусе зареспавнен");
	return true;
}
#if defined _ALS_pc_cmd_respv
	#undef pc_cmd_respv
#else
	#define _ALS_pc_cmd_respv
#endif
#define pc_cmd_respv ah_pc_cmd_respv
#if defined ah_pc_cmd_respv
	forward ah_pc_cmd_respv(playerid);
#endif

CMD:offwarn(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new string:nick[25], string:reason[33]; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /offwarn [Ник игрока] [Причина]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок с данным именем находится на сервере. Выдать наказание не удалось");
		return 1;
	}
	if(strfind(reason,"`") != -1 || strfind(reason,"'") != -1) return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Найдены запрещенные символы");


	new
	    nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
	    query_offwarn_getid[100];

	format(query_offwarn_getid, sizeof query_offwarn_getid, "SELECT `ID`, `Admin`, `Warns`, `Ban` FROM `accounts` WHERE `NickName` = '%s'", nickname);
	new Cache:result = mysql_query(mysql, query_offwarn_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
		id,
		admin,
		warns,
		ban;

	id = cache_get_row_int(0, 0);
	admin = cache_get_row_int(0, 1);
	warns = cache_get_row_int(0, 2);
	ban = cache_get_row_int(0, 3);

	cache_delete(result, mysql);

	if(admin >= 7)
	{
		new
			frmt_warn_admin[150];

		format(frmt_warn_admin, sizeof frmt_warn_admin, "[A] %s попытался выдать оффлайн предупреждение Администратору %s", PN(playerid), nickname);
 		SendAdminsMessage(COLOR_GREY, frmt_warn_admin);
 		return 1;
	}

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	if(ban)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок имеет блокировку");

	new
		warnscount = warns+1;

	if(warnscount < 3)
	{
		new
			frmt_warn_text[193];

		format(frmt_warn_text, sizeof frmt_warn_text, "Игрок %s получил оффлайн предупреждение от Администратора %s [%d/3]. Причина: %s", nickname, PN(playerid), warnscount, reason);
		ASCMTA(COLOR_LIGHTRED, frmt_warn_text);
		AdminLog(PI[playerid][pID], id, "/offwarn");
	}

 	new query_offwarn[330];

	format(query_offwarn, sizeof query_offwarn, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0', `v_Days` = '0', `v_Fraction` = '0', `v_Rank` = '0', `v_Subfraction` = '0', `v_FractionSkin` = '0', `v_FWarns` = '0', `Division` = '0' WHERE `ID` = '%d'", id);
    mysql_tquery(mysql, query_offwarn);
    format(query_offwarn, sizeof query_offwarn, "UPDATE `accounts` SET `Warns` = `Warns`+1, `WarnTime` = `WarnTime`+7, `WarnStatus` = `WarnStatus`+7, `WarnNick` = '%s', `WarnReason` = '%s' WHERE `ID` = '%d'", nickname, reason, id);
    mysql_tquery(mysql, query_offwarn);

	if(warnscount == 3)
	{
		new
			frmt_ban_text[193],
			query_offwarn_ban[210];

		format(frmt_ban_text, sizeof frmt_ban_text, "Игрок %s получил оффлайн бан от Администратора %s на 10 дней [3/3]. Причина: %s", nickname, PN(playerid), reason);
		ASCMTA(COLOR_LIGHTRED, frmt_ban_text);

	 	format(query_offwarn_ban, sizeof query_offwarn_ban, "INSERT INTO `ban` (`id`, `admin`, `takeid`, `time`, `reason`, `status`) VALUES ('', '%d', '%d', '10', '%s', '0')", PI[playerid][pID], id, reason);
	 	mysql_query(mysql, query_offwarn_ban);
        format(query_offwarn_ban, sizeof query_offwarn_ban, "UPDATE `accounts` SET `BanActivate` = '0', `Ban` = '10', `WarnTime` = '0', `Warns` = '0', `WarnStatus` = '0', `WarnNick` = '', `WarnReason` = '' WHERE `ID` = '%d'", id);
        mysql_query(mysql, query_offwarn_ban);
	    AdminLog(PI[playerid][pID], id, "/offban");
	}
	return true;
}
#if defined _ALS_pc_cmd_offwarn
	#undef pc_cmd_offwarn
#else
	#define _ALS_pc_cmd_offwarn
#endif
#define pc_cmd_offwarn ah_pc_cmd_offwarn
#if defined ah_pc_cmd_offwarn
	forward ah_pc_cmd_offwarn(playerid);
#endif

CMD:unwarnoff(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /unwarnoff [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок с данным именем находится на сервере. Выдать наказание не удалось");
		return 1;
	}

	new
	    nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
	    query_offwarn_getid[100];

	format(query_offwarn_getid, sizeof query_offwarn_getid, "SELECT `ID`, `Warns`, `WarnTime`, `Ban` FROM `accounts` WHERE `NickName` = '%s'", nickname);
	new Cache:result = mysql_query(mysql, query_offwarn_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
		id,
		warns,
		warntime,
		ban;

	id = cache_get_row_int(0, 0);
	warns = cache_get_row_int(0, 1);
	warntime = cache_get_row_int(0, 2);
	ban = cache_get_row_int(0, 3);

	cache_delete(result, mysql);

	if(ban)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок имеет блокировку");

	if(!warns)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У игрока нет предупреждений");

	new
        query_unwarnoff[80];

    format(query_unwarnoff, sizeof query_unwarnoff, "UPDATE `accounts` SET `Warns` = `Warns`-1 WHERE `ID` = '%d'", id);
    mysql_query(mysql, query_unwarnoff);


	if(warntime > 7)
		format(query_unwarnoff, sizeof query_unwarnoff, "UPDATE `accounts` SET `WarnTime` = '7' WHERE `ID` = '%d'", id), mysql_query(mysql, query_unwarnoff);

	else if(warntime < 7)
		format(query_unwarnoff, sizeof query_unwarnoff, "UPDATE `accounts` SET `WarnTime` = '0' WHERE `ID` = '%d'", id), mysql_query(mysql, query_unwarnoff);


	new
	    frmt_unwarn_message[150];

	format(frmt_unwarn_message, sizeof frmt_unwarn_message, "[A] %s снял предупреждение игроку %s в оффлайне", PN(playerid), nickname);
	SendAdminsMessage(COLOR_GREY, frmt_unwarn_message);
	AdminLog(PI[playerid][pID], id, "/unwarnoff");
	return true;
}
#if defined _ALS_pc_cmd_unwarnoff
	#undef pc_cmd_unwarnoff
#else
	#define _ALS_pc_cmd_unwarnoff
#endif
#define pc_cmd_unwarnoff ah_pc_cmd_unwarnoff
#if defined ah_pc_cmd_unwarnoff
	forward ah_pc_cmd_unwarnoff(playerid);
#endif

CMD:templeader(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new fractionid, subid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /templeader [ID фракции] [ID подфракции]");

	if(fractionid < 0 || fractionid > 14)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID фракции (от 0 до 14)");

	new
	    total_sub = GetSubfraction(fractionid),
	    frmt_templeader_msg[190];

	if(fractionid == 0)
	{
	    PI[playerid][pFraction] = 0;
	    PI[playerid][pSubfraction] = 0;
	    PI[playerid][pRank] = 0;
	    PI[playerid][pFractionSkin] = PI[playerid][pSkin];
		pTemp[playerid][pTempLeader] = false;
	    SetPlayerColor(playerid, 0xFFFFFF11);
	    SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы покинули временную организацию");
	    return 1;
	}

	if(total_sub != (-1) && (subid < 0 || subid > total_sub))
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID подфракции");

	if(subid > 0 && total_sub == -1)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}В данной фракции нет подфракций");

	if(subid > 0 && subid <= total_sub && total_sub != -1)
	{
	    new
			frid = GetSubfractionID(fractionid);

	    PI[playerid][pFraction] = fractionid;
	    PI[playerid][pSubfraction] = subid;
	    PI[playerid][pRank] = 10;
	    PI[playerid][pFractionSkin] = PI[playerid][pSkin];
		pTemp[playerid][pTempLeader] = true;
	    SetPlayerColor(playerid, 0xFFFFFF11);
		format(frmt_templeader_msg, sizeof frmt_templeader_msg, "{FF9900}[Успешно] {FFFFFF}Вы тихо вступили во фракцию %s, подфракцию %s", gFractionName[fractionid-1], gSubfractionName[frid][subid-1]);
		SendClientMessage(playerid, COLOR_WHITE, frmt_templeader_msg);
	}
	else if(subid == 0)
	{
	    PI[playerid][pFraction] = fractionid;
	    PI[playerid][pSubfraction] = subid;
	    PI[playerid][pRank] = gFractionRankCount[fractionid-1];
	    PI[playerid][pFractionSkin] = PI[playerid][pSkin];
	    pTemp[playerid][pTempLeader] = true;
	    SetPlayerColor(playerid, 0xFFFFFF11);
		format(frmt_templeader_msg, sizeof frmt_templeader_msg, "{FF9900}[Успешно] {FFFFFF}Вы тихо вступили во фракцию %s", gFractionName[fractionid-1]);
		SendClientMessage(playerid, COLOR_WHITE, frmt_templeader_msg);
	}
	else
	    SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный параметр (фракция или подфракция)");

	return true;
}
#if defined _ALS_pc_cmd_templeader
	#undef pc_cmd_templeader
#else
	#define _ALS_pc_cmd_templeader
#endif
#define pc_cmd_templeader ah_pc_cmd_templeader
#if defined ah_pc_cmd_templeader
	forward ah_pc_cmd_templeader(playerid);
#endif

CMD:okay(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /okay [ID игрока]");

    if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не найден");

	if(!IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не авторизовался");

    if(!temp_change_nickname_want[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /okay [ID игрока]");

	new
		nickname[MAX_PLAYER_NAME+1],
		oldname[MAX_PLAYER_NAME+1],
		query_nick_change_accept[54 + MAX_PLAYER_NAME + 9],
		format_nick_change_chat[26 + MAX_PLAYER_NAME + MAX_PLAYER_NAME],
		format_nick_change_adminchat[36 + MAX_PLAYER_NAME],
		format_nick_change_pl[71 + MAX_PLAYER_NAME],
		query_updhouse_owner[90 + MAX_PLAYER_NAME],
		query_business_owner[90 + MAX_PLAYER_NAME],
		query_namestore_new[80 + 11 + MAX_PLAYER_NAME + 12],
		string[200];

	SetString(nickname, temp_change_nickname[target]);
	strdel(temp_change_nickname[target], 0, MAX_PLAYER_NAME);

	GetPlayerName(target, oldname, MAX_PLAYER_NAME);
	temp_change_nickname_want[target] = false;

	if(GetPlayerID(nickname) != INVALID_PLAYER_ID)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Произошла ошибка при смене ника игроку");

	if(SetPlayerName(target,nickname) == -1)
	{
	    SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Смена ника не удалась, найдены запрещенные символы");
		return SendClientMessage(target, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У вас присутствуют запрещенные символы в никнейме");
	}

	new
		date[12],
		d,
		m,
		y;

	getdate(y, m, d);
	format(date, sizeof date, "%d-%d-%d", d, m, y);

	format(query_namestore_new, sizeof query_namestore_new, "INSERT INTO `namestore` (`account_id`, `newname`, `data`) VALUES ('%d', '%s', '%s')", PI[target][pID], PN(target), date);
	mysql_query(mysql, query_namestore_new);

	SetString(PlayerName[target], nickname);

	if(PI[target][pHouseKey] != 0)
	{
		if(GetString(HouseInfo[PI[target][pHouseKey]-1][hOwner], oldname))
		{
			new houseid = PI[target][pHouseKey] - 1;
			SetString(HouseInfo[houseid][hOwner], nickname);
			format(query_updhouse_owner,sizeof query_updhouse_owner,"UPDATE `houses` SET `Owner` = '%s' WHERE `ID` = '%d'",nickname,houseid+1);
			mysql_query(mysql, query_updhouse_owner);
		}

		format(string, sizeof(string), "UPDATE `houses` SET `Room_Owner_0` = '%s' WHERE `Room_Owner_0` = '%s'", nickname, oldname);
		mysql_tquery(mysql, string);
		format(string, sizeof(string), "UPDATE `houses` SET `Room_Owner_1` = '%s' WHERE `Room_Owner_1` = '%s'", nickname, oldname);
		mysql_tquery(mysql, string);
		format(string, sizeof(string), "UPDATE `houses` SET `Room_Owner_2` = '%s' WHERE `Room_Owner_2` = '%s'", nickname, oldname);
		mysql_tquery(mysql, string);
	}
	if(PI[target][pFamily] != 0)
	{
		new
		    famid = PI[target][pFamily]-1,
			frmt_update_family[120];

		if(GetString(gFamily[famid][fOwner], oldname))
		{
		    SetString(gFamily[famid][fOwner], nickname);
			format(frmt_update_family, sizeof frmt_update_family, "UPDATE `family` SET `Owner` = '%s' WHERE `ID` = '%d'", nickname, famid+1);
			mysql_query(mysql, frmt_update_family);
		}

		if(GetString(gFamily[famid][fSubOwner], oldname))
		{
		    SetString(gFamily[famid][fSubOwner], nickname);
			format(frmt_update_family, sizeof frmt_update_family, "UPDATE `family` SET `SubOwner` = '%s' WHERE `ID` = '%d'", nickname, famid+1);
			mysql_query(mysql, frmt_update_family);
		}

	}
	if(PI[target][pBizKey] < 1000 && PI[target][pBizKey] != 0)
	{
		if(GetString(BizInfo[PI[target][pBizKey]-1][bOwner], oldname))
		{
			new bizid = PI[target][pBizKey] - 1;
			SetString(BizInfo[bizid][bOwner], nickname);
			format(query_business_owner, sizeof query_business_owner, "UPDATE `business` SET `Owner` = '%s' WHERE `ID` = '%d'", nickname, bizid+1);
			mysql_query(mysql, query_business_owner);
			UpdateBiz(bizid,1);
		}
	}
	if(PI[target][pBizKey] > 1000 && PI[target][pBizKey] != 0)
	{
		if(GetString(gFillings[PI[target][pBizKey]-1000][fillingOwner], oldname))
		{
			new fillingid = PI[target][pBizKey] - 1000;
			SetString(gFillings[fillingid][fillingOwner], nickname);
			format(query_business_owner, sizeof query_business_owner, "UPDATE `fillings` SET `Owner` = '%s' WHERE `ID` = '%d'", nickname, fillingid+1);
			mysql_query(mysql, query_business_owner);
			UpdateFillingText(fillingid);
		}
	}

	new bool:online = false;
	if(strlen(PI[target][pMerrit]) > 0)
	{
	 	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
	    {
	        if(!strcmp(PN(target), PI[i][pMerrit], true) && IsPlayerConnected(i))
			{
				new str[256];
				format(str, sizeof(str), "UPDATE `accounts` SET `Merrit`='%s' WHERE `NickName` = '%s'; ", nickname, PI[target][pMerrit]);
				mysql_tquery(mysql, str);
                online = true;
				SetString(PI[i][pMerrit], nickname);
				break;
			}
	    }
	    if(online == false)
	    {
			new str[256];
			format(str, sizeof(str), "UPDATE `accounts` SET `Merrit`='%s' WHERE `NickName` = '%s'; ", nickname, PI[target][pMerrit]);
			mysql_tquery(mysql, str);
		}
	}

	for(new i; i < 15; i++)
	{
		for(new b; b < 10; b++)
		{
			if(GetString(gNickNomination[i][b], oldname))
			{
			    SetString(gNickNomination[i][b], nickname);
			    if(b == 0) SetDynamicObjectMaterialText(gNomination[i], 0, nickname, 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
			}
		}
	}
	format(query_nick_change_accept,sizeof(query_nick_change_accept),"UPDATE `accounts` SET `NickName` = '%s' WHERE `ID` = '%d'", nickname, PI[target][pID]);
	mysql_query(mysql, query_nick_change_accept);

	format(format_nick_change_chat,sizeof(format_nick_change_chat),"%s изменил нонРП имя на %s", oldname, nickname);
	SendClientMessageToAll(COLOR_YELLOW, format_nick_change_chat);

	format(format_nick_change_pl,sizeof(format_nick_change_pl),"Ваш ник изменен на %s. Не забудьте указать новый ник в SA-MP клиенте.", nickname);
	SendClientMessage(target, 0xff7640ff, format_nick_change_pl);

	format(format_nick_change_adminchat,sizeof(format_nick_change_adminchat),"Замену ника одобрил администратор %s", PN(playerid));
	SendAdminsMessage(0x037AFAFF, format_nick_change_adminchat);
	AdminLog(PI[playerid][pID], PI[target][pID], "/okay");
    return 1;
}
#if defined _ALS_pc_cmd_okay
	#undef pc_cmd_okay
#else
	#define _ALS_pc_cmd_okay
#endif
#define pc_cmd_okay ah_pc_cmd_okay
#if defined ah_pc_cmd_okay
	forward ah_pc_cmd_okay(playerid);
#endif

CMD:nookay(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /nookay [ID игрока]");

    if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не найден");

	if(!IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не авторизовался");

    if(!temp_change_nickname_want[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Данный игрок не подавал заявку на смену ника");

    temp_change_nickname_want[target] = false;

	new
	    format_nick_change_adminchat[MAX_PLAYER_NAME + 45];

	format(format_nick_change_adminchat, sizeof format_nick_change_adminchat, "[A] %s отказал смену ника %s", PN(playerid), PN(target));
	SendAdminsMessage(0x037AFAFF, format_nick_change_adminchat);
    AdminLog(PI[playerid][pID], PI[target][pID], "/nookay");
    return 1;
}
CMD:iokay(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /iokay [ID игрока]");

    if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не авторизовался");

    if(!temp_change_nickname_want[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Данный игрок не подавал заявку на смену ника");

	new
		frmt_str_nickchange[24 + MAX_PLAYER_NAME*2];

	format(frmt_str_nickchange, sizeof frmt_str_nickchange, "Заявка на смену ника %s > %s", PN(target), temp_change_nickname[target]);
    SendClientMessage(playerid, 0xFF7640FF, frmt_str_nickchange);
	return 1;
}

CMD:house(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new houseid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /house [Номер дома]");

	if(houseid < 1 || houseid > OWNABLEHOUSES)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный номер дома");

    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid, HouseInfo[houseid-1][hEnter_X], HouseInfo[houseid-1][hEnter_Y], HouseInfo[houseid-1][hEnter_Z]);
	SetPlayerFacingAngle(playerid, HouseInfo[houseid-1][hEnter_R]);
	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы были телепортированы к дому");
	return true;
}
#if defined _ALS_pc_cmd_house
	#undef pc_cmd_house
#else
	#define _ALS_pc_cmd_house
#endif
#define pc_cmd_house ah_pc_cmd_house
#if defined ah_pc_cmd_house
	forward ah_pc_cmd_house(playerid);
#endif

CMD:gethere(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /gethere [ID игрока]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

    new
		Float:x, Float:y, Float:z, Float:a;

    pTemp[target][pAntiAir] += 4;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    SetPlayerVirtualWorld(target, GetPlayerVirtualWorld(playerid));
    SetPlayerInterior(target, GetPlayerInterior(playerid));

    SetPVarInt(target, "anticheat_tp", gettime()+1);
    SetPlayerPos(target, x+1.0*-floatsin(1.0, degrees), y+1.0*floatcos(1.0, degrees), z);
    BizEntered[target] = BizEntered[playerid];
    HouseEntered[target] = HouseEntered[playerid];

    new
        frmt_gethere_message[120];

    format(frmt_gethere_message, sizeof frmt_gethere_message, "Администратор %s телепортировал Вас к себе", PN(playerid));
    SendClientMessage(target, COLOR_WHITE, frmt_gethere_message);

    format(frmt_gethere_message, sizeof frmt_gethere_message, "[A] %s телепортировал к себе игрока %s", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_gethere_message);

	return true;
}
#if defined _ALS_pc_cmd_gethere
	#undef pc_cmd_gethere
#else
	#define _ALS_pc_cmd_gethere
#endif
#define pc_cmd_gethere ah_pc_cmd_gethere
#if defined ah_pc_cmd_gethere
	forward ah_pc_cmd_gethere(playerid);
#endif


CMD:skin(playerid, params[])
{
	if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target, skin; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /skin [ID игрока] [ID скина]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(skin < 1 || skin > 311)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}ID скина от 1 до 311");

	if(skin == 74)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID скина");

	SetPlayerSkinEx(target, skin);
	pTemp[target][pTempSkin] = true;

	new
	    frmt_skin_message[90];

	format(frmt_skin_message, sizeof frmt_skin_message, "Администратор %s поставил Вам временный скин", PN(playerid));
	SendClientMessage(target, COLOR_WHITE, frmt_skin_message);

    SendClientMessage(target, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте {FFFF00}/endskin{FFFFFF} чтобы выбросить одежду");
	return true;
}
#if defined _ALS_pc_cmd_skin
	#undef pc_cmd_skin
#else
	#define _ALS_pc_cmd_skin
#endif
#define pc_cmd_skin ah_pc_cmd_skin
#if defined ah_pc_cmd_skin
	forward ah_pc_cmd_skin(playerid);
#endif

CMD:rhp(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new radius; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /rhp [радиус]");

    if(radius < 1 || radius > 100)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /rhp [радиус (1-100)]");

    new
		frmt_rhp_message[130];

    format(frmt_rhp_message, sizeof frmt_rhp_message, "Вы изменили здоровье игрокам в радиусе %d метров", radius);
    SendClientMessage(playerid, COLOR_WHITE, frmt_rhp_message);


    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        if(IsPlayerConnected(i) && IsPlayerLogged[i])
        {
			if(GetPlayerDistanceToPlayer(playerid, i) < radius)
			{
	            J_SetPlayerHealth(i, 100);
				format(frmt_rhp_message, sizeof frmt_rhp_message, "Администратор %s изменил вам здоровье", PN(playerid));
				SendClientMessage(i, COLOR_WHITE, frmt_rhp_message);
			}
		}
    }
    return true;
}
#if defined _ALS_pc_cmd_rhp
	#undef pc_cmd_rhp
#else
	#define _ALS_pc_cmd_rhp
#endif
#define pc_cmd_rhp ah_pc_cmd_rhp
#if defined ah_pc_cmd_rhp
	forward ah_pc_cmd_rhp(playerid);
#endif

CMD:veh(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5)
		return 1;

	new
		vehmodel, color1, color2, string[256];

    if(sscanf(params, "dD(-1)D(-1)", vehmodel, color1, color2))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /veh [id авто] [цвет 1] [цвет 2]");

	if(color1 == -1)
		color1 = random(128);

	if(color2 == -1)
		color2 = random(128);

	if(vehmodel < 400 || vehmodel > 611)
 		return SendClientMessage(playerid, 0xB4B5B7FF, !"ID транспорта от 400 до 611");

	if(color1 < 0 || color1 > 256 || color2 < 0 || color2 > 256)
		return SendClientMessage(playerid, COLOR_GREY, !"Номер цвета от 0 до 256");

	new
		Float:X, Float:Y, Float:Z, Float:A;

	GetPlayerPos(playerid, X,Y,Z);
	GetPlayerFacingAngle(playerid,A);
	CreatedCar[CREATEDCARS] = J_AddStaticVehicleEx(vehmodel, X, Y+3.0, Z, A, color1, color2, 1000000);
	new carid = CreatedCar[CREATEDCARS];
	J_SetVehicleHealth(carid, 1000);
	format(string, sizeof(string), "Автомобиль %d создан", carid);
	SCM(playerid, COLOR_WHITE, string);
	VehicleInfo[carid][vLock] = 0;
	VehicleInfo[carid][vFuel] = Transport[vehmodel - 400][trTank];
	VehicleInfo[carid][vHealth] = 1000.0;
	VehicleInfo[carid][vOwnerid] = INVALID_PLAYER_ID;
	VehicleInfo[carid][vSozdan] = 1;
	ADD_VEHICLES ++;
	CREATEDCARS ++;
	return true;
}
#if defined _ALS_pc_cmd_veh
	#undef pc_cmd_veh
#else
	#define _ALS_pc_cmd_veh
#endif
#define pc_cmd_veh ah_pc_cmd_veh
#if defined ah_pc_cmd_veh
	forward ah_pc_cmd_veh(playerid);
#endif

CMD:delv(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new radius; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /delv [Радиус (от 1 до 100)]");

    if(radius < 1 || radius > 100)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный радиус (от 1 до 100)");

	new
		Float:car_x,
		Float:car_y,
		Float:car_z;

	for(new i, j = GetVehiclePoolSize(); i <= j; i++)
	{
	    if(i == INVALID_VEHICLE_ID)
	        continue;

		if(GetVehicleModel(i) > 399)
		{
		    GetVehiclePos(i, car_x, car_y, car_z);

		    if(IsPlayerInRangeOfPoint(playerid, radius, car_x, car_y, car_z))
		    {
		        if(VehicleInfo[i][vSozdan] == 1 && !IsPlayerInVehicle(playerid, i) && !IsVehicleOccupied(i))
		        {
					ADD_VEHICLES -= 1;
					CREATEDCARS -= 1;
					DestroyVehicleEx(i);
				}
			}
	    }
	}
	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Транспорт в введенном радиусе удален");
	return true;
}
#if defined _ALS_pc_cmd_delv
	#undef pc_cmd_delv
#else
	#define _ALS_pc_cmd_delv
#endif
#define pc_cmd_delv ah_pc_cmd_delv
#if defined ah_pc_cmd_delv
	forward ah_pc_cmd_delv(playerid);
#endif

CMD:ears(playerid)
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	if(pTemp[playerid][pEarsSMS])
	    pTemp[playerid][pEarsSMS] = false, SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы выключили прослушку SMS");

	else
	    pTemp[playerid][pEarsSMS] = true, SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы включили прослушку SMS");


	return true;
}
#if defined _ALS_pc_cmd_ears
	#undef pc_cmd_ears
#else
	#define _ALS_pc_cmd_ears
#endif
#define pc_cmd_ears ah_pc_cmd_ears
#if defined ah_pc_cmd_ears
	forward ah_pc_cmd_ears(playerid);
#endif

CMD:sban(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new player:target, days, string:reason[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /sban [ID игрока] [Кол-во дней] [Причина]");

	if(!IsPlayerConnected(target) || playerid == target)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(!PI[target][pID] || !IsPlayerLogged[target])
	{
		J_Kick(target);
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован, поэтому был кикнут");
	}


	if(days < 1 || days > 30)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное кол-во дней");

	if(PI[target][pAdmin] >= 7)
	{
		new
			frmt_ban_admin[110];

		format(frmt_ban_admin, sizeof frmt_ban_admin, "[A] %s попытался забанить Администратора %s", PN(playerid), PN(target));
 		SendAdminsMessage(COLOR_GREY, frmt_ban_admin);
 		return 1;
	}

	if(PI[target][pAdmin] && (PI[playerid][pAdmin] < PI[target][pAdmin]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new query_auninvite[190 + 9];
	format(query_auninvite, sizeof query_auninvite, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0' WHERE `ID` = '%d'", PI[target][pID]);
	mysql_query(mysql, query_auninvite);

	PI[target][pFraction] = 0;
	PI[target][pRank] = 0;
	PI[target][pFWarns] = 0;
	PI[target][pFractionSkin] = 0;
	PI[target][pSubfraction] = 0;
	SetString(PI[target][pDateInvite], "00-00-0000");
	SetString(PI[target][pLastRank], "00-00-0000");
	PI[target][pDivision] = 0;
	UpdatePlayerData(target, "Division", PI[target][pDivision]);
	SetPlayerColor(target, 0xFFFFFF11);
	SetPlayerSkin(target, PI[target][pSkin]);
	SetPlayerArmour(target, 0);
	resetgun(target);

	new
		frmt_ban_text[193],
	    frmt_ban_dialog[448];

    format(frmt_ban_text, sizeof frmt_ban_text, "[S] Администратор %s забанил игрока %s на %d %s. Причина: %s", PN(playerid), PN(target), days, Declension_GetDays(days), reason);
    SendAdminsMessage(COLOR_RED, frmt_ban_text);
	format(frmt_ban_text, sizeof frmt_ban_text, "Администратор %s забанил игрока %s на %d %s. Причина: %s", PN(playerid), PN(target), days, Declension_GetDays(days), reason);
	SendClientMessage(target, COLOR_LIGHTRED, frmt_ban_text);
    AdminLog(PI[playerid][pID], PI[target][pID], "/sban");

	new
		d,
		m,
		y,
		hours,
		minutes;

	getdate(y, m, d);
	gettime(hours, minutes);
	format(frmt_ban_dialog, sizeof frmt_ban_dialog,
	"{FFFFFF}Внимание,\n\
	Ваш аккаунт заблокирован за нарушение правил сервера,\n\
	обязательно сделайте скриншот данного окна или Ваша жалоба не будет принята.\n\
	Дата выдачи наказания: {86B9FF}%d-%d-%d %d:%d{FFFFFF}\n\
	Срок наказания: {FFFF00}%d %s{FFFFFF}\n\
	Причина: {FFFF00}%s{FFFFFF}\n\
	Администратор, выдавший наказание: {FFFF00}%s", d, m, y, hours, minutes, days, Declension_GetDays(days), reason, PN(playerid));
	ShowPlayerDialogEx(target, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, PN(target), frmt_ban_dialog, !"Закрыть", !"");

	ServerBan(playerid, target, days, reason);
    J_Kick(target);

	return true;
}
#if defined _ALS_pc_cmd_sban
	#undef pc_cmd_sban
#else
	#define _ALS_pc_cmd_sban
#endif
#define pc_cmd_sban ah_pc_cmd_sban
#if defined ah_pc_cmd_sban
	forward ah_pc_cmd_sban(playerid);
#endif

CMD:auninvite(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /auninvite [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(!PI[target][pFraction])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не состоит во фракции");

	new query_auninvite[205];
	format(query_auninvite, sizeof query_auninvite, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0' WHERE `ID` = '%d'", PI[target][pID]);
	mysql_query(mysql, query_auninvite);
	if(PI[target][pHouseKey] != 0)
	{
		new houseid = PI[target][pHouseKey] - 1;
		new slot;
		for(new i;i<4;i++)
		{
			if(HouseInfo[houseid][hSkin][i] == PI[target][pFractionSkin])
			{
				slot = i;
				break;
			}
		}
		HouseInfo[houseid][hSkin][slot] = 0;
		UpdateHouseDress(houseid);
	}
	PI[target][pFraction] = 0;
	PI[target][pRank] = 0;
	PI[target][pFWarns] = 0;
	PI[target][pFractionSkin] = 0;
	PI[target][pSubfraction] = 0;
	SetString(PI[target][pDateInvite], "00-00-0000");
	SetString(PI[target][pLastRank], "00-00-0000");
	PI[target][pDivision] = 0;
	UpdatePlayerData(target, "Division", PI[target][pDivision]);
	SetPlayerColor(target, 0xFFFFFF11);
	SetPlayerSkin(target, PI[target][pSkin]);
	SetPlayerArmour(target, 0);
	resetgun(target);
    CheckPlayerGoCuff(target);

	new
		frmt_auninvite[64 + MAX_PLAYER_NAME];

	format(frmt_auninvite, sizeof frmt_auninvite, "Администратор %s уволил вас из организации", PN(playerid));
	SendClientMessage(target, 0xFF182DFF, frmt_auninvite);

	format(frmt_auninvite, sizeof frmt_auninvite, "{FF9900}[Успешно] {FFFFFF}Вы уволили игрока %s из организации", PN(target));
	SendClientMessage(playerid, COLOR_WHITE, frmt_auninvite);

	if(GotoInfo[target][gtID] != INVALID_PLAYER_ID)
	{
		new
		    cuff = GotoInfo[target][gtID];

		temp_cuffer_sender[cuff] = INVALID_PLAYER_ID;
		temp_cuffer_receiver[target] = INVALID_PLAYER_ID;

		f_TogglePlayerControllable(cuff, true);
		SetPlayerSpecialAction(cuff, 0);
	    ClearAnims(cuff);
        CheckPlayerGoCuff(cuff);
        CheckPlayerGoCuff(target);
	}
    AdminLog(PI[playerid][pID], PI[target][pID], "/auninvite");
	return true;
}
#if defined _ALS_pc_cmd_auninvite
	#undef pc_cmd_auninvite
#else
	#define _ALS_pc_cmd_auninvite
#endif
#define pc_cmd_auninvite ah_pc_cmd_auninvite
#if defined ah_pc_cmd_auninvite
	forward ah_pc_cmd_auninvite(playerid);
#endif

CMD:inter(playerid,params[])
{
	if(PI[playerid][pAdmin] < 5)
    	return 1;

	extract params -> new interior; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /inter [1 - 150]");

	if(interior < 1 || interior > 150)
    	return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /inter [1-150]");

 	switch(interior)
	{
	    case 1: SetPlayerPos(playerid, -25.884498,-185.868988,1003.546875),SetPlayerInterior(playerid, 17);
	    case 2: SetPlayerPos(playerid, 6.091179,-29.271898,1003.549438),SetPlayerInterior(playerid, 10);
	    case 3: SetPlayerPos(playerid, -30.946699,-89.609596,1003.546875),SetPlayerInterior(playerid, 18);
	    case 4: SetPlayerPos(playerid, -25.132598,-139.066986,1003.546875),SetPlayerInterior(playerid, 16);
	    case 5: SetPlayerPos(playerid, -27.312299,-29.277599,1003.557250),SetPlayerInterior(playerid, 4);
	    case 6: SetPlayerPos(playerid, -26.691598,-55.714897,1003.546875),SetPlayerInterior(playerid, 6);
	    case 7: SetPlayerPos(playerid, -1827.147338,7.207417,1061.143554),SetPlayerInterior(playerid, 14);
	    case 8: SetPlayerPos(playerid, -1861.936889,54.908092,1061.143554),SetPlayerInterior(playerid, 14);
	    case 9: SetPlayerPos(playerid, 1.808619,32.384357,1199.593750),SetPlayerInterior(playerid, 1);
	    case 10: SetPlayerPos(playerid, 315.745086,984.969299,1958.919067),SetPlayerInterior(playerid, 9);
	    case 11: SetPlayerPos(playerid, 286.148986,-40.644397,1001.515625),SetPlayerInterior(playerid, 1);
	    case 12: SetPlayerPos(playerid, 286.800994,-82.547599,1001.515625),SetPlayerInterior(playerid, 4);
	    case 13: SetPlayerPos(playerid, 296.919982,-108.071998,1001.515625),SetPlayerInterior(playerid, 6);
	    case 14: SetPlayerPos(playerid, 314.820983,-141.431991,999.601562),SetPlayerInterior(playerid, 7);
	    case 15: SetPlayerPos(playerid, 316.524993,-167.706985,999.593750),SetPlayerInterior(playerid, 6);
	    case 16: SetPlayerPos(playerid, 302.292877,-143.139099,1004.062500),SetPlayerInterior(playerid, 7);
	    case 17: SetPlayerPos(playerid, 298.507934,-141.647048,1004.054748),SetPlayerInterior(playerid, 7);
	    case 18: SetPlayerPos(playerid, 1038.531372,0.111030,1001.284484),SetPlayerInterior(playerid, 3);
	    case 19: SetPlayerPos(playerid, 444.646911,508.239044,1001.419494),SetPlayerInterior(playerid, 12);
	    case 20: SetPlayerPos(playerid, 2215.454833,-1147.475585,1025.796875),SetPlayerInterior(playerid, 15);
	    case 21: SetPlayerPos(playerid, 833.269775,10.588416,1004.179687),SetPlayerInterior(playerid, 3);
	    case 22: SetPlayerPos(playerid, -103.559165,-24.225606,1000.718750),SetPlayerInterior(playerid, 3);
	    case 23: SetPlayerPos(playerid, 963.418762,2108.292480,1011.030273),SetPlayerInterior(playerid, 1);
	    case 24: SetPlayerPos(playerid, -2240.468505,137.060440,1035.414062),SetPlayerInterior(playerid, 6);
	    case 25: SetPlayerPos(playerid, 663.836242,-575.605407,16.343263),SetPlayerInterior(playerid, 0);
	    case 26: SetPlayerPos(playerid, 2169.461181,1618.798339,999.976562),SetPlayerInterior(playerid, 1);
	    case 27: SetPlayerPos(playerid, 1889.953369,1017.438293,31.882812),SetPlayerInterior(playerid, 10);
	    case 28: SetPlayerPos(playerid, -2159.122802,641.517517,1052.381713),SetPlayerInterior(playerid, 1);
	    case 29: SetPlayerPos(playerid, 207.737991,-109.019996,1005.132812),SetPlayerInterior(playerid, 15);
	    case 30: SetPlayerPos(playerid, 204.332992,-166.694992,1000.523437),SetPlayerInterior(playerid, 14);
	    case 31: SetPlayerPos(playerid, 207.054992,-138.804992,1003.507812),SetPlayerInterior(playerid, 3);
	    case 32: SetPlayerPos(playerid, 203.777999,-48.492397,1001.804687),SetPlayerInterior(playerid, 1);
	    case 33: SetPlayerPos(playerid, 226.293991,-7.431529,1002.210937),SetPlayerInterior(playerid, 5);
	    case 34: SetPlayerPos(playerid, 161.391006,-93.159156,1001.804687),SetPlayerInterior(playerid, 18);
	    case 35: SetPlayerPos(playerid, 493.390991,-22.722799,1000.679687),SetPlayerInterior(playerid, 17);
	    case 36: SetPlayerPos(playerid, 501.980987,-69.150199,998.757812),SetPlayerInterior(playerid, 11);
	    case 37: SetPlayerPos(playerid, -227.027999,1401.229980,27.765625),SetPlayerInterior(playerid, 18);
	    case 38: SetPlayerPos(playerid, 457.304748,-88.428497,999.554687),SetPlayerInterior(playerid, 4);
	    case 39: SetPlayerPos(playerid, 454.973937,-110.104995,1000.077209),SetPlayerInterior(playerid, 5);
	    case 40: SetPlayerPos(playerid, 435.271331,-80.958938,999.554687),SetPlayerInterior(playerid, 6);
	    case 41: SetPlayerPos(playerid, 452.489990,-18.179698,1001.132812),SetPlayerInterior(playerid, 1);
	    case 42: SetPlayerPos(playerid, 681.557861,-455.680053,-25.609874),SetPlayerInterior(playerid, 1);
	    case 43: SetPlayerPos(playerid, 375.962463,-65.816848,1001.507812),SetPlayerInterior(playerid, 10);
	    case 44: SetPlayerPos(playerid, 369.579528,-4.487294,1001.858886),SetPlayerInterior(playerid, 9);
	    case 45: SetPlayerPos(playerid, 373.825653,-117.270904,1001.499511),SetPlayerInterior(playerid, 5);
	    case 46: SetPlayerPos(playerid, 381.169189,-188.803024,1000.632812),SetPlayerInterior(playerid, 17);
	    case 47: SetPlayerPos(playerid, 244.411987,305.032989,999.148437),SetPlayerInterior(playerid, 1);
	    case 48: SetPlayerPos(playerid, 271.884979,306.631988,999.148437),SetPlayerInterior(playerid, 2);
	    case 49: SetPlayerPos(playerid, 291.282989,310.031982,999.148437),SetPlayerInterior(playerid, 3);
	    case 50: SetPlayerPos(playerid, 302.180999,300.722991,999.148437),SetPlayerInterior(playerid, 4);
	    case 51: SetPlayerPos(playerid, 322.197998,302.497985,999.148437),SetPlayerInterior(playerid, 5);
	    case 52: SetPlayerPos(playerid, 346.870025,309.259033,999.155700),SetPlayerInterior(playerid, 6);
	    case 53: SetPlayerPos(playerid, -959.564392,1848.576782,9.000000),SetPlayerInterior(playerid, 17);
	    case 54: SetPlayerPos(playerid, 384.808624,173.804992,1008.382812),SetPlayerInterior(playerid, 3);
	    case 55: SetPlayerPos(playerid, 223.431976,1872.400268,13.734375),SetPlayerInterior(playerid, 0);
	    case 56: SetPlayerPos(playerid, 772.111999,-3.898649,1000.728820),SetPlayerInterior(playerid, 5);
	    case 57: SetPlayerPos(playerid, 774.213989,-48.924297,1000.585937),SetPlayerInterior(playerid, 6);
	    case 58: SetPlayerPos(playerid, 773.579956,-77.096694,1000.655029),SetPlayerInterior(playerid, 7);
	    case 59: SetPlayerPos(playerid, 1527.229980,-11.574499,1002.097106),SetPlayerInterior(playerid, 3);
	    case 60: SetPlayerPos(playerid, 1523.509887,-47.821197,1002.130981),SetPlayerInterior(playerid, 2);
	    case 61: SetPlayerPos(playerid, 2496.049804,-1695.238159,1014.742187),SetPlayerInterior(playerid, 3);
	    case 62: SetPlayerPos(playerid, 1267.663208,-781.323242,1091.906250),SetPlayerInterior(playerid, 5);
	    case 63: SetPlayerPos(playerid, 513.882507,-11.269994,1001.565307),SetPlayerInterior(playerid, 3);
	    case 64: SetPlayerPos(playerid, 2454.717041,-1700.871582,1013.515197),SetPlayerInterior(playerid, 2);
	    case 65: SetPlayerPos(playerid, 2527.654052,-1679.388305,1015.498596),SetPlayerInterior(playerid, 1);
	    case 66: SetPlayerPos(playerid, 2543.462646,-1308.379882,1026.728393),SetPlayerInterior(playerid, 2);
	    case 67: SetPlayerPos(playerid, 1212.019897,-28.663099,1000.953125),SetPlayerInterior(playerid, 3);
	    case 68: SetPlayerPos(playerid, 761.412963,1440.191650,1102.703125),SetPlayerInterior(playerid, 6);
	    case 69: SetPlayerPos(playerid, 1204.809936,-11.586799,1000.921875),SetPlayerInterior(playerid, 2);
	    case 70: SetPlayerPos(playerid, 1204.809936,13.897239,1000.921875),SetPlayerInterior(playerid, 2);
	    case 71: SetPlayerPos(playerid, 942.171997,-16.542755,1000.929687),SetPlayerInterior(playerid, 3);
	    case 72: SetPlayerPos(playerid, 964.106994,-53.205497,1001.124572),SetPlayerInterior(playerid, 3);
	    case 73: SetPlayerPos(playerid, -2640.762939,1406.682006,906.460937),SetPlayerInterior(playerid, 3);
	    case 74: SetPlayerPos(playerid, -729.276000,503.086944,1371.971801),SetPlayerInterior(playerid, 1);
	    case 75: SetPlayerPos(playerid, -794.806396,497.738037,1376.195312),SetPlayerInterior(playerid, 1);
	    case 76: SetPlayerPos(playerid, 2350.339843,-1181.649902,1027.976562),SetPlayerInterior(playerid, 5);
	    case 77: SetPlayerPos(playerid, 2807.619873,-1171.899902,1025.570312),SetPlayerInterior(playerid, 8);
	    case 78: SetPlayerPos(playerid, 318.564971,1118.209960,1083.882812),SetPlayerInterior(playerid, 5);
	    case 79: SetPlayerPos(playerid, 1412.639892,-1.787510,1000.924377),SetPlayerInterior(playerid, 1);
	    case 80: SetPlayerPos(playerid, 1302.519897,-1.787510,1001.028259),SetPlayerInterior(playerid, 18);
	    case 81: SetPlayerPos(playerid, 2522.000000,-1673.383911,14.866223),SetPlayerInterior(playerid, 0);
	    case 82: SetPlayerPos(playerid, -221.059051,1408.984008,27.773437),SetPlayerInterior(playerid, 18);
	    case 83: SetPlayerPos(playerid, 2324.419921,-1145.568359,1050.710083),SetPlayerInterior(playerid, 12);
	    case 84: SetPlayerPos(playerid, -975.975708,1060.983032,1345.671875),SetPlayerInterior(playerid, 10);
	    case 85: SetPlayerPos(playerid, 411.625976,-21.433298,1001.804687),SetPlayerInterior(playerid, 2);
	    case 86: SetPlayerPos(playerid, 418.652984,-82.639793,1001.804687),SetPlayerInterior(playerid, 3);
	    case 87: SetPlayerPos(playerid, 412.021972,-52.649898,1001.898437),SetPlayerInterior(playerid, 12);
	    case 88: SetPlayerPos(playerid, -204.439987,-26.453998,1002.273437),SetPlayerInterior(playerid, 16);
	    case 89: SetPlayerPos(playerid, -204.439987,-8.469599,1002.273437),SetPlayerInterior(playerid, 17);
	    case 90: SetPlayerPos(playerid, -204.439987,-43.652496,1002.273437),SetPlayerInterior(playerid, 3);
	    case 91: SetPlayerPos(playerid, 246.783996,63.900199,1003.640625),SetPlayerInterior(playerid, 6);
	    case 92: SetPlayerPos(playerid, 246.375991,109.245994,1003.218750),SetPlayerInterior(playerid, 10);
	    case 93: SetPlayerPos(playerid, 288.745971,169.350997,1007.171875),SetPlayerInterior(playerid, 3);
	    case 94: SetPlayerPos(playerid, -2029.798339,-106.675910,1035.171875),SetPlayerInterior(playerid, 3);
	    case 95: SetPlayerPos(playerid, -1398.065307,-217.028900,1051.115844),SetPlayerInterior(playerid, 7);
	    case 96: SetPlayerPos(playerid, -1398.103515,937.631164,1036.479125),SetPlayerInterior(playerid, 15);
	    case 97: SetPlayerPos(playerid, -1444.645507,-664.526000,1053.572998),SetPlayerInterior(playerid, 4);
	    case 98: SetPlayerPos(playerid, -1465.268676,1557.868286,1052.531250),SetPlayerInterior(playerid, 14);
	    case 99: SetPlayerPos(playerid, -1401.829956,107.051300,1032.273437),SetPlayerInterior(playerid, 1);
	    case 100: SetPlayerPos(playerid, -1790.378295,1436.949829,7.187500),SetPlayerInterior(playerid, 0);
	    case 101: SetPlayerPos(playerid, 1643.839843,-1514.819580,13.566620),SetPlayerInterior(playerid, 0);
	    case 102: SetPlayerPos(playerid, -1685.636474,1035.476196,45.210937),SetPlayerInterior(playerid, 0);
	    case 103: SetPlayerPos(playerid, 76.632553,-301.156829,1.578125),SetPlayerInterior(playerid, 0);
	    case 104: SetPlayerPos(playerid, 1059.895996,2081.685791,10.820312),SetPlayerInterior(playerid, 0);
	    case 105: SetPlayerPos(playerid, 1059.180175,2148.938720,10.820312),SetPlayerInterior(playerid, 0);
	    case 106: SetPlayerPos(playerid, 2131.507812,1600.818481,1008.359375),SetPlayerInterior(playerid, 1);
	    case 107: SetPlayerPos(playerid, 2315.952880,-1.618174,26.742187),SetPlayerInterior(playerid, 0);
	    case 108: SetPlayerPos(playerid, 2319.714843,-14.838361,26.749565),SetPlayerInterior(playerid, 0);
	    case 109: SetPlayerPos(playerid, 1710.433715,-1669.379272,20.225049),SetPlayerInterior(playerid, 18);
	    case 110: SetPlayerPos(playerid, 1494.325195,1304.942871,1093.289062),SetPlayerInterior(playerid, 3);
	    case 111: SetPlayerPos(playerid, 235.508994,1189.169897,1080.339966),SetPlayerInterior(playerid, 3);
	    case 112: SetPlayerPos(playerid, 223.043991,1289.259888,1082.199951),SetPlayerInterior(playerid, 1);
	    case 113: SetPlayerPos(playerid, 225.630997,1022.479980,1084.069946),SetPlayerInterior(playerid, 7);
	    case 114: SetPlayerPos(playerid, 295.138977,1474.469971,1080.519897),SetPlayerInterior(playerid, 15);
	    case 115: SetPlayerPos(playerid, 328.493988,1480.589966,1084.449951),SetPlayerInterior(playerid, 15);
	    case 116: SetPlayerPos(playerid, 385.803986,1471.769897,1080.209961),SetPlayerInterior(playerid, 15);
	    case 117: SetPlayerPos(playerid, 375.971985,1417.269897,1081.409912),SetPlayerInterior(playerid, 15);
	    case 118: SetPlayerPos(playerid, 490.810974,1401.489990,1080.339966),SetPlayerInterior(playerid, 2);
	    case 119: SetPlayerPos(playerid, 447.734985,1400.439941,1084.339966),SetPlayerInterior(playerid, 2);
	    case 120: SetPlayerPos(playerid, 227.722992,1114.389893,1081.189941),SetPlayerInterior(playerid, 5);
	    case 121: SetPlayerPos(playerid, 260.983978,1286.549927,1080.299927),SetPlayerInterior(playerid, 4);
	    case 122: SetPlayerPos(playerid, 221.666992,1143.389893,1082.679932),SetPlayerInterior(playerid, 4);
	    case 123: SetPlayerPos(playerid, 27.132700,1341.149902,1084.449951),SetPlayerInterior(playerid, 10);
	    case 124: SetPlayerPos(playerid, -262.601990,1456.619995,1084.449951),SetPlayerInterior(playerid, 4);
	    case 125: SetPlayerPos(playerid, 22.778299,1404.959961,1084.449951),SetPlayerInterior(playerid, 5);
	    case 126: SetPlayerPos(playerid, 140.278000,1368.979980,1083.969971),SetPlayerInterior(playerid, 5);
	    case 127: SetPlayerPos(playerid, 234.045990,1064.879883,1084.309937),SetPlayerInterior(playerid, 6);
	    case 128: SetPlayerPos(playerid, -68.294098,1353.469971,1080.279907),SetPlayerInterior(playerid, 6);
	    case 129: SetPlayerPos(playerid, -285.548981,1470.979980,1084.449951),SetPlayerInterior(playerid, 15);
	    case 130: SetPlayerPos(playerid, -42.581997,1408.109985,1084.449951),SetPlayerInterior(playerid, 8);
	    case 131: SetPlayerPos(playerid, 83.345093,1324.439941,1083.889893),SetPlayerInterior(playerid, 9);
	    case 132: SetPlayerPos(playerid, 260.941986,1238.509888,1084.259888),SetPlayerInterior(playerid, 9);
	    case 133: SetPlayerPos(playerid, 1133.069946,-9.573059,1000.750000),SetPlayerInterior(playerid, 12);
	    case 134: SetPlayerPos(playerid, 2464.109863,-1698.659912,1013.509949),SetPlayerInterior(playerid, 2);
	    case 135: SetPlayerPos(playerid, 416.8144,2537.6863,10.0000),SetPlayerInterior(playerid, 10);
	    case 136: SetPlayerPos(playerid, 2283.0396,-1137.5461,1050.8984),SetPlayerInterior(playerid, 11);
	    case 137: SetPlayerPos(playerid, 2208.5957,-1074.3628,1050.4844),SetPlayerInterior(playerid, 1);
	    case 138: SetPlayerPos(playerid, 2237.7783,-1077.3889,1049.0234),SetPlayerInterior(playerid, 2);
	    case 139: SetPlayerPos(playerid, 2233.4780,-1110.7450,1050.8828),SetPlayerInterior(playerid, 5);
	    case 140: SetPlayerPos(playerid, 2346.7014,-1184.1390,1027.9766),SetPlayerInterior(playerid, 5);
	    case 141: SetPlayerPos(playerid, 2232.1101,-1117.1912,1050.8828),SetPlayerInterior(playerid, 5);
	    case 142: SetPlayerPos(playerid, 2192.6206,-1202.7321,1049.0234),SetPlayerInterior(playerid, 6);
	    case 143: SetPlayerPos(playerid, 2313.0601,-1209.7261,1049.0234),SetPlayerInterior(playerid, 6);
	    case 144: SetPlayerPos(playerid, 2319.4553,-1023.3117,1050.2109),SetPlayerInterior(playerid, 9);
	    case 145: SetPlayerPos(playerid, 2251.8733,-1138.8230,1050.6328),SetPlayerInterior(playerid, 9);
	    case 146: SetPlayerPos(playerid, 2262.3333,-1138.4283,1050.6328),SetPlayerInterior(playerid, 10);
	    case 147: SetPlayerPos(playerid, -2044.7096,178.5866,28.8359),SetPlayerInterior(playerid, 1);
	    case 148: SetPlayerPos(playerid, 607.5771,-10.9472,1000.9153),SetPlayerInterior(playerid, 1);
	    case 149: SetPlayerPos(playerid, 612.9734,-75.8104,997.9922),SetPlayerInterior(playerid, 2);
	    case 150: SetPlayerPos(playerid, -1473.0231,755.9099,40.8029),SetPlayerInterior(playerid, 0);
	}
	return true;
}
#if defined _ALS_pc_cmd_inter
	#undef pc_cmd_inter
#else
	#define _ALS_pc_cmd_inter
#endif
#define pc_cmd_inter ah_pc_cmd_inter
#if defined ah_pc_cmd_inter
	forward ah_pc_cmd_inter(playerid);
#endif

CMD:olip(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

    extract params -> new string:nick[25]; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /olip [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");


    new
		nickname[MAX_PLAYER_NAME+1],
        query_check_lip[179],
		get_info[1280];

    mysql_escape_string(nick, nickname);

	format(query_check_lip, sizeof query_check_lip, "SELECT `Money`, `Bank`, `Level`, `Ban`, `ID`, `LastLogin`, `LastIP` FROM `accounts` WHERE `NickName` = '%s' LIMIT 0, 21", nick);
	new Cache:result = mysql_query(mysql, query_check_lip);
	new found = cache_get_row_count(mysql);

	if(!found)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Аккаунт с данным ником не найден"), cache_delete(result, mysql);

    strcat(get_info, "{FFFFFF}Ник\t\t\tДеньги\tБанк\tУровень\tБан (Дней)\tID\tЗаход\n");

	new
		money,
		bank,
		level,
		id,
		last_login[15],
		ban[30],
		ban_days,
		lip_count,
		ipaddress[18],
		bool:new_page;


	for(new i; i < found; i++)
	{
	    if(lip_count > 19 && found > 20)
		{
			new_page = true;
		    break;
		}
		money = cache_get_row_int(i, 0);
		bank = cache_get_row_int(i, 1);
		level = cache_get_row_int(i, 2);
		ban_days = cache_get_row_int(i, 3);
		id = cache_get_row_int(i, 4);
        cache_get_row(i, 5, last_login, mysql, sizeof last_login);
        cache_get_row(i, 6, ipaddress, mysql, sizeof last_login);

        if(!ban_days)
            format(ban, sizeof ban, "-");

		else
		    format(ban, sizeof ban, "{FF0000}Забанен (%d){FFFFFF}", ban_days);

		format(get_info, sizeof get_info, "%s%s\t\t%d\t%d\t%d\t\t%s\t\t%d\t%s\n", get_info, nickname, money, bank, level, ban, id, last_login);
	    lip_count++;
	    pTemp[playerid][pLipList]++;
	}

	cache_delete(result, mysql);

	SetString(pTemp[playerid][pLipIP], ipaddress);

	if(!new_page)
		ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, pTemp[playerid][pLipIP], get_info, !"Закрыть", !"");

	else
		ShowPlayerDialogEx(playerid, 898, DIALOG_STYLE_MSGBOX, pTemp[playerid][pLipIP], get_info, !"Закрыть", !"");

    AdminLog(PI[playerid][pID], id, "/olip");
	return true;
}


CMD:offban(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new string:nick[25], days, string:reason[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /offban [Ник игрока] [Кол-во дней] [Причина]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(days < 1 || days > 30)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное кол-во дней");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок с данным именем находится на сервере. Выдать наказание не удалось");
		return 1;
	}

	new
	    nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
	    query_offwarn_getid[100];

	format(query_offwarn_getid, sizeof query_offwarn_getid, "SELECT `ID`, `Admin`, `Ban` FROM `accounts` WHERE `NickName` = '%s'", nickname);
	new Cache:result = mysql_query(mysql, query_offwarn_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
		id,
		admin,
		ban;

	id = cache_get_row_int(0, 0);
	admin = cache_get_row_int(0, 1);
	ban = cache_get_row_int(0, 2);

	cache_delete(result, mysql);

	if(admin >= 7)
	{
		new
			frmt_ban_admin[150];

		format(frmt_ban_admin, sizeof frmt_ban_admin, "[A] %s попытался выдать оффлайн бан Администратору %s", PN(playerid), nickname);
 		SendAdminsMessage(COLOR_GREY, frmt_ban_admin);
 		return 1;
	}

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	if(ban)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок имеет блокировку");

	new
	    frmt_offban_message[162],
		frmt_offban_query[110],
 		frmt_offban_update[93],
		query_offban[390];

	format(query_offban, sizeof query_offban, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0', `v_Days` = '0', `v_Fraction` = '0', `v_Rank` = '0', `v_Subfraction` = '0', `v_FractionSkin` = '0', `v_FWarns` = '0', `Division` = '0', `Warns` = `Warns`+1, `WarnTime` = `WarnTime`+7 WHERE `ID` = '%d'", id);
	mysql_query(mysql, query_offban);

	format(frmt_offban_message, sizeof frmt_offban_message, "Игрок %s получил оффлайн бан на %d %s от Администратора %s. Причина: %s", nickname, days, Declension_GetDays(days), PN(playerid), reason);
    ASCMTA(COLOR_LIGHTRED, frmt_offban_message);
	format(frmt_offban_query, sizeof frmt_offban_query, "INSERT INTO `ban` VALUES ('','%d','%d','%d','%s','0')", PI[playerid][pID], id, days, reason);
	mysql_query(mysql, frmt_offban_query);
	format(frmt_offban_update, sizeof frmt_offban_update, "UPDATE `accounts` SET `BanActivate` = '0', `Ban` = '%d' WHERE `ID` = '%d'", days, id);
	mysql_query(mysql, frmt_offban_update);

	AdminLog(PI[playerid][pID], id, "/offban");
	return true;
}
#if defined _ALS_pc_cmd_offban
	#undef pc_cmd_offban
#else
	#define _ALS_pc_cmd_offban
#endif
#define pc_cmd_offban ah_pc_cmd_offban
#if defined ah_pc_cmd_offban
	forward ah_pc_cmd_offban(playerid);
#endif

CMD:soffban(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new string:nick[25], days, string:reason[33]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /soffban [Ник игрока] [Кол-во дней] [Причина]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	if(days < 1 || days > 30)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное кол-во дней");

	if(strlen(reason) > 32)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинная причина");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок с данным именем находится на сервере. Выдать наказание не удалось");
		return 1;
	}

	new
	    nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
	    query_offwarn_getid[100];

	format(query_offwarn_getid, sizeof query_offwarn_getid, "SELECT `ID`, `Admin`, `Ban` FROM `accounts` WHERE `NickName` = '%s'", nickname);
	new Cache:result = mysql_query(mysql, query_offwarn_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
		id,
		admin,
		ban;

	id = cache_get_row_int(0, 0);
	admin = cache_get_row_int(0, 1);
	ban = cache_get_row_int(0, 2);

	cache_delete(result, mysql);

	if(admin >= 7)
	{
		new
			frmt_ban_admin[150];

		format(frmt_ban_admin, sizeof frmt_ban_admin, "[A] %s попытался выдать оффлайн бан Администратору %s", PN(playerid), nickname);
 		SendAdminsMessage(COLOR_GREY, frmt_ban_admin);
 		return 1;
	}

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	if(ban)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок имеет блокировку");

	new
	    frmt_offban_message[162],
		frmt_offban_query[110],
 		frmt_offban_update[93],
		query_offban[390];

	format(query_offban, sizeof query_offban, "UPDATE `accounts` SET `Fraction` = '0', `Rank` = '0', `FractionSkin` = '0', `Subfraction` = '0', `DateInvite` = '00-00-0000', `LastRank` = '00-00-0000', `FWarns` = '0', `v_Days` = '0', `v_Fraction` = '0', `v_Rank` = '0', `v_Subfraction` = '0', `v_FractionSkin` = '0', `v_FWarns` = '0', `Division` = '0', `Warns` = `Warns`+1, `WarnTime` = `WarnTime`+7 WHERE `ID` = '%d'", id);
	mysql_query(mysql, query_offban);

	format(frmt_offban_message, sizeof frmt_offban_message, "[S] Игрок %s получил оффлайн бан на %d %s от Администратора %s. Причина: %s", nickname, days, Declension_GetDays(days), PN(playerid), reason);
    SendAdminsMessage(COLOR_RED, frmt_offban_message);
	format(frmt_offban_query, sizeof frmt_offban_query, "INSERT INTO `ban` VALUES ('','%d','%d','%d','%s','0')", PI[playerid][pID], id, days, reason);
	mysql_query(mysql, frmt_offban_query);
	format(frmt_offban_update, sizeof frmt_offban_update, "UPDATE `accounts` SET `BanActivate` = '0', `Ban` = '%d' WHERE `ID` = '%d'", days, id);
	mysql_query(mysql, frmt_offban_update);

    AdminLog(PI[playerid][pID], id, "/soffban");
	return true;
}
#if defined _ALS_pc_cmd_soffban
	#undef pc_cmd_soffban
#else
	#define _ALS_pc_cmd_soffban
#endif
#define pc_cmd_soffban ah_pc_cmd_soffban
#if defined ah_pc_cmd_soffban
	forward ah_pc_cmd_soffban(playerid);
#endif

CMD:unban(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /unban [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	new
		nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
		query_getid[48 + MAX_PLAYER_NAME],
		frmt_unban_query[59],
		frmt_unban_upt[79],
		frmt_checkban_query[120],
		frmt_unban_message[85];

	format(query_getid, sizeof query_getid, "SELECT `ID` FROM `accounts` WHERE `NickName` = '%s'", nickname);

	new Cache:qID = mysql_query(mysql, query_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(qID, mysql);
	}

	new id = cache_get_row_int(0, 0);
	cache_delete(qID, mysql);

	format(frmt_checkban_query, sizeof frmt_checkban_query, "SELECT `takeid` FROM `ban` WHERE `takeid` = '%d'",id);

	new Cache:qCheckBan = mysql_query(mysql, frmt_checkban_query);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не забанен");
		return cache_delete(qCheckBan, mysql);
	}
	else
	{
		format(frmt_unban_message, sizeof frmt_unban_message, "[A] %s разбанил игрока %s", PN(playerid), nickname);
		SendAdminsMessage(COLOR_GREY, frmt_unban_message);
		format(frmt_unban_query, sizeof frmt_unban_query, "DELETE FROM `ban` WHERE `takeid` = '%d'", id);
		mysql_tquery(mysql, frmt_unban_query);
		format(frmt_unban_upt, sizeof frmt_unban_upt, "UPDATE `accounts` SET `BanActivate` = '0', `Ban` = '0' WHERE `ID` = '%d'", id);
		mysql_tquery(mysql, frmt_unban_upt);
	}
	cache_delete(qCheckBan, mysql);

	AdminLog(PI[playerid][pID], id, "/unban");
	return true;
}
#if defined _ALS_pc_cmd_unban
	#undef pc_cmd_unban
#else
	#define _ALS_pc_cmd_unban
#endif
#define pc_cmd_unban ah_pc_cmd_unban
#if defined ah_pc_cmd_unban
	forward ah_pc_cmd_unban(playerid);
#endif

CMD:deletegun(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new radius; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /deletegun [Радиус (от 1 до 100)]");

    if(radius < 1 || radius > 100)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /deletegun [радиус (1-100)]");

    new
		frmt_delgun_message[130];

    format(frmt_delgun_message, sizeof frmt_delgun_message, "Вы иъяли оружие у игроков в радиусе %d метров", radius);
    SendClientMessage(playerid, COLOR_WHITE, frmt_delgun_message);


    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        if(IsPlayerConnected(i) && IsPlayerLogged[i])
        {
			if(GetPlayerDistanceToPlayer(playerid, i) < radius)
			{
	            resetgun(i);
				format(frmt_delgun_message, sizeof frmt_delgun_message, "Администратор %s изъял Ваше оружие", PN(playerid));
				SendClientMessage(i, COLOR_WHITE, frmt_delgun_message);
			}
		}
    }

	return true;
}
#if defined _ALS_pc_cmd_deletegun
	#undef pc_cmd_deletegun
#else
	#define _ALS_pc_cmd_deletegun
#endif
#define pc_cmd_deletegun ah_pc_cmd_deletegun
#if defined ah_pc_cmd_deletegun
	forward ah_pc_cmd_deletegun(playerid);
#endif


CMD:getcar(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new vehicleid; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /getcar [ID транспорта]");

	new
		model = GetVehicleModel(vehicleid);

	if(0 == model)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID транспорта");

	new
		Float:x, Float:y, Float:z,
		frmt_getcar_message[90];

    GetPlayerPos(playerid, x, y, z);
    SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
    SetPVarInt(playerid, "anticheat_tp", gettime()+1);
    SetVehiclePos(vehicleid, x-4, y, z+1);

    format(frmt_getcar_message, sizeof frmt_getcar_message, "[A] %s телепортировал к себе транспорт %d", PN(playerid), vehicleid);
	SendAdminsMessage(COLOR_GREY, frmt_getcar_message);
	return true;
}
#if defined _ALS_pc_cmd_getcar
	#undef pc_cmd_getcar
#else
	#define _ALS_pc_cmd_getcar
#endif
#define pc_cmd_getcar ah_pc_cmd_getcar
#if defined ah_pc_cmd_getcar
	forward ah_pc_cmd_getcar(playerid);
#endif

CMD:msg(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new string:text[100]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /msg [Текст]");

	if(strlen(text) > 120)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный текст");

	new
	    frmt_msg_message[200];

	format(frmt_msg_message, sizeof frmt_msg_message, "Администратор %s: %s", PN(playerid), text);
    SendClientMessageToAll(0xFFCD00FF, frmt_msg_message);
	return true;
}
#if defined _ALS_pc_cmd_msg
	#undef pc_cmd_msg
#else
	#define _ALS_pc_cmd_msg
#endif
#define pc_cmd_msg ah_pc_cmd_msg
#if defined ah_pc_cmd_msg
	forward ah_pc_cmd_msg(playerid);
#endif

CMD:startmp(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

    extract params -> new count; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /startmp [Кол-во игроков]");

    if(count < 5 || count > 49)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное кол-во игроков (5-50)");

    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        if(!IsPlayerConnected(i) || !IsPlayerLogged[i])
            continue;

        if(pTemp[i][pOnMP])
            pTemp[i][pOnMP] = false;
    }

	new
		frmt_start_mp[142];

	format(frmt_start_mp, sizeof frmt_start_mp, "\n\n{FFFFFF}Введите текст мероприятия (макс. 100 сим.):\n\
    Игроки будут телепортированы на место вашей позиции\n\
	(Количество игроков: %d)\n\n", count);

	temp_mp_players = count;

    ShowPlayerDialogEx(playerid, 414, DIALOG_STYLE_INPUT, !"Мероприятие", frmt_start_mp, !"Создать", !"Отмена");

	return true;
}


CMD:stopmp(playerid)
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	if(!temp_mp_status)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}В данный момент не проводится мероприятие");

	temp_mp_status = false;
	temp_mp_pos_x = 0;
	temp_mp_pos_y = 0;
	temp_mp_pos_z = 0;
	temp_mp_interior = 0;
	temp_mp_world = 0;
	temp_mp_players = 0;
	temp_mp_ongame = 0;

	new
	    frmt_stopmp[MAX_PLAYER_NAME + 25];

	format(frmt_stopmp, sizeof frmt_stopmp, "%s закрыл телепорт на МП", PN(playerid));
	SendAdminsMessage(0x037AFAFF, frmt_stopmp);
	return true;
}

CMD:mp(playerid)
{
    if(PI[playerid][pJailTime] != 0)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Команда не доступна в тюрьме");

	if(!temp_mp_status || temp_mp_ongame > temp_mp_players)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}В данный момент не проводится мероприятие либо все места заняты");

	if(pTemp[playerid][pOnMP])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы уже находитесь на мероприятии");

	SetPlayerPos(playerid, temp_mp_pos_x, temp_mp_pos_y, temp_mp_pos_z);
	SetPlayerVirtualWorld(playerid, temp_mp_world);
	SetPlayerInterior(playerid, temp_mp_interior);
	pTemp[playerid][pOnMP] = true;


	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы были телепортированы на мероприятие");
	return true;
}


CMD:aheal(playerid, params[])
{
    if(PI[playerid][pAdmin] < 5)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /aheal [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(!PI[target][pDisease])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У игрока нет болезней");

	PI[target][pDisease] = 0;
	UpdatePlayerData(target, "Disease", PI[target][pDisease]);

	new
		frmt_healing[70 + MAX_PLAYER_NAME];

	format(frmt_healing, sizeof frmt_healing, "Администратор %s вылечил Вас от всех болезней", PN(playerid));
	SendClientMessage(target, 0xFF182DFF, frmt_healing);

	format(frmt_healing, sizeof frmt_healing, "[A] %s вылечил %s от всех болезней", PN(playerid), PN(target));
	SendAdminsMessage(COLOR_GREY, frmt_healing);

	return true;
}
#if defined _ALS_pc_cmd_aheal
	#undef pc_cmd_aheal
#else
	#define _ALS_pc_cmd_aheal
#endif
#define pc_cmd_aheal ah_pc_cmd_aheal
#if defined ah_pc_cmd_aheal
	forward ah_pc_cmd_aheal(playerid);
#endif

CMD:earstc(playerid, params[])
{
	if(PI[playerid][pAdmin] < 5)
		return 1;

	if(temp_ears_testchat[playerid])
	    temp_ears_testchat[playerid] = 0, SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы отключили прослушку чата тестеров");

	else
	    temp_ears_testchat[playerid] = 1, SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы включили прослушку чата тестеров");


	return true;
}
CMD:gzcolor(playerid,params[])
{
  	if(PI[playerid][pAdmin] < 5)
	  	return 1;

	extract params -> new id_gang; else
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}/gzcolor [параметр (2-6)]");

	if(id_gang < 2 || id_gang > 6)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный параметр");

	if(GhettoRasform)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Гетто заморожено");

	for(new i; i <= MAX_GANGZONE; i++)
	{
		if(PlayerToKvadrat(playerid, GZMZ[i][gCoords][0], GZMZ[i][gCoords][1], GZMZ[i][gCoords][2], GZMZ[i][gCoords][3]) && ZoneOnBattle[i] == 0)
		{
			GZMZ[i][gGang] = id_gang;
			GangZoneStopFlashForAll(GZMZ[i][gCreate]);
			GangZoneHideForAll(GZMZ[i][gCreate]);
			GangZoneShowForAll(GZMZ[i][gCreate], GetGangZoneColor(i));
			SaveGZ(i);
			return 1;
		}
	}
	return true;
}
CMD:setweather(playerid, params[])
{
    if(PI[playerid][pAdmin] < 6)
		return 1;

	new list_weather [] =
		!"1) Разные версии синих небес/облаков\n2) Разные версии синих небес/облаков\n3) Разные версии синих небес/облаков\n\
		4) Разные версии синих небес/облаков\n5) Разные версии синих небес/облаков\n6) Разные версии синих небес/облаков\n\
		7) Разные версии синих небес/облаков\n8) Гроза\n9) Пасмурно и туман\n10) Ясное синее небо\n11) Обжигающая жаркая\n\
		12) Очень тусклый, бесцветный, смутные\n13) Очень тусклый, бесцветный, смутные\n14) Очень тусклый, бесцветный, смутные\n\
		15) Очень тусклый, бесцветный, смутные\n16) Тусклый, неясный, дождливые\n17) Опаливая горячие\n18) Опаливая горячие\n19) Песчаная буря\n\
		20) Туманный/зеленоватые\n21) Очень темное, gradiented очертание, пурпурные\n22) Очень темное, gradiented очертание, зеленые\n\
		23) Изменения бледного апельсина\n26) Изменения бледного апельсина\n27) Изменения свежий синие\n29) Изменения свежий синие\n\
		30) Изменения темного, неясного, чирка\n32) Изменения темного, неясного, чирка\n33) Темный, неясный, коричневый\n34) Синий/пурпурный, регулярный\n\
		35) Тусклые коричневые\n36) Яркий, туманный, апельсин\n38) Яркий, туманный, апельсин\n39) Чрезвычайно яркие\n\
		40) Ярезвычайно яркие\n42) Синий/пурпурные неясные\n43) Темные токсичные облака\n44) Черное/белое небо\n45) Черное/пурпурное небо\n\
		81) Небо темнеет независимо от времени суток\n91) Небо становится черным как ночью\n200) Приближается шторм";


	ShowPlayerDialogEx(playerid, 999, DIALOG_STYLE_LIST, !"Установка погоды", list_weather, !"Принять", !"Отмена");
	return true;
}
#if defined _ALS_pc_cmd_setweather
	#undef pc_cmd_setweather
#else
	#define _ALS_pc_cmd_setweather
#endif
#define pc_cmd_setweather ah_pc_cmd_setweather
#if defined ah_pc_cmd_setweather
	forward ah_pc_cmd_setweather(playerid);
#endif

CMD:agun(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new player:target, gun, ammo; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /agun [ID игрока] [ID оружие] [Кол-во патронов]");

	if(gun < 1 || gun > 46)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID оружия");

	if(ammo < 1 || ammo > 1500)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверное количество патронов");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	_GiveGun(target, gun, ammo);
	return 1;
}
#if defined _ALS_pc_cmd_agun
	#undef pc_cmd_agun
#else
	#define _ALS_pc_cmd_agun
#endif
#define pc_cmd_agun ah_pc_cmd_agun
#if defined ah_pc_cmd_agun
	forward ah_pc_cmd_agun(playerid);
#endif

CMD:makelead(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /makelead [ID игрока]");

	if(!IsPlayerConnected(target) || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(PI[target][pv_Fraction])
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок находится в отпуске");

	if(PI[target][pWarns])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У игрока присутствует варн");

	temp_makelead[playerid] = target;

	new
		frmt_makelead[300];

	for( new i; i < MAX_FRACTIONS; i ++ )
		format( frmt_makelead, sizeof frmt_makelead, "%s%s\n", frmt_makelead, gFractionName[i] );

	ShowPlayerDialogEx(playerid, 912, DIALOG_STYLE_LIST, PN(target), frmt_makelead, !"Далее", !"Отмена");

	AdminLog(PI[playerid][pID], PI[target][pID], "/makelead");
	return true;
}
CMD:offcapture(playerid)
{
  	if(PI[playerid][pAdmin] < 6)
	  	return 1;

	new
	    frmt_freeze_ghetto[33 + MAX_PLAYER_NAME];

	if(GhettoFreeze == 0)
	{
		GhettoFreeze = 1;

		format(frmt_freeze_ghetto, sizeof frmt_freeze_ghetto, "[A] %s заморозил гетто", PN(playerid));
		SendAdminsMessage(COLOR_LIGHTRED, frmt_freeze_ghetto);
	}
	else
	{
		GhettoFreeze = 0;

		format(frmt_freeze_ghetto, sizeof frmt_freeze_ghetto, "[A] %s разморозил гетто", PN(playerid));
		SendAdminsMessage(COLOR_LIGHTRED, frmt_freeze_ghetto);
	}

    return true;
}
CMD:offbizwar(playerid)
{
  	if(PI[playerid][pAdmin] < 6)
	  	return 1;

	new
	    frmt_freeze_mafia[33 + MAX_PLAYER_NAME];

	if(MafiaFreeze == 0)
	{
		MafiaFreeze = 1;

		format(frmt_freeze_mafia, sizeof frmt_freeze_mafia, "[A] %s заморозил мафии", PN(playerid));
		SendAdminsMessage(COLOR_LIGHTRED, frmt_freeze_mafia);
	}
	else
	{
		MafiaFreeze = 0;

		format(frmt_freeze_mafia, sizeof frmt_freeze_mafia, "[A] %s разморозил мафии", PN(playerid));
		SendAdminsMessage(COLOR_LIGHTRED, frmt_freeze_mafia);
	}

    return true;
}
CMD:rasform(playerid)
{
  	if(PI[playerid][pAdmin] < 6)
	  	return 1;

	GhettoRasform = 1;

	new
	    frmt_freeze_ghetto[40 + MAX_PLAYER_NAME];


	format(frmt_freeze_ghetto, sizeof frmt_freeze_ghetto, "[A] %s разформировал гетто", PN(playerid));
	SendAdminsMessage(COLOR_LIGHTRED, frmt_freeze_ghetto);

	SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Изменения будут применены после рестарта");

	mysql_query(mysql, "TRUNCATE `gangzone`");
	mysql_query(mysql, "INSERT INTO `gangzone` (`id`, `Coords[0]`, `Coords[1]`, `Coords[2]`, `Coords[3]`, `Gang`) VALUES\
	(1, 1770.06, -1283.66, 1890.06, -1183.66, 2),\
	(2, 1890.06, -1283.66, 2010.06, -1183.66, 2),\
	(3, 1770.06, -2183.66, 1890.06, -2083.66, 4),\
	(4, 1890.06, -2183.66, 2010.06, -2083.66, 4),\
	(5, 2010.06, -2183.66, 2130.06, -2083.66, 4),\
	(6, 2130.06, -2183.66, 2250.06, -2083.66, 4),\
	(7, 2730.06, -1383.66, 2850.06, -1283.66, 5),\
	(8, 2610.06, -1383.66, 2730.06, -1283.66, 5),\
	(9, 2490.06, -1383.66, 2610.06, -1283.66, 5),\
	(10, 2370.06, -1383.66, 2490.06, -1283.66, 2),\
	(11, 2250.06, -1383.66, 2370.06, -1283.66, 2),\
	(12, 2130.06, -1383.66, 2250.06, -1283.66, 3),\
	(13, 2010.06, -1383.66, 2130.06, -1283.66, 3),\
	(14, 1890.06, -1383.66, 2010.06, -1283.66, 2),\
	(15, 1770.06, -1383.66, 1890.06, -1283.66, 2),\
	(16, 2730.06, -1483.66, 2850.06, -1383.66, 5),\
	(17, 2610.06, -1483.66, 2730.06, -1383.66, 5),\
	(18, 2490.06, -1483.66, 2610.06, -1383.66, 5),\
	(19, 2370.06, -1483.66, 2490.06, -1383.66, 3),\
	(20, 2250.06, -1483.66, 2370.06, -1383.66, 3),\
	(21, 2130.06, -1483.66, 2250.06, -1383.66, 3),\
	(22, 2010.06, -1483.66, 2130.06, -1383.66, 3),\
	(23, 1890.06, -1483.66, 2010.06, -1383.66, 3),\
	(24, 1770.06, -1483.66, 1890.06, -1383.66, 3),\
	(25, 2730.06, -1583.66, 2850.06, -1483.66, 5),\
	(26, 2610.06, -1583.66, 2730.06, -1483.66, 5),\
	(27, 2490.06, -1583.66, 2610.06, -1483.66, 5),\
	(28, 2370.06, -1583.66, 2490.06, -1483.66, 3),\
	(29, 2250.06, -1583.66, 2370.06, -1483.66, 3),\
	(30, 2130.06, -1583.66, 2250.06, -1483.66, 3),\
	(31, 2010.06, -1583.66, 2130.06, -1483.66, 3),\
	(32, 1890.06, -1583.66, 2010.06, -1483.66, 3),\
	(33, 1770.06, -1583.66, 1890.06, -1483.66, 3),\
	(34, 2730.06, -1683.66, 2850.06, -1583.66, 5),\
	(35, 2610.06, -1683.66, 2730.06, -1583.66, 5),\
	(36, 2490.06, -1683.66, 2610.06, -1583.66, 5),\
	(37, 2370.06, -1683.66, 2490.06, -1583.66, 3),\
	(38, 2250.06, -1683.66, 2370.06, -1583.66, 3),\
	(39, 2130.06, -1683.66, 2250.06, -1583.66, 3),\
	(40, 2010.06, -1683.66, 2130.06, -1583.66, 3),\
	(41, 1890.06, -1683.66, 2010.06, -1583.66, 3),\
	(42, 1770.06, -1683.66, 1890.06, -1583.66, 3),\
	(43, 2730.06, -1783.66, 2850.06, -1683.66, 6),\
	(44, 2610.06, -1783.66, 2730.06, -1683.66, 6),\
	(45, 2490.06, -1783.66, 2610.06, -1683.66, 6),\
	(46, 2370.06, -1783.66, 2490.06, -1683.66, 6),\
	(47, 2250.06, -1783.66, 2370.06, -1683.66, 4),\
	(48, 2130.06, -1783.66, 2250.06, -1683.66, 3),\
	(49, 2010.06, -1783.66, 2130.06, -1683.66, 3),\
	(50, 1890.06, -1783.66, 2010.06, -1683.66, 4),\
	(51, 1770.06, -1783.66, 1890.06, -1683.66, 4),\
	(52, 2730.06, -1883.66, 2850.06, -1783.66, 6),\
	(53, 2610.06, -1883.66, 2730.06, -1783.66, 6),\
	(54, 2490.06, -1883.66, 2610.06, -1783.66, 6),\
	(55, 2370.06, -1883.66, 2490.06, -1783.66, 6),\
	(56, 2250.06, -1883.66, 2370.06, -1783.66, 4),\
	(57, 2130.06, -1883.66, 2250.06, -1783.66, 4),\
	(58, 2010.06, -1883.66, 2130.06, -1783.66, 4),\
	(59, 1890.06, -1883.66, 2010.06, -1783.66, 4),\
	(60, 1770.06, -1883.66, 1890.06, -1783.66, 4),\
	(61, 2730.06, -1983.66, 2850.06, -1883.66, 6),\
	(62, 2610.06, -1983.66, 2730.06, -1883.66, 6),\
	(63, 2490.06, -1983.66, 2610.06, -1883.66, 6),\
	(64, 2370.06, -1983.66, 2490.06, -1883.66, 6),\
	(65, 2250.06, -1983.66, 2370.06, -1883.66, 4),\
	(66, 2130.06, -1983.66, 2250.06, -1883.66, 4),\
	(67, 2010.06, -1983.66, 2130.06, -1883.66, 4),\
	(68, 1890.06, -1983.66, 2010.06, -1883.66, 4),\
	(69, 1770.06, -1983.66, 1890.06, -1883.66, 4),\
	(70, 2730.06, -2083.66, 2850.06, -1983.66, 6),\
	(71, 2610.06, -2083.66, 2730.06, -1983.66, 6),\
	(72, 2490.06, -2083.66, 2610.06, -1983.66, 6),\
	(73, 2370.06, -2083.66, 2490.06, -1983.66, 6),\
	(74, 2250.06, -2083.66, 2370.06, -1983.66, 4),\
	(75, 2130.06, -2083.66, 2250.06, -1983.66, 4),\
	(76, 2010.06, -2083.66, 2130.06, -1983.66, 4),\
	(77, 1890.06, -2083.66, 2010.06, -1983.66, 4),\
	(78, 1770.06, -2083.66, 1890.06, -1983.66, 4),\
	(79, 2730.06, -2183.66, 2850.06, -2083.66, 6),\
	(80, 2610.06, -2183.66, 2730.06, -2083.66, 6),\
	(81, 2490.06, -2183.66, 2610.06, -2083.66, 6),\
	(82, 2370.06, -2183.66, 2490.06, -2083.66, 6),\
	(83, 2250.06, -2183.66, 2370.06, -2083.66, 4),\
	(84, 2010.06, -1283.66, 2130.06, -1183.66, 3)");

	mysql_query(mysql, "INSERT INTO `gangzone` (`id`, `Coords[0]`, `Coords[1]`, `Coords[2]`, `Coords[3]`, `Gang`) VALUES\
	(85, 2130.06, -1283.66, 2250.06, -1183.66, 3),\
	(86, 2250.06, -1283.66, 2370.06, -1183.66, 2),\
	(87, 2370.06, -1283.66, 2490.06, -1183.66, 2),\
	(88, 2490.06, -1283.66, 2610.06, -1183.66, 5),\
	(89, 2610.06, -1283.66, 2730.06, -1183.66, 5),\
	(90, 2730.06, -1283.66, 2850.06, -1183.66, 5),\
	(91, 1770.06, -1183.66, 1890.06, -1083.66, 2),\
	(92, 1890.06, -1183.66, 2010.06, -1083.66, 2),\
	(93, 2010.06, -1183.66, 2130.06, -1083.66, 2),\
	(94, 2130.06, -1183.66, 2250.06, -1083.66, 2),\
	(95, 2250.06, -1183.66, 2370.06, -1083.66, 2),\
	(96, 2370.06, -1183.66, 2490.06, -1083.66, 2),\
	(97, 2490.06, -1183.66, 2610.06, -1083.66, 5),\
	(98, 2610.06, -1183.66, 2730.06, -1083.66, 5),\
	(99, 2730.06, -1183.66, 2850.06, -1083.66, 5),\
	(100, 1770.06, -1083.66, 1890.06, -983.657, 2),\
	(101, 1890.06, -1083.66, 2010.06, -983.657, 2),\
	(102, 2010.06, -1083.66, 2130.06, -983.657, 2),\
	(103, 2130.06, -1083.66, 2250.06, -983.657, 2),\
	(104, 2250.06, -1083.66, 2370.06, -983.657, 2),\
	(105, 2370.06, -1083.66, 2490.06, -983.657, 2),\
	(106, 2490.06, -1083.66, 2610.06, -983.657, 5),\
	(107, 2610.06, -1083.66, 2730.06, -983.657, 5),\
	(108, 2730.06, -1083.66, 2850.06, -983.657, 5)");

	AdminLog(PI[playerid][pID], PI[playerid][pID], "/rasform");
	return true;
}
CMD:lego1(playerid)
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	ShowPlayerDialogEx(playerid, 348, DIALOG_STYLE_LIST, !"Редактор объектов", !"{FF7319}1.{FFFFFF} Инструкция\n{FF7319}2.{FFFFFF} Создать объект\n{FF7319}3.{FFFFFF} Изменить карту\n{FF7319}4.{FFFFFF} Удалить все", !"Выбрать", !"Отмена");
	return true;
}
CMD:makeadmin(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new player:target, level; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /makeadmin [ID игрока] [Уровень]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

    if(PI[playerid][pAdmin] == 7 && level > 7)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}У Вас недостаточно прав");

	if(level < 0 || level > 6)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный уровень");

    PI[target][pAdmin] = level;
	UpdatePlayerData(target, "Admin", PI[target][pAdmin]);

	new
	    frmt_makeadmin_message[110];

	if(level == 0)
    {
	    format(frmt_makeadmin_message, sizeof frmt_makeadmin_message, "Вы сняли игрока %s с должности администратора", PN(target));
	    SendClientMessage(playerid, COLOR_YELLOW, frmt_makeadmin_message);

    	format(frmt_makeadmin_message, sizeof frmt_makeadmin_message, "%s снял Вас с должности администратора", PN(playerid));
		SendClientMessage(target, COLOR_YELLOW, frmt_makeadmin_message);

		if(Iter_Contains(Connect_Admin, target))
			Iter_Remove(Connect_Admin, target);
    }
    else
    {
	    format(frmt_makeadmin_message, sizeof frmt_makeadmin_message, "Вы выдали игроку %s %d-й уровень администратирования", PN(target), level);
	    SendClientMessage(playerid, COLOR_YELLOW, frmt_makeadmin_message);

	    format(frmt_makeadmin_message, sizeof frmt_makeadmin_message, "[A] %s назначил %s администратором %d-го уровня", PN(playerid), PN(target),level);
		SendAdminsMessage(COLOR_LIGHTRED, frmt_makeadmin_message);
        SendClientMessage(target,-1,"{FFC800}[Подсказка] {FFFFFF}Код Администратора: {FF7319}12345");
        SendClientMessage(target,COLOR_GREY,"Не забудьте сохранить код Администратора.");
        SendClientMessage(target,COLOR_GREY,"Изменить код Администратора можно в настройках.");

		if(!Iter_Contains(Connect_Admin, target))
			Iter_Add(Connect_Admin, target);
	}

	AdminLog(PI[playerid][pID], PI[target][pID], "/makeadmin");
	return true;
}
CMD:banip(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new string:ipaddress[20]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /banip [IP адрес]");

	if(strlen(ipaddress) < 1 || strlen(ipaddress) > 16)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком короткий или длинный IP адрес");

	new regex:rip = regex_new("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])[^[:digit:]^[:cntrl:]]){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");

	if(!regex_check(ipaddress, rip))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный IP адрес"), regex_delete(rip);

    regex_delete(rip);

	new
	    frmt_banip_mes[30 + MAX_PLAYER_NAME + 16];

	format(frmt_banip_mes, sizeof frmt_banip_mes, "[A] %s забанил IP %s", PN(playerid), ipaddress);
    SendAdminsMessage(COLOR_GREY, frmt_banip_mes);

    SendClientMessage(playerid, COLOR_GREY, !"IP адрес забанен!");

	new
		frmt_banip_rcon[6 + 16];

	format(frmt_banip_rcon, sizeof frmt_banip_rcon, "banip %s", ipaddress);

	SendRconCommand(frmt_banip_rcon);
	SendRconCommand("reloadbans");

	AdminLog(PI[playerid][pID], PI[playerid][pID], "/banip");
	return true;
}
CMD:unbanip(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new string:ipaddress[20]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /banip [IP адрес]");

	if(strlen(ipaddress) < 1 || strlen(ipaddress) > 16)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком короткий или длинный IP адрес");

	new regex:rip = regex_new("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])[^[:digit:]^[:cntrl:]]){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");

	if(!regex_check(ipaddress, rip))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный IP адрес"), regex_delete(rip);

    regex_delete(rip);

	new
		frmt_unban_rcon[8 + 24],
		frmt_unban_achat[32 + MAX_PLAYER_NAME + 24];

	format(frmt_unban_rcon, sizeof frmt_unban_rcon,"unbanip %s", ipaddress);
	SendRconCommand(frmt_unban_rcon);

	format(frmt_unban_achat, sizeof frmt_unban_achat, "[A] %s разбанил IP %s", PN(playerid), ipaddress);
    SendAdminsMessage(COLOR_GREY, frmt_unban_achat);

    SendRconCommand("reloadbans");
    AdminLog(PI[playerid][pID], PI[playerid][pID], "/unbanip");
	return true;
}
CMD:deladminoff(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /deladminoff [Ник игрока]");

	if(strlen(nick) < 1 || strlen(nick) > 16)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком короткий или длинный никнейм");

	if(GetPlayerID(nick) != INVALID_PLAYER_ID)
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок с данным именем находится на сервере");
		return 1;
	}

	new
	    nickname[MAX_PLAYER_NAME+1];

	mysql_escape_string(nick, nickname);

	new
	    query_deladm_getid[90];

	format(query_deladm_getid, sizeof query_deladm_getid, "SELECT `ID`, `Admin` FROM `accounts` WHERE `NickName` = '%s'", nickname);
	new Cache:result = mysql_query(mysql, query_deladm_getid);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
		id,
		admin;

	id = cache_get_row_int(0, 0);
	admin = cache_get_row_int(0, 1);

	cache_delete(result, mysql);

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");

	new
	    query_deladm[67];

	format(query_deladm, sizeof query_deladm, "UPDATE `accounts` SET `Admin` = '0' WHERE `ID` = '%d'", id);
	mysql_query(mysql, query_deladm);

	format(query_deladm, sizeof query_deladm, "Вы сняли %s с поста администратора", nickname);
	SendClientMessage(playerid, COLOR_YELLOW, query_deladm);
	return true;
}
CMD:ssteretacc(playerid, params[])
{
    if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new string:nick[25]; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /ssteretacc [Ник игрока]");

	if(strlen(nick) > MAX_PLAYER_NAME)
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком длинный никнейм");

	new
		nickname[MAX_PLAYER_NAME+1],
		frmt_offget_check[180];

	mysql_escape_string(nick, nickname);

	format(frmt_offget_check, sizeof frmt_offget_check, "SELECT `ID`, `Money`, `Bank`, `Level`, `RegIP`, `OldIP`, `DateReg`, `VirMoney`, `Admin` FROM `accounts` WHERE `NickName` = '%s'",nickname);
	new Cache:result = mysql_query(mysql, frmt_offget_check);

	if(!cache_get_row_count(mysql))
	{
		SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный никнейм");
		return cache_delete(result, mysql);
	}

	new
	    id,
	    money,
	    bank,
	    level,
		regip[16],
		oldip[16],
		datereg[25],
		virmoney,
		admin;

 	id = cache_get_row_int(0, 0);
	money = cache_get_row_int(0, 1);
	bank = cache_get_row_int(0, 2);
	level = cache_get_row_int(0, 3);
	cache_get_row(0, 4, regip, mysql);
	cache_get_row(0, 5, oldip, mysql);
	cache_get_row(0, 6, datereg, mysql);
	virmoney = cache_get_row_int(0, 7);
	admin = cache_get_row_int(0, 8);

	cache_delete(result, mysql);

	if(admin && (PI[playerid][pAdmin] < admin))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Вы не можете применить это к администратору старше Вас уровнем");


	new
	    reg_country[90],
	    reg_city[90],
	 	last_country[90],
	 	last_city[90],
 		frmt_delacc[450];

	GetIPCountry(oldip, last_country, sizeof(last_country));
	GetIPCity(oldip, last_city, sizeof(last_city));
	GetIPCountry(regip, reg_country, sizeof(reg_country));
	GetIPCity(regip, reg_city, sizeof(reg_city));

	format(frmt_delacc, sizeof frmt_delacc, "{FFFFFF}Вы действительно хотите удалить аккаунт {FF9900}%s{FFFFFF}?\n\n{AAD4EE}\
	Номер аккаунта:\t\t%d\n\
	Наличные:\t\t\t%d$\n\
	Осн. банк счёт:\t\t\t%d$\n\
	Уровень:\t\t\t%d\n\
	IP адрес(регис.):\t\t%s (%s %s)\n\
	IP адрес(послед.):\t\t%s (%s %s)\n\
	Дата регистрации:\t\t%s\n\
	Донат:\t\t\t\t%d",
	nickname, id, money, bank, level, regip, reg_country, reg_city, oldip, last_country, last_city, datereg, virmoney);

	pTemp[playerid][pDelName] = id;

	ShowPlayerDialogEx(playerid, 878, DIALOG_STYLE_MSGBOX, !"Удаление аккаунта", frmt_delacc, !"Удалить", !"Отмена");

	AdminLog(PI[playerid][pID], id, "/ssteretacc");
	return true;
}
CMD:adminskin(playerid, params[])
{
	if(PI[playerid][pAdmin] < 6)
		return 1;

	extract params -> new player:target, skin; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /adminskin [ID игрока] [ID скина]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	if(skin < 1 || skin > 311)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}ID скина от 1 до 311");

	if(skin == 74)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID скина");

	if(!PI[target][pAdmin])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Игрок не администратор");

	if(GetPlayerSkin(target) == PI[target][pFractionSkin] && PI[target][pFraction])
	{
	    if(PI[target][pSex] == 1)
			SetPlayerSkinEx(target, OrgInfo[PI[target][pFraction]-1][oMSkins][PI[target][pRank]-1]);

	    else if(PI[target][pSex] == 2)
			SetPlayerSkinEx(target, OrgInfo[PI[target][pFraction]-1][oWSkins][PI[target][pRank]-1]);

		PI[target][pSkin] = skin, UpdatePlayerData(target, "Skin", PI[target][pSkin]);
	}
	else
		PI[target][pSkin] = skin, UpdatePlayerData(target, "Skin", PI[target][pSkin]), SetPlayerSkinEx(target,skin);

	if(PI[target][pHouseKey])
	{
		new
			houseid = PI[target][pHouseKey]-1,
			slot = -1;

		for(new i;i<4;i++)
		{
			if(skin == HouseInfo[houseid][hSkin][i])
				return 1;

			if(!HouseInfo[houseid][hSkin][i])
			{
				slot = i;
				break;
			}
		}
		if(slot != -1)
		{
			HouseInfo[target][hSkin][slot] = skin;
			UpdateHouseDress(target);
		}
	}

	new
	    frmt_skin_message[180];

	format(frmt_skin_message, sizeof frmt_skin_message, "Администратор %s установил Вам постоянный скин", PN(playerid));
	SendClientMessage(target, COLOR_WHITE, frmt_skin_message);
	format(frmt_skin_message, sizeof frmt_skin_message, "{FF9900}[Успешно] {FFFFFF}Вы успешно установили постоянный скин администратору %s", PN(target));
	SendClientMessage(playerid, COLOR_WHITE, frmt_skin_message);

	AdminLog(PI[playerid][pID], PI[target][pID], "/adminskin");
	return true;
}

CMD:agl(playerid, params[])
{
    if(PI[playerid][pAdmin] < 7)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /agl [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	PI[target][pCarLic] = YES_LICENSE;
	UpdatePlayerData(target, "CarLic", PI[target][pCarLic]);

	PI[target][pFlyLic] = YES_LICENSE;
	UpdatePlayerData(target, "FlyLic", PI[target][pFlyLic]);

	PI[target][pBoatLic] = YES_LICENSE;
	UpdatePlayerData(target, "BoatLic", PI[target][pBoatLic]);

	PI[target][pGunLic] = YES_LICENSE;
	UpdatePlayerData(target, "GunLic", PI[target][pGunLic]);

	SendClientMessage(playerid, COLOR_WHITE, !"{FF9900}[Успешно] {FFFFFF}Вы успешно выдали все лицензии");

	new
		frmt_agivelic_message[80];

	format(frmt_agivelic_message, sizeof frmt_agivelic_message, "Администратор %s выдал Вам все лицензии", PN(playerid));
	SendClientMessage(target, COLOR_GREY, frmt_agivelic_message);

	AdminLog(PI[playerid][pID], PI[target][pID], "/agl");
	return true;
}
CMD:payday(playerid)
{
    if(PI[playerid][pAdmin] < 7) return 1;
    payday_admin = true;
    PayDay();
    SendClientMessage(playerid,-1,"- Вы запустили PayDay");
    return true;
}
CMD:secretbag(playerid, params[])
{
    if(PI[playerid][pAdmin] < 7)
		return 1;


    if(sscanf(params,"d",params[0]))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /secretbag [сумма]");

	if(params[0] < 10000 || params[0] > 1000000)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Cумма от 10000$ до 1000000$");

	if(bag_count > 9)
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Слишком много мешов на карте!");

    new
		Float:bagx,
		Float:bagy,
	 	Float:bagz;

 	GetPlayerPos(playerid, bagx, bagy, bagz);

 	bag_area[bag_count] = CreateDynamicSphere(bagx+1.5, bagy, bagz, 1.0, 0, 0);
	bag_pickup[bag_count] = CreateDynamicPickup(1550, 1, bagx+1.5, bagy, bagz, 0, 0);
	bag_value[bag_count] = params[0];

	bag_count++;

	new
		string[128];

	format(string, sizeof string, "{FFFFFF}[Внимание] {FFD700}На карте появился мешочек с деньгами. Найдите его и получите %d$", params[0]);

 	SCMTA(COLOR_WHITE, string);
    return true;
}
CMD:setstat(playerid, params[])
{
	if(PI[playerid][pAdmin] < 7)
		return 1;

	extract params -> new player:target, number, value; else
 	{
        SendClientMessage(playerid, COLOR_GREY, !"/setstat [ID игрока] [Номер данных] [Значение]");
        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"Номера данных: 1)Пол 2)Возраст 3)Работа");
        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"4)Скин 5)Деньги 6)Банк 7)Уровень 8)Exp 9)Номер телефона");
        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"10)Наркотики 11)Лицензия вождение 12)Лицензия полёты");
        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"13)Лицензия лодки 14)Лицензия оружие 15)Донат");
        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"16)Патроны 17)Ед.оружия 18)Фракц. скин 19)Цвет кожи 20)Законопослушность 21)Промокод 22) Макс. навык");
		return 1;
	}

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	new
		str[100];

	switch(number)
	{
		case 1:
		{
	        if(value < 1 || value > 2)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Пол | 1)Мужской 2)Женский");

	        PI[target][pSex] = value;
	        UpdatePlayerData(target, "Sex", PI[target][pSex]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили пол %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
		}
	    case 2:
	    {
	        if(value < 10 || value > 110)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Возраст не может быть менее 10 и более 110");

			PI[target][pAge] = value;
	        UpdatePlayerData(target, "Age", PI[target][pAge]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили возраст %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 3:
	    {
	        if(value < 1 || value > 3)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Работа | 1) Автобусник 2) Таксист 3) Дальнобойщики");

			PI[target][pJob] = value;
	        UpdatePlayerData(target, "Job", PI[target][pJob]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили место работы %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 4:
	    {
     		if(value < 1 || value > 311)
			 	return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}ID скина от 1 до 311");

	        PI[target][pSkin] = value;
	        UpdatePlayerData(target, "Skin", PI[target][pSkin]);

	    	format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили скин %s", PN(target));

	        if(!PI[target][pFraction]) SetPlayerSkin(target, value);
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 5:
	    {
     		if(value < 0 || value > 100000000)
	 			return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Максимальная сумма 100 000 000$");

	        PI[target][pMoney] = value;
	        UpdatePlayerData(target, "Money", PI[target][pMoney]);
	        GivePlayerMoney(target, PI[target][pMoney]);

	    	format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество денег %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 6:
	    {
	        PI[target][pBank] = value;
	        UpdatePlayerData(target, "Bank", PI[target][pBank]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество денег в банке %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 7:
	    {
    		if(value < 1 || value > 35)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Уровень игрока от 1 до 35");

		    PI[target][pLevel] = value;
			SetPlayerScore(target, value);
		    UpdatePlayerData(target, "Level", PI[target][pLevel]);

   			format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили уровень игрока %s", PN(target));
		    SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 8:
	    {
	        PI[target][pExp] = value;
	        UpdatePlayerData(target, "Exp", PI[target][pExp]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили EXP игрока %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 9:
		{
	        PI[target][pTelNum] = value;
	        UpdatePlayerData(target, "TelNum", PI[target][pTelNum]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили номер телефона %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 10:
	    {
	        PI[target][pDrugs] = value;
	        UpdatePlayerData(target, "Drugs", PI[target][pDrugs]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество наркотиков у %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 11:
	    {
	        if(value)
			{
	            PI[target][pCarLic] = YES_LICENSE;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы выдали %s лицензию на вождение", PN(target));
	        }
	        else
			{
	            PI[target][pCarLic] = 0;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы забрали лицензию на вождение у %s", PN(target));
	        }
			UpdatePlayerData(target, "CarLic", PI[target][pCarLic]);

	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 12:
	    {
	        if(value)
			{
	           	PI[target][pFlyLic] = YES_LICENSE;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы выдали %s лицензию на полёты", PN(target));
	        }
	        else
			{
	            PI[target][pFlyLic] = 0;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы забрали лицензию на полёты у %s", PN(target));
	        }
			UpdatePlayerData(target, "FlyLic", PI[target][pFlyLic]);

	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 13:
	    {
	        if(value)
			{
	            PI[target][pBoatLic] = YES_LICENSE;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы выдали %s лицензию на лодку", PN(target));
	        }
	        else
			{
	            PI[target][pBoatLic] = 0;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы забрали лицензию на лодку у %s", PN(target));
	        }
            UpdatePlayerData(target, "BoatLic", PI[target][pBoatLic]);
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 14:
	    {
	        if(value)
			{
	            PI[target][pGunLic] = YES_LICENSE;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы выдали %s лицензию на оружие", PN(target));
	        }
	        else
			{
	            PI[target][pGunLic] = 0;
	            format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы забрали лицензию на оружие у %s", PN(target));
	        }
            UpdatePlayerData(target, "GunLic", PI[target][pGunLic]);
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 15:
	    {
	        PI[target][pVirMoney] = value;
	        UpdatePlayerData(target, "VirMoney", PI[target][pVirMoney]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество доната у %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 16:
	    {
	        PI[target][pMats] = value;
	        UpdatePlayerData(target, "Mats", PI[target][pMats]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество патрон у %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 17:
	    {
	        PI[target][pPackets] = value;
	        UpdatePlayerData(target, "Packets", PI[target][pPackets]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили количество ед. оружия у %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 18:
		{
     		if(value < 1 || value > 311)
			 	return SendClientMessage(playerid, COLOR_WHITE, !"ID скина от 1 до 311");

	        PI[target][pFractionSkin] = value;
	        UpdatePlayerData(target, "FractionSkin", PI[target][pFractionSkin]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили фракц. скин %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 19:
		{
	        if(value < 1 || value > 2)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Цвет | 1)Черный 2)Светлый");

	        PI[target][pRace] = value-1;
	        UpdatePlayerData(target, "Race", PI[target][pRace]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили цвет кожи %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 20:
		{
    		if(value < 1 || value > 100)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Законопослушность игрока от 1 до 100");

	        PI[target][pZKP] = value;
	        UpdatePlayerData(target, "ZKP", PI[target][pZKP]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили законопослушность %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
	    case 21:
	    {
	        PI[target][pCPromo] = value;
	        UpdatePlayerData(target, "CPromo", PI[target][pCPromo]);

	        new
	            query_updt_promo[70];

			format(query_updt_promo, sizeof query_updt_promo, "UPDATE `promoyt` SET `pcOwnerID` = '%d' WHERE `pcID` = '%d'", PI[target][pID], PI[target][pCPromo]);
			mysql_tquery(mysql, query_updt_promo, "", "");

			gPromo[value-1][pcOwnerID] = PI[target][pID];

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили промокод %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);

	    }
	    case 22:
		{
	        if(value < 1 || value > 2)
				return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Навык 1)");

	        PI[target][pTruckSkill] = 250;
	        UpdatePlayerData(target, "TruckSkill", PI[target][pTruckSkill]);

	        format(str, sizeof str, "{FF9000}[Успешно] {FFFFFF}Вы успешно изменили навык игроку %s", PN(target));
	        SendClientMessage(playerid, COLOR_WHITE, str);
	    }
		default:
		{
	        SendClientMessage(playerid, COLOR_GREY, !"/setstat [ID игрока] [Номер данных] [Значение]");
	        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"Номера данных: 1)Пол 2)Возраст 3)Работа");
	        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"4)Скин 5)Деньги 6)Банк 7)Уровень 8)Exp 9)Номер телефона");
	        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"10)Наркотики 11)Лицензия вождение 12)Лицензия полёты");
	        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"13)Лицензия лодки 14)Лицензия оружие 15)Донат");
	        SendClientMessage(playerid, COLOR_LIGHTGREEN, !"16)Патроны 17)Ед.оружия 18)Фракц. скин 19)Цвет кожи 20)Законопослушность 21)Промокод");
			return 1;
		}
	}
	return true;
}


CMD:unfreeze(playerid, params[])
{
    if(PI[playerid][pAdmin] < 4)
		return 1;

	extract params -> new player:target; else
	    return SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Используйте: /agl [ID игрока]");

	if(!IsPlayerConnected(target))
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Неверный ID игрока");

	if(!PI[target][pID] || !IsPlayerLogged[target])
		return SendClientMessage(playerid, COLOR_WHITE, !"{FF2222}[Ошибка] {FFFFFF}Этот игрок не зарегистрирован");

	f_TogglePlayerControllable(target, true);

    new
        frmt_unfreeze_mess[70];

    format(frmt_unfreeze_mess, sizeof frmt_unfreeze_mess, "{FF9000}[Успешно] {FFFFFF}Вы успешно разморозили игрока %s", PN(target));
    SendClientMessage(playerid, COLOR_WHITE, frmt_unfreeze_mess);
	return true;

}
@__godmode_test(playerid);
@__godmode_test(playerid)
{
	if(temp_godmode_target[playerid] != INVALID_PLAYER_ID)
	{
		new
		    Float:health,
			frmt_godmode_result[130],
			target = temp_godmode_target[playerid];

		GetPlayerHealth(target, health);

		if(temp_godmode_health[playerid]-health > 0)
		{
	  		format(frmt_godmode_result, sizeof frmt_godmode_result, "Игрок %s[%d] God Mode не обнаружен [Было HP: %.0f.00, стало HP: %.0f.00]", PN(target), target, temp_godmode_health[playerid], health);
			SendClientMessage(playerid, COLOR_ORANGE, frmt_godmode_result);

		    J_SetPlayerHealth(target, temp_godmode_health[playerid]);
		    temp_godmode_target[playerid] = INVALID_PLAYER_ID;
		    temp_godmode_health[playerid] = 0.0;
		    temp_godmode_armour[playerid] = 0.0;
		}
		else if(temp_godmode_health[playerid]-health == 0)
		{
	  		format(frmt_godmode_result, sizeof frmt_godmode_result, "Игрок %s[%d] подозрение на God Mode [Было HP: %.0f.00, стало HP: %.0f.00]", PN(target), target, temp_godmode_health[playerid], health);
			SendClientMessage(playerid, COLOR_ORANGE, frmt_godmode_result);

		    J_SetPlayerHealth(target, temp_godmode_health[playerid]);
		    temp_godmode_target[playerid] = INVALID_PLAYER_ID;
		    temp_godmode_health[playerid] = 0.0;
		    temp_godmode_armour[playerid] = 0.0;
		}
		if(temp_godmode_armour[playerid])
		    SetPlayerArmour(target, temp_godmode_armour[playerid]);
	}
}
