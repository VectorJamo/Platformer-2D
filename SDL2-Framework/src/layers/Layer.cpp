#include "Layer.h"

std::unordered_map<std::string, Layer*> Layer::CurrentLayers;
Layer::Layer(const std::string& layerName)
	:m_LayerName(layerName)
{
}

Layer::~Layer()
{
}
