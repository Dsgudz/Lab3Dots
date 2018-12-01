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
		for (int j = 1; j < i; j++)
		{
			h = arr[i].gety();
			if (checkmap[j])
			{
				x1 = arr[j].getx();
				y1 = arr[j].gety();
				c1 = (h - y1) / 2;
				a1 = 2 * (h - y1);

				for (int k = j; k < i; k++)
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

						
						x = sqrt((c2 - c1) / (a1 - a2)); /// NO!
						y = a1 * x * x + c1; /// NO!

						raven[dtsiter].set(x + x1, y + h);
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