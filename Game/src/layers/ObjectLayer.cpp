#include "ObjectLayer.h"
#include <SDL.h>
#include "src/maths/vec2.h"

ObjectLayer::ObjectLayer(const std::string& layerName, SDL_Renderer* renderer)
	:Layer(layerName, renderer)
{
	Layer::CurrentLayers[layerName] = this;

	m_Coins.reserve(m_NumCoins);
	m_Spikes.reserve(m_NumSpikes);

	AddCoins();
	AddSpikes();
	AddSaws();
}

ObjectLayer::~ObjectLayer()
{
	for (auto& coin : m_Coins)
		delete coin;

	for (auto& spike : m_Spikes)
		delete spike;

	for (auto& saw : m_Saws)
		delete saw;
}

void ObjectLayer::AddCoins()
{
	m_Coins.emplace_back(new Coin(vec2(3 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(4 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(5 * 32, 1 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(7 * 32, 2 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(10 * 32, 7 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(12 * 32, 4 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(17 * 32, 6 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(24 * 32, 4 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(25 * 32, 4 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(29 * 32, 3 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(34 * 32, 6 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(34 * 32, 7 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(35 * 32, 7 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(36 * 32, 7 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(37 * 32, 7 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
	m_Coins.emplace_back(new Coin(vec2(37 * 32, 6 * 32), vec2(32, 32), (int)Objects::Coin, "res/images/Extras/coin_gold.png"));
}

void ObjectLayer::AddSpikes()
{
	m_Spikes.emplace_back(new Spike(vec2(6 * 32, 1 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(9 * 32, 10 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(10 * 32, 10 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(11 * 32, 10 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(22 * 32, 5 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(23 * 32, 5 * 32), "res/images/Traps/Spikes/Idle.png"));
	m_Spikes.emplace_back(new Spike(vec2(28 * 32, 3 * 32), "res/images/Traps/Spikes/Idle.png"));
}

void ObjectLayer::AddSaws()
{
	Saw* saw1 = new Saw(vec2(12 * 32, 4 * 32), vec2(32.0f, 32.0f), "res/images/Traps/Saw/On.png", m_Renderer);
	saw1->EnableHorizontalMotion(saw1->GetPosition().x, 32 * 4 + saw1->GetPosition().x);

	Saw* saw2 = new Saw(vec2(34 * 32, 7 * 32), vec2(32.0f, 32.0f), "res/images/Traps/Saw/On.png", m_Renderer);
	saw2->EnableHorizontalMotion(saw2->GetPosition().x, 32 * 4 + saw2->GetPosition().x);

	m_Saws.emplace_back(saw1);
	m_Saws.emplace_back(saw2);
}

void ObjectLayer::Update()
{
	for (auto& coin : m_Coins)
	{
		coin->Update();
	}
	for (auto& spike : m_Spikes)
	{
		spike->Update();
	}
	for (auto& saw : m_Saws)
	{
		saw->Update();
	}
}

void ObjectLayer::Render()
{
	for (auto& coin : m_Coins)
	{
		coin->Render(m_Renderer);
	}
	for (auto& spike : m_Spikes)
	{
		spike->Render(m_Renderer);
	}
	for (auto& saw : m_Saws)
	{
		saw->Render(m_Renderer);
	}
}