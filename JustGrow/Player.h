#pragma once

class Player
{
public:
	Player::Player(std::map<std::string, sf::Texture> textures);
	void drawCursor(sf::RenderWindow* window, Monster* monster);
	void dealDmg(Monster* monster);
private:
	std::map<std::string, sf::Texture> a_textures;
	sf::Texture a_attackCursorTexture;
	sf::Texture a_handCursorTexture;
	sf::Sprite a_attackCursorSprite;
	sf::Sprite a_handCursorSprite;
	int a_dmg;

};

