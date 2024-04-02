#include "Graphics.h"

void DrawTexture(Graphics_t *instance, SDL_Texture *tex)
{
    SDL_RenderCopy(instance->renderer, tex, NULL, NULL);
}

void ClearBuffer(Graphics_t *instance)
{
    SDL_RenderClear(instance->renderer);
}

SDL_Texture *LoadTexture(Graphics_t *instance, const char *path)
{
    SDL_Texture *tex = NULL;

    SDL_Surface *surface = IMG_Load(path);
    if(!surface)
    {
        printf("Error Loading Image: Path(%s) - Error %s\n", path, IMG_GetError());
        return NULL;
    }

    tex = SDL_CreateTextureFromSurface(instance->renderer, surface);

    if(!tex)
    {
        printf("Error creating texture: %s", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);
    return tex;
}

static void Render(Graphics_t *instance)
{
    SDL_RenderPresent(instance->renderer);
}

static void Destroy(Graphics_t *instance)
{
    SDL_DestroyWindow(instance->window);
    instance->window = NULL;

    SDL_DestroyRenderer(instance->renderer);
    instance->renderer = NULL;

    IMG_Quit();
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

    instance->renderer = SDL_CreateRenderer(
        instance->window,
        -1,
        SDL_RENDERER_ACCELERATED);

    if(!instance->renderer)
    {
        printf("Error creating renderer %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int flags = IMG_INIT_PNG;

    if(!(IMG_Init(flags) & flags))
    {
        printf("IMG Init Error: %s\n", IMG_GetError());
        return false;
    }

    instance->buffer = SDL_GetWindowSurface(instance->window);

    return true;

}

Graphics_t *Graphics(char *title, int width, int height)
{
    Graphics_t *instance = malloc(sizeof(Graphics_t));
    memset(instance, 0, sizeof(Graphics_t));

    instance->initialized = Init(instance, title, width, height);

    instance->Destroy = Destroy;
    instance->Render = Render;
    instance->LoadTexture = LoadTexture;
    instance->ClearBuffer = ClearBuffer;
    instance->DrawTexture = DrawTexture;

    return instance;
}
