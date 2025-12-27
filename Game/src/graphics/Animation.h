#pragma once
#include <SDL.h>
#include <SDL_image.h>

// Represents a single animation
struct Animation
{
private:
	SDL_Rect* animationRects;
	int maxFrames;
	int currentFrame = 0;
	SDL_Rect* currentRect;
	
	float animationFrameTime = 0.1f; // Change frames every 0.1 second
	float currentTime = 0.0f;

public:
	Animation(SDL_Rect* animationRects, int maxFrames);
	~Animation();

	void PlayAnimation();
	inline SDL_Rect GetCurrentRect() { return *currentRect; }
};
