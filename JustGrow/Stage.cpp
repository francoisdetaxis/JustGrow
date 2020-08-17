#include "main.h"

Stage::Stage(std::map<std::string, Mytexture>* textures)
{
	_currentLevel = 1;
	_currentStage = 1;
	_textures = textures;
	_currentPlatform = (*textures)["platform6"];
	_currentPlatformSprite.setTexture(*_currentPlatform.getTexture());
}