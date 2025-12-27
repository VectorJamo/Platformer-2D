#pragma once
// TODO: Complete it.

struct vec2
{
	union 
	{
		struct 
		{
			float x, y; 
		};
		struct
		{
			float width, height;
		};
		struct
		{
			float a, b;
		};

	};

	vec2();
	vec2(float x, float y);

	static vec2 Rotate(const vec2& another, float degress);
	vec2 operator*(float scalar);
	vec2 operator+(const vec2& another);

	static vec2 GetRandomNormalVec2();
};

