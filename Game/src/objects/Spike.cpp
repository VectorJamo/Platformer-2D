#include "Spike.h"
#include "Objects.h"
#include "../graphics/Camera.h"

Spike::Spike(const vec2& position, const char* texturePath)
	:GameObject(position, vec2(32.0f, 32.0f), (int)Objects::Spike, texturePath)
{
}

Spike::~Spike()
{
}

void Spike::Update()
{
}

void Spike::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { m_Position.x - Camera::CamTopLeftX, m_Position.y - Camera::CamTopLeftY, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_ObjectTexture->GetTextureBuffer(), NULL, &destRect);
}

void Spike::Render(SDL_Renderer* renderer, float camX, float camY)
{
}
