#pragma once
#include <maths/vec2.h>
#include <utils/AssetLoader.h>
#include <vector>
#include <SDL_image.h>

#include <utils/Texture.h>

class GameObject;

class Entity
{
protected:
	int m_EntityID;
	vec2 m_Position, m_Dimension;
	Texture* m_EntityTexture;

public:
	Entity(int entityID, const char* texturePath);
	Entity(const vec2& position, const vec2& dimension, int entityID, const char* texturePath); 
	virtual ~Entity();

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void Render(SDL_Renderer* renderer, float camX, float camY) = 0;

	void SetPosition(const vec2& position);
	void SetDimension(const vec2& dimension);

	inline const vec2& GetPosition() const { return m_Position; }
	inline const vec2& GetDimension() const { return m_Dimension; }
	inline const int GetEntityID() const { return m_EntityID; }
};