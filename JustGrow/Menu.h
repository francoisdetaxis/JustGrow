#pragma once
#include "Mytexture.h"
#include "Button.h"


class Menu
{
public:
	Menu(std::map<std::string, Mytexture>* textures);
	void draw(sf::RenderWindow &window);
	void Menu::addButton(Button* btn);
private:
	sf::IntRect _menuRect;
	sf::Texture _menuTexture;
	sf::Sprite _menuSprite;
	std::vector<Button*> _buttons;
};

