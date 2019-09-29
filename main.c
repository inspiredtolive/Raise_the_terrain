#include "terrain.h"

/**
 * main - renders a grid with varying altitudes
 * Return: Success(0), Error(1)
 */
int main(void)
{
	SDL_Instance instance;

	SDL_Point **terrain_points;

	if (init_instance(&instance) != 0)
		return (1);

	/* creates an array of 2d points */
	terrain_points = init_terrain();
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
