#include "main.h"

Monster::Monster(std::map<std::string, Mytexture>* textures, std::map<std::string, sf::SoundBuffer>* sounds, std::map<std::string, sf::Font>* fonts)
{
	_textures = textures;
	_sounds = sounds;
	_fonts = fonts;

	_fps = 50;

	//initial monster hp
	_maxHp = 10;
	_currentHp = 10;

	//initial booleans
	_state = Monster::State::IDLE;

	//INITIALIZE MONSTER
	_currentMonsterNb = 1;
	_currentMonsterIdle = (*textures)["monster1_idle"];
	_currentMonsterHurt = (*textures)["monster1_hurt"];
	_currentMonsterDying = (*textures)["monster1_dying"];
	//total number of frames
	_currentMonsterSpriteFramesNb = _currentMonsterIdle.getFramesNb();
	//set current monster texture
	_currentMonsterSprite.setTexture(*_currentMonsterIdle.getTexture());
	//size of 1 frame
	_currentMonsterSpriteWidth = _currentMonsterSprite.getTextureRect().width / _currentMonsterSpriteFramesNb;
	_currentMonsterSpriteHeight = _currentMonsterSprite.getTextureRect().height;
	//max length of the monster sprite
	_currentMonsterSpriteMaxWidth = (_currentMonsterSpriteFramesNb - 1) * _currentMonsterSpriteWidth;
	//Monster rectangle
	_currentMonsterSpriteRect.left = 0;
	_currentMonsterSpriteRect.top = 0;
	_currentMonsterSpriteRect.height = _currentMonsterSpriteHeight;
	_currentMonsterSpriteRect.width = _currentMonsterSpriteWidth;

	//initial hit sound && set all buffers
	_hit1Buffer = (*sounds)["hit1"];
	_hit2Buffer = (*sounds)["hit2"];
	_hit3Buffer = (*sounds)["hit3"];
	_hitSound.setBuffer(_hit1Buffer);
	_currentHitSound = 1;

	//Monster hitbox = initial monsterRect
	this->updateHitbox();

	//hitbox borders (shape) = hitbox rect
	_hitboxBordersShape.setFillColor(sf::Color::Transparent);
	_hitboxBordersShape.setOutlineColor(sf::Color::Red);
	_hitboxBordersShape.setOutlineThickness(5.f);
	this->updateHitboxBordersShape();

	//HP TEXT
	_hpFont = (*fonts)["hpFont"];
	_hpText.setFont(_hpFont);
	_hpText.setString(std::to_string(_currentHp) + " HP");
	_hpText.setColor(sf::Color::Red);

	//HP BAR
	_hpBarEmptyTexture = *(*textures)["hpBarEmpty"].getTexture();
	_hpBarFullTexture = *(*textures)["hpBarFull"].getTexture();
	_hpFrameWidth = _hpBarFullTexture.getSize().x;
	_hpRect.height = _hpBarFullTexture.getSize().y;
	_hpRect.width = _hpBarFullTexture.getSize().x;
	_hpBarEmptySprite.setTexture(_hpBarEmptyTexture);
	_hpBarFullSprite.setTexture(_hpBarFullTexture);
	_hpBarFullSprite.setTextureRect(_hpRect);
}

void Monster::setPosition(int x, int y)
{
	float centeredX, centeredY, offsetY, offsetX;

	//setPosition monster
	_currentMonsterSprite.setPosition(x, y);

	//set HP bar position
	this->setHpBarPosition();

	//setPosition HP Text
	this->setHpTextPosition();

	//TODO WTF ? why does this work without setting top and left for hpRect ?
	//a_hpRect.top = y + a_frameSize / 1.25;
	//a_hpRect.left = x + a_frameSize / 5;

	//hitbox rect = monster rect initial position
	this->updateHitbox();

	//hitbox borders (shape) = hitbox rect
	_hitboxBordersShape.setPosition(_currentMonsterSprite.getPosition().x, _currentMonsterSprite.getPosition().y);
	_hitboxBordersShape.setSize(sf::Vector2f(_currentMonsterHitboxRect.width, _currentMonsterHitboxRect.height));
}

void Monster::setScale(float x, float y)
{
	_currentMonsterSprite.setScale(x, y);
}

void Monster::updateHitbox()
{
	_currentMonsterHitboxRect.left = _currentMonsterSprite.getPosition().x;
	_currentMonsterHitboxRect.top = _currentMonsterSprite.getPosition().y;
	_currentMonsterHitboxRect.height = _currentMonsterSpriteHeight * _currentMonsterSprite.getScale().y;
	_currentMonsterHitboxRect.width = _currentMonsterSpriteWidth * _currentMonsterSprite.getScale().x;
}

void Monster::updateHitboxBordersShape()
{
	_hitboxBordersShape.setPosition(_currentMonsterSprite.getPosition().x, _currentMonsterSprite.getPosition().y);
	_hitboxBordersShape.setSize(sf::Vector2f(_currentMonsterSpriteWidth, _currentMonsterSpriteHeight));
}

void Monster::setHpBarPosition()
{
	float centeredX, centeredY, offsetY, offsetX;
	//setPosition HP bar
	centeredX = _currentMonsterSprite.getPosition().x + (((float)_currentMonsterSpriteWidth * _currentMonsterSprite.getScale().x - (float)_hpBarEmptyTexture.getSize().x) / 2);
	centeredY = _currentMonsterSprite.getPosition().y + (((float)_currentMonsterSpriteHeight * _currentMonsterSprite.getScale().y - (float)_hpBarEmptyTexture.getSize().y) / 2);
	offsetY = 0.65 * _currentMonsterSpriteHeight;
	_hpBarEmptySprite.setPosition(centeredX, centeredY + offsetY);
	_hpBarFullSprite.setPosition(centeredX, centeredY + offsetY);
}

void Monster::setHpTextPosition()
{
	float centeredX, centeredY, offsetY, offsetX;

	centeredX = _currentMonsterSprite.getPosition().x + (((float)_currentMonsterSpriteWidth * _currentMonsterSprite.getScale().x - _hpText.getGlobalBounds().width) / 2);
	centeredY = _currentMonsterSprite.getPosition().y + (((float)_currentMonsterSpriteHeight * _currentMonsterSprite.getScale().y - _hpText.getGlobalBounds().height) / 2);
	offsetY = 0.55 * _currentMonsterSpriteHeight;
	_hpText.setPosition(centeredX, centeredY + offsetY);
}

void Monster::nextFrame()
{
	switch (_state) {
	case Monster::State::HURT:
		_fps = 50;
		break;
	case Monster::State::IDLE:
		_fps = 50;
		break;
	case Monster::State::DEAD:
		//TODO adapt dying animation speed with current dps of click/heroes : less dps --> slower and more dps --> faster
		_fps = 50;
		break;
	default:
		break;
	}

	//TODO end of ishurt animation and isdying animations to implement in this method
	if (_monsterAnimationClock.getElapsedTime().asMilliseconds() > _fps) {
		_monsterAnimationClock.restart();

		if (_currentMonsterSpriteRect.left >= _currentMonsterSpriteMaxWidth) {
			//end of the sprite is reached
			_currentMonsterSpriteRect.left = 0;

			switch (_state) {
			case Monster::State::HURT:
				this->idle();
				break;
			case Monster::State::IDLE:
				break;
			case Monster::State::DEAD:
				this->nextMob();
				break;
			default:
				break;
			}
		}
		else {
			//there are still frames to go on the sprite
			_currentMonsterSprite.setTextureRect(_currentMonsterSpriteRect);
			_currentMonsterSpriteRect.left += _currentMonsterSpriteWidth;
		}
	}
}

void Monster::playHitSound()
{
	//PLAY A RANDOM HIT SOUND
	//std::random_device rd;     // only used once to initialise (seed) engine
	//std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	//std::uniform_int_distribution<int> uni(1, 3); // guaranteed unbiased
	//int random = uni(rng);
	//switch (random) {
	//case 1:
	//	a_hitSound.setBuffer(a_hit1Buffer);
	//	break;
	//case 2:
	//	a_hitSound.setBuffer(a_hit2Buffer);
	//	break;
	//case 3:
	//	a_hitSound.setBuffer(a_hit3Buffer);
	//	break;
	//default:
	//	//TODO dafuq happened ?
	//	break;
	//}

	//PLAY HIT SOUNDS IN THE SAME ORDER REPEATEDLY
	switch (_currentHitSound) {
	case 1:
		_hitSound.setBuffer(_hit2Buffer);
		_currentHitSound = 2;
		break;
	case 2:
		_hitSound.setBuffer(_hit3Buffer);
		_currentHitSound = 3;
		break;
	case 3:
		_hitSound.setBuffer(_hit1Buffer);
		_currentHitSound = 1;
		break;
	}
	_hitSound.play();
}

void Monster::draw(sf::RenderWindow* window, bool debug)
{
	//debug --> show hitbox
	if (debug)
		window->draw(_hitboxBordersShape);

	//draw monster sprite
	window->draw(_currentMonsterSprite);

	//draw hp bars & Text
	window->draw(_hpBarEmptySprite);
	window->draw(_hpBarFullSprite);
	window->draw(_hpText);
}

void Monster::setHp(int hp)
{
	if (hp <= 0)
	{
		_currentHp = 0;
		_hpText.setString(std::to_string(_currentHp) + " HP");
		_hpRect.width = _currentHp * _hpFrameWidth / _maxHp;
		_hpBarFullSprite.setTextureRect(_hpRect);
	}
	else {
		_currentHp = hp;
		_hpText.setString(std::to_string(_currentHp) + " HP");
		_hpRect.width = _currentHp * _hpFrameWidth / _maxHp;
		_hpBarFullSprite.setTextureRect(_hpRect);
	}
}

void Monster::takeDmg(int dmgTaken)
{
	this->setHp(_currentHp - dmgTaken);
	if (_currentHp <= 0)
	{
		this->die();
	}
	else {
		this->hurt();
	}
}

void Monster::die()
{
	if (_state != Monster::State::DEAD)
	{
		//dying animation frames number
		_currentMonsterSpriteFramesNb = _currentMonsterDying.getFramesNb();
		//set dying texture
		_currentMonsterSprite.setTexture(*_currentMonsterDying.getTexture());
		//size of 1 frame
		_currentMonsterSpriteWidth = _currentMonsterDying.getTexture()->getSize().x / _currentMonsterSpriteFramesNb;
		_currentMonsterSpriteHeight = _currentMonsterDying.getTexture()->getSize().y;
		//max length of the monster sprite
		_currentMonsterSpriteMaxWidth = (_currentMonsterSpriteFramesNb - 1) * _currentMonsterSpriteWidth;
		//Monster rectangle
		_currentMonsterSpriteRect.left = 0;
		_currentMonsterSpriteRect.top = 0;
		_currentMonsterSpriteRect.height = _currentMonsterSpriteHeight;
		_currentMonsterSpriteRect.width = _currentMonsterSpriteWidth;

		_state = Monster::State::DEAD;
		_monsterAnimationClock.restart();
	}
	else {
	}
}

void Monster::hurt()
{
	if (_state != Monster::State::HURT)
	{
		//change to hurt monster texture
		//_currentMonsterHurtTexture = _currentMonsterHurt.getTexture();
		//hurt frames number
		_currentMonsterSpriteFramesNb = _currentMonsterHurt.getFramesNb();
		//set texture
		_currentMonsterSprite.setTexture(*_currentMonsterHurt.getTexture());
		//size of 1 frame
		_currentMonsterSpriteWidth = _currentMonsterHurt.getTexture()->getSize().x / _currentMonsterSpriteFramesNb;
		_currentMonsterSpriteHeight = _currentMonsterHurt.getTexture()->getSize().y;
		//max length of the monster sprite
		_currentMonsterSpriteMaxWidth = (_currentMonsterSpriteFramesNb - 1) * _currentMonsterSpriteWidth;
		//Monster rectangle
		_currentMonsterSpriteRect.left = 0;
		_currentMonsterSpriteRect.top = 0;
		_currentMonsterSpriteRect.height = _currentMonsterSpriteHeight;
		_currentMonsterSpriteRect.width = _currentMonsterSpriteWidth;
		_state = Monster::State::HURT;
		_monsterAnimationClock.restart();
	}
	else {
		_currentMonsterSpriteRect.left = 0;
		_monsterAnimationClock.restart();
	}
}

void Monster::idle()
{
	if (_state != Monster::State::IDLE)
	{
		//change to hurt monster texture
		//_currentMonsterIdleTexture = _currentMonsterIdle.getTexture();
		//hurt frames number
		_currentMonsterSpriteFramesNb = _currentMonsterIdle.getFramesNb();
		//set texture
		_currentMonsterSprite.setTexture(*_currentMonsterIdle.getTexture());
		//size of 1 frame
		_currentMonsterSpriteWidth = _currentMonsterIdle.getTexture()->getSize().x / _currentMonsterSpriteFramesNb;
		_currentMonsterSpriteHeight = _currentMonsterIdle.getTexture()->getSize().y;
		//max length of the monster sprite
		_currentMonsterSpriteMaxWidth = (_currentMonsterSpriteFramesNb - 1) * _currentMonsterSpriteWidth;
		//Monster rectangle
		_currentMonsterSpriteRect.left = 0;
		_currentMonsterSpriteRect.top = 0;
		_currentMonsterSpriteRect.height = _currentMonsterSpriteHeight;
		_currentMonsterSpriteRect.width = _currentMonsterSpriteWidth;

		//!!!!!!!!!!!!!!!!!!!!!!!
		_state = Monster::State::IDLE;
		_monsterAnimationClock.restart();
	}
	else {
	}
}

void Monster::nextMob()
{
	//Reset to first monster once we went through all the textures...
	if (_currentMonsterNb == 3)
		_currentMonsterNb = 0;

	_currentMonsterNb++;
	std::string nextMonster = "monster" + std::to_string(_currentMonsterNb);
	_currentMonsterIdle = (*_textures)[nextMonster + "_idle"];
	_currentMonsterHurt = (*_textures)[nextMonster + "_hurt"];
	_currentMonsterDying = (*_textures)[nextMonster + "_dying"];
	//_currentMonsterIdleTexture = _currentMonsterIdle.getTexture();
	//_currentMonsterHurtTexture = _currentMonsterHurt.getTexture();
	//_currentMonsterDyingTexture = _currentMonsterDying.getTexture();
	//dying frames number
	_currentMonsterSpriteFramesNb = _currentMonsterIdle.getFramesNb();
	//set texture
	_currentMonsterSprite.setTexture(*_currentMonsterIdle.getTexture());

	//size of 1 frame
	_currentMonsterSpriteWidth = _currentMonsterIdle.getTexture()->getSize().x / _currentMonsterSpriteFramesNb;
	_currentMonsterSpriteHeight = _currentMonsterIdle.getTexture()->getSize().y;
	//max length of the monster sprite
	_currentMonsterSpriteMaxWidth = (_currentMonsterSpriteFramesNb - 1) * _currentMonsterSpriteWidth;
	//Monster rectangle
	_currentMonsterSpriteRect.left = 0;
	_currentMonsterSpriteRect.top = 0;
	_currentMonsterSpriteRect.height = _currentMonsterSpriteHeight;
	_currentMonsterSpriteRect.width = _currentMonsterSpriteWidth;

	//Maximum life increase + full life for the next monster
	//TODO
	//find formula to increase hp of monsters
	this->setHp(_maxHp);

	_state = Monster::State::IDLE;
	_monsterAnimationClock.restart();
}