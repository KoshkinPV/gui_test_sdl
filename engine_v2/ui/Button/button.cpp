#include "button.h"

#include "../window/window.h"

button::button()
	:mPosition({ 0,0,0,0 })
{
	mRenderer = NULL;
	mTexture = NULL;
}

void button::render()
{
	SDL_SetRenderDrawColor(mRenderer, 108, 146, 175, 255);
	SDL_RenderFillRect(mRenderer, &mPosition);
}

void button::setPosition(SDL_Rect rect)
{
	mPosition = rect;
}

void button::setRenderer(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}

void button::setTexture(std::string path)
{

}

void button::setType(type _type)
{
	mType = _type;
}

void button::setWindow(window* _window)
{
	Window = _window;
}

SDL_Rect button::getRect()
{
	return mPosition;
}

SDL_Texture* button::getTexture()
{
	return mTexture;
}

type button::getType()
{
	return mType;
}


bool button::ButtonPressed()
{
	if (pressed)
	{
		pressed = false;
		return true;
	}
	return false;
}

void button::action()
{
	if (mType == CONSOLE)
	{
		std::cout << "Hello!\n";
	}
	if(mType == RECT)
	{
		/*
			Тут будет самописный объект сцены в котором должны быть координаты,
			причем я думаю что на сцене для удобства можно центр взять за 0,0 по осям
			и уже от этого строить наш игровой мир.
			*/
		Window->createObject();
	};
}

void button::button_process_event(const SDL_Event* event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		if (event->button.button == SDL_BUTTON_LEFT &&
			event->button.x >= mPosition.x &&
			event->button.x <= (mPosition.x + mPosition.w) &&
			event->button.y >= mPosition.y &&
			event->button.y <= (mPosition.y + mPosition.h))
		{
			pressed = true;
		}
	}
}

