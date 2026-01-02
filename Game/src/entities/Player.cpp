#include "Player.h"

#include "src/entities/PlayerAnimations.h"
#include "src/input/KeyManager.h"
#include "src/map/MapConstants.h"
#include "src/utils/CollisionHandler.h"
#include "src/layers/Layer.h"
#include "src/layers/ObjectLayer.h"
#include "src/audio/SfxPool.h"

#include "Application.h"

#include "../graphics/Camera.h"


Player::Player(int playerID, const char* playerSpritePath, Tilemap* map, SDL_Renderer* renderer)
	:Entity(playerID, playerSpritePath)
{
	m_Map = map;
	m_Renderer = renderer;
	m_CollisionRect = { 4, 4, 24, 24 };

	LoadAssets();
	SetupAnimations();

	m_CurrentDirection = PlayerDirections::RIGHT;
	m_ShouldMove = false;
	m_ShouldFlipTexture = false;

	m_Position.x = 10 * MapConstants::TileWidth;
	m_Position.y = 6 * MapConstants::TileHeight;
	m_Dimension = vec2(MapConstants::TileWidth, MapConstants::TileHeight);
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;
	
	m_Jump = false;
	m_IsFalling = false;
}

Player::~Player()
{
	delete m_IdleTexture;
	delete m_RunTexture;
	delete m_JumpTexture;
	delete m_FallTexture;

	delete[] m_Animations;
}

void Player::LoadAssets()
{
	m_IdleTexture = new Texture("res/images/Characters/Mask_Dude/Idle.png", m_Renderer);
	m_RunTexture = new Texture("res/images/Characters/Mask_Dude/Run.png", m_Renderer);
	m_JumpTexture = new Texture("res/images/Characters/Mask_Dude/Jump.png", m_Renderer);
	m_FallTexture = new Texture("res/images/Characters/Mask_Dude/Fall.png", m_Renderer);

	for (int i = 0; i < 11; i++) 
	{
		m_IdleAnimationRects[i] = { 32 * i, 0, 32, 32 };
	}
	for (int i = 0; i < 12; i++) 
	{
		m_RunAnimationRects[i] = { 32 * i, 0, 32, 32 };
	}
}

void Player::SetupAnimations()
{
	m_Animations = new Animation[(int)PlayerAnimations::TOTAL_ANIMATIONS];
	m_Animations[(int)PlayerAnimations::IDLE_RIGHT].SetAnimation(m_IdleTexture, m_IdleAnimationRects, 11);
	m_Animations[(int)PlayerAnimations::RUN_RIGHT].SetAnimation(m_RunTexture, m_RunAnimationRects, 12);
}

void Player::CheckCollisions()
{
	CollisionDirection collisionDirection = CollisionHandler::CheckEntityWorldCollision(this, m_Map, m_Velocity);
	bool first = false;
	bool second = false;
	if (collisionDirection.xCollision)
	{
		m_Velocity.x = 0.0f;
	}
	if (collisionDirection.yCollision) {
		m_Velocity.y = 0.0f;

		if (m_IsFalling)
		{
			m_IsFalling = false;
			m_Jump = false;
		}
		else if (m_Jump && !m_IsFalling) {
			// Abort the ascend
			m_IsFalling = true;

			m_CurrentJumpVelocity = m_JumpYVel; // Reset to initial velocity for the next jump			
		}
	}
	else {
		if (!m_Jump)
		{
			m_IsFalling = true;
		}
	}

	// Player-Object collision
	ObjectLayer* objLayer = (ObjectLayer*)Layer::CurrentLayers["objectLayer"];
	std::vector<Coin*>& coins = objLayer->GetCoins();

	for (int i = 0; i < coins.size();)
	{
		if (CollisionHandler::CheckCollision(this, coins[i], m_Velocity, vec2(0.0f, 0.0f)))
		{
			m_Coins++;
			SfxPool::coinSfx->Play();

			coins.erase(coins.begin() + i);
			continue;
		}
		i++;
	}
}

void Player::Update()
{
	m_Velocity.x = 0.0f;
	m_Velocity.y = m_GravityYVel * Application::GetDeltaTime();
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
	if (KeyManager::IsKeyPressed(SDLK_SPACE) && !m_Jump)
	{
		m_Jump = true;
	}

	if (m_Jump && !m_IsFalling)
	{
		FixedUpdate();
	}

	if (m_ShouldMove)
	{
		switch (m_CurrentDirection)
		{
		case PlayerDirections::LEFT:
			m_Velocity.x = -m_PlayerSpeed * Application::GetDeltaTime();
			break;
		case PlayerDirections::RIGHT:
			m_Velocity.x = m_PlayerSpeed * Application::GetDeltaTime();
			break;
		}
	}

	// Check Collisions
	CheckCollisions();

	m_Position.x += m_Velocity.x;
	m_Position.y += m_Velocity.y;

	m_CurrentAnimation->PlayAnimation();

	// Update the Camera
	Camera::Update(m_Position, m_Dimension);
}

void Player::FixedUpdate()
{
	m_CumulativeTime += Application::GetDeltaTime();
	if (m_CumulativeTime >= m_TargetFrameTime)
	{
		m_CumulativeTime = 0.0f;

		if (m_Jump)
		{
			CaluclateJumpPhysics();
		}
	}
}


void Player::CaluclateJumpPhysics()
{
	if (m_CurrentJumpVelocity <= 0.0f && !m_IsFalling)
	{
		m_CurrentJumpVelocity += m_DragY;
	
		m_Velocity.y += m_CurrentJumpVelocity;
	}
	else {
		m_IsFalling = true;
		m_CurrentJumpVelocity = m_JumpYVel; // Reset to initial velocity for the next jump
	}
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { m_Position.x - Camera::CamTopLeftX, m_Position.y - Camera::CamTopLeftY, m_Dimension.width, m_Dimension.height };

	if (!m_Jump)
	{
		SDL_Rect srcRect = m_CurrentAnimation->GetCurrentRect();

		if (m_IsFalling)
		{
			if (m_ShouldFlipTexture)
			{
				m_FallTexture->RenderFlippedHorizontally(m_Renderer, NULL, &destRect);
			}
			else {
				m_FallTexture->Render(m_Renderer, NULL, &destRect);
			}
		}
		else {
			if (m_ShouldFlipTexture) { 
				m_CurrentAnimation->GetAnimationTexture()->RenderFlippedHorizontally(m_Renderer, &srcRect, &destRect);
			}
			else {
				m_CurrentAnimation->GetAnimationTexture()->Render(m_Renderer, &srcRect, &destRect);
			}
		}

	}
	else {
		// Descend jump state
		if (m_IsFalling)
		{
			if (m_ShouldFlipTexture)
			{
				m_FallTexture->RenderFlippedHorizontally(m_Renderer, NULL, &destRect);
			}
			else {
				m_FallTexture->Render(m_Renderer, NULL, &destRect);
			}
		}
		else {
		// Ascend jump state
			if (m_ShouldFlipTexture)
			{
				m_JumpTexture->RenderFlippedHorizontally(m_Renderer, NULL, &destRect);
			}
			else {
				m_JumpTexture->Render(m_Renderer, NULL, &destRect);
			}
		}

	}

	// Collision rect
	//SDL_Rect collisionRectRenderable = { m_Position.x + m_CollisionRect.x, m_Position.y + m_CollisionRect.y, m_CollisionRect.w, m_CollisionRect.h };
	//SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 200);
	//SDL_RenderDrawRect(m_Renderer, &collisionRectRenderable);
}

void Player::Render(SDL_Renderer* renderer, float camX, float camY)
{
}