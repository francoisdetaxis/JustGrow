#include "Menu.h"

Menu::Gold::Gold()
{

}

Menu::Gold::Gold(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts, Menu* menu)
{
	//initial gold gain
	_goldGain = 1;

	//money display
	_gold = 0;
	_goldSprite.setTexture(textures["coin"].getTexture());
	_goldText.setString("0");
	_goldText.setCharacterSize(48);
	_goldText.setFont(fonts["dmgFont"]);
	_goldText.setPosition(menu->getSize().x * 0.8, menu->getSize().y * 0.2);
	_goldSprite.setPosition(_goldText.getPosition().x + _goldText.getGlobalBounds().width + 25, _goldText.getPosition().y);
}


void Menu::Gold::draw(sf::RenderWindow& window)
{
	window.draw(_goldSprite);
	window.draw(_goldText);
}

void Menu::Gold::move(int x, int y)
{
	_goldSprite.move(x, y);
	_goldText.move(x, y);
}

void Menu::Gold::gain()
{
	_gold += _goldGain;
	_goldText.setString(std::to_string(_gold));
}
