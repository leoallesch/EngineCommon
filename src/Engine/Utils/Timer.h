#ifndef TIMER_H
#define TIMER_H

typedef struct Timer_t
{
    unsigned int startTicks;
    unsigned int elapsedTicks;
    float deltaTime;
    float timeScale;

    void (*Destroy)(struct Timer_t *instance);
    void (*Reset)(struct Timer_t *instance);
    void (*Update)(struct Timer_t *instance);
    void (*SetTimeScale)(struct Timer_t *instance, float scale);
} Timer_t;

Timer_t *Timer();

#endif