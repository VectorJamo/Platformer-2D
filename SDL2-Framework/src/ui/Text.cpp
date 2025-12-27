#include "Text.h"
#include <string>

SDL_Renderer* Text::m_Renderer;

#define ENGINE_DIR_MASK "../SDL2-Framework"

Text::Text(const std::string& text, int x, int y, int pointSize, SDL_Renderer* renderer)
	:m_Text(text), m_CurrentFont(nullptr), m_X(x), m_Y(y), m_PointSize(pointSize)
{
	m_Renderer = renderer;

	std::string defaultFontPath = std::string(ENGINE_DIR_MASK) + std::string("/res/fonts/8-bit-pusab.ttf");
	m_CurrentFont = TTF_OpenFont(defaultFontPath.c_str(), pointSize);
	if (m_CurrentFont == nullptr)
	{
		std::cout << "Failed to load font." << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}
	m_Color = { 255, 255, 255, 255 };

	m_Texture = CreateTexture();
}

Text::Text(const std::string& text, const std::string& fontPath, int x, int y, int pointSize, SDL_Renderer* renderer)
	:m_Text(text), m_CurrentFont(nullptr), m_X(x), m_Y(y), m_PointSize(pointSize)
{
	m_Renderer = renderer;
	m_CurrentFont = TTF_OpenFont(fontPath.c_str(), pointSize);
	if (m_CurrentFont == nullptr)
	{
		std::cout << "Failed to load font." << std::endl;
	}
	m_Color = { 255, 255, 255, 255 };

	m_Texture = CreateTexture();
}

Text::~Text()
{
	TTF_CloseFont(m_CurrentFont);
	SDL_DestroyTexture(m_Texture);
}

void Text::Render()
{
	SDL_Rect dest = { m_X, m_Y, m_Width, m_Height };
	SDL_RenderCopy(m_Renderer, m_Texture, NULL, &dest);
}

void Text::SetText(const std::string& text)
{
	m_Text = text;
	SDL_DestroyTexture(m_Texture);
	m_Texture = CreateTexture();
}

void Text::SetPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
}

void Text::SetFont(TTF_Font* font)
{
	TTF_CloseFont(m_CurrentFont);
	SDL_DestroyTexture(m_Texture);
	m_CurrentFont = font;
	
	m_Texture = CreateTexture();
}

void Text::SetTextAlpha(char alpha)
{
	SDL_SetTextureAlphaMod(m_Texture, alpha);
}

SDL_Texture* Text::CreateTexture()
{
	SDL_Surface* surface = TTF_RenderText_Blended(m_CurrentFont, m_Text.c_str(), m_Color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface);

	if (m_Text.length() == 0)
	{
		m_Width = 0;
		m_Height = 0;
	}else{
		SDL_QueryTexture(texture, NULL, NULL, &m_Width, &m_Height);
	}
	SDL_FreeSurface(surface);
	return texture;
}

