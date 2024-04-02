#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"

typedef struct
{
    uint32_t hash;
    char *key;
    void *value;
} HashTableEntry_t;

typedef struct HashTable_t
{
    size_t capacity;
    size_t size;
    List_t **buckets;

    void (*Destroy)(struct HashTable_t *instance);
    void *(*Get)(struct HashTable_t *instance, void *key);
    void (*Put)(struct HashTable_t *instance, void *key, void *value);
} HashTable_t;

HashTable_t *HashTable();

#endif
