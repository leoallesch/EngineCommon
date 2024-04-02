#include "Engine.h"
#include <string.h>

static const int FPS = 60;

static void Run(Engine_t *instance)
{
    while(!instance->quit)
    {
        instance->timer->Update(instance->timer);

        while(SDL_PollEvent(&instance->event) != 0)
        {
            switch(instance->event.type)
            {
                case SDL_QUIT:
                    instance->quit = true;
            }
        }
        if(instance->timer->deltaTime >= 1.0f / FPS)
        {
            instance->graphics->ClearBuffer(instance->graphics);

            instance->tex->Render(instance->tex);

            instance->graphics->Render(instance->graphics);

            instance->timer->Reset(instance->timer);
        }
    }
}

static void Destroy(Engine_t *instance)
{
    instance->graphics->Destroy(instance->graphics);
    instance->graphics = NULL;

    instance->assetManager->Destroy(instance->assetManager);
    instance->assetManager = NULL;

    instance->timer->Destroy(instance->timer);
    instance->timer = NULL;
}

Engine_t Engine(char *title, int width, int height)
{
    Engine_t instance = {0};

    instance.graphics = Graphics(title, width, height);
    instance.assetManager = AssetManager(instance.graphics);
    instance.timer = Timer();

    instance.quit = false;

    instance.Run = Run;
    instance.Destroy = Destroy;

    if(!instance.graphics->initialized)
    {
        instance.quit = true;
    }

    instance.tex = Texture(
        "redcircle.png",
        NULL,
        instance.assetManager,
        instance.graphics);
    
    return instance;
}
