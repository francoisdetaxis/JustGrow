#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!", sf::Style::Fullscreen);
	sf::Sprite sprite;
	sf::IntRect rect1;
	sf::IntRect hitbox;
	sf::Clock clock;
	sf::Vector2i mouseposi;
	sf::Vector2f mouseposf;
	rect1.left = 0;
	rect1.top = 0;
	rect1.height = 660;
	rect1.width = 660;
	hitbox = rect1;

	All all();

	std::string wesh = "./resources/image/running_man.png";

	if (!all.setTexture(wesh))
	{
		//TODO handle error
		return -1;
	}
	int kekchose = 150;

	sf::SoundBuffer buffer;
	// load something into the sound buffer...
	if (!buffer.loadFromFile("./resources/sound/hit_sound.wav"))
		return -1;
	sf::Sound sound;
	sound.setBuffer(buffer);

	sprite.setPosition((SCREEN_WIDTH / 2) - kekchose, ((SCREEN_HEIGHT / 2) - kekchose));
	hitbox.top = (SCREEN_HEIGHT / 2) - kekchose;
	hitbox.left = (SCREEN_WIDTH / 2) - kekchose;
	sprite.setTexture(all.getTexture());


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
				if (event.mouseButton.button == sf::Mouse::Left && hitbox.contains(sf::Mouse::getPosition(window)))
				{
					sound.play();
				}

			}


		}
		mouseposi = sf::Mouse::getPosition();
		sprite.setTextureRect(rect1);
		if (clock.getElapsedTime().asMilliseconds() > 50) {
			clock.restart();
			if (rect1.left >= 9240) {
				rect1.left = 0;
			}
			else
				rect1.left += 660;
		}


		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}