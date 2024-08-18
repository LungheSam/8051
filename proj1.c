#include <reg51.h>
sbit led=P2^0;
sbit led2=P2^1;
void delay(unsigned int ms);
void main(void){
	P2=0xff;
	while(1){
		led=1;
		led2=0;
		delay(300);
		led=0;
		led2=1;
		delay(300);
	}
}
void delay(unsigned int ms){
	unsigned int i,j;
	for (i=0;i<ms;i++){
		for (j=0;j<1275;j++);
	}
}