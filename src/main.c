#include <stdio.h>

#include "Engine.h"
#include "List.h"
#include "HashTable.h"

static char *title = "SDL2 Engine";
static int SCREEN_WIDTH = 800;
static int SCREEN_HEIGHT = 600;

int main ()
{
    Engine_t engine = Engine(title, SCREEN_WIDTH, SCREEN_HEIGHT);

    printf("Game is running...\n");

    engine.Run(&engine);
    engine.Destroy(&engine);

    printf("Exiting...\n");

    return 0;
}
