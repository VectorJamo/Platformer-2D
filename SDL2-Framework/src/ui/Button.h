#pragma once

#include "UIManager.h"
#include "Text.h"

class Button
{
private:
	Text* m_Text;
	int m_X, m_Y, m_Padding;
	SDL_Color m_TextColor, m_ButtonColor;
	
	static SDL_Renderer* m_Renderer;

public:
	bool isMouseOver, wasClicked;

public:
	Button(int x, int y, int padding, const std::string& text, int pointSize, SDL_Color textColor, SDL_Color buttonColor, SDL_Renderer* renderer);
	~Button();

	void Render();

	void SetPosition(float x, float y);

	inline int GetX() { return m_X; }
	inline int GetY() { return m_Y; }
	inline int GetWidth() { return m_Text->GetWidth() + m_Padding * 2; }
	inline int GetHeight() { return m_Text->GetHeight() + m_Padding * 2; }

};