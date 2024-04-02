#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct List_t
{
    size_t size;
    size_t dataSize;
    void *data;

    void (*Push)(struct List_t *instance, const void *data);
    void *(*At)(struct List_t *instance, int index);
    void (*Free)(struct List_t *instance);
    int (*GetSize)(struct List_t *instance);

} List_t;

List_t List(size_t dataSize);

#endif