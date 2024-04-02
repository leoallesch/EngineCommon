#include "Vector2.h"
#include "Utils.h"
#include <math.h>

float Vec2_MagnitudeSqr(Vector2_t v)
{
    return v.x*v.x + v.y*v.y;
}

float Vec2_Magnitude(Vector2_t v)
{
    return (float)sqrtf(Vec2_MagnitudeSqr(v));
}

Vector2_t Vec2_Normalized(Vector2_t v)
{
    float mag = Vec2_Magnitude(v);

    return Vector2(v.x / mag, v.y / mag);
}

Vector2_t Vec2_Add(Vector2_t l, Vector2_t r)
{
    return Vector2(l.x + r.x, l.y + r.y);
}


Vector2_t Vec2_Subtract(Vector2_t l, Vector2_t r)
{
    return Vector2(l.x - r.x, l.y - r.y);
}

Vector2_t Vec2_MultiplyScalar(Vector2_t vec, float scalar)
{
    return Vector2(vec.x * scalar, vec.y * scalar);
}

Vector2_t Vec2_Rotate(Vector2_t v, float angle)
{
    float radAngle = (float)angle * DEG_TO_RAD;

    return Vector2(
        (float)(v.x * cos(radAngle) - v.y * sin(radAngle)),
        (float)(v.x * sin(radAngle) + v.y * cos(radAngle)));
}

Vector2_t Vector2(float x, float y)
{
    Vector2_t vector = {x, y};

    return vector;
}