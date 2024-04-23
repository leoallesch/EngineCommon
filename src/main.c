#include <stdio.h>

#include "EntityManager.h"

int main ()
{
    EntityManager_t manager;

    EntityManager_Init(&manager);

    EntityManager_AddEntity(&manager);
    EntityManager_AddEntity(&manager);
    EntityManager_AddEntity(&manager);
    EntityManager_AddEntity(&manager);

    for(uint32_t i = 0; i < EntityManager_GetCount(&manager); i++)
    {
        printf("Entity ID: %d\n", EntityManager_GetEntity(&manager, i));
    }

    EntityManager_Destroy(&manager);
    return 0;
}
