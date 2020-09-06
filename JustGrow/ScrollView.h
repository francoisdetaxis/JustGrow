#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class ScrollView
{
public:
	ScrollView(sf::Texture& bgTexture);
	void draw(sf::RenderWindow& window);
private:
	sf::Texture _backgroundTexture;
	sf::Sprite _scrollSprite;
	sf::RectangleShape _scrollBar;
};
