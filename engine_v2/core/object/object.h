#pragma once
#include <SDL.h>

class object
{
public:
	object();
	
	void setPosition(const SDL_Rect& rect);
	SDL_Rect getPosition();
	SDL_Rect* getPtrPosition();

private:
	SDL_Rect mPosition;
};

