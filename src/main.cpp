// main.c

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>

#include "../include/defs.h"

#include "../include/init.h"

#include "../include/screen.h"
#include "../include/input.h"

#include "../include/img.h"

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

game_t game;

void finish()
{
    SDL_DestroyWindow(game.window);
    IMG_Quit();
    SDL_Quit();
}

int main()
{
    init_everything(game.window, game.renderer, game.surface);

    game.rect.w = DEFAULT_SCREEN_WIDTH; game.rect.h = DEFAULT_SCREEN_HEIGHT;
    game.rect.x = game.rect.y = 0;

    // printf("Window: %zu\n", sizeof(game.window));
    // printf("Renderer: %zu\n", sizeof(game.renderer));
    // printf("Surface: %zu\n\n", sizeof(game.surface));
    // printf("Rect: %zu\n", sizeof(game.rect));
    // printf("Event: %zu\n\n", sizeof(game.event));

    // printf("Event: %zu\n", sizeof(game));
    
    // SDL_Surface *bmp = bmp_load("./dither.bmp");
    // pngClass png("./dither.bmp");
    bmpClass bmp("./dither.bmp");
    bmp.createTextureFromSurface(game.renderer);

    // pngClass png("./dither.bmp");
    // png.createTextureFromSurface(game.renderer);

    while(true) // All game logic goes here.
    {   // #fcd7d7
        clear_screen(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);

        input(&game.event);

        // SDL_RenderCopy(game.renderer, bmp.getTexture(), NULL, &game.rect);
        // SDL_RenderCopy(game.renderer, png.getTexture(), NULL, &game.rect);
        SDL_RenderPresent(game.renderer);
    }

    finish();

    return 0;
}
