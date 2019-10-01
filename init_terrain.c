#include "terrain.h"

/**
 * init_terrain - creates an array of 2d points
 * @terrain_points: pointer to a buffer of points
 * Return: Success(0), Error(1)
 */
int init_terrain(point_t ***terrain_points)
{
	int i = 0;
	float x, y;

	*terrain_points = malloc(sizeof(**terrain_points) * SIZE * SIZE);
	if (*terrain_points == NULL)
	{
		fprintf(stderr, "Malloc failed!\n");
		return (1);
	}
	for (i = 0, x = -3.5, y = -3.5; i < SIZE * SIZE; i++)
	{
		(*terrain_points)[i] = malloc(sizeof(SDL_Point));
		if ((*terrain_points)[i] == NULL)
		{
			fprintf(stderr, "Malloc failed!\n");
			for (i -= 1; i >= 0; i--)
				free((*terrain_points)[i]);
			free(*terrain_points);
			*terrain_points = NULL;
			return (1);
		}
		(*terrain_points)[i]->x = x;
		(*terrain_points)[i]->y = y;
        (*terrain_points)[i]->z = z;
		if (x == SIZE - 4.5)
		{
			x = -3.5;
			y++;
		}
		else
			x++;
	}
	return (0);
}
