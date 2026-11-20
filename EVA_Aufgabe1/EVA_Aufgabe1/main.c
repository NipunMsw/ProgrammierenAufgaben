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
    DDRC = 0x00;
    DDRA = 0xFF;
    DDRH = 0xFF;
    PORTH = 0;

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

        inWohnzimmer = (PINC & (1<<0)) !=0;
        inBad = (PINC & (1<<2)) !=0;
        in1Og = (PINC & (1<<4)) !=0;
        in2Og = (PINC & (1<<5)) !=0;
        inEg = (PINC & (1<<6)) !=0;
        inLichtSens = (PINC & (1<<7)) !=0;
        
        // VERARBEITUNG
        outWohnzimmer = inWohnzimmer;
        outSpiegel = inBad;
        outBad = outSpiegel;
        if (!inLichtSens){
            outEg= in1Og || in2Og || inEg;
            outOg=outEg;
        }else{
            outEg= 0;
            outOg=outEg;
        }

        // AUSGABE
        PORTA = (outWohnzimmer * 0b00000001) | (outBad * 0b00000010) | (outSpiegel * 0b00000100) | (outEg * 0b01000000) | (outOg * 0b10000000);
    }
}