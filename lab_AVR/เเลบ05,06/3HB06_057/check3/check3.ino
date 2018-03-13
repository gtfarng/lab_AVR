#include <avr/io.h>
int main (void)
{
		unsigned char LOOKUPTB[] = {	0b00111111, //0
					0b00000110,0b01011011, //1,2
					0b01001111,0b01100110, //3,4
					0b01101101,0b01111101, //5,6
					0b00000111,0b11111111, //7,8
					0b10000111,0b11111101, //-7,-6
					0b11101101,0b11100110, //-5,-4
					0b11001111,0b11011011, //-3,-2
					0b10000110 };          //-1
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

