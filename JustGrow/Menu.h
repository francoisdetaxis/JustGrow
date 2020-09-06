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
	Menu(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void draw(sf::RenderWindow& window);
	void addButton(Button* btn);
	void move(int x, int y);
	sf::Vector2u getSize() { return _menuSprite.getTexture()->getSize(); }

private:
	int _scale;
	sf::IntRect _menuRect;
	sf::Sprite _menuSprite;
	std::vector<Button*> _buttons;
};
