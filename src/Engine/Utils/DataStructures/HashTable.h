#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include "List.h"

#define INITIAL_CAPACITY 1024

typedef struct
{
    uint32_t hash;
    const char *key;
    void *value;
} HashTableEntry_t;

typedef struct HashTable_t
{
    size_t capacity;
    size_t size;
    List_t **buckets;

    void (*Destroy)(struct HashTable_t *instance);
    void *(*Get)(struct HashTable_t *instance, const void *key);
} HashTable_t;

HashTable_t *HashTable();

#endif
