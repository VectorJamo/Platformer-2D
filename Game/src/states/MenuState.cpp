#include "MenuState.h"
#include "GameState.h"

MenuState::MenuState(Window* window, bool* isAppRunning)
	:StateManager(window, isAppRunning)
{
	
}

MenuState::~MenuState()
{
}

void MenuState::Init()
{
	m_TitleText = new Text("Platformer", 100, 100, 32, m_Window->GetRenderer());
	m_CurrentY = 50.0f;
	m_TitleText->SetPosition(m_Window->GetWidth() / 2 - m_TitleText->GetWidth() / 2, m_CurrentY);
	m_CurrentY += m_TitleText->GetHeight();
	m_CurrentY += m_Gap*3;

	m_PlayButton = new Button(200.0f, m_CurrentY, 5, "Play", 18, { 0, 0, 0, 0 }, {255, 255, 255, 255}, m_Window->GetRenderer());
	m_PlayButton->SetPosition(m_Window->GetWidth()/2 - m_PlayButton->GetWidth()/2, m_CurrentY);

	m_CurrentY += m_PlayButton->GetHeight();
	m_CurrentY += m_Gap;
	m_QuitButton = new Button(200.0f, m_CurrentY, 5, "Quit", 18, { 0, 0, 0, 0 }, { 255, 255, 255, 255 }, m_Window->GetRenderer());
	m_QuitButton->SetPosition(m_Window->GetWidth() / 2 - m_QuitButton->GetWidth() / 2, m_CurrentY);

	UIManager::AddButton(m_PlayButton);
	UIManager::AddButton(m_QuitButton);
}

void MenuState::Update()
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

	if (m_PlayButton->wasClicked)
	{
		UIManager::ClearUI();

		StateManager::CurrentState = new GameState(m_Window, m_IsAppRunning);
		StateManager::CurrentState->Init();
	}
	if (m_QuitButton->wasClicked)
	{
		*m_IsAppRunning = false;
	}
}

void MenuState::Render()
{
	m_TitleText->Render();
	m_PlayButton->Render();
	m_QuitButton->Render();
}
