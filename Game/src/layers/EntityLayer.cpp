#include "EntityLayer.h"
#include <SDL.h>
#include "src/entities/Entities.h"

EntityLayer::EntityLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	m_Player = new Player((int)ENTITIES::Player, "res/images/Characters/Mask_Dude/Idle.png", renderer);
}

EntityLayer::~EntityLayer()
{
}

void EntityLayer::Update()
{
	m_Player->Update();
}

void EntityLayer::Render()
{
	m_Player->Render(m_Renderer);
}
