#ifndef CIRCLE
#define CIRCLE

#include <SFML/Graphics.hpp>
#include "figure.hpp"

class Circle : public Figure
{
	public:
	void draw(sf::RenderWindow *window, int x, int y, int width, int height)
	{
		int radius=height;
		if(height>width)
		radius=width;
		radius*=0.4;
		sf::CircleShape circle(radius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(-7);
		circle.setOutlineColor(sf::Color::Blue);
		circle.setPosition(x+(width-radius)/3.5,y+(height-radius)/5.5);
		window->draw(circle);
	}
};

#endif
