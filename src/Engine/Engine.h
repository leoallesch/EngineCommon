#ifndef ENGINE_H
#define ENGINE_H

#include "AssetManager.h"
#include "InputManager.h"
#include "AnimatedTexture.h"

typedef struct Engine_t
{
    Graphics_t *graphics;

    AssetManager_t *assetManager;
    InputManager_t *inputManager;

    Timer_t *timer;

    Entity_t *entity;
    Texture_t *tex;
    AnimatedTexture_t *aTex;

    bool quit;

    SDL_Event event;

    void (*Run)(struct Engine_t *instance);
    void (*Destroy)(struct Engine_t *instance);
} Engine_t;

Engine_t Engine(char *title, int width, int height);

#endif
