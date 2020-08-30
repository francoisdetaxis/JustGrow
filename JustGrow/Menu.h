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
	Menu::Menu(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts);
	void Menu::draw(sf::RenderWindow& window);
	void Menu::addButton(Button* btn);
	void gainGold();
	void Menu::move(int x, int y);
	sf::Vector2u Menu::getSize() { return _menuSprite.getTexture()->getSize(); }
	class Gold
	{
	public:
		Gold();
		Gold(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts, Menu* menu);
		void Gold::draw(sf::RenderWindow& window);
		void Gold::move(int x, int y);
		void Gold::gain();
	private:
		int _goldGain;
		int _gold;
		sf::Text _goldText;
		sf::Sprite _goldSprite;
	};
private:
	//int _goldGain;
	//int _gold;
	//sf::Text _goldText;
	//sf::Sprite _goldSprite;
	Gold _gold;

	int _scale;
	sf::IntRect _menuRect;
	sf::Sprite _menuSprite;
	std::vector<Button*> _buttons;
};
