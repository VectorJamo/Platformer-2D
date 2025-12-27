#pragma once

#include <SDL_ttf.h>
#include <iostream>
#include <string>

class Text
{
private:
	std::string m_Text;
	TTF_Font* m_CurrentFont;
	int m_X, m_Y, m_Width, m_Height;
	int m_PointSize;

	SDL_Texture* m_Texture;
	SDL_Color m_Color;

	static SDL_Renderer* m_Renderer;

private:
	SDL_Texture* CreateTexture();
public:
	Text(const std::string& text, int x, int y, int pointSize, SDL_Renderer* renderer);
	Text(const std::string& text, const std::string& fontPath, int x, int y, int pointSize, SDL_Renderer* renderer);
	~Text();

	void Render();
	
	// Setters
	void SetText(const std::string& text);
	void SetPosition(int x, int y);
	void SetFont(TTF_Font* font);
	void SetTextAlpha(char alpha);

	// Getters
	inline std::string& GetString() { return m_Text; }
	inline int GetX() { return m_X; }
	inline int GetY() { return m_Y; }
	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }
	inline int GetPointSize() { return  m_PointSize; }
};