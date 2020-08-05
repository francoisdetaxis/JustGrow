#include "Monster.h"

Monster::Monster()
{
	//max length of the sprite
	a_maxLeft = 9240;

	//size of 1 frame
	a_frameSize = 660;

	//Monster rectangle
	a_monsterRect.left = 0;
	a_monsterRect.top = 0;
	a_monsterRect.height = 660;
	a_monsterRect.width = 660;

	//Monster hitbox
	a_monsterHitbox.height = a_monsterRect.height;
	a_monsterHitbox.width = a_monsterRect.width;
	
	if (!a_monsterTexture.loadFromFile("./resources/image/running_man.png")) {
		//TODO handle error
	}
	if (!a_soundBuffer.loadFromFile("./resources/sound/hit_sound.wav")) {
		//TODO handle error
	}
	a_hitSound.setBuffer(a_soundBuffer);

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;
	
	//hitbox borders (shape) = hitbox rect
	a_hitboxBorders.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBorders.setSize(sf::Vector2f(a_monsterRect.height, a_monsterRect.width));
	a_hitboxBorders.setOutlineColor(sf::Color::Red);
	a_hitboxBorders.setOutlineThickness(5.f);

	//set monster sprite texture
	a_monsterSprite.setTexture(a_monsterTexture);

}

int Monster::getFrameSize()
{
	return a_frameSize;
}

void Monster::setPosition(int x, int y)
{
	a_monsterSprite.setPosition(x, y);

	//hitbox rect = monster rect initial position
	// TOP = y position of the top left corner
	// LEFT = x position of the top left corner
	a_monsterHitbox.left = a_monsterSprite.getPosition().x;
	a_monsterHitbox.top = a_monsterSprite.getPosition().y;

	//hitbox borders (shape) = hitbox rect
	a_hitboxBorders.setPosition(a_monsterSprite.getPosition().x, a_monsterSprite.getPosition().y);
	a_hitboxBorders.setSize(sf::Vector2f(a_monsterRect.height, a_monsterRect.width));
}

sf::RectangleShape Monster::getHitboxShape()
{
	return a_hitboxBorders;
}

void Monster::setRect(sf::IntRect rect)
{
	a_monsterSprite.setTextureRect(rect);
}



sf::IntRect Monster::getRect()
{
	return a_monsterRect;
}

void Monster::resetRect()
{
	a_monsterRect.left = 0;
}

void Monster::nextFrame()
{
	a_monsterSprite.setTextureRect(a_monsterRect);
	a_monsterRect.left += a_frameSize;
	
}

sf::Sprite Monster::getSprite()
{
	return a_monsterSprite;
}

int Monster::getMaxLeft()
{
	return a_maxLeft;
}

int Monster::getClockTime()
{
	return a_clock.getElapsedTime().asMilliseconds();
}

void Monster::restartclock()
{
	a_clock.restart();
}

bool Monster::isHit(sf::RenderWindow *window)
{
	//DEBUG VERSION
	//sf::Vector2i pos = sf::Mouse::getPosition(*window);
	//if (a_monsterHitbox.contains(pos))
	//	return true;
	//else
	//	return false;

	//SHORT VERSION
	return a_monsterHitbox.contains(sf::Mouse::getPosition(*window));
}

void Monster::playSound()
{
	a_hitSound.play();
}
