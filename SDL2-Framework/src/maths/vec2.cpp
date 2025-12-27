#include "vec2.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

#define PI 3.1415f
#define DEG_TO_RAD(x) (x* PI)/180.0f

vec2::vec2()
	:x(0), y(0)
{
}

vec2::vec2(float x, float y)
	:x(x), y(y)
{
}

vec2 vec2::Rotate(const vec2& another, float degrees)
{
	float xComp = another.x * cos(DEG_TO_RAD(degrees)) + another.y * sin(DEG_TO_RAD(degrees));
	float yComp = another.x * -(sin(DEG_TO_RAD(degrees))) + another.y * cos(DEG_TO_RAD(degrees));

	return vec2(xComp, yComp);
}

vec2 vec2::operator*(float scalar)
{
	return vec2(x * scalar, y * scalar);
}

vec2 vec2::operator+(const vec2& another)
{
	return vec2(x + another.x, y + another.y);
}

vec2 vec2::GetRandomNormalVec2()
{
	float x = (rand() % 200 + 1) - 100; // -100 to 100
	float y = (rand() % 200 + 1) - 100; // -100 to 100

	float magnitude = sqrt(x * x + y * y);

	return vec2((float)x/magnitude, (float)y/magnitude);
}
