#pragma once
#include "Mytexture.h"
class Button
{
public:
	Button();
	Button(sf::Texture& btnTexture);
	void draw(sf::RenderWindow& window);
	void setTexture(sf::Texture& texture);
	sf::Texture& getTexture() { return _btnTexture; }
	void Button::updateShape();
	void Button::setPosition(int x, int y);
	bool Button::isHit(sf::RenderWindow& window);
private:
	sf::Texture _btnTexture;
	sf::Sprite _btnSprite;
	sf::IntRect _btnRect;
	sf::RectangleShape _btnShape;
	bool _isMouseAlreadyOverButton;
};

