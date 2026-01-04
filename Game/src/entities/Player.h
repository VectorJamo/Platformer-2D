#pragma once

#include "src/entities/Entity.h"
#include "../graphics/Animation.h"
#include "PlayerDirections.h"
#include "src/map/Tilemap.h"

class Player : public Entity
{
private:
	Tilemap* m_Map;

	SDL_Renderer* m_Renderer;

	// Textures
	Texture* m_IdleTexture, * m_RunTexture, * m_JumpTexture, * m_FallTexture;

	// Animation clip rects
	SDL_Rect m_IdleAnimationRects[11], m_RunAnimationRects[12];

	// Indexed using indices from PlayerAnimations.h
	Animation* m_Animations; 
	Animation* m_CurrentAnimation;

	// Player movement
	vec2 m_Velocity;

	PlayerDirections m_CurrentDirection;
	bool m_ShouldMove;
	bool m_ShouldFlipTexture;

	static constexpr float m_PlayerSpeed = 100.0f;
	static constexpr float m_GravityYVel = 100.0f;

	// Player Jump
	static constexpr float m_JumpYVel = -8.0f;
	static constexpr float m_DragY = 0.2f;
	bool m_Jump, m_IsFalling;
	float m_CurrentJumpVelocity = m_JumpYVel;

	// Fixed Update
	static constexpr int m_TargetFPS = 60.0f;
	static constexpr float m_TargetFrameTime = 1.0f/(float)m_TargetFPS;
	float m_CumulativeTime = 0.0f;

	// Player Stats
	int m_Coins = 0;
	int m_Health = 100;
	
	// Player Effects
	bool m_IsInvincible = false;
	float m_InvincibilityTime = 2.0f; // 2seconds
	float m_InvincibleTimePassed = 0.0f;

public:
	Player(int playerID, const char* playerSpritePath, Tilemap* map, SDL_Renderer* renderer);
	~Player();

	void LoadAssets();
	void SetupAnimations();
	void CheckCollisions();
	void CaluclateJumpPhysics();

	void FixedUpdate();
	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;

	inline int GetCoins() const { return m_Coins; }
	inline int GetHealth() const { return m_Health; }
};