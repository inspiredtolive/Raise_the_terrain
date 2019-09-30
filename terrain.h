#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL2/SDL.h>
#include <math.h>

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 720
#define SIZE 8
#define LINE_LEN 120
#define X_OFFSET 630
#define Y_OFFSET 400
#define INCLINE 0.7

/**
 * struct SDL_Instance - structure to contain SDL essentials
 * @window: SDL window to render to
 * @renderer: 2D rendering context for a window
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * struct point_s - structure to hold 3d coordinates
 * @x: x-coordinate
 * @y: y-coordinate
 * @z: z-coordinate
 */
typedef struct point_s
{
	float x;
	float y;
	float z;
} point_t;

int init_instance(SDL_Instance *);
int get_altitudes(const char *file_path, point_t ***terrain_points);
int poll_events(float *angle);
int init_terrain(point_t ***terrain_points);
void render_terrain(SDL_Instance, point_t **terrain_points, float angle);
float rotate_x(point_t *point, float degrees);
float rotate_y(point_t *point, float degrees);
int incline_x(float x, float y);
int incline_y(float x, float y, float z);

#endif
