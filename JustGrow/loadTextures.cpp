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
	Mytexture platform1("./resources/image/platforms/platform1.png", 1);
	Mytexture platform2("./resources/image/platforms/platform2.png", 1);
	Mytexture platform3("./resources/image/platforms/platform3.png", 1);
	Mytexture platform4("./resources/image/platforms/platform4.png", 1);
	Mytexture platform6("./resources/image/platforms/platform6.png", 1);

	//hp bars
	Mytexture hpBarEmpty("./resources/image/hpbar/hpbarempty.png", 1);
	Mytexture hpBarFull("./resources/image/hpbar/hpbarfull.png", 1);

	//cursors
	Mytexture attackCursor("./resources/image/cursors/sword_cursor.png", 1);
	Mytexture handCursor("./resources/image/cursors/hand_cursor.png", 1);

	std::map<std::string, Mytexture> textures{
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
		{"platform6", platform6},
		{"hpBarEmpty", hpBarEmpty},
		{"hpBarFull", hpBarFull},
		{"attackCursor", attackCursor},
		{"handCursor", handCursor}
	};
	return textures;
}