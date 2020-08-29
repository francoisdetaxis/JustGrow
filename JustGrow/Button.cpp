#include "Button.h"

Button::Button()
{
	//btn texture
	sf::Texture texture;
	texture.loadFromFile("./resources/image/error.png");
	_btnTexture = texture;

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

	//menu rect
	_btnRect.top = 0;
	_btnRect.left = 0;
	_btnRect.height = _btnTexture.getSize().y;
	_btnRect.width = _btnTexture.getSize().x;

	//menu sprite
	_btnSprite.setTexture(_btnTexture);
	_btnSprite.setTextureRect(_btnRect);

	//btn shape
	this->updateShape();
}

void Button::setPosition(int x, int y)
{
	_btnSprite.setPosition(x, y);
	_btnShape.setPosition(x, y);
	_btnRect.top = y;
	_btnRect.left = x;
}