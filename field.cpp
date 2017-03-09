#include "field.hpp"

	Field :: Field()
	{
		figure=NULL;
		mark='?';
	}
	
	Field :: ~Field()
	{
		delete figure;
	}

	void Field :: draw_frame(sf::RenderWindow *window)
	{
		sf::RectangleShape rectangle; 
		rectangle.setSize(sf::Vector2f(width,height));
		rectangle.setFillColor(sf::Color(128, 128, 128, 255));
		rectangle.setPosition(x, y);
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(-5);
		window->draw(rectangle);
	}

	void Field :: make_frame(sf::RenderWindow *window, int edge_x, int edge_y, int j, int i, int w, int h)
	{
		x=edge_x+j*w;
		width=w;
		y=edge_y+i*h;
		height=h;
		center.x=(2*x+w)/2;
		center.y=(2*y+h)/2;
		draw_frame(window);
	}

	bool Field :: check_field(sf::Vector2f pos)
	{
		if( (mark=='?') && (pos.x>=x) && (pos.y>=y) && (pos.x<x+width) && (pos.y<y+height) )
		return true;
		else
		return false;
	}
	
	void Field :: set_figure(sf::RenderWindow *window, char new_mark)
	{
		if(new_mark=='x')
		{
			figure = new Cross;
		}
		
		else if(new_mark=='o')
		{
			figure = new Circle;
		}	
		figure->draw(window, x, y, width, height);
		mark=new_mark;
	}
