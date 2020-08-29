#pragma once

class Menu
{
public:
	Menu::Menu(std::map<std::string, Mytexture>& textures);
	void draw(sf::RenderWindow &window);
	void Menu::addButton(Button* btn);
	void move(int x, int y);
	sf::Vector2u getSize() { return _menuTexture.getSize(); }
private:
	int _scale;
	sf::IntRect _menuRect;
	sf::Texture _menuTexture;
	sf::Sprite _menuSprite;
	std::vector<Button*> _buttons;
};

