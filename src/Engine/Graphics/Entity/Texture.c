#include "Texture.h"

static void Render(void *context)
{
    Texture_t *instance = context;
    instance->graphics->DrawTexture(instance->graphics, instance->texture);
}

static void Destroy(Texture_t *instance)
{
    SDL_DestroyTexture(instance->texture);
    instance->texture = NULL;
    instance->graphics = NULL;
}

Texture_t *Texture(const char *path, Entity_t *entity, Graphics_t *graphics)
{
    Texture_t *instance = malloc(sizeof(Texture_t));
    memset(instance, 0, sizeof(Texture_t));

    instance->Destroy = Destroy;
    instance->Render = Render;

    instance->entity = entity;
    instance->graphics = graphics;
    instance->texture = instance->graphics->LoadTexture(
        instance->graphics,
        path);

    return instance;
}