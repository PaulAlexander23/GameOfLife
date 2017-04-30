#include "Graphics.h"


Graphics::Graphics(bool* quit, int ScreenWidth, int ScreenHeight)
{

	window = NULL;
	window = SDL_CreateWindow("My First RPG", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window counldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainEvent = new SDL_Event();
}


Graphics::~Graphics()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* Graphics::GetRenderer()
{
	return renderer;
}

SDL_Event* Graphics::GetMainEvent()
{
	return mainEvent;
}

void Graphics::Begin()
{
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void Graphics::End()
{
	SDL_RenderPresent(renderer);
}