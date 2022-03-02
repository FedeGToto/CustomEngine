#pragma once
#include <SDL.h>
#include "Actor.h"
#include "Texture.h"
#include "Scene.h"

using namespace std;

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	struct ExecutableSettings
	{
	public:

		const char* projectName;
		int width;
		int height;
		double targetFramerate;
	};

	static bool isRunning;

	static double deltaTime;
	static int FPS;

	static Scene* currentScene;
	static Scene* nextScene;

	const void Init(ExecutableSettings* newSettings);
	const void Update();
	const void Close();

private:
	ExecutableSettings* currentSettings;
	SDL_Window* gameWindow = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event gameEvents;

	Uint64 now;
	Uint64 last;
};