#include <Arduino.h>

#include <RobotLeg.h>
#include <CalibratedServo.h>
#include <vector.h>
#include <InverseKinematics.h>
#include <TimePointCycle.h>

#define SERVO_0_PIN 5
#define SERVO_1_PIN 6
#define SERVO_2_PIN 9

InverseKinematics ik(.5, 1.5, 2);
CalibratedServo s0(SERVO_0_PIN, -90, 500, 2500);
CalibratedServo s1(SERVO_1_PIN, -90, 500, 2500);
CalibratedServo s2(SERVO_2_PIN, 0, 500, 2500);

Vector4 c[] = {createVector4(1, -2, 1, 0),
               createVector4(-1, -2, 1, 1),
               createVector4(0, -1, 1, 1.5),
               createVector4(1, -2, 1, 2)};
TimePointCycle tpc(c, sizeof(c) / sizeof(c[0]));

float *angles;
float time = 0;

void printAngles(float *angles)
{
    Serial.print("[Angles] A0: ");
    Serial.print(angles[0]);
    Serial.print(", A1: ");
    Serial.print(angles[1]);
    Serial.print(", A2: ");
    Serial.print(angles[2]);
    Serial.println();
}

void RobotLeg::setup()
{
    s0.attach();
    s1.attach();
    s2.attach();
}

void RobotLeg::loop(float deltaTime)
{
    time += deltaTime;
    if (time >= tpc.getCycleTime())
        time -= tpc.getCycleTime();

    // Serial.print("Time: ");
    // Serial.println(time, 7);

    Vector3 target = tpc.getCyclePoint(time);
    // Serial.print("Target: ");
    // printVector(&target);
    // Serial.println();

    angles = ik.calculateAngles(target);
    // printAngles(angles);

    s0.writeAngle(angles[0]);
    s1.writeAngle(angles[1]);
    s2.writeAngle(angles[2]);

    // delay(100);
}