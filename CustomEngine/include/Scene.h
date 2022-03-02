#pragma once
#include <SDL.h>
#include <vector>

#include "Actor.h"

class Scene
{
public:
	Scene() = default;
	~Scene() {};

	virtual void OnCreate(SDL_Renderer* gameRenderer)
	{
		currentRenderer = gameRenderer;
	};
	virtual void OnDestroy() {};
	virtual void OnActivate() {};
	virtual void OnDeactivate() {};

	virtual void ProcessInput(SDL_Event currentEvents);
	virtual void Update();
	virtual void LateUpdate();
	virtual void Draw(SDL_Renderer* renderer);

	std::vector<Actor*> activeActors;

protected:
	SDL_Renderer* currentRenderer;

	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
};