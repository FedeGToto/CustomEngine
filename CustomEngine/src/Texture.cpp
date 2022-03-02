#include "Texture.h"
#include <stdio.h>

Texture::Texture(SDL_Renderer* renderer, const char* filePath)
{
	texture = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(filePath);

	texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	if (texture == NULL)
		printf("Could not load texture. Error: %s\n", SDL_GetError());

	SDL_FreeSurface(loadedSurface);
}

SDL_Texture* Texture::getTexture()
{
	return texture;
}
