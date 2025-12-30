#include "MapLayer.h"

MapLayer::MapLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	// Tilemap
	m_WorldSheet = new SpriteSheet("res/images/Terrain/Terrain.png", m_Renderer, vec2(16.0f, 16.0f));
	m_Map = new Tilemap("res/maps/map.txt", 11, 22, m_WorldSheet);
}

MapLayer::~MapLayer()
{
	delete m_WorldSheet;
	delete m_Map;
}

void MapLayer::Update()
{
}

void MapLayer::Render()
{
	// Tilemap
	m_Map->RenderFromSprite(m_Renderer);
}
