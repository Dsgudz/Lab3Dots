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
	Entity entt;
	VisualMaster::init();

	point pt[20];
	/*for(int i =0; i<20;i++)
		for (int j = 0; j < 20; j++)
		{*/
			pt[0].set(500, 500);
			pt[1].set(400, 700);
			//pt[0].line(pt[1], Color::Green);
			pt[0].draw(Color::Green);
			pt[1].draw(Color::Red);
			
		/*}*/


	while (VisualMaster::isopen())
	{
		VisualMaster::redraw();
		VisualMaster::maintenance();
	}

	system("pause");

	return 0;

}