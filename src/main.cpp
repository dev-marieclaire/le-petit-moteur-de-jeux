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

void finish()
{
    SDL_DestroyWindow(game.window);
    IMG_Quit();
    SDL_Quit();
}

int main()
{
    init_everything(&game);

    img_t bmp("./madame.bmp");
    bmp.createTextureFromSurface(game.renderer);

    bmp.setPosition(
        ((game.rect.w)/2)-((bmp.getArea().w)/2),
        ((game.rect.h)/2)-((bmp.getArea().h)/2)
    );

    while(true) // All game logic goes here.
    {   // #fcd7d7
        SDL_SetRenderDrawColor(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);
        SDL_RenderClear(game.renderer);

        input(&game.event);

        SDL_RenderCopy(game.renderer, bmp.getTexture(), NULL, bmp.getAreaPtr());
        
        SDL_RenderPresent(game.renderer);
    }

    finish();

    return 0;
}
