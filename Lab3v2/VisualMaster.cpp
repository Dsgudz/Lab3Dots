#include "VisualMaster.h"

RenderWindow *VisualMaster::window;
Event VisualMaster::event;
Entity VisualMaster::entities[1000];

void VisualMaster::init() { window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "DOTS EVERYWHERE"); }
void VisualMaster::clr() { delete window; }

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

int VisualMaster::addline(int x1, int y1, int x2, int y2, Color clr)
{
	int i = 0;
	int n = 0;
	int xiter;
	int xt, xl, yl, yr;
	int x[2] = {};
	int y[2] = {};
	
	xt = y1 * (x2 - x1) / (y1 - y2) + x1;
	xl = (1000 - y1) * (x2 - x1) / (y2 - y1) + x1;
	yl = x1 * (y2 - y1) / (x1 - x2) + y1;
	yr = (1000 - x1) * (y2 - y1) / (x2 - x1) + y1;

	if (xt > 0 && xt < 1000)
	{
		x[i] = xt;
		y[i] = 0;
		n++;
	}
	if (xl > 0 && xl < 1000)
	{
		x[i] = xl;
		y[i] = 1000;
		n++;
	}
	if (yl > 0 && yl < 1000)
	{
		x[i] = 0;
		y[i] = yl;
		n++;
	}
	if (yr > 0 && yr < 1000)
	{
		x[i] = 1000;
		y[i] = yr;
		n++;
	}
	n = abs(x[1] - x[0]) / DotR;
	xiter = min(x[1], x[0]);
	int *data = new int[2 * n];

	while (xiter <= x[1] || xiter <= x[0])
	{
		data[i] = xiter;
		i++;
		data[i] = (xiter - x1) * (y2 - y1) / (x2 - x1) + y1;
		i++;
		xiter+=DotR;
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
	int i = 0;
	int c = y / 2;
	int a = sqrt((y - c) / y / y);
	int xl = -sqrt(h - c / a);
	int xr = sqrt(h - c / a);


	int xt1, xt2;



	int *data = new int[2 * (xr - xl) / DotR];
	
	
	i = 0;
	int xiter = xl;
	while ( i < xr)
	{
		data[i] = xiter;
		i++;
		data[i] = a*xiter*xiter + c;
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