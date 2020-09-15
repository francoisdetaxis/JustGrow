#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <math.h>
#include "Mytexture.h"
#include "Button.h"
#include "Menu.h"
#include "Stage.h"
#include "Monster.h"
#include "Player.h"
#include "BigNumber.h"

class Stage;
class Monster;
class Player;
class Gold
{
public:
	Gold();
	Gold(std::map<std::string, Mytexture>& textures, std::map<std::string, sf::Font>& fonts, std::map<std::string, sf::SoundBuffer>& sounds, Menu& menu);
	void increaseGain(Stage& stage, Monster& monster, Player& player);
	void Gold::draw(sf::RenderWindow& window);
	void Gold::move(int x, int y);
	void Gold::gain();
	void updateText();
	//bool spend(int amount);
	bool spend(BigNumber amount);

	//public because easier...
	BigNumber _goldGain;
	BigNumber _gold;
private:
	//int _goldGain;
	//int _gold;

	sf::Text _goldText;
	sf::Sprite _goldSprite;
	sf::Sound _goldSound;
};
