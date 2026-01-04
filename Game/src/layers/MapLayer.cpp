#include "MapLayer.h"

MapLayer::MapLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	m_Background = new Texture("res/images/background.png", m_Renderer);

	// Tilemap
	m_WorldSheet = new SpriteSheet("res/images/Terrain/Terrain.png", m_Renderer, vec2(16.0f, 16.0f));
	m_Map = new Tilemap("res/maps/map.txt", 11, 22, m_WorldSheet);
}

MapLayer::~MapLayer()
{
	delete m_WorldSheet;
	delete m_Map;

	delete m_Background;
}

void MapLayer::Update()
{
}

void MapLayer::Render()
{
	SDL_Rect dest = { 0, 0, WindowDimensions::Width, WindowDimensions::Height };

	m_Background->Render(m_Renderer, NULL, &dest);
	// Tilemap
	m_Map->RenderFromSprite(m_Renderer);
}
