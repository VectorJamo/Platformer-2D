#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "src/utils/Texture.h"

// Represents a single animation
struct AnimationRect
{
	Texture* texture;
	SDL_Rect* clipRects;
};

struct Animation
{
private:
	AnimationRect animationRects;
	int maxFrames;
	int currentFrame = 0;
	SDL_Rect currentRect;
	
	float animationFrameTime = 0.05f; // Change frames every 0.1 second
	float currentTime = 0.0f;

public:
	Animation();
	Animation(Texture* texture, SDL_Rect* animationRects, int maxFrames);
	~Animation();

	void SetAnimation(Texture* texture, SDL_Rect* animationRects, int maxFrames);

	void PlayAnimation();
	inline const SDL_Rect& GetCurrentRect() const { return currentRect; }
	inline Texture* GetAnimationTexture() const { return animationRects.texture; }
};
