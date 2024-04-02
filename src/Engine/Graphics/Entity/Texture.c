#include "Texture.h"

static void Render(void *context)
{
    Texture_t *instance = context;

    instance->renderRect.w = instance->width;
    instance->renderRect.h = instance->height;


    if(!instance->entity)
    {
        instance->renderRect.x = (int)(0 - instance->width * 0.5f);
        instance->renderRect.y = (int)(0 - instance->height * 0.5f);
    }
    else
    {
        Vector2_t pos = instance->entity->GetPos(instance->entity, GLOBAL);
        instance->renderRect.x = (int)(pos.x - instance->width * 0.5f);
        instance->renderRect.y = (int)(pos.y - instance->height * 0.5f);
    }
    

    instance->graphics->DrawTexture(
        instance->graphics,
        instance->texture,
        (instance->clipped) ? &instance->clippedRect : NULL,
        &instance->renderRect);
}

void Clip(Texture_t *instance, int x, int y, int w, int h)
{
    instance->clipped = true;

    instance->width = w;
    instance->height = h;
    instance->renderRect.w = instance->width;
    instance->renderRect.h = instance->height;

    instance->clippedRect.x = x;
    instance->clippedRect.y = y;
    instance->clippedRect.w = instance->width;
    instance->clippedRect.h = instance->height;

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

    instance->Destroy = Destroy;
    instance->Render = Render;
    instance->Clip = Clip;

    instance->entity = entity;
    instance->assetManager = assetManager;
    instance->graphics = graphics;
    instance->clipped = false;

    instance->texture = instance->assetManager->GetTexture(instance->assetManager, path);

    SDL_QueryTexture(
        instance->texture,
        NULL,
        NULL,
        &instance->width,
        &instance->height);

    return instance;
}