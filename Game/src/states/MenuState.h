#pragma once
#include <iostream>

#include <src/states/StateManager.h>

#include <src/input/KeyManager.h>
#include <src/input/MouseManager.h>
#include <src/ui/UIManager.h>

#include "src/ui/Text.h"
#include "src/ui/Button.h"

class MenuState : public StateManager
{
private:
	static constexpr float m_Gap = 20.0f;
	float m_CurrentY;
	Text* m_TitleText;

	Button* m_PlayButton, *m_QuitButton;

public:
	MenuState(Window* window, bool* isAppRunning);
	~MenuState();

	void Init() override;
	void Update() override;
	void Render() override;
};

