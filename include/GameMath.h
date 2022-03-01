#pragma once
#include <stdio.h>

struct  Vector2
{
	Vector2()
		:x(0.0f), y(0.0f)
	{}

	Vector2(float x1, float y1)
		:x(x1), y(y1)
	{}

	void print() {
		printf("X: %f Y: %f", x, y);
	}

	float x, y;
};