#include <avr/io.h>

int main(void)
{
    DDRC = 0x00;
    DDRA = 0xFF;
    DDRH = 0xFF;
    PORTH = 0x00;

    while (1)
    {
        uint8_t anzahl = 0;

        for (uint8_t schalter = PINC; schalter; schalter >>= 1)
        {
            anzahl += schalter & 1;
        }

        PORTA = (1U << anzahl) - 1U;
    }
}