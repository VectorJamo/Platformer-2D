#pragma once

#include "src/entities/Entity.h"
#include "../graphics/Animation.h"
#include "PlayerDirections.h"

class Player : public Entity
{
private:
	SDL_Renderer* m_Renderer;

	// Textures
	Texture* m_IdleTexture, * m_RunTexture, * m_JumpTexture, * m_FallTexture;

	// Animation clip rects
	SDL_Rect m_IdleAnimationRects[11], m_RunAnimationRects[12];

	// Indexed using indices from PlayerAnimations.h
	Animation* m_Animations; 
	Animation* m_CurrentAnimation;

	// Player directions
	PlayerDirections m_CurrentDirection;
	bool m_ShouldMove;
	bool m_ShouldFlipTexture;

	static constexpr float m_PlayerSpeed = 100.0f;

public:
	Player(int playerID, const char* playerSpritePath, SDL_Renderer* renderer);
	~Player();

	void LoadAssets();
	void SetupAnimations();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;
};