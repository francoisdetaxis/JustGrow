#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include "Monster.h"
#include "Player.h"
#include "Mytexture.h"
#include "Hit.h"

class Player
{
public:
	Player::Player(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void drawCursor(sf::RenderWindow& window, Monster& monster);
	void dealDmg(Monster& monster);
	void drawDmg(sf::RenderWindow& window);

private:
	std::map<std::string, Mytexture> _textures;
	std::map<std::string, sf::Font> _fonts;

	Mytexture _attackCursor;
	Mytexture _handCursor;

	sf::Sprite _attackCursorSprite;
	sf::Sprite _handCursorSprite;
	sf::Font _dmgFont;
	std::deque<Hit> _hits;

	int _dmg;
	int _critChance;
	int _critMultiplier;
};
