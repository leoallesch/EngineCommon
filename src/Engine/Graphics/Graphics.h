#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Graphics_t
{
    bool initialized;

    char *title;

    int screenWidth;
    int screenHeight;

    SDL_Window *window;
    SDL_Surface *buffer;

    void (*Destroy)(struct Graphics_t *instance);
    void (*Render)(struct Graphics_t *instance);
} Graphics_t;

Graphics_t *Graphics(char *title, int width, int height);

#endif