// main.c
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "headers/defs.h"
#include "headers/init.h"

#include "headers/screen.h"
#include "headers/input.h"

game_t game;
game_t *game_ptr = &game;

void finish()
{
    SDL_DestroyWindow(game.window);
    SDL_Quit();
}

void main()
{
    init_all(&game_ptr->window, &game_ptr->renderer);

    while(true) // All game logic goes here.
    {   // #fcd7d7
        clear_screen(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);
        input(&game.event);
        present_scene(game.renderer);
    }

    finish();
}
