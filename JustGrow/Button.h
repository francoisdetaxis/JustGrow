#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button::Button();
	Button::Button(sf::Texture& btnTexture);
	void Button::move(int x, int y);
	void Button::draw(sf::RenderWindow& window);
	void Button::setTexture(sf::Texture& texture);
	sf::Texture& Button::getTexture() { return _btnTexture; }
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
