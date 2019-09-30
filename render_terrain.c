#include "terrain.h"

/**
 * render_terrain - draws lines between all the points in points
 * @instance: structure that contains the renderer
 * @points: array that contains the points
 */
void render_terrain(SDL_Instance instance, SDL_Point **points, float *z, float angle)
{
	int i;
	float rot_x1, rot_y1, rot_x2, rot_y2, incl_x1, incl_y1, incl_x2, incl_y2;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (i = 0; i < SIZE * SIZE; i++)
	{
		rot_x1 = rotate_x(angle, points[i]->x, points[i]->y);
		rot_y1 = rotate_y(angle, points[i]->x, points[i]->y);
		incl_x1 = incline_x(rot_x1, rot_y1) + X_OFFSET;
		incl_y1 = incline_y(rot_x1, rot_y1, z[i]) + Y_OFFSET;
		if (i + SIZE < SIZE * SIZE)
		{
			rot_x2 = rotate_x(angle, points[i + SIZE]->x, points[i + SIZE]->y);
			rot_y2 = rotate_y(angle, points[i + SIZE]->x, points[i + SIZE]->y);
			incl_x2 = incline_x(rot_x2, rot_y2) + X_OFFSET;
			incl_y2 = incline_y(rot_x2, rot_y2, z[i + SIZE]) + Y_OFFSET;
			SDL_RenderDrawLine(instance.renderer, incl_x1, incl_y1, incl_x2, incl_y2);
		}
		if (((i + 1) % SIZE != 0 || i == 0) && i + 1 < SIZE * SIZE)
		{
			rot_x2 = rotate_x(angle, points[i + 1]->x, points[i + 1]->y);
			rot_y2 = rotate_y(angle, points[i + 1]->x, points[i + 1]->y);
			incl_x2 = incline_x(rot_x2, rot_y2) + X_OFFSET;
			incl_y2 = incline_y(rot_x2, rot_y2, z[i + 1]) + Y_OFFSET;
			SDL_RenderDrawLine(instance.renderer, incl_x1, incl_y1, incl_x2, incl_y2);
		}

	}
}
