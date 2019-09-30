#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL2/SDL.h>
#include <math.h>

#define SIZE 8
#define LINE_LEN 60
#define X_OFFSET 630
#define Y_OFFSET 200
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

int init_instance(SDL_Instance *);
float *get_altitudes(const char *file_path);
int poll_events(float *angle);
void init_terrain(SDL_Point ***terrain_points);
void render_terrain(SDL_Instance instance, SDL_Point **terrain_points, float *altitudes, float angle);
float rotate_x(float degrees, float x, float y);
float rotate_y(float degrees, float x, float y);
int incline_x(float x, float y);
int incline_y(float x, float y, float z);

#endif
