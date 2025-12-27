#pragma once

// Map constants
// TODO: Change as you need
namespace MapConstants {
	inline constexpr int TileWidth = 32;
	inline constexpr int TileHeight = 32;
	inline constexpr int NumRows = 12;
	inline constexpr int NumCols = 40;

	inline constexpr int TotalWidth = TileWidth * NumCols; // Hover over to see the final size
	inline constexpr int TotalHeight = TileHeight * NumRows; // Hover over to see the final size
}

namespace WindowDimensions {
	inline constexpr int Width = MapConstants::TotalWidth/2;
	inline constexpr int Height = MapConstants::TotalHeight;
	inline constexpr const char* Title = "Platformer-2D";
}