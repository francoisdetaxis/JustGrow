#include "main.h"
#include "loadingScreen.h"
extern bool isLoading;

void displayLoadingScreen(sf::RenderWindow* window)
{
	window->setActive(true);

	sf::Texture loadingScreenTexture;
	sf::Sprite loadingScreenSprite;
	loadingScreenTexture.loadFromFile("./resources/image/loadingScreen.png");
	loadingScreenSprite.setTexture(loadingScreenTexture);
	loadingScreenSprite.setPosition((SCREEN_WIDTH - loadingScreenTexture.getSize().x) / 2, (SCREEN_HEIGHT - loadingScreenTexture.getSize().y) / 2);
	while (isLoading)
	{
		window->clear();
		window->draw(loadingScreenSprite);
		window->display();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	window->setActive(false);
}