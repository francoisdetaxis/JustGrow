#include "dragon.h"

void displayDragon(sf::RenderWindow& window)
{
	//DRAGON ANIMATION
	sf::Texture dragonTexture;
	sf::Sprite dragonSprite;
	sf::IntRect rect;
	sf::Clock clock;
	rect.left = 0;
	rect.top = 0;
	rect.width = 1306;
	rect.height = 882;
	dragonTexture.loadFromFile("./resources/image/sprites/dragon_sprite.png");
	dragonSprite.setTexture(dragonTexture);
	dragonSprite.setTextureRect(rect);
	bool isLoading = true;
	while (isLoading)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				isLoading = false;
		}
		if (clock.getElapsedTime().asMilliseconds() > 100) {
			clock.restart();

			if (rect.left >= 13640) {
				//end of the sprite is reached
				rect.left = 0;
			}
			else {
				//there are still frames to go on the sprite
				dragonSprite.setTextureRect(rect);
				rect.left += 1364;
			}
		}
		window.clear();
		window.draw(dragonSprite);
		window.display();
	}
}