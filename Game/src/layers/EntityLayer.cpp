#include "EntityLayer.h"

EntityLayer::EntityLayer(const std::string& layerName)
	:Layer(layerName)
{
	Layer::CurrentLayers[layerName] = this;
}

EntityLayer::~EntityLayer()
{
}

void EntityLayer::Update()
{

}

void EntityLayer::Render()
{
}
