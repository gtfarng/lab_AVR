#include <avr/io.h>
int main(void){
	DDRD = 0x00; // set port B as input
	DDRC = 0xFF; // set port C as output
	unsigned char SWITCH_V, DISP, i, count, Bitposition, test_bit;
	unsigned char LOOKUPTB[] = {
		0b00111111, 0b00000110, //0,1
		0b01011011, 0b01001111, //2,3
		0b01100110, 0b01101101, //4,5
		0b01111101, 0b00000111, //6,7
		0b01111111, 0b01101111, //8,9
		0b01110111, 0b01111100, //10,11
		0b00111001, 0b01011110, //12,13
		0b01111001, 0b01110001  //14,15
	};
	
	while (1){
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