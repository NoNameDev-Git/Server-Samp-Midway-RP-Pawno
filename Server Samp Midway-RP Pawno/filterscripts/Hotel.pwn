//////////////////////////////
////    Отель "Верона"    ////
//// -------------------- ////
//// Создатель: DIESEL-90 ////
//////////////////////////////

#include <a_samp>
new EnterSS;
new ExitSS;

public OnFilterScriptInit()
{

    //---- Объекты холла и коридора ----//
	//Объекты с заменеными текстурами
	//-- Холл отеля --
	//---- Стены
	new stenah1 = CreateObject(8419,1489.5380859,-1575.0000000,3400.0000000,270.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenah1, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenah2 = CreateObject(8419,1489.5380859,-1505.0000000,3400.0000000,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenah2, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);

	new stenah3 = CreateObject(5882,1461.4990234,-1540.1992188,3400.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenah3, 5, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenah3, 1, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenah4 = CreateObject(5882,1517.3291016,-1540.1992188,3400.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenah4, 5, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenah4, 1, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- Потолок
	new potolokh = CreateObject(8421,1489.5380859,-1541.7666016,3420.7939453,0.0000000,90.0000000,270.0000000);
    SetObjectMaterial(potolokh, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0xFFC0C0C0);
    SetObjectMaterial(potolokh, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0xFFC0C0C0);
    SetObjectMaterial(potolokh, 2, 2439, "cj_ff_counters", "CJ_WOOD6", 0xFFC0C0C0);
    SetObjectMaterial(potolokh, 3, 2439, "cj_ff_counters", "CJ_WOOD6", 0xFFC0C0C0);

	//---- Пол
	new polh = CreateObject(8555,1489.5380859,-1541.7666015,3374.3950195,0.0000000,0.0000000,90.0000000);
    SetObjectMaterial(polh, 7, 2439, "cj_ff_counters", "CJ_WOOD6", 0);

	//---- Ресепшн
	new reception1 = CreateObject(2439,1497.0909424,-1540.1992188,3397.7351074,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(reception1, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception1, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception2 = CreateObject(2439,1499.0999756,-1544.2259521,3397.7351074,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(reception2, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception2, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception3 = CreateObject(2439,1497.0909424,-1541.1999512,3397.7351074,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(reception3, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception3, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception4 = CreateObject(2439,1497.0908203,-1542.1992188,3397.7351074,0.0000000,0.0000000,269.9890137);
	SetObjectMaterial(reception4, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception4, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception5 = CreateObject(2439,1497.0908203,-1543.1992188,3397.7351074,0.0000000,0.0000000,269.9890137);
	SetObjectMaterial(reception5, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception5, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception6 = CreateObject(2439,1497.0908203,-1539.1992188,3397.7351074,0.0000000,0.0000000,269.9890137);
	SetObjectMaterial(reception6, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception6, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception7 = CreateObject(2439,1497.0908203,-1538.1992188,3397.7351074,0.0000000,0.0000000,269.9890137);
	SetObjectMaterial(reception7, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception7, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception8 = CreateObject(2439,1497.0909424,-1537.1999512,3397.7351074,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(reception8, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception8, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception9 = CreateObject(2439,1498.0989990,-1544.2259521,3397.7351074,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(reception9, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception9, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new reception10 = CreateObject(2439,1498.1180420,-1536.1920166,3397.7351074,0.0000000,0.0000000,180.0000000);
	SetObjectMaterial(reception10, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception10, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
    new reception11 = CreateObject(2440,1497.0920410,-1544.1949463,3397.7351074,0.0000000,0.0000000,270.0000000);
    SetObjectMaterial(reception11, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception11, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
    
	new reception12 = CreateObject(2440,1497.1230469,-1536.1929932,3397.7351074,0.0000000,0.0000000,180.0000000);
	SetObjectMaterial(reception12, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	SetObjectMaterial(reception12, 1, 2439, "cj_ff_counters", "CJ_WOOD6", 0);

	//---- ТВ
	new tvh1 = CreateObject(2267,1497.6650390,-1530.3449707,3399.5,0.0000000,0.0000000,270.0000000);
    SetObjectMaterial(tvh1, 0, 16000, "con_drivein", "drvin_screen", 0xFF000000);
    SetObjectMaterial(tvh1, 1, 9362, "sfn_byofficeint", "CJ_TV_SCREEN", 0);
    
    new tvh2 = CreateObject(2267,1481.1699218,-1530.3449707,3399.5,0.0000000,0.0000000,90.0000000);
    SetObjectMaterial(tvh2, 0, 16000, "con_drivein", "drvin_screen", 0xFF000000);
    SetObjectMaterial(tvh2, 1, 9362, "sfn_byofficeint", "CJ_TV_SCREEN", 0);

	//---- Дверь у ресепшна
	new doorrec = CreateObject(1569,1499.6298828,-1533.1992188,3397.7199707,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(doorrec, 0, 16150, "ufo_bar", "des_backdoor1", 0);
	
	//---- Картина
	new kar = CreateObject(2790, 1489.5380859, -1516.6999511, 3403.5, 0.00000, 0.00000, 0.00000);
    SetObjectMaterial(kar, 1, 2267, "picture_frame", "CJ_PAINTING30", 0);

	//---- Окна
	new oknoh1 = CreateObject(1569,1495.1992188,-1563.1494141,3400.5000000,90.0000000,0.0000000,270.0000000);
	SetObjectMaterial(oknoh1, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh2 = CreateObject(1569,1495.1992188,-1563.1494141,3398.1157227,90.0000000,0.0000000,269.9890137);
	SetObjectMaterial(oknoh2, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh3 = CreateObject(1569,1492.6337891,-1563.1484375,3398.0551758,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(oknoh3, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh4 = CreateObject(1569,1495.2529297,-1563.1484375,3398.0551758,0.0000000,0.0000000,269.9890137);
	SetObjectMaterial(oknoh4, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh5 = CreateObject(1569,1486.3800049,-1563.1494141,3398.1157227,90.0000000,0.0000000,269.9890137);
	SetObjectMaterial(oknoh5, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh6 = CreateObject(1569,1486.3800049,-1563.1494141,3400.5000000,90.0000000,0.0000000,269.9890137);
	SetObjectMaterial(oknoh6, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh7 = CreateObject(1569,1486.4344482,-1563.1484375,3398.0551758,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(oknoh7, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	new oknoh8 = CreateObject(1569,1483.8149414,-1563.1484375,3398.0551758,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(oknoh8, 0, 2439, "cj_ff_counters", "CJ_WOOD6", 0);
	
	//---- Название отеля
	new nazvanie = CreateObject(19175,1499.5996093,-1540.1992187,3400.5,0.0000000,0.0000000,270.0000000);
	SetObjectMaterialText(nazvanie, "Отель Верона", 0, OBJECT_MATERIAL_SIZE_512x512,\
    "Verdana", 80, 0, 0xFFFFFFFF, 0xFF000000, 1);
    

	//-- Коридор отеля --
	//---- Стены
	new stenak1 = CreateObject(8419,1489.5380859,-1504.9880371,3285.0000000,0.0000000,90.0000000,270.0000000);
	SetObjectMaterial(stenak1, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenak2 = CreateObject(8419,1538.4699707,-1532.8000488,3300.0000000,0.0000000,90.0000000,90.0000000);
	SetObjectMaterial(stenak2, 1, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak2, 2, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak2, 3, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak2, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenak3 = CreateObject(8419,1440.6298828,-1532.7998047,3300.0000000,0.0000000,90.0000000,90.0000000);
	SetObjectMaterial(stenak3, 1, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak3, 2, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak3, 3, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	SetObjectMaterial(stenak3, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenak4 = CreateObject(8419,1446.5498047,-1522.0000000,3300.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(stenak4, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenak5 = CreateObject(8419,1532.3291016,-1522.0000000,3300.0000000,0.0000000,90.0000000,180.0000000);
	SetObjectMaterial(stenak5, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);
	
	new stenak6 = CreateObject(8419,1489.5380859,-1550.0000000,3285.0000000,0.0000000,90.0000000,90.0000000);
    SetObjectMaterial(stenak6, 4, 4002, "cityhall_lan", "LAcityhwal1", 0xFFC0C0C0);

	//---- Потолок
	new potoloko = CreateObject(8555,1489.5380859,-1535.0000000,3332.5000000,0.0000000,179.9945068,0.0000000);
    SetObjectMaterial(potoloko, 7, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF363636);

	//---- Пол
	new polo = CreateObject(8555,1489.5380859,-1535.0000000,3281.6589355,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(polo, 7, 14858, "gen_pol_vegas", "grey_carpet_256", 0);
	
	//---- Косяки дверей
	new kosykk1 = CreateObject(1507,1481.4200439,-1520.9399414,3305.0000000,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(kosykk1, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk2 = CreateObject(1507,1480.0000000,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk2, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk3 = CreateObject(1507,1479.9667969,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk3, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk4 = CreateObject(1507,1481.4200439,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk4, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk5 = CreateObject(1507,1480.0000000,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk5, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk6 = CreateObject(1507,1479.9667969,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk6, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk7 = CreateObject(1507,1472.5999756,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk7, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk8 = CreateObject(1507,1474.0250244,-1515.3299561,3305.0000000,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(kosykk8, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk9 = CreateObject(1507,1472.5693359,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk9, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk10 = CreateObject(1507,1474.0250244,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk10, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk11 = CreateObject(1507,1472.5999756,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk12 = CreateObject(1507,1472.5693359,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk13 = CreateObject(1507,1466.6250000,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk13, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk14 = CreateObject(1507,1465.1999512,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk14, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk15 = CreateObject(1507,1465.1660156,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk15, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk16 = CreateObject(1507,1465.1999512,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk16, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk17 = CreateObject(1507,1466.6250000,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk17, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk18 = CreateObject(1507,1465.1660156,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk18, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk19 = CreateObject(1507,1499.0699463,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk19, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk20 = CreateObject(1507,1497.6569824,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk20, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk21 = CreateObject(1507,1497.6191406,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk21, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk22 = CreateObject(1507,1497.6569824,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk22, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk23 = CreateObject(1507,1499.0699463,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk23, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk24 = CreateObject(1507,1497.6191406,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk24, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk25 = CreateObject(1507,1506.4429932,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk25, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk26 = CreateObject(1507,1505.0100098,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk26, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk27 = CreateObject(1507,1513.8299561,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk27, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk28 = CreateObject(1507,1512.4000244,-1520.9399414,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk28, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk29 = CreateObject(1507,1504.9794922,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk29, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk30 = CreateObject(1507,1512.3691406,-1520.9560547,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk30, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk31 = CreateObject(1507,1512.4000244,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk31, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk32 = CreateObject(1507,1513.8299561,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk32, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk33 = CreateObject(1507,1512.3691406,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk33, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk34 = CreateObject(1507,1506.4429932,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk34, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk35 = CreateObject(1507,1505.0100098,-1515.3299561,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk35, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk36 = CreateObject(1507,1504.9794922,-1514.3222656,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk36, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk37 = CreateObject(1507,1488.0810547,-1538.0999756,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk37, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk38 = CreateObject(1507,1491.0129395,-1538.0999756,3305.0000000,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(kosykk38, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk39 = CreateObject(1507,1489.5498047,-1538.1169434,3307.4050293,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykk39, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykk40 = CreateObject(1507,1489.5710449,-1538.1169434,3307.4328613,270.0000000,0.0000000,180.0000000);
	SetObjectMaterial(kosykk40, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);


    //Обычные объекты
    CreateObject(19172,1481.1359863,-1550.270019,3400,0.0000000,0.0000000,90.0000000);
    CreateObject(19174,1497.6970214,-1550.270019,3400,0.0000000,0.0000000,270.0000000);
	CreateObject(18755,1489.5380859,-1514.6894531,3399.6599121,0.0000000,0.0000000,90.0000000);
	CreateObject(18756,1487.5292969,-1514.7099609,3399.6499023,0.0000000,0.0000000,90.0000000);
	CreateObject(18757,1491.5322266,-1514.7099609,3399.6499023,0.0000000,0.0000000,90.0000000);
	CreateObject(14629,1489.5380859,-1532.5500488,3406.5500488,0.0000000,0.0000000,0.0000000);
	CreateObject(1569,1488.0400391,-1563.2900391,3397.7199707,0.0000000,0.0000000,0.0000000);
	CreateObject(1569,1491.0400391,-1563.2841797,3397.7199707,0.0000000,0.0000000,179.9945068);
	CreateObject(1726,1480.3499756,-1541.3496094,3397.7351074,0.0000000,0.0000000,90.0000000);
	CreateObject(1726,1480.3496094,-1545.1396484,3397.7351074,0.0000000,0.0000000,90.0000000);
	CreateObject(1726,1480.3499756,-1537.5439453,3397.7351074,0.0000000,0.0000000,90.0000000);
	CreateObject(1569,1479.1800537,-1521.1999512,3397.7199707,0.0000000,0.0000000,270.0000000);
	CreateObject(1569,1479.1800537,-1524.1999512,3397.7199707,0.0000000,0.0000000,90.0000000);
	CreateObject(1726,1480.4000244,-1519.3399658,3397.7351074,0.0000000,0.0000000,44.9945068);
	CreateObject(1726,1497.0000000,-1517.8994141,3397.7351074,0.0000000,0.0000000,314.9945068);
	CreateObject(630,1480.3499756,-1538.4492188,3398.7600098,0.0000000,0.0000000,0.0000000);
	CreateObject(630,1480.3499756,-1542.2500000,3398.7600098,0.0000000,0.0000000,0.0000000);
	CreateObject(632,1480.9794922,-1546.7998047,3398.1000977,0.0000000,0.0000000,0.0000000);
	CreateObject(632,1480.9794922,-1533.8496094,3398.1000977,0.0000000,0.0000000,0.0000000);
	CreateObject(1726,1498.4794922,-1521.5585938,3397.7351074,0.0000000,0.0000000,270.0000000);
	CreateObject(1726,1498.4179688,-1525.7656250,3397.7351074,0.0000000,0.0000000,225.0000000);
	CreateObject(948,1498.4794922,-1520.5673828,3397.6999512,0.0000000,0.0000000,0.0000000);
	CreateObject(948,1498.4794922,-1524.5478516,3397.6999512,0.0000000,0.0000000,0.0000000);
	CreateObject(1827,1482.5999756,-1540.3499756,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(1827,1496.1999512,-1522.5870361,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(2852,1496.1999512,-1522.5999756,3398.1599121,0.0000000,0.0000000,0.0000000);
	CreateObject(2852,1482.5600586,-1540.3499756,3398.1599121,0.0000000,0.0000000,0.0000000);
	CreateObject(2894,1497.0468750,-1540.1999512,3398.7800293,0.0000000,0.0000000,90.0000000);
	CreateObject(2753,1497.0908203,-1542.1992188,3398.9299316,0.0000000,0.0000000,270.0000000);
	CreateObject(2753,1497.0908203,-1538.1992188,3398.9299316,0.0000000,0.0000000,269.9945068);
	CreateObject(1726,1498.4794922,-1555.0000000,3397.7351074,0.0000000,0.0000000,270.0000000);
	CreateObject(948,1498.4794922,-1554.1699219,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(18084,1493.9492188,-1562.3330078,3399.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(18084,1485.1199951,-1562.3330078,3399.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(948,1498.4794922,-1557.8994141,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(3935,1497.8000488,-1561.5500488,3399.0000000,0.0000000,0.0000000,45.0000000);
	CreateObject(3935,1480.8499756,-1561.5500488,3399.0000000,0.0000000,0.0000000,315.0000000);
	CreateObject(948,1480.3496094,-1554.1699219,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(948,1480.3496094,-1557.8994141,3397.7351074,0.0000000,0.0000000,0.0000000);
	CreateObject(1726,1480.3496094,-1557.0050049,3397.7351074,0.0000000,0.0000000,90.0000000);
	CreateObject(1363,1478.9499512,-1526.9554443,3398.5720215,0.0000000,0.0000000,0.0000000);
	CreateObject(1363,1478.9499512,-1526.2590332,3398.5720215,0.0000000,0.0000000,0.0000000);
	CreateObject(1363,1478.9499512,-1525.5620117,3398.5720215,0.0000000,0.0000000,0.0000000);
	CreateObject(2773,1487.7900391,-1561.5999756,3398.2529297,0.0000000,0.0000000,0.0000000);
	CreateObject(2773,1491.1989746,-1561.5999756,3398.2529297,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1499.4746094,-1524.5478516,3399.6499023,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1499.4749756,-1520.5673828,3399.6499023,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1499.4749756,-1554.1699219,3399.6499023,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1499.4749756,-1557.8994141,3399.6499023,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1479.3549805,-1557.8994141,3399.6499023,0.0000000,0.0000000,180.0000000);
	CreateObject(1731,1479.3549805,-1554.1699219,3399.6499023,0.0000000,0.0000000,179.9945068);
	CreateObject(18755,1489.5380859,-1514.6894531,3306.9350586,0.0000000,0.0000000,90.0000000);
	CreateObject(18756,1487.5292969,-1514.7099609,3306.8999023,0.0000000,0.0000000,90.0000000);
	CreateObject(18757,1491.5322266,-1514.7099609,3306.8999023,0.0000000,0.0000000,90.0000000);
	CreateObject(1504,1489.5500488,-1538.2900391,3304.9299316,0.0000000,0.0000000,0.0000000);
	CreateObject(1504,1489.5830078,-1538.2619629,3304.9299316,0.0000000,0.0000000,180.0000000);
	CreateObject(1506,1479.9670410,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1472.5699463,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1465.1660156,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1497.6199951,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1504.9799805,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1512.3699951,-1521.1099854,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1465.1660156,-1516.6989746,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1472.5693359,-1516.6982422,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1479.9670410,-1516.6989746,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1497.6199951,-1516.6989746,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1504.9799805,-1516.6989746,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(1506,1512.3699951,-1516.6989746,3304.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(18084,1521.4599609,-1518.8800049,3306.6999512,0.0000000,0.0000000,270.0000000);
	CreateObject(1569,1458.2399902,-1520.4100342,3305.0048828,0.0000000,0.0000000,90.0000000);
	CreateObject(1569,1458.2343750,-1517.4090576,3305.0048828,0.0000000,0.0000000,270.0000000);
	CreateObject(1731,1509.4365234,-1516.8593750,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1502.0292969,-1516.8593750,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1516.8193359,-1516.8593750,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1494.6748047,-1516.8593750,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1484.4200439,-1516.8599854,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1477.0300293,-1516.8599854,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1469.6199951,-1516.8599854,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1462.2199707,-1516.8599854,3307.0000000,0.0000000,0.0000000,90.0000000);
	CreateObject(1731,1462.2199707,-1520.9250488,3307.0000000,0.0000000,0.0000000,270.0000000);
	CreateObject(1731,1469.6199951,-1520.9250488,3307.0000000,0.0000000,0.0000000,269.9945068);
	CreateObject(1731,1477.0300293,-1520.9250488,3307.0000000,0.0000000,0.0000000,269.9945068);
	CreateObject(1731,1484.4199219,-1520.9248047,3307.0000000,0.0000000,0.0000000,269.9890137);
	CreateObject(948,1520.0000000,-1517.3599854,3305.0048828,0.0000000,0.0000000,0.0000000);
	CreateObject(948,1520.0000000,-1520.4699707,3305.0048828,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1494.6748047,-1520.9248047,3307.0000000,0.0000000,0.0000000,269.9890137);
	CreateObject(1731,1502.0292969,-1520.9248047,3307.0000000,0.0000000,0.0000000,269.9890137);
	CreateObject(1731,1509.4365234,-1520.9248047,3307.0000000,0.0000000,0.0000000,269.9890137);
	CreateObject(1731,1516.8193359,-1520.9248047,3307.0000000,0.0000000,0.0000000,269.9890137);
	CreateObject(1731,1491.5699463,-1524.0200195,3307.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1491.5699463,-1529.9219971,3307.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1491.5699463,-1535.8199463,3307.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(1731,1487.5250244,-1524.0200195,3307.0000000,0.0000000,0.0000000,180.0000000);
	CreateObject(1731,1487.5250244,-1529.9219971,3307.0000000,0.0000000,0.0000000,179.9945068);
	CreateObject(1731,1487.5250244,-1535.8199463,3307.0000000,0.0000000,0.0000000,179.9945068);
	CreateObject(18075,1489.5380859,-1521.6300049,3309.1799316,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1502.3000488,-1521.6300049,3309.1799316,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1514.9000244,-1521.6300049,3309.1799316,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1476.5999756,-1521.6300049,3309.1799316,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1464.0000000,-1521.6300049,3309.1799316,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1489.5380859,-1532.5000000,3309.1799316,0.0000000,0.0000000,90.0000000);
    
    
    //---- Объекты номера 1 и 2 ----//
    //Объекты с заменеными текстурами
    //---- Пол (Номер 1)
	new polnom11 = CreateObject(19380,1511.2998047,-1530.3652344,3480.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(polnom11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
	
	new polnom12 = CreateObject(19380,1511.2998047,-1540.0000000,3480.0000000,0.0000000,90.0000000,0.0000000);
    SetObjectMaterial(polnom12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);

	//---- Стены (Номер 1)
	new stenan11 = CreateObject(19377,1507.0000000,-1530.3652344,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan11, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
    new stenan12 = CreateObject(19377,1507.0000000,-1540.0000000,3483.0000000,0.0000000,0.0000000,0.0000000);
    SetObjectMaterial(stenan12, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
    
	new stenan13 = CreateObject(19377,1515.5898438,-1540.0000000,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan13, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan14 = CreateObject(19377,1515.5898438,-1530.3652344,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan14, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan15 = CreateObject(19377,1511.2998047,-1527.5000000,3483.4333496,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan15, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan16 = CreateObject(19377,1511.2998047,-1544.8496094,3483.4333496,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan16, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan17 = CreateObject(19377,1507.3281250,-1539.9443359,3483.4333496,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan17, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan18 = CreateObject(19362,1512.5000000,-1544.6806641,3481.8359375,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan18, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan19 = CreateObject(19362,1512.5000000,-1544.6806641,3485.3359375,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan19, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan110 = CreateObject(19362,1512.5000000,-1541.4697266,3485.3359375,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan110, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new stenan111 = CreateObject(19391,1512.5000000,-1541.4697266,3481.8359375,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan111, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- Плинтуса (Номер 1)
	new plintus11 = CreateObject(19375,1507.0292969,-1530.3652344,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus12 = CreateObject(19375,1507.0292969,-1540.0000000,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus13 = CreateObject(19375,1507.3769531,-1539.9150391,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus13, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus14 = CreateObject(19375,1511.2998047,-1527.5263672,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus14, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus15 = CreateObject(19375,1515.5546875,-1530.3652344,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus15, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus16 = CreateObject(19375,1515.5546875,-1540.0000000,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus16, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus17 = CreateObject(19375,1511.2998047,-1544.8125000,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus17, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus18 = CreateObject(19375,1507.3281250,-1539.9799805,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus18, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus19 = CreateObject(19386,1512.5400391,-1541.4794922,3478.5000000,0.0000000,179.9945068,0.0000000);
	SetObjectMaterial(plintus19, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus110 = CreateObject(19386,1512.4599609,-1541.4814453,3478.4980469,0.0000000,179.9945068,0.0000000);
	SetObjectMaterial(plintus110, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus111 = CreateObject(19356,1512.5400391,-1544.6923828,3478.5000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus111, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new plintus112 = CreateObject(19356,1512.4599609,-1544.6923828,3478.5000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus112, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);

	//---- Потолок (Номер 1)
	new potolokn11 = CreateObject(19381,1511.2998047,-1530.3652344,3484.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(potolokn11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF363636);
	
	new potolokn12 = CreateObject(19381,1511.2998047,-1540.0000000,3484.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(potolokn12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF363636);

	//---- Рама окна (Номер 1)
	new raman11 = CreateObject(1569,1510.0400391,-1527.6992188,3480.8144531,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(raman11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF000000);
	
	new raman12 = CreateObject(1569,1510.0400391,-1527.6992188,3483.1989746,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(raman12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF000000);
	
	new raman13 = CreateObject(1569,1509.9863281,-1527.6992188,3480.7548828,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(raman13, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF000000);
	
	new raman14 = CreateObject(1569,1512.6054688,-1527.6992188,3480.7548828,0.0000000,0.0000000,90.0000000);
    SetObjectMaterial(raman14, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF000000);

	//---- ТВ (Номер 1)
	new tvn1 = CreateObject(2267,1515.4794922,-1533.8007812,3482.1000977,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(tvn1, 0, 16000, "con_drivein", "drvin_screen", 0xFF000000);
    SetObjectMaterial(tvn1, 1, 9362, "sfn_byofficeint", "CJ_TV_SCREEN", 0);
	
	//---- Мебель (Номер 1)
	new komodn1 = CreateObject(1743,1514.0292969,-1533.2988281,3480.0859375,0.0000000,0.0000000,270.0000000); //Комод под ТВ
	SetObjectMaterial(komodn1, 0, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	SetObjectMaterial(komodn1, 1, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	SetObjectMaterial(komodn1, 2, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	
	new schkafn1 = CreateObject(2576,1513.9228516,-1528.0996094,3480.0859375,0.0000000,0.0000000,0.0000000); //Шкаф
	SetObjectMaterial(schkafn1, 0, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	
	new kreslon11 = CreateObject(1724,1507.5100098,-1528.7299805,3480.0859375,0.0000000,0.0000000,45.0000000); //Кресло 1
	SetObjectMaterial(kreslon11, 1, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	
	new kreslon12 = CreateObject(1724,1512.0996094,-1539.2753906,3480.0859375,0.0000000,0.0000000,179.9945068); //Кресло 2
	SetObjectMaterial(kreslon12, 1, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	
	new divann1 = CreateObject(1723,1511.5000000,-1534.8291016,3480.0859375,0.0000000,0.0000000,90.0000000); //Диван
	SetObjectMaterial(divann1, 1, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
	
	new schkafvn1 = CreateObject(2145,1510.3291016,-1540.2500000,3480.0000000,0.0000000,0.0000000,0.0000000); //Шкаф в ванной
    SetObjectMaterial(schkafvn1, 1, 2566, "cj_hotel_sw", "CJ_WOOD_DARK", 0);
    SetObjectMaterial(schkafvn1, 2, 2566, "cj_hotel_sw", "CJ_WOOD1", 0);

	//---- Дверь в ванную (Номер 1)
	new doorvn1 = CreateObject(1491,1512.5000000,-1542.2197266,3480.0791016,0.0000000,0.0000000,90.0000000);
    SetObjectMaterial(doorvn1, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);

	//---- Косяк двери (Номер 1)
	new kosykn11 = CreateObject(1505,1513.3496094,-1546.1800537,3480.0859375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(kosykn11, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykn12 = CreateObject(1505,1514.7998047,-1546.1800537,3480.0859375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(kosykn12, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	new kosykn13 = CreateObject(1505,1513.2998047,-1544.6650391,3482.5000000,90.0000000,0.0000000,0.0000000);
	SetObjectMaterial(kosykn13, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF2F2D2D);
	
	

	//---- Пол (Номера 2)
	new polnom21 = CreateObject(19380,1511.2998047,-1560.0000000,3480.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(polnom21, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF0482FF);
	
	new polnom22 = CreateObject(19380,1511.2998047,-1569.6328125,3480.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(polnom22, 0, 14858, "gen_pol_vegas", "grey_carpet_256", 0xFF0482FF);

	//---- Стены (Номер 2)
	new stenan21 = CreateObject(19377,1511.2998047,-1555.1999512,3483.4333496,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan21, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan22 = CreateObject(19377,1515.5898438,-1560.0000000,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan22, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan23 = CreateObject(19377,1515.5898438,-1569.6328125,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan23, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan24 = CreateObject(19377,1507.0000000,-1560.0000000,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan24, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan25 = CreateObject(19377,1507.0000000,-1569.6328125,3483.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan25, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan26 = CreateObject(19377,1511.4414062,-1572.0000000,3483.4333496,90.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan26, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan27 = CreateObject(19377,1512.3652344,-1571.9492188,3485.3369141,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(stenan27, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan28 = CreateObject(19362,1513.9000244,-1567.1999512,3485.3359375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan28, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);
	
	new stenan29 = CreateObject(19391,1513.8994141,-1567.1992188,3481.8359375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(stenan29, 0, 4002, "cityhall_lan", "LAcityhwal1", 0xFF0482FF);

	//---- Плинтуса (Номер 2)
	new plintus21 = CreateObject(19375,1515.5546875,-1560.0000000,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus21, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus22 = CreateObject(19375,1515.5546875,-1569.6328125,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus22, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus23 = CreateObject(19375,1507.0292969,-1560.0000000,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus23, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus24 = CreateObject(19375,1507.0292969,-1569.6328125,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus24, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus25 = CreateObject(19375,1511.4414062,-1555.2230225,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus25, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus26 = CreateObject(19375,1511.4414062,-1571.9599609,3475.4331055,90.0000000,90.0000000,0.0000000);
	SetObjectMaterial(plintus26, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus27 = CreateObject(19375,1512.3242188,-1571.9000244,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus27, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus28 = CreateObject(19375,1512.4000244,-1572.0000000,3475.0000000,0.0000000,0.0000000,0.0000000);
	SetObjectMaterial(plintus28, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus29 = CreateObject(19386,1513.9100342,-1567.1700439,3478.5000000,0.0000000,180.0000000,90.0000000);
	SetObjectMaterial(plintus29, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new plintus210 = CreateObject(19386,1513.9079590,-1567.2290039,3478.5000000,0.0000000,179.9945068,90.0000000);
	SetObjectMaterial(plintus210, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- Потолок (Номер 2)
    new potolokn21 = CreateObject(19381,1511.2998047,-1560.0000000,3484.0000000,0.0000000,90.0000000,0.0000000);
    SetObjectMaterial(potolokn21, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
    
	new potolokn22 = CreateObject(19381,1511.2998047,-1569.6328125,3484.0000000,0.0000000,90.0000000,0.0000000);
	SetObjectMaterial(potolokn22, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- Рама окна (Номер 2)
	new raman21 = CreateObject(1569,1510.9300537,-1571.8000488,3480.8144531,90.0000000,0.0000000,270.0000000);
	SetObjectMaterial(raman21, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new raman22 = CreateObject(1569,1510.9300537,-1571.8000488,3483.1989746,90.0000000,0.0000000,270.0000000);
	SetObjectMaterial(raman22, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new raman23 = CreateObject(1569,1508.3649902,-1571.8000488,3480.7546387,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(raman23, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new raman24 = CreateObject(1569,1510.9843750,-1571.8000488,3480.7546387,0.0000000,0.0000000,269.9945068);
	SetObjectMaterial(raman24, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- ТВ (Номер 2)
	new tvn21 = CreateObject(2267,1515.4794922,-1561.4799805,3482.1000977,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(tvn21, 0, 16000, "con_drivein", "drvin_screen", 0xFFFFFFFF);
    SetObjectMaterial(tvn21, 1, 9362, "sfn_byofficeint", "CJ_TV_SCREEN", 0);
	
	new tvn22 = CreateObject(2267,1512.2500000,-1569.5000000,3482.0000000,0.0000000,0.0000000,270.0000000);
	SetObjectMaterial(tvn22, 0, 16000, "con_drivein", "drvin_screen", 0xFFFFFFFF);
    SetObjectMaterial(tvn22, 1, 9362, "sfn_byofficeint", "CJ_TV_SCREEN", 0);

	//---- Мебель (Номер 2)
	new schkafn2 = CreateObject(2576,1507.5999756,-1567.3010254,3480.0000000,0.0000000,0.0000000,90.0000000); //Шкаф
	SetObjectMaterial(schkafn2, 0, 2563, "cj_hotel_sw", "CJ_WOOD1", 0);
	
	new schkafvn2 = CreateObject(2145,1515.2500000,-1567.5600586,3480.0859375,0.0000000,0.0000000,0.0000000); //Шкаф в ванной
	SetObjectMaterial(schkafvn2, 1, 2563, "cj_hotel_sw", "CJ_WOOD1", 0xFF0482FF);
	SetObjectMaterial(schkafvn2, 2, 2563, "cj_hotel_sw", "CJ_WOOD1", 0);

	//---- Дверь в ванную (Номер 1)
	new doorvn2 = CreateObject(1491,1514.6440430,-1567.1992188,3480.0791016,0.0000000,0.0000000,180.0000000);
	SetObjectMaterial(doorvn2, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);

	//---- Косяк двери (Номер 2)
	new kosykn21 = CreateObject(1505,1513.3496094,-1555.3994141,3480.0859375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(kosykn21, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new kosykn22 = CreateObject(1505,1514.7998047,-1555.3994141,3480.0859375,0.0000000,0.0000000,90.0000000);
	SetObjectMaterial(kosykn22, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);
	
	new kosykn23 = CreateObject(1505,1513.2998047,-1552.8691406,3482.5000000,90.0000000,0.0000000,0.0000000);
    SetObjectMaterial(kosykn23, 0, 4002, "cityhall_lan", "LAcityhwal1", 0);


    //Обычные объекты
    CreateObject(1738,1511.6992188,-1571.8193359,3480.5600586,0.0000000,0.0000000,179.9945068);
	CreateObject(1738,1512.6999512,-1568.0000000,3480.5600586,0.0000000,0.0000000,90.0000000);
    CreateObject(2262,1508.8399658,-1539.359985,3481.5,0.0000000,0.0000000,180.0000000);
    CreateObject(1738,1509.1992188,-1527.6992188,3480.5600586,0.0000000,0.0000000,0.0000000);
	CreateObject(1738,1511.5498047,-1540.4023438,3480.5600586,0.0000000,0.0000000,0.0000000);
    CreateObject(1506,1513.2998047,-1544.7998047,3480.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(1702,1507.6350098,-1570.4000244,3480.0783691,0.0000000,0.0000000,90.0000000);
	CreateObject(18084,1511.2998047,-1528.4873047,3481.6999512,0.0000000,0.0000000,179.9945068);
	CreateObject(2566,1509.5898438,-1535.3496094,3480.6660156,0.0000000,0.0000000,90.0000000);
	CreateObject(2568,1510.3994141,-1539.3496094,3480.0859375,0.0000000,0.0000000,179.9945068);
	CreateObject(2517,1508.5693359,-1544.2998047,3480.0859375,0.0000000,0.0000000,90.0000000);
	CreateObject(2526,1508.8193359,-1540.5292969,3480.0859375,0.0000000,0.0000000,179.9945068);
	CreateObject(2528,1510.0234375,-1544.2998047,3480.0859375,0.0000000,0.0000000,179.9945068);
	CreateObject(2523,1511.9238281,-1543.0156250,3480.0849609,0.0000000,0.0000000,270.0000000);
	CreateObject(14677,1510.6494141,-1545.2148438,3482.0600586,0.0000000,0.0000000,90.0000000);
	CreateObject(2836,1507.6796875,-1542.2988281,3480.0859375,0.0000000,0.0000000,0.0000000);
	CreateObject(2836,1507.6800537,-1543.4000244,3480.0859375,0.0000000,0.0000000,0.0000000);
	CreateObject(630,1513.3994141,-1528.0996094,3481.1110840,0.0000000,0.0000000,271.9995117);
	CreateObject(18075,1511.2998047,-1533.7998047,3483.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(18075,1507.0999756,-1546.5600586,3483.9499512,0.0000000,0.0000000,0.0000000);
	CreateObject(18084,1509.6700439,-1571.0000000,3481.6999512,0.0000000,0.0000000,0.0000000);
	CreateObject(2563,1509.5517578,-1562.9799805,3480.0859375,0.0000000,0.0000000,90.0000000);
	CreateObject(1506,1513.2998047,-1555.2792969,3480.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(2562,1507.1999512,-1555.7979736,3480.0859375,0.0000000,0.0000000,0.0000000);
	CreateObject(1705,1511.3000488,-1555.8199463,3480.0859375,0.0000000,0.0000000,0.0000000);
	CreateObject(1743,1514.0292969,-1560.9499512,3480.0859375,0.0000000,0.0000000,270.0000000);
	CreateObject(948,1507.6500244,-1567.7580566,3480.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(948,1507.6500244,-1571.1500244,3480.0000000,0.0000000,0.0000000,0.0000000);
	CreateObject(2517,1513.0780029,-1570.4129639,3480.0859375,0.0000000,0.0000000,180.0000000);
	CreateObject(2528,1515.0400391,-1569.5500488,3480.0859375,0.0000000,0.0000000,270.0000000);
	CreateObject(2523,1514.9899902,-1570.8000488,3480.0859375,0.0000000,0.0000000,270.0000000);
	CreateObject(2836,1514.3599854,-1570.0000000,3480.0859375,0.0000000,0.0000000,90.0000000);
	CreateObject(14677,1513.7399902,-1573.0100098,3482.0600586,0.0000000,0.0000000,90.0000000);
	CreateObject(1720,1508.1519775,-1556.4720459,3480.0859375,0.0000000,0.0000000,180.0000000);
	CreateObject(2120,1508.8170166,-1538.5000000,3480.7241211,0.0000000,0.0000000,90.0000000);
	CreateObject(18075,1511.2998047,-1561.2080078,3483.9399414,0.0000000,0.0000000,0.0000000);
	CreateObject(18075,1516.6700439,-1573.8000488,3483.9399414,0.0000000,0.0000000,0.0000000);
    
    
	//Пикапы
	EnterSS = CreatePickup(1314, 2, 1489.5380859375, -1517.0999755859, 3398.6999511719); //Пикап входа в коридор из холла
	ExitSS = CreatePickup(1314, 2, 1489.5380859375, -1517.0999755859, 3305.9899902344); //Пикап выхода из коридора в холл

	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
     if(pickupid == EnterSS) //Телепорт в коридор из холла
        {
            SetPlayerPos(playerid,1489.4581, -1519.4474, 3306.0044);
            SetPlayerInterior(playerid, 0);
        }
     if(pickupid == ExitSS) //Телепорт из коридора в холл
        {
            SetPlayerPos(playerid,1489.5272, -1519.7052, 3398);
            SetPlayerInterior(playerid, 0);
        }
	 return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
     if(strcmp("/verona", cmdtext, true, 10) == 0) //Телепортироватся в холл отеля
        {
            SetPlayerPos(playerid,1489.5311, -1560.3278, 3398.7405);
            SetPlayerInterior(playerid, 0);
            return 1;
        }
     if(strcmp("/n1", cmdtext, true, 10) == 0) //Телепортироватся в номер 1
        {
            SetPlayerPos(playerid,1514.1198, -1543.8586, 3481.0859);
            SetPlayerInterior(playerid, 0);
            return 1;
        }
     if(strcmp("/n2", cmdtext, true, 10) == 0) //Телепортироватся в номер 2
        {
            SetPlayerPos(playerid,1514.1469, -1556.2971, 3481.0859);
            SetPlayerInterior(playerid, 0);
            return 1;
        }
     if(strcmp("/exitn", cmdtext, true, 10) == 0) //Телепортироватся в коридор
        {
            SetPlayerPos(playerid,1498.2416, -1518.8777, 3306.0044);
            SetPlayerInterior(playerid, 0);
            return 1;
        }
	 return 0;
}
