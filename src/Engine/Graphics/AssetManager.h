#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Graphics.h"
#include "HashTable.h"
#include <stdint.h>

enum
{
    AssetType_Texture
};
typedef uint8_t AssetType_t;

typedef struct
{
    char *filename;
    void *data;
} AssetEntry_t;

typedef struct AssetManager_t {
    Graphics_t *graphics;
    HashTable_t *textures;

    void (*Destroy)(struct AssetManager_t *instance);
    SDL_Texture *(*GetTexture)(struct AssetManager_t *instance, char *filename);
} AssetManager_t;

AssetManager_t *AssetManager(Graphics_t *graphics);

#endif