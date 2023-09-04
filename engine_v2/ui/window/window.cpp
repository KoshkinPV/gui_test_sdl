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
	createSection();
	createButton();

	while (!quit)
	{
		SDL_Delay(10);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
				break;
			}

			if (event.type == SDL_MOUSEBUTTONUP) {
				if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseButtonDown = false;
					selectedRect = NULL;
				}
			}

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
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
			}
			if (event.type == SDL_MOUSEMOTION)
			{
				mousePos = { event.motion.x, event.motion.y };

				if (leftMouseButtonDown && selectedRect != NULL)
				{
					selectedRect->x = mousePos.x - clickOffset.x;
					selectedRect->y = mousePos.y - clickOffset.y;
				}
			}
			for (size_t i = 0; i < buttons.size(); ++i)
			{
				buttons.at(i).button_process_event(&event);
			}
		}
		buttonsPressed();
		render();
 	}
}

void window::render()
{
	SDL_SetRenderDrawColor(mRenderer, 242, 242, 242, 255);
	SDL_RenderClear(mRenderer);
	World.render();
	section.render();
	for (auto i : buttons)
	{
		i.render();
	}
	SDL_RenderPresent(mRenderer);
}

void window::createWorld()
{
	World.setWindow(this);
	World.setRenderer(mRenderer);
	World.setResolution(width, height);
	World.createObject();
}

void window::createSection()
{
	section.setRenderer(mRenderer);
	section.setTexture("../img/section.jpg");
	SDL_Rect rect = { 0,0, width / 10, height };
	section.setPosition(rect);
}

void window::createButton()
{
	button tmpBtn;
	SDL_Rect rect{ 50,20, 64, 48 };
	tmpBtn.setPosition(rect);
	tmpBtn.setRenderer(mRenderer);
	tmpBtn.setType(RECT);
	tmpBtn.setWindow(this);
	buttons.push_back(tmpBtn);
}

void window::createObject()
{
	World.createObject();
}

void window::buttonsPressed()
{
	for (size_t i = 0; i < buttons.size(); ++i)
	{
		if (buttons.at(i).ButtonPressed())
		{
			buttons.at(i).action();
		}
	}
}