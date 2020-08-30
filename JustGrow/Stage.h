#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <map>
#include "Monster.h"
#include "Mytexture.h"
#include "Gold.h"

class Monster;
class Stage
{
public:
	Stage::Stage(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void nextLevel(Monster& monster, Gold& gold);
	void nextStage(Monster& monster, Gold& gold);
	void Stage::updateTextsPosition(Monster& monster);
	int Stage::getStage() { return _currentStage; }
	int Stage::getLevel() { return _currentLevel; }
	sf::Vector2u Stage::getSize() { return _currentPlatform.getTexture().getSize(); }
	void Stage::draw(sf::RenderWindow& window, bool debug = false);
	void Stage::setPosition(int x, int y, Monster& monster);
	void Stage::nextPlatform(Monster& monster);
	void Stage::updateTextureRect();
	void Stage::updateDebugShape();

private:
	std::map<std::string, Mytexture> _textures;
	std::map<std::string, sf::Font> _fonts;

	int _currentStage;
	int _currentLevel;
	int _currentPlatformNb;

	sf::Text _stageText; //infinite
	sf::Text _levelText; //1 to 10

	sf::IntRect _currentRect;
	Mytexture _currentPlatform;
	sf::Sprite _currentPlatformSprite;
	sf::RectangleShape _debugShape;
};