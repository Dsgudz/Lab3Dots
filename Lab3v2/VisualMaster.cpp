#include "VisualMaster.h"

#include <iostream>

RenderWindow *VisualMaster::window;
Event VisualMaster::event;
Entity VisualMaster::entities[1000];

void VisualMaster::init() { window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "DOTS EVERYWHERE"); }
void VisualMaster::clr() { delete window; }

using namespace std;

void VisualMaster::redraw()
{
	window->clear(sf::Color::White);
	for (int i = 0; i < 1000; i++)
		if (entities[i].active)
			entities[i].draw();
	window->display();
}

void VisualMaster::maintenance()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void VisualMaster::remove(int i)
{
	entities[i].active = false;
}

int VisualMaster::adddot(int x, int y, Color clr)
{
	int i = 0;
	int *data = new int[2];
	data[0] = x;
	data[1] = y;
	while (entities[i].active)
	{
		i++;
	}
	entities[i].active = true;
	entities[i].set(1, data, clr, window);
	delete[] data;
	return i;
}

int VisualMaster::addline(int x1, int y1, bool if1, int x2, int y2, bool if2, Color clr)
{
	int i = 0;
	int n = 0;
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
		swap(if1, if2);
	}

	int *data = new int[100000];

	if (x1 == x2)
	{
		for (int xiter = y1; xiter < y2; xiter += DotR)
		{
			data[2 * n + 1] = xiter;
			data[2 * n] = (xiter - y1) * (x2 - x1) / (y2 - y1) + x1;
			n++;
		}

		if (if1)
			for (int xiter = y1; ((xiter >= 0) && (data[2 * n] <= 1000) && (data[2 * n] >= 0)); xiter -= DotR)
			{
				data[2 * n + 1] = xiter;
				data[2 * n] = (xiter - y1) * (x2 - x1) / (y2 - y1) + x1;
				n++;
			}

		if (if2)
			for (int xiter = y2; ((xiter <= 1000) && (data[2 * n] <= 1000) && (data[2 * n] >= 0)); xiter += DotR)
			{
				data[2 * n + 1] = xiter;
				data[2 * n] = (xiter - y1) * (x2 - x1) / (y2 - y1) + x1;
				n++;
			}
	}
	else
	{
		for (int xiter = x1; xiter < x2; xiter += DotR)
		{
			data[2 * n] = xiter;
			data[2 * n + 1] = (xiter - x1) * (y2 - y1) / (x2 - x1) + y1;
			n++;
		}

		if (if1)
			for (int xiter = x1; ((xiter >= 0) && (data[2 * n - 1] <= 1000) && (data[2 * n - 1] >= 0)); xiter -= DotR)
			{
				data[2 * n] = xiter;
				data[2 * n + 1] = (xiter - x1) * (y2 - y1) / (x2 - x1) + y1;
				n++;
			}

		if (if2)
			for (int xiter = x2; ((xiter <= 1000) && (data[2 * n - 1] <= 1000) && (data[2 * n - 1] >= 0)); xiter += DotR)
			{
				data[2 * n] = xiter;
				data[2 * n + 1] = (xiter - x1) * (y2 - y1) / (x2 - x1) + y1;
				n++;
			}
	}

	i = 0;

	while (entities[i].active)
	{
		i++;
	}
	entities[i].active = true;
	entities[i].set(n, data, clr, window);
	delete[] data;
	return i;
}

int VisualMaster::addparabol(int x, int y, int h, Color clr)
{
	y = -y;
	y += h;
	int i = 0;
	int c = y / 2;
	float a = 2 * y;
	int xl = -sqrt((h - c) * a);
	int xr = sqrt((h - c) * a);


	int xt1, xt2;



	int *data = new int[2 * (xr - xl) / DotR];
	
	
	i = 0;
	int xiter = xl;
	while ( xiter < xr)
	{
		data[i] = xiter + x;
		i++;
		data[i] = -(xiter*xiter/a + c) + h;
		i++;
		xiter += DotR;
	}

	i = 0;


	while (entities[i].active)
	{
		i++;
	}
	entities[i].active = true;


	entities[i].set(((xr - xl) / DotR), data, clr, window);
	delete[] data;
	return i;
}

bool VisualMaster::isopen()
{
	return window->isOpen();
}