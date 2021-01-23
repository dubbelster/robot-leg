#include <TimePointCycle.h>
#include <vector.h>
#include <Arduino.h>

// Maak instance met cyclus.
TimePointCycle::TimePointCycle(Vector4 _cycle[], int _cycleSize)
{
    cycle = _cycle;
    cycleSize = _cycleSize;
}

// Maak instance met lege cyclus.
TimePointCycle::TimePointCycle()
{
    // TimePointCycle([]);
}

// Return de tijd die de cyclus in zijn geheel neemt.
float TimePointCycle::getCycleTime()
{
    return cycle[cycleSize - 1].t; // Return de tijd van het laatste element.
}

// Public
Vector3 TimePointCycle::getCyclePoint(float time)
{
    // time = time % getCycleTime(); // Zorg ervoor dat de tijd altijd binnen de cyclus valt.
    Vector4 *start, *end; // Worden de punten waar de huidige tijd tussen zit.

    Vector4 *ptr = cycle;
    for (int i = 0; i < cycleSize; i++)
    {
        // Het eerste punt waarvan de punt tijd groter is dan de huidige tijd is het eindpunt.
        if (time < ptr->t)
        {
            end = ptr;

            // Startpunt is het vorige punt in de array.
            // Zijn we bij het 0e element neem dan het laatste element uit de array.
            if (i == 0)
            {
                ptr += cycleSize;
                start = ptr;
            }
            else
            {
                ptr--;
                start = ptr;
            }

            break;
        }

        ptr++;
    }

    float ratio = (time - start->t) / (end->t - start->t); // Bereken het ratio van hoever tussen de 2 punten de huidige tijd is.
    return interpolateVector(createVector3(start), createVector3(end), ratio);

    Serial.print("START: ");
    printVector(start);
    Serial.print("\nEND: ");
    printVector(end);
    Serial.println("\n-------------");

    return createVector3(0, 0, 0);
}