#include "terrain.h"

/**
 * init_terrain - creates an array of 2d points
 * Return: array of 2d terrain_points
 */
SDL_Point **init_terrain(void)
{
	int i;
	float x, y;
	float z[64] = {
		120, 60, 40, 60, 20, -20, -80, -120, 40, 20, 30, 30,
		-10, -40, -90, -110, 20, 30, 10, 06, -6, -20, -26, -90,
		00, -6, 10, 10, -6, -20, -20, -40, -20, -20, -18, -14,
		-40, -20, -20, -30, -10, -10, -10, -10, -8, -20, -20, -30,
		20, 10, 10, 10, 10, 04, 10, -10, 30, 24, 24, 22, 20, 18, 14, 16
	};
	SDL_Point **terrain_points;

	terrain_points = malloc(sizeof(*terrain_points) * SIZE * SIZE);
	if (terrain_points == NULL)
	{
		fprintf(stderr, "Malloc failed!\n");
		return (NULL);
	}
	for (i = 0, x = 0, y = 0; i < SIZE * SIZE; i++)
	{
		terrain_points[i] = malloc(sizeof(SDL_Point));
		if (terrain_points[i] == NULL)
		{
			fprintf(stderr, "Malloc failed!\n");
			for (i -= 1; i >= 0; i--)
				free(terrain_points[i]);
			free(terrain_points);
			return (NULL);
		}
		terrain_points[i]->x = incline_x(x, y);
		terrain_points[i]->y = incline_y(x, y, z[i]);
		if (x == SIZE - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (terrain_points);
}
