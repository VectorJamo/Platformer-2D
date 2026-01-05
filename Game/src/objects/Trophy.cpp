#include "Trophy.h"
#include "../graphics/Camera.h"
#include <iostream>

Trophy::Trophy(const vec2& position, const vec2& dimension, int objectID, const char* texturePath)
	:GameObject(position, dimension, objectID, texturePath)
{
	
}

Trophy::~Trophy()
{
}

void Trophy::Update()
{
}

void Trophy::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { m_Position.x - Camera::CamTopLeftX, m_Position.y - Camera::CamTopLeftY, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_ObjectTexture->GetTextureBuffer(), NULL, &destRect);
}

void Trophy::Render(SDL_Renderer* renderer, float camX, float camY)
{
}