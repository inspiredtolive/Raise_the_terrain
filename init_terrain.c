#include "terrain.h"

/**
 * init_terrain - creates an array of 2d points
 * @terrain_points: pointer to a buffer of points
 */
void init_terrain(SDL_Point ***terrain_points)
{
	int i = 0;
	float x, y, z[64];
	char *line, *token;
	size_t n;

	*terrain_points = malloc(sizeof(**terrain_points) * SIZE * SIZE);
	if (*terrain_points == NULL)
	{
		fprintf(stderr, "Malloc failed!\n");
		return;
	}
	for (i = 0, x = 0, y = 0; i < SIZE * SIZE; i++)
	{
		(*terrain_points)[i] = malloc(sizeof(SDL_Point));
		if ((*terrain_points)[i] == NULL)
		{
			fprintf(stderr, "Malloc failed!\n");
			for (i -= 1; i >= 0; i--)
				free((*terrain_points)[i]);
			free(*terrain_points);
			*terrain_points = NULL;
			return;
		}
		(*terrain_points)[i]->x = x;
		(*terrain_points)[i]->y = y;
		if (x == SIZE - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}
