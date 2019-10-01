#include "terrain.h"

/**
 * get_altitudes - opens a file of altitudes and stores them into an array
 * @file_path: path of the file to open
 * @terrain_points: pointer to array of 3d points
 * Return: Success(0), Error(1)
 */
int get_altitudes(const char *file_path, point_t ***terrain_points)
{
	int i = 0;
	size_t n;
	char *line = NULL, *token = NULL;
	FILE *terrain_file;

	terrain_file = fopen(file_path, "r");
	if (terrain_file == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return (1);
	}
	while (getline(&line, &n, terrain_file) != -1)
	{
		token = strtok(line, " \n");
		for (; token && i < SIZE * SIZE; i++, token = strtok(NULL, " \n"))
			(*terrain_points)[i]->z = atoi(token);
	}
	free(token);
	return (0);
}
