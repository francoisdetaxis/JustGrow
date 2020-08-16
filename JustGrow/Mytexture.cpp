#include "main.h"

Mytexture::Mytexture()
{
	//DO NOT REMOVE
}

Mytexture::~Mytexture()
{
	//DO NOT REMOVE
}

Mytexture::Mytexture(std::string path, int framesNb)
{
	_framesNb = framesNb;
	_texture.loadFromFile(path);
}