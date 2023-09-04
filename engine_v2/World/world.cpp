#include "world.h"
#include "../window/window.h"

world::world()
	:Window(nullptr),
	width(0),
	height(0)
{

}

void world::render()
{
	for (auto i : objects)
	{
		SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
		SDL_RenderFillRect(mRenderer, i.getPtrPosition());
	}
}

void world::setWindow(window* _window)
{
	Window = _window;
}


void world::setRenderer(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}

void world::setResolution(int x, int y)
{
	width = x;
	height = y;
}


window* world::getWindow()
{
	return Window;
}

SDL_Renderer* world::getRenderer()
{
	return mRenderer;	
}

int world::getWidth()
{
	return width;
}

int world::getHeight()
{
	return height;
}

SDL_Texture* world::getTexture()
{
	return mTexture;
}

std::vector<object>* world::getVector()
{
	return &objects;
}

void world::createObject()
{
	object obj;
	SDL_Rect position{ 300, 300, 128, 128 };
	obj.setPosition(position);
	
	objects.push_back(obj);
}
