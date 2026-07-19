// init.c

#include <SDL2/SDL.h>

#include "defs.h"

#include "init/init_window.h"
#include "init/init_renderer.h"
#include "init/init_surface.h"
#include "init/init_img.h"

// Inits SDL libs and loads defaults.
void init_everything(SDL_Window *w, SDL_Renderer *r, SDL_Surface *s) // Initializes all.
{
    // Init libraries.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {   printf("Couldn't init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // Initializes the window.
    w = init_window();

    // Sets the renderer hint.
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    // SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "0");
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");

    if (w != NULL)
    {   r = init_renderer(w);
        if (!r)
        {   printf("Coudln't create SDL Renderer: %s", SDL_GetError());
            exit(1);
        }

        s = init_surface_from_window(w);

        if (!s)
        {   printf("Coudln't create SDL Surface: %s", SDL_GetError());
            exit(1);
        }
    }
    else
    { printf("Error: Window doesn't exist."); }

    init_img(DEFAULT_IMG_FLAGS);
}
