#pragma once

class Mytexture
{
public:
	//constructor
	Mytexture();
	~Mytexture();
	Mytexture(std::string path, int framesNb);
	//getters
	int getFramesNb();
	sf::Texture getTexture();

private:
	//attributes
	sf::Texture a_texture;
	int a_framesNb;
};

