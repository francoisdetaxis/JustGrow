#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>
#include "Monster.h"
#include "Mytexture.h"
#include "Gold.h"
#include "Player.h"

class Monster;
class Player;
class Stage
{
public:
	Stage::Stage(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void nextLevel(Monster& monster, Gold& gold, Player& player);
	void nextStage(Monster& monster, Gold& gold, Player& player);
	bool isBoss();
	void decreaseBossTimer(Monster& monster);
	void Stage::updateTextsPosition(Monster& monster);
	void updateSkullPosition(Monster& monster);
	void updateTimerSpritePosition();
	void updateTimerTextPosition();
	int Stage::getStage() { return _currentStage; }
	int Stage::getLevel() { return _currentLevel; }
	sf::Vector2u Stage::getSize() { return _currentPlatform.getTexture().getSize(); }
	void Stage::draw(sf::RenderWindow& window, Monster& monster, bool debug = false);
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

	float _bossTimeSeconds;

	sf::Text _stageText; //infinite
	sf::Text _levelText; //1 to 10
	sf::Text _timerText;

	sf::Sprite _skullSprite;
	sf::Sprite _timerSprite;

	sf::Clock _bossTimer;

	sf::IntRect _currentRect;
	Mytexture _currentPlatform;
	sf::Sprite _currentPlatformSprite;
	sf::RectangleShape _debugShape;
};