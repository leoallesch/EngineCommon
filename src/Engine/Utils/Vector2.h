#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct Vector2_t
{
    float x;
    float y;
} Vector2_t;

Vector2_t Vector2(float x, float y);
float Vec2_MagnitudeSqr(struct Vector2_t v);
float Vec2_Magnitude(struct Vector2_t v);
Vector2_t Vec2_Normalized(Vector2_t v);
Vector2_t Vec2_Add(Vector2_t l, Vector2_t r);
Vector2_t Vec2_Subtract(Vector2_t l, Vector2_t r);
Vector2_t Vec2_MultiplyScalar(Vector2_t vec, float scalar);
Vector2_t Vec2_Rotate(Vector2_t v, float angle);

#endif