#include "AnimatedTexture.h"

static void Update(AnimatedTexture_t *instance)
{
    if (!instance->animationComplete)
    {
        instance->animationTimer += instance->timer->deltaTime;

        if(instance->animationTimer >= instance->animationSpeed)
        {
            if(instance->mode == LOOP)
            {
                instance->animationTimer -= instance->animationSpeed;
            }
            else
            {
                instance->animationComplete = true;
                instance->animationTimer = instance->animationSpeed - instance->timePerFrame;
            }
        }

        if (instance->direction == HORIZONTAL)
        {
            instance->texture->clippedRect.x = 
                instance->startX + (int)(instance->animationTimer / instance->timePerFrame) * instance->texture->width;
        }
        else
        {
            instance->texture->clippedRect.y = 
                instance->startY + (int)(instance->animationTimer / instance->timePerFrame) * instance->texture->height;
        }
    }
}

static void WrapMode(AnimatedTexture_t *instance, WrapMode_t mode)
{
    instance->mode = mode;
}

static void Destroy(AnimatedTexture_t *instance)
{
    instance->texture = NULL;
    instance->timer = NULL;
    free(instance);
}

AnimatedTexture_t *AnimatedTexture(
    Texture_t *texture,
    Timer_t *timer,
    int x,
    int y,
    int w,
    int h,
    int frameCount,
    float animationSpeed,
    AnimationDirection_t dir)
{
    AnimatedTexture_t *instance = malloc(sizeof(AnimatedTexture_t));

    instance->texture = texture;
    instance->timer = timer;

    instance->texture->Clip(instance->texture, x, y, w, h);

    instance->startX = x;
    instance->startY = y;
    instance->frameCount = frameCount;
    instance->animationSpeed = animationSpeed;
    instance->timePerFrame = instance->animationSpeed / instance->frameCount;
    instance->animationTimer = 0.0f;
    instance->direction = dir;
    instance->mode = LOOP;
    instance->animationComplete = false;

    instance->Destroy = Destroy;
    instance->WrapMode = WrapMode;
    instance->Update = Update;

    return instance;

}