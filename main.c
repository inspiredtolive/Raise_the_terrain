#include "terrain.h"

/**
 * main - renders a grid with varying altitudes
 * @argc: number of arguments, should be 2
 * @argv: array of string arguments, should contain path to terrain file
 * Return: Success(0), Error(1)
 */
int main(int argc, const char *argv[])
{
	FILE *terrain_file;
	SDL_Instance instance;

	SDL_Point **terrain_points;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./terrain <file_path>\n");
		return (1);
	}
	terrain_file = fopen(argv[1], "r");
	if (terrain_file == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return (1);
	}

	if (init_instance(&instance) != 0)
		return (1);

	/* creates an array of 2d points */
	init_terrain(&terrain_points, terrain_file);
	/* render loop */
	while (terrain_points != NULL)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		render_terrain(instance, terrain_points);
		SDL_RenderPresent(instance.renderer);
	}
	/* free allocated memory */
	free(terrain_points);
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
