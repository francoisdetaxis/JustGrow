#include "main.h"

std::map<std::string, sf::Font> loadFonts()
{
	//HP font
	sf::Font hpFont;
	sf::Font dmgFont;
	hpFont.loadFromFile("./resources/fonts/TitilliumWeb-Black.ttf");
	dmgFont.loadFromFile("./resources/fonts/OpenSans-ExtraBoldItalic.ttf");

	std::map<std::string, sf::Font> fonts{
		{"hpFont", hpFont},
		{"dmgFont", dmgFont},
	};
	return fonts;
}
