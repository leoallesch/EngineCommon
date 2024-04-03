#include "Entity.h"
#include <stdlib.h>
#include <string.h>

static void Translate(Entity_t *instance, Vector2_t vec)
{
    instance->pos = Vec2_Add(instance->pos, vec);
}

Vector2_t GetPos(Entity_t *instance, EntitySpace_t space)
{
    if(space == LOCAL || instance->parent == NULL)
    {
        return instance->pos;
    }
    else
    {
        Vector2_t parent = instance->parent->GetPos(instance->parent, GLOBAL);
        Vector2_t parentRotation = Vec2_Rotate(
            instance->pos,
            instance->parent->GetRotation(instance->parent, LOCAL));
        return Vec2_Add(parent, parentRotation);
    }
}

void SetPos(Entity_t *instance, Vector2_t pos)
{
    instance->pos = pos;
}

Entity_t *GetParent(Entity_t *instance)
{
    return instance->parent;
}

void SetParent(Entity_t *instance, Entity_t *parent)
{
    Vector2_t pos = GetPos(instance, GLOBAL);
    Vector2_t parentPos = GetPos(parent, GLOBAL);
    instance->pos = Vec2_Subtract(pos, parentPos);

    instance->parent = parent;
}

void SetActive(Entity_t *instance, bool active)
{
    instance->active = active;
}

float GetRotation(Entity_t *instance, EntitySpace_t space)
{
    if(space == LOCAL || instance->parent == NULL)
    {
        return instance->rotation;
    }
    else
    {
        return instance->parent->GetRotation(instance->parent, GLOBAL) + instance->rotation;
    }
}

void SetRotation(Entity_t *instance, float r)
{
    instance->rotation = r;

    if(instance->rotation >= 360.0f)
    {
        instance->rotation -= 360.0f;
    }
    if(instance->rotation < 0.0f)
    {
        instance->rotation += 360.0f;
    }
}

void Destroy(Entity_t *instance)
{
    instance->parent = NULL;
    free(instance);
    instance = NULL;
}

Entity_t *Entity(float x, float y)
{
    Entity_t *instance = malloc(sizeof(Entity_t));

    instance->Destroy= Destroy;
    instance->SetPos = SetPos;
    instance->GetPos = GetPos;
    instance->SetRotation = SetRotation;
    instance->GetRotation = GetRotation;
    instance->SetActive = SetActive;
    instance->SetParent = SetParent;
    instance->GetParent = GetParent;
    instance->Translate = Translate;

    instance->pos.x = x;
    instance->pos.y = y;

    instance->rotation = 0.0f;
    instance->active = true;
    instance->parent = NULL;

    return instance;
}