#ifndef VECTOR
#define VECTOR

struct Vector3
{
    float x, y, z;
};

struct Vector4
{
    float x, y, z, t;
};

Vector3 createVector3(float x, float y, float z);
Vector3 createVector3(Vector4 *vector);
Vector4 createVector4(float x, float y, float z, float t);

Vector3 interpolateVector(Vector3 a, Vector3 b, float ratio);

void printVector(Vector3 *vector);
void printVector(Vector4 *vector);

#endif