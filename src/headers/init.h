#include <SDL2/SDL.h>

/* UNUSED, for the moment...*/
extern SDL_Window *init_window();
extern SDL_Window *init_custom_window(const char *title, uint x, uint y, uint w, uint h, uint flags);
extern SDL_Renderer *init_renderer(SDL_Window *w);
extern SDL_Renderer *init_custom_renderer(SDL_Window *w, int index, uint flags);

// extern void init_all();
extern void init_all(SDL_Window **w, SDL_Renderer **r);
