#pragma once

#include "src/entities/Entity.h"
#include "../graphics/Animation.h"

class Player : public Entity
{
private:
	Animation* m_Animations; // Indexed using indices from PlayerAnimations.h
	Animation* m_CurrentAnimation;

public:
	Player(int playerID, const char* playerSpritePath);
	~Player();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;
};