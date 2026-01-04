#pragma once
#include "src/objects/GameObject.h"
#include "src/maths/vec2.h"
#include "../graphics/Animation.h"

enum class SawDirection
{
	IDLE = 0, LEFT = 1, RIGHT = 2
};

// Horizontal Saw
class Saw : public GameObject
{
private:
	Animation* m_SawAnimation;
	SDL_Rect m_SawAnimationRects[8];

	SawDirection m_CurrentDirection;
	vec2 m_Velocity;
	float m_LeftXMax, m_RightXMax;
	float m_Speed;

public:
	Saw(const vec2& position, const vec2& dimension, const char* texturePath, SDL_Renderer* renderer);
	~Saw();
	
	void EnableHorizontalMotion(float leftWorldBoundX, float rightWorldBoundX);

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;

	inline SawDirection GetCurrentDirection() const { return m_CurrentDirection; }
	inline vec2 GetVelocity() const { return m_Velocity; }
};

