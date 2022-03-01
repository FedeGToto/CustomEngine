#pragma once
#include <SDL.h>

class Texture {
public:
	Texture(SDL_Renderer* renderer, const char* filePath);
	~Texture() {};

	SDL_Texture* getTexture();

private:
	SDL_Texture* texture;
};
