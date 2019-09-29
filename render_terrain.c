#include "terrain.h"

/**
 * render_terrain - draws lines between all the points in terrain_points
 * @instance: structure that contains the renderer
 * @terrain_points: array that contains the points
 */
void render_terrain(SDL_Instance instance, SDL_Point **terrain_points)
{
	int i;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (i = 0; i < SIZE * SIZE; i++)
	{
		if (i + SIZE < SIZE * SIZE)
			SDL_RenderDrawLine(instance.renderer, terrain_points[i]->x,
				terrain_points[i]->y, terrain_points[i + SIZE]->x,
				terrain_points[i + SIZE]->y);
			if (i != 0 && i % SIZE != 0)
				SDL_RenderDrawLine(instance.renderer, terrain_points[i - 1]->x,
					terrain_points[i - 1]->y, terrain_points[i]->x,
					terrain_points[i]->y);
	}
}
