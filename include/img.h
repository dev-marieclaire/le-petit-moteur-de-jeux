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

class bmpClass : public imageClass
{
    public:
        bmpClass(const char *src);
};

class pngClass : public imageClass
{
    public:
        pngClass(const char *src);
};

class jpegClass : public imageClass
{
    public:
        jpegClass(const char *src);
};

class tgaClass : public imageClass
{
    public:
        tgaClass(const char *src);
};

class tifClass : public imageClass
{
    public:
        tifClass(const char *src);
};
