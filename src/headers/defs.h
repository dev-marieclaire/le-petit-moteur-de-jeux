#define _GNU_SOURCE 1
#include <SDL2/SDL.h>

#define TITLE "Game"

#define DEFAULT_SCREEN_WIDTH    800
#define DEFAULT_SCREEN_HEIGHT   600

#define DEFAULT_WINFLAGS 0

// Struct that defines the highest-level information about the application/game
typedef struct game_t
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;

    SDL_Event       event;
}game_t;
