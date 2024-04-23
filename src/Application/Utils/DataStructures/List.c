#include "List.h"

#include <stdio.h>
#include <string.h>

#define INIT_CAPACITY 4
#define GROWTH_MULTI 2

static size_t GetSize(List_t *instance)
{
    return instance->size;
}

static void *At(List_t *instance, size_t index)
{
    if(index >= instance->size)
    {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return instance->array[index];
}

static void Destroy(List_t *instance)
{
    free(instance->array);
    free(instance);
}

static void Set(List_t *instance, void *data, size_t index)
{
    if(index >= instance->size)
    {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    instance->array[index] = data;
}

static void Push(List_t *instance, void *data)
{
    if(!(instance->size < instance->capacity))
    {
        uint64_t tmp = (uint64_t) GROWTH_MULTI * (uint64_t) instance->capacity;
        if(tmp > SIZE_MAX)
        {
            printf("Size overflow\n");
            exit(EXIT_FAILURE);
        }

        size_t newCapacity = (size_t)tmp;
        void *new = malloc(newCapacity * sizeof(*(instance->array)));

        if(!new)
        {
            printf("Error reallocating array memory\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new, instance->array, instance->size * sizeof(*(instance->array)));
        free(instance->array);
        instance->array = new;
        instance->capacity = newCapacity;
    }
    instance->array[instance->size] = data;
    instance->size++;
}

List_t *List()
{
    List_t *instance = malloc(sizeof(List_t));

    if(!instance)
    {
        printf("Error allocating memory for list\n");
        free(instance);
        return NULL;
    }

    instance->capacity = INIT_CAPACITY;
    instance->size = 0;
    instance->array = malloc(instance->capacity * sizeof(*(instance->array)));

    if(!instance->array)
    {
        printf("Error allocating memory for array\n");
        free(instance->array);
        free(instance);
        return NULL;
    }

    instance->Push = Push;
    instance->Set = Set;
    instance->Destroy = Destroy;
    instance->At = At;
    instance->GetSize = GetSize;

    return instance;
}
