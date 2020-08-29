#include "ScrollView.h"

ScrollView::ScrollView(sf::Texture& bgTexture)
{
	//texture
	_backgroundTexture = bgTexture;

	//sprite
	_scrollSprite.setTexture(_backgroundTexture);

	//scrollbar
	_scrollBar.setFillColor(sf::Color::Green);
}

void ScrollView::draw(sf::RenderWindow& window)
{
	window.draw(_scrollSprite);
	window.draw(_scrollBar);
}