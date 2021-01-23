#ifndef INV_KIN
#define INV_KIN

#include <vector.h>

class InverseKinematics
{
private:
    float lengths[3];
    float angles[3];

public:
    InverseKinematics(float l0, float l1, float l2);
    
    float *calculateAngles(Vector3 target);
};

#endif