#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//using namespace sf;
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{


	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!", sf::Style::Fullscreen);
	sf::CircleShape shape(100.f);
	sf::Texture texture;


	if (!texture.loadFromFile("./resources/Idle/idle_sprite.png"))
	{
		//TODO handle error
		return -1;
	}

	//texture.setRepeated(true);


	sf::Sprite sprite;
	sprite.setTexture(texture);
	//sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);





	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				shape.setFillColor(sf::Color::Red);
			}
			else {
				shape.setFillColor(sf::Color::Green);
			}



		}

		window.clear();

		window.draw(sprite);
		//window.draw(shape);
		window.display();
	}

	return 0;
}