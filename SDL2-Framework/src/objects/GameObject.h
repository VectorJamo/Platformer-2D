#pragma once
#include "maths/vec2.h"
#include "utils/AssetLoader.h"
#include <vector>
#include <SDL_image.h>

#include "utils/Texture.h"

class Entity;

class GameObject
{
protected:
	int m_ObjectID;
	vec2 m_Position, m_Dimension;
	Texture* m_ObjectTexture;

public:
	GameObject(int objectID, const char* texturePath);
	GameObject(const vec2& position, const vec2& dimension, int objectID, const char* texturePath);
	virtual ~GameObject();
	
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void Render(SDL_Renderer* renderer, float camX, float camY) = 0;

	void SetPosition(const vec2& position);
	void SetDimension(const vec2& dimension);

	inline const vec2& GetPosition() const { return m_Position; }
	inline const vec2& GetDimension() const { return m_Dimension; }
	inline const int GetObjectID() const { return m_ObjectID; }
};