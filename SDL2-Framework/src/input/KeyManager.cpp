#include "KeyManager.h"
#include <iostream>

#include <SDL.h>

bool KeyManager::m_Keys[MAX_KEYS];
void KeyManager::InitializeKeyManager()
{
	memset(m_Keys, 0, sizeof(bool) * MAX_KEYS);
}

void KeyManager::UpdateKeyState(SDL_Event* ev)
{
	if (ev->type == SDL_KEYDOWN)
	{
		SDL_Keycode key = ev->key.keysym.sym;
		if (key > 0 && key < 256)
		{
			m_Keys[key] = true;
		}
	}
	if (ev->type == SDL_KEYUP)
	{
		SDL_Keycode key = ev->key.keysym.sym;
		if (key > 0 && key < 256)
		{
			m_Keys[key] = false;
		}
	}
}

bool KeyManager::IsKeyPressed(char key)
{
	return m_Keys[key];
}

bool KeyManager::IsKeyReleased(char key)
{
	return !m_Keys[key];
}

