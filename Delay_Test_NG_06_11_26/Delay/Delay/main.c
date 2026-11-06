/*
 * Delay.c
 *
 * Created: 06.11.2026 10:22:56
 * Author : e5Golla
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
        DDRA = 1;
        for (int x = 0; x<8; x++)
        {
            PORTA = (1<<x); 
            _delay_ms(1000);
        }
        for (int x = 0; x<8; x++)
        {
            PORTA = (0x80>>x);
            _delay_ms(1000);
        }
        
    }
}

