#include <SDL2/SDL.h>

#include "defs.h"

// Initializes a window with some default values and performs a checking
SDL_Window *init_window()
{
    SDL_Window *w = SDL_CreateWindow(TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Position
        DEFAULT_SCREEN_WIDTH,   DEFAULT_SCREEN_HEIGHT,  // Size
        DEFAULT_WINFLAGS
    );

    if (!w)
    {   printf("Failed to load window: %s\n", SDL_GetError());
        exit(1);
    }
    
    return w;
}

// Initializes a window with custom values and performs a checking
SDL_Window *init_custom_window(const char *title, uint x, uint y, uint w, uint h, uint flags)
{
    SDL_Window *w = SDL_CreateWindow(title, x, y, w, h, flags);

    if (!w)
    {   printf("Failed to load window: %s\n", SDL_GetError());
        exit(1);
    }
    
    return w;
}