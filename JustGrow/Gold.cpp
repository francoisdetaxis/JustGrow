#include "Gold.h"

Gold::Gold()
{
}

Gold::Gold(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts, std::map<std::string, sf::SoundBuffer>& sounds, Menu& menu)
{
	//initial gold gain
	//_goldGain = 1;
	_goldGain = BigNumber(1, 0);

	//money display
	//_gold = 0;
	_gold = BigNumber(0, 0);
	_goldSprite.setTexture(textures["coin"].getTexture());
	//_goldText.setString("0");
	//_goldText.setString(_gold.asString(true));
	this->updateText();
	_goldText.setCharacterSize(48);
	_goldText.setFont(fonts["dmgFont"]);
	_goldText.setPosition(menu.getSize().x * 0.8, menu.getSize().y * 0.2);
	_goldSprite.setPosition(_goldText.getPosition().x + _goldText.getGlobalBounds().width + 25, _goldText.getPosition().y);

	//gold pickup sound
	_goldSound.setBuffer(sounds["coin_pickup"]);
}

void Gold::increaseGain(Stage& stage, Monster& monster, Player& player)
{
	double stageNb = stage.getStage();
	if (stageNb > 75)
	{
		//_goldGain = std::ceil((monster.getMaxHp() / 15) * std::min(3.0, std::pow(1.025, stageNb - 75)) * player.getGoldMultiplier());
		_goldGain = (monster.getMaxHp() / 15) * std::min(3.0, std::pow(1.025, stageNb - 75)) * player.getGoldMultiplier();
	}
	else
	{
		//_goldGain = std::ceil((monster.getMaxHp() / 15) * player.getGoldMultiplier());
		_goldGain = (monster.getMaxHp() / 15) * player.getGoldMultiplier();
		if (_goldGain < 1)
		{
			//_goldGain = 1;
			_goldGain = BigNumber(1, 0);
		}
	}
}

void Gold::draw(sf::RenderWindow& window)
{
	window.draw(_goldSprite);
	window.draw(_goldText);
}

void Gold::move(int x, int y)
{
	_goldSprite.move(x, y);
	_goldText.move(x, y);
}

void Gold::gain()
{
	_gold += _goldGain; //increase gold amount
	//_goldText.setString(std::to_string(_gold)); //update gold text
	//_goldText.setString(_gold.asString(true)); //update gold text
	this->updateText();
	_goldSound.play();
}

void Gold::updateText()
{
	_goldText.setString(_gold.asString(true)); //update gold text
}

//bool Gold::spend(int amount)
bool Gold::spend(BigNumber amount)
{
	//return false if not enough gold otherwise return true
	if (_gold - amount >= 0)
	{
		_gold -= amount;
		//_goldText.setString(std::to_string(_gold)); //update gold text
		//_goldText.setString(_gold.asString(true)); //update gold text
		this->updateText();
		return true;
	}
	else
	{
		return false;
	}
}