#include "cpetri.h"


cpetri::cpetri(SDL_Renderer* passed_renderer)
{
	renderer = passed_renderer;
}


cpetri::~cpetri()
{
}

int cpetri::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	for (int i = 1; i < 1000 - 1; i++)
	{
		for (int j = 1; j < 1000 - 1; j++)
		{
			if(grid[i+j*1000] == 1)
			{
				SDL_RenderDrawPoint(renderer, i, j);
			}
		}
	}

	return 1;
}

void cpetri::timestep(int t)
{

	for (int i = 0; i < t; i++)
	{
		GOL(&grid);
	}
}


int cpetri::contaminate(double lambda)
{
	double temp;
	for (int i = 1; i < 1000 - 1; i++)
	{
		for (int j = 1; j < 1000 - 1; j++)
		{
			temp = 1.0*rand()/RAND_MAX;
			if (temp < lambda)
			{
				grid[i+j*1000] = 1;
			}
		}
	}

	return 1;

}