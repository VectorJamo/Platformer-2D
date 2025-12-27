#include "Animation.h"
#include "Application.h"

Animation::Animation()
{
}

Animation::Animation(Texture* texture, SDL_Rect* animationRects, int maxFrames)
{
	this->animationRects.texture = texture;
	this->animationRects.clipRects = animationRects;
	this->maxFrames = maxFrames;
}

Animation::~Animation()
{
}

void Animation::SetAnimation(Texture* texture, SDL_Rect* animationRects, int maxFrames)
{
	this->animationRects.texture = texture;
	this->animationRects.clipRects = animationRects;
	this->maxFrames = maxFrames;
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
	currentRect = animationRects.clipRects[currentFrame];
}
