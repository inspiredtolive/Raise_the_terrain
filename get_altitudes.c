#include "terrain.h"

float *get_altitudes(const char *file_path)
{
	int i = 0;
	size_t n;
	float *z;
	char *line, *token;
	FILE *terrain_file;

	z = malloc(sizeof(*z) * SIZE * SIZE);
	if (z == NULL)
	{
		fprintf(stderr, "Malloc failed!\n");
		return (NULL);
	}
	terrain_file = fopen(file_path, "r");
	if (terrain_file == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return (NULL);
	}
	while (getline(&line, &n, terrain_file) != -1)
	{
		token = strtok(line, " \n");
		for (; token && i < 64; i++, token = strtok(NULL, " \n"))
			z[i] = atoi(token);
	}
	return (z);
}
