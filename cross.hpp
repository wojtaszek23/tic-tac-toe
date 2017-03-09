#ifndef CROSS
#define CROSS

#include <SFML/Graphics.hpp>
#include "figure.hpp"

class Cross : public Figure
{
	public:
	void draw(sf::RenderWindow *window, int x, int y, int width, int height)
	{
		sf::RectangleShape line(sf::Vector2f(width, 7));
		line.setFillColor(sf::Color::Green);
		line.rotate(45*height/width);
		line.setPosition(x+width*0.1,y+height*0.1);
		window->draw(line);

		sf::RectangleShape line2(sf::Vector2f(width, 7));
		line2.setFillColor(sf::Color::Green);
		line2.rotate(-45*height/width);
		line2.setPosition(x+width*0.05,y+height*0.85);
		window->draw(line2);
	}
};

#endif
