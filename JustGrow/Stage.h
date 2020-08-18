#pragma once
#include "Mytexture.h"
#include "Monster.h"
#include <iostream>

class Stage
{
public:
	Stage(std::map<std::string, Mytexture>* textures);
	int getStage() { return _currentStage; }
	int getLevel() { return _currentLevel; }
	sf::Vector2u getSize() { return _currentPlatform.getTexture()->getSize(); }
	void setPosition(int x, int y);
	void draw(sf::RenderWindow* window, bool debug = false);
	void next(Monster* monster);
	void Stage::updateTextureRect();
	void Stage::updateDebugShape();
private:
	int _currentStage;
	int _currentLevel;
	int _currentPlatformNb;

	sf::IntRect _currentRect;
	Mytexture _currentPlatform;
	sf::Sprite _currentPlatformSprite;
	std::map<std::string, Mytexture>* _textures;
	sf::RectangleShape _debugShape;
};
