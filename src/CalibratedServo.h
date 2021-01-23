#ifndef CAL_SER
#define CAL_SER

#include <Servo.h>

class CalibratedServo
{
private:
    Servo s;
    float offset;
    int pin, min, max, delta;

    void clampAngle(float *angle);

public:
    CalibratedServo(int pin, float offset, int min, int max);
    CalibratedServo(int pin, float offset);
    CalibratedServo(int pin);

    void attach();
    void detach();

    void writeAngle(float angle);
    void writeMicroseconds(int value);
};

#endif