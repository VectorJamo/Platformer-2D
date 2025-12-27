#include "AssetLoader.h"

SDL_Renderer* AssetLoader::m_Renderer;

Texture* AssetLoader::LoadTexture(const char* path)
{
    return new Texture(path, m_Renderer);
}

void AssetLoader::SetRenderer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}
