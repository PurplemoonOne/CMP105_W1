#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect_two.setSize(sf::Vector2f(100, 100));
	
	rect_two.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setOutlineColor(sf::Color::Red);
	circle.setPosition(100, 100);

	if (!font.loadFromFile("font/ariel.tff"))
	{
		
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(10);
	text.setFillColor(sf::Color::Blue);
	text.setOrigin(200, 200);
	text.setStyle(sf::Text::Bold | sf::Text::Italic);

	texture.loadFromFile("RonSwanson.png");
	sprite.setTexture(texture);
	
	 incriment = sf::Vector2i(2, 2);

}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u position = window->getSize();
	
	rect_two.setPosition(position.x - 100, position.y - 100);
	
	MoveShape();
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(rect);
	window->draw(circle);
	window->draw(text);
	window->draw(rect_two);
	window->draw(sprite);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));

	
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	
	window->display();
}

void Level::MoveShape()
{

	if ((sprite.getPosition().x > window->getSize().x)  && 
		incriment.x > 0 || 
		(sprite.getPosition().x < 0 && incriment.x < 0))
	{
		int r, g, b, a;
		r = rand() % 255 + 1;
		g = rand() % 255 + 1;
		b = rand() % 255 + 1;
		a = 255;
		
		sprite.setColor(sf::Color(r, g, b, a));

		incriment.x = -incriment.x;
	}

	if ((sprite.getPosition().y > window->getSize().y)  &&
		incriment.y > 0 ||
		(sprite.getPosition().y < 0 && incriment.y < 0))
	{

		int r, g, b, a;
		r = rand() % 255 + 1;
		g = rand() % 255 + 1;
		b = rand() % 255 + 1;
		a = 255;

		sprite.setColor(sf::Color(r, g, b, a));

		incriment.y = -incriment.y;
	}

	sprite.setPosition(sprite.getPosition().x + incriment.x, sprite.getPosition().y + incriment.y);
	window->draw(sprite);
}