#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Graphics.h"
#include "List.h"
#include <stdint.h>

typedef struct
{
    char *key;
    void *value;
} AssetEntry_t;

typedef struct AssetManager_t {
    Graphics_t *graphics;
    List_t *textures;

    void (*Destroy)(struct AssetManager_t *instance);
    SDL_Texture *(*GetTexture)(struct AssetManager_t *instance, char *filename);
} AssetManager_t;

AssetManager_t *AssetManager(Graphics_t *graphics);

#endif