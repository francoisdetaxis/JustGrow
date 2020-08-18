#include "main.h"

Stage::Stage(std::map<std::string, Mytexture>* textures)
{
	_currentLevel = 1;
	_currentStage = 1;
	_currentPlatformNb = 1;
	_textures = textures;
	_currentPlatform = (*textures)["platform1"];
	_currentPlatformSprite.setTexture(*_currentPlatform.getTexture());

	this->updateTextureRect();
	this->updateDebugShape();
}

void Stage::next(Monster* monster)
{
	_currentPlatformNb++;
	if (_currentPlatformNb > MAX_PLATFORM_NB)
		_currentPlatformNb = 1;
	std::string platform;
	platform = "platform" + std::to_string(_currentPlatformNb);
	_currentPlatform = (*_textures)[platform];
	_currentPlatformSprite.setTexture(*_currentPlatform.getTexture());

	this->updateTextureRect();

	int centeredX, centeredY, offsetY, monsterHeight, monsterWidth;
	monsterWidth = monster->getMonsterWidth();
	monsterHeight = monster->getMonsterHeight();
	centeredX = monster->getPosition().x + (((float)monsterWidth - (float)this->getSize().x) / 2);
	centeredY = monster->getPosition().y + (((float)monsterHeight - (float)this->getSize().y) / 2);
	offsetY = 0.2 * monsterHeight;
	this->setPosition(centeredX, centeredY + offsetY);
	this->updateDebugShape();
}

void Stage::updateTextureRect()
{
	_currentRect.top = 0;
	_currentRect.left = 0;
	_currentRect.height = _currentPlatform.getTexture()->getSize().y;
	_currentRect.width = _currentPlatform.getTexture()->getSize().x;
	_currentPlatformSprite.setTextureRect(_currentRect);
}

void Stage::updateDebugShape()
{
	_debugShape.setPosition(_currentPlatformSprite.getPosition().x, _currentPlatformSprite.getPosition().y);
	_debugShape.setSize(sf::Vector2f(_currentPlatform.getTexture()->getSize().x, _currentPlatform.getTexture()->getSize().y));
	_debugShape.setFillColor(sf::Color::Transparent);
	_debugShape.setOutlineColor(sf::Color::Blue);
	_debugShape.setOutlineThickness(5.f);
}

void Stage::draw(sf::RenderWindow* window, bool debug)
{
	window->draw(_currentPlatformSprite);
	if (debug)
		window->draw(_debugShape);
}

void Stage::setPosition(int x, int y)
{
	_currentPlatformSprite.setPosition(x, y);
	this->updateDebugShape();
}