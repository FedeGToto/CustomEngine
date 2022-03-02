#include "Actor.h"
#include <stdio.h>
#include <vector>
#include "game.h"

void Actor::Start()
{
	printf("Creating a new actor!\n");
	canRender = false;
	// Put the object in the update list
	Game::currentScene->activeActors.push_back(this);
	id = Game::currentScene->activeActors.size()-1;
}

void Actor::Start(Vector2 startPos, Texture* newTexture)
{
	pos = startPos;

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

	texture = newTexture;
	Game::currentScene->activeActors.push_back(this);
	id = Game::currentScene->activeActors.size();
	canRender = true;
}

void Actor::Update()
{
	printf("Updating the first actor in the game!. Delta Time: %f. FPS: %d\n", Game::deltaTime, Game::FPS);
}

void Actor::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Actor::setPos(Vector2 newPos)
{
	pos = newPos;
}

void Actor::setAngle(float nAngle)
{
	angle = nAngle;
}

void Actor::setScale(float w, float h)
{
	scale.x = w;
	scale.y = h;
}

Texture* Actor::getTexture()
{
	return texture;
}

SDL_Rect Actor::getCurrentFrame()
{
	return currentFrame;
}

void Actor::Render(SDL_Renderer* renderer)
{
	if (canRender) {
		SDL_Rect src;

		src.x = currentFrame.x;
		src.y = currentFrame.y;
		src.w = currentFrame.w;
		src.h = currentFrame.h;

		SDL_Rect dst;
		dst.x = pos.x + (currentFrame.w - currentFrame.w * scale.x) / 2;
		dst.y = pos.y + (currentFrame.h - currentFrame.h * scale.y) / 2;
		dst.w = currentFrame.w * scale.x;
		dst.h = currentFrame.h * scale.y;

		SDL_RenderCopyEx(renderer, texture->getTexture(), &src, &dst, angle, 0, SDL_FLIP_NONE);
	}
}

void Actor::Destroy()
{
	for (auto i = 0; i <= Game::currentScene->activeActors.size(); ++i)
	{
		if (Game::currentScene->activeActors[i]->id == id)
		{
			Game::currentScene->activeActors.erase(
				std::remove(Game::currentScene->activeActors.begin(), Game::currentScene->activeActors.end(), Game::currentScene->activeActors[i]));
		}
	}
}
