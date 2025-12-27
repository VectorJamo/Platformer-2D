#include "Animation.h"
#include "Application.h"

Animation::Animation(SDL_Rect* animationRects, int maxFrames)
{
	this->animationRects = animationRects;
	this->maxFrames = maxFrames;

	currentRect = animationRects;
}

Animation::~Animation()
{
}

void Animation::PlayAnimation()
{
	currentTime += Application::GetDeltaTime();
	if (currentTime > animationFrameTime)
	{
		currentTime = 0.0f;
		currentFrame++;
		if (currentFrame >= maxFrames) 
		{
			currentFrame = 0;
		}
	}
	currentRect = &animationRects[currentFrame];
}
