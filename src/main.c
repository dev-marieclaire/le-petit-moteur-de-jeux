// main.c
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "headers/defs.h"
#include "headers/init.h"

#include "headers/screen.h"
#include "headers/input.h"

#include "headers/img.h"

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

    SDL_Surface *bmp = bmp_load("./dither.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(game.renderer, bmp);

    game.area.w = DEFAULT_SCREEN_WIDTH; game.area.h = DEFAULT_SCREEN_HEIGHT;
    game.area.x = game.area.y = 0;

    while(true) // All game logic goes here.
    {   // #fcd7d7
        clear_screen(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);

        input(&game.event);

        SDL_RenderCopy(game.renderer, texture, NULL, &game.area);
        present_scene(game.renderer);
    }

    finish();
}
