#include "Saw.h"
#include "Objects.h"
#include "../graphics/Camera.h"
#include "src/Application.h"
#include <iostream>

Saw::Saw(const vec2& position, const vec2& dimension, const char* texturePath, SDL_Renderer* renderer)
	:GameObject(position, dimension, (int)Objects::Saw, texturePath)
{
	for (int i = 0; i < 8; i++)
	{
		m_SawAnimationRects[i] = { 38 * i, 0, 38, 38 };
	}

	m_SawAnimation = new Animation(m_ObjectTexture, m_SawAnimationRects, 8);
	m_CurrentDirection = SawDirection::IDLE;
	m_Speed = 100.0f;
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;
}

Saw::~Saw()
{
	delete m_SawAnimation;
}

void Saw::EnableHorizontalMotion(float leftWorldBoundX, float rightWorldBoundX)
{
	m_CurrentDirection = SawDirection::RIGHT;
	m_LeftXMax = leftWorldBoundX;
	m_RightXMax = rightWorldBoundX;
}

void Saw::Update()
{
	if (m_CurrentDirection == SawDirection::LEFT)
	{
		m_Velocity.x = -m_Speed * Application::GetDeltaTime();

		float m_XNew = m_Position.x + m_Velocity.x;
		if (m_XNew > m_LeftXMax)
		{
			m_Position.x = m_XNew;
		}
		else {
			m_CurrentDirection = SawDirection::RIGHT;
		}
	}
	else if(m_CurrentDirection == SawDirection::RIGHT) 
	{
		m_Velocity.x = m_Speed * Application::GetDeltaTime();

		float m_RightNew = m_Position.x + m_Velocity.x + m_Dimension.width;
		if (m_RightNew < m_RightXMax)
		{
			m_Position.x = m_RightNew - m_Dimension.width;
		}
		else {
			m_CurrentDirection = SawDirection::LEFT;
		}
	}

	m_SawAnimation->PlayAnimation();
}

void Saw::Render(SDL_Renderer* renderer)
{
	SDL_Rect srcRect = m_SawAnimation->GetCurrentRect();
	SDL_Rect destRect = { m_Position.x - Camera::CamTopLeftX, m_Position.y - Camera::CamTopLeftY, m_Dimension.width, m_Dimension.height };
	SDL_RenderCopy(renderer, m_ObjectTexture->GetTextureBuffer(), &srcRect, &destRect);
}

void Saw::Render(SDL_Renderer* renderer, float camX, float camY)
{
}