#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define INIT_CAPACITY 4
#define GROWTH_MULTI 2

typedef struct List_t
{
    size_t size;
    size_t capacity;
    void **array;

    void (*Push)(struct List_t *instance, void *data);
    void (*Set)(struct List_t *instance, void *data, size_t index);
    void *(*At)(struct List_t *instance, size_t index);
    void (*Free)(struct List_t *instance);
    size_t (*GetSize)(struct List_t *instance);

} List_t;

List_t *List();

#endif
