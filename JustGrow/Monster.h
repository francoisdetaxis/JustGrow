#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Stage.h"
#include "Mytexture.h"
#include "Gold.h"

class Stage;
class Monster
{
public:
	enum class State
	{
		HURT,
		IDLE,
		DEAD
	};

	//constructors
	Monster(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::SoundBuffer>& sounds, std::map<std::string, sf::Font>& fonts);

	//getters and setters
	void setPosition(int x, int y);
	const sf::Vector2f getPosition() { return _currentMonsterSprite.getPosition(); }
	int getMonsterWidth() { return _currentMonsterSpriteWidth * _currentMonsterSprite.getScale().x; }
	int getMonsterHeight() { return _currentMonsterSpriteHeight * _currentMonsterSprite.getScale().y; }
	void setHp(int hp);
	int getHp() { return _currentHp; }
	int getMaxHp() { return _maxHp; }
	void takeDmg(int dmgTaken);

	//other methods
	void updateHitboxBordersShape();
	void setHpTextPosition();
	void nextFrame(Stage& stage, Gold& gold, Player& player);
	void setHpBarPosition();
	void updateHitbox();
	void setScale(float x, float y);
	void increaseMaxHp(Stage& stage);
	void draw(sf::RenderWindow& window, bool debug = false);
	bool isHit(sf::RenderWindow& window) { return _currentMonsterHitboxRect.contains(sf::Mouse::getPosition(window)); }
	void playHitSound();
	void nextMob();
	void die();
	void playDyingSound();
	void hurt();
	void idle();

private:
	//animation speed
	int _fps;

	//all textures, sounds and fonts
	std::map<std::string, Mytexture> _textures;
	std::map<std::string, sf::SoundBuffer> _sounds;
	std::map<std::string, sf::Font> _fonts;

	//HP
	sf::Font _hpFont;
	sf::Texture _hpBarFullTexture;
	sf::Texture _hpBarEmptyTexture;
	sf::Sprite _hpBarFullSprite;
	sf::Sprite _hpBarEmptySprite;
	sf::IntRect _hpRect;
	sf::Text _hpText;
	int _currentHp;
	int _maxHp;
	int _hpFrameWidth;

	//MONSTER
	Mytexture _currentMonsterIdle;
	Mytexture _currentMonsterHurt;
	Mytexture _currentMonsterDying;
	sf::Sprite _currentMonsterSprite;
	sf::IntRect _currentMonsterSpriteRect;
	sf::IntRect _currentMonsterHitboxRect;
	int _currentMonsterSpriteWidth;
	int _currentMonsterSpriteHeight;
	int _currentMonsterSpriteMaxWidth;
	int _currentMonsterSpriteFramesNb;
	int _currentMonsterNb;
	sf::Clock _monsterAnimationClock;
	State _state;

	//SOUNDS
	sf::SoundBuffer _hitSoundBuffer;
	sf::SoundBuffer _hit1Buffer;
	sf::SoundBuffer _hit2Buffer;
	sf::SoundBuffer _hit3Buffer;
	sf::Sound _hitSound;
	sf::Sound _currentDyingSound;
	int _currentHitSound;

	//DEBUG
	sf::RectangleShape _hitboxBordersShape;
};
