#include "main.h"

std::map<std::string, sf::Texture> loadTextures()
{
	//monsters
	sf::Texture monster1;

	//platforms
	sf::Texture platform1;
	sf::Texture platform2;
	sf::Texture platform3;

	//hp bars
	sf::Texture hpBarEmpty;
	sf::Texture hpBarFull;

	//cursors
	sf::Texture attackCursor;
	sf::Texture handCursor;


	//monsters
	monster1.loadFromFile("./resources/image/sprites/running_man.png");

	//platforms
	platform1.loadFromFile("./resources/image/platforms/platform1.png");
	platform2.loadFromFile("./resources/image/platforms/platform2.png");
	platform3.loadFromFile("./resources/image/platforms/platform3.png");

	//hp bars
	hpBarEmpty.loadFromFile("./resources/image/hpbar/hpbarempty.png");
	hpBarFull.loadFromFile("./resources/image/hpbar/hpbarfull.png");

	//cursors
	attackCursor.loadFromFile("./resources/image/cursors/sword-cursor.png");
	handCursor.loadFromFile("./resources/image/cursors/hand-cursor.png");

	std::map<std::string, sf::Texture> textures{
		{"monster1", monster1},
		{"platform1", platform1},
		{"platform2", platform2},
		{"platform3", platform3},
		{"hpBarFull", hpBarFull},
		{"hpBarEmpty", hpBarEmpty},
		{"attackCursor", attackCursor},
		{"handCursor", handCursor}
	};

	return textures;
}
