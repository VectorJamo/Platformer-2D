#include "Layer.h"

std::unordered_map<std::string, Layer*> Layer::CurrentLayers;
SDL_Renderer* Layer::m_Renderer = nullptr;

Layer::Layer(const std::string& layerName, SDL_Renderer* renderer)
{
	m_LayerName = layerName;
	m_Renderer = renderer;
}

Layer::~Layer()
{
}
