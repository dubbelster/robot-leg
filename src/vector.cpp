#include <Arduino.h>
#include <vector.h>

Vector3 createVector3(float x, float y, float z)
{
    return Vector3{.x = x, .y = y, .z = z};
}

Vector3 createVector3(Vector4 *vector)
{
    return Vector3{.x = vector->x, .y = vector->y, .z = vector->z};
}

Vector4 createVector4(float x, float y, float z, float t)
{
    return Vector4{.x = x, .y = y, .z = z, .t = t};
}

float interpolate(float a, float b, float ratio)
{
    return a * (1 - ratio) + b * ratio;
}

Vector3 interpolateVector(Vector3 a, Vector3 b, float ratio)
{
    return createVector3(
        interpolate(a.x, b.x, ratio),
        interpolate(a.y, b.y, ratio),
        interpolate(a.z, b.z, ratio));
}

void printVector(Vector3 *vector)
{
    Serial.print("X: ");
    Serial.print(vector->x);
    Serial.print(", Y: ");
    Serial.print(vector->y);
    Serial.print(", Z: ");
    Serial.print(vector->z);
}

void printVector(Vector4 *vector)
{
    Serial.print("X: ");
    Serial.print(vector->x);
    Serial.print(", Y: ");
    Serial.print(vector->y);
    Serial.print(", Z: ");
    Serial.print(vector->z);
    Serial.print(", T: ");
    Serial.print(vector->t);
}