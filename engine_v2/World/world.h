#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "../object/object.h"

class window;

class world
{
public:
	world();

	void render();

	void setWindow(window* _window);
	void setRenderer(SDL_Renderer* renderer);
	void setResolution(int x, int y);

	window* getWindow();
	SDL_Renderer* getRenderer();
	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();

	std::vector<object>* getVector();

	void createObject();
	

private:
	int width;
	int height;

	window* Window;

	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;

	std::vector<object> objects;
};

