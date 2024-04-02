#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include "List.h"

typedef struct MapNode_t
{
    char *key;
    void *value;
    size_t dataSize;
} MapNode_t;

typedef struct Map_t
{

    void (*Insert)(struct Map_t *instance, const char*key, const void *data);
} Map_t;

Map_t Map();


#endif