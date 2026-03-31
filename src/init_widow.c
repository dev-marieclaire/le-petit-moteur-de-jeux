#include <SDL2/SDL.h>

#include "headers/init_window.h"
#include "headers/defs.h"

// Initializes a window with some default values and performs a checking
SDL_Window *init_window()
{
    SDL_Window *win = SDL_CreateWindow(TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Position
        DEFAULT_SCREEN_WIDTH,   DEFAULT_SCREEN_HEIGHT,  // Size
        DEFAULT_WINFLAGS
    );

    if (!win)
    {   printf("Failed to load window: %s\n", SDL_GetError());
        exit(1);
    }
    
    return win;
}

// Initializes a window with custom values and performs a checking
SDL_Window *init_custom_window(const char *title, uint x, uint y, uint w, uint h, uint flags)
{
    SDL_Window *win = SDL_CreateWindow(title, x, y, w, h, flags);

    if (!win)
    {   printf("Failed to load window: %s\n", SDL_GetError());
        exit(1);
    }
    
    return win;
}