#define str 	0
#define data 	1
#define clk 	3

int displayControl(int queue, int hRGB)
{
	int R, G, B;
	
	int regBits[24];


	return regBits;
}

void shiftOut (int counter, int queue, int regBits[24])
{
	//Clock
	if ((counter % 2) == 0){
		PORTB = (1 << clk);
	} else {
		PORTB = (0 << clk);
	}
	
	//Strobe
	if (counter == queue - 2)	PORTB = (1 << str);
	if (counter == queue - 1)	PORTB = (0 << str);

	//Data
	if ((counter % 2) == 0 && counter < (queue - 2)){
		PORTB = (regBits[counter/2] << data);
	}
}
