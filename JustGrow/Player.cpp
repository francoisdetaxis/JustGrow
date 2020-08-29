#include "main.h"

Player::Player(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)

{
	_textures = textures;
	_fonts = fonts;

	_dmgFont = _fonts["dmgFont"];

	//initialize crit chance (%)
	_critChance = 5;
	_critMultiplier = 2;

	//prepare cursor textures and sprites
	_attackCursor = textures["attackCursor"];
	_handCursor = textures["handCursor"];

	_attackCursorSprite.setTexture(_attackCursor.getTexture());
	_handCursorSprite.setTexture(_handCursor.getTexture());

	//initialize player damage
	_dmg = 1;
}

void Player::drawCursor(sf::RenderWindow& window, Monster& monster)
{
	if (monster.isHit(window))
	{
		//draw sword cursor
		_attackCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.draw(_attackCursorSprite);
	}
	else {
		//draw hand cursor
		_handCursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.draw(_handCursorSprite);
	}
}

void Player::dealDmg(Monster& monster)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uniCrit(0, 100); // guaranteed unbiased
	int random_crit = uniCrit(rng);
	bool crit;
	int dmgTaken;

	if (random_crit <= _critChance)
	{
		//crit occurs
		crit = true;
		dmgTaken = _critMultiplier * _dmg;
	}
	else {
		//normal hit
		crit = false;
		dmgTaken = _dmg;
	}
	monster.takeDmg(dmgTaken);
	Hit hit(dmgTaken, crit, _dmgFont, monster);

	//add hit to queue
	_hits.push_back(hit);
}

void Player::drawDmg(sf::RenderWindow& window)
{
	for (int i = 0; i < _hits.size(); i++) {
		auto time = _hits[i].getDmgTextClock().getElapsedTime().asSeconds();
		if (_hits[i].getDmgTextClock().getElapsedTime().asSeconds() <= 3)
		{
			window.draw(_hits[i].getDmgText());
		}
		else {
			_hits.pop_front();
		}
	}
}