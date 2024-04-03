#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2.h"
#include <stdbool.h>
#include <stdint.h>

enum
{
    UNKNOWN,
    LOCAL,
    GLOBAL
};
typedef uint8_t EntitySpace_t;

typedef struct Entity_t
{
    Vector2_t pos;

    float rotation;
    bool active;

    struct Entity_t *parent;

    void (*Destroy)(struct Entity_t *instance);
    void (*SetPos)(struct Entity_t *instance, Vector2_t pos);
    Vector2_t (*GetPos)(struct Entity_t *instance, EntitySpace_t space);
    void (*SetRotation)(struct Entity_t *instance, float rotation);
    float (*GetRotation)(struct Entity_t *instance, EntitySpace_t space);
    void (*SetActive)(struct Entity_t *instance, bool active);
    void (*SetParent)(struct Entity_t *instance, struct Entity_t *parent);
    struct Entity_t *(*GetParent)(struct Entity_t *instance);
    void (*Translate)(struct Entity_t *instance, Vector2_t vec);
} Entity_t;

Entity_t *Entity(float x, float y);

#endif