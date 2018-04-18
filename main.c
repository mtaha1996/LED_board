//Created on 2018-04-14

#include <LPC21xx.h>

//int data[16][70]= []

void initialize();
void show(int**,int,int);



int main()
{
	initialize();
	
	int counter = 0;
	
	while (1)
	{
		if (IO0PIN & 0x00000800)
		{

		}
	}
	
	return 0;
}

void initialize()
{
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	PINSEL2 = 0x00000000;
	
	IO0DIR = 0x0000FFFF; // Bit 0-15 of Port 0 is Output
}

void  show(int** data, int shift, int speed)
{
	
	

}
