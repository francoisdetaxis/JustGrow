#include "main.h"

Player::Player(std::map<std::string, Mytexture>* textures, std::map<std::string, sf::Font>* fonts)
{
	_textures = textures;
	_fonts = fonts;

	//initialize crit chance (%)
	_critChance = 5;
	_critMultiplier = 2;

	//dmg display font
	_dmgFont = (*fonts)["dmgFont"];

	//prepare cursor textures and sprites
	_attackCursor = (*textures)["attackCursor"];
	_handCursor = (*textures)["handCursor"];

	_attackCursorSprite.setTexture(*_attackCursor.getTexture());
	_handCursorSprite.setTexture(*_handCursor.getTexture());

	//initialize player damage
	_dmg = 1;
}

void Player::drawCursor(sf::RenderWindow* window, Monster* monster)
{
	if (monster->isHit(window))
	{
		//draw sword cursor
		_attackCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
		window->draw(_attackCursorSprite);
	}
	else {
		//draw hand cursor
		_handCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
		window->draw(_handCursorSprite);
	}
}

void Player::dealDmg(Monster* monster)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uniCrit(0, 100); // guaranteed unbiased

	//create Text, set font, size, color...
	sf::Text dmgText;
	dmgText.setFont(_dmgFont);

	int random_crit = uniCrit(rng);

	if (random_crit <= _critChance)
	{
		//crit occurs
		monster->takeDmg(_critMultiplier * _dmg);
		dmgText.setString(std::to_string(_critMultiplier * _dmg));
		dmgText.setCharacterSize(96);
		dmgText.setFillColor(sf::Color::Red);
		dmgText.setOutlineColor(sf::Color::Black);
	}
	else {
		//normal hit
		//change monster hp
		monster->takeDmg(_dmg);
		dmgText.setString(std::to_string(_dmg));
		dmgText.setCharacterSize(48);
		dmgText.setFillColor(sf::Color::Yellow);
		dmgText.setOutlineColor(sf::Color::Black);
	}

	//SET RANDOM POSITION FOR DMG TEXT
	//generate random x, y coords near monster and set dmg text position
	int x, y, offsetX, offsetY;
	offsetX = monster->getMonsterWidth() / 4;
	offsetY = monster->getMonsterHeight() / 4;
	x = monster->getPosition().x;
	y = monster->getPosition().y;

	std::uniform_int_distribution<int> uniX(x + offsetX, x + monster->getMonsterWidth() - offsetX); // guaranteed unbiased
	int random_x = uniX(rng);
	std::uniform_int_distribution<int> uniY(y + offsetY, y + monster->getMonsterHeight() - offsetY); // guaranteed unbiased
	int random_y = uniY(rng);
	dmgText.setPosition(random_x, random_y);

	//add to Text dmg queue
	_dmgTexts.push_back(dmgText);

	//create clock and add it to the clock queue
	sf::Clock dmgClock;
	_dmgClocks.push_back(dmgClock);
}

void Player::drawDmg(sf::RenderWindow* window)
{
	sf::Vector2f currentPos;

	for (int i = 0; i < _dmgTexts.size(); i++) {
		if (_dmgClocks[i].getElapsedTime().asSeconds() <= 3)
		{
			//TODO give cool animation to dmg text
			//utter shit below:
			/*if (_dmgClocks[i].getElapsedTime().asMilliseconds() % 50 == 0)
			{
				if (_dmgClocks[i].getElapsedTime().asMilliseconds() >= 1500)
					_dmgTexts[i].setCharacterSize(96);
				int transparency = _dmgTexts[i].getColor().a;
				int r = _dmgTexts[i].getColor().r;
				int g = _dmgTexts[i].getColor().g;
				int b = _dmgTexts[i].getColor().b;
				transparency = transparency - 3;
				if (transparency < 0)
					transparency = 0;
				_dmgTexts[i].setColor(sf::Color(r, g, b, transparency));
				_dmgTexts[i].move(0, -4);
			}*/

			window->draw(_dmgTexts[i]);
		}
		else {
			_dmgClocks.pop_front();
			_dmgTexts.pop_front();
		}
	}
}