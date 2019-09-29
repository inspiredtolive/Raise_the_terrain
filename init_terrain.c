#include "terrain.h"

/**
 * init_terrain - creates an array of 2d points
 * @terrain_points: pointer to a buffer of points
 * @terrain_file: pointer to terrain file
 */
void init_terrain(SDL_Point ***terrain_points, FILE *terrain_file)
{
	int i = 0;
	float x, y, z[64];
	char *line, *token;
	size_t n;

	while (getline(&line, &n, terrain_file) != -1)
	{
		token = strtok(line, " \n");
		for (; token && i < 64; i++, token = strtok(NULL, " \n"))
			z[i] = atoi(token);
	}
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
		(*terrain_points)[i]->x = incline_x(x, y);
		(*terrain_points)[i]->y = incline_y(x, y, z[i]);
		if (x == SIZE - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}
