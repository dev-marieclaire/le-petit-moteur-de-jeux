
#include <SDL2/SDL.h>
#include <stdio.h>

void input(SDL_Event *e)
{
    while(SDL_PollEvent(e))
    {
        if (e->type == SDL_QUIT)
            exit(0);
    }
}
