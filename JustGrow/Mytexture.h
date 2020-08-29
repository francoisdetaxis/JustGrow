#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Mytexture
{
public:
	//constructors
	Mytexture::Mytexture();
	Mytexture::~Mytexture();
	Mytexture::Mytexture(std::string path, int framesNb);
	//getters
	int Mytexture::getFramesNb() { return _framesNb; }
	sf::Texture& Mytexture::getTexture() { return _texture; }

private:
	sf::Texture _texture;
	int _framesNb;
};
