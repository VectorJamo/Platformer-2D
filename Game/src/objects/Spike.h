#pragma once
#include "src/objects/GameObject.h"
#include "src/maths/vec2.h"

class Spike : public GameObject
{
private:


public:
	Spike(const vec2& position, const char* texturePath);
	~Spike();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;
};

