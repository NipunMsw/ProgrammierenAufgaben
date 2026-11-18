/*
 * OperatorenAufgabe.c
 *
 * Created: 18.11.2026 13:09:05
 * Author : e5Golla
 */ 

#include <avr/io.h>


int main(void)
{
    uint8_t inSchalter7;
    uint8_t inSchalter6;
    uint8_t inSchalter5;
    uint8_t inSchalter4;
    uint8_t inSchalter3;
    uint8_t inSchalter2;
    uint8_t inSchalter1;
    uint8_t inSchalter0;
    
    uint8_t outLed7;
    uint8_t outLed6;
    uint8_t outLed5;
    uint8_t outLed4;
    uint8_t outLed3;
    uint8_t outLed2;
    uint8_t outLed1;
    uint8_t outLed0;
    
    uint8_t ungerade;
    uint8_t ausgabe;
    DDRA = 0xFF;
    
    while (1) 
    {
        //EINGABE
        inSchalter7 = (PINC & (1 << 7)) != 0;
        inSchalter6 = (PINC & (1 << 6)) != 0;
        inSchalter5 = (PINC & (1 << 5)) != 0;
        inSchalter4 = (PINC & (1 << 4)) != 0;
        inSchalter3 = (PINC & (1 << 3)) != 0;
        inSchalter2 = (PINC & (1 << 2)) != 0;
        inSchalter1 = (PINC & (1 << 1)) != 0;
        inSchalter0 = (PINC & (1 << 0)) != 0;
        
        //VERARBEITUNG
        outLed0 = inSchalter7;
        outLed1 = inSchalter7 && inSchalter6 && !inSchalter5;
        outLed2 = !inSchalter6 || !inSchalter5 || !inSchalter4;
        outLed3 = ungerade = (PINC & (1 << 1)) != 0;
        outLed4 = !outLed3;
        outLed5 = (PINC % 17 == 0);
        outLed6 = ((PINC >> 1) & 0b00000111) > ((PINC >> 4) & 0b00000111);
        outLed7 = ((PINC >> 1) & 0b00000111) == ((PINC >> 4) & 0b00000111);
        
        //AUSGABE
        ausgabe = outLed0 * 0x01 | outLed1 * 0x02 |
        outLed2 * 0x04 | outLed3 * 0x08 |
        outLed4 * 0x10 | outLed5 * 0x20 |
        outLed6 * 0x40 | outLed7 * 0x80;
        
        if (inSchalter0)
        {
            PORTA = ~ausgabe;
        }
        else
        {
            PORTA = ausgabe;
        }
    }
}

