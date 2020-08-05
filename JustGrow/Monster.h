#pragma once
#include "main.h"

class Monster
{
public:
	//constructors
	Monster();
	//getters and setters
	void Monster::setRect(sf::IntRect rect);
	sf::IntRect Monster::getRect();
	void Monster::resetRect();
	sf::Sprite Monster::getSprite();
	void Monster::nextFrame();
	int Monster::getMaxLeft();
	int Monster::getClockTime();
	void Monster::restartclock();
	bool Monster::isHit(sf::RenderWindow* window);
	void Monster::playSound();
	void Monster::setPosition(int x, int y);
	sf::RectangleShape Monster::getHitboxShape();
	int Monster::getFrameSize();


	//attributes
	sf::Clock a_clock;
	sf::Texture a_monsterTexture;
	sf::Sprite a_monsterSprite;
	sf::IntRect a_monsterRect;
	sf::IntRect a_monsterHitbox;
	sf::SoundBuffer a_soundBuffer;
	sf::Sound a_hitSound;
	int a_frameSize;
	int a_maxLeft;
	sf::RectangleShape a_hitboxBorders;
};

