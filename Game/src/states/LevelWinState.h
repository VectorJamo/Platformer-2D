#pragma once
#include <iostream>

#include <src/states/StateManager.h>

#include <src/input/KeyManager.h>
#include <src/input/MouseManager.h>
#include <src/ui/UIManager.h>

#include "src/ui/Text.h"
#include "src/ui/Button.h"

class LevelWinState : public StateManager
{
private:
	int m_CoinsCollected;

	static constexpr float m_Gap = 20.0f;
	float m_CurrentY;
	Text* m_LevelWinText, *m_CoinsCollectedText;

	Button* m_RetryButton, *m_QuitButton;

public:
	LevelWinState(Window* window, bool* isAppRunning, int coinsCollected);
	~LevelWinState();

	void Init() override;
	void Update() override;
	void Render() override;
};

