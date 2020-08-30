#include "Menu.h"

Menu::Menu(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)
{
	//initial gold gain
	_goldGain = 1;
	//scale
	_scale = 1;

	////menu texture
	_menuSprite.setTexture(textures["menu"].getTexture());

	//menu rect
	_menuRect.top = 0;
	_menuRect.left = 0;
	_menuRect.height = _menuSprite.getGlobalBounds().height;
	_menuRect.width = _menuSprite.getGlobalBounds().width;

	//menu sprite
	_menuSprite.setTextureRect(_menuRect);

	//money display
	_gold = 0;
	_goldSprite.setTexture(textures["coin"].getTexture());
	_goldText.setString("0");
	_goldText.setCharacterSize(48);
	_goldText.setFont(fonts["dmgFont"]);
	_goldText.setPosition(_menuSprite.getGlobalBounds().width * 0.8, _menuSprite.getGlobalBounds().height * 0.2);
	_goldSprite.setPosition(_goldText.getPosition().x + _goldText.getGlobalBounds().width + 25, _goldText.getPosition().y);
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(_menuSprite);
	window.draw(_goldSprite);
	window.draw(_goldText);

	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->draw(window);
	}
}

void Menu::addButton(Button* btn)
{
	_buttons.push_back(btn);
}

void Menu::gainGold()
{
	_gold += _goldGain;
	_goldText.setString(std::to_string(_gold));
}

void Menu::move(int x, int y)
{
	_menuSprite.move(x, y);
	_goldSprite.move(x, y);
	_goldText.move(x, y);
	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->move(x, y);
	}
}