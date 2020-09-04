#include "Player.h"

Player::Player(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)
{
	//TODO will have to load these from save...
	_goldMultiplier = 1;
	_clickLvl = 1;
	_heroMult = 1;
	_globalMult = 1;

	this->updateClickCost();

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
	_clickDmg = 1;
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
		dmgTaken = _critMultiplier * _clickDmg;
	}
	else {
		//normal hit
		crit = false;
		dmgTaken = _clickDmg;
	}

	monster.takeDmg(dmgTaken);

	//TODO verify there's no memory leak...
	Hit* hit;
	hit = new Hit(dmgTaken, crit, _dmgFont, monster);

	//add hit to queue
	_hits.push_back(hit);
}

void Player::cheat(Monster& monster)
{
	//TODO verify there's no memory leak...
	monster.takeDmg(999);
	Hit* hit;
	hit = new Hit(999, true, _dmgFont, monster);
	//add hit to queue
	_hits.push_back(hit);
}

void Player::drawDmg(sf::RenderWindow& window)
{
	for (int i = 0; i < _hits.size(); i++) {
		if (_hits[i]->getDmgTextClock().getElapsedTime().asSeconds() <= 3)
		{
			window.draw(_hits[i]->getDmgText());
		}
		else {
			_hits.pop_front();
		}
	}
}

void Player::clickUpgrade(Gold& gold, Button& upgradeBtn)
{
	if (gold.spend(_clickUpgradeCost))
	{
		_clickLvl++;
		this->updateClickDmg();
		this->updateClickCost();
		upgradeBtn.setTextString("LVL UP\n" + std::to_string((int)_clickUpgradeCost));
		upgradeBtn.setTooltipString("DMG: " + std::to_string(_clickDmg));
	}
}

void Player::updateClickCost()
{
	if (_clickLvl <= 15)
	{
		_clickUpgradeCost = std::floor(((double)_clickLvl + 5.0) * std::pow(1.07, _clickLvl - 1.0));
	}
	else
	{
		_clickUpgradeCost = std::floor(20 * std::pow(1.07, _clickLvl - 1.0));
	}
}

void Player::updateClickDmg()
{
	_clickDmg = 1 + _globalMult * _clickLvl;
}

void Player::updateHeroesMult()
{
	//TODO not applied to click, heroes ONLY
	//TODO TEST this function
	//×4 Multiplier for each 25 Hero Levels, starting from level 200; at Hero Level 1000, 2000, ..., 8000 the multiplier is ×10.
	if (_clickLvl < 200)
	{
		_heroMult = 1;
	}
	else if (_clickLvl > 200)
	{
		_heroMult = _clickLvl * 4 / 25;
	}
	else if (_clickLvl > 1000)
	{
		_heroMult += _clickLvl * 10 / 1000;
	}
}