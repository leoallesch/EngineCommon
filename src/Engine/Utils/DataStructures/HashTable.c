#include "HashTable.h"

#include <string.h>

static uint32_t Hash(const void *data)
{
   uint32_t hash = (const uint32_t) 5381;
   const char *str = (const char *)data;
   char c;
   while ((c=*str++))
   {
      hash = ((hash << 5) + hash) + c;
   }

   hash ^= hash >> 16;
   hash *= 0x3243f6a9U;
   hash ^= hash >> 16;

   return hash;
}

static HashTableEntry_t *GetEntry(HashTable_t *instance, const void *key)
{
   HashTableEntry_t *result = NULL;
   HashTableEntry_t *cur = NULL;
   List_t *curList = NULL;

   uint32_t hash = GetHash(key);
   size_t index = hash % instance->capacity;
   curList = instance->buckets[index];

   if(curList)
   {
      for(int i = 0; i < curList->size; i++)
      {
         cur = curList->array[i];
         if(cur->hash == hash)
         {
            if(strcmp(key, cur->key) == 0)
            {
               result = cur;
               break;
            }
         }
      }
   }
   return result;
}

static void *Get(HashTable_t *instance, const void *key)
{
   HashTableEntry_t *result = GetEntry(instance, key);
   if(result)
   {
      return result->value;
   }
   return NULL;
}

static void Grow(HashTable_t *instance)
{
   List_t **newbuckets;
   List_t *curBucket;
   HashTableEntry_t *curEntry;
   size_t newCapacity;
   size_t newIndex;
}

static void Destroy(HashTable_t *instance)
{
   List_t *cur;
   HashTableEntry_t *curEntry;

   for (int i = 0; i < instance->capacity; i++)
   {
      cur = instance->buckets[i];
      if(cur)
      {
         for (int j = 0; j < cur->size; j++)
         {
            curEntry = cur->array[j];
            free(curEntry->key);
            free(curEntry->value);
            free(curEntry);
         }
      }
      free(cur);
   }
   free(instance->buckets);
   free(instance);
}

HashTable_t *HashTable()
{
   HashTable_t *instance = malloc(sizeof(HashTable_t));
   if(!instance)
   {
      printf("Error allocating memory for table\n");
      free(instance);
      exit(EXIT_FAILURE);
   }

   instance->size = 0;
   instance->capacity = INITIAL_CAPACITY;
   instance->buckets = malloc(instance->capacity * sizeof(*(instance->buckets)));

   if(!instance->buckets)
   {
      printf("Error allocating memory for buckets\n");
      free(instance->buckets);
      free(instance);
      exit(EXIT_FAILURE);
   }

   for (int i = 0; i < instance->capacity; i++)
   {
      instance->buckets[i] = NULL;
   }
   return instance;
}
