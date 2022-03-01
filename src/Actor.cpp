#include "Actor.h"
#include <stdio.h>
#include "game.h"

void Actor::Start()
{
	printf("Creating a new actor!\n");
	canRender = false;
	// Put the object in the update list
	Game::activeActors.push_back(this);
}

void Actor::Start(Vector2 startPos, Texture* newTexture)
{
	pos = startPos;

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

	texture = newTexture;
	Game::activeActors.push_back(this);
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
