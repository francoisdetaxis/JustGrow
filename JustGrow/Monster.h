#pragma once
#include "main.h"

class Monster
{
public:

	//constructors
	Monster::Monster(std::string monsterPath, std::string monsterHitSoundPath, int frames);

	//getters and setters
	void Monster::setRect(sf::IntRect rect);
	sf::Sprite Monster::getSprite();
	void Monster::setPosition(int x, int y);
	sf::RectangleShape Monster::getHitboxShape();
	int Monster::getFrameSize();

	//other methods
	void Monster::nextFrame();
	bool Monster::isHit(sf::RenderWindow* window);
	void Monster::playSound();

private:

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
	int a_framesTotal;
};

