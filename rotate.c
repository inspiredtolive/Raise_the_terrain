#include "terrain.h"

float rotate_x(float degrees, float x, float y)
{
	float radians = degrees * M_PI / 100;

	return (x * cos(radians) - y * sin(radians));
}

float rotate_y(float degrees, float x, float y)
{
	float radians = degrees * M_PI / 100;

	return (x * sin(radians) + y * cos(radians));
}
