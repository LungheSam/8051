#include <reg51.h>

void delay(unsigned int ms){
	unsigned int i,j;
	for(i=0;i<ms;i++){
		for (j=0;j<1275;j++);
	}
}
void main(void){
	P2=0x00;
	P1-0x00;
	while(1){
		//forward 0000 1010
		P2=0x0A;
		P1=0x71;//F: 0111 0001 
		delay(1000);
		
		//backward 0000 0101
		P2=0x05;
		P1=0xff;//B: 0111 1111 
		delay(1000);
		//stop 0000 0000 
		P2=0x00;
		P1=0x6d;//S: 0110 1101
		delay(1000);
		//Left 0000 0110 
		P2=0x06;
		P1=0x38;//L: 0011 1000
		delay(1000);
		//Right 0000 1001 
		P2=0x09;
		P1=0x77;//R: 0111 0111
		delay(1000);
		//stop 0000 0000 
		P2=0x00;
		P1=0x6d;//S: 0110 1101
		delay(1000);
		
	}
}