#ifndef MATCH
#define MATCH

#include <SFML/Graphics.hpp>
#include "board.hpp"

class Match
{
	private:
	sf::RenderWindow window;
	Board *board;

	public:
	Match();
	~Match();
	void play();
};

#endif
