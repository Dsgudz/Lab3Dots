#include "LabMaster.h"

LabMaster::LabMaster()
{
	int i = 0;
	floorlvl.set(1000, 1000);
	while (i < 2*ndots)
	{
		arr[i].set(dots[2*i], dots[2*i + 1]);
		i++;
		arr[i].draw(Color::Black);
	}
}


void findcenter(float& x0, float& y0, float x1, float y1, float x2, float y2, float x3, float y3)
{
	float xm1 = (x1 + x2) / 2;
	float ym1 = (y1 + y2) / 2;
	float xm2 = (x2 + x3) / 2;
	float ym2 = (y2 + y3) / 2;

	float k1 = (x1 - x2) / (y2 - y1);
	float k2 = (x2 - x3) / (y3 - y2);

	float b1 = ym1 - k1*xm1;
	float b2 = ym2 - k2*xm2;


	x0 = (b2 - b1) / (k1 - k2);
	y0 = k1*x0 + b1;
}


void LabMaster::voronoy()
{
	











	
}

void LabMaster::sort()
{
	for (int i = 0; i < ndots; i++)
		for (int j = 1; j < ndots; j++)
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
}

void LabMaster::start()
{
	sort();
	voronoy();

	for (int i = 0; i < ndots; i++)
	{
		arr[i].draw(Color::Yellow);
	}
	for (int i = 0; i < nraven; i++)
	{
		arr[i].draw(Color::Magenta);
	}
}