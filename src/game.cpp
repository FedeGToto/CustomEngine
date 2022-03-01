#include "game.h"
#include <stdio.h>
#include "GameMath.h"

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
			// Create the renderer
			renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
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
	Texture* testTexture = new Texture(renderer, "./Resources/Sprites/TestSprite.bmp");
	Vector2 newVector2 = Vector2(15,115);
	testActor->Start(newVector2, testTexture);
	while (isRunning)
	{
		now = SDL_GetTicks64();
		deltaTime = now - last;

		SDL_RenderClear(renderer);
		
		if (deltaTime > 1000.0 / currentSettings->targetFramerate) {
			FPS = 1000.0 / deltaTime;

			last = now;
			while (SDL_PollEvent(&gameEvents))
			{
				switch (gameEvents.type)
				{
				case SDL_QUIT:
					isRunning = false;
				case SDL_KEYDOWN:
					printf("A key has been pressed\n");
					switch (gameEvents.key.keysym.sym)
					{
					case SDLK_UP:
						testActor->setPos(testActor->getPos().x, testActor->getPos().y - 4);
						break;
					case SDLK_DOWN:
						testActor->setPos(testActor->getPos().x, testActor->getPos().y + 4);
						break;
					case SDLK_LEFT:
						testActor->setPos(testActor->getPos().x - 4, testActor->getPos().y);
						break;
					case SDLK_RIGHT:
						testActor->setPos(testActor->getPos().x + 4, testActor->getPos().y);
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}

			// Update logic
			for (Actor* i : activeActors)
			{
				if (i->isActive)
					i->Update();
			}

			//Update screen
			for (Actor* i : activeActors)
			{
				if (i->isActive)
					i->Render(renderer);
			}
			SDL_RenderPresent(renderer);
		}
	}
}

const void Game::Close()
{
	SDL_Quit();
	gameWindow = NULL;
}