#include "main.h"

std::map<std::string, Mytexture> loadTextures()
{
	//monsters

	Mytexture monster1_idle("./resources/image/sprites/monster1-idle.png", 12);

	//platforms
	Mytexture platform1("./resources/image/platforms/platform1.png", 1);
	Mytexture platform2("./resources/image/platforms/platform2.png", 1);
	Mytexture platform3("./resources/image/platforms/platform3.png", 1);

	//hp bars
	Mytexture hpBarEmpty("./resources/image/hpbar/hpbarempty.png", 1);
	Mytexture hpBarFull("./resources/image/hpbar/hpbarfull.png", 1);

	//cursors
	Mytexture attackCursor("./resources/image/cursors/sword-cursor.png", 1);
	Mytexture handCursor("./resources/image/cursors/hand-cursor.png", 1);

	std::map<std::string, Mytexture> textures{
		{"monster1_idle", monster1_idle},
		{"platform1", platform1},
		{"platform2", platform2},
		{"platform3", platform3},
		{"hpBarEmpty", hpBarEmpty},
		{"hpBarFull", hpBarFull},
		{"attackCursor", attackCursor},
		{"handCursor", handCursor}
	};
	return textures;
}