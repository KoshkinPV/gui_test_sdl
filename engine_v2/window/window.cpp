#include "window.h"

window::window()
{
	if (init())
	{
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		Loop();
	}
	
}

bool window::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		success = false;
		return 0;
	}
	else
	{
		SDL_GetCurrentDisplayMode(0, &mode);
		width = mode.w;
		height = mode.h - 60;

		mWindow = SDL_CreateWindow("game engine v2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (mWindow == NULL)
		{
			success = false;
			return 0;
		}
		return success;
	}
}

void window::Loop()
{
	bool quit = false;
	SDL_Event event;
	bool leftMouseButtonDown = false;
	SDL_Point mousePos;
	SDL_Point clickOffset;
	SDL_Rect* selectedRect = NULL;

	createWorld();
	
	while (!quit)
	{
		SDL_Delay(16);
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONUP:
			if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
			{
				leftMouseButtonDown = false;
				selectedRect = NULL;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
			{
				leftMouseButtonDown = true;
				
				for (size_t i = 0; i < World.getVector()->size(); i++)
				{
					SDL_Rect* rect = World.getVector()->at(i).getPtrPosition();
					if (SDL_PointInRect(&mousePos, rect))
					{
						selectedRect = rect;
						clickOffset.x = mousePos.x - rect->x;
						clickOffset.y = mousePos.y - rect->y;

						break;
					}
				}
			}
		case SDL_MOUSEMOTION:
		{
			mousePos = { event.motion.x, event.motion.y };

			if (leftMouseButtonDown && selectedRect != NULL)
			{
				selectedRect->x = mousePos.x - clickOffset.x;
				selectedRect->y = mousePos.y - clickOffset.y;
			}
		}
		default:
			break;
		}
		render();
 	}
}

void window::render()
{
	SDL_SetRenderDrawColor(mRenderer, 242, 242, 242, 255);
	SDL_RenderClear(mRenderer);
	World.render();
	SDL_RenderPresent(mRenderer);
}

void window::createWorld()
{
	World.setWindow(this);
	World.setRenderer(mRenderer);
	World.setResolution(width, height);
	World.createObject();
}
