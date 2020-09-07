#include "main.h"
bool isLoading = true;

int main(int argc, char* argv[])
{
	BigNumber a(6.00, 10);
	BigNumber b(2.00, 0);
	BigNumber result;
	result = a / b;
	//a *= b;
	//std::cout << a.asString() << std::endl;
	std::cout << a.asString() << " / " << b.asString() << " = " << result.asString() << std::endl;

	return 0;
	//SET TO TRUE TO DRAW ADDITIONAL STUFF
	bool debug = true;

	//background music...
	sf::Music music;
	music.openFromFile("./resources/sound/maintheme.wav");
	music.play();

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

	//backgorund sprite...
	sf::Sprite background;
	background.setTexture(textures["background"].getTexture());

	//create monster (set scale BEFORE set position...TODO fix this behaviour so that it works either way)
	Monster monster(textures, sounds, fonts);
	monster.setScale(0.5, 0.5);

	//create player
	Player player(textures, fonts);

	//create menu
	Menu menu(textures, fonts);

	//Stage
	Stage stage(textures, fonts);

	//create Buttons...
	Button btnclickUpgrade(textures["clickUpgrade"].getTexture(), fonts);
	btnclickUpgrade.setTextString("LVL UP\n" + std::to_string(player.getClickCost()));
	btnclickUpgrade.setTooltipString("DMG: " + std::to_string(player.getClickDmg()));

	Button btnFace(textures["face"].getTexture(), fonts);
	btnclickUpgrade.setPosition(50, 50);
	btnFace.setPosition(50, btnclickUpgrade.getTexture().getSize().y + 50 + 20);

	Button btnSound(textures["sound"].getTexture());
	btnSound.setPosition(SCREEN_WIDTH - btnSound.getSize().x - 50, SCREEN_HEIGHT - btnSound.getSize().y - 50);

	//add buttons to the menu
	menu.addButton(&btnclickUpgrade);
	menu.addButton(&btnFace);

	//position monster
	monster.setPosition((SCREEN_WIDTH / 2) + (((SCREEN_WIDTH / 2) - monster.getMonsterWidth()) / 2), (SCREEN_HEIGHT - monster.getMonsterHeight()) / 2);

	//create gold
	Gold gold(textures, fonts, sounds, menu);

	//position menu
	menu.move(0, (SCREEN_HEIGHT - menu.getSize().y) / 2);
	gold.move(0, (SCREEN_HEIGHT - menu.getSize().y) / 2);

	//all of this just to place the platform behind the monster...
	int centeredX, centeredY, offsetY, monsterHeight, monsterWidth;
	monsterWidth = monster.getMonsterWidth();
	monsterHeight = monster.getMonsterHeight();
	centeredX = monster.getPosition().x + (((float)monsterWidth - (float)stage.getSize().x) / 2);
	centeredY = monster.getPosition().y + (((float)monsterHeight - (float)stage.getSize().y) / 2);
	offsetY = 0.2 * monsterHeight;
	stage.setPosition(centeredX, centeredY + offsetY, monster);

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
				if (event.key.code == sf::Keyboard::Q && debug)
					stage.nextPlatform(monster);
				if (event.key.code == sf::Keyboard::A && debug)
					player.cheat(monster);
				if (event.key.code == sf::Keyboard::W && debug)
					stage.nextStage(monster, gold, player);
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left && monster.isHit(window))
				{
					monster.playHitSound();
					player.dealDmg(monster);
				}
				if (event.mouseButton.button == sf::Mouse::Left && btnclickUpgrade.isHit(window))
				{
					player.clickUpgrade(gold, btnclickUpgrade);
				}
				if (event.mouseButton.button == sf::Mouse::Left && btnSound.isHit(window))
				{
					if (music.getStatus() == music.Paused)
					{
						music.play();
						btnSound.setTexture(textures["sound"].getTexture());
					}
					else
					{
						music.pause();
						btnSound.setTexture(textures["muteSound"].getTexture());
					}
				}
			}
		}
		//monster animation
		monster.nextFrame(stage, gold, player);

		//DRAW EVERYTHING
		window.clear();
		window.draw(background);
		menu.draw(window);
		stage.draw(window, monster, debug);
		monster.draw(window, debug);
		gold.draw(window);
		player.drawCursor(window, monster);
		player.drawDmg(window);
		btnSound.draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}