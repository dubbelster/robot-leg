#include <CalibratedServo.h>
#include <Arduino.h>

#define DEFAULT_MIN 500
#define DEFAULT_MAX 2500

// Zorgt ervoor dat de hoek niet minder dan 0 en niet meer dan 180 graden is.
void CalibratedServo::clampAngle(float *angle)
{
    if (*angle < 0)
    {
        *angle = 0;
    }
    else if (*angle > 180)
    {
        *angle = 180;
    }
}

CalibratedServo::CalibratedServo(int pin, float offset, int min, int max)
{
    this->pin = pin;
    this->offset = offset;
    this->min = min;
    this->max = max;
    this->delta = max - min;
}

CalibratedServo::CalibratedServo(int pin, float offset)
{
    CalibratedServo(pin, offset, DEFAULT_MIN, DEFAULT_MAX);
}

CalibratedServo::CalibratedServo(int pin)
{
    CalibratedServo(pin, 0, DEFAULT_MIN, DEFAULT_MAX);
}

void CalibratedServo::attach()
{
    s.attach(pin, min, max);
}

void CalibratedServo::detach()
{
    s.detach();
}

// Zet de hoek waar de servo naartoe gaat.
void CalibratedServo::writeAngle(float angle)
{
    angle -= offset;    // Bereken de angle waarop die aan de servo gecommuniceerd moet worden door de offset er van af te halen.
    clampAngle(&angle); // Zorg ervoor dat de hoek tussen 0 en 180 graden is.

    // Zet de hoek om in de pulse breedte voor de servo.
    int pulseWidth = (angle * (float)delta / (float)180) + 0.5 + min; // Voeg 0.5 toe om eerlijk af te ronden

    // Communiceer de hoek naar de servo.
    s.writeMicroseconds(pulseWidth);
}

void CalibratedServo::writeMicroseconds(int value)
{
    s.writeMicroseconds(value);
}