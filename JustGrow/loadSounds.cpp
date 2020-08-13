#include "main.h"

std::map<std::string, sf::SoundBuffer> loadSounds()
{
	sf::SoundBuffer hit1;
	sf::SoundBuffer hit2;
	sf::SoundBuffer hit3;
	sf::SoundBuffer coin_pickup1;

	hit1.loadFromFile("./resources/sound/hit_1.wav");
	hit2.loadFromFile("./resources/sound/hit_2.wav");
	hit3.loadFromFile("./resources/sound/hit_3.wav");
	coin_pickup1.loadFromFile("./resources/sound/coin_pickup1.wav");

	std::map<std::string, sf::SoundBuffer> sounds = {
		{"hit1", hit1},
		{"hit2", hit2},
		{"hit3", hit3},
		{"coin_pickup1", coin_pickup1}
	};
	return sounds;
}