#include "Texture.h"

static void Render(void *context)
{
    Texture_t *instance = context;
    instance->graphics->DrawTexture(instance->graphics, instance->texture);
}

static void Destroy(Texture_t *instance)
{
    instance->texture = NULL;
    instance->assetManager = NULL;
    instance->graphics = NULL;
}

Texture_t *Texture(
    char *path,
    Entity_t *entity,
    AssetManager_t *assetManager,
    Graphics_t *graphics)
{
    Texture_t *instance = malloc(sizeof(Texture_t));
    memset(instance, 0, sizeof(Texture_t));

    instance->Destroy = Destroy;
    instance->Render = Render;

    instance->entity = entity;
    instance->assetManager = assetManager;
    instance->graphics = graphics;

    instance->texture = instance->assetManager->GetTexture(instance->assetManager, path);

    SDL_QueryTexture(
        instance->texture,
        NULL,
        NULL,
        &instance->width,
        &instance->height);
    
    return instance;
}