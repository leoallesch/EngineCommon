#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "SDL.h"
#include <stdbool.h>

typedef struct InputManager_t
{
    const Uint8 *keyboardStates;

    void (*Destroy)(struct InputManager_t *instance);
    bool (*KeyDown)(struct InputManager_t *instance, SDL_Scancode scanCode);
    void (*Update)(struct InputManager_t *instance);

} InputManager_t;

InputManager_t *InputManager();

#endif