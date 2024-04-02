#include "AssetManager.h"

#include <string.h>

static SDL_Texture *GetTexture(AssetManager_t *instance, char* filename)
{
    char path[256] = "assets/img/";
    strcat(path, filename);
    SDL_Texture* texture = (SDL_Texture *)instance->textures->Get(instance->textures, path);

    if(texture == NULL)
    {
        instance->textures->Put(
            instance->textures,
            path,
            instance->graphics->LoadTexture(instance->graphics, path));
    }
    return (SDL_Texture *)instance->textures->Get(instance->textures, path);

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
    instance->textures = HashTable();

    instance->Destroy = Destroy;
    instance->GetTexture = GetTexture;

    return instance;
}