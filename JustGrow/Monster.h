#pragma once
#include "main.h"

class Monster
{
public:

	//constructors
	Monster::Monster(std::map<std::string, sf::Texture> textures, std::map<std::string, sf::SoundBuffer> sounds);

	//getters and setters
	void Monster::setPosition(int x, int y);
	int Monster::getFrameSize();

	//other methods
	void Monster::draw(sf::RenderWindow* window);
	void Monster::nextFrame();
	bool Monster::isHit(sf::RenderWindow* window);
	void Monster::playSound();
	void Monster::nextMob();
	void Monster::nextPlatform();
	void Monster::dealDmg();

private:

	//attributes
	std::map<std::string, sf::Texture> a_textures;
	std::map<std::string, sf::SoundBuffer> a_sounds;
	sf::Clock a_clock;
	sf::Texture a_monsterTexture;
	sf::Texture a_backgroundTexture;
	sf::Sprite a_monsterSprite;
	sf::Sprite a_backgroundSprite;
	sf::IntRect a_monsterRect;
	sf::IntRect a_monsterHitbox;
	sf::SoundBuffer a_soundBuffer;
	sf::Sound a_hitSound;
	int a_frameSize;
	int a_maxLeft;
	sf::RectangleShape a_hitboxBorders;
	int a_framesTotal;
};
