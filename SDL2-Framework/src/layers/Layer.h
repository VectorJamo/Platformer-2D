#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <SDL.h>

class Layer
{
protected:
	std::string m_LayerName;
	static SDL_Renderer* m_Renderer;

public:
	static std::unordered_map<std::string, Layer*> CurrentLayers;

public:
	Layer(const std::string& layerName, SDL_Renderer* renderer);
	~Layer();

	virtual void Update() = 0;
	virtual void Render() = 0;
};