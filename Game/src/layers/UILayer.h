#pragma once
#include "src/layers/Layer.h"
#include "src/utils/Texture.h"
#include "../entities/Player.h"
#include "src/ui/Text.h"

enum class HeartStates
{
	FULL = 0, HALF_FULL, EMPTY
};

class UILayer : public Layer
{
private:
	Texture* m_HeartTexture;
	SDL_Rect m_HeartRects[3];

	Text* m_CoinsText;
	int m_LastCoins = 0;

public:
	UILayer(const std::string& layerName, SDL_Renderer* renderer);
	~UILayer();

	void Update() override;
	void Render() override;
	void Render(Player* player);
};

