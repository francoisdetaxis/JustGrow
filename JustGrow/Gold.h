#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Mytexture.h"
#include "Button.h"
#include "Menu.h"

class Gold
{
public:
	Gold();
	Gold(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts, std::map<std::string, sf::SoundBuffer>& sounds, Menu& menu);
	void increaseGain();
	void Gold::draw(sf::RenderWindow& window);
	void Gold::move(int x, int y);
	void Gold::gain();
private:
	int _goldGain;
	int _gold;
	sf::Text _goldText;
	sf::Sprite _goldSprite;
	sf::Sound _goldSound;
};
