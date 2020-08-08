#include "Monster.h"

Monster::Monster(std::string monsterPath, std::string monsterHitSoundPath, int frames)
{
	//load texture from file
	if (!a_monsterTexture.loadFromFile(monsterPath)) {
		//TODO handle error
	}

	//load hit sound from file
	if (!a_soundBuffer.loadFromFile(monsterHitSoundPath)) {
		//TODO handle error
	}

	//size of 1 frame (frames must be squares)
	a_frameSize = a_monsterTexture.getSize().y;

	//total number of frames
	a_framesTotal = frames;

	//max length of the sprite (there's 30 frames)
	a_maxLeft = (a_framesTotal - 1) * a_frameSize;

	//Monster rectangle
	a_monsterRect.left = 0;
	a_monsterRect.top = 0;
	a_monsterRect.height = a_frameSize;
	a_monsterRect.width = a_frameSize;

	//Monster hitbox
	a_monsterHitbox.height = a_monsterRect.height;
	a_monsterHitbox.width = a_monsterRect.width;

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

sf::Sprite Monster::getSprite()
{
	return a_monsterSprite;
}


bool Monster::isHit(sf::RenderWindow* window)
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
