#pragma once
#include <SDL.h>
#include <string>


enum type
{
	CONSOLE,
	RECT,
	STREAM,
	SOMETHING,
	TEST_OBJECT,
};

class window;

class button
{
public:
	button();
	
	void render();

	void setRenderer(SDL_Renderer* _renderer);
	void setTexture(std::string path);
	void setPosition(SDL_Rect rect);
	void setType(type _type);
	void setWindow(window* _window);

	SDL_Texture* getTexture();
	SDL_Rect getRect();
	type getType();

	void button_process_event(const SDL_Event* event);
	bool ButtonPressed();

	void action();

private:
	bool pressed;

	SDL_Rect mPosition;
	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;
	window* Window;
	
	type mType;
};