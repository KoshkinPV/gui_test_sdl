#pragma once
#include <SDL.h>
#include <vector>
#include "../../core/World/world.h"
#include <iostream>
#include "../sections/sections.h"
#include "../Button/button.h"

class window
{
public:
	window();

	bool init();
	void close();

	void Loop();
	void render();

	void createWorld();
	void createSection();
	void createButton();
	void createObject();

	void buttonsPressed();

private:
	int width = 640;
	int height = 480;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_DisplayMode mode;
	sections section;
	world World;
	std::vector<button> buttons;
};

