#if defined _al_included
	#endinput
#endif
#define _al_included

new
    gNomination[16],
    gNominationArea[16],
	gNickNomination[16][10][MAX_PLAYER_NAME],
	gNominationStar,
	gPointsNomination[16][10],
	gNominationBusiness[97],
	gNomBusinessTotal[97];
    
new gNominationName[16][50] = {"Долгожитель", "Благотворитель", "Лучший сотрудник МВД", "Лучший сотрудник МО", "Лучший сотрудник Midway Media", "Лучший Мафиози", "Грузчик", "Бизнесмен", "Самый Богатый", "Меценат штата", "Лучший сотрудник Правительство", "Лучший сотрудник FBI", "Лучший сотрудник МЗ", "Лучший Бандит", "Строитель дорог", "Работник завода"};
    
public OnGameModeInit()
{
	gNomination[0] = CreateDynamicObject(19482, 836.603, -1998.731, 14.587, 0.000, 0.000, 360.000, -1, -1, -1, 300.000, 300.000);
	SetDynamicObjectMaterial(gNomination[0], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[1] = CreateDynamicObject(19482, 836.603, -1986.820, 14.587, 0.000, 0.000, 360.000, -1, -1, -1, 300.000, 300.000);
	SetDynamicObjectMaterial(gNomination[1], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[2] = CreateDynamicObject(19482, 836.603, -1974.790, 14.587, 0.000, 0.000, 360.000, -1, -1, -1, 300.000, 300.000);
	SetDynamicObjectMaterial(gNomination[2], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[3] = CreateDynamicObject(19482,836.603,-1962.710,14.587,0.000,0.000,360.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[3], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[4] = CreateDynamicObject(19482,836.603,-1950.769,14.587,0.000,0.000,360.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[4], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[5] = CreateDynamicObject(19482,836.603,-1938.718,14.587,0.000,0.000,360.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[5], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[6] = CreateDynamicObject(19482,836.603,-1926.688,14.587,0.000,0.000,360.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[6], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[7] = CreateDynamicObject(19482,836.603,-1914.748,14.587,0.000,0.000,360.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[7], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[8] = CreateDynamicObject(19482,836.307,-1998.731,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[8], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[9] = CreateDynamicObject(19482,836.307,-1986.690,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[9], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[10] = CreateDynamicObject(19482,836.307,-1974.681,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[10], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[11] = CreateDynamicObject(19482,836.307,-1962.641,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[11], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[12] = CreateDynamicObject(19482,836.307,-1950.661,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[12], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[13] = CreateDynamicObject(19482,836.307,-1938.740,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[13], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[14] = CreateDynamicObject(19482,836.307,-1926.740,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[14], 0, -1, "none", "none", 0xFFFFFFFF);
	gNomination[15] = CreateDynamicObject(19482,836.307,-1914.650,14.587,0.000,0.000,180.000,-1,-1,-1,300.000,300.000);
	SetDynamicObjectMaterial(gNomination[15], 0, -1, "none", "none", 0xFFFFFFFF);
    
    gNominationArea[0] = CreateDynamicSphere(837.6263, -1998.7970, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1998.7970, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[1] = CreateDynamicSphere(837.6263, -1986.6276, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1986.6276, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[2] = CreateDynamicSphere(837.6263, -1974.6248, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1974.6248, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[3] = CreateDynamicSphere(837.6263, -1962.5530, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1962.5530, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[4] = CreateDynamicSphere(837.6263, -1950.4817, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1950.4817, 13.3849, -1, -1, -1, 5.0);
    gNominationArea[5] = CreateDynamicSphere(837.6263, -1938.5277, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1938.5277, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[6] = CreateDynamicSphere(837.6263, -1926.5853, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1926.5853, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[7] = CreateDynamicSphere(837.6263, -1914.5425, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 837.6263, -1914.5425, 13.3849, -1, -1, -1, 5.0);
	
	gNominationArea[8] = CreateDynamicSphere(835.1622, -1998.7970, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1998.7970, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[9] = CreateDynamicSphere(835.1622, -1986.6276, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1986.6276, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[10] = CreateDynamicSphere(835.1622, -1974.6248, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1974.6248, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[11] = CreateDynamicSphere(835.1622, -1962.5530, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1962.5530, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[12] = CreateDynamicSphere(835.1622, -1950.4817, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1950.4817, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[13] = CreateDynamicSphere(835.1622, -1938.5277, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1938.5277, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[14] = CreateDynamicSphere(835.1622, -1926.5853, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1926.5853, 13.3849, -1, -1, -1, 5.0);
	gNominationArea[15] = CreateDynamicSphere(835.1622, -1914.5425, 13.3849, 1.0);
	CreateDynamicPickup(19135, 23, 835.1622, -1914.5425, 13.3849, -1, -1, -1, 5.0);
	
	gNominationStar = CreateDynamicSphere(836.4982, -2032.7076, 13.7849, 1.0);
	CreateDynamicPickup(1247, 23, 836.4982, -2032.7076, 13.7849, -1, -1, -1, 5.0);

    #if defined al_OnGameModeInit
         return al_OnGameModeInit();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit al_OnGameModeInit
#if defined al_OnGameModeInit
	forward al_OnGameModeInit();
#endif


public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(areaid == gNominationArea[0])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[0][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Долгожитель{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;
				
		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;
					
				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");
		    
			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second);
		}
	    if(PI[playerid][pCard])
			format(frmt_nom_message, sizeof frmt_nom_message, "%sВаш результат: %d", frmt_nom_message, PI[playerid][pLevel]);
			
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[1])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[1][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Благотворитель{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d${FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[1]);
		}
        if(PI[playerid][pCard])
	    	format(frmt_nom_message, sizeof frmt_nom_message, "%sВаш результат: %d$", frmt_nom_message, PI[playerid][pCharity]);
	    	
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[2])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[2][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник МВД{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[2]);
		}
		
        if(PI[playerid][pCard])
        {
		    if(PI[playerid][pFraction] == 8)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

		
	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[3])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[3][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник МО{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[3]);
		}

        if(PI[playerid][pCard])
        {
		    if(PI[playerid][pFraction] == 7)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}

		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[4])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[4][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник Midway Media{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[4]);
		}

        if(PI[playerid][pCard])
        {
		    if(PI[playerid][pFraction] == 9)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[5])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[5][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший Мафиози{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[5]);
		}

        if(PI[playerid][pCard])
        {
		    if(PI[playerid][pFraction] >= 12 && PI[playerid][pFraction] <= 16)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[6])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[6][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Грузчик{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[6]);
		}

		if(PI[playerid][pCard])
			format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsLoader]);
			
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[7])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[7][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Бизнесмен{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d${FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[7]);
		}
	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[8])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[8][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Самый Богатый{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d${FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[8]);
		}
	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[9])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[9][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Меценат штата{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d рублей{FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[9]);
		}
		if(PI[playerid][pCard])
			format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d рублей", frmt_nom_message, PI[playerid][pTotalDon]);
			
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[10])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[10][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник Правительство{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[10]);
		}
		if(PI[playerid][pCard])
		{
		    if(PI[playerid][pFraction] == 10)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[11])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[11][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник FBI{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[11]);
		}
		if(PI[playerid][pCard])
		{
		    if(PI[playerid][pFraction] == 11)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[12])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[12][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший сотрудник МЗ{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[12]);
		}
		if(PI[playerid][pCard])
		{
		    if(PI[playerid][pFraction] == 1)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[13])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[13][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Лучший Бандит{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[13]);
		}
		
		if(PI[playerid][pCard])
		{
		    if(PI[playerid][pFraction] >= 2 && PI[playerid][pFraction] <= 6)
				format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsOrg]);
		}
		
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");

	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[14])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[14][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Строитель дорог{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[14]);
		}
		
	    if(PI[playerid][pCard])
			format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsRoad]);
			
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");
		    
	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationArea[15])
	{
		new
			nickname[MAX_PLAYER_NAME],
			frmt_nom_message[950],
			query_nom_get[170];

		format(query_nom_get, sizeof query_nom_get, "SELECT `NickName`, `Level`, `Age`, `Fraction`, `Subfraction`, `Rank`, `TelNum` FROM `accounts` WHERE `NickName` = '%s'", gNickNomination[15][0]);
		new Cache:result = mysql_query(mysql, query_nom_get);

		strcat(frmt_nom_message, "\n\n{FFDA00}Работник завода{FFFFFF}\n\n\n");

		if(cache_get_row_count(mysql) > 0)
		{
			new
			    level,
				age,
				fraction,
				subfraction,
				rank,
				rankname[25],
				fractionname[40],
				phone,
				year,
				month,
				day,
				hour,
				minute,
				second;

		    cache_get_row(0, 0, nickname, mysql, 24);
		    level = cache_get_row_int(0, 1);
		    age = cache_get_row_int(0, 2);
		    fraction = cache_get_row_int(0, 3);
		    subfraction = cache_get_row_int(0, 4);
		    rank = cache_get_row_int(0, 5);
		    phone = cache_get_row_int(0, 6);
			getdate(year, month, day);
			gettime(hour, minute, second);

		 	if(fraction)
			{
				new
					fractionid = fraction-1;

				strcat(fractionname, gFractionName[fractionid]);

				if(fractionid+1 == 10 && !subfraction && rank <= 9)
					strcat(rankname, gPrezRankName[rank-1]);

				else strcat(rankname, gFractionRankName[fractionid][rank-1]);
			}
		    else strcat(fractionname, "-"), strcat(rankname, "-");

			format(frmt_nom_message, sizeof frmt_nom_message, "%sИмя: {FFFF00}%s\n{FFFFFF}Лет в штате: {FFFF00}%d\n{FFFFFF}Возраст: {FFFF00}%d\n{FFFFFF}Номер телефона: {FFFF00}%d\n{FFFFFF}Организация: {FFFF00}%s\n{FFFFFF}Ранг: {FFFF00}%s\n{FFFFFF}Дата: {FFFF00}%02d.%02d.%02d %02d:%02d:%02d{FFFFFF}\n\n{FFFFFF}Результат: {FFFF00}%d балл(ов){FFFFFF}\n\n", frmt_nom_message, nickname, level, age, phone, fractionname, rankname, day,month,year, hour,minute,second, gPointsNomination[15]);
		}
		
	    if(PI[playerid][pCard])
			format(frmt_nom_message, sizeof frmt_nom_message, "%s\nВаш результат: %d балл(ов)", frmt_nom_message, PI[playerid][pPointsFactory]);
			
		else
		    strcat(frmt_nom_message, "{FF6347}Для того, чтобы ваш результат учитывался\nкупите Билет Рекордсмена в Мэрии");
		    
	    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Аллея славы", frmt_nom_message, !"Закрыть", !"");
	    cache_delete(result, mysql);
	}
	else if(areaid == gNominationStar)
	{
	    ShowPlayerDialogEx(playerid, 1881, DIALOG_STYLE_LIST, !"Аллея славы", !"{FF7319}1.{FFFFFF} Главные рекордсмены\n{FF7319}2.{FFFFFF} Долгожитель\n{FF7319}3.{FFFFFF} Благотворитель\n{FF7319}4.{FFFFFF} Лучший сотрудник МВД\n{FF7319}5.{FFFFFF} Лучший сотрудник МО\n{FF7319}6.{FFFFFF} Лучший сотрудник Midway Media\n{FF7319}7.{FFFFFF} Лучший Мафиози\n{FF7319}8.{FFFFFF} Грузчик\n{FF7319}9.{FFFFFF} Бизнесмен\n{FF7319}10.{FFFFFF} Самый Богатый\n{FF7319}11.{FFFFFF} Меценат штата\n{FF7319}12.{FFFFFF} Лучший сотрудник Правительство\n{FF7319}13.{FFFFFF} Лучший сотрудник FBI\n{FF7319}14.{FFFFFF} Лучший сотрудник МЗ\n{FF7319}15.{FFFFFF} Лучший Бандит\n{FF7319}16.{FFFFFF} Строитель дорог\n{FF7319}17.{FFFFFF} Работник завода", !"Выбор", !"Закрыть");
	}
    #if defined al_OnPlayerEnterDynamicArea
         return al_OnPlayerEnterDynamicArea(playerid, areaid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterDynamicArea
	#undef OnPlayerEnterDynamicArea
#else
	#define _ALS_OnPlayerEnterDynamicArea
#endif
#define OnPlayerEnterDynamicArea al_OnPlayerEnterDynamicArea
#if defined al_OnPlayerEnterDynamicArea
	forward al_OnPlayerEnterDynamicArea(playerid, areaid);
#endif

stock SetNominationName()
{
	print("Началась загрузка Аллеи Славы");
	mysql_query(mysql, "UPDATE `accounts` SET `Alley` = 0");
	mysql_tquery(mysql, "UPDATE `accounts` SET `PointsBusiness` = '0', `PointsMoney` = '0'");
	
	new
		nickname[MAX_PLAYER_NAME];

	new Cache:rLvl = mysql_query(mysql, "SELECT `NickName`,`Level` FROM `accounts` WHERE `Level` >= 15 AND `Card` = 1 ORDER BY `Level` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[0][i], "The State");
		SetDynamicObjectMaterialText(gNomination[0], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;
	        
		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;
		        
			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new level = cache_get_row_int(i, 1);
			SetString(gNickNomination[0][i], nickname);
			gPointsNomination[0][i] = level;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[0][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[0], 0, gNickNomination[0][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rLvl, mysql);

	new Cache:rCharity = mysql_query(mysql, "SELECT `NickName`,`Charity` FROM `accounts` WHERE `Charity` >= 1 AND `Card` = 1 ORDER BY `Charity` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[1][i], "The State");
		SetDynamicObjectMaterialText(gNomination[1], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;
		        
			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new charity = cache_get_row_int(i, 1);
			SetString(gNickNomination[1][i], nickname);
			gPointsNomination[1][i] = charity;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[1][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[1], 0, gNickNomination[1][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}


	cache_delete(rCharity, mysql);
	
	new Cache:rBestPD = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 8 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[2][i], "The State");
		SetDynamicObjectMaterialText(gNomination[2], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[2][i], nickname);
			gPointsNomination[2][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[2][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[2], 0, gNickNomination[2][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestPD, mysql);

	new Cache:rBestArmy = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 7 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[3][i], "The State");
		SetDynamicObjectMaterialText(gNomination[3], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[3][i], nickname);
			gPointsNomination[3][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[3][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[3], 0, gNickNomination[3][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestArmy, mysql);

	new Cache:rBestMedia = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 9 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[4][i], "The State");
		SetDynamicObjectMaterialText(gNomination[4], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[4][i], nickname);
			gPointsNomination[4][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[4][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[4], 0, gNickNomination[4][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestMedia, mysql);

	new Cache:rBestMafia = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` >= 12 AND `Fraction` <= 14 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[5][i], "The State");
		SetDynamicObjectMaterialText(gNomination[5], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[5][i], nickname);
			gPointsNomination[5][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gPointsNomination[5][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[5], 0, gNickNomination[5][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestMafia, mysql);

	new Cache:rBestLoader = mysql_query(mysql, "SELECT `NickName`,`PointsLoader` FROM `accounts` WHERE `PointsLoader` >= 1 AND `Card` = 1 ORDER BY `PointsLoader` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[6][i], "The State");
		SetDynamicObjectMaterialText(gNomination[6], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;
   			    
			cache_get_row(i, 0, nickname, mysql, 24);
			new pointsloader = cache_get_row_int(i, 1);
			SetString(gNickNomination[6][i], nickname);
			gPointsNomination[6][i] = pointsloader;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gPointsNomination[6][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[6], 0, gNickNomination[6][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestLoader, mysql);
	
	new Cache:rBusiness = mysql_query(mysql, "SELECT `bID`, `day_1`+`day_2`+`day_3`+`day_4`+`day_5`+`day_6`+`day_7`+`day_8`+`day_9`+`day_10` FROM `bizstats` ORDER BY `day_1`+`day_2`+`day_3`+`day_4`+`day_5`+`day_6`+`day_7`+`day_8`+`day_9`+`day_10` DESC");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[7][i], "The State");
		SetDynamicObjectMaterialText(gNomination[7], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    for(new b; b < cache_get_row_count(mysql); b++)
	    {
	        new
				bid = cache_get_row_int(b, 0),
				total = cache_get_row_int(b, 1);

			gNominationBusiness[b] = bid;
			gNomBusinessTotal[b] = total;
	    }
	}
	cache_delete(rBusiness, mysql);

    for(new b; b < 86; b++)
    {
		if(gNominationBusiness[b] == 0)
			continue;
            
	    new
			query_get_nickname[95],
			query_nom[170];

		format(query_get_nickname, sizeof query_get_nickname, "SELECT `NickName` FROM `accounts` WHERE `BizKey` = '%d' AND `Card` = 1 LIMIT 1", gNominationBusiness[b]);
		new Cache:rGetOwner = mysql_query(mysql, query_get_nickname);

		if(cache_get_row_count(mysql))
		{
			cache_get_row(0, 0, nickname, mysql, 24);
			cache_delete(rGetOwner, mysql);
			format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `PointsBusiness` = '%d' WHERE `NickName` = '%s'", gNomBusinessTotal[b], nickname);
			mysql_tquery(mysql, query_nom);
			
			
		}
		else
			cache_delete(rGetOwner, mysql);
	}
	
			
	new Cache:rBestBiz = mysql_query(mysql, "SELECT `NickName`,`PointsBusiness` FROM `accounts` WHERE `PointsBusiness` >= 1 AND `Card` = 1 ORDER BY `PointsBusiness` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[7][i], "The State");
		SetDynamicObjectMaterialText(gNomination[7], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointbiz = cache_get_row_int(i, 1);
			SetString(gNickNomination[7][i], nickname);
			gPointsNomination[7][i] = pointbiz;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[7][0]);
		mysql_tquery(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[7], 0, gNickNomination[7][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestBiz, mysql);


    new Cache:rGetMoney = mysql_query(mysql, "SELECT `NickName`, `Money`+`Bank` FROM `accounts` WHERE `Money`+`Bank` >= 1 AND `Card` = 1 ORDER BY `Money`+`Bank` DESC");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[8][i], "The State");
		SetDynamicObjectMaterialText(gNomination[8], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
			checked,
			query_nom[290];

	    for(new i; i < cache_get_row_count(mysql); i++)
	    {

	        if(checked >= 10)
				break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new money = cache_get_row_int(i, 1);
			
			

            
			format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `PointsMoney` = '%d' WHERE `NickName` = '%s' AND `Card` = 1", money, nickname);
			print(query_nom);
			mysql_tquery(mysql, query_nom);
			checked++;
	    }
	}
	
	cache_delete(rGetMoney, mysql);

	new Cache:rGetBank = mysql_query(mysql, "SELECT `ownerid`,`money` FROM `bank`");

	if(cache_get_row_count(mysql) > 0)
	{
	    new
	        query_nom[190];
	        
	    for(new b; b < cache_get_row_count(mysql); b++)
	    {
	        new id = cache_get_row_int(b, 0);
	        new money = cache_get_row_int(b, 1);
			format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `PointsMoney` = `PointsMoney`+'%d' WHERE `ID` = '%d' AND `Card` = 1", money, id);
			print(query_nom);
			mysql_tquery(mysql, query_nom);
	    }
	}
    cache_delete(rGetBank, mysql);
            
	new Cache:rBestMoney = mysql_query(mysql, "SELECT `NickName`,`PointsMoney` FROM `accounts` WHERE `PointsMoney` >= 1 AND `Card` = 1 ORDER BY `PointsMoney` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[8][i], "The State");
		SetDynamicObjectMaterialText(gNomination[8], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked,
			rows,
			field;
	        
		cache_get_data(rows, field);

		for(new i; i < rows; i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsmoney = cache_get_row_int(i, 1);
			SetString(gNickNomination[8][i], nickname);
			gPointsNomination[8][i] = pointsmoney;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[8][0]);
		mysql_tquery(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[8], 0, gNickNomination[8][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestMoney, mysql);


	new Cache:rBestDonate = mysql_query(mysql, "SELECT `NickName`,`TotalDon` FROM `accounts` WHERE `TotalDon` >= 1 AND `Card` = 1 ORDER BY `TotalDon` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[9][i], "The State");
		SetDynamicObjectMaterialText(gNomination[9], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;
   			    
			new totaldon = cache_get_row_int(i, 1);
			SetString(gNickNomination[9][i], nickname);
			gPointsNomination[9][i] = totaldon;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[9][0]);
		mysql_tquery(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[9], 0, gNickNomination[9][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestDonate, mysql);

	
	new Cache:rBestMeria = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 10 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[10][i], "The State");
		SetDynamicObjectMaterialText(gNomination[10], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[10][i], nickname);
			gPointsNomination[10][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[10][0]);
		mysql_tquery(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[10], 0, gNickNomination[10][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestMeria, mysql);

	new Cache:rBestFBI = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 11 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[11][i], "The State");
		SetDynamicObjectMaterialText(gNomination[11], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[11][i], nickname);
			gPointsNomination[11][i] = pointsorg;
			checked++;
		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[11][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[11], 0, gNickNomination[11][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestFBI, mysql);

	new Cache:rBestHeal = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` = 1 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[12][i], "The State");
		SetDynamicObjectMaterialText(gNomination[12], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[12][i], nickname);
			gPointsNomination[12][i] = pointsorg;
			checked++;
		}
		
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[12][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[12], 0, gNickNomination[12][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestHeal, mysql);
	
	new Cache:rBestGang = mysql_query(mysql, "SELECT `NickName`,`PointsOrg` FROM `accounts` WHERE `PointsOrg` >= 1 AND `Card` = 1 AND `Fraction` >= 2 AND `Fraction` <= 6 ORDER BY `PointsOrg` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[13][i], "The State");
		SetDynamicObjectMaterialText(gNomination[13], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsorg = cache_get_row_int(i, 1);
			SetString(gNickNomination[13][i], nickname);
			gPointsNomination[13][i] = pointsorg;
			checked++;
		}
		
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[13][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[13], 0, gNickNomination[13][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestGang, mysql);
	
	new Cache:rBestRoad = mysql_query(mysql, "SELECT `NickName`,`PointsRoad` FROM `accounts` WHERE `PointsRoad` >= 1 AND `Card` = 1 ORDER BY `PointsRoad` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[14][i], "The State");
		SetDynamicObjectMaterialText(gNomination[14], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);

   			if(GetString(nickname, "NULL"))
   			    continue;

			new pointsroad = cache_get_row_int(i, 1);
			SetString(gNickNomination[14][i], nickname);
			gPointsNomination[14][i] = pointsroad;
			checked++;

		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[14][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[14], 0, gNickNomination[14][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestRoad, mysql);

	new Cache:rBestFactory = mysql_query(mysql, "SELECT `NickName`,`PointsFactory` FROM `accounts` WHERE `PointsFactory` >= 1 AND `Card` = 1 ORDER BY `PointsFactory` DESC LIMIT 10");

	if(0 == cache_get_row_count(mysql))
	{
	    for(new i; i < 10; i++) SetString(gNickNomination[15][i], "The State");
		SetDynamicObjectMaterialText(gNomination[15], 0, "-", 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}
	
	else
	{
	    new
	        checked;

		for(new i; i < cache_get_row_count(mysql); i++)
		{
		    if(checked >= 10)
		        break;

			cache_get_row(i, 0, nickname, mysql, 24);
			
   			if(GetString(nickname, "NULL"))
   			    continue;
   			    
			new pointsfactory = cache_get_row_int(i, 1);
			SetString(gNickNomination[15][i], nickname);
			gPointsNomination[15][i] = pointsfactory;
			checked++;

		}
		new query_nom[160];
		format(query_nom, sizeof query_nom, "UPDATE `accounts` SET `Alley` = 1, `AlleyDays` = `AlleyDays`+1 WHERE `NickName` = '%s' AND `Alley` = 0", gNickNomination[15][0]);
		mysql_query(mysql, query_nom);
		SetDynamicObjectMaterialText(gNomination[15], 0, gNickNomination[15][0], 130, "Ariel", 27, 1, 0xFFFFFF00, 0x00000000, 1);
	}

	cache_delete(rBestFactory, mysql);
	
	print("Закончилась загрузка Аллеи Славы");

}


forward GetNomMoney();
public GetNomMoney()
{

    return 1;
}

