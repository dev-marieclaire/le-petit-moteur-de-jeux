#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Surface *image_load(const char *path);
extern SDL_RWops *bmp_ptr(const char *path);
extern SDL_Surface *bmp_ptr_load(SDL_RWops *ptr);
extern SDL_Surface *bmp_load(const char *path);

class imageClass {
    private:
        // Image properties. Area may be unused.
        SDL_Rect area;
        SDL_Surface *data;
        SDL_Texture *texture;

        // Each class has its own implementation of this method. See img.cpp.
        // Returns a non-zero value if successful.
        virtual int assignImage(const char *src) = 0;

        // Frees the memory assigned to the image.
        void clean()
        {
            if (data) SDL_FreeSurface(data);
            if (texture) SDL_DestroyTexture(texture);
        }

    public:
        // Getter zone
        SDL_Rect getArea()
        { return area; }

        SDL_Surface *getData()
        { return data; }

        SDL_Texture *getTexture()
        { return texture; }

        // Setter zone
        void setData(SDL_Surface *src)
        { data = src; }

        // Autres choses
        void createTextureFromSurface(SDL_Renderer *renderer)
        { texture = SDL_CreateTextureFromSurface(renderer, data); }

        void reimport(const char *src)
        { clean(); assignImage(src); }

        ~imageClass()
        { clean(); }
};

/* Format import */

class bmpClass : public imageClass
{
    private:
        int assignImage(const char *src);

    public:
        bmpClass(const char *src)
        { assignImage(src); }
};

class pngClass : public imageClass
{
    private:
        int assignImage(const char *src);

    public:
        pngClass(const char *src)
        { assignImage(src); }
};

class jpegClass : public imageClass
{
    private:
        int assignImage(const char *src);

    public:
        jpegClass(const char *src)
        { assignImage(src); }
};

class tgaClass : public imageClass
{
    private:
        int assignImage(const char *src);

    public:
        tgaClass(const char *src)
        { assignImage(src); }
};

class tifClass : public imageClass
{
    private:
        int assignImage(const char *src);

    public:
        tifClass(const char *src)
        { assignImage(src); }
};
