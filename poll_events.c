#include "terrain.h"

/**
 * poll_events - listens for keydown events
 * Return: Quit(1), Nothing(0)
 */
int poll_events(void)
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
		}
	}
	return (0);
}
