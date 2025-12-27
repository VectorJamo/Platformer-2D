#include "MouseManager.h"
#include <iostream>

bool MouseManager::m_Buttons[MOUSE_BUTTONS_MAX];

void MouseManager::InitializeMouseManager()
{
	memset(m_Buttons, 0, MOUSE_BUTTONS_MAX);
}

void MouseManager::UpdateMouseState(SDL_Event* ev)
{
	if (ev->type == SDL_MOUSEBUTTONDOWN)
	{
		m_Buttons[ev->button.button] = true;
	}
	if (ev->type == SDL_MOUSEBUTTONUP)
	{
		m_Buttons[ev->button.button] = false;
	}
}

bool MouseManager::IsMouseButtonPressed(int button)
{
	return m_Buttons[button];
}