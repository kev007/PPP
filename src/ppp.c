#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

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

void display (int buffer_size, int hRGB)
{
	int R, G, B;	
	


	if ((R % buffer_size) == 0){

	}	
	if ((G % buffer_size) == 0){

	}	
	if ((B % buffer_size) == 0){

	}	
}

void lauflicht (void)
{
	int i = 0;
	int buffer = 4;
	int delay = 100;

	while(1)
	{		
		PORTA ^= 0xFF;
		PORTB = (1 << str);
		_delay_ms(delay);	
		
		if ((i % buffer) == 0){
			PORTB = (1 << data);
		} else {
			PORTB = (0 << data);
		}
		i++;
		
		_delay_ms(delay);	
		PORTB ^= (1 << clk);
		_delay_ms(delay);
		PORTB ^= (1 << clk);
		_delay_ms(delay);
	}
}

int main()
{
	init();

	lauflicht();
}
