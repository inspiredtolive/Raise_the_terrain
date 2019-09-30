#include "terrain.h"

/**
 * main - renders a grid with varying altitudes
 * @argc: number of arguments, should be 2
 * @argv: array of string arguments, should contain path to terrain file
 * Return: Success(0), Error(1)
 */
int main(int argc, const char *argv[])
{
	int i, terrain_initalized = -1;
	float angle = 0;
	point_t **terrain_points;
	SDL_Instance instance;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./terrain <file_path>\n");
		return (1);
	}
	if (init_instance(&instance) != 0)
		return (1);
	/* creates an array of 3d points */
	if (init_terrain(&terrain_points) == 0)
		terrain_initalized = get_altitudes(argv[1], &terrain_points);
	/* render loop */
	while (terrain_initalized == 0)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&angle) == 1)
			break;
		render_terrain(instance, terrain_points, angle);
		SDL_RenderPresent(instance.renderer);
	}
	/* free allocated memory */
	for (i = 0; terrain_points &&  i < SIZE * SIZE; i++)
		free(terrain_points[i]);
	free(terrain_points);
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
