#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include "Timer.h"
#include "Texture.h"
#include <stdint.h>

enum
{
    ONCE,
    LOOP
};
typedef uint8_t WrapMode_t;

enum
{
    HORIZONTAL,
    VERTICAL
};
typedef uint8_t AnimationDirection_t;


typedef struct AnimatedTexture_t
{
    Texture_t *texture;
    Timer_t *timer;

    int startX;
    int startY;

    float animationTimer;
    float animationSpeed;
    float timePerFrame;

    int frameCount;

    WrapMode_t mode;
    AnimationDirection_t direction;

    bool animationComplete;

    void (*Destroy)(struct AnimatedTexture_t *instance);
    void (*WrapMode)(struct AnimatedTexture_t *instance, WrapMode_t mode);
    void (*Update)(struct AnimatedTexture_t *instance);
} AnimatedTexture_t;

AnimatedTexture_t *AnimatedTexture(
    Texture_t *texture,
    Timer_t *timer,
    int x,
    int y,
    int w,
    int h,
    int frameCount,
    float animationSpeed,
    AnimationDirection_t dir);

#endif