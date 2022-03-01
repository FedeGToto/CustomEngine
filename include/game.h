#pragma once
#include <SDL.h>

class Game
{
public:
	struct ExecutableSettings
	{
	public:
		ExecutableSettings();
		~ExecutableSettings();

		const char* projectName;
		int width;
		int height;
	};

	const void Init(ExecutableSettings* newSettings);

	const void Update();

	const void Close();

	bool isRunning;

private:
	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;
	SDL_Event gameEvents;
};