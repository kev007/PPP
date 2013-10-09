#define str 	0
#define data 	1
#define clk 	3

int displayControl(int period, int hRGB)
{
	int R, G, B;
	
	int regBits[24];


	if ((R % period) == 0){

	}	
	if ((G % period) == 0){

	}	
	if ((B % period) == 0){

	}	

	return regBits;
}

void shiftOut (int8_t pointer, int8_t period, int regBits[24])
{
	//Clock
	if ((pointer % 2) == 0){
		PORTB = (1 << clk);
	} else {
		PORTB = (0 << clk);
	}
	
	//Strobe
	if (pointer == period - 2)	PORTB = (1 << str);
	if (pointer == period - 1)	PORTB = (0 << str);


	if ((pointer % 2) == 0 && pointer < (period - 2)){
		PORTB = (regBits[pointer/2] << pointer/2);
	}
}
