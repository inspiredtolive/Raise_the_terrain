#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL2/SDL.h>

#define SIZE 8
#define LINE_LEN 120
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
int poll_events(void);
void init_terrain(SDL_Point ***terrain_points, FILE *terrain_file);
void render_terrain(SDL_Instance instance, SDL_Point **terrain_points);
int incline_x(float x, float y);
int incline_y(float x, float y, float z);

#endif
