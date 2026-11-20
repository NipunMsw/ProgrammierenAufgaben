/*
 * EVA_Aufgabe1.c
 *
 * Created: 19.11.2026 16:02:12
 * Author : e5Golla
 */

#include <avr/io.h>

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
    uint8_t inWohnzimmer;
    uint8_t inBad;
    uint8_t in1Og;
    uint8_t in2Og;
    uint8_t inEg;
    uint8_t inLichtSens;

    // AUSGÄNGE
    uint8_t outWohnzimmer;
    uint8_t outBad;
    uint8_t outSpiegel;
    uint8_t outEg;
    uint8_t outOg;

    while (1)
    {
        // EINGABE
        inWohnzimmer = (SENSOR_EINGAENGE & PINWOHNZIMMER) != 0;
        inBad        = (SENSOR_EINGAENGE & PINBAD) != 0;
        in1Og        = (SENSOR_EINGAENGE & PIN1OG) != 0;
        in2Og        = (SENSOR_EINGAENGE & PIN2OG) != 0;
        inEg         = (SENSOR_EINGAENGE & PINEG) != 0;
        inLichtSens  = (SENSOR_EINGAENGE & PINLICHTSENS) != 0;

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