#include "Monster.h"

Monster::Monster(std::map<std::string, sf::Texture> textures, std::map<std::string, sf::SoundBuffer> sounds)
{

	a_monsterTexture = textures["monster1"];
	a_soundBuffer = sounds["hitSound1"];
	a_backgroundTexture = textures["platform1"];

	//size of 1 frame (frames must be squares)
	a_frameSize = a_monsterTexture.getSize().y;

	//total number of frames
	a_framesTotal = a_monsterTexture.getSize().x / a_monsterTexture.getSize().y;

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
	a_hitboxBorders.setFillColor(sf::Color::Transparent);
	a_hitboxBorders.setOutlineColor(sf::Color::Red);
	a_hitboxBorders.setOutlineThickness(5.f);

	//set sprites textures
	a_monsterSprite.setTexture(a_monsterTexture);
	a_backgroundSprite.setTexture(a_backgroundTexture);

}

int Monster::getFrameSize()
{
	return a_frameSize;
}

void Monster::setPosition(int x, int y)
{
	a_monsterSprite.setPosition(x, y);
	a_backgroundSprite.setPosition(x, y + a_frameSize / 5);

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
	window->draw(a_hitboxBorders);
	window->draw(a_monsterSprite);

}