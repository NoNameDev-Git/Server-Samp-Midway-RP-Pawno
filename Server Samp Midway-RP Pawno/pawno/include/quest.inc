#if defined _quest_included
	#endinput
#endif
#define _quest_included

new
	gQuestSaimon,
	gQuestLinkoln;

public OnGameModeInit()
{
	CreateActor(234, 1771.3352, -1884.2300, 13.5528, 181.2930);
	CreateDynamic3DTextLabel("Саймон", 0xFFFFFFAA, 1771.3352, -1884.2300, 13.5528+1.0, 5.0);
	CreateDynamic3DTextLabel("[ALT]", 0xFFFFFFAA, 1771.3352, -1884.2300, 13.5528+0.5, 5.0);

	gQuestSaimon = CreateDynamicSphere(1771.3812, -1884.9320, 13.5528, 5.0);

	CreateActor(206, 380.8920, -2021.7834, 7.8359, 181.6688);
	CreateDynamic3DTextLabel("Линкольн", 0xFFFFFFAA, 380.8920, -2021.7834, 7.8359+1.0, 5.0);
	CreateDynamic3DTextLabel("[ALT]", 0xFFFFFFAA, 380.8920, -2021.7834, 7.8359+0.5, 5.0);

	gQuestLinkoln = CreateDynamicSphere(380.9093, -2022.4840, 7.8359, 5.0);

    #if defined quest_OnGameModeInit
         return quest_OnGameModeInit();
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit quest_OnGameModeInit
#if defined quest_OnGameModeInit
	forward quest_OnGameModeInit();
#endif


public OnPlayerEnterDynamicArea(playerid, areaid)
{
    #if defined quest_OnPlayerEnterDynamicArea
         return quest_OnPlayerEnterDynamicArea(playerid, areaid);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerEnterDynamicArea
	#undef OnPlayerEnterDynamicArea
#else
	#define _ALS_OnPlayerEnterDynamicArea
#endif
#define OnPlayerEnterDynamicArea quest_OnPlayerEnterDynamicArea
#if defined quest_OnPlayerEnterDynamicArea
	forward quest_OnPlayerEnterDynamicArea(playerid, areaid);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
 	if(newkeys & KEY_WALK && !IsPlayerInAnyVehicle(playerid))
	{
		if(IsPlayerInDynamicArea(playerid, gQuestSaimon))
		{
		    if(PI[playerid][pQuest] == 1 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
				ShowPlayerDialogEx(playerid, 1050, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Эй, человек, постой.\nЯ смотрю, ты только приехал сюда. Ты уже думал о том, как будешь зарабатывать на жизнь?\nЕсли что, у меня как раз есть работенка для тебя.\nЗдесь недалеко строят дорогу, им не помешают работники, заодно и денежку накопишь\n\n{AFAFAF}Задача: Перенести 20 тележек со щебнем\nНаграда: 3750$ и 1 ехр", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 1 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 20)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Перенести 20 тележек со щебнем\nНаграда: 3750$ и 1 ехр\nВыполнено: %d/20", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", frmt_quest_info, !"Закрыть", !"");
			}
			else if(PI[playerid][pQuest] == 1 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 20)
			    ShowPlayerDialogEx(playerid, 1051, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Хм, отлично поработал! Держи свою награду!", !"Далее", !"");

			else if(PI[playerid][pQuest] == 2 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
				ShowPlayerDialogEx(playerid, 1151, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Знаешь, что я подумал. Самое время получить водительское удостоверение.\nВсё же удобнее передвигаться по штату на автомобиле.\nЕзжай в автошколу и пройди курсы вождения. Требования там строгие, поэтому внимательно изучи ПДД перед экзаменом.\nПосле того, как получишь права, возвращайся ко мне.\n\n{AFAFAF}Задача: Получить водительское удостоверение\nНаграда: 3500$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 2 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{AFAFAF}Задача: Получить водительское удостоверение\nНаграда: 3500$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 2 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3500$");
	            GiveMoney(playerid, 3500, "квест 2");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 525);
	            }

		        PI[playerid][pQuest] = 3;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        	ShowPlayerDialogEx(playerid, 1053, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Я вижу ты уже с правами, молодец.\nНедалеко отсюда, в порт прибыл корабль с грузом, мой двоюродный брат руководит разгрузкой и ему нужны люди.\nРабота несложная, за которую тебе щедро заплатят.\n\n{AFAFAF}Задача: Перенести 20 ящиков груза\nНаграда: 4200$ и 1 ехр", !"Принять", !"Отмена");
			}
			
			else if(PI[playerid][pQuest] == 3 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
	        	ShowPlayerDialogEx(playerid, 1053, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Я вижу ты уже с правами, молодец.\nНедалеко отсюда, в порт прибыл корабль с грузом, мой двоюродный брат руководит разгрузкой и ему нужны люди.\nРабота несложная, за которую тебе щедро заплатят.\n\n{AFAFAF}Задача: Перенести 20 ящиков груза\nНаграда: 4200$ и 1 ехр", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 3 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 20)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Перенести 20 ящиков груза\nНаграда: 4200$ и 1 ехр\nВыполнено: %d/20", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", frmt_quest_info, !"Закрыть", !"");
			}
			else if(PI[playerid][pQuest] == 3 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 20)
			    ShowPlayerDialogEx(playerid, 1054, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Мой двоюродный брат тебе особо благодарен! Он передал тебе премию", !"Далее", !"");

			else if(PI[playerid][pQuest] == 4 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
			    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{AFAFAF}Задача: Купить телефон в 24/7\nНаграда: 3500$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 4 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
		        ShowPlayerDialogEx(playerid, 1055, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Самое время прикупить себе новенький iPhone. Как раз в магазин неподалеку завезли новые модели с крутыми расцветками.\n\n{AFAFAF}Задача: Купить телефон в 24/7\nНаграда: 3500$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 4 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3500$");
	            GiveMoney(playerid, 3500, "квест 4");

	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 525);
	            }

		        PI[playerid][pQuest] = 5;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
			    ShowPlayerDialogEx(playerid, 1056, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Слушай, дружище. Если ты ещё не устал работать, у меня для тебя есть очередная подработка.\nЕсть свободная вакансия на заводе по производству автозапчастей.\nЯ думаю, там можно неплохо заработать.\n\n{AFAFAF}Задача: Собрать 20 автозапчастей\nНаграда: 5200$ и 1 ехр", !"Принять", !"Отмена");
			}
			else if(PI[playerid][pQuest] == 5 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 20)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Собрать 20 автозапчастей\nНаграда: 5200$ и 1 ехр\nВыполнено: %d/20", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", frmt_quest_info, !"Закрыть", !"");
			}
			else if(PI[playerid][pQuest] == 5 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] != 20)
			    ShowPlayerDialogEx(playerid, 1056, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Слушай, дружище. Если ты ещё не устал работать, у меня для тебя есть очередная подработка.\nЕсть свободная вакансия на заводе по производству автозапчастей.\nЯ думаю, там можно неплохо заработать.\n\n{AFAFAF}Задача: Собрать 20 автозапчастей\nНаграда: 5200$ и 1 ехр", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 5 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 20)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}5200$ и 1 exp");
	            GiveMoney(playerid, 5200, "квест 5");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 780);
	            }

				PI[playerid][pExp]++;
				UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
				CheckNextLevel(playerid);
		        PI[playerid][pQuest] = 6;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1057, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Ты уже заработал неплохие деньги. Самое время прилично приодеться.\nНедалеко отсюда есть магазин одежды, прикупи что-то стоящее.\n\n{AFAFAF}Задача: Купить новый скин в магазине одежды\nНаграда: 5000$", !"Принять", !"Отмена");
			}
			else if(PI[playerid][pQuest] == 6 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
			    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{AFAFAF}Задача: Купить новый скин в магазине одежды\nНаграда: 5000$", !"Закрыть", !"");

            else if(PI[playerid][pQuest] == 6 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] != 1)
		        ShowPlayerDialogEx(playerid, 1057, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Ты уже заработал неплохие деньги. Самое время прилично приодеться.\nНедалеко отсюда есть магазин одежды, прикупи что-то стоящее.\n\n{AFAFAF}Задача: Купить новый скин в магазине одежды\nНаграда: 5000$", !"Принять", !"Отмена");

	        else if(PI[playerid][pQuest] == 6 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}5000$");
	            GiveMoney(playerid, 5000, "квест 6");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 750);
	            }
		        PI[playerid][pQuest] = 7;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	            ShowPlayerDialogEx(playerid, 1058, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}К такому стильному костюму неплохо бы подобрать стильный аксессуар.\nСходи в магазин аксессуаров и прикупи себе что-нибудь стильное.\n\n{AFAFAF}Задача: Приобрести аксессуар в магазине аксессуаров\nНаграда: 4700$", !"Принять", !"Отмена");
			}
			else if(PI[playerid][pQuest] == 7 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
			    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{AFAFAF}Задача: Приобрести аксессуар в магазине аксессуаров\nНаграда: 4700$", !"Закрыть", !"");

            else if(PI[playerid][pQuest] == 7 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] != 1)
	            ShowPlayerDialogEx(playerid, 1058, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}К такому стильному костюму неплохо бы подобрать стильный аксессуар.\nСходи в магазин аксессуаров и прикупи себе что-нибудь стильное.\n\n{AFAFAF}Задача: Приобрести аксессуар в магазине аксессуаров\nНаграда: 4700$", !"Принять", !"Отмена");

	    	else if(PI[playerid][pQuest] == 7 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}4700$");
	            GiveMoney(playerid, 4700, "квест 7");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 705);
	            }
		        PI[playerid][pQuest] = 8;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, 1059, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Дружище, я сразу понял, что тебе можно доверять. Было приятно иметь с тобой дело, вот тебе небольшой бонус от меня.\nМне на долгое время нужно уехать из города.\nЕсли тебя заинтересует, у моего друга Линкольна есть для тебя ещё пару предложений. Ты сможешь найти его у колеса обозрения.\n\n{AFAFAF}Задача: Поговорить с Линкольном\nНаграда: 8000$ и 2 ехр", !"Принять", !"Отмена");
			}
	    	else if(PI[playerid][pQuest] == 8 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] == 0)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{AFAFAF}Задача: Поговорить с Линкольном\nНаграда: 8000$ и 2 ехр", !"Закрыть", !"");

	    	else if(PI[playerid][pQuest] == 8 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
				ShowPlayerDialogEx(playerid, 1059, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Дружище, я сразу понял, что тебе можно доверять. Было приятно иметь с тобой дело, вот тебе небольшой бонус от меня.\nМне на долгое время нужно уехать из города.\nЕсли тебя заинтересует, у моего друга Линкольна есть для тебя ещё пару предложений. Ты сможешь найти его у колеса обозрения.\n\n{AFAFAF}Задача: Поговорить с Линкольном\nНаграда: 8000$ и 2 ехр", !"Принять", !"Отмена");

			else
			    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}У меня пока ничего для тебя нет", !"Закрыть", !"");
		}
		else if(IsPlayerInDynamicArea(playerid, gQuestLinkoln))
		{
	    	if(PI[playerid][pQuest] == 8 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] == 0)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}8000$ и 2 exp");
	            GiveMoney(playerid, 8000, "квест 8");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1200);
	            }

				PI[playerid][pExp] += 2;
				UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
				CheckNextLevel(playerid);
		        PI[playerid][pQuest] = 9;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
			    ShowPlayerDialogEx(playerid, 1060, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Приветствую, я Линкольн.\nСаймон говорил, что ты должен прийти. У меня есть для тебя работа.\nЯ надеюсь, у тебя есть водительские права? Мне срочно нужен опытный водитель автобуса.\nДумаю, ты справишься.\n\n{AFAFAF}Задача: Проехать 250 чекпоинтов\nНаграда: 7800$ и 2 ехр", !"Принять", !"Отмена");
			}
	    	else if(PI[playerid][pQuest] == 9 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
			    ShowPlayerDialogEx(playerid, 1060, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Приветствую, я Линкольн.\nСаймон говорил, что ты должен прийти. У меня есть для тебя работа.\nЯ надеюсь, у тебя есть водительские права? Мне срочно нужен опытный водитель автобуса.\nДумаю, ты справишься.\n\n{AFAFAF}Задача: Проехать 250 чекпоинтов\nНаграда: 7800$ и 2 ехр", !"Принять", !"Отмена");

	    	else if(PI[playerid][pQuest] == 9 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 250)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Проехать 250 чекпоинтов\nНаграда: 7800$ и 2 ехр\nВыполнено: %d/250", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", frmt_quest_info, !"Закрыть", !"");
			}
			else if(PI[playerid][pQuest] == 9 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 250)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}7800$ и 2 exp");
	            GiveMoney(playerid, 7800, "квест 9");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1170);
	            }
				PI[playerid][pExp] += 2;
				UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
				CheckNextLevel(playerid);
		        PI[playerid][pQuest] = 10;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, 1061, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Слушай, ты уже долгое время в штате, но медицинской книжки у тебя до сих пор нету.\nЕсли дальше ты захочешь устроиться на работу, она обязательно пригодится.\nПолучи её в любой из больниц штата.\n\n{AFAFAF}Задача: Получить мед. карту в больнице\nНаграда: 6200$", !"Принять", !"Отмена");
			}

	    	else if(PI[playerid][pQuest] == 10 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
				ShowPlayerDialogEx(playerid, 1061, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Слушай, ты уже долгое время в штате, но медицинской книжки у тебя до сих пор нету.\nЕсли дальше ты захочешь устроиться на работу, она обязательно пригодится.\nПолучи её в любой из больниц штата.\n\n{AFAFAF}Задача: Получить мед. карту в больнице\nНаграда: 6200$", !"Принять", !"Отмена");

	    	else if(PI[playerid][pQuest] == 10 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{AFAFAF}Задача: Получить мед. карту в больнице\nНаграда: 6200$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 10 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}6200$");
	            GiveMoney(playerid, 6200, "квест 10");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 930);
	            }
		        PI[playerid][pQuest] = 11;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
                ShowPlayerDialogEx(playerid, 1062, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Иногда в штате бывает небезопасно, тебе точно понадобится оружие.\nДля того, чтобы его носить, нужно получить определенную лицензию у сотрудников мэрии.\nЯ думаю, это не займет много времени.\n\n{AFAFAF}Задача: Получить лицензию на оружие в мэрии\nНаграда: 6600$", !"Принять", !"Отмена");
			}

	    	else if(PI[playerid][pQuest] == 11 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
                ShowPlayerDialogEx(playerid, 1062, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Иногда в штате бывает небезопасно, тебе точно понадобится оружие.\nДля того, чтобы его носить, нужно получить определенную лицензию у сотрудников мэрии.\nЯ думаю, это не займет много времени.\n\n{AFAFAF}Задача: Получить лицензию на оружие в мэрии\nНаграда: 6600$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 11 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{AFAFAF}Задача: Получить лицензию на оружие в мэрии\nНаграда: 6600$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 11 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}6600$");
	            GiveMoney(playerid, 6600, "квест 11");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 990);
	            }
		        PI[playerid][pQuest] = 12;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1063, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Теперь у тебя есть лицензия, но этого мало.\nПомимо лицензии, нужно иметь хороший навык стрельбы.\nДавай немного потренируемся в стрельбе из \"Пустынного орла\" в тире.\n\n{AFAFAF}Задача: Выстрелить 200 патрон из \"Пустынного орла\" на территории тира\nНаграда: 7000$ и 15 патронов \"Пустынного орла\"", !"Принять", !"Отмена");
			}

	    	else if(PI[playerid][pQuest] == 12 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
		        ShowPlayerDialogEx(playerid, 1063, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Теперь у тебя есть лицензия, но этого мало.\nПомимо лицензии, нужно иметь хороший навык стрельбы.\nДавай немного потренируемся в стрельбе из \"Пустынного орла\" в тире.\n\n{AFAFAF}Задача: Выстрелить 200 патрон из \"Пустынного орла\" на территории тира\nНаграда: 7000$ и 15 патронов \"Пустынного орла\"", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 12 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 200)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Выстрелить 200 патрон из \"Пустынного орла\" на территории тира\nНаграда: 7000$ и 15 патронов \"Пустынного орла\"\nВыполнено: %d/200", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", frmt_quest_info, !"Закрыть", !"");
			}

			else if(PI[playerid][pQuest] == 12 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 200)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}7000$ и 15 патронов Desert Eagle");
	            GiveMoney(playerid, 7000, "квест 12");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1100);
	            }
	            _GiveGun(playerid, 24, 15);
		        PI[playerid][pQuest] = 13;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1064, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Вот и пришло время немного развлечься.\nВ штате частенько проходят турниры по пейнтболу, прими участие в одном из них.\nЭто отличный способ перевести дух и потренироваться.\nКроме хорошего настроения, есть шанс получить награду.\n\n{AFAFAF}Задача: Поучаствовать в турнире по пейнтболу\nНаграда: 7500$", !"Принять", !"Отмена");
			}

			else if(PI[playerid][pQuest] == 13 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
		        ShowPlayerDialogEx(playerid, 1064, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Вот и пришло время немного развлечься.\nВ штате частенько проходят турниры по пейнтболу, прими участие в одном из них.\nЭто отличный способ перевести дух и потренироваться.\nКроме хорошего настроения, есть шанс получить награду.\n\n{AFAFAF}Задача: Поучаствовать в турнире по пейнтболу\nНаграда: 7500$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 13 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{AFAFAF}Задача: Поучаствовать в турнире по пейнтболу\nНаграда: 7500$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 13 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}7500$");
	            GiveMoney(playerid, 7500, "квест 13");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1150);
	            }
		        PI[playerid][pQuest] = 15;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1066, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}После тяжелого дня стоит немного подкрепиться.\nСходи в ближайшую закусочную и перекуси.\n\n{AFAFAF}Задача: Приобрести любое блюдо в любой закусочной\nНаграда: 7000$", !"Принять", !"Отмена");

		        //ShowPlayerDialogEx(playerid, 1065, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Надеюсь, ты отдохнул.\nТеперь можно опять вернуться за работу.\nВ сфере дальнобойщиков водятся неплохие деньги, тебе стоит попробовать.\n\n{AFAFAF}Задача: Перевезти 15 грузов\nНаграда: 10000$ и 2 exp", !"Принять", !"Отмена");
			}

			else if(PI[playerid][pQuest] == 14 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
		        ShowPlayerDialogEx(playerid, 1065, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Надеюсь, ты отдохнул.\nТеперь можно опять вернуться за работу.\nВ сфере дальнобойщиков водятся неплохие деньги, тебе стоит попробовать.\n\n{AFAFAF}Задача: Перевезти 15 грузов\nНаграда: 10000$ и 2 exp", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 14 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 15)
			{
			    new
					frmt_quest_info[170];

				format(frmt_quest_info, sizeof frmt_quest_info, "{AFAFAF}Задача: Перевезти 15 грузов\nНаграда: 10000$ и 2 exp\nВыполнено: %d/15", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", frmt_quest_info, !"Закрыть", !"");
			}

			else if(PI[playerid][pQuest] == 14 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] >= 15)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}10000$");
	            GiveMoney(playerid, 10000, "квест 14");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1500);
	            }
				PI[playerid][pExp] += 2;
				UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
				CheckNextLevel(playerid);
		        PI[playerid][pQuest] = 15;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1066, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}После тяжелого дня стоит немного подкрепиться.\nСходи в ближайшую закусочную и перекуси.\n\n{AFAFAF}Задача: Приобрести любое блюдо в любой закусочной\nНаграда: 7000$", !"Принять", !"Отмена");
			}

			else if(PI[playerid][pQuest] == 15 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
		        ShowPlayerDialogEx(playerid, 1066, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}После тяжелого дня стоит немного подкрепиться.\nСходи в ближайшую закусочную и перекуси.\n\n{AFAFAF}Задача: Приобрести любое блюдо в любой закусочной\nНаграда: 7000$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 15 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
				ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{AFAFAF}{AFAFAF}Задача: Приобрести любое блюдо в любой закусочной\nНаграда: 7000$", !"Закрыть", !"");

			else if(PI[playerid][pQuest] == 15 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 1)
			{
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}7000$");
	            GiveMoney(playerid, 7000, "квест 15");
	            if(PI[playerid][pPromo])
	            {
	                new promoid = PI[playerid][pPromo]-1;
	                GivePromoMoney(playerid, promoid, 1050);
	            }
		        PI[playerid][pQuest] = 16;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	         	ShowPlayerDialogEx(playerid, 1067, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Саймон был прав,ты действительно надежный человек.\nНо, на этом наше сотрудничество подошло к концу, у меня больше нет заданий для тебя. Но как появится работенка,\nя обязательно свяжусь с тобой. На последок дам тебе совет, найди себе занятие по душе,\nустройся в организацию и поднимайся по карьерной лестнице.\n\nУдачи тебе.\n\n{AFAFAF}Задача: Устроиться в организацию\nНаграда: 25000$", !"Принять", !"Отмена");
			}

            else if(PI[playerid][pQuest] == 16 && PI[playerid][pQuestStatus] == 0 && PI[playerid][pQuestProcess] == 0)
	         	ShowPlayerDialogEx(playerid, 1067, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Саймон был прав,ты действительно надежный человек.\nНо, на этом наше сотрудничество подошло к концу, у меня больше нет заданий для тебя. Но как появится работенка,\nя обязательно свяжусь с тобой. На последок дам тебе совет, найди себе занятие по душе,\nустройся в организацию и поднимайся по карьерной лестнице.\n\nУдачи тебе.\n\n{AFAFAF}Задача: Устроиться в организацию\nНаграда: 25000$", !"Принять", !"Отмена");

			else if(PI[playerid][pQuest] == 16 && PI[playerid][pQuestStatus] != 0 && PI[playerid][pQuestProcess] != 1)
                ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{AFAFAF}{AFAFAF}Задача: Устроиться в организацию\nНаграда: 25000$", !"Закрыть", !"");

			else
			    ShowPlayerDialogEx(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}У меня пока ничего для тебя нет", !"Закрыть", !"");

		}
	}
    #if defined quest_OnPlayerKeyStateChange
         return quest_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    #else
   	 	return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange quest_OnPlayerKeyStateChange
#if defined quest_OnPlayerKeyStateChange
	forward quest_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

stock QuestDialog(playerid, dialogid, response)
{
	switch(dialogid)
	{
		case 1050:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 1)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Перенесите 20 тележек со щебнем и возвращайтесь обратно");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь на работу \"Строитель дорог\" {FFFF00}(/gps -> Работы -> Строитель дорог)");
		}
		case 1051:
		{
		    if(!response)
				return 1;

	    	if(PI[playerid][pQuest] != 1)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3750$ и 1 exp");
            GiveMoney(playerid, 3750, "квест 1");
            if(PI[playerid][pPromo])
            {
                new promoid = PI[playerid][pPromo]-1;
                GivePromoMoney(playerid, promoid, 563);
            }
			PI[playerid][pExp]++;
			UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
			CheckNextLevel(playerid);

			if(PI[playerid][pCarLic] != YES_LICENSE)
			{
		        PI[playerid][pQuest] = 2;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, 1052, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Знаешь, что я подумал. Самое время получить водительское удостоверение.\nВсё же удобнее передвигаться по штату на автомобиле.\nЕзжай в автошколу и пройди курсы вождения. Требования там строгие, поэтому внимательно изучи ПДД перед экзаменом.\nПосле того, как получишь права, возвращайся ко мне.\n\n{AFAFAF}Задача: Получить водительское удостоверение\nНаграда: 3500$", !"Принять", !"Отмена");
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Вы уже выполнили все условия следущего задания");
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3500$");
	            GiveMoney(playerid, 3500, "квест 2");
		        if(PI[playerid][pPromo])
		        {
		            new promoid = PI[playerid][pPromo]-1;
		            GivePromoMoney(playerid, promoid, 525);
		        }
		        PI[playerid][pQuest] = 3;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        	ShowPlayerDialogEx(playerid, 1053, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Я вижу ты уже с правами, молодец.\nНедалеко отсюда, в порт прибыл корабль с грузом, мой двоюродный брат руководит разгрузкой и ему нужны люди.\nРабота несложная, за которую тебе щедро заплатят.\n\n{AFAFAF}Задача: Перенести 20 ящиков груза\nНаграда: 4200$ и 1 ехр", !"Принять", !"Отмена");
			}
		}
		case 1151:
		{
		    if(!response)
				return 1;

	    	if(PI[playerid][pQuest] != 2)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

			if(PI[playerid][pCarLic] != YES_LICENSE)
			{
		        PI[playerid][pQuest] = 2;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
				ShowPlayerDialogEx(playerid, 1052, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Знаешь, что я подумал. Самое время получить водительское удостоверение.\nВсё же удобнее передвигаться по штату на автомобиле.\nЕзжай в автошколу и пройди курсы вождения. Требования там строгие, поэтому внимательно изучи ПДД перед экзаменом.\nПосле того, как получишь права, возвращайся ко мне.\n\n{AFAFAF}Задача: Получить водительское удостоверение\nНаграда: 3500$", !"Принять", !"Отмена");
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Вы уже выполнили все условия следущего задания");
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3500$");
	            GiveMoney(playerid, 3500, "квест 2");
		        if(PI[playerid][pPromo])
		        {
		            new promoid = PI[playerid][pPromo]-1;
		            GivePromoMoney(playerid, promoid, 525);
		        }
		        PI[playerid][pQuest] = 3;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        	ShowPlayerDialogEx(playerid, 1053, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Я вижу ты уже с правами, молодец.\nНедалеко отсюда, в порт прибыл корабль с грузом, мой двоюродный брат руководит разгрузкой и ему нужны люди.\nРабота несложная, за которую тебе щедро заплатят.\n\n{AFAFAF}Задача: Перенести 45 ящиков груза\nНаграда: 4200$ и 1 ехр", !"Принять", !"Отмена");
			}


		}
		case 1052:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 2)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Получите водительское удостоверение");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в автошколу {FFFF00}(/gps -> Важные места -> Автошкола)");
		}
		case 1053:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 3)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Перенесите 20 ящиков груза");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь на работу \"Грузчик\" {FFFF00}(/gps -> Работы -> Грузчик)");
		}
		case 1054:
		{
		    if(!response)
		        return 1;


	    	if(PI[playerid][pQuest] != 3)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}4200$ и 1 exp");
            GiveMoney(playerid, 4200, "квест 3");
	        if(PI[playerid][pPromo])
	        {
	            new promoid = PI[playerid][pPromo]-1;
	            GivePromoMoney(playerid, promoid, 630);
	        }
			PI[playerid][pExp]++;
			UpdatePlayerData(playerid, "Exp", PI[playerid][pExp]);
			CheckNextLevel(playerid);


			if(0 == PI[playerid][pPhone])
			{
		        PI[playerid][pQuest] = 4;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1055, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Самое время прикупить себе новенький iPhone. Как раз в магазин неподалеку завезли новые модели с крутыми расцветками.\n\n{AFAFAF}Задача: Купить телефон в 24/7\nНаграда: 3500$", !"Принять", !"Отмена");
			}
			else
			{
			    SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Вы уже выполнили все условия следущего задания");
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}3500$");
	            GiveMoney(playerid, 3500, "квест 4");
		        if(PI[playerid][pPromo])
		        {
		            new promoid = PI[playerid][pPromo]-1;
		            GivePromoMoney(playerid, promoid, 525);
		        }
		        PI[playerid][pQuest] = 5;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
			    ShowPlayerDialogEx(playerid, 1056, DIALOG_STYLE_MSGBOX, !"Саймон", !"{FFFFFF}Слушай, дружище. Если ты ещё не устал работать, у меня для тебя есть очередная подработка.\nЕсть свободная вакансия на заводе по производству автозапчастей.\nЯ думаю, там можно неплохо заработать.\n\n{AFAFAF}Задача: Собрать 20 автозапчастей\nНаграда: 5200$ и 1 ехр", !"Принять", !"Отмена");
			}
		}
		case 1055:
		{
		    if(!response)
				return 1;

	    	if(PI[playerid][pQuest] != 4)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Купите себе телефон в 24/7");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Для того чтобы найти ближайший 24/7, используйте {FFFF00}/gps");
		}
		case 1056:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 5)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Соберите 20 автозапчастей");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь на работу \"Сборщик автозапчастей\" {FFFF00}(/gps -> Работы -> Сборщик автозапчастей)");
		}
		case 1057:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 6)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Купите себе новый скин в магазине одежды");
		}
		case 1058:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 7)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Купите аксессуар в магазине аксессуаров");
		}
		case 1059:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 8)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestSaimon))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Отправляйтесь к Линкольну и поговорите с ним");
		}
		case 1060:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 9)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Проедьте 250 чекпоинтов на работе автобусником");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в ближайшую мэрию для трудоустройства");
		}
		case 1061:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 10)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

			if(0 == PI[playerid][pMedCard])
			{
		        PI[playerid][pQuestStatus] = 1;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Получите медицинскую карту у сотрудника больницы");
		        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в ближайшую больницу");
	        }
	        else
	        {
			    SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Вы уже выполнили все условия следущего задания");
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}6200$");
	            GiveMoney(playerid, 6200, "квест 10");
		        if(PI[playerid][pPromo])
		        {
		            new promoid = PI[playerid][pPromo]-1;
		            GivePromoMoney(playerid, promoid, 930);
		        }
		        PI[playerid][pQuest] = 11;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
                ShowPlayerDialogEx(playerid, 1062, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Иногда в штате бывает небезопасно, тебе точно понадобится оружие.\nДля того, чтобы его носить, нужно получить определенную лицензию у сотрудников мэрии.\nЯ думаю, это не займет много времени.\n\n{AFAFAF}Задача: Получить лицензию на оружие в мэрии\nНаграда: 6600$", !"Принять", !"Отмена");
	        }
		}
		case 1062:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 11)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

			if(PI[playerid][pGunLic] != YES_LICENSE)
			{
		        PI[playerid][pQuestStatus] = 1;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Получите лицензию на оружие у сотрудника мэрии");
		        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в ближайшую мэрию");
	        }
	        else
	        {
			    SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Вы уже выполнили все условия следущего задания");
	            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Вы получили {33AA33}6600$");
	            GiveMoney(playerid, 6600, "квест 11");
		        if(PI[playerid][pPromo])
		        {
		            new promoid = PI[playerid][pPromo]-1;
		            GivePromoMoney(playerid, promoid, 990);
		        }
		        PI[playerid][pQuest] = 12;
		        UpdatePlayerData(playerid, "Quest", PI[playerid][pQuest]);
		        PI[playerid][pQuestStatus] = 0;
		        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
		        PI[playerid][pQuestProcess] = 0;
		        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
		        ShowPlayerDialogEx(playerid, 1063, DIALOG_STYLE_MSGBOX, !"Линкольн", !"{FFFFFF}Теперь у тебя есть лицензия, но этого мало.\nПомимо лицензии, нужно иметь хороший навык стрельбы.\nДавай немного потренируемся в стрельбе из \"Пустынного орла\" в тире.\n\n{AFAFAF}Задача: Выстрелить 200 патрон из \"Пустынного орла\" на территории тира\nНаграда: 7000$ и 15 патронов \"Пустынного орла\"", !"Принять", !"Отмена");

	        }
		}
		case 1063:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 12)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Выстрелите 200 патрон из \"Пустынного орла\" на территории тира");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь на \"Полигон для стрельбы\" {FFFF00}(/gps -> Важные места -> Полигон для стрельбы)");
		}
		case 1064:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 13)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
            SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Поучаствуйте в турнире по пейнтболу");
            SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в \"Центр развлечений\" {FFFF00}(/gps -> Важные места -> Центр развлечений)");
		}
		case 1065:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 14)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Перевезите 15 грузов на работе дальнобойщика");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Отправляйтесь в ближайшую мэрию для трудоустройства");
		}
		case 1066:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 15)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Купить любое блюдо в любой закусочной");
	        SendClientMessage(playerid, COLOR_WHITE, !"{FFC800}[Подсказка] {FFFFFF}Для того чтобы найти ближайшую закусочную, используйте {FFFF00}/gps");
		}
		case 1067:
		{
		    if(!response)
		        return 1;

	    	if(PI[playerid][pQuest] != 16)
				return 1;

			if(0 == IsPlayerInDynamicArea(playerid, gQuestLinkoln))
			    return 1;

	        PI[playerid][pQuestStatus] = 1;
	        UpdatePlayerData(playerid, "QuestStatus", PI[playerid][pQuestStatus]);
	        PI[playerid][pQuestProcess] = 0;
	        UpdatePlayerData(playerid, "QuestProcess", PI[playerid][pQuestProcess]);
	        SendClientMessage(playerid, COLOR_WHITE, !"{DC143C}[QUEST] {FFFFFF}Устройтесь в организацию");
		}
	}
	return 1;
}
