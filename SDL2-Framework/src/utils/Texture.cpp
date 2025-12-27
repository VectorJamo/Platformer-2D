#include "Texture.h"

#include <iostream>

Texture::Texture(const char* path, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(path);
    if (surface == nullptr)
    {
        std::cout << "|Asset Loader Error|: Failed to load texture!" << std::endl;
        std::cout << path << std::endl;
    }
    m_Texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

Texture::~Texture()
{
	SDL_DestroyTexture(m_Texture);
}

void Texture::Render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* destRect)
{
    SDL_RenderCopy(renderer, m_Texture, srcRect, destRect);
}

SpriteSheet::SpriteSheet(const char* path, SDL_Renderer* renderer, const vec2& spriteSize)
    :m_SpriteSize(spriteSize)
{
    m_SpriteSheet = new Texture(path, renderer);
}

SpriteSheet::~SpriteSheet()
{
    delete m_SpriteSheet;
}

void SpriteSheet::RenderSprite(SDL_Renderer* renderer, SDL_Rect* spriteRect, SDL_Rect* destRect)
{
    m_SpriteSheet->Render(renderer, spriteRect, destRect);
}

SDL_Rect SpriteSheet::GetSpriteRect(int col, int row)
{
    SDL_Rect spriteRect = { col * (int)m_SpriteSize.width, row * (int)m_SpriteSize.height, (int)m_SpriteSize.width, (int)m_SpriteSize.height };
    return spriteRect;
}

Sprite::Sprite(SpriteSheet* spriteSheet, int col, int row)
{
    this->spriteSheet = spriteSheet;
    this->col = col;
    this->row = row;
}

void Sprite::Render(SDL_Renderer* renderer, SDL_Rect* destRect)
{
    SDL_Rect srcRect = spriteSheet->GetSpriteRect(this->col, this->row);
    SDL_RenderCopy(renderer, spriteSheet->GetSpriteSheet()->GetTextureBuffer(), &srcRect, destRect);
}
