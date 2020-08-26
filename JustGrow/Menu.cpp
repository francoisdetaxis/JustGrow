#include "main.h"

Menu::Menu(std::map<std::string, Mytexture>* textures)
{
	//menu texture
	_menuTexture = *(*textures)["menu"].getTexture();

	//menu rect
	_menuRect.top = 0;
	_menuRect.left = 0;
	_menuRect.height = _menuTexture.getSize().y;
	_menuRect.width = _menuTexture.getSize().x;

	//menu sprite
	_menuSprite.setTexture(_menuTexture);
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