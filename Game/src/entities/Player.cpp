#include "Player.h"

#include "src/entities/PlayerAnimations.h"
#include "src/input/KeyManager.h"
#include "src/map/MapConstants.h"

#include "Application.h"

Player::Player(int playerID, const char* playerSpritePath, SDL_Renderer* renderer)
	:Entity(playerID, playerSpritePath)
{
	m_Renderer = renderer;

	LoadAssets();
	SetupAnimations();

	m_CurrentDirection = PlayerDirections::RIGHT;
	m_ShouldMove = false;
	m_ShouldFlipTexture = false;

	m_Position.x = 10 * MapConstants::TileWidth;
	m_Position.y = 6 * MapConstants::TileHeight;
	m_Dimension = vec2(MapConstants::TileWidth, MapConstants::TileHeight);
}

Player::~Player()
{
}

void Player::LoadAssets()
{
	m_IdleTexture = new Texture("res/images/Characters/Mask_Dude/Idle.png", m_Renderer);
	m_RunTexture = new Texture("res/images/Characters/Mask_Dude/Run.png", m_Renderer);
	m_JumpTexture = new Texture("res/images/Characters/Mask_Dude/Jump.png", m_Renderer);
	m_FallTexture = new Texture("res/images/Characters/Mask_Dude/Fall.png", m_Renderer);

	for (int i = 0; i < 11; i++) {
		m_IdleAnimationRects[i] = { 32 * i, 0, 32, 32 };
	}
	for (int i = 0; i < 12; i++) {
		m_RunAnimationRects[i] = { 32 * i, 0, 32, 32 };
	}
}

void Player::SetupAnimations()
{
	m_Animations = new Animation[(int)PlayerAnimations::TOTAL_ANIMATIONS];
	m_Animations[(int)PlayerAnimations::IDLE_RIGHT].SetAnimation(m_IdleTexture, m_IdleAnimationRects, 11);
	m_Animations[(int)PlayerAnimations::RUN_RIGHT].SetAnimation(m_RunTexture, m_RunAnimationRects, 12);
}

void Player::Update()
{
	m_ShouldMove = false;
	m_CurrentAnimation = &m_Animations[(int)PlayerAnimations::IDLE_RIGHT];

	if (KeyManager::IsKeyPressed(SDLK_a))
	{
		m_CurrentDirection = PlayerDirections::LEFT;
		m_ShouldMove = true;
		m_ShouldFlipTexture = true;

		m_CurrentAnimation = &m_Animations[(int)PlayerAnimations::RUN_RIGHT];
	}
	if (KeyManager::IsKeyPressed(SDLK_d))
	{
		m_CurrentDirection = PlayerDirections::RIGHT;
		m_ShouldMove = true;
		m_ShouldFlipTexture = false;

		m_CurrentAnimation = &m_Animations[(int)PlayerAnimations::RUN_RIGHT];
	}

	if (m_ShouldMove)
	{
		switch (m_CurrentDirection)
		{
		case PlayerDirections::LEFT:
			m_Position.x -= m_PlayerSpeed * Application::GetDeltaTime();
			break;
		case PlayerDirections::RIGHT:
			m_Position.x += m_PlayerSpeed * Application::GetDeltaTime();
			break;
		}
	}

	m_CurrentAnimation->PlayAnimation();
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { m_Position.x, m_Position.y, m_Dimension.width, m_Dimension.height };
	SDL_Rect srcRect = m_CurrentAnimation->GetCurrentRect();

	if (m_ShouldFlipTexture) { 
		m_CurrentAnimation->GetAnimationTexture()->RenderFlippedHorizontally(m_Renderer, &srcRect, &destRect);
	}
	else {
		m_CurrentAnimation->GetAnimationTexture()->Render(m_Renderer, &srcRect, &destRect);
	}
}

void Player::Render(SDL_Renderer* renderer, float camX, float camY)
{
}