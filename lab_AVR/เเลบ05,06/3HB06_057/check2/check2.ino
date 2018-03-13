#include <avr/io.h>
int main(void)
{
	DDRD = 0x00; // set port B as input
	DDRC = 0xFF; // set port C as output
	unsigned char SWITCH_V, DISP, i, count, Bitposition, test_bit;
	unsigned char LOOKUPTB[] = { 
		0b00111111,
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
                0b01110001
	};
	
	while (1)
	{
		SWITCH_V = PIND;
		count = 0;
		Bitposition = 0x01;
		for (i=0;i<8;i++){
			test_bit = SWITCH_V & (Bitposition << i);
			if (!test_bit)
				count++;
		}
		DISP = LOOKUPTB[count];
		PORTC = DISP ;
	}
}
