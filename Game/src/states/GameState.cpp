#include "GameState.h"
#include "GameOverState.h"
#include "LevelWinState.h"
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

	delete m_BackgroundMusic;
}

void GameState::Init()
{
	SfxPool::InitializeSfx();
	m_BackgroundMusic = new Music("res/audio/music/backgroundMusic.mp3");
	m_BackgroundMusic->SetVolume(0.05f);
	m_BackgroundMusic->Play(-1);

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

	HandleStateChanges();
}

void GameState::Render()
{
	m_MapLayer->Render();
	m_EntityLayer->Render();
	m_ObjectLayer->Render();
	m_UILayer->Render(m_EntityLayer->GetPlayer());

}

void GameState::HandleStateChanges()
{
	// State Changes
	if (m_EntityLayer->GetPlayer()->GetHealth() <= 0)
	{
		UIManager::ClearUI();

		Window* windowPointer = m_Window;
		bool* appRunningPointer = m_IsAppRunning;

		delete StateManager::CurrentState;

		StateManager::CurrentState = new GameOverState(windowPointer, appRunningPointer);
		
		StateManager::CurrentState->Init();
	}

	if (m_EntityLayer->GetPlayer()->HasWonLevel())
	{
		UIManager::ClearUI();

		Window* windowPointer = m_Window;
		bool* appRunningPointer = m_IsAppRunning;
		int coinsCollected = m_EntityLayer->GetPlayer()->GetCoins();

		delete StateManager::CurrentState;

		StateManager::CurrentState = new LevelWinState(windowPointer, appRunningPointer, coinsCollected);

		StateManager::CurrentState->Init();
	}
}
