#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::Fullscreen);

	//load textures
	std::map<std::string, sf::Texture> textures = loadTextures();

	//load sounds
	std::map<std::string, sf::SoundBuffer> sounds = loadSounds();

	//load fonts
	std::map<std::string, sf::Font> fonts = loadFonts();

	Monster monster(textures, sounds, fonts);
	//set the position to the center of the screen
	monster.setPosition((SCREEN_WIDTH - monster.getFrameSize()) / 2, (SCREEN_HEIGHT - monster.getFrameSize()) / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left && monster.isHit(&window))
				{
					monster.playSound();
					monster.dealDmg();
				}
			}
		}

		monster.nextFrame();
		monster.nextMob();

		//DRAW EVERYTHING
		window.clear();
		monster.draw(&window);
		window.display();
	}

	return 0;
}