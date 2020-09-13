#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button();
	Button(sf::Texture& btnTexture, std::map<std::string, sf::Font>& fonts);
	Button(sf::Texture& btnTexture);
	void move(int x, int y);
	void draw(sf::RenderWindow& window);
	void setTexture(sf::Texture& texture);
	sf::Texture& getTexture() { return _btnTexture; }
	void updateShape();
	void setPosition(int x, int y);
	void setTextString(std::string str);
	void setTooltipString(std::string str);
	bool isHit(sf::RenderWindow& window);
	const sf::Vector2f getPosition() { return _btnSprite.getPosition(); }
	sf::Vector2u getSize() { return _btnTexture.getSize(); }
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
