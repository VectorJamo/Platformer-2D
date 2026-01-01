#include "Coin.h"
#include "../graphics/Camera.h"
#include <iostream>

Coin::Coin(const vec2& position, const vec2& dimension, int objectID, const char* texturePath)
	:GameObject(position, dimension, objectID, texturePath)
{
	for (int i = 0; i < 8; i++)
	{
		m_AnimationRects[i] = { i * 32, 0, 32, 32 };
	}
	m_CoinAnimation = new Animation(m_ObjectTexture, m_AnimationRects, 8);
}

Coin::~Coin()
{
	delete m_CoinAnimation;
}

void Coin::Update()
{
	m_CoinAnimation->PlayAnimation();
}

void Coin::Render(SDL_Renderer* renderer)
{
	SDL_Rect srcRect = m_CoinAnimation->GetCurrentRect();
	SDL_Rect destRect = { m_Position.x - Camera::CamTopLeftX, m_Position.y - Camera::CamTopLeftY, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_ObjectTexture->GetTextureBuffer(), &srcRect, &destRect);
}

void Coin::Render(SDL_Renderer* renderer, float camX, float camY)
{
}
