// input.c

#include <SDL2/SDL.h>
#include <stdio.h>

void input(SDL_Event *e)
{
    while(SDL_PollEvent(e))
    {
        if (e->type == SDL_QUIT)
            exit(0);
        // if (e->type == SDL_WINDOWEVENT && e->window.event == SDL_WINDOWEVENT_CLOSE)
        // {
        //     SDL_Quit();
        // }

        /*if (e->window.event == SDL_WINDOWEVENT_SHOWN)
            *shown = true;
        else if (SDL_WINDOWEVENT_HIDDEN)
            *shown = false;

        // if (e->window.event == SDL_WINDOWEVENT_EXPOSED)
        
        if (e->window.event == SDL_WINDOWEVENT_ENTER)
            *mouse_focus = true;
        else if (e->window.event == SDL_WINDOWEVENT_LEAVE)
            *mouse_focus = false;
        
        if (e->window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
            *kb_focus = true;
        else if (e->window.event == SDL_WINDOWEVENT_FOCUS_LOST)
            *kb_focus = false;
        
        if (e->window.event == SDL_WINDOWEVENT_MINIMIZED)
            *minimized = true;
        else if (e->window.event == SDL_WINDOWEVENT_MAXIMIZED || SDL_WINDOWEVENT_RESTORED)
            *minimized = false; */
    }
}
