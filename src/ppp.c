#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../input.h"
#include "../output.h"
#include "../modes.h"

#define F_CPU 16000000    // AVR clock frequency in Hz, used by util/delay.h
#define str 	0
#define data 	1
#define clk 	3

volatile int16_t overflow = 0;

void init (void)
{
	DDRB	= 	0b00001011;
	DDRA	= 	0b11111111;
	DDRD	= 	0x00;
	PORTA	= 	0b11111111;
	PORTB	= 	0b00000100;

	GICR 	= 	1<<INT2;			//aktiviert Interrupt
	MCUCSR 	|= 	(1<<ISC2);		//steigende Flanke

/*
	TCCR1B 	|= 	(1<<CS11);
	TCCR1B 	|= 	(1<<CS10);
	TIMSK 	|= 	(1<<TOIE1);
	TCNT1	=	0;
*/
	sei();	
				
}

int main()
{
	init();

	//lauflicht();
	//tasterTest();
}


ISR(INT2_vect)
{
	PORTA	= 	0b00000000;
}

