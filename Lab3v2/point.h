#pragma once
#include "VisualMaster.h"

class point
{
public:
	point();
	~point();

	bool operator>(point);
	void set(unsigned int, unsigned int);
	void draw(Color);
	void hide();
	unsigned int getx() { return x; };
	unsigned int gety() { return y; };
	int line(point&, Color);
	int parabol(point&, Color);
private:
	unsigned int x, y;
	int index = -1;
};