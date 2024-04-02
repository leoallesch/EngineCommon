#ifndef ENGINE_H
#define ENGINE_H

// #include <SDL2/SDL.h>
#include "SDL.h"
#include "AssetManager.h"
#include "Texture.h"
#include "Timer.h"

typedef struct Engine_t
{
    Graphics_t *graphics;
    AssetManager_t *assetManager;
    Timer_t *timer;
    Texture_t *tex;

    bool quit;

    SDL_Event event;

    void (*Run)(struct Engine_t *instance);
    void (*Destroy)(struct Engine_t *instance);
} Engine_t;

Engine_t Engine(char *title, int width, int height);

#endif
