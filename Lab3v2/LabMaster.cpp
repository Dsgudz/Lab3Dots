#include "LabMaster.h"

LabMaster::LabMaster()
{
	int i = 0;
	while (i < 2*ndots)
	{
		arr[i].set(dots[2*i], dots[2*i + 1]);
		i++;
		arr[i].draw(Color::Black);
	}
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