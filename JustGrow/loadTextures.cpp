#include "loadTextures.h"



std::map<std::string, sf::Texture> loadTextures()
{
	sf::Texture monster1;
	sf::Texture platform1;
	sf::Texture platform2;
	sf::Texture platform3;

	monster1.loadFromFile("./resources/image/sprites/running_man.png");
	platform1.loadFromFile("./resources/image/platforms/platform1.png");
	platform2.loadFromFile("./resources/image/platforms/platform2.png");
	platform3.loadFromFile("./resources/image/platforms/platform3.png");

	std::map<std::string, sf::Texture> textures{
		{"monster1", monster1},
		{"platform1", platform1},
		{"platform2", platform2},
		{"platform3", platform3},
	};

	return textures;
}
