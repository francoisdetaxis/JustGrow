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

class Gold;
class Monster;
class Hit;
class Player
{
public:
	Player::Player(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void drawCursor(sf::RenderWindow& window, Monster& monster);
	void dealDmg(Monster& monster);
	void cheat(Monster& monster);
	void drawDmg(sf::RenderWindow& window);
	int getGoldMultiplier() { return _goldMultiplier; }
	void clickUpgrade(Gold& gold);
	void updateClickCost();
	void updateClickDmg();
	void updateClickMult();
	int getClickLvl() { return _clickLvl; }

private:
	std::map<std::string, Mytexture> _textures;
	std::map<std::string, sf::Font> _fonts;

	Mytexture _attackCursor;
	Mytexture _handCursor;

	sf::Sprite _attackCursorSprite;
	sf::Sprite _handCursorSprite;
	sf::Font _dmgFont;
	std::deque<Hit*> _hits;

	int _clickDmg;
	int _clickMult;
	int _critChance;
	int _critMultiplier;
	int _goldMultiplier;
	int _clickLvl;
	double _clickUpgradeCost;
};
