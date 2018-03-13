/*
 * check4_lab05.c
 *
 * Created: 3/17/2016 3:26:31 PM
 *  Author: coe
 */ 


#include <avr/io.h>
int main (void)
{
	unsigned char LOOKUPTB[] = {	0b00111111, //0
		0b00000110,//1
		0b01011011,//2
		0b01001111,//3
		0b01100110,//4
		0b01101101,//5
		0b01111101,//6
		0b00000111,//7
		0b01111111,//8
		0b01100111,//9
		0b10111111,//10
		0b10000110,//11
		0b11011011,//12
		0b11001111,//13
		0b11100110,//14
		0b11101101//15
	};
	unsigned char DISPLY, SWITCH_V;

	DDRC	= 0xFF;
	DDRD = 0x00;
	while(1)
	{
		SWITCH_V = PIND;
		SWITCH_V &= 0x0F;
		SWITCH_V = SWITCH_V >> 4;
		DISPLY = LOOKUPTB[SWITCH_V];
		PORTC = ~(DISPLY);
	}
}

