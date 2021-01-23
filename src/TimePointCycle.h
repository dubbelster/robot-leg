#ifndef TIM_POI_CYC
#define TIM_POI_CYC

#include <vector.h>

class TimePointCycle
{
private:
    Vector4 *cycle;
    int cycleSize;
public:
    TimePointCycle(Vector4 *cycle, int cycleSize);
    TimePointCycle();

    Vector3 getCyclePoint(float time);
    void setCycle(Vector3 *cycle);
    float getCycleTime();
};

#endif