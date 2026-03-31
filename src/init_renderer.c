#include <SDL2/SDL.h>

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
