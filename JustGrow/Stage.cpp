#include "Stage.h"
#include "main.h"

Stage::Stage(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)
{
	_currentLevel = 1;
	_currentStage = 1;
	_currentPlatformNb = 1;
	_bossTimeSeconds = 30.0;
	_textures = textures;
	_currentPlatform = textures["platform1"];
	_currentPlatformSprite.setTexture(_currentPlatform.getTexture());

	//timer and skull sprites
	_timerSprite.setTexture(textures["timer"].getTexture());
	_skullSprite.setTexture(textures["skull"].getTexture());

	//TODO change font ?
	_stageText.setFont(fonts["dmgFont"]);
	_levelText.setFont(fonts["dmgFont"]);
	_timerText.setFont(fonts["dmgFont"]);
	_stageText.setString("Stage 1");
	_levelText.setString("Level 1/10");
	_timerText.setString("30.0");

	this->updateTextureRect();
	this->updateDebugShape();
}

void Stage::nextLevel(Monster& monster, Gold& gold, Player& player)
{
	if (_currentLevel == 10 || this->isBoss())
	{
		_currentLevel = 1;
		this->nextStage(monster, gold, player);
	}
	else
	{
		_currentLevel++;
		monster.increaseMaxHp(*this);
		gold.increaseGain(*this, monster, player);
	}

	if (this->isBoss())
	{
		_levelText.setString("Level " + std::to_string(_currentLevel) + "/1");
	}
	else
	{
		_levelText.setString("Level " + std::to_string(_currentLevel) + "/10");
	}
}

void Stage::nextStage(Monster& monster, Gold& gold, Player& player)
{
	_currentStage++;
	_stageText.setString("Stage " + std::to_string(_currentStage));
	monster.increaseMaxHp(*this);
	gold.increaseGain(*this, monster, player);
	this->nextPlatform(monster);
	if (this->isBoss())
	{
		_bossTimer.restart();
		_bossTimeSeconds = 30.0;
		_timerText.setString("30.0");
	}
}

bool Stage::isBoss()
{
	if (_currentStage % 5 == 0)
		return true;
	else
		return false;
}

void Stage::decreaseBossTimer(Monster& monster)
{
	_bossTimeSeconds -= 0.1;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << _bossTimeSeconds;
	_timerText.setString(stream.str());
	if (_bossTimeSeconds < 0)
	{
		_bossTimer.restart();
		_bossTimeSeconds = 30.0;
		_timerText.setString("30.0");
		monster.setHp(monster.getMaxHp());
	}
}

void Stage::draw(sf::RenderWindow& window, Monster& monster, bool debug)
{
	window.draw(_currentPlatformSprite);
	window.draw(_stageText);
	window.draw(_levelText);
	window.draw(_skullSprite);
	if (this->isBoss())
	{
		window.draw(_timerSprite);
		window.draw(_timerText);
		if (_bossTimer.getElapsedTime().asMilliseconds() > 100)
		{
			this->decreaseBossTimer(monster);
			_bossTimer.restart();
		}
	}
	if (debug)
		window.draw(_debugShape);
}

void Stage::updateTextsPosition(Monster& monster)
{
	//stage and level texts position are to be set first
	int stageCenterX, stageCenterY, levelCenterX, levelCenterY, offsetY;
	stageCenterX = monster.getPosition().x + ((monster.getMonsterWidth() - _stageText.getGlobalBounds().width) / 2);
	stageCenterY = monster.getPosition().y + ((monster.getMonsterHeight() - _stageText.getGlobalBounds().height) / 2);
	levelCenterX = monster.getPosition().x + ((monster.getMonsterWidth() - _levelText.getGlobalBounds().width - _skullSprite.getGlobalBounds().width) / 2) + _skullSprite.getGlobalBounds().width;
	levelCenterY = monster.getPosition().y + ((monster.getMonsterHeight() - _levelText.getGlobalBounds().height) / 2);
	offsetY = monster.getMonsterHeight();
	_stageText.setPosition(stageCenterX, stageCenterY - offsetY);
	_levelText.setPosition(levelCenterX, levelCenterY + _stageText.getGlobalBounds().height + 10 - offsetY);
}

void Stage::updateSkullPosition(Monster& monster)
{
	//text position must be set beforehand...
	int skullX;
	skullX = monster.getPosition().x + ((monster.getMonsterWidth() - _levelText.getGlobalBounds().width - _skullSprite.getGlobalBounds().width) / 2);
	_skullSprite.setPosition(skullX, _levelText.getPosition().y - 10);
}

void Stage::updateTimerSpritePosition()
{
	//skull position must be set beforehand...
	_timerSprite.setPosition(_skullSprite.getPosition().x, _skullSprite.getPosition().y + _timerSprite.getGlobalBounds().height + 10);
}

void Stage::updateTimerTextPosition()
{
	//timer sprite position must be set beforehand...
	_timerText.setPosition(_timerSprite.getPosition().x + _timerSprite.getGlobalBounds().width + 10, _timerSprite.getPosition().y + 10);
}

void Stage::updateDebugShape()
{
	_debugShape.setPosition(_currentPlatformSprite.getPosition().x, _currentPlatformSprite.getPosition().y);
	_debugShape.setSize(sf::Vector2f(_currentPlatform.getTexture().getSize().x, _currentPlatform.getTexture().getSize().y));
	_debugShape.setFillColor(sf::Color::Transparent);
	_debugShape.setOutlineColor(sf::Color::Blue);
	_debugShape.setOutlineThickness(5.f);
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

void Stage::setPosition(int x, int y, Monster& monster)
{
	_currentPlatformSprite.setPosition(x, y);
	_timerSprite.setPosition(x, y);
	_skullSprite.setPosition(x, y);
	this->updateDebugShape();
	this->updateTextsPosition(monster);
	this->updateSkullPosition(monster);
	this->updateTimerSpritePosition();
	this->updateTimerTextPosition();
}