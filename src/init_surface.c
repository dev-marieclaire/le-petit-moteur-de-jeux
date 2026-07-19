// init_surface.c

#include <SDL2/SDL.h>

SDL_Surface *init_surface_from_window(SDL_Window *win)
{
    SDL_Surface *s = SDL_GetWindowSurface(win);
    
    if (!SDL_HasWindowSurface(win))
    {   printf("Failed to create surface from window: %s\n", SDL_GetError());
        exit(1);
    }

    return s;
}
