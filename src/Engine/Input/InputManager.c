#include "InputManager.h"

static void Update(InputManager_t *instance)
{
    instance->keyboardStates = SDL_GetKeyboardState(NULL);
}

static bool KeyDown(InputManager_t *instance, SDL_Scancode scanCode)
{
    return instance->keyboardStates[scanCode];
}

static void Destroy(InputManager_t *instance)
{
    free(instance);
}

InputManager_t *InputManager()
{
    InputManager_t *instance = malloc(sizeof(InputManager_t));
    memset(instance, 0, sizeof(InputManager_t));

    instance->Destroy = Destroy;
    instance->Update = Update;
    instance->KeyDown = KeyDown;

    return instance;
}