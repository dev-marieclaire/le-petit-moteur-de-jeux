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

    // Displays a dithered image of Madame Monet and Her Son
    img_t madame("./madame.bmp");
    madame.createTextureFromSurface(game.renderer);

    madame.setDimensions(madame.getArea().w/2, madame.getArea().h/2);

    madame.setPosition(
        ((game.rect.w)/2)+((game.rect.w)/4)-((madame.getArea().w)/2),
        ((game.rect.h)/2)-((madame.getArea().h)/2)
    );

    // Displays a dithered image of The Houses of Parliment
    img_t house("./dither.bmp");
    house.createTextureFromSurface(game.renderer);

    house.setDimensions(house.getArea().w / 2, house.getArea().h/2);

    house.setPosition(
        ((game.rect.w)/4)-((house.getArea().w)/2),
        ((game.rect.h)/2)-((house.getArea().h)/2)
    );

    SDL_RendererInfo info;
    SDL_GetRendererInfo(game.renderer, &info);
    printf("Renderer: %s\n", info.name);
    printf("Flags: %d\n", info.flags);

    static bool rerender = true;

    while(true) // All game logic goes here.
    {
        input(&game.event);

        /* Fame measurement
        static Uint32 lastTime = 0;
        static int frames = 0;
        frames++;

        if (SDL_GetTicks() - lastTime > 1000) {
            printf("FPS: %d\n", frames);
            frames = 0;
            lastTime = SDL_GetTicks();
        }
        */

        // #fcd7d7
        if (rerender) {
            SDL_SetRenderDrawColor(game.renderer, 0xfc, 0xd7, 0xd7, 0xff);
            SDL_RenderClear(game.renderer);

            SDL_RenderCopy(game.renderer, madame.getTexture(), NULL, madame.getAreaPtr());
            SDL_RenderCopy(game.renderer, house.getTexture(), NULL, house.getAreaPtr());
            
            SDL_RenderPresent(game.renderer);
            
            rerender = false;
        }

        // Add this even with VSync
        SDL_Delay(1); // Tiny sleep prevents CPU from spinning
    }

    finish();

    return 0;
}
