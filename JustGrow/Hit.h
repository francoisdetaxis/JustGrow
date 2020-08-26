#pragma once
#include "Monster.h"

class Hit
{
public:
	Hit(int dmg, bool isCrit, sf::Font dmgFont, Monster* monster);
	//TODO make these private, make getters and setters etc...
	sf::Clock getDmgTextClock() { return _dmgTextClock; }
	sf::Text getDmgText() { return _dmgText; }
	//sf::Font _dmgFont;
private:
	sf::Text _dmgText;
	sf::Clock _dmgTextClock;
	sf::Clock _dmgSpriteClock;
	sf::Sprite _dmgSprite;
};
