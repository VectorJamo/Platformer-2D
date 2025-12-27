#include "Entity.h"

Entity::Entity(int entityID, const char* texturePath)
	:m_EntityID(entityID)
{
	m_EntityTexture = AssetLoader::LoadTexture(texturePath);
}

Entity::Entity(const vec2& position, const vec2& dimension, int entityID, const char* texturePath)
	:m_Position(position), m_Dimension(dimension), m_EntityID(entityID)
{
	m_EntityTexture = AssetLoader::LoadTexture(texturePath);
}

Entity::~Entity()
{
	delete m_EntityTexture;
}

void Entity::SetPosition(const vec2& position)
{
	m_Position = position;
}

void Entity::SetDimension(const vec2& dimension)
{
	m_Dimension = dimension;
}

