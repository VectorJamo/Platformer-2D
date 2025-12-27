#include "StateManager.h"

StateManager* StateManager::CurrentState = nullptr;

StateManager::StateManager(Window* window, bool* isAppRunning)
	:m_Window(window), m_IsAppRunning(isAppRunning)
{

}

StateManager::~StateManager()
{
}
