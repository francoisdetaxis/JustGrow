#include "main.h"

std::map<std::string, sf::Font> loadFonts()
{
	//HP font
	sf::Font hpFont;
	hpFont.loadFromFile("./resources/fonts/TitilliumWeb-Black.ttf");

	std::map<std::string, sf::Font> fonts{
		{"hpFont", hpFont},
	};

	return fonts;
}
