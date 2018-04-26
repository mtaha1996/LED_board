//Created on 2018-04-14

#include <LPC21xx.h>
//#include "taha.h"
//int data[16][70]= []

unsigned char taha[16][16] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
	{0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

// Global variables
int speed=1;
int dir=1;
unsigned char board[16][24];


// Functions
void initialize();
void delay();
void show(unsigned char[16][24]);
void start_board(); 
void set_board();
void clr_board();



int main()
{
	initialize();
	clr_board();
	set_board();
	
	while (1)
	{
		
		start_board();
		

	}
	
	return 0;
}

void initialize()
{
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	PINSEL2 = 0x00000000;
	
	IO0DIR = 0x001FFFFF; // Bit 0-20 of Port 0 is Output
}

void show(unsigned char brd[16][24])
{
	int value;
	int counter = 0;
	while(counter<24){
		value = 0;	
		IOPIN0 =  0x001FFFE0; // bit 5-20 set to 1
		IOSET0 = counter;
		for(int i = 0 ; i <16 ; i++){
				if (counter < 16){
					if (brd[i][counter]==1){
					value += 1 << i;
					}
				}
			}
		IOCLR0 = value << 5 ;		
		delay();
		counter++;
	}
	counter = 0;
}

void delay1(){
	int i = 10000000;
	
	while(i>0) i--;
}

void start_board(){
		
	show(board);
	if(IOPIN0 & 1<< 21){ // set direction
		dir = 1;
	}
	else {
		dir = 0;
	}


}

void delay(){

	int i = 100;
	
	while(i>0) i--;
}

void clr_board(){

	for(int i=0;i<16;i++){
		for(int j=0;j<24;j++){
			board[i][j] = 0;		
		}	
	}
}

void set_board(){

	for(int i = 0 ; i <16 ; i++){
				for(int j = 0 ; j <24 ; j++){
					if (taha[i][j]==1){
						board[i][j] = 1;
					}
					else {
						board[i][j] = 0;					
					}
				}
			}


}


