#include <SDL2/SDL.h>

#include "defs.h"

#include "init/init_window.h"
#include "init/init_renderer.h"
#include "init/init_surface.h"
#include "init/init_img.h"

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

    s = init_surface_from_window(*w);

    init_img(DEFAULT_IMG_FLAGS);
}
