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
        PORTA = 0xFF;
        _delay_ms(1000);
        PORTA = 0x00;
        _delay_ms(1000);
    }
}

