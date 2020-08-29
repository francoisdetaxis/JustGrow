#pragma once
#include "Monster.h"

class Stage
{
public:
	Stage(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void nextLevel();

	void updateTextsPosition(Monster& monster);
	int getStage() { return _currentStage; }
	int getLevel() { return _currentLevel; }
	sf::Vector2u getSize() { return _currentPlatform.getTexture().getSize(); }
	void draw(sf::RenderWindow& window, bool debug = false);
	void setPosition(int x, int y, Monster& monster);
	void nextPlatform(Monster& monster);
	void Stage::updateTextureRect();
	void Stage::updateDebugShape();

private:
	void nextStage();

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
