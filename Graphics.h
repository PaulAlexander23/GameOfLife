#pragma once
#include "stdafx.h"
class Graphics
{
public:
	Graphics(bool* quit, int ScreenWidth, int ScreenHeight);
	~Graphics();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

};

