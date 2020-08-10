#include "main.h"

Monster::Monster(std::map<std::string, Mytexture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts)
{
	a_textures = textures;
	a_sounds = sounds;
	a_fonts = fonts;

	//initial monster hp
	a_maxHp = 10;
	a_currentHp = 10;

	//initial hp font & text
	a_hpFont = fonts["hpFont"];
	a_hpText.setFont(a_hpFont);
	a_hpText.setString(std::to_string(a_currentHp) + " HP");
	a_hpText.setColor(sf::Color::Red);

	//initial monster texture
	a_monsterTexture = textures["monster1_idle"].getTexture();

	//initial hit sound
	a_soundBuffer = sounds["hitSound1"];
	a_hitSound.setBuffer(a_soundBuffer);
	
	//initial platform
	a_backgroundTexture = textures["platform1"].getTexture();

	//initial hp bar
	a_hpBarEmptyTexture = textures["hpBarEmpty"].getTexture();
	a_hpBarFullTexture = textures["hpBarFull"].getTexture();
	a_hpFrameWidth = a_hpBarFullTexture.getSize().x;

	a_hpRect.height = a_hpBarFullTexture.getSize().y;
	a_hpRect.width = a_hpBarFullTexture.getSize().x;

	//total number of frames
	a_framesTotal = textures["monster1_idle"].getFramesNb();

	//size of 1 frame
	a_monsterSpriteWidth = a_monsterTexture.getSize().x / a_framesTotal;
	a_monsterSpriteHeight = a_monsterTexture.getSize().y;

	//max length of the monster sprite
	a_maxLeft = (a_framesTotal - 1) * a_monsterSpriteWidth;

	//Monster rectangle
	a_monsterSpriteRect.left = 0;
	a_monsterSpriteRect.top = 0;
	a_monsterSpriteRect.height = a_monsterSpriteHeight;
	a_monsterSpriteRect.width = a_monsterSpriteWidth;

	//Monster hitbox
	a_monsterHitbox.height = a_monsterSpriteHeight;
	a_monsterHitbox.width = a_monsterSpriteWidth;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBordersShape.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBordersShape.setSize(sf::Vector2f(a_monsterSpriteWidth, a_monsterSpriteHeight));
	a_hitboxBordersShape.setFillColor(sf::Color::Transparent);
	a_hitboxBordersShape.setOutlineColor(sf::Color::Red);
	a_hitboxBordersShape.setOutlineThickness(5.f);

	//set sprites textures
	a_monsterSprite.setTexture(a_monsterTexture);
	a_backgroundSprite.setTexture(a_backgroundTexture);
	a_hpBarEmptySprite.setTexture(a_hpBarEmptyTexture);
	a_hpBarFullSprite.setTexture(a_hpBarFullTexture);
	a_hpBarFullSprite.setTextureRect(a_hpRect);
}

int Monster::getMonsterFrameWidth()
{
	return a_monsterSpriteWidth;
}

int Monster::getMonsterFrameHeight()
{
	return a_monsterSpriteHeight;

}

void Monster::setPosition(int x, int y)
{
	float centeredXbackground, centeredYbackground;

	//setPosition monster
	a_monsterSprite.setPosition(x, y);

	//setPosition HP bar
	centeredXbackground = x + (((float)a_monsterSpriteWidth - (float)a_hpBarEmptyTexture.getSize().x) / 2);
	centeredYbackground = y + (((float)a_monsterSpriteHeight - (float)a_hpBarEmptyTexture.getSize().y) / 2);
	a_hpBarEmptySprite.setPosition(centeredXbackground, centeredYbackground);
	a_hpBarFullSprite.setPosition(centeredXbackground, centeredYbackground);

	//setPosition HP Text
	centeredXbackground = x + (((float)a_monsterSpriteWidth - 10) / 2);
	centeredYbackground = y + (((float)a_monsterSpriteHeight - 10) / 2);
	a_hpText.setPosition(centeredXbackground, centeredYbackground);

	//setPostion background
	centeredXbackground = x + (((float)a_monsterSpriteWidth - (float)a_backgroundTexture.getSize().x) / 2);
	centeredYbackground = y + (((float)a_monsterSpriteHeight - (float)a_backgroundTexture.getSize().y) / 2);
	a_backgroundSprite.setPosition(centeredXbackground, centeredYbackground);

	//TODO WTF ? why does this work without setting top and left for hpRect ?
	//a_hpRect.top = y + a_frameSize / 1.25;
	//a_hpRect.left = x + a_frameSize / 5;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBordersShape.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBordersShape.setSize(sf::Vector2f(a_monsterHitbox.width, a_monsterHitbox.height));
}

void Monster::nextFrame()
{
	if (a_clock.getElapsedTime().asMilliseconds() > 50) {
		a_clock.restart();

		if (a_monsterSpriteRect.left >= a_maxLeft) {
			a_monsterSpriteRect.left = 0;
		}
		else {
			a_monsterSprite.setTextureRect(a_monsterSpriteRect);
			a_monsterSpriteRect.left += a_monsterSpriteWidth;
		}
	}
}

bool Monster::isHit(sf::RenderWindow* window)
{
	return a_monsterHitbox.contains(sf::Mouse::getPosition(*window));
}

void Monster::playSound()
{
	a_hitSound.play();
}

void Monster::draw(sf::RenderWindow* window)
{
	window->draw(a_backgroundSprite);
	window->draw(a_hitboxBordersShape); //comment to hide hitbox borders
	window->draw(a_monsterSprite);
	window->draw(a_hpBarEmptySprite);
	window->draw(a_hpBarFullSprite);
	window->draw(a_hpText);

}

void Monster::nextMob()
{
	//TODO
	
}

void Monster::nextPlatform()
{
	//TODO
}

void Monster::setHp(int hp)
{
	if (hp < 0)
	{
		//TODO kill monster
	}
	else {
		a_currentHp = hp;
		a_hpText.setString(std::to_string(a_currentHp) + " HP");
		a_hpRect.width = a_currentHp * a_hpFrameWidth / a_maxHp;
		a_hpBarFullSprite.setTextureRect(a_hpRect);
	}
}

int Monster::getHp()
{
	return a_currentHp;
}