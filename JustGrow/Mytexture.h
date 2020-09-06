#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Mytexture
{
public:
	//constructors
	Mytexture();
	~Mytexture();
	Mytexture(std::string path, int framesNb);
	//getters
	int getFramesNb() { return _framesNb; }
	sf::Texture& getTexture() { return _texture; }

private:
	sf::Texture _texture;
	int _framesNb;
};
