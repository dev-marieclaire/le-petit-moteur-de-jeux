#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Surface *image_load(const char *path);
extern SDL_RWops *bmp_ptr(const char *path);
extern SDL_Surface *bmp_ptr_load(SDL_RWops *ptr);
extern SDL_Surface *bmp_load(const char *path);


class imageClass {
    private:
        SDL_Rect area;
        SDL_Surface *data;
        SDL_Texture *texture;

    public:
        SDL_Rect getArea()
        { return area; }

        SDL_Surface *getData()
        { return data; }

        SDL_Texture *getTexture()
        { return texture; }

        void createTextureFromSurface(SDL_Renderer *renderer)
        { texture = SDL_CreateTextureFromSurface(renderer, data); }

        void setData(SDL_Surface *src)
        { data = src; }
};

class pngClass : public imageClass
{
    public:
    pngClass(const char *src)
    {
        SDL_RWops *rw = SDL_RWFromFile(src, "rb");

        if (!rw) {
            printf("Couldn't open %s: %s\n", src, SDL_GetError());
            exit(1);
        }

        SDL_Surface *surf = IMG_LoadPNG_RW(rw);
    
        if (!surf) {
            printf("Failed to load %s, is it a valid PNG file?: %s\n", src, IMG_GetError());
            exit(1);
        }

        imageClass::setData(surf);
    }
};

class bmpClass : public imageClass
{
    public:
    bmpClass(const char *src)
    {
        SDL_RWops *rw = SDL_RWFromFile(src, "rb");

        if (!rw) {
            printf("Couldn't open %s: %s\n", src, SDL_GetError());
            exit(1);
        }

        SDL_Surface *surf = IMG_Load_RW(rw, 1);
    
        if (!surf) {
            printf("Failed to load %s, is it a valid BMP file?: %s\n", src, IMG_GetError());
            exit(1);
        }

        imageClass::setData(surf);
    }
};

