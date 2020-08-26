#include "main.h"
bool isLoading = true;

int main(int argc, char* argv[])
{
	//SET TO TRUE TO DRAW ADDITIONAL STUFF
	bool debug = true;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::None);
	window.setMouseCursorVisible(false);
	window.setActive(false);

	//loading screen in a separate thread
	std::thread loadingScreenThread(displayLoadingScreen, &window);

	//load textures
	std::map<std::string, Mytexture> textures = loadTextures();

	//load sounds
	std::map<std::string, sf::SoundBuffer> sounds = loadSounds();

	//load fonts
	std::map<std::string, sf::Font> fonts = loadFonts();

	//create monster (set scale BEFORE set position...TODO fix this behaviour so that it works either way)
	Monster monster(&textures, &sounds, &fonts);
	monster.setScale(0.5, 0.5);

	//create player
	Player player(&textures, &fonts);

	//centered monster
	monster.setPosition((SCREEN_WIDTH - monster.getMonsterWidth()) / 2, (SCREEN_HEIGHT - monster.getMonsterHeight()) / 2);

	//Stage
	Stage stage(&textures);
	//all of this just to place the platform behind the monster...
	int centeredX, centeredY, offsetY, monsterHeight, monsterWidth;
	monsterWidth = monster.getMonsterWidth();
	monsterHeight = monster.getMonsterHeight();
	centeredX = monster.getPosition().x + (((float)monsterWidth - (float)stage.getSize().x) / 2);
	centeredY = monster.getPosition().y + (((float)monsterHeight - (float)stage.getSize().y) / 2);
	offsetY = 0.2 * monsterHeight;
	stage.setPosition(centeredX, centeredY + offsetY);

	// synchronize threads:
	window.setActive(true);

	//loading is finished --> set the global variable to indicate to the other thread that loading is done.
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

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Q)
					stage.next(&monster);
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left && monster.isHit(&window))
				{
					monster.playHitSound();
					player.dealDmg(&monster);
				}
			}
		}
		//monster animation
		monster.nextFrame();
		//DRAW EVERYTHING
		window.clear();
		stage.draw(&window, debug);
		monster.draw(&window, debug);
		player.drawCursor(&window, &monster);
		player.drawDmg(&window);
		window.display();
	}
	return 0;
}