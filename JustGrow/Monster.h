#pragma once
#include "Mytexture.h"

class Monster
{
public:
	//constructors
	Monster(std::map<std::string, Mytexture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts);

	//getters and setters
	void setPosition(int x, int y);
	int getMonsterFrameWidth();
	int getMonsterFrameHeight();
	void setHp(int hp);
	void takeDmg(int dmgTaken);
	int getHp();
	const sf::Vector2f getPosition();

	//other methods
	void draw(sf::RenderWindow* window);
	void nextFrame();
	bool isHit(sf::RenderWindow* window);
	void playSound();
	void nextMob();
	void nextPlatform();
	void die();
	void hurt();
	void idle();

private:
	//all textures, sounds and fonts
	std::map<std::string, Mytexture> a_textures;
	std::map<std::string, sf::SoundBuffer> a_sounds;
	std::map<std::string, sf::Font> a_fonts;

	//HP
	sf::Font a_hpFont;
	sf::Texture a_hpBarFullTexture;
	sf::Texture a_hpBarEmptyTexture;	
	sf::Sprite a_hpBarFullSprite;
	sf::Sprite a_hpBarEmptySprite;
	sf::IntRect a_hpRect;
	sf::Text a_hpText;
	int a_currentHp;
	int a_maxHp;
	int a_hpFrameWidth;

	//PLATFORM
	sf::Sprite a_backgroundSprite;
	sf::Texture a_backgroundTexture;

	//MONSTER
	sf::Texture a_currentMonsterIdleTexture;
	sf::Texture a_currentMonsterHurtTexture;
	sf::Texture a_currentMonsterDyingTexture;
	Mytexture a_currentMonsterIdle;
	Mytexture a_currentMonsterHurt;
	Mytexture a_currentMonsterDying;
	sf::Sprite a_currentMonsterSprite;
	sf::IntRect a_currentMonsterSpriteRect;
	sf::IntRect a_currentMonsterHitboxRect;
	int a_currentMonsterSpriteWidth;
	int a_currentMonsterSpriteHeight;
	int a_currentMonsterSpriteMaxWidth;
	int a_currentMonsterSpriteFramesNb;
	int a_currentMonsterNb;
	sf::Clock a_clock;
	//TODO switch these bools to an enum 'monsterState'...?
	bool a_isDead;
	bool a_isHurt;

	//SOUNDS
	sf::SoundBuffer a_hitSoundBuffer;
	sf::SoundBuffer a_hit1Buffer;
	sf::SoundBuffer a_hit2Buffer;
	sf::SoundBuffer a_hit3Buffer;
	sf::Sound a_hitSound;
	int a_currentHitSound;

	//DEBUG
	sf::RectangleShape a_hitboxBordersShape;
};
