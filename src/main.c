// main.c

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>

#include "defs.h"

#include "init.h"

#include "screen.h"
#include "input.h"

#include "img.h"

game_t game;
game_t *game_ptr = &game;

void finish()
{
    SDL_DestroyWindow(game.window);
    IMG_Quit();
    SDL_Quit();
}

void main()
{
    init_all(&game_ptr->window, &game_ptr->renderer, game_ptr->surface);

    game.rect.w = DEFAULT_SCREEN_WIDTH; game.rect.h = DEFAULT_SCREEN_HEIGHT;
    game.rect.x = game.rect.y = 0;
    
    SDL_Surface *bmp = bmp_load("./dither.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(game.renderer, bmp);

    while(true) // All game logic goes here.
    {   // #fcd7d7
        clear_screen(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);

        input(&game.event);

        SDL_RenderCopy(game.renderer, texture, NULL, &game.rect);
        SDL_RenderPresent(game.renderer);
    }

    finish();
}
