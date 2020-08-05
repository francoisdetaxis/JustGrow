#include "All.h"
#include "main.h"


void All::setTexture(sf::Texture texture)
{
	a_texture = texture;
}

sf::Texture All::getTexture(void)
{
	return a_texture;
}
All::All(sf::Texture texture)
{
	a_texture = texture;
}

