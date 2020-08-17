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
	void setPostion(int x, int y) { _currentPlatformSprite.setPosition(x, y); }
	void draw(sf::RenderWindow* window) { window->draw(_currentPlatformSprite); }
private:
	int _currentStage;
	int _currentLevel;
	Mytexture _currentPlatform;
	sf::Sprite _currentPlatformSprite;
	std::map<std::string, Mytexture>* _textures;
};
