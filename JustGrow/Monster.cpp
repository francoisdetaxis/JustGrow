#include "main.h"

Monster::Monster(std::map<std::string, sf::Texture> textures, std::map<std::string, sf::SoundBuffer> sounds, std::map<std::string, sf::Font> fonts)
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
	a_monsterTexture = textures["monster1"];

	//initial hit sound
	a_soundBuffer = sounds["hitSound1"];
	a_hitSound.setBuffer(a_soundBuffer);
	
	//initial platform
	a_backgroundTexture = textures["platform1"];

	//initial hp bar
	a_hpBarEmptyTexture = textures["hpBarEmpty"];
	a_hpBarFullTexture = textures["hpBarFull"];
	a_hpFrameWidth = a_hpBarFullTexture.getSize().x;

	a_hpRect.height = a_hpBarFullTexture.getSize().y;
	a_hpRect.width = a_hpBarFullTexture.getSize().x;

	//size of 1 frame (frames must be squares)
	a_frameSize = a_monsterTexture.getSize().y;

	//total number of frames
	a_framesTotal = a_monsterTexture.getSize().x / a_monsterTexture.getSize().y;

	//max length of the monster sprite
	a_maxLeft = (a_framesTotal - 1) * a_frameSize;

	//Monster rectangle
	a_monsterRect.left = 0;
	a_monsterRect.top = 0;
	a_monsterRect.height = a_frameSize;
	a_monsterRect.width = a_frameSize;

	//Monster hitbox
	a_monsterHitbox.height = a_monsterRect.height;
	a_monsterHitbox.width = a_monsterRect.width;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBorders.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBorders.setSize(sf::Vector2f(a_monsterRect.height, a_monsterRect.width));
	a_hitboxBorders.setFillColor(sf::Color::Transparent);
	a_hitboxBorders.setOutlineColor(sf::Color::Red);
	a_hitboxBorders.setOutlineThickness(5.f);

	//set sprites textures
	a_monsterSprite.setTexture(a_monsterTexture);
	a_backgroundSprite.setTexture(a_backgroundTexture);
	a_hpBarEmptySprite.setTexture(a_hpBarEmptyTexture);
	a_hpBarFullSprite.setTexture(a_hpBarFullTexture);
	a_hpBarFullSprite.setTextureRect(a_hpRect);
}

int Monster::getFrameSize()
{
	return a_frameSize;
}

void Monster::setPosition(int x, int y)
{
	a_monsterSprite.setPosition(x, y);
	a_backgroundSprite.setPosition(x, y + a_frameSize / 5);
	a_hpBarEmptySprite.setPosition(x + a_frameSize / 5, y + a_frameSize / 1.25);
	a_hpBarFullSprite.setPosition(x + a_frameSize / 5, y + a_frameSize / 1.25);
	a_hpText.setPosition(x + a_frameSize / 2.5, y + a_frameSize / 1.40);

	//TODO WTF ?
	//a_hpRect.top = y + a_frameSize / 1.25;
	//a_hpRect.left = x + a_frameSize / 5;

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBorders.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBorders.setSize(sf::Vector2f(a_monsterRect.height, a_monsterRect.width));
}

void Monster::nextFrame()
{
	if (a_clock.getElapsedTime().asMilliseconds() > 50) {
		a_clock.restart();

		if (a_monsterRect.left >= a_maxLeft) {
			a_monsterRect.left = 0;
		}
		else {
			a_monsterSprite.setTextureRect(a_monsterRect);
			a_monsterRect.left += a_frameSize;
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
	//window->draw(a_hitboxBorders);
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