#pragma once
#include <SDL.h>
#include <iostream>

class Window
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	
	const char* m_Title;
	int m_Width, m_Height;

public:
	Window(int width, int height, const char* title);
	~Window();

	void Clear(char r, char g, char b, char a);
	void Display();

	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }
	inline const char* GetTitle() { return m_Title; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }
};

