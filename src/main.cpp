#include <Arduino.h>
#include <RobotLeg.h>

void setup()
{
    Serial.begin(115200);
    RobotLeg::setup();
    delay(1000);
}

unsigned long start = 0, end = 0;
float delta = 0;
void loop()
{
    RobotLeg::loop(delta);

    // Bereken loop tijd.
    end = micros();
    delta = (end - start) / (float)1000000;
    start = end;
}