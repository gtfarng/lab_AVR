#include <avr/io.h>
int main (void)
{
		unsigned char LOOKUPTB[] = {	0b00111111,
					0b00000110,		
					0b01011011,
					0b01001111,
					0b01100110,
					0b01101101,
					0b01111101,	
					0b00000111,
					0b01111111,	
					0b01101111,
					0b01110111,	
					0b01111100,		
					0b00111001,	
					0b01011110,
					0b01111001,	
					0b01110001 }; 
		unsigned char DISPLY, SWITCH_V;

		DDRC	= 0xFF;
		DDRD = 0x00;
		while(1)
		{
			SWITCH_V = PIND;
			SWITCH_V &= 0xF0;
                        SWITCH_V = SWITCH_V >> 4;
			DISPLY = LOOKUPTB[SWITCH_V];
                        PORTC = DISPLY;
		}
}

