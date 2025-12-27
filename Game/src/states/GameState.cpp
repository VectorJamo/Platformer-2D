#include "GameState.h"

GameState::GameState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
}

GameState::~GameState()
{
}

void GameState::Init()
{
	m_WorldSheet = new SpriteSheet("res/images/Terrain/Terrain.png", m_Window->GetRenderer(), vec2(16.0f, 16.0f));

	m_Map = new Tilemap("res/maps/map.txt");

	m_Map->AssociateTileCharToSprite(7, m_WorldSheet, 7, 0);
	m_Map->AssociateTileCharToSprite(29, m_WorldSheet, 7, 1);

	m_EntityLayer = new EntityLayer("entityLayer", m_Window->GetRenderer());
}

void GameState::Update()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			*m_IsAppRunning = false;
		}
		
		KeyManager::UpdateKeyState(&ev);
		MouseManager::UpdateMouseState(&ev);


		UIManager::UpdateUI(&ev);
	}

	m_EntityLayer->Update();
}

void GameState::Render()
{
	m_Map->RenderFromSprite(m_Window->GetRenderer());
	m_EntityLayer->Render();
}

void GameState::LoadAssets()
{
}