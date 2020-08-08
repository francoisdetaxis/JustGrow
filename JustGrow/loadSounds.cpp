#include "loadSounds.h"


std::map<std::string, sf::SoundBuffer> loadSounds()
{
	sf::SoundBuffer hitSound1;
	if (!hitSound1.loadFromFile("./resources/sound/hit_sound.wav"))
	{
		//TODO handle error
	}
	std::map<std::string, sf::SoundBuffer> sounds = {
		{"hitSound1", hitSound1}
	};
	return sounds;
}