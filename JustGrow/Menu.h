#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Mytexture.h"
#include "Button.h"

class Menu
{
public:
	Menu::Menu(std::map<std::string, Mytexture>& textures);
	void Menu::draw(sf::RenderWindow& window);
	void Menu::addButton(Button* btn);
	void Menu::move(int x, int y);
	sf::Vector2u Menu::getSize() { return _menuTexture.getSize(); }
private:
	int _scale;
	sf::IntRect _menuRect;
	sf::Texture _menuTexture;
	sf::Sprite _menuSprite;
	std::vector<Button*> _buttons;
};
