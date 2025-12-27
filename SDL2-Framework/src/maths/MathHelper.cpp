#include "MathHelper.h"

namespace MathHelper 
{
	float Clamp(float value, float min, float max)
	{
		float result = value;
		if (value < min)
			result = min;
		else if (value > max)
			result = max;

		return result;
	}
}
