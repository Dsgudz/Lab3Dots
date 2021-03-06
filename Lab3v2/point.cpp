#include "point.h"
point::point(){}
point::~point(){}

void point::set(unsigned int x0, unsigned int y0)
{
	x = x0;
	y = y0;
}

void point::draw(Color clr = Color::Black)
{
	if (index < 0)
		index = VisualMaster::adddot(x, y, clr);
}

int point::line(point& to, bool if1, bool if2, Color clr)
{
	return VisualMaster::addline(x, y, if1, to.x, to.y, if2, clr);
}

int point::parabol(point& to, Color clr)
{
	return VisualMaster::addparabol(x, y, to.y, clr);
}

void point::hide()
{
	if (index > 0)
		VisualMaster::remove(index);
	index = -1;
}

bool point::operator>(point other)
{
	return y > other.y;
}