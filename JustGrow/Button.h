#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button::Button();
	Button(sf::Texture& btnTexture, std::map<std::string, sf::Font>& fonts);
	void Button::move(int x, int y);
	void Button::draw(sf::RenderWindow& window);
	void Button::setTexture(sf::Texture& texture);
	sf::Texture& Button::getTexture() { return _btnTexture; }
	void Button::updateShape();
	void Button::setPosition(int x, int y);
	void setTextString(std::string str);
	void setTooltipString(std::string str);
	bool Button::isHit(sf::RenderWindow& window);
private:
	std::map<std::string, sf::Font> _fonts;
	sf::Text _text;
	sf::Text _tooltip;
	sf::Texture _btnTexture;
	sf::Sprite _btnSprite;
	sf::IntRect _btnRect;
	sf::RectangleShape _btnShape;
	bool _isMouseAlreadyOverButton;
};
