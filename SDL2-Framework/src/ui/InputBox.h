#pragma once

#include <SDL.h>
#include <string>
#include <maths/vec2.h>

#include "Text.h"
#include "input/KeyManager.h"
#include "input/MouseManager.h"

class InputBox
{
private:
	Text* m_Text;
	vec2 m_Position, m_Dimension;
	static constexpr int m_TextOffset = 5;

	// For cursor
	int m_AlphaCounter, m_Increment;

public:
	bool isActive;

public:
	InputBox(const vec2& position, const vec2& dimension, SDL_Renderer* renderer);
	~InputBox();

	void Update(SDL_Event* ev);
	void UpdateVisuals();
	void Render(SDL_Renderer* renderer);

	std::string& GetString();
};

