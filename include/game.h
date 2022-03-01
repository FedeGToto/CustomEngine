#pragma once
#include <SDL.h>

class Game
{
public:
	Game() {};
	virtual ~Game() {};

	struct ExecutableSettings
	{
	public:

		const char* projectName;
		int width;
		int height;
	};

	const void Init(ExecutableSettings* newSettings);

	const void Update();

	const void Close();

	bool isRunning = false;

private:
	SDL_Window* gameWindow = NULL;
	SDL_Surface* gameSurface = NULL;
	SDL_Event gameEvents;
};