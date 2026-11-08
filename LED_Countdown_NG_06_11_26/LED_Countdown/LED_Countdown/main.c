/*
 * LED_Countdown.c
 *
 * Created: 06.11.2026 13:40:59
 * Author : e5Golla
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0xFF;
    
    /* Replace with your application code */
    while (1) 
    {
        for(int i=0; i< 10; i++){
            PORTA = 10-i; 
            PORTB = 0xFF;
            _delay_ms(500);
            PORTB = 0x00;
            _delay_ms(500);
        }
        _delay_ms(1000);
        
    }
}

