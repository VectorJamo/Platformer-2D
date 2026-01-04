#include "UILayer.h"

UILayer::UILayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	m_HeartTexture = new Texture("res/images/Extras/heart_sprite.png", m_Renderer);
	m_HeartRects[(int)HeartStates::FULL] = { 0, 0, 32, 32 };
	m_HeartRects[(int)HeartStates::HALF_FULL] = { 32, 0, 32, 32 };
	m_HeartRects[(int)HeartStates::EMPTY] = { 32*2, 0, 32, 32 };

	m_CoinsText = new Text("Coins: " + std::to_string(m_LastCoins), 10, 10, 14, m_Renderer);
}

UILayer::~UILayer()
{
}

void UILayer::Update()
{
}

void UILayer::Render()
{
}

void UILayer::Render(Player* player)
{
	int currentCoins = player->GetCoins();
	if (currentCoins != m_LastCoins)
	{
		std::string coinsText = "Coins: " + std::to_string(player->GetCoins());
		m_CoinsText->SetText(coinsText);

		m_LastCoins = currentCoins;
	}

	m_CoinsText->Render();

	int halfHearts = (float)player->GetHealth() / 16.5f;

	int numFullHearts = halfHearts / 2;
	int numHalfHearts = halfHearts % 2;
	int numEmptyHearts = 3 - (numFullHearts + numHalfHearts);

	int startX = (WindowDimensions::Width - 3 * 32) - 10;
	SDL_Rect destRect = { startX, 10, 32, 32 };
	for (int i = 0; i < numFullHearts; i++)
	{
		m_HeartTexture->Render(m_Renderer, &m_HeartRects[(int)HeartStates::FULL], &destRect);
		destRect.x += 32;
	}
	for (int i = 0; i < numHalfHearts; i++)
	{
		m_HeartTexture->Render(m_Renderer, &m_HeartRects[(int)HeartStates::HALF_FULL], &destRect);
		destRect.x += 32;
	}
	for (int i = 0; i < numEmptyHearts; i++)
	{
		m_HeartTexture->Render(m_Renderer, &m_HeartRects[(int)HeartStates::EMPTY], &destRect);
		destRect.x += 32;
	}
}