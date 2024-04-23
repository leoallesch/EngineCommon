#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <stdint.h>
#include "List.h"

typedef uint32_t Entity_t;

typedef struct EntityManager_t
{
   uint32_t entityCount;
   List_t *entityList;
} EntityManager_t;

uint32_t EntityManager_GetCount(EntityManager_t *instance);

Entity_t EntityManager_GetEntity(EntityManager_t *instance, int index);

void EntityManager_RemoveEntity(EntityManager_t *instance, Entity_t entity);

void EntityManager_AddEntity(EntityManager_t *instance);

void EntityManager_Destroy(EntityManager_t *instance);

void EntityManager_Init(EntityManager_t *instance);

#endif
