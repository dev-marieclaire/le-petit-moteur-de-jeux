#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Surface *image_load(const char *path);
extern SDL_RWops *bmp_ptr(const char *path);
extern SDL_Surface *bmp_ptr_load(SDL_RWops *ptr);
extern SDL_Surface *bmp_load(const char *path);
