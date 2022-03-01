#pragma once

class Actor
{
public:
	Actor() {}
	virtual ~Actor() {}

	virtual void Start();
	virtual void Update();
};
