#pragma once

class Mytexture
{
public:
	//constructor
	Mytexture();
	~Mytexture();
	Mytexture(std::string path, int framesNb);
	//getters
	int getFramesNb() { return _framesNb; }
	sf::Texture& getTexture() { return _texture; }

private:
	//attributes
	sf::Texture _texture;
	int _framesNb;
};
