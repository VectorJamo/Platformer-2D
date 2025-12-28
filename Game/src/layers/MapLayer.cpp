#include "MapLayer.h"

MapLayer::MapLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	m_WorldSheet = new SpriteSheet("res/images/Terrain/Terrain.png", m_Renderer, vec2(16.0f, 16.0f));

	m_Map = new Tilemap("res/maps/map.txt");

	m_Map->AssociateTileCharToSprite(7, m_WorldSheet, 7, 0);
	m_Map->AssociateTileCharToSprite(29, m_WorldSheet, 7, 1);
}

MapLayer::~MapLayer()
{
}

void MapLayer::Update()
{
}

void MapLayer::Render()
{
	m_Map->RenderFromSprite(m_Renderer);
}
