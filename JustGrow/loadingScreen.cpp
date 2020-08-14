#include "main.h"
extern bool isLoading;

void displayLoadingScreen(sf::RenderWindow* window)
{
	//TODO FIX
	sf::Context context;
	context.setActive(true);
	//sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JustGrow", sf::Style::Fullscreen);
	//window.setMouseCursorVisible(false); // Hide cursor
	//DRAGON ANIMATION
	sf::Texture loadingScreenTexture;
	sf::Sprite loadingScreenSprite;
    loadingScreenTexture.loadFromFile("./resources/image/loading.png");
	loadingScreenSprite.setTexture(loadingScreenTexture);
	while (isLoading)
	{
		window->clear();
		window->draw(loadingScreenSprite);
		window->display();
	}
}