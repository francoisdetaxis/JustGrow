#include "main.h"

//Monster::Monster(std::deque<Mytexture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts)
Monster::Monster(std::map<std::string, Mytexture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts)
{
	a_textures = textures;
	a_sounds = sounds;
	a_fonts = fonts;

	//initial monster hp
	a_maxHp = 10;
	a_currentHp = 10;

	//initial booleans
	a_isDead = false;
	a_isHurt = false;

	//INITIALIZE MONSTER
	a_currentMonsterNb = 1;
	a_currentMonsterIdle = textures["monster1_idle"];
	a_currentMonsterHurt = textures["monster1_hurt"];
	a_currentMonsterDying = textures["monster1_dying"];
	//total number of frames
	a_currentMonsterSpriteFramesNb = a_currentMonsterIdle.getFramesNb();
	//set current monster texture
	a_currentMonsterIdleTexture = a_currentMonsterIdle.getTexture();
	a_currentMonsterSprite.setTexture(a_currentMonsterIdleTexture);
	//size of 1 frame
	a_currentMonsterSpriteWidth = a_currentMonsterSprite.getTextureRect().width / a_currentMonsterSpriteFramesNb;
	a_currentMonsterSpriteHeight = a_currentMonsterSprite.getTextureRect().height;
	//max length of the monster sprite
	a_currentMonsterSpriteMaxWidth = (a_currentMonsterSpriteFramesNb - 1) * a_currentMonsterSpriteWidth;
	//Monster rectangle
	a_currentMonsterSpriteRect.left = 0;
	a_currentMonsterSpriteRect.top = 0;
	a_currentMonsterSpriteRect.height = a_currentMonsterSpriteHeight;
	a_currentMonsterSpriteRect.width = a_currentMonsterSpriteWidth;

	//initial hit sound && set all buffers
	a_hit1Buffer = sounds["hit1"];
	a_hit2Buffer = sounds["hit2"];
	a_hit3Buffer = sounds["hit3"];
	a_hitSound.setBuffer(a_hit1Buffer);
	a_currentHitSound = 1;

	//initial platform
	//Mytexture platform = textures["platform6"];
	a_backgroundTexture = textures["platform6"].getTexture();
	a_backgroundSprite.setTexture(a_backgroundTexture);

	//Monster hitbox
	a_currentMonsterHitboxRect.height = a_currentMonsterSpriteHeight;
	a_currentMonsterHitboxRect.width = a_currentMonsterSpriteWidth;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_currentMonsterHitboxRect.left = a_currentMonsterSprite.getPosition().x;
	a_currentMonsterHitboxRect.top = a_currentMonsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBordersShape.setPosition(a_currentMonsterSprite.getPosition().x, a_currentMonsterSprite.getPosition().y);
	a_hitboxBordersShape.setSize(sf::Vector2f(a_currentMonsterSpriteWidth, a_currentMonsterSpriteHeight));
	a_hitboxBordersShape.setFillColor(sf::Color::Transparent);
	a_hitboxBordersShape.setOutlineColor(sf::Color::Red);
	a_hitboxBordersShape.setOutlineThickness(5.f);

	//HP TEXT
	a_hpFont = fonts["hpFont"];
	a_hpText.setFont(a_hpFont);
	a_hpText.setString(std::to_string(a_currentHp) + " HP");
	a_hpText.setColor(sf::Color::Red);

	//HP BAR
	a_hpBarEmptyTexture = textures["hpBarEmpty"].getTexture();
	a_hpBarFullTexture = textures["hpBarFull"].getTexture();
	a_hpFrameWidth = a_hpBarFullTexture.getSize().x;
	a_hpRect.height = a_hpBarFullTexture.getSize().y;
	a_hpRect.width = a_hpBarFullTexture.getSize().x;
	a_hpBarEmptySprite.setTexture(a_hpBarEmptyTexture);
	a_hpBarFullSprite.setTexture(a_hpBarFullTexture);
	a_hpBarFullSprite.setTextureRect(a_hpRect);
}

int Monster::getMonsterFrameWidth()
{
	return a_currentMonsterSpriteWidth;
}

int Monster::getMonsterFrameHeight()
{
	return a_currentMonsterSpriteHeight;

}

void Monster::setPosition(int x, int y)
{
	float centeredX, centeredY, offsetY, offsetX;

	//setPosition monster
	a_currentMonsterSprite.setPosition(x, y);

	//setPosition HP bar
	centeredX = x + (((float)a_currentMonsterSpriteWidth - (float)a_hpBarEmptyTexture.getSize().x) / 2);
	centeredY = y + (((float)a_currentMonsterSpriteHeight - (float)a_hpBarEmptyTexture.getSize().y) / 2);
	offsetY = 0.65 * a_currentMonsterSpriteHeight;
	a_hpBarEmptySprite.setPosition(centeredX, centeredY + offsetY);
	a_hpBarFullSprite.setPosition(centeredX, centeredY + offsetY);

	//setPosition HP Text
	centeredX = x + (((float)a_currentMonsterSpriteWidth - a_hpText.getGlobalBounds().width) / 2);
	centeredY = y + (((float)a_currentMonsterSpriteHeight - a_hpText.getGlobalBounds().height) / 2);
	offsetY = 0.55 * a_currentMonsterSpriteHeight;
	a_hpText.setPosition(centeredX, centeredY + offsetY);

	//setPostion background
	centeredX = x + (((float)a_currentMonsterSpriteWidth - (float)a_backgroundTexture.getSize().x) / 2);
	centeredY = y + (((float)a_currentMonsterSpriteHeight - (float)a_backgroundTexture.getSize().y) / 2);
	offsetY = 0.2 * a_currentMonsterSpriteHeight;
	a_backgroundSprite.setPosition(centeredX, centeredY + offsetY);

	//TODO WTF ? why does this work without setting top and left for hpRect ?
	//a_hpRect.top = y + a_frameSize / 1.25;
	//a_hpRect.left = x + a_frameSize / 5;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_currentMonsterHitboxRect.left = a_currentMonsterSprite.getPosition().x;
	a_currentMonsterHitboxRect.top = a_currentMonsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBordersShape.setPosition(a_currentMonsterSprite.getPosition().x, a_currentMonsterSprite.getPosition().y);
	a_hitboxBordersShape.setSize(sf::Vector2f(a_currentMonsterHitboxRect.width, a_currentMonsterHitboxRect.height));
}

void Monster::nextFrame()
{
	//TODO end of ishurt animation and isdying animations to implement in this method
	int time = a_clock.getElapsedTime().asMilliseconds();
	if (time > 50) {
		a_clock.restart();

		if (a_currentMonsterSpriteRect.left >= a_currentMonsterSpriteMaxWidth) {
			//end of the sprite is reached
			a_currentMonsterSpriteRect.left = 0;
			if (a_isHurt) {
				a_isHurt = false; //we are at the end of the hurt animation
				this->idle();
			}
			if (a_isDead) {
				a_isDead = false;
				this->nextMob();
			}
		}
		else {
			//there are still frames to go on the sprite
			a_currentMonsterSprite.setTextureRect(a_currentMonsterSpriteRect);
			a_currentMonsterSpriteRect.left += a_currentMonsterSpriteWidth;
		}
	}
}

bool Monster::isHit(sf::RenderWindow* window)
{
	return a_currentMonsterHitboxRect.contains(sf::Mouse::getPosition(*window));
}

void Monster::playSound()
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
	switch (a_currentHitSound) {
	case 1:
		a_hitSound.setBuffer(a_hit2Buffer);
		a_currentHitSound = 2;
		break;
	case 2:
		a_hitSound.setBuffer(a_hit3Buffer);
		a_currentHitSound = 3;
		break;
	case 3:
		a_hitSound.setBuffer(a_hit1Buffer);
		a_currentHitSound = 1;
		break;
	}
	a_hitSound.play();
}

void Monster::draw(sf::RenderWindow* window)
{
	//draw background
	window->draw(a_backgroundSprite);

	//debug --> show hitbox
	//window->draw(a_hitboxBordersShape); //comment to hide hitbox borders

	//draw monster sprite
	window->draw(a_currentMonsterSprite);

	//draw hp bars & Text
	window->draw(a_hpBarEmptySprite);
	window->draw(a_hpBarFullSprite);
	window->draw(a_hpText);
}

void Monster::nextPlatform()
{
	//TODO
}

void Monster::setHp(int hp)
{
	if (hp <= 0)
	{
		this->die();
		a_currentHp = 0;
		a_hpText.setString(std::to_string(a_currentHp) + " HP");
		a_hpRect.width = a_currentHp * a_hpFrameWidth / a_maxHp;
		a_hpBarFullSprite.setTextureRect(a_hpRect);
	}
	else {
		a_currentHp = hp;
		a_hpText.setString(std::to_string(a_currentHp) + " HP");
		a_hpRect.width = a_currentHp * a_hpFrameWidth / a_maxHp;
		a_hpBarFullSprite.setTextureRect(a_hpRect);
	}
}

void Monster::takeDmg(int dmgTaken)
{
	this->setHp(a_currentHp - dmgTaken);
	this->hurt();
}

int Monster::getHp()
{
	return a_currentHp;
}

const sf::Vector2f Monster::getPosition()
{
	return a_currentMonsterSprite.getPosition();
}

void Monster::die()
{
	//dyng texture
	a_currentMonsterDyingTexture = a_currentMonsterDying.getTexture();
	//dying frames number
	a_currentMonsterSpriteFramesNb = a_currentMonsterDying.getFramesNb();
	//set texture
	a_currentMonsterSprite.setTexture(a_currentMonsterDyingTexture);

	//size of 1 frame
	a_currentMonsterSpriteWidth = a_currentMonsterDyingTexture.getSize().x / a_currentMonsterSpriteFramesNb;
	a_currentMonsterSpriteHeight = a_currentMonsterDyingTexture.getSize().y;
	//max length of the monster sprite
	a_currentMonsterSpriteMaxWidth = (a_currentMonsterSpriteFramesNb - 1) * a_currentMonsterSpriteWidth;
	//Monster rectangle
	a_currentMonsterSpriteRect.left = 0;
	a_currentMonsterSpriteRect.top = 0;
	a_currentMonsterSpriteRect.height = a_currentMonsterSpriteHeight;
	a_currentMonsterSpriteRect.width = a_currentMonsterSpriteWidth;

	a_isDead = true;
	a_clock.restart();
}

void Monster::hurt()
{
	if (!a_isHurt)
	{
		//change to hurt monster texture
		a_currentMonsterHurtTexture = a_currentMonsterHurt.getTexture();
		//hurt frames number
		a_currentMonsterSpriteFramesNb = a_currentMonsterHurt.getFramesNb();
		//set texture
		a_currentMonsterSprite.setTexture(a_currentMonsterHurtTexture);
		//size of 1 frame
		a_currentMonsterSpriteWidth = a_currentMonsterHurtTexture.getSize().x / a_currentMonsterSpriteFramesNb;
		a_currentMonsterSpriteHeight = a_currentMonsterHurtTexture.getSize().y;
		//max length of the monster sprite
		a_currentMonsterSpriteMaxWidth = (a_currentMonsterSpriteFramesNb - 1) * a_currentMonsterSpriteWidth;
		//Monster rectangle
		a_currentMonsterSpriteRect.left = 0;
		a_currentMonsterSpriteRect.top = 0;
		a_currentMonsterSpriteRect.height = a_currentMonsterSpriteHeight;
		a_currentMonsterSpriteRect.width = a_currentMonsterSpriteWidth;
		a_isHurt = true;
		a_clock.restart();
	}
	else {
		a_currentMonsterSpriteRect.left = 0;
		a_clock.restart();
	}


}

void Monster::idle()
{
	//change to hurt monster texture
	a_currentMonsterIdleTexture = a_currentMonsterIdle.getTexture();
	//hurt frames number
	a_currentMonsterSpriteFramesNb = a_currentMonsterIdle.getFramesNb();
	//set texture
	a_currentMonsterSprite.setTexture(a_currentMonsterIdleTexture);
	//size of 1 frame
	a_currentMonsterSpriteWidth = a_currentMonsterIdleTexture.getSize().x / a_currentMonsterSpriteFramesNb;
	a_currentMonsterSpriteHeight = a_currentMonsterIdleTexture.getSize().y;
	//max length of the monster sprite
	a_currentMonsterSpriteMaxWidth = (a_currentMonsterSpriteFramesNb - 1) * a_currentMonsterSpriteWidth;
	//Monster rectangle
	a_currentMonsterSpriteRect.left = 0;
	a_currentMonsterSpriteRect.top = 0;
	a_currentMonsterSpriteRect.height = a_currentMonsterSpriteHeight;
	a_currentMonsterSpriteRect.width = a_currentMonsterSpriteWidth;

	//!!!!!!!!!!!!!!!!!!!!!!!
	a_clock.restart();
}

void Monster::nextMob()
{
	//change monster texture to the next monster
	//TODO
	//make these "monster" and "_IDLE" in #define ?
	std::string nextMonster = "monster" + std::to_string(a_currentMonsterNb + 1);
	a_currentMonsterNb++;
	a_currentMonsterIdle = a_textures[nextMonster + "_idle"];
	a_currentMonsterHurt = a_textures[nextMonster + "_hurt"];
	a_currentMonsterDying = a_textures[nextMonster + "_dying"];
	a_currentMonsterIdleTexture = a_currentMonsterIdle.getTexture();
	a_currentMonsterHurtTexture = a_currentMonsterHurt.getTexture();
	a_currentMonsterDyingTexture = a_currentMonsterDying.getTexture();
	//dying frames number
	a_currentMonsterSpriteFramesNb = a_currentMonsterIdle.getFramesNb();
	//set texture
	a_currentMonsterSprite.setTexture(a_currentMonsterIdleTexture);

	//size of 1 frame
	a_currentMonsterSpriteWidth = a_currentMonsterIdleTexture.getSize().x / a_currentMonsterSpriteFramesNb;
	a_currentMonsterSpriteHeight = a_currentMonsterIdleTexture.getSize().y;
	//max length of the monster sprite
	a_currentMonsterSpriteMaxWidth = (a_currentMonsterSpriteFramesNb - 1) * a_currentMonsterSpriteWidth;
	//Monster rectangle
	a_currentMonsterSpriteRect.left = 0;
	a_currentMonsterSpriteRect.top = 0;
	a_currentMonsterSpriteRect.height = a_currentMonsterSpriteHeight;
	a_currentMonsterSpriteRect.width = a_currentMonsterSpriteWidth;

	//Maximum life increase + full life for the next monster
	//TODO
	//find formula to increase hp of monsters
	a_maxHp += 10;
	this->setHp(a_maxHp);

	//set isDead to false
	a_isDead = false;
}

