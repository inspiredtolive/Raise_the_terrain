#include "terrain.h"

/**
 * rotate_x - compute x-point rotation
 * @point: 3d point
 * @degrees: degrees to rotate the terrain
 * Return: rotated x-point
 */
float rotate_x(point_t *point, float degrees)
{
	float radians = degrees * M_PI / 100;

	return (point->x * cos(radians) - point->y * sin(radians));
}

/**
 * rotate_y - compute y-point rotation
 * @point: 3d point
 * @degrees: degrees to rotate the terrain
 * Return: rotated y-point
 */
float rotate_y(point_t *point, float degrees)
{
	float radians = degrees * M_PI / 100;

	return (point->x * sin(radians) + point->y * cos(radians));
}
