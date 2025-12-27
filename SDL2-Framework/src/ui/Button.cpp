#include "Button.h"

SDL_Renderer* Button::m_Renderer;

Button::Button(int x, int y, int padding, const std::string& text, int pointSize, SDL_Color textColor, SDL_Color buttonColor, SDL_Renderer* renderer)
{
	m_Renderer = renderer;

	m_Padding = padding;
	m_X = x;
	m_Y = y;
	m_TextColor = textColor;
	m_ButtonColor = buttonColor;

	m_Text = new Text(text, x + padding, y + padding, pointSize, renderer);

	isMouseOver = false;
	wasClicked = false;
}

Button::~Button()
{
	delete m_Text;
}


void Button::Render()
{
	// Button
	SDL_Rect rect = { m_X, m_Y, m_Text->GetWidth() + m_Padding*2, m_Text->GetHeight() + m_Padding*2 };
	SDL_SetRenderDrawColor(m_Renderer, m_ButtonColor.r, m_ButtonColor.g, m_ButtonColor.b, m_ButtonColor.a);

	SDL_RenderFillRect(m_Renderer, &rect);

	// Text
	m_Text->Render();
}