#pragma once

#include <SDL_ttf.h>
#include <vector>
#include <iostream>

class Button;
class InputBox;

class UIManager
{
private:
	static std::vector<Button*> m_TrackedButtons;
	static std::vector<InputBox*> m_TrackedInputBoxes;

public:
	static bool InitializeUI();
	static void UpdateUI(SDL_Event* ev);

	static void AddButton(Button* button);
	static void AddInputBox(InputBox* inputBox);
	static void ClearButtons();
	
	static void ClearUI();

};

