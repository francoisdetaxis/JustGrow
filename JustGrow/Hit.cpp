#include "Hit.h"

Hit::Hit(int dmg, bool isCrit, sf::Font& dmgFont, Monster& monster)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

	_dmgText.setFont(dmgFont);

	if (isCrit)
	{
		_dmgText.setString(std::to_string(dmg));
		_dmgText.setCharacterSize(96);
		_dmgText.setFillColor(sf::Color::Red);
		_dmgText.setOutlineColor(sf::Color::Black);
	}
	else
	{
		_dmgText.setString(std::to_string(dmg));
		_dmgText.setCharacterSize(48);
		_dmgText.setFillColor(sf::Color::Yellow);
		_dmgText.setOutlineColor(sf::Color::Black);
	}

	//SET RANDOM POSITION FOR DMG TEXT
	//generate random x, y coords near monster and set dmg text position
	int x, y, offsetX, offsetY;
	offsetX = monster.getMonsterWidth() / 4;
	offsetY = monster.getMonsterHeight() / 4;
	x = monster.getPosition().x;
	y = monster.getPosition().y;

	std::uniform_int_distribution<int> uniX(x + offsetX, x + monster.getMonsterWidth() - offsetX); // guaranteed unbiased
	int random_x = uniX(rng);
	std::uniform_int_distribution<int> uniY(y + offsetY, y + monster.getMonsterHeight() - offsetY); // guaranteed unbiased
	int random_y = uniY(rng);
	_dmgText.setPosition(random_x, random_y);
}