#include <reg51.h>
void delay(unsigned int ms);
sbit switchButton=P1^0;
sbit led=P1^1;
unsigned int buttonNumber;
void main(void){
	
	P2=0x00;
	led=0;
	buttonNumber=0;
	while(1){
		/*
		P2=0x3f;//0011 1111
		delay(300);
		P2=0x06;//0000 0110
		delay(300);
		P2=0x5b;//0101 1011
		delay(300);
		P2=0x4f;//0100 1111
		delay(300);
		P2=0x66;//0110 0110
		delay(300);
		P2=0x6d;//0110 1101
		delay(300);
		P2=0x7d;//0111 1101
		delay(300);
		P2=0x07;//0000 0111
		delay(300);
		P2=0x7f;//0111 1111
		delay(300);
		P2=0x6f;//0110 1111
		delay(300);
		*/
		led=switchButton?0:1;
		if(led){
			buttonNumber=buttonNumber+1;
			if(buttonNumber>9){
				buttonNumber=0;
			}
		}
		switch(buttonNumber){
			case 0:
				P2=0x3f;//0011 1111
				delay(50);
				break;
			case 1:
				P2=0x06;//0000 0110
			  delay(50);
				break;
			case 2:
				P2=0x5b;//0101 1011
			  delay(50);
				break;
			case 3:
				P2=0x4f;//0100 1111
			  delay(50);
			  break;
			case 4:
				P2=0x66;//0110 0110 
			  delay(50);
			  break;
			case 5:
				P2=0x6d;//0110 1101
			  delay(50);
				break;
			case 6:
				P2=0x7d;//0111 1101
			  delay(50);
			  break;
			case 7:
				P2=0x07;//0000 0111
			  delay(50);
			  break;
			case 8:
				P2=0x7f;//0111 1111
			  delay(100);
				break;
			case 9:
				P2=0x6f;//0110 1111
			  delay(50);
			  break;
			default :
				P2=0x3f;	
			  delay(50);
			  break;
			}
	}
}
void delay(unsigned int ms){
	unsigned int i,j;
	for (i=0;i<ms;i++){
		for (j=0;j<1275;j++);
	}
}