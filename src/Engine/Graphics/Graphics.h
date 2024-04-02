#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL.h"
#include "SDL_image.h"
#include <stdbool.h>

typedef struct Graphics_t
{
    bool initialized;

    char *title;

    int screenWidth;
    int screenHeight;

    SDL_Window *window;
    SDL_Surface *buffer;

    SDL_Renderer *renderer;

    void (*Destroy)(struct Graphics_t *instance);
    void (*Render)(struct Graphics_t *instance);
    SDL_Texture *(*LoadTexture)(struct Graphics_t *instance, const char* path);
    void (*ClearBuffer)(struct Graphics_t *instance);
    void (*DrawTexture)(struct Graphics_t *instance, SDL_Texture *tex, SDL_Rect *clip, SDL_Rect *rend);
} Graphics_t;

Graphics_t *Graphics(char *title, int width, int height);

#endif
