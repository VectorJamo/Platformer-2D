#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "maths/vec2.h"

// A basic wrapper for SDL_Texture 
class Texture
{
private:
	SDL_Texture* m_Texture;

public:
	Texture(const char* path, SDL_Renderer* renderer);
	~Texture();

	void Render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* destRect);

	inline SDL_Texture* GetTextureBuffer() { return m_Texture; }
};

// A wrapper for loading a sprite sheet.
class SpriteSheet
{
private:
	Texture* m_SpriteSheet; 
	 
	vec2 m_SpriteSize;

public:
	SpriteSheet(const char* path, SDL_Renderer* renderer, const vec2& spriteSize);
	~SpriteSheet();

	void RenderSprite(SDL_Renderer* renderer, SDL_Rect* spriteRect, SDL_Rect* destRect);

	SDL_Rect GetSpriteRect(int col, int row);
	inline Texture* GetSpriteSheet() { return m_SpriteSheet; }

	inline vec2& GetSpriteSize() { return m_SpriteSize; }
};

struct Sprite
{
	SpriteSheet* spriteSheet;
	int col, row;

	Sprite(SpriteSheet* spriteSheet, int col, int row);

	void Render(SDL_Renderer* renderer, SDL_Rect* destRect);
};

