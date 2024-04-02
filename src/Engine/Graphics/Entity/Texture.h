#ifndef TEXTURE_H
#define TEXTURE_H

#include "Entity.h"
#include "Graphics.h"

typedef struct Texture_t
{
    Entity_t *entity;

    SDL_Texture *texture;
    Graphics_t *graphics;

    void (*Destroy)(struct Texture_t *instance);
    void (*Render)(void *context);
} Texture_t;

Texture_t *Texture(const char *path, Entity_t *entity, Graphics_t *graphics);

#endif