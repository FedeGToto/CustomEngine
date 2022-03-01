#pragma once
#include <SDL.h>
#include <vector>
#include "Actor.h"

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

	static vector<Actor*> activeActors;
	static double deltaTime;
	static int FPS;

	const void Init(ExecutableSettings* newSettings);
	const void Update();
	const void Close();

private:
	ExecutableSettings* currentSettings;
	SDL_Window* gameWindow = NULL;
	SDL_Surface* gameSurface = NULL;
	SDL_Event gameEvents;

	Uint64 now;
	Uint64 last;
};