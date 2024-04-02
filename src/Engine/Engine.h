#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Timer.h"
#include "Entity.h"

typedef struct Engine_t
{
    Graphics_t *graphics;
    Timer_t *timer;

    Entity_t *parent;
    Entity_t *child;

    bool quit;

    SDL_Event event;

    void (*Run)(struct Engine_t *instance);
    void (*Destroy)(struct Engine_t *instance);
} Engine_t;

Engine_t Engine(char *title, int width, int height);

#endif