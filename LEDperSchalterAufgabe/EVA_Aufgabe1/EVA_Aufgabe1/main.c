/*
 * EVA_Aufgabe1.c
 *
 * Created: 19.11.2026 16:02:12
 * Author : e5Golla
 */ 

#include <avr/io.h>

int main(void)
{
    // PORT KONFIGURATION
    DDRK = 0x00;
    DDRA = 0xFF;

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


        // VERARBEITUNG


        // AUSGABE

    }
}