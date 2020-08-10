#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false); // Hide cursor
	
	//load textures
	std::map<std::string, Mytexture> textures = loadTextures();

	//load sounds
	std::map<std::string, sf::SoundBuffer> sounds = loadSounds();

	//load fonts
	std::map<std::string, sf::Font> fonts = loadFonts();

	//create monster
	Monster monster(textures, sounds, fonts);

	//create player
	Player player(textures);

	//set the position to the center of the screen
	monster.setPosition((SCREEN_WIDTH - monster.getFrameWidth()) / 2, (SCREEN_HEIGHT - monster.getFrameWidth()) / 2);

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
					player.dealDmg(&monster);
				}
			}
		}

		monster.nextFrame();
		monster.nextMob();

		//DRAW EVERYTHING
		window.clear();
		monster.draw(&window);
		player.drawCursor(&window, &monster);
		window.display();
	}

	return 0;
}