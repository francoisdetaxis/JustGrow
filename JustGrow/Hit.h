#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Monster.h"
#include "BigNumber.h"

class Monster;
class Hit
{
public:
	Hit(int dmg, bool isCrit, sf::Font& dmgFont, Monster& monster);
	Hit(BigNumber& dmg, bool isCrit, sf::Font& dmgFont, Monster& monster);
	sf::Clock getDmgTextClock() { return _dmgTextClock; }
	sf::Text getDmgText() { return _dmgText; }
private:
	sf::Text _dmgText;
	sf::Clock _dmgTextClock;
	sf::Clock _dmgSpriteClock;
	sf::Sprite _dmgSprite;
};
