#pragma once
#include "src/maths/vec2.h"
#include "src/map/MapConstants.h"

struct Camera
{
	static float CamTopLeftX, CamTopLeftY;

	static void Update(const vec2& playerPosition, const vec2& playerDimension);
};

