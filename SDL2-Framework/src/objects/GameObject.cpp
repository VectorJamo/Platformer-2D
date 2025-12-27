#include "GameObject.h"

GameObject::GameObject(int objectID, const char* texturePath)
	:m_ObjectID(objectID)
{
	m_ObjectTexture = AssetLoader::LoadTexture(texturePath);

}

GameObject::GameObject(const vec2& position, const vec2& dimension, int objectID, const char* texturePath)
	:m_Position(position), m_Dimension(dimension), m_ObjectID(objectID)
{
	m_ObjectTexture = AssetLoader::LoadTexture(texturePath);

}

GameObject::~GameObject()
{
	delete m_ObjectTexture;
}

void GameObject::SetPosition(const vec2& position)
{
	m_Position = position;
}

void GameObject::SetDimension(const vec2& dimension)
{
	m_Dimension = dimension;
}
