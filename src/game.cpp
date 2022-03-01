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
			if (gameSurface != NULL)
			{
				SDL_FillRect(gameSurface, NULL, SDL_MapRGB(gameSurface->format, 0xFF, 0xFF, 0xFF));
			}
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

		// Update logic

		//Update screen
		SDL_UpdateWindowSurface(gameWindow);
	}
}

const void Game::Close()
{
	SDL_Quit();
	gameWindow = NULL;
}