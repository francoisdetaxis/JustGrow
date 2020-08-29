#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <iostream>
#include "Stage.h"
#include "Mytexture.h"

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
	Monster::Monster(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::SoundBuffer>& sounds, std::map<std::string, sf::Font>& fonts);

	//getters and setters
	void Monster::setPosition(int x, int y);
	const sf::Vector2f Monster::getPosition() { return _currentMonsterSprite.getPosition(); }
	int Monster::getMonsterWidth() { return _currentMonsterSpriteWidth * _currentMonsterSprite.getScale().x; }
	int Monster::getMonsterHeight() { return _currentMonsterSpriteHeight * _currentMonsterSprite.getScale().y; }
	void Monster::setHp(int hp);
	int Monster::getHp() { return _currentHp; }
	void Monster::takeDmg(int dmgTaken);

	//other methods
	void Monster::updateHitboxBordersShape();
	void Monster::setHpTextPosition();
	void Monster::nextFrame(Stage& stage);
	void Monster::setHpBarPosition();
	void Monster::updateHitbox();
	void Monster::setScale(float x, float y);
	void Monster::draw(sf::RenderWindow& window, bool debug = false);
	bool Monster::isHit(sf::RenderWindow& window) { return _currentMonsterHitboxRect.contains(sf::Mouse::getPosition(window)); }
	void Monster::playHitSound();
	void Monster::nextMob();
	void Monster::die();
	void Monster::hurt();
	void Monster::idle();

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
	Monster::State _state;

	//SOUNDS
	sf::SoundBuffer _hitSoundBuffer;
	sf::SoundBuffer _hit1Buffer;
	sf::SoundBuffer _hit2Buffer;
	sf::SoundBuffer _hit3Buffer;
	sf::Sound _hitSound;
	int _currentHitSound;

	//DEBUG
	sf::RectangleShape _hitboxBordersShape;
};
