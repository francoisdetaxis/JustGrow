#include "main.h"

Player::Player(std::map<std::string, Mytexture> textures, std::map<std::string, sf::Font> fonts)
{
	a_textures = textures;
	a_fonts = fonts;

	//initialize crit chance (%)
	a_critChance = 5;
	a_critMultiplier = 2;

	//dmg display font
	a_dmgFont = fonts["dmgFont"];

	//prepare cursor textures and sprites
	//a_attackCursorTexture = findMyTexture(textures, "attackCursor").getTexture();
	a_attackCursorTexture = textures["attackCursor"].getTexture();
	//a_handCursorTexture = findMyTexture(textures, "handCursor").getTexture();
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
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uniCrit(0, 100); // guaranteed unbiased

	//create Text, set font, size, color...
	sf::Text dmgText;
	dmgText.setFont(a_dmgFont);

	int random_crit = uniCrit(rng);

	if (random_crit <= a_critChance)
	{
		//crit occurs
		monster->takeDmg(a_critMultiplier * a_dmg);
		//monster->setHp(monster->getHp() - (a_critMultiplier * a_dmg));
		dmgText.setString(std::to_string(a_critMultiplier * a_dmg));
		dmgText.setCharacterSize(96);
		dmgText.setFillColor(sf::Color::Red);
		dmgText.setOutlineColor(sf::Color::Black);
	}
	else {
		//normal hit
		//change monster hp
		monster->takeDmg(a_dmg);
		//monster->setHp(monster->getHp() - a_dmg);
		dmgText.setString(std::to_string(a_dmg));
		dmgText.setCharacterSize(48);
		dmgText.setFillColor(sf::Color::Yellow);
		dmgText.setOutlineColor(sf::Color::Black);
	}
	
	//SET RANDOM POSITION FOR DMG TEXT
	//generate random x, y coords near monster and set dmg text position
	int x, y, offsetX, offsetY;
	offsetX = monster->getMonsterFrameWidth() / 4;
	offsetY = monster->getMonsterFrameHeight() / 4;
	x = monster->getPosition().x;
	y = monster->getPosition().y;

	std::uniform_int_distribution<int> uniX(x + offsetX, x + monster->getMonsterFrameWidth() - offsetX); // guaranteed unbiased
	int random_x = uniX(rng);
	std::uniform_int_distribution<int> uniY(y + offsetY, y + monster->getMonsterFrameHeight() - offsetY); // guaranteed unbiased
	int random_y = uniY(rng);
	dmgText.setPosition(random_x, random_y);

	//add to Text dmg queue	
	a_dmgTexts.push_back(dmgText);

	//create clock and add it to the clock queue
	sf::Clock dmgClock;
	a_dmgClocks.push_back(dmgClock);
}

void Player::drawDmg(sf::RenderWindow* window)
{
	sf::Vector2f currentPos;
	

	for (int i = 0; i < a_dmgTexts.size(); i++) {
		if (a_dmgClocks[i].getElapsedTime().asSeconds() <= 3)
		{
			currentPos = a_dmgTexts[i].getPosition();
			a_dmgTexts[i].setPosition(currentPos.x, currentPos.y - 1);
			window->draw(a_dmgTexts[i]);
		}
		else {
			a_dmgClocks.pop_front();
			a_dmgTexts.pop_front();
		}
	}
}
