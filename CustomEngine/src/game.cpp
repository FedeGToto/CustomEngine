#include "game.h"
#include <stdio.h>
#include "GameMath.h"

bool Game::isRunning = false;
double Game::deltaTime;
int Game::FPS;
Scene* Game::currentScene;
Scene* Game::nextScene;

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
			// Create the renderer
			renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
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
	Uint64 currentCounter = SDL_GetPerformanceCounter();
	Uint64 lastCounter = currentCounter;

	while (isRunning)
	{
		lastCounter = currentCounter;
		currentCounter = SDL_GetPerformanceCounter();
		deltaTime = (float)(currentCounter - lastCounter) / (float)SDL_GetPerformanceFrequency();
		FPS = (int)(1.f / deltaTime);

		SDL_RenderClear(renderer);

		if (nextScene != NULL) {
			if (currentScene != NULL)
			{
				currentScene->OnDeactivate();
				currentScene->OnDestroy();
			}
			currentScene = nextScene;

			currentScene->OnCreate(renderer);
			currentScene->OnActivate();

			nextScene = NULL;
		}

		currentScene->ProcessInput(gameEvents);
		currentScene->Update();
		currentScene->LateUpdate();
		currentScene->Draw(renderer);

		SDL_RenderPresent(renderer);
	}
}

const void Game::Close()
{
	SDL_Quit();
	gameWindow = NULL;
}