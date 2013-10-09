#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../input.h"
#include "../output.h"
#include "../modes.h"

#define F_CPU 16000000		//AVR clock frequency in Hz, used by util/delay.h
#define str 	0			//STROBE PIN
#define data 	1			//DATA PIN
#define clk 	3			//CLOCK PIN

volatile int8_t pointer = 0;
volatile int8_t period = 50;
volatile int8_t regBits[24];

void init (void)
{
	DDRB	= 	0b00001011;
	DDRA	= 	0b11111111;
	DDRD	= 	0x00;
	PORTA	= 	0b11111111;
	PORTB	= 	0b00000100;

	GICR 	= 	1<<INT2;			//aktiviert Interrupt
	MCUCSR 	|= 	(1<<ISC2);		//steigende Flanke

	//Timer 1
	TCCR1B 	|= 	(0<<CS12)|(1<<CS11)|(1<<CS10);	//clk/64 prescaler - 250000Hz
	TIMSK 	|= 	(1<<TOIE1);	
	TCNT1	=	0x00;

	sei();	
				
}

int main()
{
	init();

	//lauflicht();
	//tasterTest();
}


ISR(TIMER1_OVF_vect)
{
	if(pointer < period)
	{
		pointer++;
	}
	else
	{
		PORTA ^= 0xFF;
		pointer = 0;
	}
	shiftOut(*pointer, period, regBits);
}

ISR(INT2_vect)
{
	PORTA	^= 	0b11111111;
}




