#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
//using namespace sf;
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{
	//grosse salope

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!", sf::Style::Fullscreen);
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect rect1;
	sf::Clock clock;
	sf::Music music;
	rect1.left = 0;
	rect1.top = 0;
	rect1.height = 660;
	rect1.width = 660;
	
	if (!texture.loadFromFile("./resources/image/running_man.png"))
	{
		//TODO handle error
		return -1;
	}
	int kekchose = 150;

	if (!music.openFromFile("music.ogg"))
		return -1; // error

	sprite.setPosition((SCREEN_WIDTH / 2) - kekchose, ((SCREEN_HEIGHT / 2) - kekchose));
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
				
			}




		}

		sprite.setTextureRect(rect1);
		if (clock.getElapsedTime().asMilliseconds() > 50) {
			clock.restart();
			if (rect1.left > 9240){
				rect1.left = 0;
			} else 
				rect1.left += 660;
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}