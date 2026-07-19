// init_renderer.c

#include <SDL2/SDL.h>

#include "defs.h"

// Initializes a renderer with some default values and performs a checking
SDL_Renderer *init_renderer(SDL_Window *win)
{   SDL_Renderer *r = SDL_CreateRenderer(win, -1, DEFAULT_REND_FLAGS);

    if (!r)
    {   printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    return r;
}

// Initializes a renderer with custom values and performs a checking
SDL_Renderer *init_custom_renderer(SDL_Window *win, int index, uint flags)
{   SDL_Renderer *r = SDL_CreateRenderer(win, index, flags);

    if (!r)
    {   printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    return r;
}
