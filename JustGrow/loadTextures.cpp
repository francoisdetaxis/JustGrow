#include "main.h"

std::map<std::string, Mytexture> loadTextures()
{
	//monsters
	Mytexture monster1_idle("./resources/image/sprites/monster1_idle.png", 12);
	Mytexture monster1_dying("./resources/image/sprites/monster1_dying.png", 15);
	Mytexture monster1_hurt("./resources/image/sprites/monster1_hurt.png", 12);
	Mytexture monster2_idle("./resources/image/sprites/monster2_idle.png", 12);
	Mytexture monster2_dying("./resources/image/sprites/monster2_dying.png", 15);
	Mytexture monster2_hurt("./resources/image/sprites/monster2_hurt.png", 12);
	Mytexture monster3_idle("./resources/image/sprites/monster3_idle.png", 12);
	Mytexture monster3_dying("./resources/image/sprites/monster3_dying.png", 15);
	Mytexture monster3_hurt("./resources/image/sprites/monster3_hurt.png", 12);

	//platforms
	//TODO limit the number of textures --> switcher the sprites texture is costly (investigate)
	//all platforms on one big texture and move a Rect around is also a possibility
	Mytexture platform1("./resources/image/platforms/platform1.png", 1);
	Mytexture platform2("./resources/image/platforms/platform2.png", 1);
	Mytexture platform3("./resources/image/platforms/platform3.png", 1);
	Mytexture platform4("./resources/image/platforms/platform4.png", 1);
	Mytexture platform5("./resources/image/platforms/platform5.png", 1);
	Mytexture platform6("./resources/image/platforms/platform6.png", 1);
	Mytexture platform7("./resources/image/platforms/platform7.png", 1);
	Mytexture platform8("./resources/image/platforms/platform8.png", 1);
	Mytexture platform9("./resources/image/platforms/platform9.png", 1);

	//hp bars
	Mytexture hpBarEmpty("./resources/image/hpbar/hpbarempty.png", 1);
	Mytexture hpBarFull("./resources/image/hpbar/hpbarfull.png", 1);

	//cursors
	Mytexture attackCursor("./resources/image/cursors/sword_cursor.png", 1);
	Mytexture handCursor("./resources/image/cursors/hand_cursor.png", 1);
	Mytexture hit("./resources/image/hit.png", 1);

	//icons
	Mytexture clickUpgrade("./resources/image/icons/iconClickDmgUpgrade.png", 1);
	Mytexture face("./resources/image/icons/iconFace.png", 1);

	//menu
	Mytexture menu("./resources/image/menu/menu.png", 1);
	Mytexture pinkbg("./resources/image/pinkgbg.png", 1);

	std::map<std::string, Mytexture> textures{
		{"face", face},
		{"pinkbg", pinkbg},
		{"clickUpgrade", clickUpgrade},
		{"menu", menu},
		{"monster1_idle", monster1_idle},
		{"monster2_idle", monster2_idle},
		{"monster3_idle", monster3_idle},
		{"monster1_dying", monster1_dying},
		{"monster2_dying", monster2_dying},
		{"monster3_dying", monster3_dying},
		{"monster1_hurt", monster1_hurt},
		{"monster2_hurt", monster2_hurt},
		{"monster3_hurt", monster3_hurt},
		{"platform1", platform1},
		{"platform2", platform2},
		{"platform3", platform3},
		{"platform4", platform4},
		{"platform5", platform5},
		{"platform6", platform6},
		{"platform7", platform7},
		{"platform8", platform8},
		{"platform9", platform9},
		{"hpBarEmpty", hpBarEmpty},
		{"hpBarFull", hpBarFull},
		{"attackCursor", attackCursor},
		{"hit", hit},
		{"handCursor", handCursor}
	};
	return textures;
}

//std::unordered_map<std::string, Mytexture> loadTextures()
//{
//	//monsters
//	Mytexture monster1_idle("./resources/image/sprites/monster1-idle.png", 12, "monster1_idle");
//	Mytexture monster1_dying("./resources/image/sprites/monster1-dying.png", 15, "monster1_dying");
//	Mytexture monster1_hurt("./resources/image/sprites/monster1-hurt.png", 12, "monster1_hurt");
//
//	//platforms
//	Mytexture platform1("./resources/image/platforms/platform1.png", 1, "platform1");
//	Mytexture platform2("./resources/image/platforms/platform2.png", 1, "platform2");
//	Mytexture platform3("./resources/image/platforms/platform3.png", 1, "platform3");
//	Mytexture platform4("./resources/image/platforms/platform4.png", 1, "platform4");
//	Mytexture platform6("./resources/image/platforms/platform6.png", 1, "platform6");
//
//	//hp bars
//	Mytexture hpBarEmpty("./resources/image/hpbar/hpbarempty.png", 1, "hpBarEmpty");
//	Mytexture hpBarFull("./resources/image/hpbar/hpbarfull.png", 1, "hpBarFull");
//
//	//cursors
//	Mytexture attackCursor("./resources/image/cursors/sword-cursor.png", 1, "attackCursor");
//	Mytexture handCursor("./resources/image/cursors/hand-cursor.png", 1, "handCursor");
//
//	std::unordered_map<std::string, Mytexture> textures{
//		{"1_idle_monster", monster1_idle},
//		{"monster1_dying", monster1_dying},
//		{"monster1_hurt", monster1_hurt},
//		{"platform1", platform1},
//		{"platform2", platform2},
//		{"platform3", platform3},
//		{"platform4", platform4},
//		{"platform6", platform6},
//		{"hpBarEmpty", hpBarEmpty},
//		{"hpBarFull", hpBarFull},
//		{"attackCursor", attackCursor},
//		{"handCursor", handCursor}
//	};
//	return textures;
//}