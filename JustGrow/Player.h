#pragma once

class Player
{
public:
	Player(std::map<std::string, Mytexture> textures);
	void drawCursor(sf::RenderWindow* window, Monster* monster);
	void dealDmg(Monster* monster);
private:
	std::map<std::string, Mytexture> a_textures;
	sf::Texture a_attackCursorTexture;
	sf::Texture a_handCursorTexture;
	sf::Sprite a_attackCursorSprite;
	sf::Sprite a_handCursorSprite;
	int a_dmg;

};

