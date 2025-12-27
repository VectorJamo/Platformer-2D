#pragma once
#include <SDL.h>
#define MOUSE_BUTTONS_MAX 5

class MouseManager
{
private:
	static bool m_Buttons[MOUSE_BUTTONS_MAX];

public:
	static void InitializeMouseManager();
	static void UpdateMouseState(SDL_Event* ev);
	
	static bool IsMouseButtonPressed(int button);
};

