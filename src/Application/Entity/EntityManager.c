#include "EntityManager.h"

uint32_t EntityManager_GetCount(EntityManager_t *instance)
{
   return instance->entityCount;
}

Entity_t EntityManager_GetEntity(EntityManager_t *instance, int index)
{
   return *(Entity_t *)instance->entityList->At(instance->entityList, index);
}

void EntityManager_AddEntity(EntityManager_t *instance)
{
   Entity_t e = instance->entityCount++;
   instance->entityList->Push(instance->entityList, &e);
}

void EntityManager_Destroy(EntityManager_t *instance)
{
   instance->entityList->Destroy(instance->entityList);
}

void EntityManager_Init(EntityManager_t *instance)
{
   instance->entityCount = 0;
   instance->entityList = List();
}
