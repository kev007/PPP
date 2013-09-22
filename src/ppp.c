#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>


int main()
{
	 DDRA 	=	0b11111111; //set Port A as output
	 PORTA	=	0b11111111; //Port A pins pulled high

	 while(1)
	 {
	 	PORTA = 0b11111111;
		my_delay_ms(1000);
		PORTA = 0b00000000;
		my_delay_ms(1000);
	 }
	 return 0;
}

void  my_delay_ms (unsigned int delay)
{ 
	unsigned int i; 
	for (i=0; i<(delay/16); i++)
	{ 
    	_delay_ms(16); 
	}
	if (delay % 16)
	{
		_delay_ms(delay % 16); 
	} 
}
