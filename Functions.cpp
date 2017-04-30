
#include"stdafx.h"


void GOL(std::array<int, M*N> *grid)
{
	std::array<int, 3*M> tempgrid;
	
	int count = 0;
	int neighboors;
	
	for (int i = 1; i < N - 1; i++)
	{

		for (int j = 0; j < M; j++)
		{
			tempgrid[j + (i - 1) * M] = grid->at(j + (i - 1) * M);
			tempgrid[j + i * M]		  = grid->at(j + i * M);
			tempgrid[j + (i + 1) * M] = grid->at(j + (i + 1) * M);
		}


		for (int j = 1; j < M - 1; j++)
		{
			neighboors = tempgrid[j - 1] + tempgrid[j] + tempgrid[j + 1] + tempgrid[j - 1 + M] + tempgrid[j + 1 + M] + tempgrid[j - 1 + 2 * M] + tempgrid[j + 2 * M] + tempgrid[j + 1 + 2 * M];
			if (grid->[j + i * M] == 1)
			{
				if (neighboors < 2)
				{
					grid->at(j + i * M) = 0;
				}
				else if (neighboors > 3)
				{
					grid->at(j + i * M) = 0;
				}
			}
			else
			{
				if (neighboors == 3)
				{
					grid->at(j + i * M) = 1;
				}
			}
			
		}
	}


	return 0;
};



