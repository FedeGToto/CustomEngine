#pragma once
#include"game.h"
#include "Scene.h"

class TestScene : public Scene 
{
	void OnCreate(SDL_Renderer* gameRenderer);

	void Update();

private:
	Actor* testActor;
	
};