// main.c
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "defs.h"

#include "init.h"

#include "screen.h"
#include "input.h"

#include "img.h"

game_t game;
game_t *game_ptr = &game;

game_t _game;

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

    SDL_Surface *_bmp = bmp_load("./madame.bmp");

    _game.window = init_custom_window("Madame Monet and Her Son",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    _bmp->w,   _bmp->h,
    DEFAULT_WINFLAGS
    );
    _game.renderer = init_renderer(_game.window);
    _game.surface = init_surface_from_window(_game.window);

    _game.rect.w = _bmp->w; _game.rect.h = _bmp->h;
    _game.rect.x = _game.rect.y = 0;

    SDL_Texture *_texture = SDL_CreateTextureFromSurface(_game.renderer, _bmp);

    while(true) // All game logic goes here.
    {   // #fcd7d7
        clear_screen(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);

        input(&game.event);

        SDL_RenderCopy(game.renderer, texture, NULL, &game.rect);
        present_scene(game.renderer);

        clear_screen(_game.renderer, 0xfc, 0xd7, 0xd7, 0xff);

        input(&_game.event);

        SDL_RenderCopy(_game.renderer, _texture, NULL, &_game.rect);
        present_scene(_game.renderer);
    }

    SDL_FreeSurface(bmp);

    finish();
}
