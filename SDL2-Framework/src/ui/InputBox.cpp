#include "InputBox.h"
#include <iostream>

InputBox::InputBox(const vec2& position, const vec2& dimension, SDL_Renderer* renderer)
	:m_Position(position), m_Dimension(dimension)
{
	m_Text = new Text(std::string(""), m_Position.x + m_TextOffset, m_Position.y + m_TextOffset, m_Dimension.height/3, renderer);

	m_AlphaCounter = 255;
	m_Increment = 5;
}

InputBox::~InputBox()
{
	delete m_Text;
}

void InputBox::Update(SDL_Event* ev)
{
	// Check if it is active or not
	int mx, my;
	SDL_GetMouseState(&mx, &my);
		
	if (MouseManager::IsMouseButtonPressed(SDL_BUTTON_LEFT))
	{
		if (mx > m_Position.x && mx < m_Position.x + m_Dimension.width && my > m_Position.y && my < m_Position.y + m_Dimension.height)
		{
			std::cout << 3;
			isActive = true;
		}
		else {
			isActive = false;
		}
	}

	if (isActive)
	{
		
		// Do stuff when the input box is active
		// Get what the user has typed.
		if ((ev->type == SDL_KEYDOWN))
		{
			unsigned char keyCode = ev->key.keysym.sym;

			std::string str = m_Text->GetString();
			if (keyCode != '\b' && (m_Text->GetWidth() < (m_Dimension.width - 3 * m_TextOffset))) // For backspaces
			{
				str.push_back(keyCode);

				m_Text->SetText(str);
			}
			else {
				if (keyCode == '\b' && str.length() > 0)
				{
					str.pop_back();
					m_Text->SetText(str);
				}			
			}
		}
	}
}

void InputBox::UpdateVisuals()
{
	if (m_AlphaCounter < 50)
		m_Increment = 5;
	else if (m_AlphaCounter > 220)
		m_Increment = -5;

	m_AlphaCounter += m_Increment;
}

void InputBox::Render(SDL_Renderer* renderer)
{
	// Background
	SDL_Rect rect = { m_Position.x, m_Position.y, m_Dimension.width, m_Dimension.height };
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); // White by default.
	SDL_RenderFillRect(renderer, &rect);

	// Outline
	rect = { (int)m_Position.x, (int)m_Position.y, (int)m_Dimension.width, (int)m_Dimension.height };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White by default.
	SDL_RenderDrawRect(renderer, &rect);

	// Cursor
	if (isActive)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, m_AlphaCounter);
		SDL_Rect cursorRect = { m_Position.x + m_TextOffset * 2 + m_Text->GetWidth(), m_Position.y + m_TextOffset, 2, m_Dimension.height - m_TextOffset * 2};
		SDL_RenderFillRect(renderer, &cursorRect);
	}

	// Text
	m_Text->Render();
}

std::string& InputBox::GetString()
{
	return m_Text->GetString();
}
