#include "main.h"

Mytexture::Mytexture()
{
	//a_framesNb = 1;
	//a_texture.loadFromFile(".\resources\image\sprites");
}

Mytexture::~Mytexture()
{

}

Mytexture::Mytexture(std::string path, int framesNb)
{
	a_framesNb = framesNb;
	a_texture.loadFromFile(path);

}

int Mytexture::getFramesNb()
{
	return a_framesNb;
}

sf::Texture Mytexture::getTexture()
{
	return a_texture;
}



