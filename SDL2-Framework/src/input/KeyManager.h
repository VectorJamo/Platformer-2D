#pragma once
#include <SDL.h>

#define MAX_KEYS 256

class KeyManager
{
private:
	static bool m_Keys[MAX_KEYS];

public:
	static void InitializeKeyManager();
	/**
	 * This function should be called in the Event Polling Loop inside of the Game Loop.
	 */
	static void UpdateKeyState(SDL_Event* ev);

	static bool IsKeyPressed(char key);
	static bool IsKeyReleased(char key);
};

