#define _GNU_SOURCE 1
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TITLE "Game"

#define DEFAULT_SCREEN_WIDTH    800
#define DEFAULT_SCREEN_HEIGHT   600

#define DEFAULT_WINFLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS
#define DEFAULT_REND_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define DEFAULT_IMG_FLAGS IMG_INIT_JPG | IMG_INIT_PNG

// Struct that defines the highest-level information about the application/game
typedef struct game_t
{
    SDL_Window      *window; // 8 Bytes
    SDL_Renderer    *renderer; // 8 Bytes
    SDL_Surface     *surface; // 8 Bytes

    SDL_Rect        rect; // 16 Bytes
    SDL_Event       event; // 56 Bytes

    // bool    shown; // 1 Bytes
    // bool    mouse_focus;
    // bool    keyboard_focus;
    // bool    minimized;
}game_t;
