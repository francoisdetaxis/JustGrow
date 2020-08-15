#include "main.h"
extern bool isLoading;

void displayLoadingScreen(sf::RenderWindow* window)
{
	window->setActive(true);

	sf::Texture loadingScreenTexture;
	sf::Sprite loadingScreenSprite;
    loadingScreenTexture.loadFromFile("./resources/image/loading.png");
	loadingScreenSprite.setTexture(loadingScreenTexture);
	while (isLoading)
	{
		window->clear();
		window->draw(loadingScreenSprite);
		window->display();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	window->setActive(false);
}