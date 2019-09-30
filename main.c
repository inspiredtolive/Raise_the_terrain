#include "terrain.h"

/**
 * main - renders a grid with varying altitudes
 * @argc: number of arguments, should be 2
 * @argv: array of string arguments, should contain path to terrain file
 * Return: Success(0), Error(1)
 */
int main(int argc, const char *argv[])
{
	float *altitudes, angle = 0;
	SDL_Instance instance;

	SDL_Point **terrain_points;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./terrain <file_path>\n");
		return (1);
	}
	if (init_instance(&instance) != 0)
		return (1);
	altitudes = get_altitudes(argv[1]);
	/* creates an array of 2d points */
	init_terrain(&terrain_points);
	/* render loop */
	while (altitudes != NULL && terrain_points != NULL)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&angle) == 1)
			break;
		render_terrain(instance, terrain_points, altitudes, angle);
		SDL_RenderPresent(instance.renderer);
	}
	/* free allocated memory */
	free(terrain_points);
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
