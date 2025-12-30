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
	m_MapLayer = new MapLayer("mapLayer", m_Window->GetRenderer());
	m_EntityLayer = new EntityLayer("entityLayer", m_Window->GetRenderer());
	m_ObjectLayer = new ObjectLayer("objectLayer", m_Window->GetRenderer());
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

	m_MapLayer->Update();
	m_EntityLayer->Update();
	m_ObjectLayer->Update();
}

void GameState::Render()
{
	m_MapLayer->Render();
	m_EntityLayer->Render();
	m_ObjectLayer->Render();
}

void GameState::LoadAssets()
{
}