// img.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "img.h"

bmpClass::bmpClass(const char *src)
{   SDL_RWops *rw = SDL_RWFromFile(src, "rb");

    if (!rw)
    {   printf("Couldn't open %s: %s\n", src, SDL_GetError());
        exit(1);
    }

    SDL_Surface *surf = IMG_Load_RW(rw, 1);
    
    if (!surf)
    {   printf("Failed to load %s, is it a valid BMP file?: %s\n", src, IMG_GetError());
        exit(1);
    }

    imageClass::setData(surf);
}

pngClass::pngClass(const char *src)
{   SDL_RWops *rw = SDL_RWFromFile(src, "rb");

    if (!rw)
    {   printf("Couldn't open %s: %s\n", src, SDL_GetError());
        exit(1);
    }

    SDL_Surface *surf = IMG_LoadPNG_RW(rw);
    
    if (!surf)
    {   printf("Failed to load %s, is it a valid PNG file?: %s\n", src, IMG_GetError());
        exit(1);
    }

    imageClass::setData(surf);
}

jpegClass::jpegClass(const char *src)
{   SDL_RWops *rw = SDL_RWFromFile(src, "rb");

    if (!rw)
    {   printf("Couldn't open %s: %s\n", src, SDL_GetError());
        exit(1);
    }

    SDL_Surface *surf = IMG_LoadJPG_RW(rw);
    
    if (!surf)
    {   printf("Failed to load %s, is it a valid JPEG file?: %s\n", src, IMG_GetError());
        exit(1);
    }

    imageClass::setData(surf);
}

tgaClass::tgaClass(const char *src)
{   SDL_RWops *rw = SDL_RWFromFile(src, "rb");

    if (!rw)
    {   printf("Couldn't open %s: %s\n", src, SDL_GetError());
        exit(1);
    }

    SDL_Surface *surf = IMG_LoadTGA_RW(rw);
    
    if (!surf)
    {   printf("Failed to load %s, is it a valid TGA file?: %s\n", src, IMG_GetError());
        exit(1);
    }

    imageClass::setData(surf);
}

tifClass::tifClass(const char *src)
{   SDL_RWops *rw = SDL_RWFromFile(src, "rb");

    if (!rw)
    {   printf("Couldn't open %s: %s\n", src, SDL_GetError());
        exit(1);
    }

    SDL_Surface *surf = IMG_LoadTIF_RW(rw);
    
    if (!surf)
    {   printf("Failed to load %s, is it a valid TGA file?: %s\n", src, IMG_GetError());
        exit(1);
    }

    imageClass::setData(surf);
}
