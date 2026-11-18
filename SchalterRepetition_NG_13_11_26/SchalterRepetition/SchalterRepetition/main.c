/*
 * SchalterRepetition.c
 *
 * Created: 13.11.2026 11:16:18
 * Author : e5Golla
 */ 

#include <avr/io.h>


int main(void)
{
        DDRA = 0xFF;
        DDRB = 0xFF;
        DDRC = 0x00;
        
        uint8_t HauptFlag = 0;
        uint8_t NotfallFlag = 0;
    /* Replace with your application code */
    while (1) 
    {
        if (PINC & (1 << 0))
        {
            if (PINC & (1 << 1))
            {
                PORTA |= 0b00011111;
                
            }else{
                PORTA &= 0b01100000;
            }
            if (PINC & (1 << 2))
            {
                PORTA |= 0b11100000;
                PORTB |= 0b00001111;
                
            }else{
                PORTA &= 0b00011111;
                PORTB &= 0b11110000;
            }
        }
    }
}

