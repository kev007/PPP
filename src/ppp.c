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

volatile int counter = 0;	
volatile int queue = 50;	//Time (1 period) used for transfering data to the shift register (also: amount of clocks to empty the queue)
volatile int regBits[24];	//Contents of the shift registers in array format [Number of bits that can be stored in the shift registers]
volatile int freq = 60;		//Frequency (in Hz) of LED color value updates
volatile int t = 50;		//Time period (in ms) of one LED color value before update - do not use both frequency and period


void init (void)
{
	DDRB	= 	0b00001011;
	DDRA	= 	0b11111111;
	DDRD	= 	0x00;
	PORTA	= 	0b11111111;
	PORTB	= 	0b00000100;

	//GICR 	= 	1<<INT2;			//aktiviert Interrupt
	//MCUCSR 	|= 	(1<<ISC2);		//steigende Flanke

	//Timer 1
	TCCR1B 	= 	0b00000011;		//(0<<CS12)|(1<<CS11)|(1<<CS10);	//clk/64 prescaler - 250000Hz
	TIMSK 	= 	(1<<TOIE1);		//Timer/Counter1, Overflow Interrupt Enable
	TCNT1	=	0;				//Timer/Counter1 reset

	sei();	
				
}

int main()
{
	init();

	//lauflicht();		//execute lauflicht - do activate while timers are in use since _delay is utilized
	//tasterTest();
}


ISR(TIMER1_OVF_vect)
{
	if(counter < queue)					
	{
		counter++;
	} else {
		counter = 0;
	}

	if ((counter % 100000) == 0){
		PORTA ^= 0b11111111;
	}
/*
	if (counter % freq == 0) {
		shiftOut(&counter, queue, &regBits);
	}
*/
	if (counter == t*10000) {
		shiftOut(&counter, queue, &regBits);
	}

}
/*
ISR(INT2_vect)
{
	PORTA	^= 	0b11111111;
}
*/



