#include "game.h"
#include <stdio.h>

const void Game::Init(ExecutableSettings* newSettings)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

	}
	else
	{
		gameWindow = SDL_CreateWindow(newSettings->projectName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, newSettings->width, newSettings->height, 0);

		if (gameWindow != NULL)
		{
			// Create the surface
			gameSurface = SDL_GetWindowSurface(gameWindow);
		}
		else
		{
			printf("ERROR! Cause: %s\n", SDL_GetError());
		}

		isRunning = true;
	}
}

const void Game::Update()
{
	while (isRunning)
	{
		while (SDL_PollEvent(&gameEvents))
		{
			switch (gameEvents.type)
			{
			case SDL_QUIT:
				isRunning = false;
			default:
				break;
			}
		}
	}
}

const void Game::Close()
{
	SDL_Quit();
	gameWindow = NULL;
}