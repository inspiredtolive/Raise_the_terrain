#include "terrain.h"

/**
 * incline_x - compute x coordinate incline
 * @x: x coordinate
 * @y: y coordinate
 * Return: inclined x coordinate
 */
int incline_x(float x, float y)
{
	return ((INCLINE * x - INCLINE * y) * LINE_LEN + X_OFFSET);
}

/**
 * incline_y - compute y coordinate incline
 * @x: x coordinate
 * @y: y coordinate
 * @z: z coordinate
 * Return: inclined y coordinate
 */
int incline_y(float x, float y, float z)
{
	return (((1 - INCLINE) * x + (1 - INCLINE) * y - z / 100) * LINE_LEN
	+ Y_OFFSET);
}
