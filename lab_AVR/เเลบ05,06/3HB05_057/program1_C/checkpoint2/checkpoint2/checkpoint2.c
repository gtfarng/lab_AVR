/*
 * checkpoint2.c
 *
 * Created: 2/25/2016 4:32:08 PM
 *  Author: coe
 */ 


#include <avr/io.h>
int main(void)
{
	DDRD = 0x00; // set port D as input
	DDRC = 0xFF; // set port C as output
	unsigned char SWITCH_V, DISP, i, count, mask, test_bit;
	while (1)
	{
		//---read input switch via portB
		SWITCH_V = PIND;
		count = 0;
		mask = 0x01;
		for (i=0;i<8;i++)
		{
			test_bit = SWITCH_V & (mask << i);
			if (test_bit)
			count++;
		}
		switch(count)
		{
			case 0: DISP= 0b00111111; break;
			case 1: DISP= 0b00000110; break;
			case 2: DISP= 0b01011011; break;
			case 3: DISP= 0b01001111; break;
			case 4: DISP= 0b01100110; break;
			case 5: DISP= 0b01101101; break;
			case 6: DISP= 0b01111101; break;
			case 7: DISP= 0b00000111; break;
			case 8: DISP= 0b01111111; break;
			case 9: DISP= 0b01101111; break;
			case 10:DISP= 0b01110111; break;
			case 11:DISP= 0b01111100; break;
			case 12:DISP= 0b00111001; break;
			case 13:DISP= 0b01011110; break;
			case 14:DISP= 0b01111001; break;
			default:DISP= 0b01110001; //15
		}
		PORTC = DISP;
	}
}