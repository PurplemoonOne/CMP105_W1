#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();

	void MoveShape();
	sf::RenderWindow* window;

	
	sf::RectangleShape rect;
	sf::RectangleShape rect_two;
	sf::CircleShape circle;

	sf::Font font;
	sf::Text text;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2i incriment;
};