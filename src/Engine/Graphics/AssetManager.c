#include "AssetManager.h"

#include <string.h>

static SDL_Texture *GetTexture(AssetManager_t *instance, char* filename)
{
    char path[256] = "assets/img/";
    strcat(path, filename);
    bool loaded = false;
    
    for (int i = 0; i < instance->textures->size; i++)
    {
        AssetEntry_t *entry = instance->textures->At(instance->textures, i);
        if(strcmp(entry->key, path) == 0)
        {
            loaded = true;
        }
    }

    SDL_Texture *texture = instance->graphics->LoadTexture(instance->graphics, path);

    if(!loaded)
    {
        AssetEntry_t entry = {path, texture};
        instance->textures->Push(
            instance->textures,
            &entry);
    }
    return texture;
}

static void Destroy(AssetManager_t *instance)
{
    instance->textures->Destroy(instance->textures);
    free(instance);
    instance = NULL;
}

AssetManager_t *AssetManager(Graphics_t *graphics)
{
    AssetManager_t *instance = malloc(sizeof(AssetManager_t));

    if(!instance)
    {
        printf("Error creating AssetManager\n");
        free(instance);
        exit(EXIT_FAILURE);
    }

    instance->graphics = graphics;
    instance->textures = List();

    instance->Destroy = Destroy;
    instance->GetTexture = GetTexture;

    return instance;
}