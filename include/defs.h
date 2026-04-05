#define _GNU_SOURCE 1
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TITLE "Game"

#define DEFAULT_SCREEN_WIDTH    800
#define DEFAULT_SCREEN_HEIGHT   600

#define DEFAULT_WINFLAGS 0
#define DEFAULT_REND_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define DEFAULT_IMG_FLAGS IMG_INIT_JPG|IMG_INIT_PNG

// Struct that defines the highest-level information about the application/game
typedef struct game_t
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    SDL_Surface     *surface;

    SDL_Rect        rect;
    SDL_Event       event;

    bool    shown;
    bool    mouse_focus;
    bool    keyboard_focus;
    bool    minimized;
}game_t;
