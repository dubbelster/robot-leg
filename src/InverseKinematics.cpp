#include <stdint.h>
#include <vector.h>
#include <InverseKinematics.h>
#include <math.h>

#define RAD_2_DEG 57.2957795131

InverseKinematics::InverseKinematics(float l0, float l1, float l2)
{
    lengths[0] = l0;
    lengths[1] = l1;
    lengths[2] = l2;
}

float *InverseKinematics::calculateAngles(Vector3 target)
{
    // Bereken hoeken
    float tdLength = sqrtf(squaref(target.z) + squaref(target.x));
    float tdMiddleAndLowerLength = tdLength - lengths[0];
    float svMiddleAndLowerLength = sqrtf(squaref(target.y) + squaref(tdMiddleAndLowerLength));

    // Hoek upper leg
    angles[0] = atan2f(target.x, target.z);

    // Hoek middle leg
    float tan = atan2f(tdLength - lengths[0], -target.y);
    float cos = acosf((squaref(lengths[2]) - squaref(lengths[1]) - squaref(svMiddleAndLowerLength)) /
                      (-2 * lengths[1] * svMiddleAndLowerLength));
    angles[1] = -(tan + cos - M_PI_2);

    // Hoek lower leg
    angles[2] = M_PI - acosf((squaref(svMiddleAndLowerLength) - squaref(lengths[1]) - squaref(lengths[2])) /
                             (-2 * lengths[1] * lengths[2]));

    // Check of de uitkomsten nummers zijn.
    if (isnanf(angles[1]))
        angles[1] = 0;

    if (isnanf(angles[2]))
        angles[2] = 0;

    // Zet hoekem om naar graden ipv radialen
    for (uint8_t i = 0; i < 3; i++)
    {
        angles[i] *= RAD_2_DEG;
    }

    return angles;
}