#include "game.h"

int main(int argc, char** argv)
{
	Game::ExecutableSettings* projectSettings = new Game::ExecutableSettings();
	projectSettings->projectName = "Custom Engine Test";
	projectSettings->width = 640;
	projectSettings->height = 480;
	projectSettings->targetFramerate = 144.0;

	Game* currentGame = new Game();

	currentGame->Init(projectSettings);
	currentGame->Update();
	currentGame->Close();
	
	return 0;
}