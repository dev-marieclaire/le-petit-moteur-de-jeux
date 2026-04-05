// init_surface.c

#include <SDL2/SDL.h>

SDL_Surface *init_surface_from_window(SDL_Window *w)
{
    SDL_Surface *s = SDL_GetWindowSurface(w);
    if (!s)
    {
        printf("Couldn't init SDL: %s\n", SDL_GetError()); exit(1);
    }

    return s;
}
