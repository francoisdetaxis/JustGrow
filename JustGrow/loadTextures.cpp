#include "loadTextures.h"

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
	Mytexture skull("./resources/image/icons/skull-icon.png", 1);
	Mytexture timer("./resources/image/icons/timer-icon.png", 1);
	Mytexture muteSound("./resources/image/icons/mute-sound.png", 1);
	Mytexture sound("./resources/image/icons/sound.png", 1);

	//menu
	Mytexture menu("./resources/image/menu/menu.png", 1);
	Mytexture btn("./resources/image/menu/btn-default.png", 1);

	//money
	Mytexture coin("./resources/image/gold-coin.png", 1);
	Mytexture coinSmall("./resources/image/gold-coin-small.png", 1);

	//background
	Mytexture background("./resources/image/backgrounds/game_background_1.png", 1);

	std::map<std::string, Mytexture> textures{
		{"face", face},
		{"btn", btn},
		{"background", background},
		{"muteSound", muteSound},
		{"sound", sound},
		{"skull", skull},
		{"timer", timer},
		{"coinSmall", coinSmall},
		{"coin", coin},
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