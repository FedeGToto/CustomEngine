#include "Actor.h"
#include <stdio.h>
#include "game.h"

void Actor::Start()
{
	printf("Creating a new actor!\n");
	// Put the object in the update list
	Game::activeActors.push_back(this);
}

void Actor::Update()
{
	printf("Updating the first actor in the game!. Delta Time: %f. FPS: %d\n", Game::deltaTime, Game::FPS);
}
