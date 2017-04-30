#pragma once
#include "stdafx.h"
#include "Functions.h"
#include <vector>
#include <array>

class cpetri
{
public:
	cpetri(SDL_Renderer* passed_renderer);
	~cpetri();
	int draw();
	void timestep(int t);
	int contaminate(double lambda);
private:
	SDL_Renderer *renderer;
	std::array<int,M*N> grid;

};

