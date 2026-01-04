#pragma once
#include "src/layers/Layer.h"

#include "src/utils/Texture.h"
#include "src/map/Tilemap.h"

class MapLayer : public Layer
{
private:
	Texture* m_Background;

	// Tilemap
	SpriteSheet* m_WorldSheet;
	Tilemap* m_Map;

public:
	MapLayer(const std::string& layerName, SDL_Renderer* renderer);
	~MapLayer();

	void Update() override;
	void Render() override;

	inline Tilemap* GetTileMap() { return m_Map; }
};
