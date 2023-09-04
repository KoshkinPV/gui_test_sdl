#pragma once
#include <SDL.h>
#include <vector>
#include "../World/world.h"
#include <iostream>

class window
{
public:
	window();

	bool init();
	void close();

	void Loop();
	void render();

	void createWorld();

private:
	int width = 640;
	int height = 480;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_DisplayMode mode;

	world World;
};

