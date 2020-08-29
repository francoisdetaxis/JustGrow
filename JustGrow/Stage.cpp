#include "Stage.h"
#include "main.h"

Stage::Stage(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)
{
	_currentLevel = 1;
	_currentStage = 1;
	_currentPlatformNb = 1;
	_textures = textures;
	_currentPlatform = textures["platform1"];
	_currentPlatformSprite.setTexture(_currentPlatform.getTexture());

	//TODO change font ?
	_stageText.setFont(fonts["dmgFont"]);
	_levelText.setFont(fonts["dmgFont"]);
	_stageText.setString("Stage 1");
	_levelText.setString("Level 1/10");

	this->updateTextureRect();
	this->updateDebugShape();
}

void Stage::nextLevel()
{
	if (_currentLevel == 10) {
		_currentLevel = 1;
		this->nextStage();
	}
	else
		_currentLevel++;

	_levelText.setString("Level " + std::to_string(_currentLevel) + "/10");
}

void Stage::nextStage()
{
	_currentStage++;
	_stageText.setString("Stage " + std::to_string(_currentStage));
}

void Stage::updateTextsPosition(Monster& monster)
{
	int stageCenterX, stageCenterY, levelCenterX, levelCenterY, offsetY;
	stageCenterX = monster.getPosition().x + ((monster.getMonsterWidth() - _stageText.getGlobalBounds().width) / 2);
	stageCenterY = monster.getPosition().y + ((monster.getMonsterHeight() - _stageText.getGlobalBounds().height) / 2);
	levelCenterX = monster.getPosition().x + ((monster.getMonsterWidth() - _levelText.getGlobalBounds().width) / 2);
	levelCenterY = monster.getPosition().y + ((monster.getMonsterHeight() - _levelText.getGlobalBounds().height) / 2);
	offsetY = monster.getMonsterHeight();
	_stageText.setPosition(stageCenterX, stageCenterY - offsetY);
	_levelText.setPosition(levelCenterX, levelCenterY + _stageText.getGlobalBounds().height + 10 - offsetY);
}

void Stage::nextPlatform(Monster& monster)
{
	_currentPlatformNb++;
	if (_currentPlatformNb > MAX_PLATFORM_NB)
		_currentPlatformNb = 1;
	std::string platform;
	platform = "platform" + std::to_string(_currentPlatformNb);
	_currentPlatform = _textures[platform];
	_currentPlatformSprite.setTexture(_currentPlatform.getTexture());

	this->updateTextureRect();

	int centeredX, centeredY, offsetY, monsterHeight, monsterWidth;
	monsterWidth = monster.getMonsterWidth();
	monsterHeight = monster.getMonsterHeight();
	centeredX = monster.getPosition().x + (((float)monsterWidth - (float)this->getSize().x) / 2);
	centeredY = monster.getPosition().y + (((float)monsterHeight - (float)this->getSize().y) / 2);
	offsetY = 0.2 * monsterHeight;
	this->setPosition(centeredX, centeredY + offsetY, monster);
	this->updateDebugShape();
}

void Stage::updateTextureRect()
{
	_currentRect.top = 0;
	_currentRect.left = 0;
	_currentRect.height = _currentPlatform.getTexture().getSize().y;
	_currentRect.width = _currentPlatform.getTexture().getSize().x;
	_currentPlatformSprite.setTextureRect(_currentRect);
}

void Stage::updateDebugShape()
{
	_debugShape.setPosition(_currentPlatformSprite.getPosition().x, _currentPlatformSprite.getPosition().y);
	_debugShape.setSize(sf::Vector2f(_currentPlatform.getTexture().getSize().x, _currentPlatform.getTexture().getSize().y));
	_debugShape.setFillColor(sf::Color::Transparent);
	_debugShape.setOutlineColor(sf::Color::Blue);
	_debugShape.setOutlineThickness(5.f);
}

void Stage::draw(sf::RenderWindow& window, bool debug)
{
	window.draw(_currentPlatformSprite);
	window.draw(_stageText);
	window.draw(_levelText);
	if (debug)
		window.draw(_debugShape);
}

void Stage::setPosition(int x, int y, Monster& monster)
{
	_currentPlatformSprite.setPosition(x, y);
	this->updateDebugShape();
	this->updateTextsPosition(monster);
}