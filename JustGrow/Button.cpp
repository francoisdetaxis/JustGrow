#include "Button.h"

Button::Button()
{
	//btn texture
	sf::Texture texture;
	texture.loadFromFile("./resources/image/error.png");
	_btnTexture = texture;

	//text
	_text.setColor(sf::Color::Green);
	_text.setString("UNINITIALIZED");

	//btn rect
	_btnRect.top = 0;
	_btnRect.left = 0;
	_btnRect.height = _btnTexture.getSize().y;
	_btnRect.width = _btnTexture.getSize().x;

	//btn sprite
	_btnSprite.setTexture(_btnTexture);
	_btnSprite.setTextureRect(_btnRect);

	//btn shape
	_btnShape.setFillColor(sf::Color::Transparent);
	_btnShape.setOutlineColor(sf::Color::Cyan);
	_btnShape.setOutlineThickness(5.f);
	this->updateShape();

	//MOUSE IS NOT HOVERING OVER THE BUTTON...
	_isMouseAlreadyOverButton = false;
}

Button::Button(sf::Texture& btnTexture, std::map<std::string, sf::Font>& fonts)
{
	_fonts = fonts;

	//btn texture
	_btnTexture = btnTexture;

	//text
	_text.setFont(fonts["dmgFont"]);
	_text.setColor(sf::Color::Green);
	_text.setString("UNINITIALIZED");

	//tooltip
	_tooltip.setFont(fonts["dmgFont"]);
	_tooltip.setColor(sf::Color::Green);
	_tooltip.setString("UNINITIALIZED");
	_tooltip.setPosition(_btnTexture.getSize().x + 25, 0);

	//btn rect
	_btnRect.top = 0;
	_btnRect.left = 0;
	_btnRect.height = _btnTexture.getSize().y;
	_btnRect.width = _btnTexture.getSize().x;

	//btn sprite
	_btnSprite.setTexture(_btnTexture);
	_btnSprite.setTextureRect(_btnRect);

	//btn shape
	_btnShape.setFillColor(sf::Color::Transparent);
	_btnShape.setOutlineColor(sf::Color::Cyan);
	_btnShape.setOutlineThickness(5.f);
	this->updateShape();

	//MOUSE IS NOT HOVERING OVER THE BUTTON...
	_isMouseAlreadyOverButton = false;
}

Button::Button(sf::Texture& btnTexture)
{
	//btn texture
	_btnTexture = btnTexture;

	//btn rect
	_btnRect.top = 0;
	_btnRect.left = 0;
	_btnRect.height = _btnTexture.getSize().y;
	_btnRect.width = _btnTexture.getSize().x;

	//btn sprite
	_btnSprite.setTexture(_btnTexture);
	_btnSprite.setTextureRect(_btnRect);

	//btn shape
	_btnShape.setFillColor(sf::Color::Transparent);
	_btnShape.setOutlineColor(sf::Color::Cyan);
	_btnShape.setOutlineThickness(5.f);
	this->updateShape();

	//MOUSE IS NOT HOVERING OVER THE BUTTON...
	_isMouseAlreadyOverButton = false;
}

void Button::move(int x, int y)
{
	_btnSprite.move(x, y);
	_btnShape.move(x, y);
	_tooltip.move(x, y);
	_text.move(x, y);
	_btnRect.left = _btnShape.getPosition().x;
	_btnRect.top = _btnShape.getPosition().y;
}

void Button::draw(sf::RenderWindow& window)
{
	if (this->isHit(window) && !_isMouseAlreadyOverButton)
	{
		_btnShape.setFillColor(sf::Color(255, 0, 0, 125));
		_isMouseAlreadyOverButton = true;
	}
	else if (!this->isHit(window) && _isMouseAlreadyOverButton)
	{
		_btnShape.setFillColor(sf::Color::Transparent);
		_isMouseAlreadyOverButton = false;
	}
	window.draw(_btnSprite);
	window.draw(_btnShape);
	window.draw(_text);
	window.draw(_tooltip);
}

bool Button::isHit(sf::RenderWindow& window)
{
	return _btnRect.contains(sf::Mouse::getPosition(window));
}

//update shape position and size
void Button::updateShape()
{
	_btnShape.setPosition(_btnSprite.getPosition().x, _btnSprite.getPosition().y);
	_btnShape.setSize(sf::Vector2f(_btnTexture.getSize().x, _btnTexture.getSize().y));
}

void Button::setTexture(sf::Texture& texture)
{
	_btnTexture = texture;

	//btn rect
	_btnRect.top = _btnSprite.getPosition().y;
	_btnRect.left = _btnSprite.getPosition().x;
	_btnRect.height = _btnTexture.getSize().y;
	_btnRect.width = _btnTexture.getSize().x;

	//btn sprite
	_btnSprite.setTexture(_btnTexture);

	//btn shape
	this->updateShape();
}

void Button::setPosition(int x, int y)
{
	_btnSprite.setPosition(x, y);
	_btnShape.setPosition(x, y);
	_text.setPosition(x, y);
	_tooltip.setPosition(x + _btnTexture.getSize().x + 25, y);
	_btnRect.top = y;
	_btnRect.left = x;
}

void Button::setTextString(std::string str)
{
	_text.setString(str);
}

void Button::setTooltipString(std::string str)
{
	_tooltip.setString(str);
}