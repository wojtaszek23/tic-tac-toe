#ifndef FIGURE
#define FIGURE

#include <SFML/Graphics.hpp>

class Figure
{
	public:
	virtual void draw(sf::RenderWindow *window, int x, int y, int width, int height)=0;
};




#endif
