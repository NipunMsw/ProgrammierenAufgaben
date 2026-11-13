/*
 * EingabeAusgabe.c
 *
 * Created: 09.11.2026 16:32:40
 * Author : e5Golla
 */ 

#include <avr/io.h>


int main(void)
{      
    DDRA &= (1<<4); 
    /* Replace with your application code */
    while (1) 
    {
        
        PORTA = (1<<4);
        
    }
}

