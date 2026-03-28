#include "headers/init.h"

#include <SDL2/SDL.h>

#include "headers/main.h"
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

// Initializes a renderer with some default values and performs a checking
SDL_Renderer *init_renderer(SDL_Window *w)
{
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    SDL_Renderer *r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    if (!r)
    {   printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    return r;
}

// Initializes a renderer with custom values and performs a checking
SDL_Renderer *init_custom_renderer(SDL_Window *w, int index, uint flags)
{
    SDL_Renderer *r = SDL_CreateRenderer(w, index, flags);
    if (!r)
    {   printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    return r;
}

// Inits SDL libs and loads 
void init_all(SDL_Window **w, SDL_Renderer **r) // Initializes all.
{
    // Init libraries.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {   printf("Couldn't init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    *w = init_window();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    *r = init_renderer(*w);
}
