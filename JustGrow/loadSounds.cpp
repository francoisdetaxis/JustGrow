#include "loadSounds.h"

std::map<std::string, sf::SoundBuffer> loadSounds()
{
	sf::SoundBuffer hit1;
	sf::SoundBuffer hit2;
	sf::SoundBuffer hit3;
	sf::SoundBuffer coin_pickup;
	sf::SoundBuffer monster1_dying;

	hit1.loadFromFile("./resources/sound/hit_1.wav");
	hit2.loadFromFile("./resources/sound/hit_2.wav");
	hit3.loadFromFile("./resources/sound/hit_3.wav");
	coin_pickup.loadFromFile("./resources/sound/coin_pickup.wav");
	monster1_dying.loadFromFile("./resources/sound/wilhem.wav");

	std::map<std::string, sf::SoundBuffer> sounds = {
		{"hit1", hit1},
		{"hit2", hit2},
		{"hit3", hit3},
		{"monster1_dying", monster1_dying},
		{"coin_pickup", coin_pickup}
	};
	return sounds;
}