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


void LabMaster::fortune()
{
	int beach[ndots] = {};
	int beachsize = 0;
	int ready[ndots] = {};
	int bestready = 1000;
	int i;
	float xtemp, ytemp;
	int prev, that, next;

	arr[ndots] = floorlvl;

	for(int iter = 0; iter < ndots; iter++)
	{
		i = 0;
		while ((i < beachsize) && (arr[beach[i]].getx() < arr[iter].getx()))
			i++;


		for (int j = beachsize; j > i; j--)
		{
			beach[j] = beach[j + 1];
			ready[j] = ready[j + 1];
		}

		beachsize++;
		beach[i] = iter;

		prev = beach[i-1];
		that = beach[i];
		next = beach[i+1];

		if ((i > 0) && (i < beachsize - 1))
		{
			prev = beach[i - 1];
			that = beach[i];
			next = beach[i + 1];
			findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
			ready[i] = ytemp;
		}

		if (i > 1)
		{
			prev = beach[i - 2];
			that = beach[i - 1];
			next = beach[i];
			findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
			ready[i - 1] = ytemp;
		}

		if (i < beachsize - 2)
		{
			prev = beach[i];
			that = beach[i + 1];
			next = beach[i + 2];
			findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
			ready[i + 1] = ytemp;
		}

		bestready = ready[1];

		for (int i = 2; i < beachsize - 1; i++)
			if (ready[i] < bestready)
				bestready = ready[i];

		while ((beachsize > 2) && (bestready < arr[iter + 1].gety()))
		{
			prev = beach[bestready - 1];
			that = beach[bestready];
			next = beach[bestready + 1];

			findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
			raven[nraven].set(xtemp, ytemp);
			map[nraven][0] = prev;
			map[nraven][1] = that;
			map[nraven][2] = next;
			nraven++;
			
			for (int j = bestready + 1; j < beachsize; j++)
			{
				beach[j] = beach[j - 1];
				ready[j] = ready[j - 1];
			}

			if ((bestready > 0) && (bestready < beachsize - 1))
			{
				prev = beach[bestready - 1];
				that = beach[bestready];
				next = beach[bestready + 1];
				findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
				ready[bestready] = ytemp;
			}

			if (bestready > 1)
			{
				prev = beach[bestready - 2];
				that = beach[bestready - 1];
				next = beach[bestready];
				findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
				ready[bestready - 1] = ytemp;
			}

			if (bestready < beachsize - 2)
			{
				prev = beach[bestready];
				that = beach[bestready + 1];
				next = beach[bestready + 2];
				findcenter(xtemp, ytemp, arr[prev].getx(), arr[prev].gety(), arr[that].getx(), arr[that].gety(), arr[next].getx(), arr[next].gety());
				ready[bestready + 1] = ytemp;
			}

			bestready = ready[1];

			for (int i = 2; i < beachsize - 1; i++)
				if (ready[i] < bestready)
					bestready = ready[i];
		}



	}





	
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
	fortune();

	for (int i = 0; i < ndots; i++)
	{
		arr[i].draw(Color::Yellow);
	}
	for (int i = 0; i < nraven; i++)
	{
		arr[i].draw(Color::Magenta);
	}
}