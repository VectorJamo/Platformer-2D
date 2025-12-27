#include "Window.h"

Window::Window(int width, int height, const char* title)
	:m_Window(nullptr), m_Renderer(nullptr), m_Width(width), m_Height(height), m_Title(title)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initialize SDL2" << std::endl;
	}

	m_Window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, NULL);
	m_Renderer = SDL_CreateRenderer(m_Window, -1,  SDL_RENDERER_ACCELERATED);
	// TODO: Check for errors in window or renderer creation
	if (m_Renderer == nullptr) 
	{
		std::cout << "Failed to create SDL Renderer!" << std::endl;

	}

	SDL_SetRenderDrawBlendMode(m_Renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
}

void Window::Clear(char r, char g, char b, char a)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
	SDL_RenderClear(m_Renderer);
}

void Window::Display()
{
	SDL_RenderPresent(m_Renderer);
}
