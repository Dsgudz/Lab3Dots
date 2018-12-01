#pragma once
#include <SFML/Graphics.hpp>
#ifndef DotR
#define DotR 1
#endif

#include <cmath>
#include <ctime>
#include <cstdlib>

#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace sf;

class Entity
{
public:
	Entity() {}
	~Entity() { delete[] vrtx; }

	void set(int n, int* a, Color clr, RenderWindow *wind)
	{
		delete[] vrtx;
		vrtx = new Vertex[6 * n*DotR*DotR];
		long long debug = 6 * n*DotR*DotR;
		window = wind;
		s = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = -DotR; j <= DotR; j++)
			{
				for (int k = 1; k*k + j*j <= DotR * DotR; k++)
				{
					vrtx[s].position = Vector2f(a[2 * i] + j, a[2 * i + 1] + k);
					vrtx[s].color = clr;
					s++;
				}
				for (int k = 0; k*k + j*j <= DotR * DotR; k--)
				{
					vrtx[s].position = Vector2f(a[2 * i] + j, a[2 * i + 1] + k);
					vrtx[s].color = clr;
					s++;
				}
			}
		}
		s++;
	}

	void draw()
	{
		window->draw(&vrtx[0], s, sf::Points);
	}

	bool active = false;

private:
	RenderWindow *window;
    long s;
	Vertex *vrtx = new Vertex[1];
};