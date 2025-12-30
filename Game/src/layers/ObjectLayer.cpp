#include "ObjectLayer.h"
#include <SDL.h>
#include "src/maths/vec2.h"

ObjectLayer::ObjectLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;
	
	m_Coins.reserve(m_NumCoins);

	m_Coins.emplace_back(new Coin(vec2(3 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(4 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(5 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(7 * 32, 2 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(13 * 32, 4 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(17 * 32, 6 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
}

ObjectLayer::~ObjectLayer()
{
	for (auto& coin : m_Coins)
		delete coin;
}

void ObjectLayer::Update()
{
	for (auto& coin : m_Coins)
	{
		coin->Update();
	}
}

void ObjectLayer::Render()
{
	for (auto& coin : m_Coins)
	{
		coin->Render(m_Renderer);
	}
}
