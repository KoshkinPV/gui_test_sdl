#include "sections.h"

sections::sections()
{
	mRenderer = NULL;
	mTexture = NULL;
	mPosition = { 0,0,0,0 };
}

void sections::close()
{
	SDL_DestroyTexture(mTexture);
}

void sections::render()
{
	SDL_SetRenderDrawColor(mRenderer, 161, 136, 148, 255);
	SDL_RenderFillRect(mRenderer, &mPosition);
}

void sections::setRenderer(SDL_Renderer* _renderer)
{
	mRenderer = _renderer;
}

void sections::setTexture(std::string path)
{
}

void sections::setPosition(SDL_Rect rect)
{
	mPosition = rect;
}

SDL_Texture* sections::getTexture()
{
	return mTexture;
}

SDL_Rect sections::getRect()
{
	return mPosition;
}
