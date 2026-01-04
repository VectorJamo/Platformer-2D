#pragma once
#include "src/states/StateManager.h"

class MenuState : public StateManager
{
private:

public:
	MenuState(Window* window, bool* isAppRunning);
	~MenuState();

	void Init() override;
	void Update() override;
	void Render() override;
};

