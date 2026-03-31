#include <SDL2/SDL.h>

#include "init/init_window.h"
#include "init/init_renderer.h"
#include "init/init_surface.h"
#include "init/init_img.h"

// extern void init_all();
extern void init_all(SDL_Window **w, SDL_Renderer **r, SDL_Surface *s);
extern SDL_Surface *init_surface_from_window(SDL_Window *w);
