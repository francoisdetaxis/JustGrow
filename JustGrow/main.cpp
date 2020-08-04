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
	sf::IntRect hitbox;
	sf::RectangleShape rectangle;
	sf::Clock clock;
	//sf::Music music;
	sf::Vector2i mouseposi;
	sf::Vector2f mouseposf;
	rect1.left = 0;
	rect1.top = 0;
	rect1.height = 660;
	rect1.width = 660;
	hitbox = rect1;


	if (!texture.loadFromFile("./resources/image/running_man.png"))
	{
		//TODO handle error
		return -1;
	}
	int kekchose = 150;

	//if (!music.openFromFile("./resources/sound/hit_sound.wav"))
	//{
	//	//TODO handle error
	//	return -1;
	//}

	sf::SoundBuffer buffer;
	// load something into the sound buffer...
	if (!buffer.loadFromFile("./resources/sound/hit_sound.wav"))
		return -1;
	sf::Sound sound;
	sound.setBuffer(buffer);

	sprite.setPosition((SCREEN_WIDTH / 2) - kekchose, ((SCREEN_HEIGHT / 2) - kekchose));
	hitbox.top = (SCREEN_HEIGHT / 2) - kekchose;
	hitbox.left = (SCREEN_WIDTH / 2) - kekchose;
	sprite.setTexture(texture);

	//rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(10);

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
				//mouseposf.x = mouseposi.x;
				//mouseposf.y = mouseposi.y;
				//if (sf::Event::MouseButtonReleased(sf::Mouse::Button::Left))


			}




		}
		mouseposi = sf::Mouse::getPosition();
		rectangle.setPosition(hitbox.left, hitbox.top);
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