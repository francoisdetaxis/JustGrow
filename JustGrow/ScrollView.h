#pragma once
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

