#include "Engine.h"

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
            instance->graphics->Render(instance->graphics);
            instance->timer->Reset(instance->timer);
        }
    }
}

static void Destroy(Engine_t *instance)
{
    instance->graphics->Destroy(instance->graphics);
    instance->graphics = NULL;

    instance->timer->Destroy(instance->timer);
    instance->timer = NULL;

    instance->parent->Destroy(instance->parent);
    instance->parent = NULL;
    instance->child->Destroy(instance->child);
    instance->child = NULL;
}

Engine_t Engine(char *title, int width, int height)
{
    Engine_t instance = {0};

    instance.graphics = Graphics(title, width, height);
    instance.timer = Timer();
    instance.parent = Entity(100.0f, 400.0f);
    instance.child = Entity(100.0f, 500.0f);
    instance.child->SetParent(instance.child, instance.parent);

    instance.quit = false;

    instance.Run = Run;
    instance.Destroy = Destroy;

    if(!instance.graphics->initialized)
    {
        instance.quit = true;
    }

    return instance;
}