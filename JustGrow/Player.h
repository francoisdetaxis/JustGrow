#pragma once
#include <queue>

class Player
{
public:
	//Player(std::deque<Mytexture> textures, std::map<std::string, sf::Font> fonts);
	Player(std::map<std::string, Mytexture>* textures, std::map<std::string, sf::Font>* fonts);
	void drawCursor(sf::RenderWindow* window, Monster* monster);
	void dealDmg(Monster* monster);
	void drawDmg(sf::RenderWindow* window);
private:
	//std::deque<Mytexture> a_textures;
	std::map<std::string, Mytexture>* _textures;
	std::map<std::string, sf::Font>* _fonts;
	Mytexture _attackCursor;
	Mytexture _handCursor;
	sf::Sprite _attackCursorSprite;
	sf::Sprite _handCursorSprite;
	sf::Font _dmgFont;
	//sf::Text a_dmgText;
	//sf::Clock a_dmgClock;
	std::deque<sf::Clock> _dmgClocks;
	std::deque<sf::Text> _dmgTexts;
	int _dmg;
	int _critChance;
	int _critMultiplier;
};
