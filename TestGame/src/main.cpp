#include "game.h"
#include "TestScene.h"

#include "Scene.h"

int main(int argc, char** argv)
{
	Game::ExecutableSettings* projectSettings = new Game::ExecutableSettings();
	projectSettings->projectName = "Custom Engine Test";
	projectSettings->width = 640;
	projectSettings->height = 480;
	projectSettings->targetFramerate = 60.0;

	Game* currentGame = new Game();

	TestScene* startScene = new TestScene();
	currentGame->nextScene = startScene;

	currentGame->Init(projectSettings);
	currentGame->Update();
	currentGame->Close();

	return 0;
}