#pragma once
#include "Entity.cpp"

static class VisualMaster
{
public:
	static void init();
	static void clr();

	static void redraw();
	static void maintenance();

	static int addline(int, int, int, int, Color); // REFACTOR, must be static int addline(int, int, bool, int, int, bool, Color);
	static int adddot(int, int, Color);
	static int addparabol(int, int, int, Color);
	static void remove(int);

	static bool isopen();

private:
	static const int winWidth = 1000;
	static const int winHeight = 1000;

	static RenderWindow *window;
	static Event event;
	static Entity entities[1000];
//	VertexArray FictWindow(sf::Points, 3000);
//	Vertex permapoints[1000];
//	Vertex 
};