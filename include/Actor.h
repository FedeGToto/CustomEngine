#pragma once
#include "Texture.h"
#include "GameMath.h"

class Actor
{
public:
	Actor() {}
	virtual ~Actor() {}

	virtual void Start();
	virtual void Start(Vector2 pos, Texture* newTexture);

	virtual void Update();

	virtual void Render(SDL_Renderer* renderer);

	Vector2 getPos()
	{
		return pos;
	}
	float getAngle()
	{
		return angle;
	}
	Vector2 getScale()
	{
		return scale;
	}

	void setPos(float x, float y);
	void setAngle(float angle);
	void setScale(float w, float h);

	bool isActive = true;

	Texture* getTexture();
	SDL_Rect getCurrentFrame();

private:
	Vector2 pos;
	float angle = 0;
	Vector2 scale = Vector2(1, 1);
	SDL_Rect currentFrame;
	Texture* texture;
	bool canRender = false;
};
