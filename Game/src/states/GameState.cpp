#include "GameState.h"
#include "src/audio/SfxPool.h"

GameState::GameState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
}

GameState::~GameState()
{
	delete m_MapLayer;
	delete m_EntityLayer;
	delete m_ObjectLayer;
}

void GameState::Init()
{
	SfxPool::InitializeSfx();

	m_MapLayer = new MapLayer("mapLayer", m_Window->GetRenderer());
	m_EntityLayer = new EntityLayer("entityLayer", m_Window->GetRenderer());
	m_ObjectLayer = new ObjectLayer("objectLayer", m_Window->GetRenderer());
	m_UILayer = new UILayer("uiLayer", m_Window->GetRenderer());
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
	m_UILayer->Update();
}

void GameState::Render()
{
	m_MapLayer->Render();
	m_EntityLayer->Render();
	m_ObjectLayer->Render();
	m_UILayer->Render(m_EntityLayer->GetPlayer());
}

void GameState::LoadAssets()
{
}