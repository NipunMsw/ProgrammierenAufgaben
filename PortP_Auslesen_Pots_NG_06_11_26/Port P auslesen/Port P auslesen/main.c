/*
 * Port P auslesen.c
 *
 * Created: 06.11.2026 10:49:34
 * Author : e5Golla
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0xFF;      // All 8 LEDs as outputs
    DDRF &= ~(1<<PF0); // PF0 as input

    ADMUX = (1<<REFS0);  // AVCC reference, ADC0
    ADCSRA = (1<<ADEN) | 7; // Enable ADC, prescaler 128

    while (1)
    {
        ADCSRA |= (1<<ADSC);           // Start measurement

        while (ADCSRA & (1<<ADSC));    // Wait until finished

        uint16_t value = ADC;          // Read 0-1023

        uint8_t leds = value / 114;    // Convert to 0-8

        PORTA = (1 << leds) - 1;       // Display LED bar
    }
}

