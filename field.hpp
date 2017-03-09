#ifndef FIELD
#define FIELD

#include <SFML/Graphics.hpp>
#include "figure.hpp"
#include "circle.hpp"
#include "cross.hpp"

class Field
{
	private:
	int x;
	int y;
	int width;
	int height;
	Figure *figure;
	void draw_frame(sf::RenderWindow *window);

	public:
	char mark;
	sf::Vector2f center;	
	Field();
	~Field();
	void make_frame(sf::RenderWindow *window, int edge_x, int edge_y, int j, int i, int w, int h);
	bool check_field(sf::Vector2f pos);
	void set_figure(sf::RenderWindow *window, char new_mark);

};

#endif
