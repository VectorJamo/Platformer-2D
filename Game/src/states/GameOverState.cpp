#include "GameOverState.h"
#include "GameState.h"

GameOverState::GameOverState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
	
}

GameOverState::~GameOverState()
{
}

void GameOverState::Init()
{
	m_GameOverText = new Text("Game Over", 100, 100, 32, m_Window->GetRenderer());
	m_CurrentY = 50.0f;
	m_GameOverText->SetPosition(m_Window->GetWidth() / 2 - m_GameOverText->GetWidth() / 2, m_CurrentY);
	m_CurrentY += m_GameOverText->GetHeight();
	m_CurrentY += m_Gap*3;

	m_RetryButton = new Button(200.0f, m_CurrentY, 5, "Retry", 18, { 0, 0, 0, 0 }, {255, 255, 255, 255}, m_Window->GetRenderer());
	m_RetryButton->SetPosition(m_Window->GetWidth()/2 - m_RetryButton->GetWidth()/2, m_CurrentY);

	m_CurrentY += m_RetryButton->GetHeight();
	m_CurrentY += m_Gap;
	m_QuitButton = new Button(200.0f, m_CurrentY, 5, "Quit", 18, { 0, 0, 0, 0 }, { 255, 255, 255, 255 }, m_Window->GetRenderer());
	m_QuitButton->SetPosition(m_Window->GetWidth() / 2 - m_QuitButton->GetWidth() / 2, m_CurrentY);

	UIManager::AddButton(m_RetryButton);
	UIManager::AddButton(m_QuitButton);
}

void GameOverState::Update()
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

	if (m_RetryButton->wasClicked)
	{
		UIManager::ClearUI();

		Window* windowPointer = m_Window;
		bool* appRunningPointer = m_IsAppRunning;
	
		delete StateManager::CurrentState;

		StateManager::CurrentState = new GameState(windowPointer, appRunningPointer);
		StateManager::CurrentState->Init();
		return;
	}
	if (m_QuitButton->wasClicked)
	{
		*m_IsAppRunning = false;
	}
}

void GameOverState::Render()
{
	m_GameOverText->Render();
	m_RetryButton->Render();
	m_QuitButton->Render();
}
