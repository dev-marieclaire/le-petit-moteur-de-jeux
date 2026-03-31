#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// loads images and handles errors.
SDL_Surface *image_load(const char *path)
{
    SDL_Surface *img = IMG_Load(path);

    if (!img) // Handles error.
    {   printf("IMG_Load: %s\n", IMG_GetError());
        exit(1);
    }

    return img;
}

SDL_RWops *bmp_ptr(const char *path)
{
    SDL_RWops *ptr = SDL_RWFromFile(path, "rb");

    if(!ptr)
    {   printf("IMG_Load: %s\n", IMG_GetError());
        exit(1);
    }

    return ptr;
}

SDL_Surface *bmp_ptr_load(SDL_RWops *ptr)
{
    SDL_Surface *bmp = IMG_LoadBMP_RW(ptr);

    if (!bmp) // Handles error.
    {   printf("IMG_Load: %s\n", IMG_GetError());
        exit(1);
    }

    return bmp;
}

// Allows the dev to load a bmp from just inserting the path.
SDL_Surface *bmp_load(const char *path)
{
    SDL_Surface *img = bmp_ptr_load(bmp_ptr(path));

    if(!img) // Handles error.
    {   printf("IMG_Load: %s\n", IMG_GetError());
        exit(1);
    }

    return img;
}
