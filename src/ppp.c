#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../output.h"
#include "../modes.h"

#define F_CPU 16000000    // AVR clock frequency in Hz, used by util/delay.h
#define str 	0
#define data 	1
#define clk 	2


volatile int16_t overflow = 0;

void init (void)
{
	DDRB	= 	0b00000111;
	DDRA	= 	0xFF;
	DDRD	= 	0x00;
	PORTB	= 	0xFF;

/*
	TCCR1B 	|= 	(1<<CS11);
	TCCR1B 	|= 	(1<<CS10);
	TIMSK 	|= 	(1<<TOIE1);
	TCNT1	=	0;

	sei();	
*/				
}



int main()
{
	init();

	lauflicht();
}
