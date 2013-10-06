#define str 	0
#define data 	1
#define clk 	3

void lauflicht (void)
{
	int i = 0;
	int buffer = 4;
	int delay = 100;

	while(1)
	{		
		PORTA = 0x00;
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

void tasterTest (void)
{
	PORTA = 0x00;
}
