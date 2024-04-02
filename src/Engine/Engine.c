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
            instance->inputManager->Update(instance->inputManager);

            instance->aTex->Update(instance->aTex);

            if(instance->inputManager->KeyDown(
                instance->inputManager, SDL_SCANCODE_D))
            {
                instance->entity->Translate(
                    instance->entity,
                    Vec2_MultiplyScalar(Vector2(40.0f, 0.0f), instance->timer->deltaTime));
            }
            else if(instance->inputManager->KeyDown(
                instance->inputManager, SDL_SCANCODE_A))
            {
                instance->entity->Translate(
                    instance->entity,
                    Vec2_MultiplyScalar(Vector2(-40.0f, 0.0f), instance->timer->deltaTime));
            }

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
    instance->inputManager->Destroy(instance->inputManager);
    instance->inputManager = NULL;
    instance->timer->Destroy(instance->timer);
    instance->timer = NULL;
    instance->tex->Destroy(instance->tex);
    instance->tex = NULL;
    instance->aTex->Destroy(instance->aTex);
    instance->aTex = NULL;
    instance->entity->Destroy(instance->entity);
    instance->entity = NULL;
}

Engine_t Engine(char *title, int width, int height)
{
    Engine_t instance = {0};

    instance.graphics = Graphics(title, width, height);
    instance.assetManager = AssetManager(instance.graphics);
    instance.inputManager = InputManager();
    instance.timer = Timer();

    instance.quit = false;

    instance.Run = Run;
    instance.Destroy = Destroy;

    if(!instance.graphics->initialized)
    {
        instance.quit = true;
    }
    else
    {
        instance.entity = Entity(400.0f, 300.0f);

        instance.tex = Texture(
            "SpriteSheet.png",
            instance.entity,
            instance.assetManager,
            instance.graphics);

        instance.aTex = AnimatedTexture(
            instance.tex,
            instance.timer,
            104, 45, 40, 48,
            4, 3.0f, HORIZONTAL);
    }


    
    return instance;
}
