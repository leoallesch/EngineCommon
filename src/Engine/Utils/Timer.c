#include "Timer.h"

#include <stdlib.h>
#include <string.h>
#include "SDL.h"

static void SetTimeScale(Timer_t *instance, float scale)
{
    instance->timeScale = scale;
}

static void Update(Timer_t *instance)
{
    instance->elapsedTicks = SDL_GetTicks() - instance->startTicks;
    instance->deltaTime = instance->elapsedTicks * 0.001f;
}

static void Reset(Timer_t *instance)
{
    instance->startTicks = SDL_GetTicks();
    instance->elapsedTicks = 0;
    instance->deltaTime = 0.0f;
}

static void Destroy(Timer_t *instance)
{
    free(instance);
    instance = NULL;
}

static void Init(Timer_t *instance)
{
    Reset(instance);
    instance->timeScale = 1.0f;
}

Timer_t *Timer()
{
    Timer_t *instance = malloc(sizeof(Timer_t));

    instance->Destroy = Destroy;
    instance->Reset = Reset;
    instance->Update = Update;
    instance->SetTimeScale = SetTimeScale;

    Init(instance);

    return instance;
}
