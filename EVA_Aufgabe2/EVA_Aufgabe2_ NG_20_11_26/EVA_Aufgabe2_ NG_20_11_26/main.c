/*
 * EVA_Aufgabe2_ NG_20_11_26.c
 *
 * Created: 20.11.2026 07:42:54
 * Author : e5Golla
 */ 

#include <avr/io.h>
#define PINZEUG (1<<0)
#define PINWILDN (1<<1)
#define PINWILDS (1<<2)
#define PINOBERMN (1<<3)
#define PINOBERMW (1<<4)
#define PINMATTW (1<<5)
#define PINMATTS (1<<6)

#define SENSOR_EINGAENGE PINC
#define LAMPEN_AUSGAENGE PORTA

#define LAMPE0 0x01
#define LAMPE1 0x02
#define LAMPE2 0x04
#define LAMPE3 0x08
#define LAMPE4 0x10
#define LAMPE5 0x20
#define LAMPE6 0x40


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
        inZeug = (SENSOR_EINGAENGE & PINZEUG) != 0;
        inWildN = (SENSOR_EINGAENGE & PINWILDN) != 0;
        inWildS = (SENSOR_EINGAENGE & PINWILDS) != 0;
        inObermN = (SENSOR_EINGAENGE & PINOBERMN) != 0;
        inObermW = (SENSOR_EINGAENGE & PINOBERMW) != 0;
        inMattW = (SENSOR_EINGAENGE & PINMATTW) != 0;
        inMattS = (SENSOR_EINGAENGE & PINMATTS) != 0;
        
        //VERARBEITUNG
        outA = inZeug;
        outB = inWildN || inWildS;
        outC = inWildS;
        outD = outC;
        outE = outD;
        outF = inObermN || inObermW;
        outG = inMattS || inMattW;
        
        //AUSGABE
        LAMPEN_AUSGAENGE = outA * LAMPE0 | outB * LAMPE1 | outC * LAMPE2 | outD * LAMPE3 | outE * LAMPE4 | outF * LAMPE5 | outG * LAMPE6;
    }
}

