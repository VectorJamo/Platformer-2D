#pragma once
#include "src/objects/GameObject.h"
#include "src/utils/Texture.h"
#include "src/maths/vec2.h"

class Trophy : public GameObject
{
private:

public:
	Trophy(const vec2& position, const vec2& dimension, int objectID, const char* texturePath);
	~Trophy();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;
	void Render(SDL_Renderer* renderer, float camX, float camY) override;
};