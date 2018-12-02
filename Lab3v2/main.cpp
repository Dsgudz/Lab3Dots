#pragma once
#include <SFML/Graphics.hpp>
#include "LabMaster.h"
/*sfml-system.lib;sfml-window.lib;sfml-graphics.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies)*/

#include "Entity.cpp"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include <chrono>
#include <thread>

using namespace std;

int main()
{
	VisualMaster::init();
	//VisualMaster::init();

	float x, y;

	point pt[20];
		pt[0].set(100, 200);
		pt[1].set(100, 400);
		pt[2].set(150, 450);
		findcenter(x,y, pt[0].getx(), pt[0].gety(), pt[1].getx(), pt[1].gety(), pt[2].getx(), pt[2].gety());
		pt[3].set(x, y);
		pt[0].draw(Color::Black);
		pt[1].draw(Color::Black);
		pt[2].draw(Color::Black);
		pt[3].draw(Color::Magenta);
	

	LabMaster lbmstr;

	//lbmstr.start();


	while (VisualMaster::isopen())
	{
		VisualMaster::redraw();
		VisualMaster::maintenance();
	}

	system("pause");

	return 0;

}