#include "board.hpp"

	Board::Board(sf::RenderWindow* wnd, int x, int y): window(wnd), width(x), height(y)
	{
		winner='?';
		mark='x';
		draw_board();
	}

	Board :: ~Board()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(field[i][j])
				delete field[i][j];
				field[i][j]=NULL;
			}
		}
		//window->clear(sf::Color(64, 64, 64, 255));
	}

	void Board::draw_board()
	{
		edge_x=width/10;
		edge_y=height/10;
		int w=(width-2*edge_x)/3;
		int h=(height-2*edge_y)/3;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				field[i][j]=new Field();
				field[i][j]->make_frame(window, edge_x, edge_y, j, i, w, h);
			}
		}
		window->display();
	}

	void Board :: check_field(sf::Vector2i pos_i)
	{
		sf::Vector2f pos;
		pos.x=int(pos_i.x);
		pos.y=int(pos_i.y);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(field[i][j]->check_field(pos))
				{
					field[i][j]->set_figure(window, mark);
					check_winner();					
					j=i=3;
					if(mark=='x')
					{ mark='o'; }
					else
					{ mark='x'; };
					break;
				}
			}
		}
	}

	void Board :: check_winner()
	{
		for(int i=0;i<3;i++)
		{ 
			if( (field[i][0]->mark==mark) && (field[i][1]->mark==mark) && (field[i][2]->mark==mark) )
			{
				sf::RectangleShape line(sf::Vector2f(field[i][2]->center.x-field[i][0]->center.x, 1));
				line.setFillColor(sf::Color::Red);
				line.setPosition(field[i][0]->center);
				line.setOutlineColor(sf::Color::Red);
				line.setOutlineThickness(5);
				window->draw(line);
				winner=mark;
				return;
			}

			else if( (field[0][i]->mark==mark) && (field[1][i]->mark==mark) && (field[2][i]->mark==mark) )
			{
				sf::RectangleShape line(sf::Vector2f(1, field[2][i]->center.y-field[0][i]->center.y));
				line.setFillColor(sf::Color::Red);
				line.setPosition(field[0][i]->center);
				line.setOutlineColor(sf::Color::Red);
				line.setOutlineThickness(5);
				window->draw(line);
				winner=mark;
				return;
			};
		}

		if( (field[0][0]->mark==mark) && (field[1][1]->mark==mark) && (field[2][2]->mark==mark) )
		{
			int w=sqrt(pow((field[2][2]->center.x-field[0][0]->center.x),2)+pow((field[2][2]->center.y-field[0][0]->center.y),2));
			sf::RectangleShape line(sf::Vector2f(w, 1));
			line.setFillColor(sf::Color::Red);
			line.setPosition(field[0][0]->center);
			line.setOutlineColor(sf::Color::Red);
			line.setOutlineThickness(5);
			line.rotate(45*(height)/(width-edge_x));
			window->draw(line);
			winner=mark;
			return;
		}

		else if( (field[0][2]->mark==mark) && (field[1][1]->mark==mark) && (field[2][0]->mark==mark) )
		{
			int w=sqrt(pow((field[2][0]->center.x-field[0][2]->center.x),2)+pow((field[2][0]->center.y-field[0][2]->center.y),2));
			sf::RectangleShape line(sf::Vector2f(w, 1));
			line.setFillColor(sf::Color::Red);
			line.setPosition(field[2][0]->center);
			line.setOutlineColor(sf::Color::Red);
			line.setOutlineThickness(5);
			line.rotate(-45*(height)/(width-edge_x));
			window->draw(line);	
			winner=mark;
			return;
		};	
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(field[i][j]->mark=='?')
				return;
			}
		}
		winner='-';
	}

