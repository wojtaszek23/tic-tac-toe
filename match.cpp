#include "match.hpp"

	Match :: Match()
	{
		window.create (sf::VideoMode(640,480), "Tic Tac Toe",sf::Style::Close);
        	window.clear (sf::Color(64, 64, 64, 255));
		board = new Board(&window, 640, 480);
		play();
	}

	Match :: ~Match()
	{
		if(board)
		delete board;
		board=NULL;
	}


	void Match :: play()
	{
		sf::Event event;
		while(window.isOpen())
		{
			window.display();
			while(window.pollEvent(event))
			{
				if(event.type == sf::Event::MouseButtonPressed)
				{
					if(board->winner=='?')
					board->check_field(sf::Mouse::getPosition(window));
					else
					{
						delete board;
						board= new Board(&window, 640, 480);
					};
				}				
				if(event.type == sf::Event::Closed)
				{			
					window.close();
				}
			}		
		}
	}
	

