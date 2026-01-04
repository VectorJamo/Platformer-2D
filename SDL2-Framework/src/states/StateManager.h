#pragma once
#include "../Window.h"
class StateManager
{
protected:
	Window* m_Window;
	bool* m_IsAppRunning;

public:
	static StateManager* CurrentState;
	static bool IsStateChanged;

	StateManager(Window* window, bool* isAppRunning);
	virtual ~StateManager();
	
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};