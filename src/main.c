#include <stdio.h>

#include "Engine.h"

int main ()
{
    Engine_t engine = Engine("SDL2 Engine", 1280, 720);

    printf("Game is running...\n");

    engine.Run(&engine);
    engine.Destroy(&engine);
    
    printf("Exiting...\n");

    return 0;
}