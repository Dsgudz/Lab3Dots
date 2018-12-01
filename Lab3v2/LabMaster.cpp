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

void LabMaster::voronoy()
{
	int x, y, x1, x2, y1, y2,a1,a2,c1,c2,h;

	int dtsiter = nraven;

	checkmap[0] = true;
	for (int i = 1; i < ndots; i++)
	{
		checkmap[i] = true;
		h = arr[i].gety();
		for (int j = 0; j < i; j++)
		{
			if (checkmap[j])
			{
				x1 = arr[j].getx();
				y1 = arr[j].gety();
				c1 = (h - y1) / 2;
				a1 = 2 * (h - y1);
				

				for (int k = j + 1; k < i; k++)
					if (checkmap[k])
					{
						x2 = arr[k].getx();
						y2 = arr[k].gety();
						c2 = (h - y2) / 2;
						a2 = 2 * (h - y2);


						if ((y1 + c1) > (-(x1*x1 / a2 + c2) + h))
						{
							checkmap[j] = false;
							break;
						}

						{
							float xm = (x1 + x2) / 2.f;
							float ym = (y1 + y2) / 2.f;
							float km = (x1 - x2) / float(y2 - y1);
							float bm = ym - km * xm;

							double b = bm/2.f + km*km*h - km*km*y1 - km*x1;
							double c = bm*bm - 2 * km*x1*bm + km*km*x1*x1 + km*km*h*h - km*km*y1*y1;

							y = sqrt(b*b - c) - b;
							x = (y + bm) / km;
						}

						
						raven[dtsiter].set(x, y);
						map[dtsiter][0] = i;
						map[dtsiter][1] = j;
						map[dtsiter][2] = k;

						dtsiter++;
						





					}
			}


			for (int m = nraven; m < dtsiter; m++)
			{
				x = arr[m].getx();
				y = arr[m].gety();
				if (y >(-(x1*x1 / a2 + c2) + h))
				{
					for (int n = m; n < dtsiter; n++)
					{
						arr[n] = arr[n + 1];
					}
					dtsiter--;
				}
			}

		}
	}
	nraven = dtsiter;
}/// wrong as hell

void LabMaster::sort()
{
	for (int i = 0; i < ndots; i++)
		for (int j = 1; j < ndots; j++)
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
}

void LabMaster::start()
{
	VisualMaster::init();

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