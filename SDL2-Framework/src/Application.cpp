#include "Application.h"
#include "src/states/GameState.h"
#include "src/states/MenuState.h"

#include "audio/SoundManager.h"
#include "utils/AssetLoader.h"
#include "ui/UIManager.h"
#include "states/StateManager.h"

double Application::m_DeltaTime= 0.0;
double Application::m_TimePassed = 0.0;
double Application::m_Frequency = 0.0;
Application::Application(int width, int height, const char* title)
{
	m_Window = new Window(width, height, title);
	m_Running = true;

	if (!UIManager::InitializeUI())
	{
		std::cout << "Failed to initialize UI!" << std::endl;
	}
	if (!SoundManager::InitializeAudio())
	{
		std::cout << "Failed to initialize Audio!" << std::endl;
	}
	AssetLoader::SetRenderer(m_Window->GetRenderer());

	StateManager::CurrentState = new MenuState(m_Window, &m_Running);
	StateManager::CurrentState->Init();

	m_Frequency = SDL_GetPerformanceFrequency();
}

Application::~Application()
{
	delete StateManager::CurrentState;
	delete m_Window;
}

void Application::LogFPS()
{
	m_TimePassed += Application::GetDeltaTime();
	if (m_TimePassed > m_FPSLogFrequency)
	{
		m_TimePassed = 0.0;
		std::cout <<  "FPS: " << (1 / m_DeltaTime) << std::endl;
	}
}

void Application::Run()
{
	m_LastTime = SDL_GetPerformanceCounter();
	while (m_Running)
	{
		unsigned long long currentTime = SDL_GetPerformanceCounter();
		m_DeltaTime = (double)(currentTime - m_LastTime)/m_Frequency;
		m_LastTime = currentTime;

		m_Window->Clear(0, 0, 0, 255);

		StateManager::CurrentState->Update();
		StateManager::CurrentState->Render();

		m_Window->Display();

		LogFPS();
	}
}
