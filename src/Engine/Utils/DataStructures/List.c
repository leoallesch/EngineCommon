#include "List.h"

#include <stdio.h>
#include <string.h>

static int GetSize(List_t *instance)
{
    return instance->size;
}

static void *At(List_t *instance, int index)
{
    return instance->data + index * instance->dataSize;
}

static void Free(List_t *instance)
{
    free(instance->data);
    instance->data = NULL;
    instance->dataSize = 0;
    instance->size = 0;
}

static void Push(List_t *instance, const void *data)
{
    instance->size++;

    void *temp = realloc(instance->data, instance->size * instance->dataSize);
    if(temp == NULL)
    {
        printf("Error reallocating memory!");
        free(temp);
        exit(EXIT_FAILURE);
    }
    else
    {
        instance->data = temp;
        memcpy(instance->data + (instance->size-1) * instance->dataSize, data, instance->dataSize);
    }
}

List_t List(size_t dataSize)
{
    List_t instance;

    instance.Push = Push;
    instance.Free = Free;
    instance.At = At;
    instance.GetSize = GetSize;

    instance.dataSize = dataSize;

    void *temp = malloc(instance.dataSize);

    if(temp == NULL)
    {
        printf("Error allocating memory");
        free(temp);
        exit(0);
    }
    else
    {
        instance.data = temp;
        instance.size = 0;
    }

    return instance;

}