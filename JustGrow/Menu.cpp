#include "Menu.h"

Menu::Menu(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts)
{
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
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(_menuSprite);
	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->draw(window);
	}
}

void Menu::addButton(Button* btn)
{
	_buttons.push_back(btn);
}

void Menu::move(int x, int y)
{
	_menuSprite.move(x, y);
	for (int i = 0; i < _buttons.size(); i++) {
		_buttons[i]->move(x, y);
	}
}