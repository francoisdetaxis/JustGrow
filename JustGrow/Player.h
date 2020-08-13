#pragma once
#include <queue>

class Player
{
public:
	//Player(std::deque<Mytexture> textures, std::map<std::string, sf::Font> fonts);
	Player(std::map<std::string, Mytexture> textures, std::map<std::string, sf::Font> fonts);
	void drawCursor(sf::RenderWindow* window, Monster* monster);
	void dealDmg(Monster* monster);
	void drawDmg(sf::RenderWindow* window);
private:
	//std::deque<Mytexture> a_textures;
	std::map<std::string, Mytexture> a_textures;
	std::map<std::string, sf::Font> a_fonts;
	sf::Texture a_attackCursorTexture;
	sf::Texture a_handCursorTexture;
	sf::Sprite a_attackCursorSprite;
	sf::Sprite a_handCursorSprite;
	sf::Font a_dmgFont;
	//sf::Text a_dmgText;
	//sf::Clock a_dmgClock;
	std::deque<sf::Clock> a_dmgClocks;
	std::deque<sf::Text> a_dmgTexts;
	int a_dmg;
	int a_critChance;
	int a_critMultiplier;

};

