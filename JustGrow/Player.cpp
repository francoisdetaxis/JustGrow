#include "main.h"

Player::Player(std::map<std::string, Mytexture> textures)
{
	a_textures = textures;

	//prepare cursor textures and sprites
	a_attackCursorTexture = textures["attackCursor"].getTexture();
	a_handCursorTexture = textures["handCursor"].getTexture();
	a_attackCursorSprite.setTexture(a_attackCursorTexture);
	a_handCursorSprite.setTexture(a_handCursorTexture);

	//initialize player damage
	//TODO load player dmg from save
	a_dmg = 1;
}

void Player::drawCursor(sf::RenderWindow* window, Monster* monster)
{
	if (monster->isHit(window))
	{
		//draw sword cursor
		a_attackCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
		window->draw(a_attackCursorSprite);
	}
	else {
		//draw hand cursor
		a_handCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
		window->draw(a_handCursorSprite);

	}
	
}

void Player::dealDmg(Monster* monster)
{
	//TODO display dmg dealt to monster
	monster->setHp(monster->getHp() - a_dmg);
}
