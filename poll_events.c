#include "terrain.h"

/**
 * poll_events - listens for keydown events
 * @angle: angle to rotate terrain
 * Return: Quit(1), Nothing(0)
 */
int poll_events(float *angle)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				if (key.keysym.scancode == 0x29)
					return (1);
				else if (key.keysym.scancode == SDL_SCANCODE_LEFT)
					*angle += 5;
				else if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
					*angle -= 5;
		}
	}
	return (0);
}
