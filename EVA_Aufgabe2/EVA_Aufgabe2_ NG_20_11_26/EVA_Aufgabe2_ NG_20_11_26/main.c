/*
 * EVA_Aufgabe2_ NG_20_11_26.c
 *
 * Created: 20.11.2026 07:42:54
 * Author : e5Golla
 */ 
#include <stdbool.h>
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

#define PORT_A_CONFIG 0xFF
#define PORT_C_CONFIG 0x00
#define PORT_H_CONFIG 0xFF
#define PORT_H_INIT   0x00


int main(void)
{
    /* Replace with your application code */
    
    DDRA = PORT_A_CONFIG;
    DDRC = PORT_C_CONFIG;
    DDRH = PORT_H_CONFIG;
    PORTH = PORT_H_INIT;
    
    bool inZeug;
    bool inWildN;
    bool inWildS;
    bool inObermN;
    bool inObermW;
    bool inMattW;
    bool inMattS;
    
    
    bool outA;
    bool outB;
    bool outC;
    bool outD;
    bool outE;
    bool outF;
    bool outG;

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

