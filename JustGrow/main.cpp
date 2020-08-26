#include "main.h"
bool isLoading = true;

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false); // Hide cursor
	window.setActive(false);

	sf::Sprite test;

	//loading screen in a separate thread
	std::thread loadingScreenThread(displayLoadingScreen, &window);

	//displayDragon(&window);

	//load textures
	std::map<std::string, Mytexture> textures = loadTextures();

	//load sounds
	std::map<std::string, sf::SoundBuffer> sounds = loadSounds();

	//load fonts
	std::map<std::string, sf::Font> fonts = loadFonts();

	//create monster
	Monster monster(textures, sounds, fonts);

	//create player
	Player player(textures, fonts);

	//create menu
	Menu menu(&textures);

	//create Buttons
	Button btnclickUpgrade(textures["clickUpgrade"].getTexture());
	Button btnFace(textures["face"].getTexture());
	btnclickUpgrade.setPosition(50, 50);
	btnFace.setPosition(50, btnclickUpgrade.getTexture().getSize().y + 50 + 20);

	//add buttons to the menu
	menu.addButton(&btnclickUpgrade);
	menu.addButton(&btnFace);

	//monster to the RIGHT
	monster.setPosition((SCREEN_WIDTH - monster.getMonsterFrameWidth()) - 50, (SCREEN_HEIGHT - monster.getMonsterFrameHeight()) / 2);
	//centered monster
	//monster.setPosition((SCREEN_WIDTH - monster.getMonsterFrameWidth()) / 2, (SCREEN_HEIGHT - monster.getMonsterFrameHeight()) / 2);

	// synchronize threads:
	window.setActive(true);

	isLoading = false;
	loadingScreenThread.join();

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

		//DRAW EVERYTHING
		window.clear();
		menu.draw(window);
		monster.draw(&window);
		player.drawCursor(&window, &monster);
		player.drawDmg(&window);
		window.display();
	}

	return 0;
}