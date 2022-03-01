#include "game.h"
#include <stdio.h>

vector<Actor*> Game::activeActors;
bool Game::isRunning = false;
double Game::deltaTime;
int Game::FPS;

const void Game::Init(ExecutableSettings* newSettings)
{
	currentSettings = newSettings;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {

	}
	else
	{
		gameWindow = SDL_CreateWindow(currentSettings->projectName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, currentSettings->width, currentSettings->height, 0);

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

		now = SDL_GetTicks64();
		last = SDL_GetTicks64();

		isRunning = true;
	}
}

const void Game::Update()
{
	Actor* testActor = new Actor();
	testActor->Start();
	while (isRunning)
	{
		now = SDL_GetTicks64();
		deltaTime = now - last;
		if (deltaTime > 1000.0 / currentSettings->targetFramerate) {
			FPS = 1000.0 / deltaTime;

			last = now;
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
			for (Actor* i : activeActors)
			{
				i->Update();
			}

			//Update screen
			SDL_UpdateWindowSurface(gameWindow);
		}
	}
}

const void Game::Close()
{
	SDL_Quit();
	gameWindow = NULL;
}