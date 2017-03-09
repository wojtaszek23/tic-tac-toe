#ifndef BOARD
#define BOARD

#include <SFML/Graphics.hpp>
#include <cmath>
#include "field.hpp"
#include <string>

class Board
{
	private:
	int edge_x;
	int edge_y;
	int width;
	int height;
	sf::RenderWindow *window;
	Field *field[3][3];
	sf::Font font;
	sf::Text text;
	public:
	char mark;
	char winner;
	
	Board(sf::RenderWindow* wnd, int x, int y);
	~Board();
	void draw_board();
	void check_field(sf::Vector2i pos_i);
	void check_winner();
};

#endif
