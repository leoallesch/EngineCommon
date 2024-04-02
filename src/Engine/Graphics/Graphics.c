#include "Graphics.h"

static void Render(Graphics_t *instance)
{
    SDL_UpdateWindowSurface(instance->window);
}

static void Destroy(Graphics_t *instance)
{
    SDL_DestroyWindow(instance->window);
    instance->window = NULL;

    SDL_Quit();

    free(instance);
    instance = NULL;
}

static bool Init(Graphics_t *instance, char *title, int width, int height)
{
    instance->title = title;
    instance->screenWidth = width;
    instance->screenHeight = height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL Init Error %s\n", SDL_GetError());
        return false;
    }

    instance->window = SDL_CreateWindow(
        instance->title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        instance->screenWidth,
        instance->screenHeight,
        SDL_WINDOW_SHOWN);

    if(!instance->window)
    {
        printf("Error creating window %s\n", SDL_GetError());
        return false;
    }

    instance->buffer = SDL_GetWindowSurface(
        instance->window
    );

    return true;

}

Graphics_t *Graphics(char *title, int width, int height)
{
    Graphics_t *instance = malloc(sizeof(Graphics_t));
    memset(instance, 0, sizeof(Graphics_t));

    instance->initialized = Init(instance, title, width, height);

    instance->Destroy = Destroy;
    instance->Render = Render;

    return instance;
}