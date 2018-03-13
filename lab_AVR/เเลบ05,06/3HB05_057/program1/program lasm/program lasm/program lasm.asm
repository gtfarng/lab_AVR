/*
 * program_lasm.asm
 *
 *  Created: 2/25/2016 1:51:09 PM
 *   Author: coe
 */ 

.INCLUDE	"m32def.inc"

.EQU		ALL_PIN_OUT = 0xFF
.EQU		ALL_PIN_IN = 0x00

.DEF		VAR_A = R16
.DEF		TMP = R17

.CSEG
.ORG		0x0000
		ldi	VAR_A, ALL_PIN_OUT
		out	DDRC, VAR_A

		ldi	VAR_A, ALL_PIN_IN
		out	DDRD, VAR_A

		ldi	TMP, 0x00

MAIN:
		in	VAR_A, PIND
		andi	VAR_A, 0x0F
		ldi	ZL, low(TB_7SEGMENT*2)
		ldi	ZH, high(TB_7SEGMENT*2)

		add	ZL, VAR_A
		adc	ZH, TMP
		lpm

		out	PORTC, R0
		rjmp	MAIN
		;	hgfedcba	 hgfedcba
TB_7SEGMENT:
		.DB	0b00111111,	0b00000110		; 0 and 1
		.DB	0b01011011,	0b01001111		; 2 and 3
		.DB	0b01100110,	0b01101101		; 4 and 5
		.DB	0b01111101,	0b00000111		; 6 and 7
		.DB	0b11111111,	0b10000111		; -8 and -7
		.DB	0b11111101,	0b11101101		; -6 and -5
		.DB	0b11100110,	0b11001111		; -4 and -3
		.DB	0b11011011,	0b10000110		; -2 and -1



.DSEG

