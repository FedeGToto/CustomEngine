#include "Scene.h"

#include "game.h"

void Scene::ProcessInput(SDL_Event currentEvents)
{
	while (SDL_PollEvent(&currentEvents))
	{
		switch (currentEvents.type)
		{
		case SDL_QUIT:
			Game::isRunning = false;
		default:
			break;
		}
	}

	SDL_PumpEvents();

	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	keyUp = keyState[SDL_SCANCODE_UP];
	keyDown = keyState[SDL_SCANCODE_DOWN];
	keyLeft = keyState[SDL_SCANCODE_LEFT];
	keyRight = keyState[SDL_SCANCODE_RIGHT];

	
}

void Scene::Update()
{
	// Update logic
	for (Actor* i : activeActors)
	{
		if (i->isActive)
			i->Update();
	}
}

void Scene::LateUpdate()
{
	for (Actor* i : activeActors)
	{
		if (i->isActive)
			i->LateUpdate();
	}
}

void Scene::Draw(SDL_Renderer* renderer)
{
	//Update screen
	for (Actor* i : activeActors)
	{
		if (i->isActive)
			i->Render(renderer);
	}
}
