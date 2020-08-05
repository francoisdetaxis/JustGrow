#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::Fullscreen);
	Monster monster;
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
				}
			}

		}
		if (monster.getClockTime() > 50) {
			monster.restartclock();
			monster.nextFrame();

			if (monster.getRect().left >= monster.getMaxLeft()) {
				monster.resetRect();
			}
			else
				monster.nextFrame();
		}

		window.clear();
		window.draw(monster.getHitboxShape());
		window.draw(monster.getSprite());
		window.display();
	}

	return 0;
}
