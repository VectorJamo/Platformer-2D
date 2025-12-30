#pragma once
#include "src/objects/GameObject.h"
#include "../graphics/Animation.h"
#include "src/maths/vec2.h"


class Coin : public GameObject
{
private:
	SDL_Rect m_AnimationRects[8];
	Animation* m_CoinAnimation;

public:
	Coin(const vec2& position, const vec2& dimension, int objectID, const char* texturePath);
	~Coin();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;

};
