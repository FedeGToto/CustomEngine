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

	Vector2 operator+(const Vector2& v)
	{
		Vector2 vector;
		vector.x = this->x + v.x;
		vector.y = this->y + v.y;
		return vector;
	}

	Vector2 operator-(const Vector2& v)
	{
		Vector2 vector;
		vector.x = this->x - v.x;
		vector.y = this->y - v.y;
		return vector;
	}

	void print() {
		printf("X: %f Y: %f", x, y);
	}

	float x, y;
};