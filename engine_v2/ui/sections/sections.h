#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class sections
{
public:

	sections();

	void close();

	void render();

	void setRenderer(SDL_Renderer* _renderer);
	void setTexture(std::string path);
	void setPosition(SDL_Rect rect);

	SDL_Texture* getTexture();
	SDL_Rect getRect();
private:
	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;
	SDL_Rect mPosition;
};

