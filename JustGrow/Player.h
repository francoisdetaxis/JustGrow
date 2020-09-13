#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>
#include "Hit.h"
#include "Monster.h"
#include "Player.h"
#include "Mytexture.h"
#include "Button.h"
#include "BigNumber.h"

class Gold;
class Monster;
class Hit;
class Player
{
public:
	Player(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void drawCursor(sf::RenderWindow& window, Monster& monster);
	void drawCursor(sf::RenderWindow& window);
	void dealDmg(Monster& monster);
	void cheat(Monster& monster);
	void drawDmg(sf::RenderWindow& window);
	//int getGoldMultiplier() { return _goldMultiplier; }
	BigNumber getGoldMultiplier() { return _goldMultiplier; }
	void clickUpgrade(Gold& gold, Button& upgradeBtn);
	//int getClickDmg() { return _clickDmg; }
	BigNumber getClickDmg() { return _clickDmg; }
	void reloadUpgrades(Button& upgradeBtn);
	void updateClickCost();
	//int getClickCost() { return _clickUpgradeCost; }
	BigNumber getClickCost() { return _clickUpgradeCost; }
	void updateClickDmg();
	void updateHeroesMult();
	int getClickLvl() { return _clickLvl; }

	//public because easier to save game...
	//int _clickDmg;
	BigNumber _clickDmg;
	//int _globalMult;
	BigNumber _globalMult;
	//int _heroMult;
	BigNumber _heroMult;
	int _critChance;
	//int _critMultiplier;
	BigNumber _critMultiplier;
	//int _goldMultiplier;
	BigNumber _goldMultiplier;
	int _clickLvl;
	//double _clickUpgradeCost;
	BigNumber _clickUpgradeCost;

private:
	std::map<std::string, Mytexture> _textures;
	std::map<std::string, sf::Font> _fonts;

	Mytexture _attackCursor;
	Mytexture _handCursor;

	sf::Sprite _attackCursorSprite;
	sf::Sprite _handCursorSprite;
	sf::Font _dmgFont;
	std::deque<Hit*> _hits;
};
