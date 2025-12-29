#pragma once
#include "MapConstants.h"
#include <unordered_map>
#include <string>
#include <SDL.h>

#include "utils/Texture.h"

class Tilemap
{
private:
	unsigned char** m_Map;
	int m_MapRows, m_MapCols;
	SpriteSheet* m_WorldSheet;
	
	// Use only one of these two for an instance of this Tilemap class
	std::unordered_map<unsigned char, Texture*> m_TileToTexture; // Tile to Texture Map -> For tiles with single texture
	std::unordered_map<unsigned char, Sprite*> m_TileToSprite; // Tile to Sprite in a sprite sheet

public:
	Tilemap(const char* filePath, int numTileRows, int numTileCols, SpriteSheet* worldSheet);
	~Tilemap();

	// For tiles which have an individual texture for each
	void AssociateTileCharToTexture(unsigned char c, Texture* texture);
	void Render(SDL_Renderer* renderer);
	
	// For tiles that will be loaded in from sprite sheet(s)
	void AssociateTileCharToSprite(unsigned char c, SpriteSheet* spriteSheet, int col, int row);
	void RenderFromSprite(SDL_Renderer* renderer);

	inline unsigned char** GetMap() { return m_Map; }

private:
	void LoadTilemap(const char* path);
};

