#pragma once
#include "Texture.h"

struct AssetLoader
{
private:
	static SDL_Renderer* m_Renderer;

public:
	static Texture* LoadTexture(const char* path);

	static void SetRenderer(SDL_Renderer* renderer);
};



