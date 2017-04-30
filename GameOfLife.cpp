// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Graphics.h"
#include "cpetri.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "initializing..." << endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	time_t t;
	srand((unsigned)time(&t));

	SDL_Renderer *renderer;
	
	
	bool quit = false;
	Graphics *oGraphics = new Graphics(&quit, 1000, 1000);
	cpetri *oPetri = new cpetri(oGraphics->GetRenderer());
	oPetri->contaminate(0.5);
	oGraphics->Begin();
	renderer = oGraphics->GetRenderer();
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, NULL);

	oPetri->draw();
	
	oGraphics->End();

	cout << "Start" << endl;
	_sleep(2000);
	
	while (!quit && oGraphics->GetMainEvent()->type != SDL_QUIT)
	{
		oGraphics->Begin();


		oPetri->timestep(1);


		renderer = oGraphics->GetRenderer();
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, NULL);

		oPetri->draw();

		

		oGraphics->End();

		cout << "tick" << endl;
		_sleep(100);
	}


	return 0;
}

