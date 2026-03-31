#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "headers/init.h"
#include "headers/init_window.h"
#include "headers/init_renderer.h"

// Inits SDL libs and loads 
void init_all(SDL_Window **w, SDL_Renderer **r, SDL_Surface *s) // Initializes all.
{
    // Init libraries.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {   printf("Couldn't init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    *w = init_window();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    *r = init_renderer(*w);

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted = IMG_Init(flags);

    s = SDL_GetWindowSurface(*w);

    if(initted&flags != flags)
    {   printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        // handle error
    }
}
