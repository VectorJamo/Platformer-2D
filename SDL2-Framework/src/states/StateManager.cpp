#include "StateManager.h"

StateManager* StateManager::CurrentState = nullptr;
bool StateManager::IsStateChanged = false;

StateManager::StateManager(Window* window, bool* isAppRunning)
	:m_Window(window), m_IsAppRunning(isAppRunning)
{

}

StateManager::~StateManager()
{
}
