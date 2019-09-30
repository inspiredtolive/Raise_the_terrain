#include "terrain.h"

/**
 * render_terrain - draws lines between all the points in points
 * @instance: structure that contains the renderer
 * @points: array that contains the points
 * @angle: degrees to rotate the terrain
 */
void render_terrain(SDL_Instance instance, point_t **points, float angle)
{
	int i;
	float rot_x1, rot_y1, rot_x2, rot_y2, incl_x1, incl_y1, incl_x2, incl_y2;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (i = 0; i < SIZE * SIZE; i++)
	{
		rot_x1 = rotate_x(points[i], angle);
		rot_y1 = rotate_y(points[i], angle);
		incl_x1 = incline_x(rot_x1, rot_y1) + X_OFFSET;
		incl_y1 = incline_y(rot_x1, rot_y1, points[i]->z) + Y_OFFSET;
		if (i + SIZE < SIZE * SIZE)
		{
			rot_x2 = rotate_x(points[i + SIZE], angle);
			rot_y2 = rotate_y(points[i + SIZE], angle);
			incl_x2 = incline_x(rot_x2, rot_y2) + X_OFFSET;
			incl_y2 = incline_y(rot_x2, rot_y2, points[i + SIZE]->z) + Y_OFFSET;
			SDL_RenderDrawLine(instance.renderer, incl_x1, incl_y1, incl_x2, incl_y2);
		}
		if (((i + 1) % SIZE != 0 || i == 0) && i + 1 < SIZE * SIZE)
		{
			rot_x2 = rotate_x(points[i + 1], angle);
			rot_y2 = rotate_y(points[i + 1], angle);
			incl_x2 = incline_x(rot_x2, rot_y2) + X_OFFSET;
			incl_y2 = incline_y(rot_x2, rot_y2, points[i + 1]->z) + Y_OFFSET;
			SDL_RenderDrawLine(instance.renderer, incl_x1, incl_y1, incl_x2, incl_y2);
		}

	}
}
