#include "main.h"

Player::Player(std::map<std::string, Mytexture> textures, std::map<std::string, sf::Font> fonts)
{
	a_textures = textures;
	a_fonts = fonts;

	//dmg display font
	a_dmgFont = fonts["dmgFont"];
	a_dmgText.setFont(a_dmgFont);
	a_dmgText.setCharacterSize(24);
	a_dmgText.setFillColor(sf::Color::White);
	
	
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
	//change monster hp
	monster->setHp(monster->getHp() - a_dmg);

	//display dmg dealt
	a_dmgText.setString(std::to_string(a_dmg));
	a_dmgClock.restart();

	//generate random x, y coords near monster and set dmg text position
	int x, y;
	x = monster->getPosition().x;
	y = monster->getPosition().y;


	//std::random_device rd;     // only used once to initialise (seed) engine
	//std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	//std::uniform_int_distribution<int> uni(x, max); // guaranteed unbiased
	//auto random_integer = uni(rng);
	//a_dmgText.setPosition(x, y);
	
}

void Player::drawDmg(sf::RenderWindow* window)
{
	if (a_dmgClock.getElapsedTime().asSeconds() <= 3)
	{
		window->draw(a_dmgText);
	}
}
