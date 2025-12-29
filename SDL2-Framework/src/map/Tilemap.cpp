#include "Tilemap.h"
#include <iostream>
#include <fstream>
#include <sstream>

Tilemap::Tilemap(const char* filePath, int numTileRows, int numTileCols, SpriteSheet* worldSheet)
{
	m_Map = new unsigned char* [MapConstants::NumRows];
	m_MapRows = numTileRows;
	m_MapCols = numTileCols;
	m_WorldSheet = worldSheet;

	for (int i = 0; i < MapConstants::NumRows; i++)
		m_Map[i] = new unsigned char[MapConstants::NumCols];

	LoadTilemap(filePath);
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < MapConstants::NumRows; i++)
		delete[] m_Map[i];
}

void Tilemap::AssociateTileCharToTexture(unsigned char c, Texture* texture)
{
	m_TileToTexture[c] = texture;
}

void Tilemap::Render(SDL_Renderer* renderer)
{
	for (int i = 0; i < MapConstants::NumRows; i++)
	{
		for (int j = 0; j < MapConstants::NumCols; j++)
		{
			int x = j * MapConstants::TileWidth;
			int y = i * MapConstants::TileHeight;

			SDL_Rect destRect = { x, y, MapConstants::TileWidth, MapConstants::TileHeight };
		
			if (m_TileToTexture.count(m_Map[i][j]))
			{
				m_TileToTexture[m_Map[i][j]]->Render(renderer, NULL, &destRect);
			}
		}
	}
}

void Tilemap::AssociateTileCharToSprite(unsigned char c, SpriteSheet* spriteSheet, int col, int row)
{
	m_TileToSprite[c] = new Sprite(spriteSheet, col, row);
}

void Tilemap::RenderFromSprite(SDL_Renderer* renderer)
{
	for (int i = 0; i < MapConstants::NumRows; i++)
	{
		for (int j = 0; j < MapConstants::NumCols; j++)
		{
			int x = j * MapConstants::TileWidth;
			int y = i * MapConstants::TileHeight;

			SDL_Rect destRect = { x, y, MapConstants::TileWidth, MapConstants::TileHeight };
						
			if (m_TileToSprite.count(m_Map[i][j]))
			{
				m_TileToSprite[m_Map[i][j]]->Render(renderer, &destRect);
			}
		}
	}
}

void Tilemap::LoadTilemap(const char* path)
{
	std::ifstream stream(path);

	std::string line;
	int row = 0, col = 0;
	while (std::getline(stream, line))
	{
		std::stringstream ss(line);
		std::string tileChar;

		while (std::getline(ss, tileChar, ',')) 
		{
			unsigned char tileID = std::stoi(tileChar);
			m_Map[row][col] = tileID;

			if (!m_TileToSprite.count(tileID) && tileID != 0)
			{
				int row = (int)tileID / m_MapCols;
				int col = (int)tileID % m_MapCols;
				m_TileToSprite[tileID] = new Sprite(m_WorldSheet, col, row);
			}

			col++;
		}
		row++;
		col = 0;
	}

	stream.close();
}
