/*
 * EVA_Aufgabe1.c
 *
 * Created: 19.11.2026 16:02:12
 * Author : e5Golla
 */

#include <avr/io.h>
#include <stdbool.h>
// EINGANGS-PINS
#define PINWOHNZIMMER (1 << PC0)
#define PINBAD        (1 << PC2)
#define PIN1OG        (1 << PC4)
#define PIN2OG        (1 << PC5)
#define PINEG         (1 << PC6)
#define PINLICHTSENS  (1 << PC7)

// AUSGANGS-PINS
#define LEDWOHNZIMMER (1 << PA0)
#define LEDBAD        (1 << PA1)
#define LEDSPIEGEL    (1 << PA2)
#define LEDEG         (1 << PA6)
#define LEDOG         (1 << PA7)

// PORT DEFINITIONEN
#define SENSOR_EINGAENGE PINC
#define LAMPEN_AUSGAENGE PORTA

#define SENSOR_RICHTUNG DDRC
#define LAMPEN_RICHTUNG DDRA

#define ALLE_EINGAENGE 0x00
#define ALLE_AUSGAENGE 0xFF

int main(void)
{
    // PORT KONFIGURATION
    SENSOR_RICHTUNG = ALLE_EINGAENGE;
    LAMPEN_RICHTUNG = ALLE_AUSGAENGE;

    // EINGÄNGE
    bool inWohnzimmer;
    bool inBad;
    bool in1Og;
    bool in2Og;
    bool inEg;
    bool inLichtSens;

    // AUSGÄNGE
    bool outWohnzimmer;
    bool outBad;
    bool outSpiegel;
    bool outEg;
    bool outOg;

    while (1)
    {
        // EINGABE
        inWohnzimmer = (SENSOR_EINGAENGE & PINWOHNZIMMER);
        inBad        = (SENSOR_EINGAENGE & PINBAD);
        in1Og        = (SENSOR_EINGAENGE & PIN1OG);
        in2Og        = (SENSOR_EINGAENGE & PIN2OG);
        inEg         = (SENSOR_EINGAENGE & PINEG);
        inLichtSens  = (SENSOR_EINGAENGE & PINLICHTSENS);

        // VERARBEITUNG
        outWohnzimmer = inWohnzimmer;
        outSpiegel = inBad;
        outBad = outSpiegel;

        if (!inLichtSens)
        {
            outEg = in1Og || in2Og || inEg;
            outOg = outEg;
        }
        else
        {
            outEg = 0;
            outOg = outEg;
        }

        // AUSGABE
        LAMPEN_AUSGAENGE =
            (outWohnzimmer * LEDWOHNZIMMER) |
            (outBad        * LEDBAD)        |
            (outSpiegel    * LEDSPIEGEL)    |
            (outEg         * LEDEG)         |
            (outOg         * LEDOG);
    }
}