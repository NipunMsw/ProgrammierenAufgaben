/*
 * EVA_Aufgabe2_ NG_20_11_26.c
 *
 * Created: 20.11.2026 07:42:54
 * Author : e5Golla
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    
    DDRA = 0XFF;
    DDRC = 0X00;
    DDRH = 0XFF;
    PORTH = 0;
    
    uint8_t inZeug;
    uint8_t inWildN;
    uint8_t inWildS;
    uint8_t inObermN;
    uint8_t inObermW;
    uint8_t inMattW;
    uint8_t inMattS;
    
    
    uint8_t outA;
    uint8_t outB;
    uint8_t outC;
    uint8_t outD;
    uint8_t outE;
    uint8_t outF;
    uint8_t outG;

    while (1) 
    {
        //EINGABE
        inZeug = (PINC & (1<<0)) != 0;
        inWildN = (PINC & (1<<1)) != 0;
        inWildS = (PINC & (1<<2)) != 0;
        inObermN = (PINC & (1<<3)) != 0;
        inObermW = (PINC & (1<<4)) != 0;
        inMattW = (PINC & (1<<5)) != 0;
        inMattS = (PINC & (1<<6)) != 0;
        
        //VERARBEITUNG
        outA = inZeug;
        outB = inWildN || inWildS;
        outC = inWildS;
        outD = outC;
        outE = outD;
        outF = inObermN || inObermW;
        outG = inMattS || inMattW;
        
        //AUSGABE
        PORTA = outA * 0x01 | outB * 0x02 | outC * 0x04 | outD * 0x08 | outE * 0x10 | outF * 0x20 | outG * 0x40;
    }
}

