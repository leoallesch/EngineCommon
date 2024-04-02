#ifndef TEXTURE_H
#define TEXTURE_H

#include "Entity.h"
#include "AssetManager.h"

typedef struct Texture_t
{
    Entity_t *entity;

    SDL_Texture *texture;
    AssetManager_t *assetManager;
    Graphics_t *graphics;

    int width;
    int height;

    void (*Destroy)(struct Texture_t *instance);
    void (*Render)(void *context);
} Texture_t;

Texture_t *Texture(
    char *path,
    Entity_t *entity,
    AssetManager_t *assetManager,
    Graphics_t *graphics);

#endif