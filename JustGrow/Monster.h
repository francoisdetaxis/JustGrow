#pragma once
#include "Mytexture.h"

class Monster
{
public:

	//constructors
	Monster(std::map<std::string, Mytexture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts);

	//getters and setters
	void setPosition(int x, int y);
	int getFrameWidth();
	void setHp(int hp);
	int getHp();

	//other methods
	void Monster::draw(sf::RenderWindow* window);
	void Monster::nextFrame();
	bool Monster::isHit(sf::RenderWindow* window);
	void Monster::playSound();
	void Monster::nextMob();
	void Monster::nextPlatform();

private:

	//attributes
	std::map<std::string, Mytexture> a_textures;
	std::map<std::string, sf::SoundBuffer> a_sounds;
	std::map<std::string, sf::Font> a_fonts;
	sf::Font a_hpFont;
	sf::Clock a_clock;
	sf::Texture a_monsterTexture;
	sf::Texture a_hpBarFullTexture;
	sf::Texture a_hpBarEmptyTexture;
	sf::Texture a_backgroundTexture;
	sf::Sprite a_monsterSprite;
	sf::Sprite a_backgroundSprite;
	sf::Sprite a_hpBarFullSprite;
	sf::Sprite a_hpBarEmptySprite;
	sf::IntRect a_monsterRect;
	sf::IntRect a_hpRect;
	sf::IntRect a_monsterHitbox;
	sf::SoundBuffer a_soundBuffer;
	sf::Sound a_hitSound;
	sf::Text a_hpText;
	int a_monsterSpriteWidth;
	int a_monsterSpriteHeight;
	int a_currentHp;
	int a_maxHp;
	int a_maxLeft;
	int a_hpFrameWidth;
	sf::RectangleShape a_hitboxBorders;
	int a_framesTotal;
};
