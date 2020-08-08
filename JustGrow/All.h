#pragma once
#include "main.h"

class All
{
public:
	All::All(sf::Texture texture);
	void setTexture(sf::Texture texture);
	sf::Texture getTexture(void);

private:

	sf::Texture a_texture;
	sf::Sprite a_sprite;
	sf::IntRect a_rect1;
	sf::IntRect a_hitbox;
	sf::Clock a_clock;
	sf::Vector2i a_mouseposi;
	sf::Vector2f a_mouseposf;
};
